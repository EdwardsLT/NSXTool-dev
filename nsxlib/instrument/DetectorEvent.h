// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/DetectorEvent.h
//! @brief     Implements module/class/test DetectorEvent
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

#include <Eigen/Dense>

#include "Component.h"
#include "DirectVector.h"
#include "Enums.h"
#include "GeometryTypes.h"

namespace nsx {


//! Lightweight class for detector events.
class DetectorEvent {
public:
    //! Constructor
    DetectorEvent(double px = 0, double py = 0, double frame = -1, double tof = -1);

    //! Construct from a 3 vector
    explicit DetectorEvent(Eigen::Vector3d x, double tof = -1);

    //! Detector x-coord
    double _px;
    //! Detector y-coord
    double _py;
    //! Frame number, if applicable
    double _frame;
    //! Time of flight, if applicable
    double _tof;
};

} // end namespace nsx
