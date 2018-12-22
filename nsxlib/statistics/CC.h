// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/statistics/CC.h
//! @brief     Implements module/class/test CC
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include "MergedPeak.h"

namespace nsx {
    class MergedData;

//! Class to handle calculation of correlation coefficients (CChalf and CC*)
class CC {
public:
    //! Default constructor
    CC();
    //! Calculate the statistic on the given set of merged peaks.
    void calculate(const std::vector<MergedPeak>& peaks);
    //! Calculate the statistic on the given data.
    void calculate(const MergedData& data);
    //! Return CC half (correlation of a random split of data into two bags)
    double CChalf() const;
    //! Return CC star (estimate)
    double CCstar() const;
    //! Return number of peaks
    unsigned int nPeaks() const;
private:
    double _CChalf;
    double _CCstar;
    unsigned int _nPeaks;
};

} // end namespace nsx
