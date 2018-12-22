// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/IConvolver.cpp
//! @brief     Implements module/class/test IConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "IConvolver.h"

namespace nsx {

IConvolver::IConvolver(const std::map<std::string,int> &parameters) : _parameters(parameters), _update_kernel(true)
{
}

IConvolver::~IConvolver() = default;

const std::map<std::string,int>& IConvolver::parameters() const
{
    return _parameters;
}

void IConvolver::setParameters(const std::map<std::string,int>& parameters)
{
    for (auto p : parameters) {
        auto it = _parameters.find(p.first);
        if (it != _parameters.end()) {
            it->second = p.second;
        }
    }

    _update_kernel = true;
}

RealMatrix IConvolver::extendKernel(int n_rows, int n_cols) const
{
    // Fetch the kernel matrix
    RealMatrix kernel_matrix = matrix();

    const int kernel_n_rows = kernel_matrix.rows();
    const int kernel_n_cols = kernel_matrix.cols();

    if ((n_rows < kernel_n_rows) || (n_cols < kernel_n_cols)) {
        throw std::runtime_error("The extended size is smaller than the kernel size");
    }

    // Define the amount of rows and columns padding
    const int pad_n_rows = kernel_n_rows >> 1;
    const int pad_n_cols = kernel_n_cols >> 1;

    // Extend the kernel matrix by shifting its center on (0,0) and splitting on each corner of the extended kernel matrix
    RealMatrix extended_kernel = RealMatrix::Zero(n_rows,n_cols);
    for (int i = 0; i < kernel_n_rows; ++i) {
        int ii = (i-pad_n_rows)%n_rows;
        ii += (ii < 0 ? n_rows : 0);
        for (int j = 0; j < kernel_n_cols; ++j) {
            int jj = (j-pad_n_cols)%n_cols;
            jj += (jj < 0 ? n_cols : 0);
            extended_kernel(ii,jj) = kernel_matrix(i,j);
        }
    }

    return extended_kernel;
}

} // end namespace nsx

