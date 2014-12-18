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

#ifndef NSXTOOL_MATERIALS_H_
#define NSXTOOL_MATERIALS_H_

#include <string>

namespace SX
{

namespace Crystal
{

class Materials
{
public:

	//! Constructs a Materials
	Materials();
	//! Constructs a Materials with a given name
	Materials(const std::string& name);
	//! Constructs a Materials with a given name and formula
	Materials(const std::string& name, const std::string& formula);
	//! Constructs a Materials with a given name, formula and density
	Materials(const std::string& name, const std::string& formula, double density);
	//! Constructs a materials from another Materials
	Materials(const Materials& other);
	//! Destructor
	~Materials();

	//! Assignment operator
	Materials& operator=(const Materials& other);

	//! Get the name of the materials
	const std::string& getName() const;
	//! Set the name of the materials
	void setName(const std::string& name);

	//! Get the formula of the materials
	const std::string& getFormula() const;
	//! Set the formula of the materials
	void setFormula(const std::string& name);

	//! Get the density of the materials
	double getDensity() const;
	//! Set the density of the materials
	void setDensity(double density);

	//! Return the mass of the Materials given its volume
	double getMass(double volume) const;

private:
	std::string _name, _formula;
	double _density;

};

} // end namespace Crystal

} // end namespace SX

#endif /* NSXTOOL_MATERIALS_H_ */