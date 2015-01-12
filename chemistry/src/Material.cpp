#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>

#include "Error.h"
#include "Element.h"
#include "Material.h"
#include "Units.h"

namespace SX
{

namespace Chemistry
{

double Material::tolerance=1.0e-6;

std::string Material::database="materials.xml";

materialMap Material::registeredMaterials=materialMap();

std::map<std::string,Material::State> Material::_toState={
		{"solid",Material::State::Solid},
		{"liquid",Material::State::Liquid},
		{"gaz",Material::State::Gaz}
};

std::map<std::string,Material::FillingMode> Material::_toFillingMode={
		{"mass_fraction",Material::FillingMode::MassFraction},
		{"mole_fraction",Material::FillingMode::MoleFraction},
		{"number_of_atoms",Material::FillingMode::numberOfAtoms}
};

Material* Material::buildFromDatabase(const std::string& name)
{
	auto it=registeredMaterials.find(name);
	if (it!=registeredMaterials.end())
		return it->second;
	else
	{
		ptree root;
		read_xml(database,root);

		BOOST_FOREACH(ptree::value_type const& v, root.get_child("materials"))
		{
			if (v.first.compare("material")!=0)
				continue;

			if (v.second.get<std::string>("<xmlattr>.name").compare(name)==0)
				return readMaterial(v.second);
		}
	}
	throw SX::Kernel::Error<Material>("Material "+name+" is not registered in the materials database");

}

Material* Material::readMaterial(const ptree& node)
{

	SX::Units::UnitsManager* um=SX::Units::UnitsManager::Instance();

	// Get the physical states and the filling modes of the material to be constructed
	State state=_toState.at(node.get<std::string>("<xmlattr>.state","solid"));
	FillingMode fMode=_toFillingMode.at(node.get<std::string>("<xmlattr>.filling_mode","mass_fraction"));
	Material* material=new Material(node.get<std::string>("<xmlattr>.name"),state,fMode);
	BOOST_FOREACH(ptree::value_type const& v, node)
	{
		if (v.first.compare("material")==0)
		{
			Material* submaterial;
			boost::optional<std::string> submat=v.second.get_optional<std::string>("<xmlattr>.material");
			if (submat)
				submaterial=buildFromDatabase(submat.get());
			else
				submaterial=readMaterial(v.second);

			if (fMode==FillingMode::MassFraction || fMode==FillingMode::MoleFraction)
			{
				boost::optional<const ptree&> fraction = v.second.get_child_optional("fraction");
				SX::Units::UnitsManager* um=SX::Units::UnitsManager::Instance();
				if (fraction)
				{
					ptree node=fraction.get();
					double units=um->get(node.get<std::string>("<xmlattr>.units","%"));
					material->addMaterial(submaterial,node.get_value<double>()*units);
				}
				else
					throw SX::Kernel::Error<Material>("Misformatted XML 'material' node: must have 'fraction' tag");
			}
			else
			{
				boost::optional<const ptree&> nAtoms = v.second.get_child_optional("natoms");
				if (nAtoms)
				{
					ptree node=nAtoms.get();
					material->addMaterial(submaterial,node.get_value<double>());
				}
				else
					throw SX::Kernel::Error<Material>("Misformatted XML 'material' node: must have 'natoms' tag");

			}


		}
		else if (v.first.compare("element")==0)
		{
			Element* element=Element::readElement(v.second);
			if (fMode==FillingMode::MassFraction || fMode==FillingMode::MoleFraction)
			{
				boost::optional<const ptree&> fraction = v.second.get_child_optional("fraction");
				if (fraction)
				{
					ptree node=fraction.get();
					double units=um->get(node.get<std::string>("<xmlattr>.units","%"));
					material->addElement(element,node.get_value<double>()*units);
				}
				else
					throw SX::Kernel::Error<Material>("Misformatted XML 'element' node: must have 'fraction' tag");
			}
			else
			{
				boost::optional<const ptree&> nAtoms = v.second.get_child_optional("natoms");
				if (nAtoms)
				{
					ptree node=nAtoms.get();
					material->addElement(element,node.get_value<double>());
				}
				else
					throw SX::Kernel::Error<Material>("Misformatted XML 'element' node: must have 'natoms' tag");
			}
		}
	}

	if (material->_state==State::Gaz)
	{
		boost::optional<const ptree&> density = node.get_child_optional("density");
		if (density)
		{
			ptree node=density.get();
			double units=um->get(node.get<std::string>("<xmlattr>.units","kg/m3"));
			material->setDensity(node.get_value<double>()*units);
		}
		else
		{
			const ptree& pNode=node.get_child("pressure");
			double pUnits=um->get(pNode.get<std::string>("<xmlattr>.units","Pa"));
			double pressure=pNode.get_value<double>()*pUnits;

			const ptree& tNode=node.get_child("temperature");
			double tUnits=um->get(tNode.get<std::string>("<xmlattr>.units","K"));
			double temperature=tNode.get_value<double>()*tUnits;

			material->setDensity(pressure,temperature);
		}
	}
	else
	{
		const ptree& density = node.get_child("density");
		double units=um->get(density.get<std::string>("<xmlattr>.units","kg/m3"));
		material->setDensity(density.get_value<double>()*units);
	};

	registeredMaterials.insert(materialPair(material->_name,material));

	return material;
}

Material::Material(const std::string& name, State state, FillingMode fillingMode)
: _name(name),
  _density(1.0),
  _state(state),
  _fillingMode(fillingMode),
  _elements(),
  _fractions()
{
}

void Material::addElement(Element* element, double fraction)
{

	if (_fillingMode==FillingMode::MassFraction || _fillingMode==FillingMode::MoleFraction)
	{
		if (fraction<=0 || fraction>1)
			throw SX::Kernel::Error<Material>("Invalid value for mole fraction");
		double sum=std::accumulate(_fractions.begin(),_fractions.end(),fraction);
		if (sum>(1.0+tolerance))
			throw SX::Kernel::Error<Material>("The sum of mole fractions exceeds 1.0");
	}

	// If the material already contains the element, return
	auto it=std::find(_elements.begin(),_elements.end(),element);
	if (it!=_elements.end())
	{
		unsigned int idx=std::distance(_elements.begin(),it);
		_fractions[idx]+=fraction;
	}
	else
	{
		_elements.push_back(element);
		_fractions.push_back(fraction);
	}

	return;
}

std::map<Element*,double> Material::getMoleFractions() const
{

	std::map<Element*,double> fractions;

	switch(_fillingMode)
	{
	case FillingMode::MoleFraction:
	{
		auto eit=_elements.begin();
		for (auto fit=_fractions.begin();fit!=_fractions.end();++fit,++eit)
			fractions.insert(std::pair<Element*,double>(*eit,*fit));
		break;
	}

	case FillingMode::MassFraction:
	{
		for (unsigned int i=0;i<_elements.size();++i)
		{
			double xi=1.0;
			double mi=_elements[i]->getMolarMass();
			for (unsigned int j=0;j<_elements.size();++j)
			{
				if (i==j) continue;
				double mj=_elements[j]->getMolarMass();
				xi+=(_fractions[j]/_fractions[i])*(mi/mj);
				fractions.insert(std::pair<Element*,double>(_elements[i],1.0/xi));
			}
		}
		break;
	}

	case FillingMode::numberOfAtoms:
	{
		double nAtoms=std::accumulate(_fractions.begin(),_fractions.end(),0.0);
		auto eit=_elements.begin();
		for (auto fit=_fractions.begin();fit!=_fractions.end();++fit,++eit)
			fractions.insert(std::pair<Element*,double>(*eit,*fit/nAtoms));
		break;
	}

	}

	return fractions;
}

std::map<Element*,double> Material::getMassFractions() const
{

	std::map<Element*,double> fractions;

	switch(_fillingMode)
	{
	case FillingMode::MoleFraction:
	{
		for (unsigned int i=0;i<_elements.size();++i)
		{
			double xi=1.0;
			double mi=_elements[i]->getMolarMass();
			for (unsigned int j=0;j<_elements.size();++j)
			{
				if (i==j) continue;
				double mj=_elements[j]->getMolarMass();
				xi+=(_fractions[j]/_fractions[i])*(mj/mi);
				fractions.insert(std::pair<Element*,double>(_elements[i],1.0/xi));
			}
		}
		break;
	}

	case FillingMode::MassFraction:
	{
		auto eit=_elements.begin();
		for (auto fit=_fractions.begin();fit!=_fractions.end();++fit,++eit)
			fractions.insert(std::pair<Element*,double>(*eit,*fit));
		break;
	}

	case FillingMode::numberOfAtoms:
	{
		double totalMass=0.0;
		auto eit=_elements.begin();
		for (unsigned int i=0;i<_elements.size();++i)
		{
			double fimi=_elements[i]->getMolarMass()*_fractions[i];
			fractions.insert(std::pair<Element*,double>(*eit,fimi));
			totalMass+=fimi;
		}
		for (auto& it : fractions)
			it.second/=totalMass;
		break;
	}

	}

	return fractions;
}

void Material::addElement(const std::string& name, double fraction)
{
	Element* el=Element::buildFromDatabase(name);

	addElement(el,fraction);

	return;
}

void Material::addMaterial(const std::string& name, double fraction)
{
	Material* mat=Material::buildFromDatabase(name);

	addMaterial(mat,fraction);

	return;
}

std::map<Element*,double> Material::getNAtomsPerVolume() const
{

	std::map<Element*,double> nAtoms;

	SX::Units::UnitsManager* um=SX::Units::UnitsManager::Instance();

	for (auto it : getMassFractions())
		nAtoms.insert(std::pair<Element*,double>(it.first,um->get("avogadro")*it.second*_density/it.first->getMolarMass()));

	return nAtoms;
}

void Material::addMaterial(Material* material, double fraction)
{
	if (_fillingMode == FillingMode::numberOfAtoms)
		throw SX::Kernel::Error<Material>("Invalid filling mode");

	for (auto it : material->getMassFractions())
		addElement(it.first,fraction*it.second);
}

Material::~Material()
{
}

const std::string& Material::getName() const
{
	return _name;
}

unsigned int Material::getNElements() const
{
	return _elements.size();
}

double Material::getDensity() const
{
	return _density;
}

void Material::setDensity(double density)
{
	if (density<=0)
		throw SX::Kernel::Error<Material>("Negative density value");
	_density=density;
}

void Material::setDensity(double pressure, double temperature)
{

	if (_state!=State::Gaz)
		throw SX::Kernel::Error<Material>("Setting the density from pressure and temperature only applies for materials in gaz state");;

	if (pressure<=0 || temperature<=0)
		throw SX::Kernel::Error<Material>("Negative pressure and/or temperature values");

	SX::Units::UnitsManager* um=SX::Units::UnitsManager::Instance();

	std::map<Element*,double> m=getMoleFractions();

	double moleDensity=pressure/um->get("R")/temperature;
	double density=0.0;

	for (auto it : m)
		density+=moleDensity*it.second*it.first->getMolarMass();

	setDensity(density);
}

const elementVector& Material::getElements() const
{
	return _elements;
}

} // end namespace Chemistry

} // end namespace SX
