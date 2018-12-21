#include "BoxConvolver.h"

namespace nsx {

BoxConvolver::BoxConvolver()
: AtomicConvolver({{"n_rows",3},{"n_cols",3}})
{
}

BoxConvolver::BoxConvolver(const std::map<std::string,int>& parameters)
: BoxConvolver()
{
    setParameters(parameters);
}

IConvolver* BoxConvolver::clone() const
{
    return new BoxConvolver(*this);
}

std::pair<size_t,size_t> BoxConvolver::kernelSize() const
{
    return std::make_pair(_parameters.at("n_rows"),_parameters.at("n_cols"));
}

RealMatrix BoxConvolver::matrix() const
{
    // sanity checks
    if ((_parameters.at("n_rows") <= 0) || (_parameters.at("n_cols") <= 0)) {
        throw std::runtime_error("Constant kernel called with invalid parameters");
    }

    RealMatrix kernel = RealMatrix::Ones(_parameters.at("n_rows"),_parameters.at("n_cols"));
    kernel /= kernel.sum();

    return kernel;
}

} // end namespace nsx

