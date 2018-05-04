
#include "DataSet.h"
#include "Detector.h"
#include "Diffractometer.h"
#include "Ellipsoid.h"
#include "Minimizer.h"
#include "Peak3D.h"
#include "ShapeLibrary.h"


#include <Eigen/Core>

namespace nsx {

static Eigen::Matrix3d from_cholesky(const std::array<double, 6>& components)
{
    Eigen::Matrix3d L;
    L.setZero();
    L(0,0) = components[0];
    L(1,1) = components[1];
    L(2,2) = components[2];
    L(1,0) = components[3];
    L(2,0) = components[4];
    L(2,1) = components[5];

    return L*L.transpose();
}

struct FitData {
    Eigen::Matrix3d Rs, Rd, Jk, Jp, Jd;
    Eigen::Vector3d kf, ki, q;

    FitData(sptrPeak3D peak)
    {
        auto detector = peak->data()->diffractometer()->getDetector();
        Eigen::Vector3d center = peak->getShape().center();
        auto state = peak->data()->interpolatedState(center[2]);

        Rs = state.sampleOrientationMatrix().transpose();
        Rd = state.detectorOrientation;

        auto p = detector->pixelPosition(center[0], center[1]);
        Eigen::Vector3d p0 = state.samplePosition;
        Eigen::Vector3d dp = p.vector()-p0;

        kf = state.kfLab(p).rowVector();
        ki = state.ki().rowVector();

        Jk = kf * ki.transpose() / ki.squaredNorm() - Eigen::Matrix3d::Identity();
        double r = dp.norm();

        Jp = Rd*(-1/r * Eigen::Matrix3d::Identity() + 1/r/r/r * dp * dp.transpose());
        Jp *= ki.norm();

        DetectorEvent event(center);
        Jd = state.jacobianQ(event._px, event._py);

        q = kf-ki;
    }
};


ShapeLibrary::ShapeLibrary(): 
    _profiles(),
    _choleskyD(),
    _choleskyM(),
    _choleskyS()
{
    _choleskyD.fill(1e-6);
    _choleskyM.fill(1e-6);
    _choleskyS.fill(1e-6);
}

ShapeLibrary::~ShapeLibrary()
{

}

static void covariance_helper(Eigen::Matrix3d& result, const FitData& f, const Eigen::Matrix3d& sigmaD, const Eigen::Matrix3d& sigmaM, const Eigen::Matrix3d& sigmaS)
{
    static constexpr double deg2 = (M_PI/180)*(M_PI/180);
    Eigen::Matrix3d E;
    E.setIdentity();

    Eigen::Matrix3d cov;
    cov.setZero();

    Eigen::Matrix3d Jd = f.Jd.inverse();
    Eigen::Matrix3d Jk = f.Rs * f.Jk;
    Eigen::Matrix3d Jp = f.Rs * f.Jp;
    Eigen::Vector3d qs = f.Rs*f.q;

    Eigen::Matrix3d P = f.q.squaredNorm() * Eigen::Matrix3d::Identity() - qs*qs.transpose();

    // mosaicity
    cov += P * sigmaM * P.transpose();
    // beam divergence
    cov += f.ki.squaredNorm() * Jk * sigmaD * Jk.transpose();
    // shape
    cov += Jp * sigmaS * Jp.transpose();

    result = Jd * cov * Jd.transpose();
}

bool ShapeLibrary::addPeak(sptrPeak3D peak, FitProfile&& profile, IntegratedProfile&& integrated_profile)
{
    Eigen::Matrix3d A = peak->getShape().inverseMetric();
    Eigen::Matrix3d cov = 0.5 * (A + A.transpose());
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> solver(cov);
    Eigen::VectorXd w = solver.eigenvalues();

    // peak has one axis too small. Negated expression to handle nans
    if (!(w.minCoeff() > 1e-2)) {
        return false;
    }
    _profiles[peak].first = std::move(profile);
    _profiles[peak].second = std::move(integrated_profile);
    return true;
}

void ShapeLibrary::updateFit(int num_iterations)
{
    // todo: reenable this when done testing!
    return;


    std::vector<std::pair<Eigen::Matrix3d, FitData>> fit_data;
    std::vector<std::pair<int, int>> fit_constraints;
    fit_data.reserve(_profiles.size());

    for (const auto& pair: _profiles) {
        auto peak = pair.first;
        Eigen::Matrix3d cov = peak->getShape().inverseMetric();
        FitData data(peak);
        fit_data.push_back({0.5*(cov+cov.transpose()), data});
    }

    nsx::FitParameters params;

    for (auto i = 0; i < 6; ++i) {
        params.addParameter(&_choleskyD[i]);
        params.addParameter(&_choleskyM[i]);
        params.addParameter(&_choleskyS[i]);
    }

    auto residual = [&](Eigen::VectorXd& r) -> int {
        int k = 0;
        Eigen::Matrix3d pred_cov;
        Eigen::Matrix3d sigmaM = from_cholesky(_choleskyM);
        Eigen::Matrix3d sigmaD = from_cholesky(_choleskyD);
        Eigen::Matrix3d sigmaS = from_cholesky(_choleskyS);
        
        for (const auto& tup: fit_data) {
            const auto& cov = tup.first;
            const auto& data = tup.second;

            covariance_helper(pred_cov, data, sigmaD, sigmaM, sigmaS);
            Eigen::Matrix3d delta = cov - pred_cov;

            for (int i = 0; i < 3; ++i) {
                for (int j = i; j < 3; ++j) {
                    r(k++) = delta(i,j);
                }
            }
        }

        return 0;
    };

    nsx::Minimizer min;
    min.initialize(params, 6*fit_data.size());
    min.set_f(residual);
    min.fit(num_iterations);
}

Eigen::Matrix3d ShapeLibrary::predictCovariance(sptrPeak3D peak) const
{
    FitData f(peak);
    return predictCovariance(f);
}

Eigen::Matrix3d ShapeLibrary::predictCovariance(const FitData& f) const
{
    Eigen::Matrix3d result;
    Eigen::Matrix3d sigmaM = from_cholesky(_choleskyM);
    Eigen::Matrix3d sigmaD = from_cholesky(_choleskyD);
    Eigen::Matrix3d sigmaS = from_cholesky(_choleskyS);
    covariance_helper(result, f, sigmaD, sigmaM, sigmaS);
    return result;
}

double ShapeLibrary::meanPearson() const
{
    double sum_pearson = 0;

    for (const auto& pair: _profiles) {
        auto peak = pair.first;
        Eigen::Matrix3d obs_cov = peak->getShape().inverseMetric();
        Eigen::Matrix3d pred_cov = predictCovariance(peak);
        sum_pearson += (obs_cov.transpose()*pred_cov).trace() / obs_cov.norm() / pred_cov.norm();
    }
    return sum_pearson / _profiles.size();
}

FitProfile ShapeLibrary::meanProfile(const DetectorEvent& ev, double radius, double nframes) const
{
    FitProfile mean;
    PeakList neighbors = findNeighbors(ev, radius, nframes);

    for (auto peak: neighbors) {
        //double weight = (1-r/radius) * (1-df/nframes);
        // mean.addProfile(profile, weight*weight);
        mean.addProfile(_profiles.find(peak)->second.first, 1.0);
    }

    mean.normalize();
    return mean;
}

std::vector<Intensity> ShapeLibrary::meanIntegratedProfile(const DetectorEvent& ev, double radius, double nframes) const
{
    PeakList neighbors = findNeighbors(ev, radius, nframes);
    std::vector<Intensity> mean_profile;
    const double inv_N = 1.0 / neighbors.size();

    for (auto peak: neighbors) {
        const auto& profile = _profiles.find(peak)->second.second.profile();

        if (mean_profile.size() == 0) {
            mean_profile.resize(profile.size());
        }

        for (size_t i = 0; i < mean_profile.size(); ++i) {
            mean_profile[i] += profile[i] * inv_N;
        }
    }
    return mean_profile;
}

PeakList ShapeLibrary::findNeighbors(const DetectorEvent& ev, double radius, double nframes) const
{
    PeakList neighbors;
    Eigen::Vector3d center(ev._px, ev._py, ev._frame);
    
    for (const auto& pair: _profiles) {
        auto peak = pair.first;    
        Eigen::Vector3d dc = center - peak->getShape().center();    
        // too far away on detector
        if (dc(0)*dc(0) + dc(1)*dc(1) > radius*radius) {
            continue;
        }
        // too far away in frame number
        if (std::fabs(dc(2)) > nframes) {
            continue;
        }
        neighbors.push_back(peak);
    }
    if (neighbors.size() == 0) {
        throw std::runtime_error("Error, no neighboring profiles found.");
    }
    return neighbors;
}

Eigen::Matrix3d ShapeLibrary::meanCovariance(sptrPeak3D reference_peak, double radius, double nframes, size_t min_neighbors) const
{
    Eigen::Matrix3d cov;
    cov.setZero();
    PeakList neighbors = findNeighbors(DetectorEvent(reference_peak->getShape().center()), radius, nframes);

    if (neighbors.size() < min_neighbors) {
        throw std::runtime_error("ShapeLibrary::meanCovariance(): peak has too few neighbors");
    }

    // testing (try using detector space??)
    #if 1
    for (auto peak: neighbors) {
        cov += peak->getShape().inverseMetric();
    }
    cov /= neighbors.size();
    return cov;
    #endif

    PeakCoordinateSystem reference_coord(reference_peak);

    for (auto peak: neighbors) {
        PeakCoordinateSystem coord(peak);
        Eigen::Matrix3d J = coord.jacobian();
        cov += J * peak->getShape().inverseMetric() * J.transpose();
    }

    if (neighbors.size() == 0) {
        throw std::runtime_error("Error, no neighboring profiles found.");
    }

    cov /= neighbors.size();
    Eigen::Matrix3d JI = reference_coord.jacobian().inverse();
    return JI * cov * JI.transpose();
}

} // end namespace nsx