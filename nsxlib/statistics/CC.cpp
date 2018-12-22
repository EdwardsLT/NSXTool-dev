// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/statistics/CC.cpp
//! @brief     Implements module/class/test CC
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "CC.h"
#include "MergedData.h"

namespace nsx {

CC::CC():_CChalf(0), _CCstar(0)
{

}

void CC::calculate(const MergedData& data)
{
    std::vector<MergedPeak> peaks;

    for (auto&& peak: data.peaks()) {
        peaks.push_back(peak);
    }
    calculate(peaks);
}

void CC::calculate(const std::vector<MergedPeak>& peaks)
{
    double xx, xy, yy, x, y;
    xx = xy = yy = x = y = 0.0;
    _nPeaks = 0;

    for (auto&& peak: peaks) {
        if (peak.redundancy() < 2) {
            continue;
        }

        auto split = peak.split();
        MergedPeak& p1 = split.first;
        MergedPeak& p2 = split.second;

        const double I1 = p1.intensity().value();
        const double I2 = p2.intensity().value();

        xx += I1*I1;
        xy += I1*I2;
        yy += I2*I2;
        x += I1;
        y += I2;

        ++_nPeaks;
    }

    if (_nPeaks == 0) {
        _CChalf = _CCstar = 0.0;
        return;
    }

    const double numerator = xy - x*y / _nPeaks;
    const double varx = xx - x*x / _nPeaks;
    const double vary = yy - y*y / _nPeaks;

    _CChalf = numerator / std::sqrt(varx*vary);
    _CCstar = std::sqrt( 2*_CChalf / (1.0 + _CChalf));
}

double CC::CChalf() const
{
    return _CChalf;
}

double CC::CCstar() const
{
    return _CCstar;
}

unsigned int CC::nPeaks() const
{
    return _nPeaks;
}

} // end namespace nsx
