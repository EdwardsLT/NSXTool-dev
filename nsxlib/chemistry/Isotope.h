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

#ifndef NSXTOOL_ISOTOPE_H_
#define NSXTOOL_ISOTOPE_H_

#include <map>
#include <complex>
#include <ostream>
#include <memory>
#include <set>
#include <string>
#include <utility>

#include <boost/any.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/property_tree/ptree.hpp>

#include "../kernel/Error.h"
#include "../utils/Units.h"

namespace SX {

namespace Chemistry {

using boost::property_tree::ptree;
using boost::filesystem::path;

using SX::Units::UnitsManager;

// Forward declarations
class Isotope;

class Isotope
{

public:

    enum class PropertyType {String, Int, Double, Complex, Bool};

    static std::map<std::string,PropertyType> PropertyTypes;

    static std::string DatabasePath;

    static std::string DatabaseRootNode;

public:

    Isotope()=delete;

    Isotope(const Isotope& other)=default;

    Isotope& operator=(const Isotope& other)=default;

	Isotope(const ptree& isotopeNode);

	//! Destructor
	~Isotope()=default;

	//! Returns the name of this Isotope
	const std::string& getName() const;

	template <typename PropertyType>
	PropertyType getProperty(const std::string& propertyName) const;

	bool hasProperty(const std::string& propertyName) const;

	//! Returns the formal charge of this Isotope
	double getFormalCharge() const;

	//! Returns true if this Isotope is an ion
	bool isIon() const;
	//! Return true if this Isotope is an anion (Q<0)
	bool isAnion() const;
	//! Return true if this Isotope is an cation (Q>0)
	bool isCation() const;

	//! Print some informations about this Isotope on a stream
	void print(std::ostream& os) const;

private:

	//! The name of this Isotope
	std::string _name;

	std::map<std::string,boost::any> _properties;
	std::map<std::string,std::string> _units;
    std::map<std::string,std::string> _types;

};

template <typename PropertyType>
PropertyType Isotope::getProperty(const std::string& propertyName) const
{
    auto pit = _properties.find(propertyName);
    if (pit == _properties.end())
        throw std::runtime_error("Isotope "+_name+": unknown property name ("+propertyName+")");

    return boost::any_cast<PropertyType>(pit->second);
}

//! Overloads the operator<< with an Isotope object
std::ostream& operator<<(std::ostream&,const Isotope&);

} // end namespace Chemistry

} // end namespace SX

#endif /* NSXTOOL_ISOTOPE_H_ */
