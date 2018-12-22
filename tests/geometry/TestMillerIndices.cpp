// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/geometry/TestMillerIndices.cpp
//! @brief     Implements module/class/test TestMillerIndices
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <Eigen/Dense>

#include <nsxlib/MillerIndex.h>
#include <nsxlib/NSXTest.h>

NSX_INIT_TEST

int main() {

    Eigen::RowVector3i v1(1,2,3);

    nsx::MillerIndex hkl1(v1);

    int& x = hkl1[0];

    x = 100;

    NSX_CHECK_EQUAL(hkl1[0],100);

    return 0;
}
