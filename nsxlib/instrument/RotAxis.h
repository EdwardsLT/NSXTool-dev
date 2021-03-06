// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/RotAxis.h
//! @brief     Implements module/class/test RotAxis
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <yaml-cpp/yaml.h>

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "Axis.h"

namespace nsx {

//! \brief Class defining a rotation axis.
//!
//! Allows to define a rotation axis in 3D space , constructed by a direction vector
//! and a rotation direction (CW or CCW). The direction vector needs not be normalized.
class RotAxis: public Axis {
public:
	//! Axis direction (clockwise, counter-clockwise)
	enum class Direction {CW,CCW};

	//! Static constructor for a RotAxis
	static Axis* create(const YAML::Node& node);

	//! Default constructor
	RotAxis();
	//! Copy constructor
	RotAxis(const RotAxis& other);
	//! Constructs an axis with a given name
	explicit RotAxis(const std::string& label);
	//! Explicit
	explicit RotAxis(const std::string& label, const Eigen::Vector3d& axis, Direction direction=Direction::CCW);
	//! Construct a RotAxis from a property tree node.
	RotAxis(const YAML::Node& node);
	//! Assignment operator
	RotAxis& operator=(const RotAxis& other);
	//! Destructor
	~RotAxis();
	//! Virtual copy constructor
	RotAxis* clone() const;
	//! Get rotation direction.
	void setRotationDirection(Direction);
	//! Return rotation direction: 0 for CCW and 1 for CW
	Direction rotationDirection() const;
	//! Get the rotation matrix associated with this rotation
	//@param angle : rotation angle in radians by default, use Units to convert
	//@return rotation matrix
	Eigen::Matrix3d rotationMatrix(double angle) const;
	//! Return the 4x4 Homogeous matrix corresponding to this transformation.
	Eigen::Transform<double,3,Eigen::Affine> affineMatrix(double angle) const;
	//! Get the quaternion associated with this rotation
	//@param angle : rotation angle in radians by default
	//@return rotation matrix
	Eigen::Quaterniond quaternion(double angle) const;

    std::ostream& printSelf(std::ostream& os) const override;

protected:

	//! Rotation direction
	Direction _dir;
};

} // end namespace nsx
