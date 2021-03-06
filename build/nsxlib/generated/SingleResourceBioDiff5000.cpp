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

#include "SingleResourceBioDiff5000.h"

namespace nsx {

const std::vector<std::string>& resource_instruments_BioDiff5000()
{
    static std::vector<std::string> data = {
	{"---"},
	{"instrument:"},
	{"    name: BioDiff5000"},
	{"    detector:"},
	{"        type: cylindrical"},
	{"        name: banana"},
	{"        sample_distance:"},
	{"            value: 199.5"},
	{"            units: mm"},
	{"        angular_width:"},
	{"            value: 360.0"},
	{"            units: deg"},
	{"        height:"},
	{"            value: 0.45"},
	{"            units: m"},
	{"        row_min: 0"},
	{"        col_min: 0"},
	{"        nrows: 1800"},
	{"        ncols: 5000"},
	{"        data_ordering: TopLeftRowMajor"},
	{"        goniometer:"},
	{"            name: detector-gonio"},
	{"            axis:"},
	{"                - name: 2theta(gamma)"},
	{"                  type: rotation"},
	{"                  id: 1"},
	{"                  direction: [0.0,0.0,1.0]"},
	{"                  clockwise: true"},
	{"                  physical: true"},
	{""},
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
	{"                  clockwise: true"},
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
	{"            name: mono"},
	{"            width:"},
	{"                value: 1.0"},
	{"                units: mm"},
	{"            height:"},
	{"                value: 1.0"},
	{"                units: mm"},
	{"            wavelength:"},
	{"                value: 2.6734"},
	{"                units: ang"},
	{"            fwhm:"},
	{"                value: 0.00901"},
	{"                units: ang"},
	{"..."},
    };

    return data;
}

} // end namespace nsx
