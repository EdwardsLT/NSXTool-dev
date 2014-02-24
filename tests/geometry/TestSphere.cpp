#define BOOST_TEST_MODULE "Test Multi-dimensional Sphere"
#define BOOST_TEST_DYN_LINK
#include <cmath>
#include <boost/test/unit_test.hpp>
#include <Eigen/Dense>
#include "Sphere.h"

using namespace SX::Geometry;
using Eigen::Vector2d;
using Eigen::Vector3d;
using Eigen::Vector4d;
using Eigen::Matrix2d;
using Eigen::Matrix3d;

const double tolerance=1e-5;
const double tolerance_large=1.0;

BOOST_AUTO_TEST_CASE(Test_Sphere)
{

	// Test: the construction of a 3D sphere
	Vector3d center(3,-2,4);
	double radius(10);
	Sphere<double,3> s1(center,radius);
	Vector3d lower(s1.getLower());
	Vector3d upper(s1.getUpper());

	BOOST_CHECK_CLOSE(lower[0], -7.0,tolerance);
	BOOST_CHECK_CLOSE(lower[1],-12.0,tolerance);
	BOOST_CHECK_CLOSE(lower[2], -6.0,tolerance);
	BOOST_CHECK_CLOSE(upper[0], 13.0,tolerance);
	BOOST_CHECK_CLOSE(upper[1],  8.0,tolerance);
	BOOST_CHECK_CLOSE(upper[2], 14.0,tolerance);

	// Test: the isotropic scaling of a Sphere
	s1.scale(0.5);
	lower = s1.getLower();
	upper = s1.getUpper();
	BOOST_CHECK_CLOSE(lower[0],-2.0,tolerance);
	BOOST_CHECK_CLOSE(lower[1],-7.0,tolerance);
	BOOST_CHECK_CLOSE(lower[2],-1.0,tolerance);
	BOOST_CHECK_CLOSE(upper[0], 8.0,tolerance);
	BOOST_CHECK_CLOSE(upper[1], 3.0,tolerance);
	BOOST_CHECK_CLOSE(upper[2], 9.0,tolerance);

	// Test: the translation of a Sphere
	s1.translate(Vector3d(3,1,-2));
	lower = s1.getLower();
	upper = s1.getUpper();
	BOOST_CHECK_CLOSE(lower[0], 1.0,tolerance);
	BOOST_CHECK_CLOSE(lower[1],-6.0,tolerance);
	BOOST_CHECK_CLOSE(lower[2],-3.0,tolerance);
	BOOST_CHECK_CLOSE(upper[0],11.0,tolerance);
	BOOST_CHECK_CLOSE(upper[1], 4.0,tolerance);
	BOOST_CHECK_CLOSE(upper[2], 7.0,tolerance);

	// Test: a given point falls inside the Sphere
	int nSteps(500);
	Vector3d delta=(upper-lower)/nSteps;
	Vector4d point(0,0,0,1);
	double sum(0.0);
	for(int i=0;i<=nSteps;++i)
	{
		point.x() = lower[0]+i*delta[0];
		for(int j=0;j<=nSteps;++j)
		{
			point.y() = lower[1]+j*delta[1];
			for(int k=0;k<=nSteps;++k)
			{
				point.z() = lower[2]+k*delta[2];
				if (s1.isInside(point))
					sum+=1.0;
			}
		}
	}

	sum *= ((upper[0]-lower[0])*(upper[1]-lower[1])*(upper[2]-lower[2]))/(nSteps*nSteps*nSteps);
	BOOST_CHECK_CLOSE(sum,523.6,tolerance_large);

}