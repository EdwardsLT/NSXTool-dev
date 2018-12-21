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

#include <string>
#include <map>
#include <utility>

#include "MathematicsTypes.h"

namespace nsx {

//! This implements an interface for the convolvers used for smoothing data frames prior searcing for peaks
class IConvolver {

public:

    IConvolver()=default;

    IConvolver(const std::map<std::string,int> &parameters);

    virtual ~IConvolver()=0;

    //! Clone this convolver
    virtual IConvolver* clone() const=0;

    // Const getter for kernel parameter
    const std::map<std::string,int>& parameters() const;

    virtual void setParameters(const std::map<std::string,int>& parameters);

    //! Convolve an image
    virtual RealMatrix convolve(const RealMatrix& image)=0;

    //! Return the size of the kernel
    virtual std::pair<size_t,size_t> kernelSize() const=0;

    //! Return the kernel matrix
    virtual RealMatrix matrix() const=0;

    //! Extend the kernel by padding up to n_rows and n_cols and shifting its center to (0,0)
    RealMatrix extendKernel(int n_rows, int n_cols) const;

protected:

    //! The parameters used for this convolver
    std::map<std::string,int> _parameters;

    bool _update_kernel;
};

} // end namespace nsx
