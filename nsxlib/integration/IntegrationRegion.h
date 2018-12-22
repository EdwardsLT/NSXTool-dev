// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/IntegrationRegion.h
//! @brief     Implements module/class/test IntegrationRegion
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <Eigen/Core>

#include "ConvexHull.h"
#include "Ellipsoid.h"
#include "GeometryTypes.h"
#include "PeakData.h"

namespace nsx {

//! \brief Class used to construct a peak integration region.
class IntegrationRegion {
public:
    //! Classify the type of detector event with respect to the current integration region
    enum class EventType: int {BACKGROUND = 1, PEAK = 2, FORBIDDEN = -1, EXCLUDED = 0};

    IntegrationRegion();

    IntegrationRegion(IntegrationRegion&& other) = default;

    IntegrationRegion(sptrPeak peak, double peak_end, double bkg_begin, double bkg_end);

    //! Update the integration mask of the detector (peak, background, forbiddgen zones)
    void updateMask(Eigen::MatrixXi& mask, double frame) const;
    //! Return the bounding box of the region
    const AABB aabb() const;
    //! Return the bounding box of the peak region
    const AABB peakBB() const;
    //! Classify a detector event (peak, background, forbidden, etc.)
    EventType classify(const DetectorEvent& ev) const;
    //! Update the region with the next frame
    bool advanceFrame(const Eigen::MatrixXd& image, const Eigen::MatrixXi& mask, double frame);
    //! Reset the integration region (i.e. free memory)
    void reset();
    //! Return the underlying data stored by the region
    const PeakData& data() const;
    //! Return the data stored by the region
    PeakData& data();
    //! Return the peak shape used by the region
    const Ellipsoid& shape() const;
    //! Return the convex hull of the region (e.g. BrillouinZone)
    const ConvexHull& hull() const;
    //! Return the scaling factor used to determine the peak boundary
    double peakEnd() const { return _peakEnd; }

private:
    Ellipsoid _shape;
    double _peakEnd;
    double _bkgBegin;
    double _bkgEnd;
    PeakData _data;
    ConvexHull _hull;
};

} // end namespace nsx
