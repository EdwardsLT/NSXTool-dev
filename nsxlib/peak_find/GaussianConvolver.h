#pragma once

#include "AtomicConvolver.h"

namespace nsx {

class GaussianConvolver : public AtomicConvolver {

public:

    GaussianConvolver();

    GaussianConvolver(const GaussianConvolver &other)=default;

    GaussianConvolver(const std::map<std::string,int>& parameters);

    ~GaussianConvolver()=default;

    GaussianConvolver& operator=(const GaussianConvolver &other)=default;

    IConvolver* clone() const override;

    virtual std::pair<size_t,size_t> kernelSize() const override;

    RealMatrix matrix() const override;
};

} // end namespace nsx
