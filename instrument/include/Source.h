/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon, Eric Pellegrini
 Institut Laue-Langevin
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

#ifndef NSXTOOL_SOURCE_H_
#define NSXTOOL_SOURCE_H_

#include <string>

#include <boost/property_tree/ptree.hpp>

#include "Component.h"

namespace SX
{

namespace Instrument
{

class Source : public Component
{
public:

	//! Static constructor of a monochromatic source from a property tree node
	static Source* create(const proptree::ptree& node);

	// Default constructor
	Source();
	//! Copy constructor
	Source(const Source& other);
	//! Constructs a default source with a given name
	Source(const std::string& name);
	//! Constructs a source from a property tree node
	Source(const proptree::ptree& node);
	//! Virtual copy constructor
	virtual Source* clone() const=0;
	//! Destructor
	virtual ~Source()=0;

	//! Assignment operator
	Source& operator=(const Source& other);

	//! Get the wavelength of the source
	virtual double getWavelength() const=0;
	//! Set the wavelength of the source
	virtual void setWavelength(double wavelength)=0;

	//! Get the incoming wave vector
	virtual Eigen::Vector3d getKi() const=0;

	//! Set an offset in wavelength. No effect if _offsetFixed is set to True.
	void setOffset(double offset);
	void setOffsetFixed(bool fixed);
	bool hasOffsetFixed() const;

	//! Set the width of the source slit
	void setWidth(double width);
	//! Get the width of the source slit
	double getWidth() const;

	//! Set the height of the source slit
	void setHeight(double height);
	//! Get the height of the source slit
	double getHeight() const;

protected:
	double _offset;
	bool _offsetFixed;
	double _width;
	double _height;
};

} // end namespace Instrument

} // end namespace SX

#endif /* NSXTOOL_SOURCE_H_ */
