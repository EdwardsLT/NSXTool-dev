// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/data/TestHDF5Data.cpp
//! @brief     Implements module/class/test TestHDF5Data
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <Eigen/Dense>

#include <nsxlib/DataSet.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/NSXTest.h>

NSX_INIT_TEST

int main()
{
    nsx::Experiment experiment("","BioDiff2500");

    nsx::DataSet dataset("hdf", "H5_example.hdf", experiment.diffractometer());

    dataset.open();
    Eigen::MatrixXi v = dataset.frame(0);

    // Check the total number of count in the frame 0
    NSX_CHECK_EQUAL(v.sum(), 1282584565);

    dataset.close();

    nsx::DataSet dataset1(dataset);

    dataset1.open();

    Eigen::MatrixXi v1 = dataset1.frame(0);

    // Check the total number of count in the frame 0
    NSX_CHECK_EQUAL(v1.sum(), v.sum());

    dataset1.close();
}
