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

#include "Component.h"
#include "InterpolatedState.h"
#include "MatrixOperations.h"

namespace nsx {

InterpolatedState::InterpolatedState(const InstrumentState& s1, const InstrumentState& s2, double t): 
    InstrumentState(),
    axis(),
    transformation(),
    stepSize()
{
    const double s = 1-t;

    detectorOrientation = interpolateRotation(s1.detectorOrientation, s2.detectorOrientation, t);
    detectorOffset = s*s1.detectorOffset + t*s2.detectorOffset;

    qSampleOrientation = s1.qSampleOrientation.normalized().slerp(t, s2.qSampleOrientation.normalized());
    samplePosition = s*s1.samplePosition + t*s2.samplePosition;

    ni = s*(s1.ni / s1.ni.norm()) + t*(s2.ni / s2.ni.norm());
    wavelength = s*s1.wavelength + t*s2.wavelength;

    Eigen::Quaterniond q = s2.qSampleOrientation * s1.qSampleOrientation.inverse();
    axis = q.vec().normalized();
    q.normalize();
    const double cos_theta2 = q.w();
    const double sin_theta2 = q.vec().norm();
    stepSize = 2.0*std::atan2(sin_theta2, cos_theta2);
}


} // end namespace nsx
