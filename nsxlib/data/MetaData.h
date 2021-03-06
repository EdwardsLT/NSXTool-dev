// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/MetaData.h
//! @brief     Implements module/class/test MetaData
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <map>
#include <set>
#include <stdexcept>
#include <string>

#include "DataTypes.h"
#include "Variant.h"

namespace nsx {

/*! \brief Class to store MetaData of a DataSet stored by a map of key/value pair
 *
 *  MetaData class allow to store metadata associated with a data file  into a map indexed by the string
 * of the entry. Any parameter type can be stored, using the corresponding template argument.
 * A specific key can be retrieved back using the template type defined when the key was registered.
 * From C++0x onwards, a parameter can be retrieved even if its type is unknown by the user
 * using auto.
 */
class MetaData
{
public:
	//! Constructor
	MetaData();
	//! Destructor
	~MetaData();
	//! Copy
	MetaData(const MetaData&);
	//! Assignment
	MetaData& operator=(const MetaData&);
	//! Add a pair of key and value.
	template <class _type> void add(const std::string& key, const _type& value);
	//! Get the value associated with the key. User must know the return type, otherwise use method that return boost_any
	template <class _type>  _type key(const std::string& key) const;
	//! Get the value associated with the key. User must know the return type, otherwise use method that return boost_any
	template <class _type>  _type key(const char* key) const;
	//! Return the value
	//@ return : value corresponding to key
	Variant<int,double,std::string> key(const std::string& key) const;
	//! Is this key in the metadata
	bool isKey(const std::string& key) const;
	//!Is this key in the metadata
	bool isKey(const char* key) const;
	//! Number of elements in the map
	//@ return : Number of elements in the map
	//std::size_t size() const;
	//! Get all the keys available.
	const MetaDataKeySet& keys() const;
	//! Get the full map of parameters
	const MetaDataMap& map() const;
private:
	//! Contains the map of all key/value pairs.
	MetaDataMap _map;
	//! Contains all available keys so far.
	static MetaDataKeySet  _metakeys;

};

template <typename _type>
void MetaData::add(const std::string& key,const _type& value)
{
	// First, make sure the key is already in the keyset
	// Since this is a set, no duplicate will be found. No need to search explicitely.
	std::pair<MetaDataKeySet::iterator, bool> it=_metakeys.insert(key);

	//  If all OK, then add the key to the map
	const char* ptr=(*it.first).c_str();
	_map.insert(std::pair<const char*,_type>(ptr,value));
}

template <typename _type>
 _type MetaData::key(const std::string& name) const
{
	// Search if this key is in the set.
	auto it=_metakeys.find(name);
	if (it==_metakeys.end())
		throw std::runtime_error("Could not find key :"+name+" in MetaData");
	// Then search in the map
	const char* ptr=(*it).c_str();
	auto it2=_map.find(ptr);
	if (it2==_map.end())
		throw std::runtime_error("Could not find key :"+name+" in MetaData");
	return it2->second.as<_type>();
}

template <typename _type>
 _type MetaData::key(const char* name) const
{
	return key<_type>(std::string(name));
}

} // end namespace nsx
