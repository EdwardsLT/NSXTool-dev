// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/AtomicConvolver.cpp
//! @brief     Implements module/class/test AtomicConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <cstring>
#include <mutex>
#include <stdexcept>
#include <utility>

#include "AtomicConvolver.h"

#include <iostream>

namespace nsx {

std::mutex g_mutex;

AtomicConvolver::AtomicConvolver()
: IConvolver(),
  _n_rows(0),
  _n_cols(0),
  _half_cols(0),
  _forward_plan(nullptr),
  _backward_plan(nullptr),
  _data(nullptr),
  _data_spectrum(nullptr),
  _kernel_spectrum()
{
}

AtomicConvolver::AtomicConvolver(const std::map<std::string,int> &parameters)
: IConvolver(parameters),
  _n_rows(0),
  _n_cols(0),
  _half_cols(0),
  _forward_plan(nullptr),
  _backward_plan(nullptr),
  _data(nullptr),
  _data_spectrum(nullptr),
  _kernel_spectrum()
{
}

AtomicConvolver::~AtomicConvolver()
{
    reset();
}

void AtomicConvolver::reset()
{
    // FFTW is not thread safe for all its function but fftw_execute
    // See http://www.fftw.org/fftw3_doc/Thread-safety.html
    std::unique_lock<std::mutex> lock(g_mutex);

    if (_forward_plan) {
        fftw_destroy_plan(_forward_plan);
    }
    if (_backward_plan) {
        fftw_destroy_plan(_backward_plan);
    }

    if (_data) {
        fftw_free(_data);
    }

    if (_data_spectrum) {
        fftw_free(_data_spectrum);
    }

    _n_rows = 0;

    _n_cols = 0;

    _half_cols = 0;

    _forward_plan = _backward_plan = nullptr;

    _data = nullptr;

    _data_spectrum = nullptr;

    _kernel_spectrum.resize(0);
}

void AtomicConvolver::updateKernel(int n_rows, int n_cols)
{
    if (n_rows != _n_rows || n_cols != _n_cols) {
        _update_kernel = true;
    }

    if (!_update_kernel) {
        return;
    }

    reset();

    // FFTW is not thread safe for all its function but fftw_execute
    // See http://www.fftw.org/fftw3_doc/Thread-safety.html
    std::unique_lock<std::mutex> lock(g_mutex);

    _n_rows = n_rows;
    _n_cols = n_cols;

    const auto kernel_size = kernelSize();
    const int kernel_n_rows = kernel_size.first;
    const int kernel_n_cols = kernel_size.second;

    const int pad_n_rows = kernel_n_rows >> 1;
    const int pad_n_cols = kernel_n_cols >> 1;

    const int padded_image_n_rows = _n_rows + 2*pad_n_rows;
    const int padded_image_n_cols = _n_cols + 2*pad_n_cols;

    const int padded_image_n_pixels = padded_image_n_rows * padded_image_n_cols;

    RealMatrix kernel = extendKernel(padded_image_n_rows,padded_image_n_cols);

    // Used by FFTW; check documentation for details
    _half_cols = (padded_image_n_cols>>1) + 1;

    // Use fftw_malloc instead of fftw_alloc_* to support older version of fftw3
    _data = (double*)fftw_malloc(padded_image_n_pixels * sizeof(double));
    _data_spectrum = (fftw_complex*)fftw_malloc(padded_image_n_rows * _half_cols * sizeof(fftw_complex));

    _kernel_spectrum.resize(padded_image_n_rows*_half_cols);

    // Create FFTW planner for FFT and inverse FFT
    _forward_plan = fftw_plan_dft_r2c_2d(padded_image_n_rows, padded_image_n_cols, _data, _data_spectrum, FFTW_ESTIMATE);
    _backward_plan = fftw_plan_dft_c2r_2d(padded_image_n_rows, padded_image_n_cols, _data_spectrum, _data, FFTW_ESTIMATE);

    // Precompute the transformation of the kernel
    std::memcpy(_data, kernel.data(), padded_image_n_pixels*sizeof(double));

    lock.unlock();

    // Compute the FFT of the kernel
    fftw_execute(_forward_plan);
    // Store the FFT transformed kernel as vector of complexes (convenient for convolution)
    for (int i = 0; i < padded_image_n_rows*_half_cols; ++i) {
        _kernel_spectrum[i] = std::complex<double>(_data_spectrum[i][0], _data_spectrum[i][1]);
    }

    _update_kernel = true;
}

void AtomicConvolver::padImage(const RealMatrix& image) const
{
    const auto kernel_size = kernelSize();
    const int kernel_n_rows = kernel_size.first;
    const int kernel_n_cols = kernel_size.second;

    const int pad_n_rows = kernel_n_rows >> 1;
    const int pad_n_cols = kernel_n_cols >> 1;

    const int image_n_rows = image.rows();
    const int image_n_cols = image.cols();

    const int padded_image_n_rows = image_n_rows + 2*pad_n_rows;
    const int padded_image_n_cols = image_n_cols + 2*pad_n_cols;

    // Fill the enlarged matrix by mirroring the original image
    for (int r = 0; r < padded_image_n_rows; ++r) {
        int ii;
        if (r < pad_n_rows) {
            ii = pad_n_rows - r - 1;
        } else if (r >= image_n_rows + pad_n_rows) {
            ii = 2*image_n_rows + pad_n_rows - r - 1;
        } else {
            ii = r - pad_n_rows;
        }
        for (int c = 0; c < padded_image_n_cols; c++) {
            int jj;
            if (c < pad_n_cols) {
                jj = pad_n_cols - c - 1;
            } else if (c >= image_n_cols + pad_n_cols) {
                jj = 2*image_n_cols + pad_n_cols - c - 1;
            } else {
                jj = c - pad_n_cols;
            }
            if (!(r >= pad_n_rows && r < padded_image_n_rows - pad_n_rows &&
                  c >= pad_n_cols && c < padded_image_n_cols - pad_n_cols)) {
                const int index = r*padded_image_n_cols + c;
                *(_data + index) = image(ii,jj);
            }
        }
    }

    for (int r = 0; r < image_n_rows; ++r) {
        const int shifted_index = (r+pad_n_rows)*padded_image_n_cols + pad_n_cols;
        std::memcpy(_data+shifted_index,image.data()+r*image_n_cols,image_n_cols*sizeof(double));
    }
}

RealMatrix AtomicConvolver::convolve(const RealMatrix& image)
{
    const int image_n_rows = image.rows();
    const int image_n_cols = image.cols();

    updateKernel(image_n_rows,image_n_cols);

    const auto kernel_size = kernelSize();
    const int kernel_n_rows = kernel_size.first;
    const int kernel_n_cols = kernel_size.second;

    const int pad_n_rows = kernel_n_rows >> 1;
    const int pad_n_cols = kernel_n_cols >> 1;

    const int padded_image_n_rows = image_n_rows + 2*pad_n_rows;
    const int padded_image_n_cols = image_n_cols + 2*pad_n_cols;

    const int padded_image_n_pixels = padded_image_n_rows * padded_image_n_cols;

    padImage(image);

    // factor needed to get correct inverse transform
    const double fft_norm_factor = 1.0 / static_cast<double>(padded_image_n_pixels);

    // precompute the transformation of the kernel
    fftw_execute(_forward_plan);

    // multiply fourier modes component-by-component
    for (int i = 0; i < padded_image_n_rows*_half_cols; ++i) {
        auto result = fft_norm_factor * _kernel_spectrum[i] * std::complex<double>(_data_spectrum[i][0], _data_spectrum[i][1]);
        _data_spectrum[i][0] = result.real();
        _data_spectrum[i][1] = result.imag();
    }

    // Perform inverse transform: _realData now stores the convolution
    fftw_execute(_backward_plan);

    // Offet factor for even-sized kernel
    const int offset_row = kernel_n_rows % 2 ? 0 : 1;
    const int offset_col = kernel_n_cols % 2 ? 0 : 1;

    RealMatrix fft_convolved_image(image_n_rows,image_n_cols);
    for (int r = 0; r < image_n_rows; ++r) {
        const int index = r*image_n_cols;
        const int shifted_index = (r+pad_n_rows - offset_row)*padded_image_n_cols + (pad_n_cols - offset_col);
        std::memcpy(fft_convolved_image.data()+index,_data+shifted_index,image_n_cols*sizeof(double));
    }

    return fft_convolved_image;
}

} // end namespace nsx

