#include <cmath>

#include <Eigen/Dense>

#include <nsxlib/instrument/CylindricalDetector.h>
#include <nsxlib/instrument/Gonio.h>
#include <nsxlib/utils/NSXTest.h>
#include <nsxlib/utils/Units.h>

const double tolerance=1e-3;

int main()
{
    #pragma message "todo: fix this test"
    #if 0
    nsx::CylindricalDetector d("D19-detector");
    d.setDistance(764*nsx::mm);
    d.setAngularWidth(120.0*nsx::deg);
    d.setHeight(40.0*nsx::cm);
    d.setNPixels(640,256);

    nsx::DetectorEvent ev1(&d, 319.5, 127.5, 0.0, {});

    // This should be the center of the detector at rest at (0,0.764,0)
    Eigen::Vector3d center=ev1.getPixelPosition();
    NSX_CHECK_SMALL(center[0],tolerance);
    NSX_CHECK_CLOSE(center[1],0.764,tolerance);
    NSX_CHECK_SMALL(center[2],tolerance);
    // Should be center of the detector so gamma,nu=0 at rest
    double gamma,nu;
    ev1.getGammaNu(gamma,nu);
    NSX_CHECK_SMALL(gamma,tolerance);
    NSX_CHECK_SMALL(nu,tolerance);
    double th2=ev1.get2Theta();
    NSX_CHECK_SMALL(th2,tolerance);

    // Attach a gonio
    nsx::sptrGonio g(new nsx::Gonio("gamma-arm"));
    g->addRotation("gamma",Eigen::Vector3d(0,0,1),nsx::RotAxis::CW);
    d.setGonio(g);
    // Put detector at 90 deg, event should point along x

    nsx::DetectorEvent ev2(&d, 319.5, 127.5, 0.0, {90.0*nsx::deg});
    center=ev2.getPixelPosition();
    NSX_CHECK_CLOSE(center[0],0.764,tolerance);
    NSX_CHECK_SMALL(center[1],0.001);
    NSX_CHECK_SMALL(center[2],0.001);
    ev2.getGammaNu(gamma,nu);
    NSX_CHECK_CLOSE(gamma,90*nsx::deg,tolerance);
    NSX_CHECK_SMALL(nu,0.001);

    th2 = ev2.get2Theta();
    NSX_CHECK_CLOSE(th2,90.0*nsx::deg,tolerance);
    // Scattering in the center of the detector with wavelength 2.0
    // should get kf = (0.5,0,0)
    Eigen::Vector3d kf=ev2.getKf(2.0);
    NSX_CHECK_CLOSE(kf[0],0.5,tolerance);
    NSX_CHECK_SMALL(kf[1],0.001);
    NSX_CHECK_SMALL(kf[2],0.001);
    // Should be 45 deg in the x,-y plane
    Eigen::Vector3d Q=ev2.getQ(2.0);
    NSX_CHECK_CLOSE(Q[0],0.5,tolerance);
    NSX_CHECK_CLOSE(Q[1],-0.5,tolerance);
    NSX_CHECK_SMALL(Q[2],0.001);

    // Check that detector receive an scattering vector at the right position
    double px, py,t;
    Eigen::Vector3d from(0,0,0);
    d.receiveKf(px,py,kf,from,t,{90.0*nsx::deg});
    NSX_CHECK_CLOSE(px,319.5,tolerance);
    NSX_CHECK_CLOSE(py,127.5,tolerance);

    d.receiveKf(px,py,Eigen::Vector3d(0.0,0.764,0.10),from,t,{0.0*nsx::deg});
    NSX_CHECK_CLOSE(px,319.5,tolerance);
    NSX_CHECK_CLOSE(py,191.25,tolerance);

    d.receiveKf(px,py,Eigen::Vector3d(1,0,0),from,t,{90.0*nsx::deg});
    NSX_CHECK_CLOSE(px,319.5,tolerance);
    NSX_CHECK_CLOSE(py,127.5,tolerance);

    return 0;
    #endif
}
