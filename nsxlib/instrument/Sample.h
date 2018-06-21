/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon Eric Pellegrini
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

#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

#include "ChemistryTypes.h"
#include "Component.h"
#include "ConvexHull.h"
#include "CrystalTypes.h"

namespace nsx {

//! \brief Class used to describe an experiment sample, consisting of a unit cell and material. 
class Sample: public Component {
public:

    //! Static constructor of a Sample from a property tree node
    static Sample* create(const YAML::Node& node);
    //! Default constructor
    Sample();
    //! Copy constructor
    Sample(const Sample& other);
    //! Constructs a default sample with a given name
    Sample(const std::string& name);
    //! Constructs a sample from a property tree node
    Sample(const YAML::Node& node);
    //! Virtual copy constructor
    Sample* clone() const;
    //! Destructor
    virtual ~Sample();
    //! Assignment operator
    Sample& operator=(const Sample& other);
    //! Set the sample shape described as a convex hull
    void setShape(const ConvexHull& shape);
    //! Return the sample shape, described as a convex hull
    ConvexHull& shape();
    //! Returnt he list of unit cells of the sample
    UnitCellList& unitCells();
    //! Return the list of unit cells of the sample
    const UnitCellList& unitCells() const;

private:
    ConvexHull _sampleShape;
    //! UnitCells of all crystals associated with this sample
    UnitCellList _cells;
};

} // end namespace nsx
