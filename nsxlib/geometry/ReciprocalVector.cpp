// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/geometry/ReciprocalVector.cpp
//! @brief     Implements module/class/test ReciprocalVector
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <Eigen/Dense>

#include "ReciprocalVector.h"

namespace nsx {

ReciprocalVector::ReciprocalVector(double x, double y, double z) : _rvector(x,y,z)
{
}

ReciprocalVector::ReciprocalVector(const Eigen::RowVector3d& rvector) : _rvector(rvector)
{
}

const Eigen::RowVector3d& ReciprocalVector::rowVector() const
{
    return _rvector;
}

double ReciprocalVector::operator[](int index) const
{
    if (index < 0 || index > 2) {
        throw std::runtime_error("Invalid index for a 3D vector");
    }
    return _rvector[index];
}

double& ReciprocalVector::operator[](int index)
{
    if (index < 0 || index > 2) {
        throw std::runtime_error("Invalid index for a 3D vector");
    }
    return _rvector[index];
}

double ReciprocalVector::operator()(int index) const
{
    if (index < 0 || index > 2) {
        throw std::runtime_error("Invalid index for a 3D vector");
    }
    return _rvector[index];
}

double& ReciprocalVector::operator()(int index)
{
    if (index < 0 || index > 2) {
        throw std::runtime_error("Invalid index for a 3D vector");
    }
    return _rvector[index];
}

void ReciprocalVector::print(std::ostream& os) const
{
    os << _rvector;
}

std::ostream& operator<<(std::ostream& os, const ReciprocalVector& rvector)
{
    rvector.print(os);
    return os;
}






} // end namespace nsx
