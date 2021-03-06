// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/InterpolatedState.h
//! @brief     Implements module/class/test InterpolatedState
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include "DirectVector.h"
#include "InstrumentState.h"
#include "ReciprocalVector.h"

#include <Eigen/Core>

namespace nsx {

//! Class to store an interpolation between two instrument states.
//! In addition to the data fields stored in an InstrumentState, this class
//! also stores information about the (angular) velocity and step size, which
//! is needed to compute analytic derivatives of various functions.
class InterpolatedState: public InstrumentState {
public:
    //! Default value needed for SWIG (note: nullptr does _not_ work) 
    InterpolatedState(Diffractometer *diffractometer=nullptr);
    //! Construct by interpolation. The paramter t should be between 0 and 1.
    InterpolatedState(const InstrumentState& s1, const InstrumentState& s2, double t);
    //! Compute the jacobian of the transformation (x,y,frame) -> q_sample
    Eigen::Matrix3d jacobianQ(double px, double py) const;
    //! Compute the Lorentz factor at the detector coordinates (px, py).
    double lorentzFactor(double px, double py) const;
    //! The axis of crystal rotation, in _sample space_.
    Eigen::Vector3d axis;
    //! Step size between the two underlying InstrumentStates, in radians
    double stepSize;

    #ifndef SWIG
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    #endif
};

} // end namespace nsx
