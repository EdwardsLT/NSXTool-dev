// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/refining/RefinementBatch.h
//! @brief     Implements module/class/test RefinementBatch
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <functional>
#include <map>
#include <vector>

#include <Eigen/SparseCore>

#include "CrystalTypes.h"
#include "FitParameters.h"
#include "InstrumentTypes.h"
#include "ReciprocalVector.h"
#include "UnitCell.h"

namespace nsx {

//! \class RefinementBatch
//! \brief Helper class to represent a batch of consecutive detector images.
class RefinementBatch {

public:
    //! Default constructor. Should not be used but needed for swig
    RefinementBatch() = default;
    //! Construct batch with initial unit cell and list of peaks.
    RefinementBatch(InstrumentStateList& states, const UnitCell& uc, const PeakList& peaksmax);
    //! Set the lattice B matrix to be refined.
    void refineUB();
    //! Set detector offsets in the given list of instrument states to be refined.
    void refineDetectorOffset();
    //! Set the sample position in the given list of instrument states to be refined.
    void refineSamplePosition();
    //! Set the sample orientation in the given list of instrument states to be refined.
    void refineSampleOrientation();
    //! Set the source ki in the given list of instrument states to be refined.
    void refineKi();
    //! Perform the refinement with the maximum number of iterations as given.
    bool refine(unsigned int max_iter = 100);
    //! Compute the residual vector for the current set of parameters.
    int residuals(Eigen::VectorXd& fvec);
    //! Return the list of peaks used for refinement.
    const PeakList& peaks() const;
    //! Return the refined unit cell.
    sptrUnitCell cell() const;
    //! Return the matrix of parameter constraints.
    Eigen::MatrixXd constraintKernel() const;
    //! Determine if a given frame number is part of this batch.
    bool contains(double f) const;
    //! Return the cost function
    const std::vector<double>& costFunction() const;

private:

    double _fmin;

    double _fmax;

    sptrUnitCell _cell;

    PeakList _peaks;

    FitParameters _params;

    //! Initial U matrix of cell
    Eigen::Matrix3d _u0; 

    //! U offsets
    Eigen::Vector3d _uOffsets;

    //! Cell parameters, internal format. Used internally by UBMinimizer.
    Eigen::VectorXd _cellParameters;

    std::vector<Eigen::RowVector3d> _hkls;

    std::vector<std::vector<int>> _constraints;

    std::vector<Eigen::Matrix3d> _wts;

    std::vector<std::reference_wrapper<InstrumentState>> _states;

    std::vector<double> _cost_function;
};

} // end namespace nsx
