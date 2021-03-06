// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/InterpolatedState.cpp
//! @brief     Implements module/class/test InterpolatedState
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "Component.h"
#include "Detector.h"
#include "Diffractometer.h"
#include "InterpolatedState.h"
#include "Logger.h"
#include "MatrixOperations.h"

namespace nsx {

InterpolatedState::InterpolatedState(Diffractometer *diffractometer): InstrumentState(diffractometer)
{
}

InterpolatedState::InterpolatedState(const InstrumentState& s1, const InstrumentState& s2, double t)
: InstrumentState(const_cast<Diffractometer*>(s1.diffractometer())),
  axis(),
  stepSize()
{
    if (s1.diffractometer() != s2.diffractometer()) {
        throw std::runtime_error("Cannot interpolate states between different diffractometers");
    }

    const double s = 1-t;

    detectorOrientation = interpolateRotation(s1.detectorOrientation, s2.detectorOrientation, t);
    detectorPositionOffset = s*s1.detectorPositionOffset + t*s2.detectorPositionOffset;

    Eigen::Quaterniond q1 = s1.sampleOrientationOffset*s1.sampleOrientation;
    Eigen::Quaterniond q2 = s2.sampleOrientationOffset*s2.sampleOrientation;

    q1.normalize();
    q2.normalize();

    sampleOrientation = q1.slerp(t, q2);
    sampleOrientationOffset = Eigen::Quaterniond(1, 0, 0, 0);

    samplePosition = s*s1.samplePosition + t*s2.samplePosition;

    ni = s*(s1.ni / s1.ni.norm()) + t*(s2.ni / s2.ni.norm());
    wavelength = s*s1.wavelength + t*s2.wavelength;

    //Eigen::Quaterniond q = q2 * q1.inverse();
    Eigen::Quaterniond q = q1.inverse() * q2;
    axis = q.vec().normalized();
    q.normalize();
    const double cos_theta2 = q.w();
    const double sin_theta2 = q.vec().norm();
    stepSize = 2.0*std::atan2(sin_theta2, cos_theta2);
}

Eigen::Matrix3d InterpolatedState::jacobianQ(double px, double py) const
{
    auto position = _diffractometer->detector()->pixelPosition(px, py);
    Eigen::Vector3d q0 = sampleQ(position).rowVector();
    // Jacobian of map from detector coords to sample q space
    Eigen::Matrix3d J = sampleOrientationMatrix().transpose() * jacobianK(px, py); 
    // take into account the rotation
    // negative sign is due to treating q as a column vector instead of a row vector
    J.col(2) = -stepSize * axis.cross(q0);
    return J;
}

double InterpolatedState::lorentzFactor(double px, double py) const
{
    auto position = _diffractometer->detector()->pixelPosition(px, py);
    Eigen::Vector3d q0 = sampleQ(position).rowVector();
    Eigen::Vector3d kf = sampleOrientationMatrix().transpose() * kfLab(position).rowVector().transpose();
    const double lorentz = kf.norm() / std::fabs(kf.dot(axis.cross(q0)));
    return lorentz;
}

} // end namespace nsx
