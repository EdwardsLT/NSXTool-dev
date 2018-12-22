// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/BoxConvolver.h
//! @brief     Implements module/class/test BoxConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

// Convolver description: this kernel is constant with the value 1 / (rows*cols).
// Convolving with this kernel has the effect of taking the average value of the frame.

#pragma once

#include "AtomicConvolver.h"

namespace nsx {

class BoxConvolver : public AtomicConvolver {

public:

    BoxConvolver();

    BoxConvolver(const BoxConvolver &other)=default;

    BoxConvolver(const std::map<std::string,int>& parameters);

    ~BoxConvolver()=default;

    BoxConvolver& operator=(const BoxConvolver &other)=default;

    IConvolver* clone() const override;

    virtual std::pair<size_t,size_t> kernelSize() const override;

    RealMatrix matrix() const override;
};

} // end namespace nsx
