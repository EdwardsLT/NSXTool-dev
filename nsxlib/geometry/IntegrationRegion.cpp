/*
 * nsxtool : Neutron Single Crystal analysis toolkit
    ------------------------------------------------------------------------------------------
    Copyright (C)
    2017- Laurent C. Chapon, Eric C. Pellegrini Institut Laue-Langevin 
          Jonathan Fisher, Forschungszentrum Juelich GmbH
    BP 156
    6, rue Jules Horowitz
    38042 Grenoble Cedex 9
    France
    chapon[at]ill.fr
    pellegrini[at]ill.fr
    j.fisher[at]fz-juelich.de

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

#include "IntegrationRegion.h"

#include "AABB.h"
#include "Ellipsoid.h"

#include <list>

namespace SX {
namespace Geometry {

void IntegrationRegion::setPeak(const IntegrationRegion::Ellipsoid3D &peak)
{
    _peak = peak;
}

const IntegrationRegion::Ellipsoid3D &IntegrationRegion::getPeak() const
{
    return _peak;
}

void IntegrationRegion::setBackground(const IntegrationRegion::Ellipsoid3D &background)
{
    _bkg = background;
}

const IntegrationRegion::Ellipsoid3D &IntegrationRegion::getBackground() const
{
    return _bkg;
}

bool IntegrationRegion::isInside(const Eigen::Vector4d &p) const
{
    //bool inbackground = (bkg.isInsideAABB(_state.point1) && bkg.isInside(_state.point1));
    //bool inpeak = (peak.isInsideAABB(_state.point1) && peak.isInside(_state.point1));
    if (!_peak.isInsideAABB(p)) {
        return false;
    }
    return _peak.isInside(p);
}

bool IntegrationRegion::inBackground(const Eigen::Vector4d &p) const
{
    if (!_bkg.isInsideAABB(p)) {
        return false;
    }
    return _bkg.isInside(p);
}



} // namespace Geometry
} // namespace SX
