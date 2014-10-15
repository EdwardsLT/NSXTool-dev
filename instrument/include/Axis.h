/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon Institut Laue-Langevin
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

#ifndef NSXTOOL_AXIS_H_
#define NSXTOOL_AXIS_H_
#include <string>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using Eigen::Vector3d;
using Eigen::Transform;

namespace SX {
namespace Instrument{

/** @brief Interface use for homogeneous transform, Rotation and translation, scale
*
* Each axis define a normalized direction (about which one rotates or along which one translates).
* An offset can be defined and a valid range of parameters (lowLimit, HighLimit). The Axis class
* does not maintain a given state and only return the homogeneous matrix for a input value, i.e.
* for a rotation of M_PI about the axis, the method getHomMatrix(M_PI) will return the hom. Matrix.
*/
class Axis {

public:
	Axis(const std::string& label);
	//! Copy constructor
	Axis(const Axis& other);
	//! Assignment operator
	Axis& operator=(const Axis& other);
	virtual ~Axis()=0;
	//! Give a label to this axis
	void setLabel(const std::string& label);
	//! Return the axis label
	const std::string& getLabel() const;
	//! Give the direction of the axis.
	//! Axis is normalized
	void setAxis(const Vector3d& axis);
	//! Get the normalized direction of this axis
	const Vector3d& getAxis() const;
	//! Set the axis as offsetable or not
	void setOffsetFixed(bool fixed=true);
	//! Return true if the axis offset can't be modidied
	bool hasOffsetFixed() const;
	//! Set the current offset
	void setOffset(double offset);
	//! Add an offset to the existing one
	void addOffset(double offset);
	//! Return the value of the offset
	double getOffset() const;
	//! Set the range of values accessible for this axis
	void setLimits(double, double);
	//! Set the  max value of the range
	void setHighLimit(double);
	//! Set the min value of the range
	void setLowLimit(double);
	//! Get minimum of the range
	double getHighLimit() const;
	//! Get maximum of the range
	double getLowLimit() const;
	//! Get the homogeneous (4x4) matrix corresponding to the value
	virtual Transform<double,3,Eigen::Affine> getHomMatrix(double value) const=0;
	//! Transform vector
	Vector3d transform(const Vector3d& v, double value);
	//! Set the axis to physical (true) or virtual (true)
	void setPhysical(bool physical);
	//! Return whether or not the axis is physical or not
	bool isPhysical() const;
protected:
	//! Check whether a value is within the authorized limits of this axis, throw otherwise.
	void checkRange(double value);
	//! Label of the axis
	std::string _label;
	//! Axis direction, a normalized vector
	Vector3d _axis;
	//! Offset so that finalvalue=offset+given value
	double _offset;
	//! Limits
	double _min, _max;
	//!
	bool _offsetFixed;
	//! true for a physical axis, false for a virtual
	bool _physical;

};

} // End namespace Instrument
} // End namespace SX
#endif /* NSXTOOL_AXIS_H_ */
