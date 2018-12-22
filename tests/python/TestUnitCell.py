# **************************************************************************
#
# NSXTool: Neutron Single Xtal analysis Toolkit
#
# @file      tests/python/TestUnitCell.py
# @brief     Implements class TestUnitCell
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

class TestUnitCell(unittest.TestCase):
    a = 6.32
    b = 7.22
    c = 3.44
    # todo: deg is not exported in python
    deg = np.pi / 180.0
    alpha = 90*deg
    parameters = [a,b,c,alpha]

    def setUp(self):
        a,b,c,alpha = self.parameters
        self.cell = nsx.UnitCell(a,b,c,alpha,alpha,alpha)

    def testParameters(self):
        cell = self.cell
        ch = cell.character()
        
        a,b,c,alpha = self.parameters
        
        self.assertAlmostEqual(ch.a,a)
        self.assertAlmostEqual(ch.b,b)
        self.assertAlmostEqual(ch.c,c)
        
        self.assertAlmostEqual(ch.alpha,alpha)
        self.assertAlmostEqual(ch.beta,alpha)
        self.assertAlmostEqual(ch.gamma,alpha)
        

if __name__ == '__main__':
    unittest.main()

  
