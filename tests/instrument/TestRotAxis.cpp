#define BOOST_TEST_MODULE "Test Rotation Axis"
#define BOOST_TEST_DYN_LINK
#include "RotAxis.h"
#include "Units.h"
#include <cmath>
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>

using namespace SX::Units;
using namespace SX::Instrument;
using Eigen::Vector3d;
using Eigen::Matrix3d;
const double tolerance=1e-6;
BOOST_AUTO_TEST_CASE(Test_Rot_Axis)
{
	//Empty Rotation axis initialize to (0,0,1)
    SX::Instrument::RotAxis a;
    Vector3d axis=a.getAxis();
    BOOST_CHECK(axis[0]==0);
    BOOST_CHECK(axis[1]==0);
    BOOST_CHECK(axis[2]==1);
    BOOST_CHECK_CLOSE(a.getOffset(),0.0,tolerance);
    a.setRotationDirection(CCW);
    // Check that a rotation CCW of 45.0 degrees brings the 1,0,0 vector into 1/2.(sqrt(2),sqrt(2),0)
    Vector3d transf=a.getMatrix(45.0*deg)*Vector3d(1,0,0);
    BOOST_CHECK_CLOSE(transf[0],0.5*sqrt(2.0),tolerance);
    BOOST_CHECK_CLOSE(transf[1],0.5*sqrt(2.0),tolerance);
    BOOST_CHECK_CLOSE(transf[2],0.0,tolerance);
    // Check same for CCW of 0,1,0
    transf=a.getMatrix(45.0*deg)*Vector3d(0,1,0);
	BOOST_CHECK_CLOSE(transf[0],-0.5*sqrt(2.0),tolerance);
	BOOST_CHECK_CLOSE(transf[1],0.5*sqrt(2.0),tolerance);
	BOOST_CHECK_CLOSE(transf[2],0.0,tolerance);

	// Switch rotation direction
	a.setRotationDirection(CW);
	transf=a.getMatrix(45.0*deg)*Vector3d(1,0,0);
	BOOST_CHECK_CLOSE(transf[0],0.5*sqrt(2.0),tolerance);
	BOOST_CHECK_CLOSE(transf[1],-0.5*sqrt(2.0),tolerance);
	BOOST_CHECK_CLOSE(transf[2],0.0,tolerance);
	// Check same for CCW of 0,1,0
	transf=a.getMatrix(45.0*deg)*Vector3d(0,1,0);
	BOOST_CHECK_CLOSE(transf[0],0.5*sqrt(2.0),tolerance);
	BOOST_CHECK_CLOSE(transf[1],0.5*sqrt(2.0),tolerance);
	BOOST_CHECK_CLOSE(transf[2],0.0,tolerance);

	// Ensure that offset is taken into account
	a.setRotationDirection(CCW);
	a.setOffset(1.0*deg);
	transf=a.getMatrix(44.0*deg)*Vector3d(1,0,0);
	BOOST_CHECK_CLOSE(transf[0],0.5*sqrt(2.0),tolerance);
	BOOST_CHECK_CLOSE(transf[1],0.5*sqrt(2.0),tolerance);
	BOOST_CHECK_CLOSE(transf[2],0.0,tolerance);
}
