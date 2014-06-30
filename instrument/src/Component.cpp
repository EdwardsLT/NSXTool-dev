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

#include "Component.h"
#include "HomogeneousTransformation.h"

namespace SX
{

namespace Instrument
{

using SX::Geometry::HomogeneousTransformation;

Component::Component() : _transformation(nullptr)
{
}

Component::Component(const ptree& node)
{
}

const std::string& Component::getName() const
{
	return _name;
}

void Component::parseTransformationNode(const ptree& node)
{

	if (_transformation == nullptr)
		_transformation = new HomogeneousTransformation();

}

Component::~Component()
{
}

} // End namespace Instrument

} // End namespace SX

