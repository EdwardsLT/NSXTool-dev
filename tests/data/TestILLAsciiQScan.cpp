#define BOOST_TEST_MODULE "Test ILL Ascii QScan"
#define BOOST_TEST_DYN_LINK

#include <memory>

#include <boost/test/unit_test.hpp>

#include <Eigen/Dense>

#include <nsxlib/data/DataReaderFactory.h>
#include <nsxlib/data/DataSet.h>
#include <nsxlib/instrument/ComponentState.h>
#include <nsxlib/instrument/DiffractometerStore.h>
#include <nsxlib/utils/Units.h>

using namespace nsx;

const double tolerance=1e-2;

BOOST_AUTO_TEST_CASE(Test_ILL_Ascii_QScan)
{
    DataReaderFactory factory;
    DiffractometerStore* ds;
    std::shared_ptr<Diffractometer> diff;
    std::shared_ptr<DataSet> dataf;
    MetaData* meta;
    Eigen::MatrixXi v;

    try {
        ds = DiffractometerStore::Instance();
        diff = std::shared_ptr<Diffractometer>(ds->buildDiffractometer("D9"));
        dataf = factory.create("", "D9_QSCAN", diff);
        meta=dataf->getMetadata();

        BOOST_CHECK(meta->getKey<int>("nbang")==4);

        dataf->open();
        v = dataf->getFrame(0);
    }
    catch (std::exception& e) {
        BOOST_FAIL(std::string("caught exception: ") + e.what());
    }
    catch(...) {
        BOOST_FAIL("unknown exception");
    }

    // Check the total number of count in the frame 0
    BOOST_CHECK_EQUAL(v.sum(),5.90800000e+03);

    // Check the value of the monitor
    BOOST_CHECK_CLOSE(meta->getKey<double>("monitor"),3.74130000e+04,tolerance);

    dataf->close();
}
