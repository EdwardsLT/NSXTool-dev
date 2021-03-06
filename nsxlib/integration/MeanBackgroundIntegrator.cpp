// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/MeanBackgroundIntegrator.cpp
//! @brief     Implements module/class/test MeanBackgroundIntegrator
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
#include "MeanBackgroundIntegrator.h"
#include "Peak.h"

namespace nsx {

MeanBackgroundIntegrator::MeanBackgroundIntegrator(): IPeakIntegrator()
{

}

bool MeanBackgroundIntegrator::compute(sptrPeak peak, const IntegrationRegion& region)
{
    double sum_bkg = 0.0;
    double sum_bkg2 = 0.0;
    size_t nbkg = 0;
 
    const auto& events = region.data().events();
    const auto& counts = region.data().counts();

    // TODO: should this be hard-coded??
    if (events.size() < 20) {
        throw std::runtime_error("MeanBackgroundIntegrator::compute(): too few data points");
    }

    // compute initial mean background and error
    for (auto i = 0; i < counts.size(); ++i) {
        if (region.classify(events[i]) != IntegrationRegion::EventType::BACKGROUND) {
            continue;
        }
        sum_bkg += counts[i];
        sum_bkg2 += counts[i]*counts[i];
        nbkg++;
    }

    double mean_bkg = sum_bkg / nbkg;
    double var_bkg = (sum_bkg2 - nbkg*mean_bkg*mean_bkg) / (nbkg-1);
    double sigma_bkg = std::sqrt(var_bkg);

    // update mean, rejecting outliers
    for (auto i = 0; i < 20; ++i) {
        sum_bkg = 0;
        sum_bkg2 = 0;
        nbkg = 0;

        for (auto i = 0; i < counts.size(); ++i) {
            if (std::fabs(counts[i]-mean_bkg) > 3*sigma_bkg || region.classify(events[i]) != IntegrationRegion::EventType::BACKGROUND) {
                continue;
            }
            sum_bkg += counts[i];
            sum_bkg2 += counts[i]*counts[i];
            nbkg++;
        }

        double old_mean = mean_bkg;
        mean_bkg = sum_bkg / nbkg;
        var_bkg = (sum_bkg2 - nbkg*mean_bkg*mean_bkg) / (nbkg-1);
        sigma_bkg = std::sqrt(var_bkg);

        if (std::fabs((old_mean-mean_bkg)/mean_bkg) < 1e-9) {
            break;
        }
    }
    // note 1: assuming Poisson
    // note 2: the variance is the variance of the _estimated_ mean
    _meanBackground = Intensity(mean_bkg, mean_bkg / nbkg);

    return true;
}

} // end namespace nsx
