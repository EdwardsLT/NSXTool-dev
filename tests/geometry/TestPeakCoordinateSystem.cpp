#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <Eigen/Dense>

#include <nsxlib/NSXTest.h>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/DataReaderFactory.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/DetectorEvent.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/PeakCoordinateSystem.h>

NSX_INIT_TEST

void run_test(const char* filename, const char* instrument)
{
    std::cout << "Running test of " << filename << ", " << instrument << std::endl;

    nsx::DataReaderFactory factory;

    nsx::sptrExperiment expt(new nsx::Experiment("test", instrument));
    auto diff = expt->getDiffractometer();
    auto detector = diff->getDetector();
    nsx::sptrDataSet dataf(factory.create("hdf", filename, diff));

    expt->addData(dataf);

    const int nrows = dataf->nRows();
    const int ncols = dataf->nCols();


    const int nframes = dataf->nFrames();

    const std::array<double, 9> fractions = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

    // different places to check the coordinate calculation
    std::vector<Eigen::Vector3d> coords;

    for (auto dx: fractions) {
        for (auto dy: fractions) {
            for (auto df: fractions) {
                coords.emplace_back(Eigen::Vector3d(dx*ncols, dy*nrows, df*nframes));
            }
        }
    }
    
    nsx::sptrPeak3D peak(new nsx::Peak3D(dataf));

    for (auto coord: coords) {
        peak->setShape(nsx::Ellipsoid(coord, 2.0));
        nsx::PeakCoordinateSystem frame(peak);

        auto J = frame.jacobian();

        const double dt = 1e-1;

        Eigen::Vector3d e0 = frame.transform(nsx::DetectorEvent(coord[0], coord[1], coord[2]));
        Eigen::Vector3d e1 = frame.transform(nsx::DetectorEvent(coord[0]+dt, coord[1], coord[2]));
        Eigen::Vector3d e2 = frame.transform(nsx::DetectorEvent(coord[0], coord[1]+dt, coord[2]));
        Eigen::Vector3d e3 = frame.transform(nsx::DetectorEvent(coord[0], coord[1], coord[2]+dt));

        Eigen::Vector3d y1 = J*Eigen::Vector3d(dt, 0, 0);
        Eigen::Vector3d y2 = J*Eigen::Vector3d(0, dt, 0);
        Eigen::Vector3d y3 = J*Eigen::Vector3d(0, 0, dt);

        auto detector = peak->data()->diffractometer()->getDetector();

        NSX_CHECK_SMALL(e0.norm(), 1e-8);
        std::cout << e0.transpose() << std::endl;
        NSX_CHECK_SMALL((e1-y1).norm() / e1.norm(), 1e-1);
        NSX_CHECK_SMALL((e2-y2).norm() / e2.norm(), 1e-1);
        NSX_CHECK_SMALL((e3-y3).norm() / e3.norm(), 1e-1);
        
        auto sigmaD = frame.estimateDivergence();
        auto sigmaM = frame.estimateMosaicity();

        auto detector_shape = frame.detectorShape(sigmaD, sigmaM);

        peak->setShape(detector_shape);

        NSX_CHECK_CLOSE(frame.estimateDivergence(), sigmaD, 1e-6);
        NSX_CHECK_CLOSE(frame.estimateMosaicity(), sigmaM, 1e-6);

        auto standard_shape = frame.standardShape();
        Eigen::Matrix3d cov = standard_shape.inverseMetric();

        NSX_CHECK_CLOSE(cov(0,0), sigmaD*sigmaD, 1e-4);
        NSX_CHECK_CLOSE(cov(1,1), sigmaD*sigmaD, 1e-4);
        NSX_CHECK_CLOSE(cov(2,2), sigmaM*sigmaM, 1e-4);

        NSX_CHECK_SMALL(cov(0,1), 1e-8);
        NSX_CHECK_SMALL(cov(0,2), 1e-8);
        NSX_CHECK_SMALL(cov(1,2), 1e-8);
    }
}


int main()
{
    run_test("gal3.hdf", "BioDiff2500");
    run_test("d19_test.hdf", "D19");    

    return 0;
}