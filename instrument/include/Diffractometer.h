/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon Eric Pellegrini
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
#ifndef NSXTOOL_DIFFRACTOMETER_H_
#define NSXTOOL_DIFFRACTOMETER_H_
#include <string>

namespace SX
{

namespace Instrument
{

// Forwards
class Detector;
class Sample;
class Source;

class Diffractometer
{
public:

	// Statics

	static Diffractometer* create();

	// Constructors and destructor

	//! Constructs a diffractometer from another one
	Diffractometer(const Diffractometer& other);
	// Virtual copy constructor
	virtual Diffractometer* clone() const=0;
	//! Destructor
	virtual ~Diffractometer()=0;

	// Operators

	//! Assignment operator
	Diffractometer& operator=(const Diffractometer& other);

	// Getters and setters

	//! Set the detector of this diffractometer
	void setDetector(Detector*);
	//! Set the sample of this diffractometer
	void setSample(Sample*);
	//! Set the source of this diffractometer
	void setSource(Source*);
	//! Get the name of this diffractometer
	const std::string& getName() const;
	//! Get the detector of this diffractometer
	Detector* getDetector();
	//! Get the sample of this diffractometer
	Sample* getSample();
	//! Get the source of this diffractometer
	Source* getSource();
	//! Get the type of the diffractometer
	virtual std::string getType() const=0;

protected:

	//! Default constructor
	Diffractometer();
	//! Constructs a diffractometer with a given name
	Diffractometer(const std::string& name);

	std::string _name;
	Detector* _detector;
	Sample* _sample;
	Source* _source;
};

} // Namespace Instrument
} /* Namespace SX */

#endif /* NSXTOOL_DIFFRACTOMETER_H_ */
