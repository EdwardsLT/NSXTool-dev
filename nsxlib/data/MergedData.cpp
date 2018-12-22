// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/MergedData.cpp
//! @brief     Implements module/class/test MergedData
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "MergedData.h"
#include "MergedPeak.h"

namespace nsx {

MergedData::MergedData() : _space_group("P 1"), _include_friedel(true)
{
}

MergedData::MergedData(const SpaceGroup& space_group, bool include_friedel): _space_group(space_group), _include_friedel(include_friedel), _peaks()
{      
}

bool MergedData::addPeak(const sptrPeak& peak)
{
    MergedPeak new_peak(_space_group, _include_friedel);
    new_peak.addPeak(peak);
    auto it = _peaks.find(new_peak);

    if ( it != _peaks.end() ) {
        MergedPeak merged(*it); 
        merged.addPeak(peak);
        _peaks.erase(it);
        _peaks.emplace(std::move(merged));
        return false;
    }
    _peaks.emplace(std::move(new_peak));
    return true;
}

const MergedPeakSet& MergedData::peaks() const
{
    return _peaks;
}


size_t MergedData::totalSize() const
{
    size_t total = 0;

    for (const auto& peak: _peaks) {
        total += peak.redundancy();
    }
    return total;
}

double MergedData::redundancy() const
{
    return double(totalSize()) / double(_peaks.size());
}

void MergedData::clear()
{
    _peaks.clear();
}

} // end namespace nsx
