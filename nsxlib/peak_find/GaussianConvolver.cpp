// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/GaussianConvolver.cpp
//! @brief     Implements module/class/test GaussianConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "GaussianConvolver.h"

namespace nsx {

GaussianConvolver::GaussianConvolver()
: AtomicConvolver({{"row_radius",10},{"column_radius",10},{"row_sigma",2},{"column_sigma",2}})
{
}

GaussianConvolver::GaussianConvolver(const std::map<std::string,int>& parameters)
: GaussianConvolver()
{
    setParameters(parameters);
}

IConvolver* GaussianConvolver::clone() const
{
    return new GaussianConvolver(*this);
}

std::pair<size_t,size_t> GaussianConvolver::kernelSize() const
{
    const int row_radius = _parameters.at("row_radius");
    const int column_radius = _parameters.at("column_radius");

    const size_t n_rows = 2*row_radius + 1;
    const size_t n_cols = 2*column_radius + 1;

    return std::make_pair(n_rows,n_cols);
}

RealMatrix GaussianConvolver::matrix() const
{
    // sanity checks
    if ((_parameters.at("row_radius") <= 0) ||
        (_parameters.at("column_radius") <= 0) ||
        (_parameters.at("row_sigma") <= 0) ||
        (_parameters.at("column_sigma") <= 0)) {
        throw std::runtime_error("Gaussian convolver called with invalid parameters");
    }

    const int sigma_row = _parameters.at("row_sigma");
    const int sigma_column = _parameters.at("column_sigma");

    const int row_radius = _parameters.at("row_radius");
    const int column_radius = _parameters.at("column_radius");

    const size_t n_rows = 2*row_radius + 1;
    const size_t n_cols = 2*column_radius + 1;
    RealMatrix kernel = RealMatrix::Zero(n_rows,n_cols);

    const double center_row = row_radius;
    const double center_column = column_radius;

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            const double x2 = (i-center_row)*(i-center_row);
            const double y2 = (j-center_column)*(j-center_column);
            kernel(i,j) = std::exp(-0.5*((x2/sigma_row/sigma_row) + (y2/sigma_column/sigma_column)));
        }
    }

    kernel /= kernel.sum();

    return kernel;
}

} // end namespace nsx

