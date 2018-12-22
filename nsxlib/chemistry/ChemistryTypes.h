// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/chemistry/ChemistryTypes.h
//! @brief     Implements module/class/test ChemistryTypes
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <complex>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Variant.h"

namespace nsx {

using isotopeContents=std::map<std::string,double>;

enum class ChemicalPropertyType {String=1, Int=2, Double=3, Complex=4, Bool=5};

using isotopeContents = std::map<std::string,double>;

using compoundList = std::vector<std::pair<isotopeContents,double>>;

using isotopeProperties = std::map<std::string,Variant<bool,int,double,std::complex<double>,std::string>>;

} // end namespace nsx
