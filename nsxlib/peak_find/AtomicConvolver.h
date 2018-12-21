/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon, Eric Pellegrini, Jonathan Fisher
 Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr
 pellegrini[at]ill.fr
 j.fisher[at]fz-juelich.de

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

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
