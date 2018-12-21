#include "DeltaConvolver.h"

namespace nsx {

DeltaConvolver::DeltaConvolver()
: AtomicConvolver()
{
}

DeltaConvolver::DeltaConvolver(const std::map<std::string,int>& parameters)
: DeltaConvolver()
{
    setParameters(parameters);
}

IConvolver* DeltaConvolver::clone() const
{
    return new DeltaConvolver(*this);
}

std::pair<size_t,size_t> DeltaConvolver::kernelSize() const
{
    return std::make_pair(1,1);
}

RealMatrix DeltaConvolver::matrix() const
{
    RealMatrix kernel = RealMatrix::Zero(1, 1);
    kernel(0,0) = 1.0;

    return kernel;
}

} // end namespace nsx

