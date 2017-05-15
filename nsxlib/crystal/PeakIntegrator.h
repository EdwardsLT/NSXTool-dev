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

#ifndef NSXTOOL_PEAKINTEGRATOR_H_
#define NSXTOOL_PEAKINTEGRATOR_H_

#include "../geometry/IntegrationRegion.h"
#include "../geometry/Blob3D.h"
#include "../geometry/Ellipsoid.h"
#include "../utils/Maybe.h"
#include "Intensity.h"
#include <Eigen/Core>

namespace nsx {

namespace Data {
class DataSet;
}

namespace Crystal {

class PeakIntegrator {
public:
    using Ellipsoid3D = nsx::Geometry::Ellipsoid<double, 3>;
    using MaybeEllipsoid = nsx::Utils::Maybe<Ellipsoid3D>;

    PeakIntegrator() = default;
    PeakIntegrator(const nsx::Geometry::IntegrationRegion& region, const nsx::Data::DataSet& data);
    ~PeakIntegrator() {}

    void step(const Eigen::MatrixXi& frame, size_t idx, const Eigen::MatrixXi& mask);
    void end();

    const Eigen::ArrayXd& getProjectionPeak() const;
    const Eigen::ArrayXd& getProjectionBackground() const;
    const Eigen::ArrayXd& getProjection() const;
    const Eigen::ArrayXd& getPeakError() const;

    double getMeanBackground() const;

    const nsx::Geometry::IntegrationRegion& getRegion() const;

    //! return blob shape (not: not scaled by a confidence parameter)
    //!
    MaybeEllipsoid getBlobShape(double confidence) const;

    Intensity getPeakIntensity() const;

    double pValue() const;

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

private:
    nsx::Geometry::Blob3D _blob;

    nsx::Geometry::IntegrationRegion _region;
    Eigen::Vector3d _lower;
    Eigen::Vector3d _upper;

    // Eigen::ArrayXXd _peak_mask, _bkg_mask, _peak_data;

    long _data_start;
    long _data_end;

    long _start_x;
    long _end_x;

    long _start_y;
    long _end_y;

    Eigen::Vector4d _point1;

    int _dx;
    int _dy;

    Eigen::ArrayXd _projection;
    Eigen::ArrayXd _projectionPeak;
    Eigen::ArrayXd _projectionBkg;
    Eigen::ArrayXd _peakError;
    Eigen::ArrayXd _pointsPeak;
    Eigen::ArrayXd _pointsBkg;
    Eigen::ArrayXd _countsPeak;
    Eigen::ArrayXd _countsBkg;

    Eigen::Matrix3d _fitA;
    Eigen::Vector3d _fitP;
    Eigen::Vector3d _fitB;
    Eigen::ArrayXd _sumX;
    Eigen::ArrayXd _sumY;
    double _fitCC;
    double _bkgStd;

    //

};

} // namespace Crystal
} // end namespace nsx

#endif // NSXTOOL_PEAKINTEGRATOR_H_
