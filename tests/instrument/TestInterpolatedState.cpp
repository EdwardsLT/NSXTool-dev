#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <Eigen/Dense>

#include <nsxlib/AutoIndexer.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/PeakPredictor.h>
#include <nsxlib/DataReaderFactory.h>
#include <nsxlib/PeakFinder.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Gonio.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/InstrumentState.h>
#include <nsxlib/InterpolatedState.h>
#include <nsxlib/Sample.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/Sample.h>
#include <nsxlib/Source.h>
#include <nsxlib/ErfInv.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/Units.h>
#include <nsxlib/ProgressHandler.h>
#include <nsxlib/ReciprocalVector.h>

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
   
    for (auto coord: coords) {
        const double dt = 1e-3;
        auto detector = dataf->diffractometer()->getDetector();

        auto state = dataf->interpolatedState(coord[2]);
        Eigen::Matrix3d Jq = state.jacobianQ(coord[0], coord[1]);

        auto pos0 = detector->pixelPosition(coord[0], coord[1]);
        Eigen::Vector3d q0 = state.sampleQ(pos0).rowVector();

        auto pos1 = detector->pixelPosition(coord[0]+dt, coord[1]);
        Eigen::Vector3d dq1 = state.sampleQ(pos1).rowVector().transpose() - q0;

        auto pos2 = detector->pixelPosition(coord[0], coord[1]+dt);
        Eigen::Vector3d dq2 = state.sampleQ(pos2).rowVector().transpose() - q0;

        auto state3 = dataf->interpolatedState(coord[2]+dt);
        Eigen::Vector3d dq3 = state3.sampleQ(pos0).rowVector().transpose() - q0;

        // Numerical Jacobian
        Eigen::Matrix3d NJ;
        NJ.col(0) = dq1 / dt;
        NJ.col(1) = dq2 / dt;
        NJ.col(2) = dq3 / dt;

        const double K = 50;

        NSX_CHECK_SMALL((dq1 - Jq*Eigen::Vector3d(dt,0,0)).norm() / dq1.norm(), 1e-3);
        NSX_CHECK_SMALL((dq2 - Jq*Eigen::Vector3d(0,dt,0)).norm() / dq2.norm(), 1e-3);
        NSX_CHECK_SMALL((dq3 - Jq*Eigen::Vector3d(0,0,dt)).norm() / dq3.norm(), 1e-3);

        // test numerical vs. analytic Jacobian
        NSX_CHECK_SMALL((NJ-Jq).norm() / Jq.norm(), 1e-5);
    }
}


int main()
{
    run_test("gal3.hdf", "BioDiff2500");
    run_test("d19_test.hdf", "D19");    

    return 0;
}
