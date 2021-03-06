// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/InstrumentState.cpp
//! @brief     Implements module/class/test InstrumentState
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <algorithm>

#include <Eigen/Dense>

#include "Component.h"
#include "Detector.h"
#include "DetectorEvent.h"
#include "Diffractometer.h"
#include "FitParameters.h"
#include "Gonio.h"
#include "InstrumentState.h"
#include "Logger.h"
#include "MatrixOperations.h"
#include "Minimizer.h"
#include "Sample.h"

namespace nsx {

InstrumentState::InstrumentState(Diffractometer *diffractometer)
: _diffractometer(diffractometer)
{
    detectorOrientation.setIdentity();

    sampleOrientation = Eigen::Quaterniond(1, 0, 0, 0);

    sampleOrientationOffset = Eigen::Quaterniond(1, 0, 0, 0);

    samplePosition.setZero();

    detectorPositionOffset.setZero();

    ni = {0.0, 1.0, 0.0};

    wavelength = 1.0;

    refined=false;
}

ReciprocalVector InstrumentState::kfLab(const DirectVector& detector_position) const
{
    Eigen::Vector3d k = detectorOrientation*(detector_position.vector() - samplePosition);
    k.normalize();
    k /= wavelength;
    return ReciprocalVector(k);
}

ReciprocalVector InstrumentState::sampleQ(const DirectVector& detector_position) const
{
    Eigen::RowVector3d ki = ni / ni.norm() / wavelength;
    auto qLab = kfLab(detector_position).rowVector() - ki;
    return ReciprocalVector(qLab*sampleOrientationMatrix());
}

double InstrumentState::gamma(const DirectVector& detector_position) const
{
    Eigen::RowVector3d kf = kfLab(detector_position).rowVector();
    double gamma = std::atan2(kf[0], kf[1]);
    return gamma;
}

double InstrumentState::nu(const DirectVector& detector_position) const
{
    Eigen::RowVector3d kf = kfLab(detector_position).rowVector();
    double nu = std::asin(kf[2] / kf.norm());
    return nu;
}

double InstrumentState::twoTheta(const DirectVector& detector_position) const
{
    auto kf = kfLab(detector_position).rowVector();  
    double proj = kf.dot(ni);
    return acos(proj/kf.norm()/ni.norm());
}

ReciprocalVector InstrumentState::ki() const
{
    return ReciprocalVector(ni/ni.norm()/wavelength);
}

Eigen::Matrix3d InstrumentState::sampleOrientationMatrix() const
{
    return (sampleOrientationOffset*sampleOrientation).normalized().toRotationMatrix();
}


Eigen::Matrix3d InstrumentState::jacobianK(double px, double py) const
{
    const auto* detector = _diffractometer->detector();

    // Jacobian from (px, py, frame) to lab coordinates on detector
    Eigen::Matrix3d dpdx = detector->jacobian(px, py);

    const double nki = ki().rowVector().norm();

    // postion in lab space on the detector
    Eigen::Vector3d p = detector->pixelPosition(px, py).vector();

    // Jacobian of position -> kf
    Eigen::Vector3d dp = p - samplePosition;
    double r = dp.norm();

    Eigen::RowVector3d drdx = 1/r * dp.transpose() * dpdx;

    // Jacobian of (px, py) -> kf
    Eigen::Matrix3d dkdx = nki * detectorOrientation * (dpdx / r - dp * drdx / r / r);

    return dkdx;   
}

const Diffractometer* InstrumentState::diffractometer() const
{
    return _diffractometer;
}

Diffractometer* InstrumentState::diffractometer()
{
    return _diffractometer;
}

} // end namespace nsx
