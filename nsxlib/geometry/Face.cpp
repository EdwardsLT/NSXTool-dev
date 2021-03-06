// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/geometry/Face.cpp
//! @brief     Implements module/class/test Face
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <array>

#include <Eigen/Dense>

#include "Edge.h"
#include "Face.h"
#include "Vertex.h"

namespace nsx {

Face::Face() : _id(-1), _edges(), _vertices(), _visible(false)
{
    _edges.resize(3,nullptr);
    _vertices.resize(3,nullptr);
}

Face::Face(int id) : _id(id), _edges(), _vertices(), _visible(false)
{
    _edges.resize(3,nullptr);
    _vertices.resize(3,nullptr);
}

double Face::volume(const Eigen::Vector3d& pos) const
{
	Eigen::Matrix3d mat;

	mat.row(0)=_vertices[0]->_coords - pos;
	mat.row(1)=_vertices[1]->_coords - pos;
	mat.row(2)=_vertices[2]->_coords - pos;

	double det=mat.determinant();

	return std::abs(det)/6.0;
}

int Face::volumeSign(Vertex* v) const
{
	Eigen::Matrix3d mat;

	mat.row(0)=_vertices[0]->_coords - v->_coords;
	mat.row(1)=_vertices[1]->_coords - v->_coords;
	mat.row(2)=_vertices[2]->_coords - v->_coords;

	double det=mat.determinant();

	if (std::abs(det)<1.0e-9)
		return 0;
	else
		return (det > 0) ? 1 : -1;
}

void Face::print(std::ostream& os) const
{
	os<<"Face:"<<std::endl;
	for (auto it=_edges.begin();it!=_edges.end();++it)
		if (*it)
			os<<**it;
		else
			os<<" NULL ";
}

std::ostream& operator<<(std::ostream& os, const Face& face)
{
	face.print(os);
	return os;
}

} // end namespace nsx

