// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/peak_find/TestPeakFinder.cpp
//! @brief     Implements module/class/test TestPeakFinder
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <vector>

#include <Eigen/Dense>

#include <nsxlib/Experiment.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/PeakFinder.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/MetaData.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/ProgressHandler.h>

NSX_INIT_TEST

int main()
{
    nsx::Experiment experiment("exp","D10");

    nsx::sptrDataSet dataset(new nsx::DataSet("", "D10_ascii_example", experiment.diffractometer()));
    const auto& metadata = dataset->reader()->metadata();

    NSX_CHECK_ASSERT(metadata.key<int>("nbang")==2);

    nsx::DataList datasets;
    datasets.push_back(dataset);

    nsx::PeakFinder peakFinder(datasets);

    peakFinder.setPeakMergingScale(1.0);

    peakFinder.setMaxSize(10000);
    NSX_CHECK_ASSERT(peakFinder.maxSize() == 10000);

    peakFinder.setMinSize(10);
    NSX_CHECK_ASSERT(peakFinder.minSize() == 10);

    peakFinder.setMaxFrames(10);
    NSX_CHECK_ASSERT(peakFinder.maxFrames() == 10);

    peakFinder.run();

    auto found_peaks = peakFinder.peaks();

    size_t num_peaks = found_peaks.size();

    NSX_CHECK_ASSERT(num_peaks == 1);

    dataset->close();
}
