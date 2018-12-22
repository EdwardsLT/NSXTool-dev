// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/logger/AggregateStreamWrapper.h
//! @brief     Implements module/class/test AggregateStreamWrapper
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <functional>
#include <vector>

#include "IStreamWrapper.h"

namespace nsx {

class AggregateStreamWrapper : public IStreamWrapper {
public:

    AggregateStreamWrapper(std::function<std::string()> prefix=nullptr, std::function<std::string()> suffix=nullptr);

    virtual ~AggregateStreamWrapper();

    void addWrapper(IStreamWrapper* wrapper);

    virtual void print(const std::string& message) override;

    virtual void printPrefix() override;

    virtual void printSuffix() override;

private:

    std::vector<IStreamWrapper*> _wrappers;

};

} // end namespace nsx
