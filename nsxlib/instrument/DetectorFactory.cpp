// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/DetectorFactory.cpp
//! @brief     Implements module/class/test DetectorFactory
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <stdexcept>
#include <string>

#include "CylindricalDetector.h"
#include "DetectorFactory.h"
#include "FlatDetector.h"

namespace nsx {

DetectorFactory::DetectorFactory()
{
	registerCallback("flat", &FlatDetector::create);
	registerCallback("cylindrical", &CylindricalDetector::create);
}

DetectorFactory::~DetectorFactory()
{
}

} // end namespace nsx

