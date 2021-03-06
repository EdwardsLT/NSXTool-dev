// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/Source.h
//! @brief     Implements module/class/test Source
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

#include "Component.h"
#include "Monochromator.h"

namespace nsx {

//! Class encapsulating the source (incoming beam)
class Source: public Component {

public:

    //! Static constructor of a monochromatic source from a yaml tree node
	static Source* create(const YAML::Node& node);

	//! Default constructor
	Source();

	//! Copy constructor
	Source(const Source& other);

	//! Constructs a default source with a given name
	Source(const std::string& name);

	//! Constructs a source from a property tree node
	Source(const YAML::Node& node);

	//! Virtual copy constructor
	Source* clone() const;

	//! Destructor
	~Source();

	//! Assignment operator
	Source& operator=(const Source& other);

	//! Returns the monochromators registered for this Source
	const std::vector<Monochromator>& monochromators() const;

	//! Returns the number of monochromators associated with this source
	int nMonochromators() const;
	//! Select a monochromator for this source

	void setSelectedMonochromator(size_t i);

	//! Return a non-const reference to the selected monochromator
    Monochromator& selectedMonochromator();

    //! Return a non-const reference to the selected monochromator
    const Monochromator& selectedMonochromator() const;

    //! Add a new monochromator to this source
	void addMonochromator(Monochromator mono);

protected:

	std::vector<Monochromator> _monochromators;
	size_t _selectedMonochromator;
};

} // end namespace nsx
