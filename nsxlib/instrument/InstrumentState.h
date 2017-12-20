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

#include <Eigen/Core>

namespace nsx {

struct InstrumentState {
    ComponentState detector;
    ComponentState source;
    ComponentState sample;

    Eigen::Matrix3d detectorOrientation;
    Eigen::Matrix3d sampleOrientation;

    Eigen::Vector3d samplePosition;
    Eigen::Vector3d detectorOffset;

    Eigen::RowVector3d ni;
    double wavelength;

    #ifndef SWIG
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    #endif

    InstrumentState interpolate(const InstrumentState& other, double t) const;
};

} // end namespace nsx
