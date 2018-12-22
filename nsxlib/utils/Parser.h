// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/utils/Parser.h
//! @brief     Implements module/class/test Parser
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <vector>

namespace nsx {

//! Method to read a vector of int values from two char pointers, using spirit
//! This is faster than the C atoi() function.
void readIntsFromChar(const char* begin, const char* end, std::vector<int>& v);

//! Method to read a vector of double values from two char pointers, using spirit
void readDoublesFromChar(const char* begin, const char* end, std::vector<double>& v);

} // end namespace nsx
