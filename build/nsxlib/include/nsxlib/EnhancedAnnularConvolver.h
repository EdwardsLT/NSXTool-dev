// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/EnhancedAnnularConvolver.h
//! @brief     Implements module/class/test EnhancedAnnularConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

// Convolver description: the kernel is non-zero in a circular and annular region, as follows

// [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0]
// [0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0]
// [0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0]
// [0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0]
// [0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0]
// [0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0]
// [0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0]
// [0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0]
// [0, 0, 0, 2, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 2, 2, 2, 0]
// [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2]
// [0, 0, 0, 2, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 2, 2, 2, 0]
// [0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0]
// [0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0]
// [0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0]
// [0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0]
// [0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0]
// [0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0]
// [0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0]
// [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0]

// In region 1, pixels are assigned constant positive value
// In region 2, pixels are assigned a constant negative value.
// The values are chosen so that the integral over region 1 is equal to +1,
// and the integral over region 2 is equal to -1
//
// The motivation is as follows: if a peak is contained inside region 1, then
// the convolution with region 1 computes the average intensity of the peak,
// and the convolution with region 2 computes (minus) the average background
// The the total convolution computes the average intensity minus the average background.
// This make the kernel effective for peak-finding in images which have a non-homogeneous
// background.

#pragma once

#include "AnnularConvolver.h"

namespace nsx {

//! \brief More sophisticated version of local background subtraction.
class EnhancedAnnularConvolver : public AnnularConvolver {

public:

    EnhancedAnnularConvolver();

    EnhancedAnnularConvolver(const EnhancedAnnularConvolver &other)=default;

    EnhancedAnnularConvolver(const std::map<std::string,int>& parameters);

    ~EnhancedAnnularConvolver()=default;

    EnhancedAnnularConvolver& operator=(const EnhancedAnnularConvolver &other)=default;

    IConvolver* clone() const override;

    RealMatrix convolve(const RealMatrix& image) override;
};

} // end namespace nsx
