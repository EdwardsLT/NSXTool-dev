#pragma once

#include <functional>

#include "IConvolver.h"

namespace nsx {

//! \brief Factory class for the different image filters.
class ConvolverFactory {

public:

    ConvolverFactory();

    IConvolver* create(const std::string& convolver_type, const std::map<std::string,int>& parameters) const;

    //! return the keys of the object currently registered in the factory
    const std::map<std::string,std::function<IConvolver*(const std::map<std::string,int>&)>>& callbacks() const;

    ~ConvolverFactory()=default;

private:
    std::map<std::string, std::function<IConvolver*(const std::map<std::string,int>&)>> _callbacks;
};

} // end namespace nsx
