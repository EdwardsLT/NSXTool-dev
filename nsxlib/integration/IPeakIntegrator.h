// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/IPeakIntegrator.h
//! @brief     Implements module/class/test IPeakIntegrator
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <map>
#include <vector>

#include <Eigen/Dense>

#include "Blob3D.h"
#include "BrillouinZone.h"
#include "GeometryTypes.h"
#include "IntegrationRegion.h"
#include "Intensity.h"
#include "ProgressHandler.h"
#include "UtilsTypes.h"

namespace nsx {

class DataSet;

//! \class IPeakIntegrator
//! \brief This is a helper class to handle per-frame integration of a peak.
class IPeakIntegrator {
public:
    //! Default constructor
    IPeakIntegrator();
    //! Destructor
    virtual ~IPeakIntegrator();
    //! Compute the integrated intensity of the peak given the integration region.
    virtual bool compute(sptrPeak peak, const IntegrationRegion& region) = 0;
    //! Integrate all peaks in the list which are contained in the specified data set.
    /** \param peak_end Peak boundary (in sigma)
     *  \param bkg_begin Background beginning (in sigma)
     *  \param bkg_end Background end (in sigma)
     */
    void integrate(PeakList peaks, sptrDataSet data, double peak_end, double bkg_begin, double bkg_end);
    //! Return the mean background.
    Intensity meanBackground() const;
    //! Return the integrated intensity.
    Intensity integratedIntensity() const;
    //! Return the peak rocking curve.
    const std::vector<Intensity>& rockingCurve() const;
    //! Set the progress handler.
    void setHandler(sptrProgressHandler handler);

protected:
    //! Mean local background of peak. The uncertainty is the uncertainty of the _estimate_ of the background.
    Intensity _meanBackground;
    //! Net integrated intensity, after background correction.
    Intensity _integratedIntensity;    
    //! The rocking curve of the peak.
    std::vector<Intensity> _rockingCurve;
    //! Optional pointer to progress handler.
    sptrProgressHandler _handler;
};

} // end namespace nsx
