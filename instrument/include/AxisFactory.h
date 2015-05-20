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

#ifndef NSXTOOL_AXISFACTORY_H_
#define NSXTOOL_AXISFACTORY_H_

#include <string>

#include "Factory.h"
#include "Singleton.h"
#include "Axis.h"

namespace SX
{

namespace Instrument
{

using namespace SX::Kernel;

class AxisFactory : public Factory<Axis,std::string,const proptree::ptree&>, public Singleton<AxisFactory,Constructor,Destructor>
{
private:
	friend class Constructor<AxisFactory>;
	friend class Destructor<AxisFactory>;
	AxisFactory();
	~AxisFactory();
};

} // end namespace Instrument

} // end namespace SX

#endif /* NSXTOOL_AXISFACTORY_H_ */