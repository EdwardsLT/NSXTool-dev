// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/logger/IStreamWrapper.h
//! @brief     Implements module/class/test IStreamWrapper
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <functional>
#include <string>

namespace nsx {

class Logger;

class IStreamWrapper {
public:

    //! Constructor
    IStreamWrapper(std::function<std::string()> prefix=nullptr, std::function<std::string()> suffix=nullptr);

    IStreamWrapper(const IStreamWrapper& other)=delete;

    //! Destructor
    virtual ~IStreamWrapper()=0;

    IStreamWrapper& operator=(const IStreamWrapper& oter)=delete;

    //! Write a message to the stream
    virtual void print(const std::string& message)=0;

    virtual void printPrefix()=0;

    virtual void printSuffix()=0;

protected:

    std::function<std::string()> _prefix;

    std::function<std::string()> _suffix;


};

} // end namespace nsx
