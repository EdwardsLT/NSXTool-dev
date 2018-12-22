// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/data/TestHDF5IO.cpp
//! @brief     Implements module/class/test TestHDF5IO
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <vector>

#include <Eigen/Dense>

#include <nsxlib/DataSet.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/Units.h>

NSX_INIT_TEST

int main()
{
    nsx::Experiment experiment("","D10");

    nsx::sptrDataSet dataset(new nsx::DataSet("", "D10_ascii_example", experiment.diffractometer()));

    std::vector<Eigen::MatrixXi> frames;

    dataset->open();

    for (size_t i = 0; i < dataset->nFrames(); ++i) {
        frames.push_back(dataset->frame(i));
    }

    dataset->saveHDF5("D10_hdf5_example.h5");
    dataset->close();

    // read data back in and check that it agrees!
    dataset = std::make_shared<nsx::DataSet>("h5", "D10_hdf5_example.h5", experiment.diffractometer());

    NSX_CHECK_ASSERT(dataset != nullptr);

    for (size_t i = 0; i < dataset->nFrames(); ++i) {
        NSX_CHECK_ASSERT(dataset->frame(i) == frames[i]);
    }
    dataset->close();
}
