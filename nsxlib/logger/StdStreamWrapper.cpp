// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/logger/StdStreamWrapper.cpp
//! @brief     Implements module/class/test StdStreamWrapper
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "StdStreamWrapper.h"

namespace nsx {

StdStreamWrapper::StdStreamWrapper(std::ostream& stream, std::function<std::string()> prefix, std::function<std::string()> suffix)
: IStreamWrapper(prefix, suffix),
  _stream(stream)
{
}

StdStreamWrapper::~StdStreamWrapper() {
}

void StdStreamWrapper::print(const std::string& message)
{
    _stream << message;
}

void StdStreamWrapper::printPrefix()
{
    if (_prefix) {
        _stream<<_prefix();
    }
}

void StdStreamWrapper::printSuffix()
{
    if (_suffix) {
        _stream << _suffix();
    }
    _stream.flush();
}

} // end namespace nsx
