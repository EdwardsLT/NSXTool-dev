#include "Gonio.h"
#include <algorithm>
#include <stdexcept>
#include <Units.h>
#include <Eigen/Geometry>
#include "RotAxis.h"
#include "TransAxis.h"

namespace SX
{
namespace Instrument
{

using Eigen::Quaterniond;

Gonio::Gonio(const std::string& label):_label(label)
{
}

Gonio::Gonio(const Gonio& other) : _label(other._label)
{
	_axes.reserve(other._axes.size());
	for (auto ax : other._axes)
		_axes.push_back(ax->clone());
}

Gonio& Gonio::operator=(const Gonio& other)
{
	if (this != &other)
	{
		_label = other._label;
		_axes.reserve(other._axes.size());
		for (auto ax : other._axes)
			_axes.push_back(ax->clone());
	}

	return *this;
}

Gonio::~Gonio()
{
}

Axis*const Gonio::getAxis(unsigned int i)
{
	isAxisValid(i);
	return _axes[i];
}


Axis*const Gonio::getAxis(const std::string& label)
{
	unsigned int i=isAxisValid(label);
	return _axes[i];
}


Axis* Gonio::addRotation(const std::string& label, const Vector3d& axis,RotAxis::Direction dir)
{
	_axes.push_back(new RotAxis(label,axis,dir));
	return _axes.back();
}

Axis* Gonio::addTranslation(const std::string& label, const Vector3d& axis)
{
	_axes.push_back(new TransAxis(label,axis));
	return _axes.back();
}


void Gonio::isAxisValid(unsigned int i) const
{
	if (i>=_axes.size())
		throw std::invalid_argument("Trying to access non-valid axis");
}

unsigned int Gonio::isAxisValid(const std::string& label) const
{
	for (unsigned int i=0;i<_axes.size();++i)
	{
		if (_axes[i]->getLabel().compare(label)==0)
			return i;
	}
	//! If not found
	throw std::invalid_argument("Could not find the label "+label+" as a goniometer axis in "+_label);
}


Eigen::Transform<double,3,Eigen::Affine> Gonio::getHomMatrix(const std::vector<double>& values) const
{
	if (values.size() != nPhysicalAxes())
	{
		throw std::range_error("Trying to set Gonio "+_label+" with wrong number of parameters");
	}
	Eigen::Transform<double,3,Eigen::Affine> result=Eigen::Transform<double,3,Eigen::Affine>::Identity();
	std::vector<Axis*>::const_reverse_iterator it;
	std::vector<double>::const_reverse_iterator itv=values.rbegin();

	for (it=_axes.rbegin();it!=_axes.rend();++it)
	{
		if ((*it)->isPhysical())
		{
			result=(*it)->getHomMatrix(*itv)*result;
			itv++;
		}
		else
			result=(*it)->getHomMatrix(0.0)*result;
	}
	return result;
}

Eigen::Transform<double,3,Eigen::Affine> Gonio::getInverseHomMatrix(const std::vector<double>& values) const
{
	return getHomMatrix(values).inverse();
}

Vector3d Gonio::transform(const Vector3d& v,const std::vector<double>& values)
{
	Eigen::Transform<double,3,Eigen::Affine> result=getHomMatrix(values);
	return (result*v.homogeneous());
}

Vector3d Gonio::transformInverse(const Vector3d& v,const std::vector<double>& values)
{
	Eigen::Transform<double,3,Eigen::Affine> result=getInverseHomMatrix(values);
	return (result*v.homogeneous());
}

void Gonio::transformInPlace(Vector3d& v,const std::vector<double>& values)
{
	Eigen::Transform<double,3,Eigen::Affine> result=getHomMatrix(values);
	v=result*v.homogeneous();
}

void Gonio::transformInverseInPlace(Vector3d& v,const std::vector<double>& values)
{
	v=getInverseHomMatrix(values)*v.homogeneous();
}

std::size_t Gonio::nAxes() const
{
	return _axes.size();
}


void Gonio::resetOffsets()
{
	for (int i=0;i<_axes.size();++i)
	{
		_axes[i]->setOffset(0.0);
	}
}

std::size_t Gonio::nPhysicalAxes() const
{
	std::size_t nPhysAxis = 0;
	for (auto a : _axes)
	{
		if (a->isPhysical())
			nPhysAxis++;
	}
	return nPhysAxis;
}

}
}
