// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/monte-carlo/mozaictester.h
//! @brief     Implements module/class/test mozaictester
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <Eigen/Dense>

namespace nsx {

//! Class to test the Monte-Carlo peak profile calculation
struct MozaicTester
{
    MozaicTester();

    Eigen::Vector3d buildQVector(double alpha1, double ca2, double sa2, double znorm, const Eigen::Vector3d& u, const Eigen::Vector3d& v, const Eigen::Vector3d& w);
    void updateDetector(double alpha1,
                        double znorm,
                        double calpha2,
                        double salpha2,
                        double lambda,
                        const Eigen::Vector3d& u,
                        const Eigen::Vector3d& v,
                        const Eigen::Vector3d& w,
                        const Eigen::Vector3d& n,
                        double px,
                        double py,
                        double pz,
                        Eigen::MatrixXd& detector);
    Eigen::MatrixXd run(double h, double k, double l, int n);
    Eigen::MatrixXd runCenter(double h, double k, double l, int n);
    Eigen::MatrixXd runContour(double h, double k, double l);
    Eigen::MatrixXd run1(double h, double k, double l, double px=0.0, double py=0.0, double pz=0.0);
    double _l;
    double _dl;
    double _sRadius;
    double _hMono;
    double _wMono;
    double _dMono;
    double _dDet;
    double _mu;
    double _wDet;
    double _hDet;
    double _nRows;
    double _nCols;

    Eigen::Matrix3d _ub;

};

} // end namespace nsx

