/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon, Eric Pellegrini
 Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr
 pellegrini[at]ill.fr

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef NSXTOOL_CONVEXHULL_H_
#define NSXTOOL_CONVEXHULL_H_

#include <array>
#include <cmath>
#include <list>

#include <Eigen/Dense>

#include "Face.h"
#include "Error.h"

//

namespace SX
{

namespace Geometry
{

/* !
 * \brief Class ConvexHull.
 * This class implements an templated object-oriented adaptation of the 3D incremental convex hull
 * algorithm whose implementation in C has been described in:
 *
 * o'Rourke, Joseph. Computational geometry in C. Cambridge university press, 1998. 115-144.
 *
 * Basically, the algorithm works on the same way than for the 2D case. It works by building counter clockwise
 * oriented faces (triangles) of the hull and at each step a new point is defined to be part of the hull if its
 * signed volume is negative for at least one face. Otherwise the point is discarded. When a point is added to
 * the hull, this one is extended by building new faces that link the point to the edges of the visible faces of
 * the hull from that point. After that step, the hull is updated by removing the faces (and their corresponding
 * edges) that has been completety "buried" by the hull growth.
 *
 * Some of the methods names have been renamed regarding to the C implementation because we felt more comfortable
 * with during those names in the curse of the implementation. In such case the original name will be recalled
 * when documenting those methods.
 */
template <typename T>
class ConvexHull
{

public:

	// Typedefs
	typedef Eigen::Matrix<T,3,1> vector3;
	typedef Eigen::Matrix<T,3,3> matrix33;
	typedef Vertex<T>* pVertex;
	typedef Face<T>* pFace;
	typedef Edge<T>* pEdge;

public:

	//! Check whether three vertices are coplanar
	static bool isCoplanar(pVertex v0, pVertex v1, pVertex v2);

public:

	//! Default constructor
	ConvexHull();

	//! Destructor
	~ConvexHull();

	//! Add a new vertex to be "hulled" further
	pVertex addVertex(const vector3& coords);


	//! Create a new hull face
	pFace makeFace(pVertex v0, pVertex v1, pVertex v2, pFace face=nullptr);

	pFace makeNullFace();

	pEdge makeNullEdge();

	//! Construct hull
	void constructHull();

	//! Return the vertices of the hull
	const std::list<pVertex>& getVertices() const;

	//! Return the edges of the hull
	const std::list<pEdge>& getEdges() const;

	//! Return the faces of the hull
	const std::list<pFace>& getFaces() const;

	void print(std::ostream& os) const;

	Eigen::Vector3d getCenter() const;

	double getVolume() const;

private:

	//! Define the initial double triangles that will serve as a seed for the hull
	void doubleTriangle();

	//! Find a set of three vertices that are not coplanar
	bool findInitialVertices(pVertex& v0, pVertex& v1, pVertex& v2) const;

	//! Update the hull with a new vertex
	void addOne(pVertex v);

	pFace makeConeFace(pEdge e, pVertex v);

	void makeCcw(pFace f, pEdge e, pVertex v);

	void cleanEdges();

	void cleanFaces();

	void cleanVertices();

	void cleanUp();

private:

	bool _initialized;
	std::list<pVertex> _vertices;
	std::list<pEdge> _edges;
	std::list<pFace> _faces;

};

template <typename T>
bool ConvexHull<T>::isCoplanar(pVertex v0, pVertex v1, pVertex v2)
{
	vector3 va=v1->_coords - v0->_coords;
	vector3 vb=v2->_coords - v0->_coords;

	T norm=va.cross(vb).norm();

	return (norm<1.0e-9);
}

template <typename T>
ConvexHull<T>::ConvexHull() : _initialized(false), _vertices(), _edges(), _faces()
{
}

template <typename T>
ConvexHull<T>::~ConvexHull()
{
	for (auto& v : _vertices)
		delete v;

	for (auto& e : _edges)
		delete e;

	for (auto& f : _faces)
		delete f;
}

template <typename T>
typename ConvexHull<T>::pVertex ConvexHull<T>::addVertex(const vector3& coords)
{
	pVertex v=new Vertex<T>(coords);
	_vertices.push_back(v);
	return _vertices.back();
}

template <typename T>
typename ConvexHull<T>::pFace ConvexHull<T>::makeNullFace()
{
	pFace f=new Face<T>();
	_faces.push_back(f);
	return _faces.back();
}

template <typename T>
typename ConvexHull<T>::pEdge ConvexHull<T>::makeNullEdge()
{
	pEdge e=new Edge<T>();
	_edges.push_back(e);
	return _edges.back();
}

template <typename T>
bool ConvexHull<T>::findInitialVertices(pVertex& v0, pVertex& v1, pVertex& v2) const
{
	if (_vertices.size()<3)
		throw SX::Kernel::Error<ConvexHull>("Can not set the initial polytope with less than 3 vertices.");

	for (auto it1=_vertices.begin();it1!=_vertices.end();++it1)
	{
		v0=*it1;
		for (auto it2=++it1;it2!=_vertices.end();++it2)
		{
			v1=*it2;
			for (auto it3=++it2;it3!=_vertices.end();++it3)
			{
				v2=*it3;
				if (!isCoplanar(v0,v1,v2))
					return true;
			}
		}
	}
	return false;
}

template <typename T>
void ConvexHull<T>::doubleTriangle()
{

	// Find 3 non colinear vertices
	Vertex<T> *v0(nullptr),*v1(nullptr),*v2(nullptr);
	if (!findInitialVertices(v0,v1,v2))
		throw SX::Kernel::Error<ConvexHull>("All vertices are coplanar 1.");

	// Mark the three non colinear vertices found as processed
	v0->_mark=true;
	v1->_mark=true;
	v2->_mark=true;

	// Create the two twin faces
	pFace f0=makeFace(v0,v1,v2);
	pFace f1=makeFace(v2,v1,v0,f0);

	// Link adjacent face
	f0->_edges[0]->_adjFace[1]=f1;
	f0->_edges[1]->_adjFace[1]=f1;
	f0->_edges[2]->_adjFace[1]=f1;
	f1->_edges[0]->_adjFace[1]=f0;
	f1->_edges[1]->_adjFace[1]=f0;
	f1->_edges[2]->_adjFace[1]=f0;

	// Find a fourth noncoplanar point to form tetrahedron
	for (auto v : _vertices)
	{
		if (v->_mark)
			continue;

		if (f0->volumeSign(v)!=0)
		{
			addOne(v);
			cleanUp();
			return;
		}
	}
}

template <typename T>
typename ConvexHull<T>::pFace ConvexHull<T>::makeFace(pVertex v0, pVertex v1, pVertex v2, pFace fold)
{

	Edge<T> *e0(nullptr),*e1(nullptr),*e2(nullptr);

	if (!fold)
	{
		e0=makeNullEdge();
		e1=makeNullEdge();
		e2=makeNullEdge();
	}
	else
	{
		e0=fold->_edges[2];
		e1=fold->_edges[1];
		e2=fold->_edges[0];
	}

	e0->_endPts[0]=v0;
	e0->_endPts[1]=v1;

	e1->_endPts[0]=v1;
	e1->_endPts[1]=v2;

	e2->_endPts[0]=v2;
	e2->_endPts[1]=v0;

	// Create a new face
	pFace f=makeNullFace();
	f->_edges[0]=e0;
	f->_edges[1]=e1;
	f->_edges[2]=e2;
	f->_vertices[0]=v0;
	f->_vertices[1]=v1;
	f->_vertices[2]=v2;

	// Link the edges to the face
	e0->_adjFace[0]=f;
	e1->_adjFace[0]=f;
	e2->_adjFace[0]=f;

	return _faces.back();

}

template <typename T>
void ConvexHull<T>::constructHull()
{

	if (!_initialized)
	{
		doubleTriangle();
		_initialized=true;
	}

	for (auto rit=_vertices.rbegin();rit!=_vertices.rend();rit++)
	{
		if (!((*rit)->_mark))
		{
			addOne(*rit);
			cleanUp();
		}
	}
}

template <typename T>
void ConvexHull<T>::addOne(pVertex v)
{

	v->_mark=true;
	// Mark the faces that are visible from vertex v
	bool visible=false;
	for (auto& f : _faces)
	{
		if (f->volumeSign(v)<0)
		{
			f->_visible=true;
			visible=true;
		}
	}

	// If no faces are visible from vertex v, then v is inside the hull
	if (!visible)
	{
		v->_onHull=false;
		return;
	}

	bool visible1, visible2;

	for (auto rit=_edges.end();rit!=_edges.begin();)
	{
		--rit;
		pEdge e=*rit;
		if (e->_adjFace[0])
			visible1=e->_adjFace[0]->_visible;
		else
			visible1=false;

		if (e->_adjFace[1])
			visible2=e->_adjFace[1]->_visible;
		else
			visible2=false;

		if (visible1 && visible2)
			e->_delete=true;
		else if (visible1 || visible2)
		{
			e->_newFace=makeConeFace(e,v);
		}

	}

}

template <typename T>
typename ConvexHull<T>::pFace ConvexHull<T>::makeConeFace(pEdge e, pVertex v)
{

	std::array<pEdge,2> newEdges;
	newEdges.fill(nullptr);

	// Make two new edges (if they don't already exist)
	for (unsigned int i=0;i<2;++i)
	{
		if (!e->_endPts[i]->_duplicate)
		{
			newEdges[i] = makeNullEdge();
			newEdges[i]->_endPts[0] = e->_endPts[i];
			newEdges[i]->_endPts[1] = v;
			e->_endPts[i]->_duplicate = newEdges[i];
		}
		else
			newEdges[i]=e->_endPts[i]->_duplicate;
	}

	// Make the new face
	pFace newFace = makeNullFace();
	newFace->_edges[0] = e;
	newFace->_edges[1] = newEdges[0];
	newFace->_edges[2] = newEdges[1];
	makeCcw(newFace,e,v);

	// Set the adjacent faces
	for (unsigned int i=0;i<2;++i)
	{
		for (unsigned int j=0;j<2;++j)
		{
			if (!newEdges[i]->_adjFace[j])
			{
				newEdges[i]->_adjFace[j] = newFace;
				break;
			}
		}
	}

	return _faces.back();
}

template <typename T>
void ConvexHull<T>::makeCcw(pFace f, pEdge e, pVertex v)
{

	pFace fv;

	if (e->_adjFace[0])
	{
		if (e->_adjFace[0]->_visible)
			fv = e->_adjFace[0];
		else
			fv = e->_adjFace[1];
	}
	else
		fv = e->_adjFace[1];

	unsigned int idx;
	for (idx=0;fv->_vertices[idx]!=e->_endPts[0];++idx);

	// Orient f the same as fv
	if (fv->_vertices[(idx+1)%3] != e->_endPts[1])
	{
		f->_vertices[0] = e->_endPts[1];
		f->_vertices[1] = e->_endPts[0];
	}
	else
	{
		f->_vertices[0] = e->_endPts[0];
		f->_vertices[1] = e->_endPts[1];
		pEdge temp;
		temp         = f->_edges[1];
		f->_edges[1] = f->_edges[2];
		f->_edges[2] = temp;
	}


	f->_vertices[2] = v;

}

template <typename T>
const std::list<typename ConvexHull<T>::pVertex>& ConvexHull<T>::getVertices() const
{
	return _vertices;
}

template <typename T>
const std::list<typename ConvexHull<T>::pEdge>& ConvexHull<T>::getEdges() const
{
	return _edges;
}

template <typename T>
const std::list<typename ConvexHull<T>::pFace>& ConvexHull<T>::getFaces() const
{
	return _faces;
}

template <typename T>
void ConvexHull<T>::cleanEdges()
{
	for (auto& e : _edges)
	{
		if (e->_newFace)
		{
			if (e->_adjFace[0]->_visible)
				e->_adjFace[0] = e->_newFace;
			else
				e->_adjFace[1] = e->_newFace;
			e->_newFace=nullptr;
		}
	}

	for (auto rit=_edges.rbegin();rit!=_edges.rend();++rit)
	{
		if ((*rit)->_delete)
		{
			delete *rit;
			_edges.erase(--(rit.base()));
		}
	}
}

template <typename T>
void ConvexHull<T>::cleanFaces()
{
	for (auto rit=_faces.rbegin();rit!=_faces.rend();++rit)
	{
		if ((*rit)->_visible)
		{
			delete *rit;
			_faces.erase(--(rit.base()));
		}
	}
}

template <typename T>
void ConvexHull<T>::cleanVertices()
{
	for (auto& e : _edges)
	{
		e->_endPts[0]->_onHull=true;
		e->_endPts[1]->_onHull=true;
	}

	for (auto rit=_vertices.rbegin();rit!=_vertices.rend();++rit)
	{
		if ((*rit)->_mark && !(*rit)->_onHull)
		{
			delete *rit;
			_vertices.erase(--(rit.base()));
		}
	}

	for (auto& v : _vertices)
	{
		v->_duplicate=nullptr;
		v->_onHull=false;
	}

}

template <typename T>
void ConvexHull<T>::cleanUp()
{
	cleanEdges();
	cleanFaces();
	cleanVertices();
}

template <typename T>
Eigen::Vector3d ConvexHull<T>::getCenter() const
{
	Eigen::Vector3d center=Eigen::Vector3d::Zero();
	for (auto & v : _vertices)
		center += v->_coords;
	center/=_vertices.size();

	return center;
}

template <typename T>
double ConvexHull<T>::getVolume() const
{

	Eigen::Vector3d center=getCenter();

	double volume=0.0;
	for (auto& f : _faces)
		volume += f->volume(center);

	return volume;

}

template<typename T>
void ConvexHull<T>::print(std::ostream& os) const
{
	os<<"Convex Hull:\n"<<std::endl;
	for (auto& f : _faces)
		os<<f;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const ConvexHull<T>& chull)
{
	chull.print(os);
	return os;
}

} // end namespace Geometry

} // end namespace SX

#endif /* NSXTOOL_CONVEXHULL_H_ */
