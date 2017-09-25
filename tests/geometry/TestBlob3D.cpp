#include <cmath>

#include <Eigen/Dense>

#include <nsxlib/geometry/Blob3D.h>
#include <nsxlib/utils/NSXTest.h>

const double tolerance=1e-5;

int main()
{
    nsx::Blob3D blob;
    // Create a set of points for a 3D Gaussian.
    double c_x=12.0;
    double c_y=15.0;
    double c_z=22.0;
    double sx2=2.0, sy2=3.0, sz2=5.0;
    double prefactor=1.0/std::pow(2.0*M_PI,1.5)/sqrt(sx2*sy2*sz2);
    double tot=0;
    for (int i=0;i<50;++i)
    {
        for (int j=0;j<50;++j)
        {
            for (int k=0;k<50;++k)
            {
            double mass=prefactor*exp(-0.5*(std::pow(i-c_x,2)/sx2+std::pow(j-c_y,2)/sy2+std::pow(k-c_z,2)/sz2));
            blob.addPoint(i,j,k,mass);
            tot+=mass;
            }
        }
    }
    NSX_CHECK_CLOSE(tot,1.0,tolerance);
    NSX_CHECK_CLOSE(tot,blob.getMass(),tolerance);
    Eigen::Vector3d center,eigVal;
    Eigen::Matrix3d eigVec;
    double sigma1=0.682689492;
    blob.toEllipsoid(sigma1,center,eigVal,eigVec);
    // Check that the center is OK
    NSX_CHECK_CLOSE(center(0),c_x,tolerance);
    NSX_CHECK_CLOSE(center(1),c_y,tolerance);
    NSX_CHECK_CLOSE(center(2),c_z,tolerance);
    // Check the semi_axes
    NSX_CHECK_CLOSE(eigVal(0),sqrt(sx2),tolerance);
    NSX_CHECK_CLOSE(eigVal(1),sqrt(sy2),tolerance);
    NSX_CHECK_CLOSE(eigVal(2),sqrt(sz2),tolerance);

    // Check the eigenVectors
    NSX_CHECK_CLOSE(std::abs((eigVec.col(0))(0)),1.0,tolerance);
    NSX_CHECK_CLOSE(std::abs((eigVec.col(1))(1)),1.0,tolerance);
    NSX_CHECK_CLOSE(std::abs((eigVec.col(2))(2)),1.0,tolerance);
}
