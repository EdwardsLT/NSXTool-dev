/*
 * nsxtool : Neutron Single Crystal analysis toolkit
    ------------------------------------------------------------------------------------------
    Copyright (C)
    2012- Laurent C. Chapon, Eric C. Pellegrini Institut Laue-Langevin
    BP 156
    6, rue Jules Horowitz
    38042 Grenoble Cedex 9
    France
    chapon[at]ill.fr
    pellegrini[at]ill.fr

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef NSXLIB_AABB_H
#define NSXLIB_AABB_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include "../geometry/GeometryTypes.h"

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
    virtual ~AABB();
    //! Assignment operator
    AABB& operator=(const AABB& other);

    //! Scale isotropically the AABB.
    void scale(double value);
    //! Scale anisotropically the AABB.
    void scale(const Eigen::Vector3d& scale);
    //! Rotate the AABB.
    void rotate(const Eigen::Matrix3d& eigenvectors);
    //! Translate the AABB.
    void translate(const Eigen::Vector3d& t);

    //! Check whether a point given as Homogeneous coordinate is inside the AABB.
    bool isInside(const HomVector& vector) const;
    //! Return true if the AABB intersects an ellipsoid.
    bool collide(const AABB& other) const;
    //! Return true if the AABB intersects an ellipsoid.
    bool collide(const Ellipsoid& other) const;
    //! Return true if the AABB intersects an ellipsoid.
    bool intercept(const Ellipsoid& other) const;

    //! Compute the intersection between the AABB and a given ray.
    //! Return true if an intersection was found, false otherwise.
    //! If the return value is true the intersection "times" will be stored
    //! in t1 and t2 in such a way that from + t1*dir and from + t2*dir are
    //! the two intersection points between the ray and this shape.
    bool rayIntersect(const Eigen::Vector3d& from, const Eigen::Vector3d& dir, double& t1, double& t2) const;

    //! Set the lower and upper bounds of the shape bounding box
    void setBounds(const Eigen::Vector3d& lb, const Eigen::Vector3d& ub);
    //! Set the lower bound of the shape bounding box
    void setLower(const Eigen::Vector3d& lb);
    //! Set the upper bound of the shape bounding box
    void setUpper(const Eigen::Vector3d& lb);

    //! Get a constant reference to the lower bound of the bounding box of the shape
    const Eigen::Vector3d& getLower() const;
    //! Get a constant reference to the upper bound of the bounding box of the shape
    const Eigen::Vector3d& getUpper() const;
    //! Return the center of the bounding box of the shape
    Eigen::Vector3d getAABBCenter() const;
    //! Return the extends of the bounding box of the shape
    Eigen::Vector3d getAABBExtents() const;
    //! Returns the volume of the bounding box of the shape
    double AABBVolume() const;

    //! Check whether a given point is inside the AABB of the shape
    bool isInsideAABB(const std::initializer_list<double>& point) const;
    //! Check whether a given point is inside the AABB of the shape
    bool isInsideAABB(const Eigen::Vector3d& point) const;
    //! Check whether a given Homogeneous vector is inside the AABB of the shape
    bool isInsideAABB(const HomVector& point) const;
    //! Translate the bounding box
    void translateAABB(const Eigen::Vector3d&);
    //! Scale by a constant factor
    void scaleAABB(double);
    //! Scale the bounding box
    void scaleAABB(const Eigen::Vector3d&);
    void rotate(double angle,const Eigen::Vector3d& axis,Direction direction=Direction::CCW);

    //! Check whether the bounding box of the shape contains the bounding box of the another shape
    bool contains(const AABB& other) const;

    std::ostream& printSelf(std::ostream& os) const;

#ifndef SWIG
    // Macro to ensure that an AABB object can be dynamically allocated.
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
#endif

protected:
    // The lower bound point
    Eigen::Vector3d _lowerBound;
    // The upper bound point
    Eigen::Vector3d _upperBound;

};

std::ostream& operator<<(std::ostream& os, const AABB& aabb);

} // end namespace nsx

#endif // NSXLIB_AABB_H
