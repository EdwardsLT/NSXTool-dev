// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/instrument/TestInterpolatedState.cpp
//! @brief     Implements module/class/test TestInterpolatedState
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <array>

#include <Eigen/Dense>

#include <nsxlib/Diffractometer.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/InstrumentState.h>
#include <nsxlib/InterpolatedState.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/ProgressHandler.h>
#include <nsxlib/Sample.h>
#include <nsxlib/ReciprocalVector.h>
#include <nsxlib/Source.h>

NSX_INIT_TEST

void run_test(const char* filename, const char* instrument)
{
    nsx::Experiment experiment("test", instrument);
    auto diffractometer = experiment.diffractometer();
    const auto* detector = diffractometer->detector();
    nsx::sptrDataSet dataset(new nsx::DataSet("hdf", filename, diffractometer));

    experiment.addData(dataset);

    const int nrows = dataset->nRows();
    const int ncols = dataset->nCols();

    const int nframes = dataset->nFrames();

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

        auto state = dataset->interpolatedState(coord[2]);
        Eigen::Matrix3d Jq = state.jacobianQ(coord[0], coord[1]);

        auto pos0 = detector->pixelPosition(coord[0], coord[1]);
        Eigen::Vector3d q0 = state.sampleQ(pos0).rowVector();

        auto pos1 = detector->pixelPosition(coord[0]+dt, coord[1]);
        Eigen::Vector3d dq1 = state.sampleQ(pos1).rowVector().transpose() - q0;

        auto pos2 = detector->pixelPosition(coord[0], coord[1]+dt);
        Eigen::Vector3d dq2 = state.sampleQ(pos2).rowVector().transpose() - q0;

        auto state3 = dataset->interpolatedState(coord[2]+dt);
        Eigen::Vector3d dq3 = state3.sampleQ(pos0).rowVector().transpose() - q0;

        // Numerical Jacobian
        Eigen::Matrix3d NJ;
        NJ.col(0) = dq1 / dt;
        NJ.col(1) = dq2 / dt;
        NJ.col(2) = dq3 / dt;

        NSX_CHECK_SMALL((dq1 - Jq*Eigen::Vector3d(dt,0,0)).norm() / dq1.norm(), 1e-3);
        NSX_CHECK_SMALL((dq2 - Jq*Eigen::Vector3d(0,dt,0)).norm() / dq2.norm(), 1e-3);
        NSX_CHECK_SMALL((dq3 - Jq*Eigen::Vector3d(0,0,dt)).norm() / dq3.norm(), 1e-3);

        // test numerical vs. analytic Jacobian
        NSX_CHECK_SMALL((NJ-Jq).norm() / Jq.norm(), 1e-5);
    }

    dataset->close();
}


int main()
{
    run_test("gal3.hdf", "BioDiff2500");
    run_test("d19_test.hdf", "D19");    

    return 0;
}

