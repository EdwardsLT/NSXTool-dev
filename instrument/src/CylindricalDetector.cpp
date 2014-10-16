#include "CylindricalDetector.h"
#include "Gonio.h"

namespace SX
{
namespace Instrument
{

CylindricalDetector::CylindricalDetector():Detector(),_widthAngle(0)
{

}

CylindricalDetector::CylindricalDetector(const CylindricalDetector& other) : Detector(other), _widthAngle(other._widthAngle)
{
}


CylindricalDetector::CylindricalDetector(const std::string& name):Detector(name), _widthAngle(0)
{

}

CylindricalDetector::~CylindricalDetector()
{
}

CylindricalDetector& CylindricalDetector::operator=(const CylindricalDetector& other)
{
	if (this != &other)
	{
		Detector::operator=(other);
		_widthAngle = other._widthAngle;

	}
	return *this;
}

CylindricalDetector* CylindricalDetector::clone() const
{
	return new CylindricalDetector(*this);
}

void CylindricalDetector::setAngularRange(double w, double h)
{
	_widthAngle=w;
	// R.dTheta
	_width=w*_distance;
	// Full height
	_height=2.0*_distance*tan(h);
}

void CylindricalDetector::setWidthAngle(double wangle)
{
	_widthAngle=wangle;
	// R.dTheta
	_width=wangle*_distance;
}

void CylindricalDetector::setHeightAngle(double hangle)
{
	_height=2.0*_distance*tan(hangle);
}

double CylindricalDetector::getWidthAngle()const
{
	return _widthAngle;
}

double CylindricalDetector::getHeightAngle() const
{
	return 2.0*atan(0.5*_height/_distance);
}

Eigen::Vector3d CylindricalDetector::getPos(double x, double y) const
{
	if (_nCols==0 || _nRows==0)
		throw std::runtime_error("Detector: number of rows or cols must >0");

	if (_height==0 || _width==0)
		throw std::runtime_error("Detector: width or height must be >0");

	if (_distance==0)
		throw std::runtime_error("Detector: distance must be >0");

	// Convert coordinates due to detector mapping,
	// mx,my nows in the internal convention
	double mx,my;
	convertCoordinates(x,y,mx,my);
	Eigen::Vector3d result;
	// take the center of the bin
	result[2]=(my/(_nRows-1.0)-0.5)*_height;
	double gamma=(mx/(_nCols-1.0)-0.5)*_widthAngle;
	// Angle
	result[1]=_distance*cos(gamma);
	result[0]=_distance*sin(gamma);
	return result;
}

}
}
