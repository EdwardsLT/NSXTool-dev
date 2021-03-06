// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/ISigmaIntegrator.cpp
//! @brief     Implements module/class/test ISigmaIntegrator
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "DataSet.h"
#include "Ellipsoid.h"
#include "Intensity.h"
#include "Peak.h"
#include "PeakCoordinateSystem.h"
#include "ShapeLibrary.h"
#include "ISigmaIntegrator.h"

namespace nsx {

ISigmaIntegrator::ISigmaIntegrator(sptrShapeLibrary library, double radius, double nframes):
    PixelSumIntegrator(false, false),
    _library(library),
    _radius(radius),
    _nframes(nframes)
{

}

bool ISigmaIntegrator::compute(sptrPeak peak, const IntegrationRegion& region)
{
    if (!_library) {
        return false;
    }

    if (!peak) {
        return false;
    }

    // first get mean background
    PixelSumIntegrator::compute(peak, region);
    const double mean_bkg = _meanBackground.value();
    const double var_bkg = _meanBackground.variance();

    const auto& events = region.data().events();
    const auto& counts = region.data().counts();

    // TODO: should this be hard-coded??
    if (events.size() < 29) {
        throw std::runtime_error("ISigmaIntegrator::compute(): too few data points in peak");
    }

    std::vector<Intensity> mean_profile;
    Profile1D profile;

    Eigen::Vector3d c = peak->shape().center();
    Eigen::Matrix3d A = peak->shape().metric();

    try {
        // throws if there are no neighboring peaks within the bounds
        mean_profile = _library->meanProfile1D(DetectorEvent(c), _radius, _nframes);
    } catch(...) {
        return false;
    }

    // evaluate the model profile at the given events
    for (int i = 0; i < events.size(); ++i) {
        Eigen::Vector3d dx(events[i]._px, events[i]._py, events[i]._frame);
        dx -= c;
        const double r2 = dx.transpose()*A*dx;
        profile.addPoint(r2, counts[i]);
    }

    int best_idx = -1;
    double best_val = std::numeric_limits<double>::max();
    
    // now compute minimum of sigma(I)^2 / I^2 + sigma(p)^2 / p^2
    for (int i = 0; i < profile.counts().size(); ++i) {
        const double M = profile.counts()[i];
        const int n = profile.npoints()[i];
        const double I = M - n*mean_bkg;
        const double var_I = M + n*n*var_bkg;

        const double p = mean_profile[i].value();
        const double var_p = mean_profile[i].variance();

        const double val = var_I / I / I + var_p / p / p;

        if (val < best_val) {
            best_val = val;
            best_idx = i;
        }
    }

    // something went wrong (nans?)
    if (best_idx < 0) {
        return false;
    }
  
    const double M = profile.counts()[best_idx];
    const int n = profile.npoints()[best_idx];

    _integratedIntensity = Intensity(M-n*mean_bkg, M+n*n*var_bkg);
    _integratedIntensity = _integratedIntensity / mean_profile[best_idx];

    double sigma = _integratedIntensity.sigma();

    if (std::isnan(sigma) || sigma <= 0.0) {
        return false;
    }

    // TODO: rocking curve!

    return true;
}

} // end namespace nsx
