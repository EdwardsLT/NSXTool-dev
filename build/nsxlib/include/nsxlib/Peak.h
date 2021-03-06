// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/crystal/Peak.h
//! @brief     Implements module/class/test Peak
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <map>
#include <memory>
#include <vector>

#include <Eigen/Dense>

#include "CrystalTypes.h"
#include "DataTypes.h"
#include "Ellipsoid.h"
#include "GeometryTypes.h"
#include "InstrumentTypes.h"
#include "IntegrationRegion.h"
#include "Intensity.h"
#include "IPeakIntegrator.h"

namespace nsx {

//! \class Peak
//! \brief Data type used to store integrated peaks, including their shape and location.
class Peak {

public:

    enum class Status {Selected,Unselected,OutOfBounds,NotIndexed,BadlyIntegrated,BadlyPredicted,Unknown};

    //! Create peak belonging to data without setting a position, shape, or intensity
    Peak(sptrDataSet data);
    //! Create peak belonging to data with given shape
    Peak(sptrDataSet data, const Ellipsoid& shape);
    //! Copy constructor deleted
    Peak(sptrDataSet data, const Peak& other) = delete;
    //! Assignment operator deleted
    Peak& operator=(const Peak& other) = delete;

    //! Comparison operator used to sort peaks
    friend bool operator<(const Peak& p1, const Peak& p2);

    //! Set the Peak region. Peak shaped is owned after setting
    void setShape(const Ellipsoid& peak);

    //! Get the projection of total data in the bounding box.
    const std::vector<Intensity>& rockingCurve() const;

    //! Compute the shape in q-space. May throw if there is no valid q-space ellipsoid.
    Ellipsoid qShape() const;
    //! Return the shape of the peak as an ellipsoid in detector coordinates
    const Ellipsoid& shape() const;

    //! Return the intensity, after scaling, transmission, and Lorentz factor corrections
    Intensity correctedIntensity() const;
    //! Return the raw intensity of the peak.
    Intensity rawIntensity() const;

    //! Return mean background of the peak
    Intensity meanBackground() const;

    //! Return shape scale used to define peak region
    double peakEnd() const;
    //! Return shape scale used to define beginning of background region
    double bkgBegin() const;
    //! Return shape scale used to define end of background region
    double bkgEnd() const;

    //! Return the scaling factor.
    double scale() const;
    //! Set the scaling factor.
    void setScale(double factor);

    //! Get the peak status
    Status status() const;
    //! Set the peak status
    void setStatus(Status status);

    //! Return true if the peak has a Selected status
    bool selected() const;

    //! Return the peak masking state
    bool masked() const;

    //! Return true if peak is enable (selected and not masked)
    bool enabled() const;

    //! Set the transmission factor
    void setTransmission(double transmission);
    //! Return the transmission factor
    double transmission() const;

    //! Add a unit cell to the peak, optionally make it the active cell
    void setUnitCell(sptrUnitCell uc);
    //! Return the active unit cell
    sptrUnitCell unitCell() const;

    //! Set whether the peak is observed or predicted
    void setPredicted(bool predicted);
    //! Return if the peak is predicted
    bool predicted() const;

    //! Update the integration of the peak
    void updateIntegration(const IPeakIntegrator& integrator, double peakEnd, double bkgBegin, double bkgEnd);
    //! Return the q vector of the peak, transformed into sample coordinates.
    ReciprocalVector q() const;
    //! Return the predicted q vector of the peak, based on Miller index.
    ReciprocalVector qPredicted() const;
    //! Return the data set to which this peak belongs
    sptrDataSet data() const { return _data; }
    //! Set raw intensity count (from image), with no corrections
    void setRawIntensity(const Intensity& i);
    //! Return peak center at the given frame
    DetectorEvent predictCenter(double frame) const;

    double d() const;

    #ifndef SWIG
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    #endif

private:

    //! Shape describing the Peak zone
    Ellipsoid _shape;

    //! Raw intensity (count), background corrected
    Intensity _rawIntensity;

    //! Mean background estimate
    Intensity _meanBackground;

    //! Shape scale factor for peak
    double _peakEnd;

    //! Shape scale factor for start of background
    double _bkgBegin;

    //! Shape scale factor for end of background
    double _bkgEnd;

    sptrUnitCell _unitCell;
   
    double _scale;

    Status _status;

    bool _predicted;

    double _transmission;

    sptrDataSet _data;
    //! Peak profile along frame (rotation) axis
    std::vector<Intensity> _rockingCurve;
};

} // end namespace nsx
