// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/geometry/Mask.cpp
//! @brief     Implements module/class/test Mask
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "Ellipsoid.h"
#include "Mask.h"

namespace nsx {

Mask::Mask(const AABB& aabb) : _aabb(aabb)
{
}

bool Mask::collide(const Ellipsoid& ellipsoid) const
{
    return _aabb.collide(ellipsoid);
}

AABB& Mask::aabb()
{
    return _aabb;
}

} // end namespace nsx
