// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/instrument/TestInstrumentState.cpp
//! @brief     Implements module/class/test TestInstrumentState
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <nsxlib/Experiment.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/InstrumentState.h>
#include <nsxlib/NSXTest.h>

NSX_INIT_TEST

namespace nsx {
class UnitTest_DataSet {
public:
    static int run();
};
}

int nsx::UnitTest_DataSet::run()
{
    nsx::Experiment experiment("test", "BioDiff2500");

    nsx::sptrDataSet dataset(new nsx::DataSet("hdf", "gal3.hdf", experiment.diffractometer()));

    experiment.addData(dataset);

    auto detectorStates = dataset->_reader->detectorStates();
    auto sampleStates = dataset->_reader->sampleStates();

    for (size_t i = 0; i < 100*(dataset->nFrames()-1); ++i) {
        double frame = double(i) / 100.0;
        auto state = dataset->interpolatedState(frame);

        auto lframe = std::lround(std::floor(frame));
    }

    dataset->close();

    return 0;
}

int main() 
{
    return nsx::UnitTest_DataSet::run();
}
