// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/Axis.h
//! @brief     Implements module/class/test Axis
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <iostream>
#include <string>

#include <yaml-cpp/yaml.h>

#include <Eigen/Dense>
#include <Eigen/Geometry>

namespace nsx {

/** @brief Interface use for homogeneous transform, Rotation and translation, scale
*
* Each axis define a normalized direction (about which one rotates or along which one translates).
* An offset can be defined and a valid range of parameters (lowLimit, HighLimit). The Axis class
* does not maintain a given state and only return the homogeneous matrix for a input value, i.e.
* for a rotation of M_PI about the axis, the method getHomMatrix(M_PI) will return the hom. Matrix.
*/
class Axis {

public:

	//! Static constructor for an Axis
	static Axis* create(const YAML::Node& node);

	//! Default constructor
	Axis();

	//! Copy constructor
	Axis(const Axis& other);

	//! Contruct a default z-axis
	Axis(const std::string& name);

	//! Construct an axis from a vector
	Axis(const std::string& name, const Eigen::Vector3d& axis);

	//! Construct an Axis from a property tree node.
	Axis(const YAML::Node& node);

	//! Assignment operator
	Axis& operator=(const Axis& other);

	//! Destructor
	virtual ~Axis()=0;

	//! Virtual copy constructor
	virtual Axis* clone() const=0;

	//! Give a name to this axis
	void setName(const std::string& name);

	//! Return the axis name
	const std::string& name() const;

	//! Set and normalize the axis direction
	void setAxis(const Eigen::Vector3d& axis);

	//! Get the normalized direction of this axis
	const Eigen::Vector3d& axis() const;

	//! Get the instrument id of the axis
	unsigned int id() const;

	//! Set the instrument id of the axis
	void setId(unsigned int id);

	//! Get the homogeneous (4x4) matrix corresponding to the value
	virtual Eigen::Transform<double,3,Eigen::Affine> affineMatrix(double value) const=0;

	//! Transform vector
    Eigen::Vector3d transform(const Eigen::Vector3d& v, double value);

    //! Set the axis to physical (true) or virtual (true)
	void setPhysical(bool physical);

	//! Return whether or not the axis is physical or not
	bool physical() const;

    virtual std::ostream& printSelf(std::ostream& os) const=0;

protected:
	//! Label of the axis.
	std::string _name;
	//! Axis direction, a normalized vector.
    Eigen::Vector3d _axis;
	//! Defines whether the axis is physical or not. A physical axis is related to metadata.
	bool _physical;
	//! The instrument id (e.g. MAD number for instrument related to ILL ASCII Data).
	unsigned int _id;
};

std::ostream& operator<<(std::ostream& os, const Axis& axis);

} // end namespace nsx
