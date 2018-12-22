// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/peak_find/TestDeltaConvolver.cpp
//! @brief     Implements module/class/test TestDeltaConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <nsxlib/DeltaConvolver.h>
#include <nsxlib/MathematicsTypes.h>
#include <nsxlib/NSXTest.h>

NSX_INIT_TEST

// Generate a image to use for testing the Fourier transform
nsx::RealMatrix generateImage(int rows, int cols)
{
    nsx::RealMatrix image(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            image(i, j) = i*i + i - 2*j - j*j; // something NOT symmetric in i or j, and i<->j
        }
    }
    return image;
}

double computeError(int nrows, int ncols)
{
    nsx::RealMatrix original = generateImage(nrows,ncols);
    nsx::DeltaConvolver convolver;

    nsx::RealMatrix transformed = convolver.convolve(original);
    nsx::RealMatrix difference =  original-transformed;
    double error = (difference * difference.transpose()).sum() / nrows / ncols;
    return std::sqrt(error);
}

int main()
{
    double error = computeError(30, 20);
    NSX_CHECK_ASSERT(error < 1e-10);
}

