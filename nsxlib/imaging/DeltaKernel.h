// Delta kernel
// author: Jonathan Fisher
// Forshungszentrum Jülich GmbH
// j.fisher@fz-juelich.de


// Kronecker delta kernel. Used for testing only



#ifndef NSXTOOL_INCLUDE_DELTAKERNEL_H_
#define NSXTOOL_INCLUDE_DELTAKERNEL_H_

#include "ConvolutionKernel.h"

namespace SX {

namespace Imaging {

class DeltaKernel : public ConvolutionKernel
{
public:
	static ConvolutionKernel* create();

public:
    DeltaKernel();
    DeltaKernel(const ConvolutionKernel::ParameterMap& params);

    virtual ~DeltaKernel();

    const char* getName() override;

private:
    void update() override;
};

} // Imaging

} // SX
#endif // NSXTOOL_INCLUDED_DELTAKERNEL_H_
