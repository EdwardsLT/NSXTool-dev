#include <stdexcept>

#include <Eigen/Dense>

#include "MonoDetector.h"
#include "Units.h"

namespace SX
{

namespace Instrument
{

MonoDetector::MonoDetector()
: Detector(),
  _nRows(0),
  _nCols(0),
  _minRow(0.0),
  _minCol(0.0),
  _width(0.0),
  _height(0.0),
  _angularWidth(0.0),
  _angularHeight(0.0),
  _distance(0)
{
}

MonoDetector::MonoDetector(const MonoDetector& other)
: Detector(other),
  _nRows(other._nRows),
  _nCols(other._nCols),
  _minRow(other._minRow),
  _minCol(other._minCol),
  _width(other._width),
  _height(other._height),
  _angularWidth(other._angularWidth),
  _angularHeight(other._angularHeight),
  _distance(other._distance)
{
}

MonoDetector::MonoDetector(const std::string& name)
: Detector(name),
  _nRows(0),
  _nCols(0),
  _minRow(0.0),
  _minCol(0.0),
  _width(0.0),
  _height(0.0),
  _angularWidth(0.0),
  _angularHeight(0.0),
  _distance(0)
{
}

MonoDetector::MonoDetector(const proptree::ptree& node) : Detector(node)
{
	Units::UnitsManager* um=SX::Units::UnitsManager::Instance();

	// Set the detector to sample distance from the property tree node
	const property_tree::ptree& distanceNode = node.get_child("sample_distance");
	double units=um->get(distanceNode.get<std::string>("<xmlattr>.units"));
	double distance=distanceNode.get_value<double>();
	distance *= units;
    setDistance(distance);

	// Set the detector number of pixels from the property tree node
	const property_tree::ptree& nColsNode = node.get_child("ncols");
	unsigned int nCols=nColsNode.get_value<unsigned int>();
	const property_tree::ptree& nRowsNode = node.get_child("nrows");
	unsigned int nRows=nRowsNode.get_value<unsigned int>();
    setNPixels(nCols,nRows);

    _minCol = node.get<double>("origin_x",0.0);
    _minRow = node.get<double>("origin_y",0.0);
}

MonoDetector::~MonoDetector()
{
}

MonoDetector& MonoDetector::operator=(const MonoDetector& other)
{
	if (this != &other)
	{
		Detector::operator=(other);
		_nRows = other._nRows;
		_nCols = other._nCols;
		_minRow = other._minRow;
		_minCol = other._minCol;
		_width = other._width;
		_height = other._height;
		_angularWidth = other._angularWidth;
		_angularHeight = other._angularHeight;
		_distance = other._distance;
	}
	return *this;
}

unsigned int MonoDetector::getNPixels() const
{
	return _nCols*_nRows;
}

unsigned int MonoDetector::getNCols() const
{
	return _nCols;
}

void MonoDetector::setNCols(unsigned int cols)
{
	if (cols==0)
		throw std::range_error("MonoDetector "+Component::_name+" number of pixels (row,col) must be >0");
	_nCols=cols;
}


unsigned int MonoDetector::getNRows() const
{
	return _nRows;
}

void MonoDetector::setNRows(unsigned int rows)
{
	if (rows==0)
		throw std::range_error("MonoDetector "+Component::_name+" number of pixels (row,col) must be >0");
	_nRows=rows;
}

void MonoDetector::setOrigin(double px, double py)
{
	_minCol=px;
	_minRow=py;
}

int MonoDetector::getMinRow() const
{
	return _minRow;
}

int MonoDetector::getMaxRow() const
{
	return _minRow+_nRows;
}

int MonoDetector::getMinCol() const
{
	return _minCol;
}

int MonoDetector::getMaxCol() const
{
	return _minCol+_nCols;
}

void MonoDetector::setNPixels(unsigned int cols, unsigned int rows)
{
	setNCols(cols);
	setNRows(rows);
}

bool MonoDetector::hasPixel(double px, double py) const
{

	double dx=px-_minCol;
	double dy=py-_minRow;

	return (dx>=0 && dx<static_cast<double>(_nCols) && dy>=0 && dy<static_cast<double>(_nRows));
}

double MonoDetector::getPixelHeigth() const
{
	return _height/_nRows;
}

double MonoDetector::getPixelWidth() const
{
	return _width/_nCols;
}

double MonoDetector::getHeight() const
{
	return _height;
}

double MonoDetector::getWidth() const
{
	return _width;
}

void MonoDetector::setDimensions(double width, double height)
{
	setWidth(width);
	setHeight(height);
}

double MonoDetector::getAngularHeight() const
{
	return _angularHeight;
}

double MonoDetector::getAngularWidth() const
{
	return _angularWidth;
}

void MonoDetector::setAngularDimensions(double w, double h)
{
	setAngularWidth(w);
	setAngularHeight(h);
}

double MonoDetector::getDistance() const
{
	return _distance;
}

void MonoDetector::setDistance(double d)
{
	_distance=d;
	_position=Eigen::Vector3d(0,d,0);
}

void MonoDetector::setRestPosition(const Eigen::Vector3d& pos)
{
	_position=pos;
	_distance=pos.norm();
}

unsigned int MonoDetector::getNDetectors() const
{
	return 1;
}

} // End namespace Instrument

} // End namespace SX
