// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/geometry/GeometryTypes.h
//! @brief     Implements module/class/test GeometryTypes
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <functional>
#include <memory>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

#include <Eigen/Dense>

namespace nsx {

class AABB;
class Blob3D;
class ConvexHull;
class DirectVector;
class Ellipsoid;
class Octree;
class ReciprocalVector;
class ShapeLibrary;
class Profile3D;

struct Edge;
struct Face;
struct Triangle;
struct Vertex;

using HomVector   = Eigen::Matrix<double,4,1>;
using HomMatrix   = Eigen::Matrix<double,4,4>;

using covMat = Eigen::Matrix<double,9,9>;

using sptrEllipsoid = std::shared_ptr<Ellipsoid>;

using sptrProfile3D = std::shared_ptr<Profile3D>;

using sptrShapeLibrary = std::shared_ptr<ShapeLibrary>;

using TrianglesList = std::vector<Triangle>;

using EquivalencePair = std::pair<int,int>;
using EquivalenceList = std::vector<EquivalencePair>;

using Blob3DUMap = std::unordered_map<int,Blob3D>;

enum class Direction {CW=1,CCW=2};

enum class PointType {REGION = 1, BACKGROUND = 2, EXCLUDED = 3};

} // end namespace nsx
