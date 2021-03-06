// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/FlatDetector.h
//! @brief     Implements module/class/test FlatDetector
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <yaml-cpp/yaml.h>

#include "Detector.h"
#include "GeometryTypes.h"

namespace nsx {

//! Class implementing a flat detector
class FlatDetector: public Detector {
public:

	//! Static constructor of a FlatDetector from a property tree node
	static Detector* create(const YAML::Node& node);

	//! Construct a FlatDetector
	FlatDetector()=default;
	//! Construct a FlatDetector from another one
	FlatDetector(const FlatDetector& other)=default;
	//! Construct a FlatDetector with a given name
	FlatDetector(const std::string& name);
	//! Constructs a FlatDetector from a property tree node
	FlatDetector(const YAML::Node& node);
	//! Return a pointer to a copy of a FlatDetector
	Detector* clone() const override;
	//! Destructor
	virtual ~FlatDetector();

	//! Assignment operator
	FlatDetector& operator=(const FlatDetector& other)=default;

	//! Set the height of the detector (meters)
	virtual void setHeight(double height) override;
	//! Set the width of the detector (meters)
	virtual void setWidth(double width) override;

	//! Set the angular height of the detector (radians)
	virtual void setAngularHeight(double angle) override;
	//! Set the angular width of the detector (radians)
	virtual void setAngularWidth(double angle) override;

	//! Returns the position of a given pixel in detector space. This takes into account the detector motions in detector space.
	virtual DirectVector pixelPosition(double px,double py) const override;

	//! Determine whether detector at rest can receive a scattering event with direction given by Kf. px and py are detector position if true.
	virtual DetectorEvent constructEvent(const DirectVector& from, const ReciprocalVector& kf) const override;

	virtual Eigen::Matrix3d jacobian(double x, double y) const override;

};

} // end namespace nsx
