// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/crystal/NiggliCharacter.h
//! @brief     Implements module/class/test NiggliCharacter
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

namespace nsx {

//! Centering type of the Bravais lattice
enum class LatticeCentring: char {
    P='P',
    A='A',
    C='C',
    I='I',
    F='F',
    R='R'
};

//! Bravais type
enum class BravaisType: char  {
    Triclinic='a',
    Monoclinic='m',
    Orthorhombic='o',
    Tetragonal='t',
    Hexagonal='h',
    Cubic='c',
    Trigonal='h'
};

// todo: refactor into LatticeCharacter
//! \class NiggliCharacter
//! \brief Helper struct used to store the classified type of the Niggli cell
struct NiggliCharacter {
    int number = 31; //!< number according to tables
    bool typeI = true; //!< true if type I, else type II
    std::string bravais = "aP"; //!< Bravais type
    Eigen::MatrixXd C; //!< matrix of linear constraints
    Eigen::Matrix3d P = Eigen::Matrix3d::Identity(); //!< transformation matrix
    
    bool operator==(const NiggliCharacter& other) const {
        return ((number == other.number) && (typeI == other.typeI) && (bravais == other.bravais) && (C == other.C) && (P == other.P));

    }

    bool operator!=(const NiggliCharacter& other) const {
        return ((number != other.number) || (typeI != other.typeI) || (bravais != other.bravais) || (C != other.C) || (P != other.P));

    }

    //! Initialize the condition according to priority in the table of characters
    //! with s = sign(D+E+F) and t = sign(2D+F)
    bool set(int priority, double s, double t);
};

} // end namespace nsx
