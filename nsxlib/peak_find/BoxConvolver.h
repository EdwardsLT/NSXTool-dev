// Convolver description: this kernel is constant with the value 1 / (rows*cols).
// Convolving with this kernel has the effect of taking the average value of the frame.

#pragma once

#include "AtomicConvolver.h"

namespace nsx {

class BoxConvolver : public AtomicConvolver {

public:

    BoxConvolver();

    BoxConvolver(const BoxConvolver &other)=default;

    BoxConvolver(const std::map<std::string,int>& parameters);

    ~BoxConvolver()=default;

    BoxConvolver& operator=(const BoxConvolver &other)=default;

    IConvolver* clone() const override;

    virtual std::pair<size_t,size_t> kernelSize() const override;

    RealMatrix matrix() const override;
};

} // end namespace nsx
