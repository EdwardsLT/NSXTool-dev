// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/crystal/Peak.cpp
//! @brief     Implements module/class/test Peak
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "DataSet.h"
#include "Detector.h"
#include "Diffractometer.h"
#include "GeometryTypes.h"
#include "IDataReader.h"
#include "InstrumentState.h"
#include "IPeakIntegrator.h"
#include "MillerIndex.h"
#include "Peak.h"
#include "ReciprocalVector.h"
#include "Sample.h"
#include "Source.h"
#include "UnitCell.h"
#include "Units.h"

namespace nsx {

Peak::Peak(sptrDataSet data):
    _shape(),
    _unitCell(nullptr),
    _scale(1.0),
    _status(Status::Selected),
    _predicted(true),
    _transmission(1.0),
    _data(data),
    _rockingCurve(),
    _peakEnd(4.0),
    _bkgBegin(5.0),
    _bkgEnd(6.0)
{
  
}

Peak::Peak(sptrDataSet data, const Ellipsoid &shape):
    Peak(data)
{
    setShape(shape);  
}

void Peak::setShape(const Ellipsoid& shape)
{
    // shape should be consistent with data
    if (_data) {
        Eigen::Vector3d c = shape.center();
        if (c[2] < 0.0 || c[2] > _data->nFrames()-1
          || c[0] < 0.0 || c[0] >_data->nCols()-1 
          || c[1] < 0.0 || c[1] > _data->nRows()-1) {
            throw std::runtime_error("Peak::setShape(): peak center out of bounds");
        }
    }
    _shape = shape;
}

const Ellipsoid& Peak::shape() const
{
    return _shape;
}

const std::vector<Intensity>& Peak::rockingCurve() const
{
    return _rockingCurve;
}

void Peak::setUnitCell(sptrUnitCell uc)
{
    _unitCell = uc;
}

sptrUnitCell Peak::unitCell() const
{
    return _unitCell;
}

Intensity Peak::rawIntensity() const
{
    return _rawIntensity;
}

Intensity Peak::correctedIntensity() const
{
    auto c = _shape.center();
    auto state = _data->interpolatedState(c[2]);
    const double lorentz = state.lorentzFactor(c[0], c[1]);
    const double factor = _scale / lorentz / _transmission;
    return rawIntensity() * factor / state.stepSize;
}

double Peak::transmission() const
{
    return _transmission;
}

double Peak::scale() const
{
    return _scale;
}

void Peak::setScale(double factor)
{
    _scale = factor;
}

void Peak::setTransmission(double transmission)
{
    _transmission = transmission;
}

bool Peak::enabled() const
{
    return (!masked() && _status == Status::Selected);
}

Peak::Status Peak::status() const
{
    return _status;
}

void Peak::setStatus(Peak::Status status)
{
    _status = status;
}

bool Peak::selected() const
{
    return _status == Status::Selected;
}

bool Peak::masked() const
{
    bool masked(false);
    for (auto&& m : _data->masks()) {
        // If the background of the peak intercept the mask, unselected the peak
        if (m->collide(shape())) {
            masked = true;
            break;
        }
    }

    return masked;
}

void Peak::setPredicted(bool predicted)
{
    _predicted = predicted;
}

bool Peak::predicted() const
{
    return _predicted;
}

void Peak::updateIntegration(const IPeakIntegrator& integrator, double peakEnd, double bkgBegin, double bkgEnd)
{
    _rockingCurve = integrator.rockingCurve();
    // testing
    //_meanBackground = integrator.meanBackground();
    //_rawIntensity = integrator.peakIntensity();
    _meanBackground = integrator.meanBackground();
    _rawIntensity = integrator.integratedIntensity();
    // testing!!
    //_shape = integrator.fitShape();
    _peakEnd = peakEnd;
    _bkgBegin = bkgBegin;
    _bkgEnd = bkgEnd;
}

void Peak::setRawIntensity(const Intensity& i)
{  
    // note: the scaling factor is taken to be consistent with Peak::getRawIntensity()
    _rawIntensity = i; // / data()->getSampleStepSize();
}

ReciprocalVector Peak::q() const
{
    auto pixel_coords = _shape.center();
    auto state = _data->interpolatedState(pixel_coords[2]);
    const auto* detector = _data->reader()->diffractometer()->detector();
    auto detector_position = DirectVector(detector->pixelPosition(pixel_coords[0], pixel_coords[1]));
    return state.sampleQ(detector_position);
}

double Peak::d() const
{
    return 1.0/q().rowVector().norm();
}

//! This method computes an ellipsoid in q-space which is approximately the transformation from
//! detector space to q-space of its shape ellipsoid (which is computed during blob search).
//!
//! Suppose that the detector-space ellipsoid is given by the equation (x-x0).dot(A*(x-x0)) <= 1.
//! Then if q = q0 + J(x-x0), then the corresponding ellipsoid.
//!
//! This method can throw if there is no valid q-shape corresponding to the detector space shape.
Ellipsoid Peak::qShape() const
{
    if (!_data) {
        throw std::runtime_error("Attempted to compute q-shape of peak not attached to data");
    }

    Eigen::Vector3d p = _shape.center();
    auto state = _data->interpolatedState(p[2]);    
    Eigen::Vector3d q0 = q().rowVector();    

    // Jacobian of map from detector coords to sample q space
    Eigen::Matrix3d J = state.jacobianQ(p[0], p[1]);
    const Eigen::Matrix3d JI = J.inverse();

    // inverse covariance matrix in sample q space
    const Eigen::Matrix3d q_inv_cov = JI.transpose() * _shape.metric() * JI;
    return Ellipsoid(q0, q_inv_cov);
}


ReciprocalVector Peak::qPredicted() const
{
    if (!_unitCell) {
        return {};
    }
    auto index = MillerIndex(q(), *_unitCell);
    return ReciprocalVector(_unitCell->fromIndex(index.rowVector().cast<double>()));
}

DetectorEvent Peak::predictCenter(double frame) const
{
    const DetectorEvent no_event = {0, 0, -1, -1};

    if (!_unitCell) {
        return no_event;
    }

    auto index = MillerIndex(q(), *_unitCell);
    auto state = _data->interpolatedState(frame);
    Eigen::RowVector3d q_hkl = _unitCell->fromIndex(index.rowVector().cast<double>());
    Eigen::RowVector3d ki = state.ki().rowVector();
    Eigen::RowVector3d kf = q_hkl*state.sampleOrientationMatrix().transpose() + ki;

    const double alpha = ki.norm() / kf.norm();
    

    Eigen::RowVector3d kf1 = alpha*kf;
    Eigen::RowVector3d kf2 = -alpha*kf;

    Eigen::RowVector3d pred_kf = (kf1-kf).norm() < (kf2-kf).norm() ? kf1 : kf2;

    return _data->reader()->diffractometer()->detector()->constructEvent(DirectVector(state.samplePosition), ReciprocalVector(pred_kf*state.detectorOrientation));
}

    
Intensity Peak::meanBackground() const {
    return _meanBackground;
}

double Peak::peakEnd() const {
    return _peakEnd;
}

double Peak::bkgBegin() const
{
    return _bkgBegin;
}

double Peak::bkgEnd() const
{
    return _bkgEnd;
}

} // end namespace nsx
