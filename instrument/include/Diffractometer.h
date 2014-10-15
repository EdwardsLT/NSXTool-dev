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
	//! Constructs a default diffractometer
	Diffractometer();
	//! Constructs a diffractometer from another one
	Diffractometer(const Diffractometer& other);
	//! Constructs a diffractometer with a given name
	Diffractometer(const std::string& name);
	//! Destructor
	~Diffractometer();
	//! Assignment operator
	Diffractometer& operator=(const Diffractometer& other);
	void setDetector(Detector*);
	Detector* getDetector();
	void setSample(Sample*);
	Sample* getSample();
	void setSource(Source*);
	Source* getSource();
private:
	std::string _name;
	Detector* _detector;
	Sample* _sample;
	Source* _source;
};

} // Namespace Instrument
} /* Namespace SX */

#endif /* NSXTOOL_DIFFRACTOMETER_H_ */
