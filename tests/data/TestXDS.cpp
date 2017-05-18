#define BOOST_TEST_MODULE "Test XDS output class"
#define BOOST_TEST_DYN_LINK

#include <memory>
#include <vector>

#include <Eigen/Dense>

#include <boost/test/unit_test.hpp>

#include <nsxlib/data/IData.h>
#include <nsxlib/data/XDS.h>
#include <nsxlib/data/DataReaderFactory.h>
#include <nsxlib/instrument/DiffractometerStore.h>

using namespace nsx;

BOOST_AUTO_TEST_CASE(Test_XDS)
{
    DataReaderFactory* factory = DataReaderFactory::Instance();
    DiffractometerStore* ds = DiffractometerStore::Instance();

    std::shared_ptr<Diffractometer> diff = std::shared_ptr<Diffractometer>(ds->buildDiffractometer("BioDiff2500"));
    std::shared_ptr<DataSet> dataf(factory->create("hdf", "H5_example.hdf", diff));

    dataf->open();
    Eigen::MatrixXi v=dataf->getFrame(0);

    size_t nframes = dataf->getNFrames();

    // Check the total number of count in the frame 0
    BOOST_CHECK_EQUAL(v.sum(), 1282584565);

    dataf->close();
}
