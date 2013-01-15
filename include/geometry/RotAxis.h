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
#ifndef  NSXTOOL_ROTAXIS_H_
#define NSXTOOL_ROTAXIS_H_
#include "Constants.h"
#include "V3D.h"
#include "Quat.h"
#include "Matrix33.h"
#include <string>

namespace SX
{

/* !
 * \brief Class defining a rotation axis.
 *
 *  Allows to define a rotation axis in 3D space , constructed by a direction vector
 *  and a rotation direction (CW or CCW). The direction vector needs not to be normalized.
 *
 */
class RotAxis
{
public:
	//! Constructor
	RotAxis(const V3D& axis, Units::Rotation direction=Units::CCW,const char* label=0);
	//! Destructor
	~RotAxis();
	//! Get the label of this axis
	std::string& getLabel();
	//! Get the label of this axis
	const std::string& getLabel() const;
	//! Get the rotation matrix associated with this rotation
	//@param angle : rotation angle in radians by default
	//@return rotation matrix
	Matrix33<double> getMatrix(double angle,Units::Angular) const;
	//! Get the quaternion associated with this rotation
	//@param angle : rotation angle in radians by default
	//@return rotation matrix
	Quat getQuat(double angle,Units::Angular) const;
	//! Print information into a stream
	friend std::ostream& operator<<(std::ostream& os, const RotAxis&);
private:
	//! Axis of rotation, normalized vector
	V3D _axis;
	//! Rotation direction
	Units::Rotation _dir;
	//! Label of the axis
	std::string _name;
};

} // End namespace SX

#endif /* NSXTOOL_ROTAXIS_H_ */
