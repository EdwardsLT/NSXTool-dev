// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/chemistry/Material.h
//! @brief     Implements module/class/test Material
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <map>
#include <ostream>
#include <string>

#include "ChemistryTypes.h"
#include "IsotopeDatabaseManager.h"

namespace nsx {

//! \class Material
//! \brief Class to represent the sample material type.
class Material {

public:

    //! Default constructor (deleted)
    Material()=delete;

    //! Constructs a Material with a given name
    Material(const std::string& formula);

    //! Copy constructor (deleted)
    Material(const Material& other)=default;

	//! Destructor
	~Material()=default;

    //! Assignment operator
    Material& operator=(const Material& other)=default;

    Material* clone() const;

	//! Returns the name of this Material
	const std::string& formula() const;

	const isotopeContents& isotopes() const;

	//! Returns the mass density of this Material
	double massDensity() const;
	//! Sets the mass density of this Material
	void setMassDensity(double massDensity);

	//! Returns the molar mass of this Material
	double molarMass() const;

	//! Returns the mass fractions of this Material
    isotopeContents massFractions() const;

	//! Returns the number of atoms per volume units per element (1/m3)
    isotopeContents atomicNumberDensity() const;

	//! Returns the scattering attenuation factor of this Material
	double muIncoherent() const;
	//! Returns the absorption attenuation factor of this Material at a given wavelength
	double muAbsorption(double lambda=1.798e-10) const;

	//! Print informations about this Material to an output stream
	void print(std::ostream& os) const;

private:

	std::string _formula;

	isotopeContents _isotopes;

	double _massDensity;
};

#ifndef SWIG
std::ostream& operator<<(std::ostream& os, const Material& material);
#endif

} // end namespace nsx
