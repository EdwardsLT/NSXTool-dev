/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2017- Laurent C. Chapon, Eric Pellegrini, Jonathan Fisher

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

#ifndef NSXLIB_AUTOINDEXER_H
#define NSXLIB_AUTOINDEXER_H

#include <vector>

#include "../crystal/UnitCell.h"
#include "../instrument/InstrumentTypes.h"
#include "../utils/UtilsTypes.h"

namespace nsx {

class AutoIndexer {
public:
    struct Parameters {
        double maxdim = 200.0;
        int nSolutions = 10;
        int nStacks = 30;
        int subdiv = 5;
        double HKLTolerance = 0.2;
        double niggliTolerance = 1e-3;
        double gruberTolerance = 4e-2;
        bool niggliReduction = false;
    };

public:
    AutoIndexer(const sptrExperiment& expt, const sptrProgressHandler& handler = nullptr);

    bool autoIndex(const Parameters& params);
    void addPeak(const sptrPeak3D& peak);
    const std::vector<std::pair<UnitCell,double>>& getSolutions() const;

private:
    PeakList _peaks;
    sptrExperiment _experiment;
    std::vector<std::pair<UnitCell,double>> _solutions;
    sptrProgressHandler _handler;
};

} // end namespace nsx

#endif // NSXLIB_AUTOINDEXER_H
