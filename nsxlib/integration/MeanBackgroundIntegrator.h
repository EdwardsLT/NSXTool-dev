// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/MeanBackgroundIntegrator.h
//! @brief     Implements module/class/test MeanBackgroundIntegrator
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <Eigen/Dense>

#include "IPeakIntegrator.h"

namespace nsx {

class DataSet;

//! \brief Compute the mean background near a peak.
class MeanBackgroundIntegrator: public IPeakIntegrator {
public:
    MeanBackgroundIntegrator();
    bool compute(sptrPeak3D peak, const IntegrationRegion& region) override;
};

} // end namespace nsx
