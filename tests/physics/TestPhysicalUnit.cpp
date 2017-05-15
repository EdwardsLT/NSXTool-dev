#define BOOST_TEST_MODULE "Test Physical Unit"
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <exception>
#include <iostream>
#include <string>

#include <nsxlib/physics/PhysicalUnit.h>

const double largeTolerance=1.0e-2;
const double smallTolerance=1.0e-9;

BOOST_AUTO_TEST_CASE(Test_Physical_Unit)
{
    // unit conversion tested according value got from
    // http://www.translatorscafe.com/cafe/EN/units-converter/energy/1-65/joule-kelvin/

    // Check that a bad input unit actually throws
    BOOST_CHECK_THROW(nsx::Physics::PhysicalUnit u(1.0,"xxxxxx"),std::runtime_error);

    nsx::Physics::PhysicalUnit u1(1.0,"km/s");

    // Check that an invalid conversion throws
    BOOST_CHECK_THROW(u1.convert("km*K"),std::runtime_error);

    // Check a valid conversion
    BOOST_CHECK_CLOSE(u1.convert("m/s"), 1.0e+3, smallTolerance);
    BOOST_CHECK_CLOSE(u1.convertToSI(), 1.0e+3, smallTolerance);

    // Change the value
    u1.setValue(5.0);

    // Check again a valid conversion
    BOOST_CHECK_CLOSE(u1.convert("m/s"), 5.0e+3, smallTolerance);
    BOOST_CHECK_CLOSE(u1.convertToSI(), 5.0e+3, smallTolerance);

    nsx::Physics::PhysicalUnit u2(5.0,"J");
    BOOST_CHECK_CLOSE(u2.convert("keV"), 3.121e+16, largeTolerance);
    BOOST_CHECK_CLOSE(u2.convert("kg"), 5.56325028e-17, largeTolerance);
    // Check that converting J to cd throws
    BOOST_CHECK_THROW(u2.convert("cd"),std::runtime_error);

    nsx::Physics::PhysicalUnit u3(5.0,"eV");
    BOOST_CHECK_CLOSE(u3.convert("g"), 8.913313479732e-33, largeTolerance);

    nsx::Physics::PhysicalUnit u4(5.0,"g");
    BOOST_CHECK_CLOSE(u4.convert("eV"), 5.0*5.60958616722e+32, largeTolerance);

    nsx::Physics::PhysicalUnit u5(3.0,"J**2");
    BOOST_CHECK_CLOSE(u5.convert("keV**2"), 3.0*6.241506363094e+15*6.241506363094e+15, largeTolerance);
    BOOST_CHECK_CLOSE(u5.convert("g**2"), 3.0*1.112650056e-14*1.112650056e-14, largeTolerance);

    nsx::Physics::PhysicalUnit u6(5.0,"meV**2");
//    BOOST_CHECK_CLOSE(u2.convert("keV"), 3.121e+16, largeTolerance);
    BOOST_CHECK_CLOSE(u6.convert("g**2"), 5*1.782662695946e-36*1.782662695946e-36, largeTolerance);
}
