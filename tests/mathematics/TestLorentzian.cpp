#define BOOST_TEST_MODULE "Test Lorentzian class"
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <nsxlib/mathematics/Lorentzian.h>

const double eps = 1e-10;

int run_test()
{
    nsx::Lorentzian l1(2.0, 3.0, 1.0);
    BOOST_CHECK_CLOSE(l1.evaluate(1.0), 4.0 / 9.0, eps);

    return 0;
}

BOOST_AUTO_TEST_CASE(Test_Lorentzian)
{
    BOOST_CHECK(run_test() == 0);
}