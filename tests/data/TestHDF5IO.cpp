#define BOOST_TEST_MODULE "Test HDF5 writting and reading using Blosc library"
#define BOOST_TEST_DYN_LINK

#include <memory>
#include <vector>

#include <boost/test/unit_test.hpp>

#include <Eigen/Dense>

#include <nsxlib/instrument/DiffractometerStore.h>
#include <nsxlib/data/DataReaderFactory.h>
#include <nsxlib/data/DataSet.h>

using namespace nsx;

BOOST_AUTO_TEST_CASE(Test_HDF5_IO)
{
    DataReaderFactory factory;
    DiffractometerStore* ds;
    std::shared_ptr<Diffractometer> diff;
    std::shared_ptr<DataSet> dataf;

    std::vector<Eigen::MatrixXi> frames;

    try {
        ds = DiffractometerStore::Instance();
        diff = std::shared_ptr<Diffractometer>(ds->buildDiffractometer("D10"));
        dataf = factory.create("", "D10_ascii_example", diff);
        dataf->open();

        for (size_t i = 0; i < dataf->getNFrames(); ++i) {
            frames.push_back(dataf->getFrame(i));
        }

        dataf->saveHDF5("D10_hdf5_example.h5");
        dataf->close();
        dataf.reset();

        // read data back in and check that it agrees!
        auto dataf = factory.create("h5", "D10_hdf5_example.h5", diff);

        BOOST_ASSERT(dataf != nullptr);

        for (size_t i = 0; i < dataf->getNFrames(); ++i) {
            BOOST_CHECK(dataf->getFrame(i) == frames[i]);
        }
        dataf->close();
    }
    catch (std::exception& e) {
        BOOST_FAIL(std::string("saveHDF5() threw exception: ") + e.what());
    }
    catch(...) {
        BOOST_FAIL("saveHDF5() threw unknown exception");
   
    }  
}
