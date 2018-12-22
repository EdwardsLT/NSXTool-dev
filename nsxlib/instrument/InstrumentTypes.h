// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/InstrumentTypes.h
//! @brief     Implements module/class/test InstrumentTypes
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <memory>
#include <vector>

namespace nsx {

class Component;
class DetectorEvent;
class Experiment;
class Gonio;
class InstrumentState;
class RotAxis;
class TransAxis;

using sptrExperiment = std::shared_ptr<Experiment>;

using InstrumentStateList = std::vector<InstrumentState>;

using DetectorState = std::vector<double>;

} // end namespace nsx
