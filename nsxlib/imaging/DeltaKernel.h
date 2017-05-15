// Delta kernel
// author: Jonathan Fisher
// Forschungszentrum Jülich GmbH
// j.fisher@fz-juelich.de


// Kronecker delta kernel. Used for testing only

#ifndef NSXTOOL_INCLUDE_DELTAKERNEL_H_
#define NSXTOOL_INCLUDE_DELTAKERNEL_H_

#include "ConvolutionKernel.h"

namespace nsx {

class DeltaKernel : public ConvolutionKernel {
public:
	static ConvolutionKernel* create(int nrows, int ncols);

public:
    DeltaKernel(int nrows, int ncols);
    DeltaKernel(int nrows, int ncols, const ConvolutionKernel::ParameterMap& params);

    virtual ~DeltaKernel();

    const char* getName() override;

private:
    void update() override;
};

} // end namespace nsx

#endif // NSXTOOL_INCLUDED_DELTAKERNEL_H_
