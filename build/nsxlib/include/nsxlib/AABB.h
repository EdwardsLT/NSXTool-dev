// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/geometry/AABB.h
//! @brief     Implements module/class/test AABB
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include "GeometryTypes.h"

namespace nsx {


/*! \brief Axis-Aligned Bounding-Box in D dimension.
 *
 * AABB are used to bound objects in a simple-way since
 * their axes are aligned with the coordinates of the world.
 * Used for fast collision detection test, as well as a
 * way to iterate quickly over region of interest in data
 * from images or volumes.
 */
class AABB {

public:

    //! Constructs an unitialized AABB object
    AABB();
    //! Constructs a AABB object from another ABB object
    AABB(const AABB& other);
    //! Constructs a AABB object from two Eigen vectors representing respectively its lower and upper bound
    AABB(const Eigen::Vector3d& lb, const Eigen::Vector3d& ub);
    //! Destructor
    virtual ~AABB()=default;

    //! Assignment operator
    AABB& operator=(const AABB& other);

    //! Translate the AABB.
    void translate(const Eigen::Vector3d& t);

    //! Check whether a point given as Homogeneous coordinate is inside the AABB.
    bool isInside(const Eigen::Vector3d& vector) const;

    //! Return true if the AABB intersects an ellipsoid.
    bool collide(const AABB& aabb) const;
    //! Return true if the AABB intersects an ellipsoid.
    bool collide(const Ellipsoid& ellipsoid) const;

    //! Get a constant reference to the lower bound of the bounding box of the shape
    const Eigen::Vector3d& lower() const;
    //! Set the lower bound of the ellipsoid
    void setLower(const Eigen::Vector3d& lower);

    //! Get a constant reference to the upper bound of the bounding box of the shape
    const Eigen::Vector3d& upper() const;
    //! Set the upper bound of the ellipsoid
    void setUpper(const Eigen::Vector3d& upper);

    //! Return the center of the bounding box of the shape
    Eigen::Vector3d center() const;
    //! Return the extends of the bounding box of the shape
    Eigen::Vector3d extents() const;

    //! Check whether the bounding box of the shape contains the bounding box of the another shape
    bool contains(const AABB& other) const;

    std::ostream& printSelf(std::ostream& os) const;


#ifndef SWIG
    // Macro to ensure that an AABB object can be dynamically allocated.
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
#endif

protected:
    //! The lower bound point
    Eigen::Vector3d _lowerBound;
    //! The upper bound point
    Eigen::Vector3d _upperBound;

};

std::ostream& operator<<(std::ostream& os, const AABB& aabb);

} // end namespace nsx
