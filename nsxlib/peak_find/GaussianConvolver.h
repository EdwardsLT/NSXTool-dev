// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/GaussianConvolver.h
//! @brief     Implements module/class/test GaussianConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include "AtomicConvolver.h"

namespace nsx {

class GaussianConvolver : public AtomicConvolver {

public:

    GaussianConvolver();

    GaussianConvolver(const GaussianConvolver &other)=default;

    GaussianConvolver(const std::map<std::string,int>& parameters);

    ~GaussianConvolver()=default;

    GaussianConvolver& operator=(const GaussianConvolver &other)=default;

    IConvolver* clone() const override;

    virtual std::pair<size_t,size_t> kernelSize() const override;

    RealMatrix matrix() const override;
};

} // end namespace nsx
