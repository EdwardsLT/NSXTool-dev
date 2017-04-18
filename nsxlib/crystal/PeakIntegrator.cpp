/*
 * nsxtool : Neutron Single Crystal analysis toolkit
    ------------------------------------------------------------------------------------------
    Copyright (C)
    2017- Laurent C. Chapon, Eric C. Pellegrini Institut Laue-Langevin
          Jonathan Fisher, Forschungszentrum Juelich GmbH
    BP 156
    6, rue Jules Horowitz
    38042 Grenoble Cedex 9
    France
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

#include "PeakIntegrator.h"
#include "Intensity.h"
#include "../data/IData.h"

namespace SX {
namespace Crystal {

PeakIntegrator::PeakIntegrator(const SX::Geometry::IntegrationRegion& region, const SX::Data::DataSet& data):
    _blob(),
    _region(region),
    _lower(region.getBackground().getLower()),
    _upper(region.getBackground().getUpper()),
    _data_start(),
    _data_end(),
    _start_x(),
    _end_x(),
    _start_y(),
    _end_y(),
    _point1(),
    _dx(),
    _dy()
{
    _data_start = std::lround((std::floor(_lower[2])));
    _data_end = std::lround((std::ceil(_upper[2])));

    _start_x = std::lround((std::floor(_lower[0])));
    _end_x = std::lround((std::ceil(_upper[0])));

    _start_y = std::lround((std::floor(_lower[1])));
    _end_y = std::lround((std::ceil(_upper[1])));

    if (_start_x < 0) {
        _start_x=0;
    }
    if (_start_y < 0) {
        _start_y=0;
    }
    if (_data_start < 0) {
        _data_start=0;
    }

    if (_end_x > data.getNCols()-1) {
        _end_x = static_cast<unsigned int>(data.getNCols()-1);
    }
    if (_end_y > data.getNRows()-1) {
        _end_y =  static_cast<unsigned int>(data.getNRows()-1);
    }
    if (_data_end > data.getNFrames()-1) {
        _data_end = static_cast<unsigned int>(data.getNFrames()-1);
    }

    // Allocate all vectors
    _projection = Eigen::VectorXd::Zero(_data_end - _data_start + 1);
    _projectionPeak = Eigen::VectorXd::Zero(_data_end - _data_start + 1);
    _projectionBkg = Eigen::VectorXd::Zero(_data_end - _data_start + 1);
    _pointsPeak = Eigen::VectorXd::Zero(_data_end - _data_start + 1);
    _pointsBkg = Eigen::VectorXd::Zero(_data_end - _data_start + 1);
    _countsPeak = Eigen::VectorXd::Zero(_data_end - _data_start + 1);
    _countsBkg = Eigen::VectorXd::Zero(_data_end - _data_start + 1);

    _dx = int(_end_x - _start_x)+1;
    _dy = int(_end_y - _start_y)+1;

//    _peak_mask.resize(_dy, _dx);
//    _bkg_mask.resize(_dy, _dx);

    _fitA.setZero();
    _fitP.setZero();
    _fitB.setZero();
    _fitCC = 0.0;
    _sumX = Eigen::VectorXd::Zero(_data_end - _data_start + 1);
    _sumY = Eigen::VectorXd::Zero(_data_end - _data_start + 1);
}

void PeakIntegrator::step(const Eigen::MatrixXi& frame, size_t idx, const Eigen::MatrixXi& mask)
{
    using point_type = SX::Geometry::IntegrationRegion::point_type;

    if (idx < _data_start || idx > _data_end) {
        return;
    }

    double pointsinpeak = 0;
    double pointsinbkg = 0;
    double intensityP = 0;
    double intensityBkg = 0;


    auto _peak_data = frame.block(_start_y, _start_x, _dy,_dx).array().cast<double>();
    auto _peak_mask = Eigen::ArrayXXd(_dy, _dx);
    auto _bkg_mask = Eigen::ArrayXXd(_dy, _dx);

    _peak_mask.setZero();
    _bkg_mask.setZero();

    _projection[idx-_data_start] += _peak_data.sum();

    for (unsigned int x = _start_x; x <= _end_x; ++x) {
        for (unsigned int y = _start_y; y <= _end_y; ++y) {
            int intensity = frame(y, x);

            _point1 << x, y, idx, 1;
            const auto type = _region.classifyPoint(_point1);

            const bool inpeak = (type == point_type::REGION);
            const bool inbackground = (type == point_type::BACKGROUND) && (mask(y, x) == 0);

            if (inpeak) {
                _peak_mask(y-_start_y, x-_start_x) = 1.0;
                _sumX(idx-_data_start) += x;
                _sumY(idx-_data_start) += y;
            }
            else if (inbackground) {
                _bkg_mask(y-_start_y, x-_start_x) = 1.0;

                _fitA(0, 0) += 1;
                _fitA(0, 1) += x;
                _fitA(0, 2) += y;

                _fitA(1, 0) += x;
                _fitA(1, 1) += x*x;
                _fitA(1, 2) += x*y;

                _fitA(2, 0) += y;
                _fitA(2, 1) += x*y;
                _fitA(2, 2) += y*y;

                _fitB(0) += intensity;
                _fitB(1) += intensity*x;
                _fitB(2) += intensity*y;

                _fitCC += intensity*intensity;

                _sumX(idx-_data_start) += x;
                _sumY(idx-_data_start) += y;
            }
        }
    }

    intensityP = (_peak_data*_peak_mask).sum();
    pointsinpeak = _peak_mask.sum();

    intensityBkg = (_peak_data*_bkg_mask).sum();
    pointsinbkg = _bkg_mask.sum();

    _pointsPeak[idx-_data_start] = pointsinpeak;
    _pointsBkg[idx-_data_start] = pointsinbkg;

    _countsPeak[idx-_data_start] = intensityP;
    _countsBkg[idx-_data_start] = intensityBkg;

    const double avgBkg = intensityBkg / pointsinbkg;

    // commented out: no more per-frame background
//    if (pointsinpeak > 0) {
//        _projectionPeak[idx-_data_start] = intensityP-intensityBkg*pointsinpeak/pointsinbkg;
//    }

    // update blob
    for (unsigned int x = _start_x; x <= _end_x; ++x) {
        for (unsigned int y = _start_y; y <= _end_y; ++y) {
            int intensity = frame(y, x);

            _point1 << x, y, idx, 1;
            const auto type = _region.classifyPoint(_point1);

            const bool inpeak = (type == point_type::REGION);
            const bool inbackground = (type == point_type::BACKGROUND) && (mask(y, x) == 0);

            if (inpeak && intensity > 1.20*avgBkg) {
                _blob.addPoint(x, y, idx, intensity-avgBkg);
            }
        }
    }
}

void PeakIntegrator::end()
{
    // get average background
    const double avgBkg = getMeanBackground();

    // subtract background from peak
    _projectionPeak = _countsPeak - avgBkg*_pointsPeak;

    // get the fitted background
    _fitP = _fitA.inverse()*_fitB;
    // get the norm-sqared residual
    volatile double avg_residual = (_fitCC - _fitP.dot(_fitB)) / _pointsBkg.sum();


    Eigen::ArrayXd bkg_1 = avgBkg*(_pointsPeak+_pointsBkg);
    Eigen::ArrayXd bkg_2 = _fitP(0)*(_pointsPeak+_pointsBkg) + _fitP(1)*_sumX + _fitP(2)*_sumY;

    Eigen::ArrayXd projectionPeak2 = _countsPeak.array() + _countsBkg.array() - bkg_2;

    // debugging
    std::cout << "bkg_1 " << bkg_1.sum() << std::endl;
    std::cout << "bkg_2 " << bkg_2.sum() << std::endl;
    std::cout << "I_1   " << _projectionPeak.sum() << std::endl;
    std::cout << "I_2   " << projectionPeak2.sum() << std::endl;

    double b1 = bkg_1.sum();
    double b2 = bkg_2.sum();



//    // Quick fix determine the limits of the peak range
//    int datastart = 0;
//    int dataend = 0;
//    bool startfound = false;

//    for (int i = 0; i < _projectionPeak.size(); ++i) {
//        if (!startfound && std::fabs(_projectionPeak[i]) > 1e-6) {
//            datastart = i;
//            startfound = true;
//        }
//        if (startfound) {
//            if (std::fabs(_projectionPeak[i])<1e-6) {
//                dataend = i;
//                break;
//            }
//        }
//    }
//    //

//    if (datastart>1) {
//        datastart--;
//    }

//    // Safety check
//    if (datastart==dataend) {
//        return;
//    }

    // jmf testing: what does this accomplish?
//    Eigen::VectorXd bkg=_projection-_projectionPeak;
//    double bkg_left=bkg[datastart];
//    double bkg_right=bkg[dataend];
//    double diff;
//    for (int i=datastart;i<dataend;++i) {
//        diff=bkg[i]-(bkg_left+static_cast<double>((i-datastart))/static_cast<double>((dataend-datastart))*(bkg_right-bkg_left));
//        if (diff>0) {
//            _projectionPeak[i]+=diff;
//        }
//    }

    // note: this "background" simply refers to anything in the AABB but NOT in the peak
    _projectionBkg=_projection-_projectionPeak;
}

const Eigen::VectorXd& PeakIntegrator::getProjectionPeak() const
{
    return _projectionPeak;
}

const Eigen::VectorXd& PeakIntegrator::getProjectionBackground() const
{
    return _projectionBkg;
}

const Eigen::VectorXd& PeakIntegrator::getProjection() const
{
    return _projection;
}

double PeakIntegrator::getMeanBackground() const
{
    return _countsBkg.sum() / _pointsBkg.sum();
}

const Geometry::IntegrationRegion& PeakIntegrator::getRegion() const
{
    return _region;
}

PeakIntegrator::MaybeEllipsoid PeakIntegrator::getBlobShape(double confidence) const
{
    try {
        Eigen::Vector3d center, eigenvalues;
        Eigen::Matrix3d eigenvectors;
        _blob.toEllipsoid(confidence, center, eigenvalues, eigenvectors);
        return {Ellipsoid3D(center, eigenvalues, eigenvectors)};
    }
    catch(...) {
        // return 'nothing'
        return {};
    }
}

Intensity PeakIntegrator::getTotalIntensity() const
{
    return Intensity(_countsPeak.sum(), _countsPeak.sum());
}

Intensity PeakIntegrator::getPeakIntensity() const
{
    return getTotalIntensity() - getBackgroundIntensity();
}

Intensity PeakIntegrator::getBackgroundIntensity() const
{
    double scale = double(_pointsPeak.sum()) / double(_pointsBkg.sum());
    return Intensity(_countsBkg.sum(), _countsBkg.sum()) * scale;
}

double PeakIntegrator::pValue() const
{
    // assumption: all background pixel counts are Poisson processes with rate R
    // therefore, we can estimate the rate R as below:
    const double R = _countsBkg.sum() / _pointsBkg.sum();

    // R should always be positive!
    if (std::isnan(R) || R <= 0.0) {
        return 1.0;
    }

    // null hypothesis: the pixels inside the peak are Poisson processes with rate R
    // therefore, by central limit theorem the average value
    const double avg = _countsPeak.sum() / _pointsPeak.sum();
    // is normal with mean R and variance:
    const double var = R / _pointsPeak.sum();

    // avg should be finite and positive
    if (std::isnan(avg) || avg <= 0.0) {
        return 1.0;
    }

    // variance should be finite and positive
    if (std::isnan(var) || var <= 0.0) {
        return 1.0;
    }

    // thus we obtain the following standard normal variable
    const double z = (avg-R) / std::sqrt(var);

    // compute the p value
    const double p = 1.0 - 0.5 * (1.0 + std::erf(z / std::sqrt(2)));

    return p;
}

} // namespace Crystal
} // namespace SX
