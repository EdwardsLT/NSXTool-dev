#include <fstream>
#include <string>

#include <Eigen/Dense>

#include <nsxlib/DataSet.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Experiment.h>
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
    nsx::Experiment experiment("","D10");

    Eigen::MatrixXi v;

    nsx::sptrDataSet dataset(new nsx::DataSet("", "D10_ascii_example", experiment.diffractometer()));

    auto metadata = dataset->reader()->metadata();

    NSX_CHECK_ASSERT(metadata.key<int>("nbang")==2);

    dataset->open();
    v = dataset->frame(0);

    // Check the total number of count in the frame 0
    NSX_CHECK_EQUAL(v.sum(),65);

    // Check the value of the monitor
    NSX_CHECK_CLOSE(metadata.key<double>("monitor"),20000,tolerance);

    auto sampleStates = dataset->reader()->sampleStates();
    auto detectorStates = dataset->reader()->detectorStates();
    
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
