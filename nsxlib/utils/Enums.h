// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/utils/Enums.h
//! @brief     Implements module/class/test Enums
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

namespace nsx {

enum class DataOrder : size_t {TopLeftColMajor=0,
                               TopLeftRowMajor=1,
                               TopRightColMajor=2,
                               TopRightRowMajor=3,
                               BottomLeftColMajor=4,
                               BottomLeftRowMajor=5,
                               BottomRightColMajor=6,
                               BottomRightRowMajor=7};

} // end namespace nsx
