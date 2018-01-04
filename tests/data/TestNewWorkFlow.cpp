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
#include <nsxlib/ConvolutionKernel.h>
#include <nsxlib/KernelFactory.h>

#include <nsxlib/Diffractometer.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/Sample.h>
#include <nsxlib/ErfInv.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/Units.h>
#include <nsxlib/ProgressHandler.h>
#include <nsxlib/ReciprocalVector.h>

int main()
{
    nsx::DataReaderFactory factory;

    nsx::sptrExperiment expt(new nsx::Experiment("test", "BioDiff2500"));
    auto diff = expt->getDiffractometer();
    nsx::sptrDataSet dataf(factory.create("hdf", "gal3.hdf", diff));

    expt->addData(dataf);

    nsx::sptrProgressHandler progressHandler(new nsx::ProgressHandler);
    nsx::sptrPeakFinder peakFinder(new nsx::PeakFinder);

    auto callback = [progressHandler] () {
        auto log = progressHandler->getLog();
        for (auto&& msg: log) {
            std::cout << msg << std::endl;
        }
    };

    progressHandler->setCallback(callback);

    nsx::DataList numors;
    numors.push_back(dataf);

    nsx::sptrConvolutionKernel kernel;
    std::string kernelName = "annular";
    auto kernelFactory = nsx::KernelFactory::Instance();
    kernel.reset(kernelFactory->create(kernelName, int(dataf->getNRows()), int(dataf->getNCols())));

    auto k = kernel->getKernel();

    // propagate changes to peak finder
    auto convolver = peakFinder->getConvolver();
    convolver->setKernel(kernel->getKernel());
    peakFinder->setMinComponents(30);
    peakFinder->setMaxComponents(10000);
    peakFinder->setKernel(kernel);
    peakFinder->setSearchConfidence(0.98);
    peakFinder->setIntegrationConfidence(0.997);
    peakFinder->setThresholdType(1); // absolute
    peakFinder->setThresholdValue(15.0);

    peakFinder->setHandler(progressHandler);

    auto found_peaks = peakFinder->find(numors);

    try {
        NSX_CHECK_ASSERT(found_peaks.size() >= 0);
    } catch(...) {
        std::cout << "ERROR: exception in PeakFinder::find()" << std::endl;
    }

    NSX_CHECK_ASSERT(found_peaks.size() >= 800);

    // at this stage we have the peaks, now we index
    nsx::IndexerParameters params;
    nsx::AutoIndexer indexer(progressHandler);

    auto numIndexedPeaks = [&]() -> unsigned int
    {
        unsigned int indexed_peaks = 0;

        for (auto&& peak: found_peaks) {
            if (!peak->isSelected()) {
                continue;
            }
            indexer.addPeak(peak);
            ++indexed_peaks;
        }
        return indexed_peaks;
    };

    unsigned int indexed_peaks = numIndexedPeaks();

    NSX_CHECK_ASSERT(indexed_peaks > 650);
    NSX_CHECK_NO_THROW(indexer.autoIndex(params));

    auto soln = indexer.getSolutions().front();

    // correctly indexed at least 92% of peaks
    NSX_CHECK_ASSERT(soln.second > 92.0);

    // set unit cell
    auto cell = soln.first;
    for (auto&& peak: found_peaks) {
        peak->addUnitCell(cell, true);
    }

    // add cell to sample
    dataf->getDiffractometer()->getSample()->addUnitCell(cell);

    // reintegrate peaks
    const double scale = nsx::getScale(0.997);
    dataf->integratePeaks(found_peaks, scale, 2.0*scale, true);

    indexed_peaks = numIndexedPeaks();
    NSX_CHECK_ASSERT(indexed_peaks > 600);

    // get that DataSet::getEvents works properly
    for (auto peak: found_peaks) {
        if (!peak->isSelected()) {
            continue;
        }

        std::vector<Eigen::RowVector3d> q;
        q.push_back(peak->getQ().rowVector());
        nsx::PeakPredictor predictor(dataf);
        auto events = predictor.getEvents(q);

        NSX_CHECK_ASSERT(events.size() >= 1);

        if (events.size() == 0) {
            continue;
        }

        Eigen::Vector3d p0 = peak->getShape().center();
        Eigen::Vector3d p1;

        double diff = 1e200;

        // q could cross Ewald sphere multiple times, so find best match
        for (auto&& event: events) {
            Eigen::Vector3d pnew = event;
            if ((pnew-p0).squaredNorm() < diff) {
                diff = (pnew-p0).squaredNorm();
                p1 = pnew;
            }
        }
        
        Eigen::RowVector3d q0 = nsx::Peak3D(dataf, nsx::Ellipsoid(p0, 1.0)).getQ().rowVector();
        Eigen::RowVector3d q1 = nsx::Peak3D(dataf, nsx::Ellipsoid(p1, 1.0)).getQ().rowVector();

        NSX_CHECK_CLOSE(p0(0), p1(0), 3.0);
        NSX_CHECK_CLOSE(p0(1), p1(1), 3.0);
        NSX_CHECK_CLOSE(p0(2), p1(2), 3.0);

        NSX_CHECK_CLOSE(q0(0), q1(0), 1.0);
        NSX_CHECK_CLOSE(q0(1), q1(1), 1.0);
        NSX_CHECK_CLOSE(q0(2), q1(2), 1.0);
    }


    nsx::PeakPredictor predictor(dataf);
    predictor._dmin = 2.1;
    predictor._dmax = 50.0;  
    predictor._peakScale = 1.0;
    predictor._bkgScale = 3.0;
    predictor._minimumNeighbors = 10;

    predictor._handler = std::shared_ptr<nsx::ProgressHandler>(new nsx::ProgressHandler());
    auto predicted_peaks = predictor.predictPeaks(false, found_peaks);

    std::cout << "predicted_peaks: " << predicted_peaks.size() << std::endl;
    NSX_CHECK_ASSERT(predicted_peaks.size() > 1600);

    return 0;
}
