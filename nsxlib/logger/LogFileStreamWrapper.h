// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/logger/LogFileStreamWrapper.h
//! @brief     Implements module/class/test LogFileStreamWrapper
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <fstream>
#include <string>

#include "IStreamWrapper.h"

namespace nsx {

class LogFileStreamWrapper : public IStreamWrapper {
public:

    //! Constructor
    LogFileStreamWrapper(const std::string& logfile, std::function<std::string()> prefix=nullptr, std::function<std::string()> suffix=nullptr);

    //! Destructor
    virtual ~LogFileStreamWrapper();

    //! Write a message to the stream
    virtual void print(const std::string& message) override;

    virtual void printPrefix() override;

    virtual void printSuffix() override;

private:

    std::ofstream _stream;
};

} // end namespace nsx
