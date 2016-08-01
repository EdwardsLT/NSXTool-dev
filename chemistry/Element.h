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

#ifndef NSXTOOL_ELEMENT_H_
#define NSXTOOL_ELEMENT_H_

#include <map>
#include <memory>
#include <ostream>
#include <string>

#include <boost/property_tree/ptree.hpp>

namespace SX
{

namespace Chemistry
{

// Forward declarations
class Isotope;
class Element;
class ElementManager;

// Typedefs
typedef std::shared_ptr<Isotope> sptrIsotope;
typedef std::map<std::string,sptrIsotope> isotopeMap;
typedef std::map<std::string,double> contentsMap;
typedef std::pair<std::string,sptrIsotope> strToIsotopePair;
typedef std::pair<std::string,double> strToDoublePair;

// Namespaces
namespace property_tree=boost::property_tree;

class Element
{

private:

	friend class ElementManager;

private:

	//! Returns a shared pointer to an Element.
	//! If a chemical symbol is given the element will be built from its natural isotopes otherwise it is empty and will have to be filled later by addIsotope method.
	static Element* create(const std::string& name);

public:

	//! Destructor
	~Element();

	//! Return true if two Elements are the same (same isotopes with the same abundances)
	bool operator==(const Element& other) const;
	//! Returns a shared pointer to the Isotope of this Element that matches a given name. If no element of this Element matches this name, throws.
	sptrIsotope operator[](const std::string& name);

	//! Returns the name of this Element
	const std::string& getName() const;
	//! Returns the chemical symbol of this Element
	const std::string& getSymbol() const;

	//! Return true whether this Element is natural
	bool isNatural() const;
	//! Set whether or not this Element is natural
	void setNatural(bool natural);

	//! Returns the isotopes that builds this Element
	const isotopeMap& getIsotopes() const;
	//! Returns the number of isotopes that build this Element
	unsigned int getNIsotopes() const;
	//! Return true whether some Isotope has been provided to this Element
	bool isEmpty() const;

	//! Returns the molar mass of the element (according to its isotopes composition)
	double getMolarMass() const;
	//! Returns the number of protons of the element
	unsigned int getNProtons() const;
	//! Returns the number of electrons of the element
	unsigned int getNElectrons() const;
	//! Returns the number of neutrons of the element. It is computed as the abundance-weighted sum of the number of neutrons of the isotopes that build this Element.
	double getNNeutrons() const;
	//! Returns the incoherent cross section of this Element. It is computed as the abundance-weighted sum of the incoherent cross section of the isotopes that build this Element
	double getIncoherentXs() const;
	//! Returns the absorption cross section at a given wavelength weighted. It is computed as the abundance-weighted sum of the absorption cross section of the isotopes that build this Element
	double getAbsorptionXs(double lambda=1.798e-10) const;
	//! Returns the abundance of a given isotope. If not present in the Element, throw
	double getAbundance(const std::string& name) const;
	//! Set the abundance of a given isotope
	void setAbundance(const std::string& name, double abundance);
	//! Returns the abundance of the isotopes that make this Element
	const contentsMap& getAbundances() const;

	//! Add a shared pointer to an Isotope to this Element
	sptrIsotope addIsotope(sptrIsotope isotope, double abundance);
	//! Add an isotope with a given name to this Element using its natural abundance
	sptrIsotope addIsotope(const std::string& name);
	//! Add an Isotope with a given name to this Element using a given abundance
	sptrIsotope addIsotope(const std::string& name, double abundance);


	//! Inserts the information about this Element to an XML parent node
	property_tree::ptree writeToXML() const;

	//! Prints informations about this Element to an output stream
	void print(std::ostream& os) const;

private:

	//! Default constructor (deleted)
	Element()=delete;

	//! Copy constructor (deleted)
	Element(const Element& other)=delete;

	//! Constructs an Element by fetching the isotopes from the isotopes database whose symbol matches the given symbol
	Element(const std::string& name);

	//! Assignment operator (deleted)
	Element& operator=(const Element& other)=delete;

private:

	//! The name of the element
	std::string _name;

	//! The symbol of this Element
	std::string _symbol;

	//! A mapping between the names of the Isotope this Element is made of and their corresponding shared pointer
	isotopeMap _isotopes;

	//! A mapping between the names of the Isotope this Element is made of and their corresponding abundances
	contentsMap _abundances;

	//! True whether this Element is made of natural isotopes
	bool _natural;

};

std::ostream& operator<<(std::ostream& os, const Element& element);

} // end namespace Chemistry

} // end namespace SX

#endif /* NSXTOOL_ELEMENT_H_ */