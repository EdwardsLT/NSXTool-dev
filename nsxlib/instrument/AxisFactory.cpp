// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/AxisFactory.cpp
//! @brief     Implements module/class/test AxisFactory
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <stdexcept>
#include <string>

#include "AxisFactory.h"
#include "RotAxis.h"
#include "TransAxis.h"

namespace nsx {

AxisFactory::AxisFactory()
{
    registerCallback("rotation",&RotAxis::create);
    registerCallback("translation",&TransAxis::create);
}

AxisFactory::~AxisFactory()
{
}

} // end namespace nsx

