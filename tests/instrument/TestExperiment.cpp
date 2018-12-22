// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/instrument/TestExperiment.cpp
//! @brief     Implements module/class/test TestExperiment
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <nsxlib/DataSet.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/NSXTest.h>

NSX_INIT_TEST

int main()
{
    nsx::Experiment experiment("my-exp","D10");

    NSX_CHECK_EQUAL(experiment.name(),"my-exp");

    // Change the name of the experiment
    experiment.setName("toto");

    NSX_CHECK_EQUAL(experiment.name(),"toto");

    nsx::sptrDataSet dataset(new nsx::DataSet("", "D10_ascii_example", experiment.diffractometer()));

    experiment.addData(dataset);

    // Check that adding the same data is now taken into account
    experiment.addData(dataset);
    experiment.addData(dataset);

    NSX_CHECK_EQUAL(experiment.data("D10_ascii_example")->filename(),"D10_ascii_example");

    // Remove the data from the experiment
    experiment.removeData("D10_ascii_example");

    return 0;
}

