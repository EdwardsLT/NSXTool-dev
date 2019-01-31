// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/crystal/ResolutionShell.h
//! @brief     Implements module/class/test ResolutionShell
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <vector>

#include "CrystalTypes.h"

namespace nsx {

//! \class DShell
//! \brief Utility structure to store a list of peaks with resolution in the range [dmin, dmax].
struct DShell {
    //! Minimum value of d, i.e. maximum resolution
    double dmin;
    //! Maximum value of d, i.e. minimum resolution
    double dmax;
    //! List of peaks contained within the shell
    PeakList peaks;
};

//! \class ResolutionShell
//! \brief Class to split a set of peaks into a number of shells based on resolution.
class ResolutionShell {
public:
    //! Construct the given number of cells with abolute minimum dmin and absolute maximum dmax.
    ResolutionShell(double dmin, double dmax, size_t num_shells);
    //! Add a peak to the list of shells. 
    //! It will automatically be added to the appropriate shell.
    void addPeak(const sptrPeak& peak);
    //! Return the given shell.
    const DShell& shell(size_t i) const;
    //! Return the number of shells.
    size_t nShells() const;

private:
    std::vector<DShell> _shells;
};

} // end namespace nsx
