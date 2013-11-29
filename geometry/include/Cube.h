/*
 * nsxtool : Neutron Single Crystal analysis toolkit
    ------------------------------------------------------------------------------------------
    Copyright (C)
    2012- Laurent C. Chapon, Eric C. Pellegrini Institut Laue-Langevin
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

#ifndef NSXTOOL_CUBE_H_
#define NSXTOOL_CUBE_H_

#include <boost/numeric/ublas/vector.hpp>

#include "ROI.h"

namespace SX
{

namespace Geometry
{

namespace ublas=boost::numeric::ublas;

typedef unsigned int uint;

class Cube : public ROI<double,3>
{
public:

	Cube();

	Cube(const ublas::bounded_vector<double,3>& lb, const ublas::bounded_vector<double,3>& ub);

private:

};

Cube::Cube() : ROI<double,3>()
{
}

Cube::Cube(const ublas::bounded_vector<double,3>& lb, const ublas::bounded_vector<double,3>& ub) : ROI<double,3>(lb,ub)
{
}

} // end namespace Geometry

} // end namespace SX

#endif // NSXTOOL_CUBE_H_
