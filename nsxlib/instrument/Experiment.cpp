#include <iostream>
#include <stdexcept>
#include <utility>

#include "Monochromator.h"
#include "Diffractometer.h"
#include "DiffractometerStore.h"
#include "Experiment.h"
#include "IData.h"
#include "Source.h"

namespace SX
{

namespace Instrument
{

Experiment::Experiment(const Experiment& other)
: _name(other._name),
  _diffractometerName(other._diffractometerName),
  _diffractometer(other._diffractometer),
  _data(other._data)
{
}

Experiment::Experiment(const std::string& name, const std::string& diffractometerName)
: _name(name),
  _diffractometerName(diffractometerName),
  _data()
{
	DiffractometerStore* ds=DiffractometerStore::Instance();
	_diffractometer = std::shared_ptr<Diffractometer>(ds->buildDiffractomer(diffractometerName));
}

Experiment::Experiment(const std::string& diffractometerName)
: _name("experiment"),
  _diffractometerName(diffractometerName),
  _data()
{
	DiffractometerStore* ds=DiffractometerStore::Instance();
	_diffractometer = std::shared_ptr<Diffractometer>(ds->buildDiffractomer(diffractometerName));
}

Experiment::~Experiment()
{
}

Experiment& Experiment::operator=(const Experiment& other)
{
	if (this != &other)
	{
		_name = other._name;
		_diffractometerName = other._diffractometerName;
		_diffractometer = other._diffractometer;
		_data = other._data;
	}
	return *this;
}

std::shared_ptr<Diffractometer> Experiment::getDiffractometer() const
{
	return _diffractometer;
}

const std::string& Experiment::getDiffractometerType() const
{
	return _diffractometerName;
}

std::vector<std::string> Experiment::getDataNames() const
{
	std::vector<std::string> v;
	v.reserve(_data.size());
	std::for_each(_data.begin(),_data.end(),[&v]
                                             (const std::map<std::string,std::shared_ptr<IData>>::value_type& p)
	                                         {v.push_back(p.first);});

	return v;
}

const std::map<std::string,std::shared_ptr<IData>>& Experiment::getData() const
{
	return _data;
}


std::shared_ptr<IData> Experiment::getData(std::string name)
{
	auto it=_data.find(name);
	if (it == _data.end())
		throw std::runtime_error("The data "+name+" could not be found in the experiment "+_name);

	return _data[name];
}

const std::string& Experiment::getName() const
{
	return _name;
}

void Experiment::setName(const std::string& name)
{
	_name = name;
}

void Experiment::addData(std::shared_ptr<IData> data)
{

	// Add the data only if it does not exist in the current data map
	std::string basename=data->getBasename();
	auto it=_data.find(basename);
	if (it != _data.end())
		return ;

	std::string diffName = data->getMetadata()->getKey<std::string>("Instrument");

	if (!(diffName.compare(_diffractometer->getName())==0))
		throw std::runtime_error("Mismatch between the diffractometers assigned to the experiment and the data");

	double wav=data->getMetadata()->getKey<double>("wavelength");

    // ensure that there is at least one monochromator!
    if ( _diffractometer->getSource()->getNMonochromators() == 0 ) {
        Monochromator mono("mono");
        _diffractometer->getSource()->addMonochromator(&mono);
    }

	if (_data.empty())
	{
		_diffractometer->getSource()->setWavelength(wav);
	}
	else
	{
		if (std::abs(wav-_diffractometer->getSource()->getWavelength())>1e-5)
			throw std::runtime_error("trying to mix data with different wavelengths");
	}

    _data.insert(std::pair<std::string,std::shared_ptr<IData>>(basename,data));
}

bool Experiment::hasData(const std::string& name) const
{
	auto it=_data.find(name);
	return (it != _data.end());
}

void Experiment::removeData(const std::string& name)
{
	auto it=_data.find(name);
	if (it != _data.end())
		_data.erase(it);
}


} // end namespace Instrument

} // end namespace SX