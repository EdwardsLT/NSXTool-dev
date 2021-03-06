// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/crystal/TestFFTIndexing.cpp
//! @brief     Implements module/class/test TestFFTIndexing
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <Eigen/Dense>

#include <nsxlib/AutoIndexer.h>
#include <nsxlib/CrystalTypes.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/DetectorEvent.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/DirectVector.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/Peak.h>
#include <nsxlib/PeakFilter.h>
#include <nsxlib/PeakFinder.h>
#include <nsxlib/ProgressHandler.h>
#include <nsxlib/ReciprocalVector.h>
#include <nsxlib/Sample.h>
#include <nsxlib/ShapeLibrary.h>
#include <nsxlib/UnitCell.h>

NSX_INIT_TEST

int main()
{
    nsx::Experiment experiment("test", "BioDiff2500");
    nsx::sptrDataSet dataset(new nsx::DataSet("hdf", "gal3.hdf", experiment.diffractometer()));
    experiment.addData(dataset);

    nsx::IndexerParameters params;

    params.maxdim = 70.0;
    params.nSolutions = 10;
    params.nVertices = 10000;
    params.subdiv = 30;
    params.indexingTolerance = 0.2;
    params.niggliTolerance = 1e-3;
    params.gruberTolerance = 4e-2;
    params.niggliReduction = false;
    params.minUnitCellVolume = 20.0;
    params.unitCellEquivalenceTolerance = 0.05;
    params.solutionCutoff = 10.0;

    Eigen::Matrix3d A;
    A << 45.0, 1.0, -2.0, -1.5, 36.0, -2.2, 1.25, -3, 50.0;
    nsx::UnitCell uc(A);
    uc.reduce(params.niggliReduction, params.niggliTolerance, params.gruberTolerance);
    uc = uc.applyNiggliConstraints();

    A = uc.basis();
    Eigen::Matrix3d BU = uc.reciprocalBasis();

    auto reflections = uc.generateReflectionsInShell(0.5, 100, 2.67);

    std::vector<nsx::ReciprocalVector> qs;

    for (auto index: reflections) {
        qs.emplace_back(index.rowVector().cast<double>()*BU);
    }

    auto events = dataset->events(qs);

    std::vector<nsx::sptrPeak> peaks;

     for (auto event: events) {
        nsx::sptrPeak peak(new nsx::Peak(dataset));
        Eigen::Vector3d center = {event._px, event._py, event._frame};

        // dummy shape
        try {
            peak->setShape(nsx::Ellipsoid(center, 1.0));
            peak->setStatus(nsx::Peak::Status::Selected);
            peaks.push_back(peak);

            nsx::MillerIndex hkl(peak->q(), uc);

            NSX_CHECK_ASSERT(hkl.error().norm() < 1e-10);


        } catch(...) {
            // invalid shape, nothing to do
        }
    }

    NSX_CHECK_ASSERT(peaks.size() >= 5900);

    nsx::AutoIndexer indexer;

    for (auto peak: peaks) {
        indexer.addPeak(peak);
    }


    NSX_CHECK_NO_THROW(indexer.autoIndex(params));

    auto solutions = indexer.solutions();

    NSX_CHECK_ASSERT(solutions.size() > 1);
    NSX_CHECK_ASSERT(solutions.front().second > 99.9);

    auto fit_uc = solutions.front().first;

    Eigen::Matrix3d fit_A = fit_uc->basis();
    Eigen::Matrix3d E = fit_A.inverse()*A;

    // square because of the orientation issue
    NSX_CHECK_ASSERT((E*E-Eigen::Matrix3d::Identity()).norm() < 1e-10);

    dataset->close();

    return 0;
}
