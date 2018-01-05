#include <Eigen/Dense>
#include <Eigen/Geometry>

#include <nsxlib/Axis.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/Macros.h>
#include <nsxlib/Units.h>

class TestAxis: public nsx::Axis
{
public:
    TestAxis(const std::string& label, bool physical);
    ~TestAxis();
    TestAxis* clone() const;
    Eigen::Transform<double,3,Eigen::Affine> getHomMatrix(double value) const;
};

TestAxis::TestAxis(const std::string& label, bool physical) : Axis(label)
{
    setPhysical(physical);
}

TestAxis::~TestAxis()
{
}

TestAxis* TestAxis::clone() const
{
    return new TestAxis(*this);
}

Eigen::Transform<double,3,Eigen::Affine> TestAxis::getHomMatrix(double value) const
{
    NSX_UNUSED(value);

    return Eigen::Transform<double,3,Eigen::Affine>();
}

int main()
{
    TestAxis axis("Omega",true);
    const std::string& label=axis.getLabel();

    NSX_CHECK_EQUAL(label,"Omega");
    Eigen::Vector3d v;
    v << 0,0,1;
    axis.setAxis(v);
    NSX_CHECK_EQUAL(v,axis.getAxis());

    return 0;
}
