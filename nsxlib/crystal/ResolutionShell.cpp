/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2016- Laurent C. Chapon, Eric Pellegrini, Jonathan Fisher

 Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr
 pellegrini[at]ill.fr

 Forschungszentrum Juelich GmbH
 52425 Juelich
 Germany
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

#include <cmath>
#include <set>

#include <Eigen/Eigenvalues>

#include "GCD.h"
#include "Peak3D.h"
#include "ReciprocalVector.h"
#include "ResolutionShell.h"


namespace nsx {

ResolutionShell::ResolutionShell(double dmin, double dmax, size_t num_shells):
    _numShells(std::max(num_shells, size_t(1))),
    _shells(std::max(_numShells, size_t(1))),
    _d(_numShells+1, 0.0)
{
    const double dv = (std::pow(dmin, -3) - std::pow(dmax, -3)) / double(_numShells);
    _d[0] = dmin;

    for (size_t i = 0; i < _numShells; ++i) {
        _d[i+1] = std::pow(std::pow(_d[i], -3) - dv, -1.0/3.0);
    }
}

void ResolutionShell::addPeak(const sptrPeak3D& peak)
{
    auto data = peak->data();
    auto q = peak->q();
    const double d = 1.0 / q.rowVector().norm();

    for (size_t i = 0; i < _d.size()-1; ++i) {
        if (_d[i] <= d && d < _d[i+1]) {
            _shells[i].push_back(peak);
        }
    }
}

const std::vector<PeakList>& ResolutionShell::getShells() const
{
    return _shells;
}

const std::vector<double>& ResolutionShell::getD() const
{
    return _d;
}

const PeakList& ResolutionShell::shell(size_t i) const
{
    if (i >= _shells.size()) {
        throw std::runtime_error("ResolutionShell::shell index out of bounds");
    }
    return _shells[i];
}

} // end namespace nsx
