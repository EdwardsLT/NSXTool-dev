// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/PixelSumIntegrator.h
//! @brief     Implements module/class/test PixelSumIntegrator
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <Eigen/Dense>

#include "MeanBackgroundIntegrator.h"

namespace nsx {

class DataSet;

//! \brief Peak integration using naive background estimation and subtraction.
class PixelSumIntegrator: public MeanBackgroundIntegrator {
public:
    //! Construct the pixel sum integrator
    /** \param fit_center update the peak center as part of integration
     *  \param fit_covariance update the peak shape covariance matrix as part of integration
     */
    PixelSumIntegrator(bool fit_center, bool fit_covariance);
    ~PixelSumIntegrator();
    bool compute(sptrPeak peak, const IntegrationRegion& region) override;
private:
    bool _fitCenter;
    bool _fitCovariance;
};

} // end namespace nsx
