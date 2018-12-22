// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/logger/LogFileStreamWrapper.cpp
//! @brief     Implements module/class/test LogFileStreamWrapper
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "LogFileStreamWrapper.h"

namespace nsx {

LogFileStreamWrapper::LogFileStreamWrapper(const std::string& logfile, std::function<std::string()> prefix, std::function<std::string()> suffix)
: IStreamWrapper(prefix,suffix),
  _stream(logfile,std::fstream::app)
{
}

LogFileStreamWrapper::~LogFileStreamWrapper()
{
    _stream.close();
}

void LogFileStreamWrapper::print(const std::string& message)
{
    _stream << message;
    _stream.flush();
}

void LogFileStreamWrapper::printPrefix()
{
    if (_prefix) {
        _stream<<_prefix();
    }
}

void LogFileStreamWrapper::printSuffix()
{
    if (_suffix) {
        _stream << _suffix();
    }
    _stream.flush();
}

} // end namespace nsx
