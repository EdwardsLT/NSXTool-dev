// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/crystal/CrystalTypes.h
//! @brief     Implements module/class/test CrystalTypes
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <memory>
#include <set>
#include <utility>
#include <vector>

#include <Eigen/Dense>

namespace nsx {

class MillerIndex;
class MergedPeak;
class Peak;
class PeakIntegrator;
class PeakValidator;
class Profile;
class SpaceGroup;
class SpaceGroupSymbols;
class SymOp;
class UnitCell;

using MillerIndexList = std::vector<MillerIndex>;

using affineTransformation=Eigen::Transform<double,3,Eigen::Affine>;

using UnitCellSolution = std::pair<UnitCell,double>;

using sptrPeak   = std::shared_ptr<Peak>;
using sptrUnitCell = std::shared_ptr<UnitCell>;

using RankedSolution = std::pair<sptrUnitCell,double>;

using PeakList = std::vector<sptrPeak>;

using MergedPeakSet = std::set<MergedPeak>;

using SymOpList    = std::vector<SymOp>;
using UnitCellList = std::vector<sptrUnitCell>;

using SpaceGroupSymmetry = std::pair<std::string,std::string>;

using AutoIndexingSoluce = std::pair<UnitCell,double>;

} // end namespace nsx
