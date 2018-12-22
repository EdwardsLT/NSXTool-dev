// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/mathematics/MatrixOperations.cpp
//! @brief     Implements module/class/test MatrixOperations
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "MatrixOperations.h"
#include <unsupported/Eigen/MatrixFunctions>

namespace nsx {

void removeColumn(Eigen::MatrixXd& matrix, unsigned int colToRemove)
{
    unsigned int numRows = matrix.rows();
    unsigned int numCols = matrix.cols()-1;

    if( colToRemove < numCols )
        matrix.block(0,colToRemove,numRows,numCols-colToRemove) = matrix.block(0,colToRemove+1,numRows,numCols-colToRemove);

    matrix.conservativeResize(numRows,numCols);
}

void removeRow(Eigen::MatrixXd& matrix, unsigned int rowToRemove)
{
    unsigned int numRows = matrix.rows()-1;
    unsigned int numCols = matrix.cols();

    if( rowToRemove < numRows )
        matrix.block(rowToRemove,0,numRows-rowToRemove,numCols) = matrix.block(rowToRemove+1,0,numRows-rowToRemove,numCols);

    matrix.conservativeResize(numRows,numCols);
}

Eigen::Matrix3d interpolateRotation(const Eigen::Matrix3d& U0, const Eigen::Matrix3d& U1, const double t)
{
    Eigen::Quaterniond q0(U0), q1(U1);
    return q0.slerp(t, q1).toRotationMatrix();
}



} // end namespace nsx

