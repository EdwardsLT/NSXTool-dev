// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/Profile1DIntegrator.h
//! @brief     Implements module/class/test Profile1DIntegrator
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

//! \brief Class to integrate peaks using 1d profile fitting.
class Profile1DIntegrator: public IPeakIntegrator {
public:
    //! Construct integrator with given library, peak search radius, and frame bound
    Profile1DIntegrator(sptrShapeLibrary library, double radius, double nframes);
    //! Compute the integrated intensity of the given peakd
    bool compute(sptrPeak peak, const IntegrationRegion& region) override;
private:
    sptrShapeLibrary _library;
    double _radius;
    double _nframes;
};

} // end namespace nsx
