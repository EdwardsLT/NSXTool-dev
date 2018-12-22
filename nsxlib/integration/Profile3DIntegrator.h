// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/Profile3DIntegrator.h
//! @brief     Implements module/class/test Profile3DIntegrator
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

//! \brief Peak integrator using 3d profile fitting, as described by Kabsch (1988, 2010).
class Profile3DIntegrator: public IPeakIntegrator {
public:
    Profile3DIntegrator(sptrShapeLibrary library, double radius, double nframes, bool detector_space);
    bool compute(sptrPeak peak, const IntegrationRegion& region) override;
private:
    sptrShapeLibrary _library;
    double _radius;
    double _nframes;
};

} // end namespace nsx
