// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/utils/EigenToVector.h
//! @brief     Implements module/class/test EigenToVector
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <vector>

#include <Eigen/Dense>

namespace nsx {

std::vector<double> eigenToVector(const Eigen::VectorXd& ev);

} // end namespace nsx
