/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2017- Laurent Chapon, Eric Pelligrini, Jonathan Fisher

 chapon[at]ill.fr
 pellegrini[at]ill.fr
 j.fisher[at]fz-juelich.de

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#pragma once

#include "ComponentState.h"
#include "DirectVector.h"
#include "ReciprocalVector.h"

#include <Eigen/Core>

namespace nsx {

struct InstrumentState {
    InstrumentState();

    Eigen::Matrix3d detectorOrientation;

    // compute the sample orientation from fixed orientation and offset
    Eigen::Matrix3d sampleOrientation() const;

    // fixed orientation (e.g. read from data)
    //Eigen::Matrix3d fixedSampleOrientation;
    // offset to orientation
    //Eigen::Vector3d sampleOrientationOffset;
    Eigen::Quaterniond qSampleOrientation;

    Eigen::Vector3d samplePosition;
    Eigen::Vector3d detectorOffset;

    Eigen::RowVector3d ni;
    double wavelength;

    #ifndef SWIG
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    #endif

    InstrumentState interpolate(const InstrumentState& other, double t) const;

    //! Takes a direct vector in detector coordinates and computes kf in lab coordinates
    ReciprocalVector kfLab(const DirectVector& detector_position) const;

    //! Return source ki
    ReciprocalVector ki() const;

    //! Takes direct vector in detector coordinates and computes q in sample coordinates
    ReciprocalVector sampleQ(const DirectVector& detector_position) const;

    double gamma(const DirectVector& detector_position) const;

    double nu(const DirectVector& detector_position) const;

    double lorentzFactor(const DirectVector& detector_position) const;

    double twoTheta(const DirectVector& detector_position) const;

    //! Return the axis of the rotation transforming this state into next state.
    Eigen::Vector3d rotationAxis(const InstrumentState& next) const;
    //! Return the step size (in radians) between this state and next state.
    double stepSize(const InstrumentState& next) const;
};

} // end namespace nsx
