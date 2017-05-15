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

#ifndef NSXTOOL_PEAKPREJECTOR_H_
#define NSXTOOL_PEAKREJECTOR_H_

//#include <map>
//#include <memory>

//#include <Eigen/Dense>

//#include "UnitCell.h"
//#include "SpaceGroup.h"
//#include "Peak3D.h"

namespace nsx {

namespace Crystal {
    class Peak3D;
}

namespace Data {
    class DataSet;
}

namespace Utils {
    class ProgressHandler;
}

namespace Crystal {

class PeakRejector {
public:

    bool rejectPeak(const Peak3D& peak) const;

public:

};

} // namespace Crystal
} // end namespace nsx

#endif // NSXTOOL_PEAKREJECTOR
