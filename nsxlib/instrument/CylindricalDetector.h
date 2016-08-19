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

#include <boost/property_tree/ptree.hpp>

#include "MonoDetector.h"

namespace SX
{

namespace Instrument
{

class CylindricalDetector : public MonoDetector
{
public:

	//! Static constructor of a CylindricalDetector from a property tree node
	static Detector* create(const proptree::ptree& node);

	//! Construct a CylindricalDetector
	CylindricalDetector();
	//! Construct a CylindricalDetector from another one
	CylindricalDetector(const CylindricalDetector& other);
	//! Constructs a CylindricalDetector with a given name
	CylindricalDetector(const std::string& name);
	//! Constructs a CylindricalDetector from a property tree node
	CylindricalDetector(const proptree::ptree& node);
	//! Return a pointer to a copy of a CylindricalDetector
	Detector* clone() const;
	//! Destructor
	virtual ~CylindricalDetector();

	//! Assignment operator
	CylindricalDetector& operator=(const CylindricalDetector& other);

	//! Set the height of the detector (meters)
	void setHeight(double height);
	//! Set the width of the detector (meters)
	void setWidth(double width);

	//! Set the angular height of the detector (radians)
	void setAngularHeight(double angle);
	//! Set the angular width of the detector (radians)
	void setAngularWidth(double angle);

	//! Returns the position of a given pixel in detector space. This takes into account the detector motions in detector space.
	Eigen::Vector3d getPos(double px,double py) const;

	//! Determine whether detector at rest can receive a scattering event with direction given by Kf. px and py are detector position if true.
	virtual bool hasKf(const Eigen::Vector3d& kf,const Eigen::Vector3d& from, double& px, double& py, double& t) const;

};

} //End namespace Instrument
} // End namespace SX
#endif /* NSXTOOL_CYLINDRICALDETECTOR_H_ */