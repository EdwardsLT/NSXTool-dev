// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/integration/ShapeIntegrator.h
//! @brief     Implements module/class/test ShapeIntegrator
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <Eigen/Dense>

#include "CrystalTypes.h"
#include "GeometryTypes.h"
#include "PixelSumIntegrator.h"
#include "ShapeLibrary.h"

namespace nsx {

class DataSet;

//! \brief Peak integrator class used to build a shape library for profile fitting.
class ShapeIntegrator: public PixelSumIntegrator {
public:
    //! Construct the integrator with the given shape library, bounding box, and box shape.
    ShapeIntegrator(sptrShapeLibrary lib, const AABB& aabb, int nx, int ny, int nz);
    bool compute(sptrPeak peak, const IntegrationRegion& region) override;
    //! Return the library of cached peak shapes
    sptrShapeLibrary library() const;

private:
    sptrShapeLibrary _library;
    AABB _aabb;
    int _nx, _ny, _nz;
};

} // end namespace nsx
