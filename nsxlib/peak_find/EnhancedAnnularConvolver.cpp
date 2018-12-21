#include <math.h>

#include "EnhancedAnnularConvolver.h"
#include "RadialConvolver.h"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

// M_PI is often defined but not standard
#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502884
#endif

namespace nsx {

EnhancedAnnularConvolver::EnhancedAnnularConvolver()
: AnnularConvolver()
{
}

EnhancedAnnularConvolver::EnhancedAnnularConvolver(const std::map<std::string,int>& parameters)
: AnnularConvolver(parameters)
{
}

IConvolver* EnhancedAnnularConvolver::clone() const
{
    return new EnhancedAnnularConvolver(*this);
}

RealMatrix EnhancedAnnularConvolver::convolve(const RealMatrix& image)
{
    RealMatrix convoluted_peak = _radial_convolver_peak->convolve(image);

    RealMatrix convoluted_background = _radial_convolver_background->convolve(image);

    RealMatrix diff2 = (image - convoluted_background).cwiseProduct(image-convoluted_background);
    RealMatrix stddev = _radial_convolver_background->convolve(diff2).array().sqrt();

    RealMatrix result = (convoluted_peak - convoluted_background).array() / stddev.array();

    return result;
}

} // end namespace nsx

