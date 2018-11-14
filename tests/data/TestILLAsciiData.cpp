#include <fstream>
#include <string>

#include <Eigen/Dense>

#include <nsxlib/DataReaderFactory.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/InstrumentState.h>
#include <nsxlib/MetaData.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/Units.h>

const double tolerance=1e-2;

namespace nsx {

NSX_INIT_TEST

class UnitTest_DataSet {
public:
    static int run();
};

int UnitTest_DataSet::run()
{
    nsx::DataReaderFactory factory;
    nsx::sptrDiffractometer diff;
    nsx::sptrDataSet dataf;
    Eigen::MatrixXi v;

    nsx::MetaData metadata;

    try {
        diff = nsx::Diffractometer::create("D10");

        dataf = factory.create("", "D10_ascii_example", diff);

        metadata = dataf->reader()->metadata();

        NSX_CHECK_ASSERT(metadata.key<int>("nbang")==2);

        dataf->open();
        v = dataf->frame(0);
    }
    catch(std::exception& e) {
        NSX_FAIL(std::string("caught exception: ") + e.what());
    }
    catch (...) {
        NSX_FAIL("unknown exception while loading data");
    }

    // Check the total number of count in the frame 0
    NSX_CHECK_EQUAL(v.sum(),65);

    // Check the value of the monitor
    NSX_CHECK_CLOSE(metadata.key<double>("monitor"),20000,tolerance);

    auto sampleStates = dataf->reader()->sampleStates();
    auto detectorStates = dataf->reader()->detectorStates();
    
    NSX_CHECK_CLOSE(detectorStates[3][0],0.54347000E+05/1000.0*nsx::deg,tolerance);
    NSX_CHECK_CLOSE(sampleStates[2][0],0.26572000E+05/1000.0*nsx::deg,tolerance);
    NSX_CHECK_CLOSE(sampleStates[2][1],0.48923233E+02*nsx::deg,tolerance);
    NSX_CHECK_CLOSE(sampleStates[2][2],-0.48583171E+02*nsx::deg,tolerance);

    return 0;
}

} // end namespace nsx

int main() 
{
    nsx::UnitTest_DataSet::run();
}
