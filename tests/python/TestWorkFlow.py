# **************************************************************************
#
# NSXTool: Neutron Single Xtal analysis Toolkit
#
# @file      tests/python/TestWorkFlow.py
# @brief     Implements class TestWorkFlow
#
# @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
# @license   GNU General Public License v3 or higher (see COPYING)
# @copyright Institut Laue Langevin 2013-now
# @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
#
# **************************************************************************

import pynsx as nsx
import numpy as np
import unittest
import sys

class TestWorkFlow(unittest.TestCase):
    
    def test(self):
        
        experiment = nsx.Experiment('test', 'BioDiff2500')
        dataset = nsx.DataSet("hdf", "gal3.hdf", experiment.diffractometer())
        experiment.addData(dataset)

        reader = nsx.HDF5DataReader("gal3.hdf", experiment.diffractometer())

        datasets = nsx.DataList()
        datasets.push_back(dataset)

        finder = nsx.PeakFinder(datasets)
        finder.setMinSize(30)
        finder.setMaxSize(10000)
        finder.setMaxFrames(10)

        convolver = nsx.AnnularConvolver({});

        finder.setConvolver(convolver)
        finder.setThreshold(15.0)

        finder.run()

        peaks = finder.peaks()

        selected_peaks = []

        for peak in peaks:
            if peak.enabled():
                selected_peaks.append(peak)

        self.assertTrue(len(peaks) > 800)
        self.assertTrue(len(selected_peaks) > 650)
               
        indexer = nsx.AutoIndexer(nsx.ProgressHandler())

        for peak in selected_peaks:
            
            d = 1.0 / np.linalg.norm(peak.q().rowVector())

            if (d < 2.0):
                continue

            indexer.addPeak(peak)
            peak.q()

        params = nsx.IndexerParameters()
        handler = nsx.ProgressHandler()
        indexer.autoIndex(params)

        soln = indexer.solutions()[0]

        self.assertTrue(soln[1] > 92.0)

        uc = nsx.UnitCell(soln[0])

        for peak in peaks:
            peak.setUnitCell(uc)
            peak.q()

        num_peaks = len(peaks)

        return

        #todo: fix up the library test

        library = nsx.ShapeLibrary()

        library_size = 0

        for peak in peaks:
            if not peak.enabled():
                continue
            if library.addPeak(peak):
                library_size +=1

if __name__ == '__main__':
    unittest.main()
