// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/auto_indexing/FFTIndexing.h
//! @brief     Implements module/class/test FFTIndexing
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <functional>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include "GeometryTypes.h"
#include "Units.h"

namespace nsx {

//! \class FFTIndexing
//! \brief Class used for Fast-Fourier transform autoindexing.
class FFTIndexing {
public:
    //! Type to store vector together with quality.
    using tVector = std::pair<Eigen::RowVector3d, double>;
    //! Constructor. Note that the success of FFT indexing is very sensitive to choosing reasonable
    //! values of nSubdiva and amax.
    FFTIndexing(int nSubdiv=25,double amax=50.0);
    //! Method to search uniformly on the unit sphere to identify candidate lattice directions.
    //! It is crucial to choose reasonable values of n_vertices and nsolutions.
    std::vector<tVector> findOnSphere(const std::vector<ReciprocalVector>& qvects, unsigned int n_vertices, unsigned int nsolutions) const;
    virtual ~FFTIndexing() = default;

private:
    int _nSubdiv;
    double _amax;
};

} // end namespace nsx
