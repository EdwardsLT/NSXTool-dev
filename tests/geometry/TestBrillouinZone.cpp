#define BOOST_TEST_MODULE "Test Brillouin Zone"
#define BOOST_TEST_DYN_LINK

#include <iostream>
#include <cmath>
#include <Eigen/Dense>

#include <boost/test/unit_test.hpp>

#include <nsxlib/geometry/BrillouinZone.h>

#include <nsxlib/crystal/UnitCell.h>

const double tolerance=1e-9;

// note: validation data obtained from web, see e.g.
// http://lampx.tugraz.at/~hadley/ss1/bzones/
// https://en.wikipedia.org/wiki/Brillouin_zone


// validation function
void validate_zone(const Eigen::Matrix3d& B, int nverts, int nfaces)
{
    std::cout << "validating zone for input matrix B = \n" << B << std::endl;
    nsx::BrillouinZone zone(B, 1e-3);
    nsx::ConvexHull hull = zone.convexHull();
    
    BOOST_CHECK_EQUAL(hull.getNVertices(), nverts);
    BOOST_CHECK_EQUAL(zone.vertices().size(), nverts);
    BOOST_CHECK_EQUAL(2*zone.normals().size(), nfaces);

    for (auto n: zone.normals()) {
        BOOST_CHECK(zone.inside(0.5*n));
        BOOST_CHECK(zone.inside(-0.5*n));

        BOOST_CHECK(hull.contains(0.49*n) == true);
        BOOST_CHECK(hull.contains(0.51*n) == false);

        BOOST_CHECK(zone.inside(0.51*n) == false);
        BOOST_CHECK(zone.inside(-0.51*n) == false);
    }

    for (auto v: zone.vertices()) {
        BOOST_CHECK(zone.inside(v));
        BOOST_CHECK(zone.inside(-v));

        BOOST_CHECK(zone.inside(1.01*v) == false);
        BOOST_CHECK(zone.inside(-1.01*v) == false);
    }    

    BOOST_CHECK_CLOSE(hull.getVolume(), std::fabs(B.determinant()), 1e-8);
}

BOOST_AUTO_TEST_CASE(BrillouinZone)
{
    const double deg = M_PI / 180.0;
    nsx::UnitCell uc;

    // todo: write this test!!
    Eigen::Matrix3d B;


    // primitive triclinic aP
    uc.setParams(20, 25, 15, 95*deg, 85*deg, 93*deg);
    validate_zone(uc.reciprocalBasis(), 24, 14);

    // face-centered cubic cF
    uc.setParams(10, 10, 10, 30*deg, 30*deg, 30*deg);
    validate_zone(uc.reciprocalBasis(), 24, 14);

    // primitive cubic cP
    uc.setParams(10, 10, 10, 90*deg, 90*deg, 90*deg);
    validate_zone(uc.reciprocalBasis(), 8, 6);

    // primitive monoclinic mP
    uc.setParams(15, 20, 25, 78*deg, 90*deg, 90*deg);
    validate_zone(uc.reciprocalBasis(), 12, 8);

    // face-centered monoclinic mC
    uc.setParams(20, 20, 25, 78*deg, 78*deg, 85*deg);
    validate_zone(uc.reciprocalBasis(), 24, 14);

    // primitive orthorhombic oP
    uc.setParams(15, 20, 25, 90*deg, 90*deg, 90*deg);
    validate_zone(uc.reciprocalBasis(), 8, 6);

    // face-centered orthorhombic oC

    // all faces centered orthorhombic oF

    // body-centered orthorhombic oI
    const double oI_beta = std::acos(0.5 * std::sqrt(15.0 / 20.0));
    uc.setParams(15, 20, 20, 78*deg, oI_beta, oI_beta);
    validate_zone(uc.reciprocalBasis(), 24, 14);

    // primitive tetragonal tP
    uc.setParams(20, 25, 25, 90*deg, 90*deg, 90*deg);
    validate_zone(uc.reciprocalBasis(), 8, 6);

    // body-centered tetragonal tI
    const double tI_alpha = std::acos(0.5*20.0/25.0);
    uc.setParams(20, 20, 25, -tI_alpha, -tI_alpha, 90*deg);
    validate_zone(uc.reciprocalBasis(), 24, 14);

    // hP 
    // hR

    // cP
    // cF
    // cI

}
