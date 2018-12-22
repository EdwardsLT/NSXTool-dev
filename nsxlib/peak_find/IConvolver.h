// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/IConvolver.h
//! @brief     Implements module/class/test IConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

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
