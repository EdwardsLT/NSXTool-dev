// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/MergedData.h
//! @brief     Implements module/class/test MergedData
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <set>

#include <Eigen/Dense>

#include "CrystalTypes.h"
#include "MergedPeak.h"

namespace nsx {

class DataSet;

//! \brief Class to handle merged datasets.
class MergedData {
public:

    //! Construct a default merged dataset with P1 spacegroup including friedel reflections.
    MergedData();

    //! Construct merged dataset with given spacegroup. Paramter \p friedel determines whether
    //! to include the Friedel relation \f$q \mapsto -q\f$, if this is not already part of the
    //! space group symmetry.  
    MergedData(const SpaceGroup& space_group, bool include_friedel);

    //! Add a peak to the data set. It will be automatically merged correctly according to
    //! the space group symmetry.
    bool addPeak(const sptrPeak3D& peak);

    //! Retern the set of merged peaks.
    const MergedPeakSet& peaks() const;

    //! Return redundancy = observations / symmetry-inequvialent peaks.
    double redundancy() const;

    //! Return total number of observations (including redundant ones)
    size_t totalSize() const;
    
    //! Clear the merged data
    void clear();

private:
    SpaceGroup _space_group;

    bool _include_friedel;

    MergedPeakSet _peaks;
};

} // end namespace nsx
