#include <complex>
#include <iostream>

#include <vector>

#include <fftw3.h>

#include <Eigen/Dense>

using RealMatrix = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

RealMatrix ConstantKernel(int padded_image_rows, int padded_image_cols, int kernel_rows, int kernel_cols)
{
    const int half_kernel_rows = kernel_rows >> 1;
    const int half_kernel_cols = kernel_cols >> 1;

    const int shifted_kernel_rows = padded_image_rows;
    const int shifted_kernel_cols = padded_image_cols;

    RealMatrix kernel = RealMatrix::Zero(shifted_kernel_rows,shifted_kernel_cols);

    const int offset_row = kernel_rows % 2 ? 0 : 1;
    const int offset_col = kernel_cols % 2 ? 0 : 1;
    for (int i = -half_kernel_rows + offset_row; i <= half_kernel_rows; ++i) {
        const int row = (i + shifted_kernel_rows - offset_row)%shifted_kernel_rows;
        for (int j = -half_kernel_cols + offset_col; j <= half_kernel_cols; ++j) {
            const int col = (j + shifted_kernel_cols - offset_col)%shifted_kernel_cols;
            kernel(row,col) = 1.0;
        }
    }

    kernel /= kernel.sum();

    return kernel;
}


RealMatrix ExtendKernel(const RealMatrix& kernel, int padded_image_rows, int padded_image_cols)
{
    const int kernel_rows = kernel.rows();
    const int kernel_cols = kernel.cols();

    const int half_kernel_rows = kernel_rows >> 1;
    const int half_kernel_cols = kernel_cols >> 1;

    RealMatrix extended_kernel = RealMatrix::Zero(padded_image_rows,padded_image_cols);

    for (int i = 0; i < kernel_rows; ++i) {
        for (int j = 0; j < kernel_cols; ++j) {
            int ii = (i-half_kernel_rows)%padded_image_rows;
            ii += (ii < 0 ? padded_image_rows : 0);

            int jj = (j-half_kernel_cols)%padded_image_cols;
            jj += (jj < 0 ? padded_image_cols : 0);
            extended_kernel(ii,jj) = kernel(i,j);
        }
    }

    return extended_kernel;
}

RealMatrix PadImage(const RealMatrix& image, int padded_image_rows, int padded_image_cols, int kernel_rows, int kernel_cols)
{
    const int image_rows = image.rows();
    const int image_cols = image.cols();

    const int half_kernel_rows = kernel_rows >> 1;
    const int half_kernel_cols = kernel_cols >> 1;

    RealMatrix padded_image(image_rows + 2*half_kernel_rows,image_cols + 2*half_kernel_cols);

    // Fill the enlarged matrix by mirroring the original image
    for (int r = 0; r < padded_image_rows; ++r) {
        int ii;
        if (r < half_kernel_rows) {
            ii = half_kernel_rows - r - 1;
        } else if (r >= image_rows + half_kernel_rows) {
            ii = 2*image_rows + half_kernel_rows - r - 1;
        } else {
            ii = r - half_kernel_rows;
        }
        for (int c = 0; c < padded_image_cols; c++) {
            int jj;
            if (c < half_kernel_cols) {
                jj = half_kernel_cols - c - 1;
            } else if (c >= image_cols + half_kernel_cols) {
                jj = 2*image_cols + half_kernel_cols - c - 1;
            } else {
                jj = c - half_kernel_cols;
            }
            if (!(r >= half_kernel_rows && r < padded_image_rows - half_kernel_rows &&
                  c >= half_kernel_cols && c < padded_image_cols - half_kernel_cols)) {
                padded_image(r,c) = image(ii,jj);
            }
        }
    }

    padded_image.block(half_kernel_rows,half_kernel_cols,image_rows,image_cols) = image;

    return padded_image;
}

RealMatrix DirectConvolve(const RealMatrix& enlarged_image,const RealMatrix& kernel,int n_rows,int n_cols)
{
    const int kernel_rows = kernel.rows();
    const int kernel_cols = kernel.cols();

    RealMatrix convolved_image = RealMatrix::Zero(n_rows,n_cols);
    for (int r = 0; r < n_rows; ++r) {
        for (int c = 0; c < n_cols; ++c) {
            auto mat = enlarged_image.block(r,c,kernel_rows,kernel_cols);
            for (int kr = 0; kr < kernel_rows; ++kr) {
                for (int kc = 0; kc < kernel_cols; ++kc) {
                    convolved_image(r,c) += mat(kr,kc)*kernel(kernel_rows- 1 - kr,kernel_cols - 1 - kc);
                }
            }
        }
    }
    return convolved_image;
}

int main()
{
    fftw_plan forward_plan;
    fftw_plan backward_plan;

    double* data;

    fftw_complex* data_spectrum;

    std::vector<std::complex<double>> kernel_spectrum;
    
    RealMatrix image = RealMatrix::Random(12,10);

    std::cout<<"Data"<<std::endl;
    std::cout<<image<<std::endl;

    const int image_rows = image.rows();
    const int image_cols = image.cols();

    RealMatrix direct_kernel = RealMatrix::Ones(3,6);
    direct_kernel /= direct_kernel.sum();
    std::cout<<"Direct kernel"<<std::endl;
    std::cout<<direct_kernel<<std::endl;

    const int kernel_rows = direct_kernel.rows();
    const int kernel_cols = direct_kernel.cols();

    const int half_kernel_rows = kernel_rows >> 1;
    const int half_kernel_cols = kernel_cols >> 1;

    const int padded_image_rows = image_rows + 2*half_kernel_rows;
    const int padded_image_cols = image_cols + 2*half_kernel_cols;

    const int half_padded_image_cols = (padded_image_cols>>1) + 1;
    
    RealMatrix extended_kernel = ExtendKernel(direct_kernel,padded_image_rows,padded_image_cols);

    std::cout<<"Extended kernel"<<std::endl;
    std::cout<<extended_kernel<<std::endl;

    const int n_pixels = extended_kernel.size();
    const double factor = 1.0 / ((double)(n_pixels));

    data = (double*)fftw_malloc(n_pixels * sizeof(double));
    data_spectrum = (fftw_complex*)fftw_malloc(padded_image_rows * half_padded_image_cols * sizeof(fftw_complex));

    kernel_spectrum.resize(padded_image_rows*half_padded_image_cols);

    // Create plans
    forward_plan = fftw_plan_dft_r2c_2d(padded_image_rows, padded_image_cols, data, data_spectrum, FFTW_ESTIMATE);
    backward_plan = fftw_plan_dft_c2r_2d(padded_image_rows, padded_image_cols, data_spectrum, data, FFTW_ESTIMATE);

    // Precompute the transformation of the kernel
    std::memcpy(data, extended_kernel.data(), n_pixels*sizeof(double));
    fftw_execute(forward_plan);

    // Store transformed kernel as vector of complexes (convenient for convolution)
    for (int i = 0; i < padded_image_rows*half_padded_image_cols; ++i) {
        kernel_spectrum[i] = std::complex<double>(data_spectrum[i][0], data_spectrum[i][1]);
    }

    RealMatrix padded_image = PadImage(image,padded_image_rows,padded_image_cols,kernel_rows,kernel_cols);

    //std::cout<<"Padded image"<<std::endl;
    //std::cout<<padded_image<<std::endl;

    std::memcpy(data, padded_image.data(), n_pixels*sizeof(double));

    fftw_execute(forward_plan);

    // multiply fourier modes component-by-component
    for (int i = 0; i < padded_image_rows*half_padded_image_cols; ++i) {
        auto result = factor * kernel_spectrum[i] * std::complex<double>(data_spectrum[i][0], data_spectrum[i][1]);
        data_spectrum[i][0] = result.real();
        data_spectrum[i][1] = result.imag();
    }

    // Perform inverse transform: _realData now stores the convolution
    fftw_execute(backward_plan);

    int corr_row = kernel_rows % 2 ? 0 : 1;
    int corr_col = kernel_cols % 2 ? 0 : 1;

    RealMatrix fft_convolved_image(image_rows,image_cols);
    for (int r = 0; r < image_rows; ++r) {
        const int index = r*image_cols;
        const int shifted_index = (r+half_kernel_rows - corr_row)*padded_image_cols + (half_kernel_cols - corr_col);
        std::memcpy(fft_convolved_image.data()+index,data+shifted_index,image_cols*sizeof(double));
    }

    std::cout<<"FFT convolved image"<<std::endl;
    std::cout<<fft_convolved_image<<std::endl;

    RealMatrix direct_convolved_image = DirectConvolve(padded_image,direct_kernel,image_rows,image_cols);

    std::cout<<"Direct convolved image"<<std::endl;
    std::cout<<direct_convolved_image<<std::endl;

    std::cout<<(fft_convolved_image-direct_convolved_image).maxCoeff()<<std::endl;
}
