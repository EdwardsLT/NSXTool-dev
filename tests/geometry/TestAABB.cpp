#define BOOST_TEST_MODULE "Test AABB bounding box for 3D case"
#define BOOST_TEST_DYN_LINK
#include "AABB.h"
#include <cmath>
#include <boost/test/unit_test.hpp>
#include <Eigen/Dense>

using namespace SX::Geometry;
using Eigen::Vector3d;
const double tolerance=1e-5;


BOOST_AUTO_TEST_CASE(Test_AABB)
{
	AABB<double,3> bb;
	bb.setBounds(Vector3d(0,0,0),Vector3d(1,2,3));
	Eigen::Vector3d center, extends;
	center=bb.getCenter();
	extends=bb.getExtents();

	BOOST_CHECK_CLOSE(center[0], 0.5, tolerance);
	BOOST_CHECK_CLOSE(center[1], 1.0, tolerance);
	BOOST_CHECK_CLOSE(center[2], 1.5, tolerance);

	BOOST_CHECK_CLOSE(extends[0], 1, tolerance);
	BOOST_CHECK_CLOSE(extends[1], 2, tolerance);
	BOOST_CHECK_CLOSE(extends[2], 3, tolerance);
	// Check the volume of the box
	BOOST_CHECK_CLOSE(bb.volumeND(),6,tolerance);
	// Check that a given point is inside
	BOOST_CHECK(bb.isInsideAABB(Vector3d(center)));
	// Check that a given point is outside
	BOOST_CHECK(!bb.isInsideAABB(Vector3d(2,3,4)));
	//A second bounding box, just touching
	AABB<double,3> bb2(Vector3d(1,2,3),Vector3d(2,3,4));
	BOOST_CHECK(bb2.intercept(bb));
	// Second bounding box overlaps .
	bb2.setBounds(Vector3d(0.5,2,3),Vector3d(2,3,4));
	BOOST_CHECK(bb2.intercept(bb));
	// No overlap
	bb2.setBounds(Vector3d(2,3,4),Vector3d(4,5,6));
	BOOST_CHECK(!(bb2.intercept(bb)));

	// Translate and scale operations
	bb.translate(Vector3d(1,2,3));
	Vector3d& lower=bb.getLower();
	Vector3d& upper=bb.getUpper();
	BOOST_CHECK_CLOSE(lower[0], 1.0, tolerance);
	BOOST_CHECK_CLOSE(lower[1], 2.0, tolerance);
	BOOST_CHECK_CLOSE(lower[2], 3.0, tolerance);
	BOOST_CHECK_CLOSE(upper[0], 2.0, tolerance);
	BOOST_CHECK_CLOSE(upper[1], 4.0, tolerance);
	BOOST_CHECK_CLOSE(upper[2], 6.0, tolerance);
	bb.scale(Vector3d(1,2,3));
	lower=bb.getLower();
	upper=bb.getUpper();
	BOOST_CHECK_CLOSE(lower[0], 1.0, tolerance);
	BOOST_CHECK_CLOSE(lower[1], 1.0, tolerance);
	BOOST_CHECK_CLOSE(lower[2], 0.0, tolerance);
	BOOST_CHECK_CLOSE(upper[0], 2.0, tolerance);
	BOOST_CHECK_CLOSE(upper[1], 5.0, tolerance);
	BOOST_CHECK_CLOSE(upper[2], 9.0, tolerance);
	bb.scale(0.5);
	lower=bb.getLower();
	upper=bb.getUpper();
	BOOST_CHECK_CLOSE(lower[0], 1.25, tolerance);
	BOOST_CHECK_CLOSE(lower[1], 2.0, tolerance);
	BOOST_CHECK_CLOSE(lower[2], 2.25, tolerance);
	BOOST_CHECK_CLOSE(upper[0], 1.75, tolerance);
	BOOST_CHECK_CLOSE(upper[1], 4.0, tolerance);
	BOOST_CHECK_CLOSE(upper[2], 6.75, tolerance);




}
