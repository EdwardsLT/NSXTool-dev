#include "RadialConvolver.h"

namespace nsx {

RadialConvolver::RadialConvolver()
: AtomicConvolver({{"inner_radius",5},{"outer_radius",10}})
{
}

IConvolver* RadialConvolver::clone() const
{
    return new RadialConvolver(*this);
}

RadialConvolver::RadialConvolver(const std::map<std::string,int>& parameters)
: RadialConvolver()
{
    setParameters(parameters);
}

std::pair<size_t,size_t> RadialConvolver::kernelSize() const
{
    // The size of the kernel if equal to the diameter of the outer ring (+1 for th center pixel)
    size_t r = 2*_parameters.at("outer_radius") + 1;

    return std::make_pair(r,r);
}

RealMatrix RadialConvolver::matrix() const
{
    // sanity checks
    if ((_parameters.at("inner_radius") < 0) || (_parameters.at("outer_radius") < _parameters.at("inner_radius"))) {
        throw std::runtime_error("Radial convolver called with invalid parameters");
    }

    const int inner_radius = _parameters.at("inner_radius");
    const int outer_radius = _parameters.at("outer_radius");

    size_t size = 2*outer_radius + 1;
    RealMatrix kernel = RealMatrix::Zero(size,size);

    const double center = outer_radius;

    const double inner_radius2 = inner_radius*inner_radius;
    const double outer_radius2 = outer_radius*outer_radius;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            const double r2 = (i-center)*(i-center) + (j-center)*(j-center);
            if ((r2 >= inner_radius2) && (r2 <= outer_radius2)) {
                kernel(i, j) = 1.0;
            }
        }
    }

    kernel /= kernel.sum();

    return kernel;
}

} // end namespace nsx

