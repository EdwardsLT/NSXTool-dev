#include <cmath>

#include <Eigen/Dense>

#include <nsxlib/Axis.h>
#include <nsxlib/ComponentState.h>
#include <nsxlib/Gonio.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/Units.h>

const double tolerance=1e-6;

int main()
{
    // A simple translation table
    nsx::Gonio t("Translation table");
    t.addTranslation("x",Eigen::Vector3d(1,0,0));
    t.addTranslation("y",Eigen::Vector3d(0,1,0));
    t.addTranslation("z",Eigen::Vector3d(0,0,1));

    t.getAxis("x")->setPhysical(true);
    t.getAxis("y")->setPhysical(true);
    t.getAxis("z")->setPhysical(true);

    // Transform (0,0,0)
    Eigen::Vector3d result=t.transform(Eigen::Vector3d(0,0,0),nsx::ComponentState(nullptr, {1,2,3}));
    NSX_CHECK_CLOSE(result[0],1,tolerance);
    NSX_CHECK_CLOSE(result[1],2,tolerance);
    NSX_CHECK_CLOSE(result[2],3,tolerance);
    // Check that throws if the number of parameters is invalid
    NSX_CHECK_THROW(t.transform(Eigen::Vector3d(0,0,0),nsx::ComponentState(nullptr, {1,2})),std::range_error);
    const auto a0=t.getAxis(0);
    const auto a1=t.getAxis(1);
    const auto a2=t.getAxis(2);
    NSX_CHECK_EQUAL(a0->getLabel(),"x");
    NSX_CHECK_EQUAL(a1->getLabel(),"y");
    NSX_CHECK_EQUAL(a2->getLabel(),"z");

    // Simple goniometer as in Busing Levy
    nsx::Gonio g("Busing Levy convention");
    g.addRotation("omega",Eigen::Vector3d(0,0,1),nsx::RotAxis::CW);
    g.addRotation("chi",Eigen::Vector3d(0,1,0),nsx::RotAxis::CCW);
    g.addRotation("phi",Eigen::Vector3d(0,0,1),nsx::RotAxis::CW);

    // Check that result of combined rotation is Ok.
    double om=12*nsx::deg;
    double chi=24*nsx::deg;
    double phi=55*nsx::deg;
    Eigen::Matrix3d OM;
    OM << cos(om), sin(om), 0,
         -sin(om), cos(om), 0,
          0      ,  0      , 1;
    Eigen::Matrix3d CH;
    CH << cos(chi), 0, sin(chi),
          0 ,       1,      0,
         -sin(chi), 0, cos(chi);
    Eigen::Matrix3d PH;
    PH << cos(phi), sin(phi), 0,
         -sin(phi), cos(phi), 0,
          0      ,  0      , 1;

    Eigen::Vector3d result1=OM*CH*PH*Eigen::Vector3d(1,0,0);

    result=g.transform(Eigen::Vector3d(1,0,0),nsx::ComponentState(nullptr, {om,chi,phi}));
    NSX_CHECK_CLOSE(result[0],result1[0],tolerance);
    NSX_CHECK_CLOSE(result[1],result1[1],tolerance);
    NSX_CHECK_CLOSE(result[2],result1[2],tolerance);

    // Check that this works with row vector as well,
    Eigen::Vector3d result2=g.transform(Eigen::RowVector3d(1,0,0),nsx::ComponentState(nullptr, {om,chi,phi}));
    NSX_CHECK_CLOSE(result[0],result2[0],tolerance);
    NSX_CHECK_CLOSE(result[1],result2[1],tolerance);
    NSX_CHECK_CLOSE(result[2],result2[2],tolerance);

    return 0;
}
