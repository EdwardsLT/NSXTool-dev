// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/geometry/Mask.h
//! @brief     Implements module/class/test Mask
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include "AABB.h"

namespace nsx {

//! Construct a detector mask from an axis-aligned bounding box.
class Mask {

public:

    Mask(const AABB& aabb);

    bool collide(const Ellipsoid& ellipsoid) const;

    AABB& aabb();

private:

    AABB _aabb;
};

} // end namespace nsx
