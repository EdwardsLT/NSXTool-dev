// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/monte-carlo/MCAbsorption.h
//! @brief     Implements module/class/test MCAbsorption
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <functional>
#include <random>
#include <vector>

#include "ConvexHull.h"

namespace nsx {

//! Class used to compute absorption correction by Monte-Carlo integration.
class MCAbsorption {

public:
	//! Define absorption Engine with a rectangular source of WxH
	MCAbsorption(const ConvexHull &convex_hull, double source_width, double source_height, double source_y_pos);

	~MCAbsorption();

	void setConvexHull(const ConvexHull &convex_hull);

	void setMuAbsorption(double mu_absorption);

	void setMuScattering(double mu_scattering);

	//! Run the Monte-Carlo calculation
	double run(unsigned int nIterations, const Eigen::Vector3d& outV, const Eigen::Matrix3d& sampleOrientation) const;

private:

	//! Description of the sample in terms of individual oriented triangles
	ConvexHull _convex_hull;

    double _mu_scattering;

    double _mu_absorption;

	double _source_width;

	double _source_height;

	double _source_y_pos;
};

} // end namespace nsx
