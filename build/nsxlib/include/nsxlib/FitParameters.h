// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/mathematics/FitParameters.h
//! @brief     Implements module/class/test FitParameters
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <vector>

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

#include <Eigen/Core>
#include <Eigen/SparseCore>

namespace nsx {

//! \class FitParameters
//! \brief Class to encapsulate parameters to be passed to nsx::Minimizer.
class FitParameters {

public:
    //! Add a parameter to be fit. The original value of the parameter is stored (see reset()). The return value is the index of the parameter.
    int addParameter(double* addr);
    //! Set values of the parameters from a GSL vector.
    void setValues(const gsl_vector* v);
    //! Write the values to a GSL vector
    void writeValues(gsl_vector* v) const;
    //! Return the number of parameters
    size_t nparams() const;
    //! Return the number of free parameters
    size_t nfree() const;
    //! Set the constraint matrix
    void setConstraint(const Eigen::SparseMatrix<double>& C);
    //! Remove the constraints
    void resetConstraints();
    //! Kernel of the constraints: this is the transformation from constrained parameters to original parameters.
    const Eigen::MatrixXd& kernel() const;
    //! Set the kernel of the constraints.
    void setKernel(const Eigen::MatrixXd& ker);

    //! Reset parameter values to their original state.
    void reset();

private:
    //! Vector of addresses to fit parameters. Pointers are _not_ owned.
    std::vector<double*> _params;
    std::vector<double> _originalValues;
    //! Linear transformation from kernel to parameters. The columns of K form a basis
    //! for the kernel of _C.
    Eigen::MatrixXd _K;

    //! Projection from unconstrained parameter space to constrained parameter space.
    Eigen::MatrixXd _P;

    //! Need to update constraints
    bool _constrained;

};

} // end namespace nsx
