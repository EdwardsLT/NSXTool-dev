// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/ConvolverFactory.cpp
//! @brief     Implements module/class/test ConvolverFactory
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "AnnularConvolver.h"
#include "BoxConvolver.h"
#include "ConvolverFactory.h"
#include "DeltaConvolver.h"
#include "EnhancedAnnularConvolver.h"
#include "GaussianConvolver.h"
#include "RadialConvolver.h"

namespace nsx {

using convolver_callback = std::function<IConvolver*(const std::map<std::string,int>&)>;

template <typename T>
T* create_convolver(const std::map<std::string,int>& parameters)
{
    return new T(parameters);
}

ConvolverFactory::ConvolverFactory(): _callbacks()
{
    _callbacks["annular"] = &create_convolver<AnnularConvolver>;
    _callbacks["box"] = &create_convolver<BoxConvolver>;
    _callbacks["delta"] = &create_convolver<DeltaConvolver>;
    _callbacks["enhanced annular"] = &create_convolver<EnhancedAnnularConvolver>;
    _callbacks["gaussian"] = &create_convolver<GaussianConvolver>;
    _callbacks["none"] = &create_convolver<DeltaConvolver>;
    _callbacks["radial"] = &create_convolver<RadialConvolver>;
}

IConvolver* ConvolverFactory::create(const std::string& convolver_type, const std::map<std::string,int>& parameters) const
{
    const auto it = _callbacks.find(convolver_type);

    // could not find key
    if (it == _callbacks.end()) {
        throw std::runtime_error(convolver_type + " is not registered as a valid convolver");
    }

    return (it->second)(parameters);
}

const std::map<std::string,convolver_callback>& ConvolverFactory::callbacks() const
{
    return _callbacks;
}

} // end namespace nsx

