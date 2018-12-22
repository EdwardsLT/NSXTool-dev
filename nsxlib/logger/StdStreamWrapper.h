// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/logger/StdStreamWrapper.h
//! @brief     Implements module/class/test StdStreamWrapper
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <ostream>

#include "IStreamWrapper.h"

namespace nsx {

class StdStreamWrapper : public IStreamWrapper {
public:

    //! Constructor
    StdStreamWrapper(std::ostream& stream, std::function<std::string()> prefix=nullptr, std::function<std::string()> suffix=nullptr);

    //! Destructor
    virtual ~StdStreamWrapper();

    //! Write a message to the stream
    virtual void print(const std::string& message) override;

    virtual void printPrefix() override;

    virtual void printSuffix() override;

private:
    std::ostream& _stream;
};

} // end namespace nsx
