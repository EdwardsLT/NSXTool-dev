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

#include "SingleResourceI16.h"

namespace nsx {

const std::vector<std::string>& resource_instruments_I16()
{
    static std::vector<std::string> data = {
	{"---"},
	{"instrument:"},
	{"    name: I16"},
	{"    detector:"},
	{"        name: Pilatus 10k"},
	{"        type: flat"},
	{"        sample_distance:"},
	{"            value: 488.0"},
	{"            units: mm"},
	{"        width:"},
	{"            value: 64.0"},
	{"            units: mm"},
	{"        height:"},
	{"           value: 64.0"},
	{"           units: mm"},
	{"        nrows: 195"},
	{"        ncols: 487"},
	{"        row_min: 0"},
	{"        col_min: 0"},
	{"        data_ordering: TopLeftColMajor"},
	{""},
	{"        goniometer:"},
	{"            name: delta-arm"},
	{"            axis:"},
	{"                - name: delta-arm"},
	{"                  type: rotation"},
	{"                  direction: [1.0,0.0,0.0]"},
	{"                  clockwise: false"},
	{"                  physical: true"},
	{""},
	{"                - name: gamma-arm"},
	{"                  type: rotation"},
	{"                  direction: [0.0,0.0,1.0]"},
	{"                  clockwise: false"},
	{"                  physical: true"},
	{"    sample:"},
	{"        name: sample"},
	{"        goniometer:"},
	{"            name: kappa-goniometer"},
	{"            axis:"},
	{"                - name: phi"},
	{"                  type: rotation"},
	{"                  direction: [1.0,0.0,0.0]"},
	{"                  clockwise: false"},
	{"                  physical: true"},
	{""},
	{"                - name: chi"},
	{"                  type: rotation"},
	{"                  direction: [0.0,1.0,0.0]"},
	{"                  clockwise: false"},
	{"                  physical: true"},
	{""},
	{"                - name: eta"},
	{"                  type: rotation"},
	{"                  direction: [1.0,0.0,0.0]"},
	{"                  clockwise: false"},
	{"                  physical: true"},
	{""},
	{"                - name: mu"},
	{"                  type: rotation"},
	{"                  direction: [0.0,0.0,1.0]"},
	{"                  clockwise: false"},
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
	{"                value: 1.24"},
	{"                units: ang"},
	{"            fwhm:"},
	{"                value: 0.00901"},
	{"                units: ang"},
	{"..."},
    };

    return data;
}

} // end namespace nsx
