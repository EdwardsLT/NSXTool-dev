// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/DeltaConvolver.h
//! @brief     Implements module/class/test DeltaConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include "AtomicConvolver.h"

namespace nsx {

class DeltaConvolver : public AtomicConvolver {

public:

    DeltaConvolver();

    DeltaConvolver(const DeltaConvolver &other)=default;

    DeltaConvolver(const std::map<std::string,int>& parameters);

    ~DeltaConvolver()=default;

    DeltaConvolver& operator=(const DeltaConvolver &other)=default;

    IConvolver* clone() const override;

    virtual std::pair<size_t,size_t> kernelSize() const override;

    RealMatrix matrix() const override;

};

} // end namespace nsx
