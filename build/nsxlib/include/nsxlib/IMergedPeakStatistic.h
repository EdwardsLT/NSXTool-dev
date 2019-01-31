// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/statistics/IMergedPeakStatistic.h
//! @brief     Implements module/class/test IMergedPeakStatistic
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include "CrystalTypes.h"

namespace nsx {


class MergedData;

//! \class IMergedPeakStatistic
//! \brief Interface for statistics of merged peaks (e.g. R factors, correlation coefficient, chi-squared).
class IMergedPeakStatistic {
public:
    virtual ~IMergedPeakStatistic() = default;
    //! Calculate the statistic on a given merged data set.
    virtual void calculate(const MergedData& data) = 0;
    //! Retrieve the value of the computed statistic.
    double value() const;
};

} // end namespace nsx
