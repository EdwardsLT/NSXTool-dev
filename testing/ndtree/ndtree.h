/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr

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

#ifndef NSXTOOL_NDTree_H_
#define NSXTOOL_NDTree_H_
#include <cmath>
#include <vector>
#include <boost/numeric/ublas/vector.hpp>

#include "aabb.h"

namespace ublas=boost::numeric::ublas;

namespace SX {

namespace Geometry {


constexpr int getPow (int factor)
{
	return factor > 1 ? 2 * getPow( factor-1 ) : 2;
}


template<typename T, std::size_t D>
class NDTree : public AABB<T,D>
{
public:

	typedef typename std::vector<AABB<T,D>*>::const_iterator data_iterator;
	typedef std::pair< data_iterator , data_iterator > data_range_pair;

	//! default constructor (should be called once and only once for the root node)
	NDTree();

	//! constructor from two ublas vectors
	NDTree(const ublas::bounded_vector<T,D>& lb, const ublas::bounded_vector<T,D>& ub);

	//! constructor from a parent node
	NDTree(const NDTree* parent, std::size_t nd_dran);

	//! destructor
	~NDTree();

	//! void add a new AABB object to the node
	void addData(AABB<T,D>* aabb);

	//! get the data contained in the node
	void getData(std::vector<NDTree<T,D>::data_range_pair>& treeData) const;

	//! check whether the node has some children
	bool hasChildren() const;

	//! check whether the node has some data
	bool hasData() const;

	//! recursively send some information about the node (and its descendance) to a stream
	void printSelf(std::ostream& os) const;

	//! setter for _depth attribute
	static void setDepth(std::size_t depth);

	//! setter for _MAX_STORAGE attribute
	static void setMaxStorage(std::size_t maxStorage);

	//! split the node into 2^D subnodes
	void split();

private:
	void nullifyChildren();
	static std::vector<std::size_t> createPowers();

	static std::size_t _MAX_DEPTH;
	static std::size_t _MAX_STORAGE;
	static const std::size_t _MULTIPLICITY;
	static std::vector<std::size_t> _POWERS;

	NDTree<T,D>* _children[getPow(D)];
	std::vector<AABB<T,D>*> _data;

	std::size_t _depth;

};

template<typename T, std::size_t D>
std::vector<std::size_t> NDTree<T,D>::createPowers()
{
	std::vector<std::size_t> p(D);
	int i=0;
	std::generate(p.begin(), p.end(), [&i]() {return std::pow(2,i++);});

	return p;
}

template<typename T, std::size_t D>
std::size_t NDTree<T,D>::_MAX_DEPTH(10);

template<typename T, std::size_t D>
std::size_t NDTree<T,D>::_MAX_STORAGE(4);

template<typename T, std::size_t D>
const std::size_t NDTree<T,D>::_MULTIPLICITY(std::pow(2,D));

template<typename T, std::size_t D>
std::vector<std::size_t> NDTree<T,D>::_POWERS=createPowers();


template<typename T, std::size_t D>
void NDTree<T,D>::nullifyChildren()
{
	for (std::size_t i=0;i<_MULTIPLICITY;++i)
		_children[i]=nullptr;
}

template<typename T, std::size_t D>
NDTree<T,D>::NDTree() : AABB<T,D>(), _depth(0)
{
	nullifyChildren();
	_data.reserve(_MAX_STORAGE);

}

template<typename T, std::size_t D>
NDTree<T,D>::NDTree(const ublas::bounded_vector<T,D>& lb, const ublas::bounded_vector<T,D>& ub) : AABB<T,D>(lb,ub), _depth(0)
{
	nullifyChildren();
	_data.reserve(_MAX_STORAGE);
}

template<typename T, std::size_t D>
NDTree<T,D>::NDTree(const NDTree<T,D>* parent, std::size_t nd_dran) : AABB<T,D>(parent->_lowerBound, parent->_upperBound), _depth(parent->_depth+1)
{
	nullifyChildren();
	_data.reserve(_MAX_STORAGE);

	ublas::bounded_vector<T,D> center((parent->AABB<T,D>::_lowerBound + parent->AABB<T,D>::_upperBound)*0.5);

	bool b;
	for (std::size_t i=0; i<D; ++i)
	{
		b = (nd_dran & _POWERS[i]);
		this->AABB<T,D>::_lowerBound[i] = (b ? center[i] : parent->AABB<T,D>::_lowerBound[i]);
		this->AABB<T,D>::_upperBound[i] = (b ? parent->AABB<T,D>::_upperBound[i] : center[i]);
	}

}

template<typename T, std::size_t D>
NDTree<T,D>::~NDTree()
{
	if (hasChildren())
	{
		for (unsigned int i=0;i<_MULTIPLICITY;++i)
		{
			delete _children[i];
		}
	}
	return;
}

template<typename T, std::size_t D>
void NDTree<T,D>::addData(AABB<T,D>* aabb)
{
	if (!intercept(*aabb))
		return;

	if (hasChildren())
	{
		for (unsigned int i=0;i<_MULTIPLICITY;++i)
			_children[i]->addData(aabb);
	}
	else
	{
		_data.push_back(aabb);
		if (_data.size() > _MAX_STORAGE)
			split();
	}

}

template<typename T, std::size_t D>
void NDTree<T,D>::getData(std::vector<NDTree<T,D>::data_range_pair>& treeData) const
{
	if (hasChildren())
	{
		for (unsigned int i=0; i<_MULTIPLICITY; ++i)
			_children[i]->getData(treeData);
	}
	else
	{
		if (_data.size() != 0)
			treeData.push_back(std::make_pair(_data.begin(),_data.end()));
	}
}

template<typename T, std::size_t D>
bool NDTree<T,D>::hasChildren() const
{
	return (_children[0]);
}

template<typename T, std::size_t D>
bool NDTree<T,D>::hasData() const
{
	return (_data.size() != 0);
}

template<typename T, std::size_t D>
void NDTree<T,D>::printSelf(std::ostream& os) const
{

	std::cout << "*** Node ***  " << this->_lowerBound  << "," << this->_upperBound << std::endl;
	if (!hasChildren())
	{
		std::cout << " has no children" <<std::endl;
		std::cout << "... but has " << _data.size() << "data" <<  std::endl;
	}
	else
	{
		std::cout << " has children :" << std::endl;
		for (int i=0; i<_MULTIPLICITY; ++i)
			_children[i]->printSelf(os);
	}
}

template<typename T, std::size_t D>
void NDTree<T,D>::setDepth(std::size_t depth)
{
	if (depth ==0 || depth > 1000000000000000000)
		throw("NDTree: invalid depth");
	_MAX_DEPTH = depth;
}

template<typename T, std::size_t D>
void NDTree<T,D>::setMaxStorage(std::size_t maxStorage)
{
	if (maxStorage ==0)
		throw("NDTree: invalid max storage");
	_MAX_STORAGE = maxStorage;
}

template<typename T, std::size_t D>
void NDTree<T,D>::split()
{
	// The node is already at the maximum depth: do not split anymore, just add the data
	if (_depth > _MAX_DEPTH)
		return;

	for (std::size_t i=0; i<_MULTIPLICITY; ++i)
		_children[i]=new NDTree<T,D>(this,i);

	for (auto ptr=_data.begin(); ptr!=_data.end(); ++ptr)
	{
		for (std::size_t i=0; i<_MULTIPLICITY; ++i)
			_children[i]->addData(*ptr);
	}
	_data.clear();
}

template<typename T, std::size_t D>
std::ostream& operator<<(std::ostream& os, const NDTree<T,D>& tree)
{
	tree.printSelf(os);
	return os;
}

} // namespace Geometry

} // namespace SX

#endif /* NSXTOOL_NDTree_H_ */
