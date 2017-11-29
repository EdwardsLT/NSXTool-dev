#include "DeltaKernel.h"

namespace nsx {

ConvolutionKernel* DeltaKernel::create(int nrows, int ncols)
{
	return new DeltaKernel(nrows,ncols);
}

DeltaKernel::DeltaKernel(int nrows, int ncols) : ConvolutionKernel(nrows,ncols)
{
    update();
}

DeltaKernel::DeltaKernel(int nrows, int ncols, const ConvolutionKernelParameters &params)
: ConvolutionKernel(nrows,ncols,params)
{
    update();
}

DeltaKernel::~DeltaKernel()
{
}

const char* DeltaKernel::getName()
{
    return "Delta";
}

void DeltaKernel::update()
{
    int rows, cols;

    // get necessary parameters
    rows = _kernel.rows();
    cols = _kernel.cols();

    // sanity checks
    if ( rows < 0 || cols < 0 ) {
        throw std::runtime_error("Deltaupdate() called with invalid parameters");
    }

    // set kernel equal to kronecker delta
    _kernel = RealMatrix::Zero(rows, cols);
    _kernel(0,0) = 1.0;
}

} // end namespace nsx

