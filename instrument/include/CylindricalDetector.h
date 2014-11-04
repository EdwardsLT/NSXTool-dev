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

#ifndef NSXTOOL_CYLINDRICALDETECTOR_H_
#define NSXTOOL_CYLINDRICALDETECTOR_H_
#include "Detector.h"

namespace SX {
namespace Instrument{


class CylindricalDetector : public Detector
{
public:

	// Constructors and destructor

	//! Default constructor
	CylindricalDetector();
	//! Copy constructor
	CylindricalDetector(const CylindricalDetector& other);
	//! Constructs a cylindrical detector with a given name
	CylindricalDetector(const std::string& name);
	//! Destructor
	virtual ~CylindricalDetector();
	//! Virtual copy constructor
	Detector* clone() const;

	// Operators

	//! Assignment operator
	CylindricalDetector& operator=(const CylindricalDetector& other);

	// Getters and setters

	//! Return the height in angular units (radians) covered by the detector
	double getHeightAngle() const;
	//! Return the width in angular units (radians) covered by the detector
	double getWidthAngle() const;
	//! Set the size of the detector using angular units (radians) rather than lengths. Converted internally in width and height.
	//! Use Units::deg for easy conversion
	void setAngularRange(double widthAngle, double heightAngle);
	//! Set the full height of the detector in Angle, assume the distance is set before
	void setHeightAngle(double hangle);
	//! Set the full width of the detector in Angle, assume the distance is set before
	void setWidthAngle(double wangle);

	// Other methods

	void parse(const ptree& node);

private:
	Eigen::Vector3d getPos(double x,double y) const;
	double _widthAngle;
};

} //End namespace Instrument
} // End namespace SX
#endif /* NSXTOOL_CYLINDRICALDETECTOR_H_ */
