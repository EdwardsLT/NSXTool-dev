#define BOOST_TEST_MODULE "Test 2D Sphere"
#define BOOST_TEST_DYN_LINK

#include <cmath>

#include <boost/test/unit_test.hpp>

#include <Eigen/Dense>

#include <nsxlib/geometry/Sphere.h>

using namespace nsx;

const double tolerance_small=1e-10;
const double tolerance=1e-5;
const double tolerance_large=1.0;

BOOST_AUTO_TEST_CASE(Test_Sphere)
{
    // Test: the construction of a 3D sphere
    Eigen::Vector2d center(3,-2);
    double radius(10);
    Sphere<double,2> s1(center,radius);
    Eigen::Vector2d lower(s1.getLower());
    Eigen::Vector2d upper(s1.getUpper());

    BOOST_CHECK_CLOSE(lower[0], -7.0,tolerance);
    BOOST_CHECK_CLOSE(lower[1],-12.0,tolerance);
    BOOST_CHECK_CLOSE(upper[0], 13.0,tolerance);
    BOOST_CHECK_CLOSE(upper[1],  8.0,tolerance);

    // Test: the isotropic scaling of a Sphere
    s1.scale(0.5);
    lower = s1.getLower();
    upper = s1.getUpper();
    BOOST_CHECK_CLOSE(lower[0],-2.0,tolerance);
    BOOST_CHECK_CLOSE(lower[1],-7.0,tolerance);
    BOOST_CHECK_CLOSE(upper[0], 8.0,tolerance);
    BOOST_CHECK_CLOSE(upper[1], 3.0,tolerance);

    // Test: the translation of a Sphere
    s1.translate(Eigen::Vector2d(3,1));
    lower = s1.getLower();
    upper = s1.getUpper();
    BOOST_CHECK_CLOSE(lower[0], 1.0,tolerance);
    BOOST_CHECK_CLOSE(lower[1],-6.0,tolerance);
    BOOST_CHECK_CLOSE(upper[0],11.0,tolerance);
    BOOST_CHECK_CLOSE(upper[1], 4.0,tolerance);

    Eigen::Vector3d point(0,0,1);

    // Test that a given point falls inside the Sphere
    int nSteps(500);
    Eigen::Vector2d delta=(upper-lower)/nSteps;
    double sum(0.0);
    for(int i=0;i<=nSteps;++i)
    {
        point.x() = lower[0]+i*delta[0];
        for(int j=0;j<=nSteps;++j)
        {
            point.y() = lower[1]+j*delta[1];
            if (s1.isInside(point))
                sum+=1.0;
        }
    }

    sum *= ((upper[0]-lower[0])*(upper[1]-lower[1]))/(nSteps*nSteps);
    BOOST_CHECK_CLOSE(sum,78.5,tolerance_large);

    // Test: (non-)collision between two spheres

    s1.translate(-s1.getCenter());
    Sphere<double,2> s2(Eigen::Vector2d(10,0),1.0);
    BOOST_CHECK_EQUAL(s1.collide(s2),false);
    s2.translate(Eigen::Vector2d(-2,0));
    BOOST_CHECK_EQUAL(s1.collide(s2),false);
    s2.translate(Eigen::Vector2d(-2,0));
    BOOST_CHECK_EQUAL(s1.collide(s2),false);
    s2.translate(Eigen::Vector2d(-2,0));
    BOOST_CHECK_EQUAL(s1.collide(s2),true);
    s2.translate(Eigen::Vector2d(-2,0));
    BOOST_CHECK_EQUAL(s1.collide(s2),true);
    s2.translate(Eigen::Vector2d(-2,0));
    BOOST_CHECK_EQUAL(s1.collide(s2),true);
    s2.translate(Eigen::Vector2d(-2,0));
    BOOST_CHECK_EQUAL(s1.collide(s2),true);
    s2.translate(Eigen::Vector2d(-2,0));
    BOOST_CHECK_EQUAL(s1.collide(s2),true);
    s2.translate(Eigen::Vector2d(-2,0));
    BOOST_CHECK_EQUAL(s1.collide(s2),false);

    // Test: (non-)intersection between a sphere and a ray

    double t1,t2;
    BOOST_CHECK(s1.rayIntersect(Eigen::Vector2d(-10,0),Eigen::Vector2d(2,0),t1,t2));
    BOOST_CHECK_CLOSE(t1, 2.5, tolerance_small);
    BOOST_CHECK_CLOSE(t2, 7.5, tolerance_small);

    BOOST_CHECK(s1.rayIntersect(Eigen::Vector2d(10.0*sqrt(3)/2,2.5),Eigen::Vector2d(1,0),t1,t2));
    BOOST_CHECK_CLOSE(t1,-15.0*sqrt(3)/2, tolerance_small);
    BOOST_CHECK_CLOSE(t2, -5.0*sqrt(3)/2, tolerance_small);

    BOOST_CHECK(!s1.rayIntersect(Eigen::Vector2d(8,7),Eigen::Vector2d(-1,1),t1,t2));
}
