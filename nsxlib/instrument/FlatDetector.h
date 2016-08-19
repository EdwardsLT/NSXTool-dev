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

#include <boost/property_tree/ptree.hpp>

#include "MonoDetector.h"

namespace SX
{

namespace Instrument
{

class FlatDetector : public MonoDetector
{
public:

	//! Static constructor of a FlatDetector from a property tree node
	static Detector* create(const proptree::ptree& node);

	//! Construct a FlatDetector
	FlatDetector();
	//! Construct a FlatDetector from another one
	FlatDetector(const FlatDetector& other);
	//! Construct a FlatDetector with a given name
	FlatDetector(const std::string& name);
	//! Constructs a FlatDetector from a property tree node
	FlatDetector(const proptree::ptree& node);
	//! Return a pointer to a copy of a FlatDetector
	Detector* clone() const;
	//! Destructor
	virtual ~FlatDetector();

	//! Assignment operator
	FlatDetector& operator=(const FlatDetector& other);

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

} // Namespace Instrument

} // Namespace SX


#endif /* NSXTOOL_FLATDETECTOR_H_ */