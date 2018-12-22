// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/AnnularConvolver.h
//! @brief     Implements module/class/test AnnularConvolver
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
// Thus the total convolution computes the average intensity minus the average background.
// This make the kernel effective for peak-finding in images which have a non-homogeneous
// background.

#pragma once

#include <memory>

#include "IConvolver.h"

namespace nsx {

class RadialConvolver;

//! Annular convolution kernel used for local background subtraction.
class AnnularConvolver: public IConvolver {

public:

    AnnularConvolver();

    AnnularConvolver(const AnnularConvolver &other);

    AnnularConvolver(const std::map<std::string,int>& parameters);

    ~AnnularConvolver()=default;

    AnnularConvolver& operator=(const AnnularConvolver &other);

    IConvolver* clone() const override;

    virtual std::pair<size_t,size_t> kernelSize() const override;

    void setParameters(const std::map<std::string,int>& parameters) override;

    RealMatrix convolve(const RealMatrix& image) override;

    RealMatrix matrix() const override;

protected:

    std::unique_ptr<RadialConvolver> _radial_convolver_peak;

    std::unique_ptr<RadialConvolver> _radial_convolver_background;

};

} // end namespace nsx
