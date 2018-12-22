// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/utils/EigenToVector.cpp
//! @brief     Implements module/class/test EigenToVector
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "EigenToVector.h"

namespace nsx {

std::vector<double> eigenToVector(const Eigen::VectorXd &ev)
{
   const size_t size(ev.size());
   std::vector<double> v(size);
   for (size_t i = 0; i < size; ++i) {
       v[i] = ev(i);
   }
   return v;
}

} // end namespace nsx
