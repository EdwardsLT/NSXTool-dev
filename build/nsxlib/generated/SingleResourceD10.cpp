// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/chemistry/IsotopeDatabaseManager.h
//! @brief     Implements module/class/test IsotopeDatabaseManager
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "SingleResourceD10.h"

namespace nsx {

const std::vector<std::string>& resource_instruments_D10()
{
    static std::vector<std::string> data = {
	{"---"},
	{"instrument:"},
	{"    name: D10"},
	{"    detector:"},
	{"        name: flat"},
	{"        type: flat"},
	{"        sample_distance:"},
	{"            value: 488.0"},
	{"            units: mm"},
	{"        width:"},
	{"            value: 80.0"},
	{"            units: mm"},
	{"        height:"},
	{"            value: 80.0"},
	{"            units: mm"},
	{"        row_min: 0"},
	{"        col_min: 0"},
	{"        nrows: 32"},
	{"        ncols: 32"},
	{"        data_ordering: BottomRightColMajor"},
	{"        goniometer:"},
	{"            name: detector-gonio"},
	{"            axis:"},
	{"                - name: 2theta(gamma)"},
	{"                  type: rotation"},
	{"                  id: 1"},
	{"                  direction: [0.0,0.0,1.0]"},
	{"                  clockwise: false"},
	{"                  physical: true"},
	{"                  "},
	{"                - name: 2theta(nu)"},
	{"                  type: rotation"},
	{"                  direction: [1.0,0.0,0.0]"},
	{"                  clockwise: true"},
	{"                  physical: false"},
	{"    sample:"},
	{"        name: sample"},
	{"        goniometer:"},
	{"            name: sample-gonio"},
	{"            axis:"},
	{"                - name: omega"},
	{"                  type: rotation"},
	{"                  id: 2"},
	{"                  direction: [0.0,0.0,1.0]"},
	{"                  clockwise: false"},
	{"                  physical: true"},
	{""},
	{"                - name: chi"},
	{"                  type: rotation"},
	{"                  id: 3"},
	{"                  direction: [0.0,1.0,0.0]"},
	{"                  clockwise: false"},
	{"                  physical: true"},
	{""},
	{"                - name: phi"},
	{"                  type: rotation"},
	{"                  id: 4"},
	{"                  direction: [0.0,0.0,1.0]"},
	{"                  clockwise: true"},
	{"                  physical: true"},
	{"    source:"},
	{"        name: monochromatic source"},
	{"        monochromator:"},
	{"            name: Cu(220)"},
	{"            width:"},
	{"                value: 60.0"},
	{"                units: mm"},
	{"            height:"},
	{"                value: 80.0"},
	{"                units: mm"},
	{"            wavelength:"},
	{"                value: 0.8409"},
	{"                units: ang"},
	{"            fwhm:"},
	{"                value: 0.00901"},
	{"                units: ang"},
	{"..."},
    };

    return data;
}

} // end namespace nsx
