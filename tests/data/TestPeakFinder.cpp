#include <vector>

#include <Eigen/Dense>

#include <nsxlib/data/DataReaderFactory.h>
#include <nsxlib/data/PeakFinder.h>
#include <nsxlib/data/DataSet.h>
#include <nsxlib/data/MetaData.h>
#include <nsxlib/instrument/Diffractometer.h>
#include <nsxlib/utils/NSXTest.h>
#include <nsxlib/utils/ProgressHandler.h>

int main()
{
    nsx::DataList numors;

    nsx::DataReaderFactory factory;
    auto diff = nsx::Diffractometer::build("D10");
    auto dataf = factory.create("", "D10_ascii_example", diff);
    auto meta = dataf->getMetadata();
    nsx::PeakFinder peakFinder;
    nsx::sptrProgressHandler handler(new nsx::ProgressHandler);

    NSX_CHECK_ASSERT(meta->getKey<int>("nbang")==2);

    dataf->open();
    numors.push_back(dataf);
    peakFinder.setHandler(handler);

    peakFinder.setSearchConfidence(0.997);
    NSX_CHECK_CLOSE(peakFinder.searchConfidence(), 0.997, 1e-10);

    peakFinder.setIntegrationConfidence(0.997);
    NSX_CHECK_CLOSE(peakFinder.integrationConfidence(), 0.997, 1e-10);

    peakFinder.setMaxComponents(10000);
    NSX_CHECK_ASSERT(peakFinder.getMaxComponents() == 10000);

    peakFinder.setMinComponents(10);
    NSX_CHECK_ASSERT(peakFinder.getMinComponents() == 10);

    peakFinder.setThresholdValue(3.0);
    NSX_CHECK_CLOSE(peakFinder.getThresholdValue(), 3.0, 1e-10);

    bool result = peakFinder.find(numors);
    NSX_CHECK_ASSERT(result == true);

    size_t num_peaks = dataf->getPeaks().size();

    NSX_CHECK_ASSERT(num_peaks == 1);

    dataf->close();
    dataf->clearPeaks();
    dataf = nullptr;
}
