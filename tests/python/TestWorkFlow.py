import pynsx as nsx
import numpy as np
import unittest
import sys

class TestWorkFlow(unittest.TestCase):
    
    def test(self):
        expt = nsx.Experiment('test', 'BioDiff2500')
        diff = expt.getDiffractometer()
        data = nsx.DataReaderFactory().create("hdf", "gal3.hdf", diff)
        expt.addData(data)
        source = diff.getSource()

        reader = nsx.HDF5DataReader("gal3.hdf", diff)
        data = nsx.DataSet(reader, diff)

        finder = nsx.PeakFinder()
        finder.setMinSize(30)
        finder.setMaxSize(10000)
        finder.setMaxFrames(10)
        finder.setSearchConfidence(0.98)
        finder.setIntegrationConfidence(0.997)
        finder.setConvolver("annular",{})
        finder.setThreshold("absolute",{"intensity":15.0})

        numors = nsx.DataList()
        numors.push_back(data)
        peaks = finder.find(numors)

        selected_peaks = []

        for peak in peaks:
            if peak.isSelected():
                selected_peaks.append(peak)

        self.assertTrue(len(peaks) > 800)
        self.assertTrue(len(selected_peaks) > 650)
               
        indexer = nsx.AutoIndexer(nsx.ProgressHandler())

        for peak in selected_peaks:
            indexer.addPeak(peak)
            peak.getQ()

        params = nsx.IndexerParameters()
        handler = nsx.ProgressHandler()
        indexer.autoIndex(params)

        soln = indexer.getSolutions()[0]

        self.assertTrue(soln[1] > 92.0)

        uc = nsx.UnitCell(soln[0])
        sample = diff.getSample()
        sample.addUnitCell(uc)

        for peak in peaks:
            peak.addUnitCell(uc, True)
            peak.getQ()

        num_peaks = len(peaks)

        predictor = nsx.PeakPredictor(data)
        predictor._dmin = 2.1
        predictor._dmax = 50.0
        predictor._searchRadius = 200.0
        predictor._frameRadius = 5.0
        predictor._peakScale = 1.0
        predictor._bkgScale = 3.0
        predictor._minimumRadius = 5.0
        predictor._minimumPeakDuration = 3.0
        predictor._minimumNeighbors = 10

        predictor._handler = nsx.ProgressHandler()

        predicted_peaks = predictor.predictPeaks(False, peaks)
        self.assertTrue(len(predicted_peaks) > 1600)


if __name__ == '__main__':
    unittest.main()
