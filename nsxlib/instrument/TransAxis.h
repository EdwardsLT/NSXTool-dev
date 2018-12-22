// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/TransAxis.h
//! @brief     Implements module/class/test TransAxis
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <yaml-cpp/yaml.h>

#include <Eigen/Geometry>

#include "Axis.h"

namespace nsx {

//! Translational axis of an abstract goniometer
class TransAxis: public Axis {
public:

	//! Static constructor for a TransAxis
	static Axis* create(const YAML::Node& node);

	//! Default constructor
	TransAxis();
	//! Copy constructor
	TransAxis(const TransAxis& other);
	//! Constructs a translation axis with a given label
	TransAxis(const std::string& label);
	//! Constructs a translation axis with a given label and axis
	TransAxis(const std::string& label,const Eigen::Vector3d& axis);
	//! Construct a TransAxis from a property tree node.
	TransAxis(const YAML::Node& node);
	// Destructor
	~TransAxis();
	//! Virtual copy constructor
	TransAxis* clone() const;

	//! Assignment operator
	TransAxis& operator=(const TransAxis& other);

	Eigen::Transform<double,3,Eigen::Affine> affineMatrix(double value) const;

	std::ostream& printSelf(std::ostream& os) const override;
};

} // end namespace nsx
