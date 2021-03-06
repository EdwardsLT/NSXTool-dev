# **************************************************************************
#
# NSXTool: Neutron Single Xtal analysis Toolkit
#
# @file      tests/python/TestPeakFinder.py
# @brief     Implements class TestPeakFinder
#
# @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
# @license   GNU General Public License v3 or higher (see COPYING)
# @copyright Institut Laue Langevin 2013-now
# @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
#
# **************************************************************************

import pynsx as nsx
import numpy as np
import ctypes as c
import unittest

class TestPeakFinder(unittest.TestCase):
    def test(self):

        datasets = nsx.DataList()

        peakFinder = nsx.PeakFinder(datasets)
        ph = nsx.ProgressHandler()

        #peakFinder.setIntegrationConfidence(0.997)        
        #peakFinder.setSearchConfidence(0.97)        
        
        peakFinder.setMaxSize(10000)
        self.assertTrue(peakFinder.maxSize() == 10000)

        peakFinder.setMinSize(10)
        self.assertTrue(peakFinder.minSize() == 10)

        peakFinder.setMaxFrames(10)
        self.assertTrue(peakFinder.maxFrames() == 10)        
        
if __name__ == '__main__':
    unittest.main()

  
