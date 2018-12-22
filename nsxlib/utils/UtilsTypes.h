// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/utils/UtilsTypes.h
//! @brief     Implements module/class/test UtilsTypes
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <functional>
#include <memory>
#include <set>
#include <tuple>

namespace nsx {

class ProgressHandler;

using sptrProgressHandler = std::shared_ptr<ProgressHandler>;

using ConstraintTuple = std::tuple<unsigned int,unsigned int,double>;
using ConstraintSet = std::set<ConstraintTuple>;

using FinishedCallback = std::function<void(bool)>;
using TaskCallback = std::function<bool(void)>;

} // end namespace nsx
