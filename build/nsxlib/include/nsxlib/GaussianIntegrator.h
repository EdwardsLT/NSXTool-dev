// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/GaussianIntegrator.h
//! @brief     Implements module/class/test GaussianIntegrator
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <Eigen/Dense>

#include "GeometryTypes.h"
#include "IPeakIntegrator.h"
#include "ShapeLibrary.h"

namespace nsx {

class DataSet;

//! \brief Compute integrated intensity by fitting to an analytic 3d Gaussian.
class GaussianIntegrator: public IPeakIntegrator {
public:
    GaussianIntegrator(bool fit_center, bool fit_cov);
    bool compute(sptrPeak peak, const IntegrationRegion& region) override;
    //! Return the analytic profile computed over the given integration region
    std::vector<double> profile(sptrPeak peak, const IntegrationRegion& region);

private:
    bool _fitCenter;
    bool _fitCov;
};

} // end namespace nsx
