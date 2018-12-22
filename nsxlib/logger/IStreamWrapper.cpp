// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/logger/IStreamWrapper.cpp
//! @brief     Implements module/class/test IStreamWrapper
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "IStreamWrapper.h"

namespace nsx {

IStreamWrapper::IStreamWrapper(std::function<std::string()> prefix, std::function<std::string()> suffix) : _prefix(prefix), _suffix(suffix) {
}

IStreamWrapper::~IStreamWrapper() {
}

} // end namespace nsx
