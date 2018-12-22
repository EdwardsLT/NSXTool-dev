// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/TransAxis.cpp
//! @brief     Implements module/class/test TransAxis
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "TransAxis.h"

namespace nsx {

Axis* TransAxis::create(const YAML::Node& node)
{
	return new TransAxis(node);
}

TransAxis::TransAxis() : Axis("translation")
{
}

TransAxis::TransAxis(const std::string& label) : Axis(label)
{
}

    TransAxis::TransAxis(const std::string& label, const Eigen::Vector3d& axis) : Axis(label,axis)
{
}

TransAxis::TransAxis(const TransAxis& other) : Axis(other)
{
}

TransAxis::TransAxis(const YAML::Node& node) : Axis(node)
{
}

TransAxis::~TransAxis()
{
}

TransAxis* TransAxis::clone() const
{
	return new TransAxis(*this);
}

TransAxis& TransAxis::operator=(const TransAxis& other)
{
	if (this != &other)
		Axis::operator=(other);

	return *this;
}

Eigen::Transform<double,3,Eigen::Affine> TransAxis::affineMatrix(double value) const
{
    Eigen::Transform<double,3,Eigen::Affine> mat = Eigen::Transform<double,3,Eigen::Affine>::Identity();
	mat.translation()=_axis*value;
	return mat;
}

std::ostream& TransAxis::printSelf(std::ostream& os) const
{
    os << "T(" << _axis.transpose() << ")";

    return os;
}

} // end namespace nsx

