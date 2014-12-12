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

#ifndef NSXTOOL_FLATDETECTOR_H_
#define NSXTOOL_FLATDETECTOR_H_
#include "Detector.h"

namespace SX
{

namespace Instrument
{

class FlatDetector : public Detector
{
public:

	// Static methods

	// Static constructor
	static Detector* create(const std::string& name);

	// Constructors and destructor

	//! Default Constructor
	FlatDetector();
	//! Copy constructor
	FlatDetector(const FlatDetector& other);
	//! Constructs a default flat detector with a given name
	FlatDetector(const std::string& name);
	//! Constructs a detector from an XML node
	FlatDetector(const ptree& node);
	//! Destructor
	virtual ~FlatDetector();
	//! Virtual copy constructor
	Detector* clone() const;

	// Operators

	//! Assignment operator
	FlatDetector& operator=(const FlatDetector& other);

	// Getters and setters

	//! Return the height in angular units (radians) covered by the detector
	double getHeightAngle() const;
	//! Return the width in angular units (radians) covered by the detector
	double getWidthAngle() const;
	//! Set the size of the detector using angular units (radians) rather than lengths. Converted internally in width and height.
	//! Use Units::deg for easy conversion
	void setAngularRange(double widthAngle, double heightAngle);
	void setWidthAngle(double wangle);
	void setHeightAngle(double hangle);

	Eigen::Vector3d getPos(double x,double y) const;
};

} // end namespace Instrument
} // End namespace SX


#endif /* NSXTOOL_FLATDETECTOR_H_ */
