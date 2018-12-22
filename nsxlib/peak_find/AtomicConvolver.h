// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/AtomicConvolver.h
//! @brief     Implements module/class/test AtomicConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <complex>
#include <ostream>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>

#include <fftw3.h>

#include <Eigen/Dense>

#include "IConvolver.h"
#include "MathematicsTypes.h"

namespace nsx {

class AtomicConvolver : public IConvolver {

public:

    AtomicConvolver();

    AtomicConvolver(const std::map<std::string,int> &parameters);

    AtomicConvolver(const AtomicConvolver& other)=default;

    AtomicConvolver& operator=(const AtomicConvolver& other)=default;

    virtual ~AtomicConvolver()=0;

    IConvolver* clone() const=0;

    //! Convolve an image
    virtual RealMatrix convolve(const RealMatrix& image) override;

    virtual std::pair<size_t,size_t> kernelSize() const=0;

protected:

    void updateKernel(int nrows, int ncols);

private:

    void padImage(const RealMatrix& image) const;

    void reset();

protected:

    int _n_rows;

    int _n_cols;

    int _half_cols;

    fftw_plan _forward_plan;

    fftw_plan _backward_plan;

    double* _data;

    fftw_complex* _data_spectrum;

    std::vector<std::complex<double>> _kernel_spectrum;
};

} // end namespace nsx
