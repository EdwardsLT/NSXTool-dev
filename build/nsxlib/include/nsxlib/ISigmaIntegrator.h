// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/ISigmaIntegrator.h
//! @brief     Implements module/class/test ISigmaIntegrator
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
#include "MeanBackgroundIntegrator.h"
#include "PixelSumIntegrator.h"
#include "ShapeLibrary.h"

namespace nsx {

class DataSet;

//! \brief Compute the integrated intensity via the I/sigma method used in RETREAT.
class ISigmaIntegrator: public PixelSumIntegrator {
public:
    ISigmaIntegrator(sptrShapeLibrary library, double radius, double nframes);
    bool compute(sptrPeak peak, const IntegrationRegion& region) override;
private:
    sptrShapeLibrary _library;
    double _radius;
    double _nframes;
};

} // end namespace nsx
