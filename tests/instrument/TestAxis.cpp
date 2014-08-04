#define BOOST_TEST_MODULE "Test Axis"
#define BOOST_TEST_DYN_LINK
#include "Axis.h"
#include "Units.h"
#include <Eigen/Geometry>
#include <boost/test/unit_test.hpp>


using namespace SX::Units;
using namespace SX::Instrument;
using Eigen::Vector3d;
const double tolerance=1e-6;


// Necessary since Axis is pure abstract
class TestAxis: public Axis
{
public:
	TestAxis(const std::string& label): Axis(label)
	{}
	~TestAxis(){};
	Transform<double,3,Eigen::Affine> getHomMatrix(double value) const
	{
		return Eigen::Transform<double,3,Eigen::Affine>();
	}
};

BOOST_AUTO_TEST_CASE(Tests_Axis)
{
	TestAxis axis("Omega");
	const std::string& label=axis.getLabel();

	BOOST_CHECK_EQUAL(label,"Omega");
	Vector3d v;
	v << 0,0,1;
	axis.setAxis(v);
	BOOST_CHECK_EQUAL(v,axis.getAxis());

	BOOST_CHECK_EQUAL(axis.getOffset(),0.0);

	axis.setOffset(2.0);
	BOOST_CHECK_EQUAL(axis.getOffset(),2.0);
	axis.addOffset(1.0);
	BOOST_CHECK_EQUAL(axis.getOffset(),3.0);

}