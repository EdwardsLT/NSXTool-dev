// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/auto_indexing/GruberReduction.h
//! @brief     Implements module/class/test GruberReduction
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <string>

#include <Eigen/Dense>

#include "NiggliCharacter.h"
#include "UnitCell.h"

namespace nsx {

//! \class GruberReduction
//! \brief Classify and reduce a lattice according to the 44 types in the international tables.
class GruberReduction
{
public:
    //!! Construct algorithm with the metric tensor of the Cell, and a tolerance
    GruberReduction(const Eigen::Matrix3d& g, double epsilon);
    //! Find the conventional cell and output transformation matrix, centring type and Bravais lattice of the new cell.
    //! Return value is the condition which matched (1-44)
    int reduce(Eigen::Matrix3d& P, LatticeCentring& centring, BravaisType& bravais);
    //! Classify the lattice as one of the 44 types listed in the international tables.
    //! The return value contains all relevant information about the class.
    NiggliCharacter classify();

private:
    bool equal(double A,double B) const;
    Eigen::Matrix3d _g;
    double _epsilon;
};

} // end namespace nsx
