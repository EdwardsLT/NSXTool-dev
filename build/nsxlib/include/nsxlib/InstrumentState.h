// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/InstrumentState.h
//! @brief     Implements module/class/test InstrumentState
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <vector>

#include <Eigen/Core>

#include "DirectVector.h"
#include "InstrumentTypes.h"
#include "ReciprocalVector.h"

namespace nsx {

class Diffractometer;

//! Class storing the state of the experiment at a given moment of time.
//! State refers to any parameters which might change during the experiment:
//! sample orientation, sample position, etc. States are initially loaded
//! as metadata but can also be refined as part of the data treatment.
class InstrumentState {
public:

    //! default value needed for SWIG (note: nullptr does _not_ work)
    InstrumentState(Diffractometer *diffractometer=nullptr);

    //! Destructor
    virtual ~InstrumentState() {}

    //! Takes a direct vector in detector coordinates and computes kf in lab coordinates
    ReciprocalVector kfLab(const DirectVector& detector_position) const;

    //! Return source ki
    ReciprocalVector ki() const;

    //! Takes direct vector in detector coordinates and computes q in sample coordinates
    ReciprocalVector sampleQ(const DirectVector& detector_position) const;

    //! Return the gamma angle associated to the given lab space position
    double gamma(const DirectVector& detector_position) const;

    //! Return the nu angle associated to the given lab space position
    double nu(const DirectVector& detector_position) const;

    //! Return the 2*theta angle associated to the given lab space position
    double twoTheta(const DirectVector& detector_position) const;

    //! Compute the jacobian of the transformation (x,y) -> k_lab
    Eigen::Matrix3d jacobianK(double px, double py) const;

    //! Return a pointer to the diffractometer of the state
    Diffractometer* diffractometer();

    //! Return a const pointer to the diffractometer of the state
    const Diffractometer* diffractometer() const;

public:

    //! Detector orientation as read from metadata
    Eigen::Matrix3d detectorOrientation;

    //! compute the sample orientation from fixed orientation and offset
    Eigen::Matrix3d sampleOrientationMatrix() const;

    //! Sample orientation as read from metadata
    Eigen::Quaterniond sampleOrientation;

    //! Offset to sample orientation, used for parameter refinement
    Eigen::Quaterniond sampleOrientationOffset;

    //! Sample position
    Eigen::Vector3d samplePosition;

    //! Detector offset.
    Eigen::Vector3d detectorPositionOffset;

    //! Incoming beam direction.
    Eigen::RowVector3d ni;

    //! Incoming beam wavelength.
    double wavelength;

    //! True if this state has been refined
    bool refined;

    #ifndef SWIG
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    #endif

protected:
    //! Pointer to the diffractometer whose state this object stores.
    //! The actual resource is not owned by this object which just borrows it.
    Diffractometer *_diffractometer;
};

} // end namespace nsx
