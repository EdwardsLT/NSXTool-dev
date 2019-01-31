// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/crystal/PeakData.h
//! @brief     Implements module/class/test PeakData
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <deque>
#include <Eigen/Dense>

#include "CrystalTypes.h"
#include "DetectorEvent.h"
#include "GeometryTypes.h"
#include "InstrumentTypes.h"
#include "ReciprocalVector.h"
#include "PeakCoordinateSystem.h"

namespace nsx {

//! \class PeakData
//! \brief Helper class used by integration routines.
class PeakData {
public:
    //! Construct instance associated to the given peak
    PeakData(sptrPeak peak = nullptr);
    //! Return the list of detector events associated to the peak
    const std::deque<DetectorEvent>& events() const;
    //! Return the list of detector counts associated to the peak
    const std::deque<double>& counts() const;
    //! Compute the standard coordinates for each of the observed events.
    void computeStandard();
    //! Add an event to the list of events.
    void addEvent(const DetectorEvent& ev, double count);
    //! Clear the events
    void reset();

private:
    sptrPeak _peak;
    PeakCoordinateSystem _system;
    std::deque<DetectorEvent> _events;
    std::deque<double> _counts;
    std::deque<Eigen::Vector3d> _coords;
};

} // end namespace nsx
