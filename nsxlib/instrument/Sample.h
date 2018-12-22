// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/instrument/Sample.h
//! @brief     Implements module/class/test Sample
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

#include "ChemistryTypes.h"
#include "Component.h"
#include "ConvexHull.h"
#include "CrystalTypes.h"
#include "DataTypes.h"

namespace nsx {

//! Helper struct for storing the result of the sample gonio fit
struct SampleGonioFit
{
    bool success;
    std::vector<double> offsets;
    std::vector<double> cost_function;
};

//! \brief Class used to describe an experiment sample, consisting of a unit cell and material. 
class Sample: public Component {
public:

    //! Static constructor of a Sample from a property tree node
    static Sample* create(const YAML::Node& node);

    //! Default constructor
    Sample();

    //! Copy constructor
    Sample(const Sample& other)=default;

    //! Constructs a default sample with a given name
    Sample(const std::string& name);

    //! Constructs a sample from a property tree node
    Sample(const YAML::Node& node);

    //! Virtual copy constructor
    Sample* clone() const;

    //! Destructor
    virtual ~Sample();

    //! Assignment operator
    Sample& operator=(const Sample& other)=default;

    //! Set the sample shape described as a convex hull
    void setShape(const ConvexHull& shape);

    //! Return a non-const reference to the convex hull describing the sample shape
    ConvexHull& shape();

    //! Return a const reference to the convex hull describing the sample shape
    const ConvexHull& shape() const;

    SampleGonioFit fitGonioOffsets(const DataList& dataset, size_t n_iterations=1000, double tolerance=1.0e-6) const;

private:

    ConvexHull _sampleShape;
};

} // end namespace nsx
