// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/peak_find/TestConvolver.cpp
//! @brief     Implements module/class/test TestConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <stdexcept>

#include <Eigen/Dense>

#include <nsxlib/ConvolverFactory.h>
#include <nsxlib/MathematicsTypes.h>
#include <nsxlib/NSXTest.h>

#include <iostream>

NSX_INIT_TEST

using RealMatrix = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

// Helper function for computing direct convolution
// Tested against scipy.signal.convolve2d (see nsxtool/scripts/test_convolution.py)
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

// Helper function for extending image using symmetry padding
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

void testBadConvolverParameters(const std::string& kernel_name, const std::map<std::string,int>& parameters)
{
    nsx::ConvolverFactory convolver_factory;

    NSX_CHECK_THROW(convolver_factory.create(kernel_name,parameters)->matrix(),std::runtime_error);
}

void testConvolver(const RealMatrix& image, const std::string& kernel_name, const std::map<std::string,int>& parameters)
{
    const double tolerance = 1.0e-9;

    nsx::ConvolverFactory convolver_factory;
    RealMatrix direct_convolved_image;

    const int image_n_rows = image.rows();
    const int image_n_cols = image.cols();

    auto kernel = convolver_factory.create(kernel_name,parameters);

    auto kernel_matrix = kernel->matrix();

    int kernel_n_rows = kernel_matrix.rows();
    int kernel_n_cols = kernel_matrix.cols();

    int pad_n_rows = kernel_n_rows >> 1;
    int pad_n_cols = kernel_n_cols >> 1;

    int padded_image_n_rows = image_n_rows + 2*pad_n_rows;
    int padded_image_n_cols = image_n_cols + 2*pad_n_cols;

    RealMatrix padded_image = PadImage(image,padded_image_n_rows,padded_image_n_cols,kernel_n_rows,kernel_n_cols);

    direct_convolved_image = DirectConvolve(padded_image,kernel_matrix,image_n_rows,image_n_cols);

    RealMatrix fft_convolved_image = kernel->convolve(image);
    for (int r = 0; r < image_n_rows; ++r) {
        for (int c = 0; c < image_n_cols; ++c) {
            NSX_CHECK_SMALL(direct_convolved_image(r,c)-fft_convolved_image(r,c),tolerance);
        }
    }
}

int main()
{
    testBadConvolverParameters("box",{{"n_rows",3},{"n_cols",0}});
    testBadConvolverParameters("box",{{"n_rows",0},{"n_cols",3}});
    testBadConvolverParameters("box",{{"n_rows",-1},{"n_cols",2}});

    testBadConvolverParameters("radial",{{"inner_radius",-1},{"outer_radius",3}});
    testBadConvolverParameters("radial",{{"inner_radius",4},{"outer_radius",1}});

    testBadConvolverParameters("gaussian",{{"row_radius",-1},{"column_radius",3},{"row_sigma",3},{"column_sigma",3}});
    testBadConvolverParameters("gaussian",{{"row_radius",2},{"column_radius",-3},{"row_sigma",3},{"column_sigma",3}});
    testBadConvolverParameters("gaussian",{{"row_radius",10},{"column_radius",30},{"row_sigma",-3},{"column_sigma",3}});
    testBadConvolverParameters("gaussian",{{"row_radius",10},{"column_radius",30},{"row_sigma",3},{"column_sigma",-6}});

    testBadConvolverParameters("annular",{{"inner_radius",-1},{"middle_radius",3},{"outer_radius",3}});
    testBadConvolverParameters("annular",{{"inner_radius",2},{"middle_radius",8},{"outer_radius",3}});

    testBadConvolverParameters("enhanced annular",{{"inner_radius",-1},{"middle_radius",3},{"outer_radius",3}});
    testBadConvolverParameters("enhanced annular",{{"inner_radius",2},{"middle_radius",8},{"outer_radius",3}});

    RealMatrix image = RealMatrix::Random(50,65);

    testConvolver(image,"delta",{});

    testConvolver(image,"none",{});

    testConvolver(image,"box",{{"n_rows",3},{"n_cols",3}});
    testConvolver(image,"box",{{"n_rows",3},{"n_cols",6}});
    testConvolver(image,"box",{{"n_rows",1},{"n_cols",3}});
    testConvolver(image,"box",{{"n_rows",3},{"n_cols",1}});
    testConvolver(image,"box",{{"n_rows",2},{"n_cols",2}});
    testConvolver(image,"box",{{"n_rows",1},{"n_cols",1}});

    testConvolver(image,"gaussian",{{"row_radius",10},{"column_radius",2},{"row_sigma",3},{"column_sigma",4}});
    testConvolver(image,"gaussian",{{"row_radius",12},{"column_radius",15},{"row_sigma",1},{"column_sigma",5}});

    testConvolver(image,"radial",{{"inner_radius",0},{"outer_radius",8}});
    testConvolver(image,"radial",{{"inner_radius",5},{"outer_radius",15}});
    testConvolver(image,"radial",{{"inner_radius",2},{"outer_radius",20}});
    testConvolver(image,"radial",{{"inner_radius",4},{"outer_radius",6}});
    testConvolver(image,"radial",{{"inner_radius",0},{"outer_radius",4}});

    testConvolver(image,"annular",{{"inner_radius",2},{"middle_radius",5},{"outer_radius",8}});
    testConvolver(image,"annular",{{"inner_radius",4},{"middle_radius",7},{"outer_radius",8}});
    testConvolver(image,"annular",{{"inner_radius",2},{"middle_radius",9},{"outer_radius",16}});
}

