// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/geometry/BrillouinZone.h
//! @brief     Implements module/class/test BrillouinZone
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <vector>

#include <Eigen/Dense>

#include "ConvexHull.h"
#include "DataTypes.h"
#include "GeometryTypes.h"

namespace nsx {

//! \class BrillouinZone
//! \brief Class to calculate first Brillouin zone of a lattice and to convert it to a convex hull representation.
//! The first Brillouin zone of a lattice is defined to be the set of all vectors which are closer to the origin
//! than to any other lattice point. From this definition, it comes that it is a convex hull bounded
//! by Bragg planes, i.e. planes with normal vector q passing through the point q/2 for lattice vectors q. 
//! Hence, to construct the Brillouin zone, one has to enumerate the finitely many q's which appear
//! as normals to the faces of the zone. Then, the bouding vertices are determined by taking 3-fold intersections of the bounding planes.
class BrillouinZone {

public:
    //! Create a Brillouin zone out of the given (row) basis matrix B.
    BrillouinZone(const Eigen::Matrix3d& B, double eps=1e-6);
    //! Check if a reciprocal vector is inside the Brillouin zone.
    bool inside(const Eigen::RowVector3d& q) const;
    //! Return the vertices of the polytope.
    const std::vector<Eigen::RowVector3d>& vertices() const;
    //! Return the list of plane normals (q values for Bragg planes).
    const std::vector<Eigen::RowVector3d>& normals() const;
    //! Return a convex hull representation.
    ConvexHull convexHull() const;

    //! Return radius of largest sphere contained in the zone.
    double innerRadius() const;
    //! Return radius of smallest sphere containing the zone.
    double outerRadius() const;

    //! Return the convex hull, transformed to detector coordinates.
    //! May throw if the vertices cannot be transformed (e.g. peak on edge of image).
    ConvexHull detectorConvexHull(const ReciprocalVector& q0, sptrDataSet data) const;

private:

    //! List of lattice vectors defining the Bragg planes of the Brillouin zone
    std::vector<Eigen::RowVector3d> _qs;
    //! Parameter to control numerical stability
    double _eps;
    //! The basis matrix (row vectors)
    Eigen::Matrix3d _B;
    //! List of vertices generating the Brillouin zone as a convex hull
    std::vector<Eigen::RowVector3d> _vertices;
    //! squared radius of the smallest sphere containing the zone
    double _r2;

    //! Calculate bounding planes of the Brillouin zone
    void compute();
    //! Remove extraneous bounding planes
    void clean_qs();
    //! Compute the bounding vertices
    void compute_vertices();

};

} // end namespace nsx
