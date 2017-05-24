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

#ifndef NSXLIB_ROTAXIS_H
#define NSXLIB_ROTAXIS_H

#include <boost/property_tree/ptree.hpp>

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "Axis.h"

namespace nsx {

/**
 * @brief Class defining a rotation axis.
 *
 *  Allows to define a rotation axis in 3D space , constructed by a direction vector
 *  and a rotation direction (CW or CCW). The direction vector needs not be normalized.
 *
 */
class RotAxis : public Axis {
public:
	enum Direction {CCW,CW};

	//! Static constructor for a RotAxis
	static Axis* create(const boost::property_tree::ptree& node);

	//! Default constructor
	RotAxis();
	//! Copy constructor
	RotAxis(const RotAxis& other);
	//! Constructs an axis with a given name
	explicit RotAxis(const std::string& label);
	//! Explicit
	explicit RotAxis(const std::string& label, const Eigen::Vector3d& axis, Direction direction=CCW);
	//! Construct a RotAxis from a property tree node.
	RotAxis(const boost::property_tree::ptree& node);
	//! Assignment operator
	RotAxis& operator=(const RotAxis& other);
	//! Destructor
	~RotAxis();
	//! Virtual copy constructor
	RotAxis* clone() const;
	//! Get rotation direction.
	void setRotationDirection(Direction);
	// ! Return 0 for CCW and 1 for CW
	Direction getRotationDirection() const;
	//! Get the rotation matrix associated with this rotation
	//@param angle : rotation angle in radians by default, use Units to convert
	//@return rotation matrix
	Eigen::Matrix3d getRotationMatrix(double angle) const;
	//! Return the 4x4 Homogeous matrix corresponding to this transformation.
	Eigen::Transform<double,3,Eigen::Affine> getHomMatrix(double angle) const;
	//! Get the quaternion associated with this rotation
	//@param angle : rotation angle in radians by default
	//@return rotation matrix
	Eigen::Quaterniond getQuat(double angle) const;
	//! Print information into a stream
	friend std::ostream& operator<<(std::ostream& os, const RotAxis&);

protected:
	//! Rotation direction
	Direction _dir;
};

static const RotAxis AxisXCW=RotAxis("XCW",Eigen::Vector3d(1,0,0),RotAxis::CW);
static const RotAxis AxisXCCW=RotAxis("XCCW",Eigen::Vector3d(1,0,0),RotAxis::CCW);
static const RotAxis AxisYCW=RotAxis("YCW",Eigen::Vector3d(0,1,0),RotAxis::CW);
static const RotAxis AxisYCCW=RotAxis("YCCW",Eigen::Vector3d(0,1,0),RotAxis::CCW);
static const RotAxis AxisZCW=RotAxis("ZCW",Eigen::Vector3d(0,0,1),RotAxis::CW);
static const RotAxis AxisZCCW=RotAxis("ZCCW",Eigen::Vector3d(0,0,1),RotAxis::CCW);

} // end namespace nsx

#endif // NSXLIB_ROTAXIS_H
