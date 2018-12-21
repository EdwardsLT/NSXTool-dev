#pragma once

#include "AtomicConvolver.h"

namespace nsx {

class DeltaConvolver : public AtomicConvolver {

public:

    DeltaConvolver();

    DeltaConvolver(const DeltaConvolver &other)=default;

    DeltaConvolver(const std::map<std::string,int>& parameters);

    ~DeltaConvolver()=default;

    DeltaConvolver& operator=(const DeltaConvolver &other)=default;

    IConvolver* clone() const override;

    virtual std::pair<size_t,size_t> kernelSize() const override;

    RealMatrix matrix() const override;

};

} // end namespace nsx
