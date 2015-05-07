#include "Gonio.h"
#include "Source.h"

namespace SX
{

namespace Instrument
{

Source* Source::create(const property_tree::ptree& node)
{
	// Set the sample name from the XML node
	std::string name=node.get<std::string>("name");

	Source* source=new Source(name);

    // Set the sample goniometer from the XML node

    const property_tree::ptree& goniometerNode=node.get_child("goniometer");

    std::shared_ptr<Gonio> gonio(Gonio::create(goniometerNode));

    source->setGonio(gonio);

    return source;
}

Source::Source()
: Component("source"),
  _wavelength(1.0),
  _offset(0.0),
  _offsetFixed(true),
  _width(0.01),
  _height(0.01)
{
}

Source::Source(const Source& other)
: Component(other),
  _wavelength(other._wavelength),
  _offset(other._offset),
  _offsetFixed(other._offsetFixed),
  _width(other._width),
  _height(other._height)
{
}

Source::Source(const std::string& name)
: Component(name),
  _wavelength(1.0),
  _offset(0.0),
  _offsetFixed(true),
  _width(0.01),
  _height(0.01)
{
}

void Source::buildFromXML(const property_tree::ptree& node)
{
	// Set the source name from the XML node
	std::string sourceName=node.get<std::string>("name");
	this->setName(sourceName);
}

Source::~Source()
{
}

Source& Source::operator=(const Source& other)
{
	if (this != &other)
	{
		Component::operator=(other);
		_wavelength = other._wavelength;
		_offset = other._offset;
		_offsetFixed = other._offsetFixed;
		_width = other._width;
		_height = other._height;
	}
	return *this;
}

Component* Source::clone() const
{
	return new Source(*this);
}

double Source::getWavelength() const
{
	return (_wavelength+_offset);
}

void Source::setWavelength(double wavelength)
{
	_wavelength=wavelength;
}

Eigen::Vector3d Source::getki() const
{
	return Eigen::Vector3d(0,1.0/(_wavelength+_offset),0.0);
}

void Source::setOffset(double off)
{
	if (!_offsetFixed)
		_offset=off;
}
void Source::setOffsetFixed(bool fixed)
{
	_offsetFixed=fixed;
}

bool Source::hasOffsetFixed() const
{
	return _offsetFixed;
}

double Source::getWidth() const
{
	return _width;
}

void Source::setWidth(double width)
{
	_width=width;
}

double Source::getHeight() const
{
	return _height;
}

void Source::setHeight(double height)
{
	_height=height;
}

} // end namespace Instrument

} // end namespace SX
