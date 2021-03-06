// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/geometry/Face.h
//! @brief     Implements module/class/test Face
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <vector>
#include <ostream>

#include <Eigen/Dense>

namespace nsx {

struct Edge;
struct Vertex;

/* !
 * \brief Class Face.
 * This class implements the Face object used in the incremental convex hull algorithm.
 */
struct Face {

	//! Default constructor
	Face();

	//! Default constructor
	Face(int id);

	//! Copy constructor
	Face(const Face& other)=delete;

	//! Destructor
	~Face()=default;

	//! Assignment operator
	Face& operator=(const Face& other)=delete;

	//! Returns the int signed volume of the tetrahedron formed by this Face and a vertex.
	//! It is equal respectively to 1 and -1  if the vertex is on the negative or positive side of this Face
	//! with the positive side determined by the right hand rule. It is equal to 0 if the vertice is within the face
	int volumeSign(Vertex* v) const;

	//! Returns the volume of the tetrahedron formed by this Face and any point.
	double volume(const Eigen::Vector3d& pos) const;

	//! Send some informations about this Face on an output stream
	void print(std::ostream& os) const;

	//! The three pointer to the edges of this Face
	std::vector<Edge*> _edges;

	//! The three pointers to the vertices of this Face
	std::vector<Vertex*> _vertices;

	//! Indicates whether or not this Face is visible
	bool _visible;

    int _id;
};

std::ostream& operator<<(std::ostream& os, const Face& face);

} // end namespace nsx
