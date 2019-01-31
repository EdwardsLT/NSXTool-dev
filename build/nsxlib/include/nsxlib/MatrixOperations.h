// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/mathematics/MatrixOperations.h
//! @brief     Implements module/class/test MatrixOperations
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <Eigen/Dense>

namespace nsx {

void removeColumn(Eigen::MatrixXd& matrix, unsigned int colToRemove);

void removeRow(Eigen::MatrixXd& matrix, unsigned int rowToRemove);

Eigen::Matrix3d interpolateRotation(const Eigen::Matrix3d& U0, const Eigen::Matrix3d& U1, const double t);


} // end namespace nsx
