/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon, Eric Pellegrini
 Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr
 pellegrini[at]ill.fr

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

#pragma once

#include <array>
#include <ostream>
#include <string>
#include <vector>

#include <Eigen/Dense>

#include "CrystalTypes.h"
#include "GeometryTypes.h"
#include "SymOp.h"

namespace nsx {

class SpaceGroup {

public:

    static std::vector<SpaceGroupSymmetry> symmetry_table;

    static std::vector<std::string> symbols();

public:
    //! Construct a space group from its IT symbol. Lookup in the IUCR table
    SpaceGroup(std::string symbol);
    //! Copy
    SpaceGroup(const SpaceGroup& other) = default;
    //! Assignment
    SpaceGroup& operator=(const SpaceGroup& other);
    //! Get the IT symbol for this space group
    const std::string& symbol() const;
    //! Get the string containing the generators (in the Jones notation), separated bt ";' character
    const std::string& generators() const;
    //! Get a vector containing the Symmetry operations for this space group
    const SymOpList& groupElements() const;
    //! Determine whether a h,k,l reflection is forbidden
    bool isExtinct(const MillerIndex& hkl) const;
    //! Return true if centrosymmetric
    bool isCentrosymmetric() const;
    //! Print to a stream
    void print(std::ostream& os) const;
    //! Return the type of cell (triclinic, monoclinic ...)
    char bravaisType() const;
    //! Return the percentage of extinct reflections
    double fractionExtinct(const MillerIndexList& hkls) const;
    //! Return the Bravais type symbol
    std::string bravaisTypeSymbol() const;
    //! Return the ID of the space group
    int id() const;    
    //! Return whether two sets of indices are related by a symmetry
    bool isEquivalent(double h1, double k1, double l1, double h2, double k2, double l2, bool friedel=false) const;
    //! Return whether two sets of indices are related by a symmetry
    bool isEquivalent(const ReciprocalVector& a, const ReciprocalVector& b, bool friedel=false) const;
    //! Return whether two sets of indices are related by a symmetry up to Friedel reflection
    bool isFriedelEquivalent(double h1, double k1, double l1, double h2, double k2, double l2) const;

    std::vector<PeakList> findEquivalences(const PeakList &peak_list, bool friedel) const;

private:

    void reduceSymbol();

    void generateGroupElements();

    std::string _symbol;
    std::string _generators;
    SymOpList _groupElements;
};

std::ostream& operator<<(std::ostream& os, const SpaceGroup& sg);

} // end namespace nsx
