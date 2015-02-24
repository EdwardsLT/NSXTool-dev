#include <limits>

#include <boost/filesystem.hpp>

#include "Error.h"
#include "Isotope.h"
#include "Path.h"
#include "Units.h"

namespace SX
{

namespace Chemistry
{

sptrIsotope Isotope::create(const std::string& name)
{
	return sptrIsotope(new Isotope(name));
}

sptrIsotope Isotope::create(const property_tree::ptree& node)
{

	SX::Units::UnitsManager* um = SX::Units::UnitsManager::Instance();
	double units;

	// Create an empty isotope and fill it with its corresponding XML tags
	Isotope* is=new Isotope();

	is->_name=node.get<std::string>("<xmlattr>.name");

	is->_symbol=node.get<std::string>("symbol");

	is->_element=node.get<std::string>("element");

	is->_nProtons=node.get<int>("n_protons");

	is->_nNucleons=node.get<int>("n_nucleons");

	is->_nElectrons=is->_nProtons;

	// If no units provided for molar_mass take g/mol as the default one
	units=um->get(node.get<std::string>("molar_mass.<xmlattr>.units","g_per_mole"));
	is->_molarMass=node.get<double>("molar_mass")*units;

	is->_nuclearSpin=node.get<double>("nuclear_spin");

	is->_state=node.get<std::string>("state");

	// If no units provided for abundance take % as the default one
	units=um->get(node.get<std::string>("half_life.<xmlattr>.units","%"));
	is->_abundance=node.get<double>("abundance",0.0)*units;

	// If no units provided for half_life take year as the default one
	units=um->get(node.get<std::string>("half_life.<xmlattr>.units","year"));
	is->_halfLife=node.get<double>("half_life",std::numeric_limits<double>::infinity())*units;

	is->_stable=node.get<bool>("stable");

	// If no units provided for b_coherent take fm as the default one
	units=um->get(node.get<std::string>("b_coherent.<xmlattr>.units","fm"));
	is->_bCoherent=node.get<std::complex<double>>("b_coherent")*units;

	// If no units provided for b_incoherent take fm as the default one
	units=um->get(node.get<std::string>("b_incoherent.<xmlattr>.units","fm"));
	is->_bIncoherent=node.get<std::complex<double>>("b_incoherent")*units;

	// If no units provided for b_plus take fm as the default one
	units=um->get(node.get<std::string>("b_plus.<xmlattr>.units","fm"));
	is->_bPlus=node.get<std::complex<double>>("b_plus",is->_bCoherent)*units;

	// If no units provided for b_minus take fm as the default one
	units=um->get(node.get<std::string>("b_minus.<xmlattr>.units","fm"));
	is->_bMinus=node.get<std::complex<double>>("b_minus",is->_bCoherent)*units;

	// If no units provided for xs_coherent take barn as the default one
	units=um->get(node.get<std::string>("xs_coherent.<xmlattr>.units","barn"));
	is->_xsCoherent=node.get<double>("xs_coherent")*units;

	// If no units provided for xs_incoherent take barn as the default one
	units=um->get(node.get<std::string>("xs_incoherent.<xmlattr>.units","barn"));
	is->_xsIncoherent=node.get<double>("xs_incoherent")*units;

	// If no units provided for xs_scattering take barn as the default one
	units=um->get(node.get<std::string>("xs_scattering.<xmlattr>.units","barn"));
	is->_xsScattering=node.get<double>("xs_scattering")*units;

	// If no units provided for xs_absorption take barn as the default one
	units=um->get(node.get<std::string>("xs_absorption.<xmlattr>.units","barn"));
	is->_xsAbsorption=node.get<double>("xs_absorption")*units;

	return sptrIsotope(is);
}

Isotope::Isotope()
: _name(""),
  _symbol(""),
  _element(""),
  _nProtons(0),
  _nNucleons(0),
  _nElectrons(0),
  _molarMass(0.0),
  _nuclearSpin(0.0),
  _state(""),
  _abundance(0.0),
  _halfLife(0.0),
  _stable(true),
  _bCoherent(0.0),
  _bIncoherent(0.0),
  _bPlus(0.0),
  _bMinus(0.0),
  _xsCoherent(0.0),
  _xsIncoherent(0.0),
  _xsScattering(0.0),
  _xsAbsorption(0.0)
{
}

Isotope::Isotope(const std::string& name)
: _name(name),
  _symbol(""),
  _element(""),
  _nProtons(0),
  _nNucleons(0),
  _nElectrons(0),
  _molarMass(0.0),
  _nuclearSpin(0.0),
  _state(""),
  _abundance(0.0),
  _halfLife(0.0),
  _stable(true),
  _bCoherent(0.0),
  _bIncoherent(0.0),
  _bPlus(0.0),
  _bMinus(0.0),
  _xsCoherent(0.0),
  _xsIncoherent(0.0),
  _xsScattering(0.0),
  _xsAbsorption(0.0)
{
}

Isotope::~Isotope()
{
}

bool Isotope::operator==(const Isotope& other)
{
	// Two isotopes is1 and is2 are considered to be equal if Z(is1)=Z(is2) and A(is1)=A(is2)
	return ((_nProtons==other._nProtons) && (_nNucleons==other._nNucleons));
}

const std::string& Isotope::getName() const
{
	return _name;
}

const std::string& Isotope::getSymbol() const
{
	return _symbol;
}

const std::string& Isotope::getState() const
{
	return _state;
}

double Isotope::getNuclearSpin() const
{
	return _nuclearSpin;
}

double Isotope::getAbundance() const
{
	return _abundance;
}

double Isotope::getHalfLife() const
{
	return _halfLife;
}

bool Isotope::getStable() const
{
	return _stable;
}

double Isotope::getFormalCharge() const
{
	return (_nProtons-_nElectrons);
}

double Isotope::getMolarMass() const
{
	return _molarMass;
}

double Isotope::getNNeutrons() const
{
	return (_nNucleons-_nProtons);
}

double Isotope::getNNucleons() const
{
	return _nNucleons;
}

double Isotope::getNElectrons() const
{
	return _nElectrons;
}

double Isotope::getNProtons() const
{
	return _nProtons;
}

std::complex<double>  Isotope::getBCoherent() const
{
	return _bCoherent;
}

std::complex<double>  Isotope::getBIncoherent() const
{
	return _bIncoherent;
}

std::complex<double>  Isotope::getBPlus() const
{
	return _bPlus;
}

std::complex<double>  Isotope::getBMinus() const
{
	return _bMinus;
}

double Isotope::getXsCoherent() const
{
	return _xsCoherent;
}

double Isotope::getXsIncoherent() const
{
	return _xsIncoherent;
}

double Isotope::getXsAbsorption() const
{
	return _xsAbsorption;
}

double Isotope::getXsScattering() const
{
	return _xsScattering;
}

bool Isotope::isIon() const
{
	return (_nProtons!=_nElectrons);
}

bool Isotope::isAnion() const
{
	return (_nProtons<_nElectrons);
}

bool Isotope::isCation() const
{
	return (_nProtons>_nElectrons);
}

void Isotope::print(std::ostream& os) const
{
	os<<"Isotope "<<_name<<" ["<<_nProtons<<","<<_nNucleons<<"]";
}

std::ostream& operator<<(std::ostream& os,const Isotope& isotope)
{
	isotope.print(os);
	return os;
}

} // end namespace Chemistry

} // end namespace SX
