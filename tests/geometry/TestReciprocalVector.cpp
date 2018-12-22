// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/geometry/TestReciprocalVector.cpp
//! @brief     Implements module/class/test TestReciprocalVector
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <Eigen/Dense>

#include <nsxlib/NSXTest.h>
#include <nsxlib/ReciprocalVector.h>

NSX_INIT_TEST

int main()
{

    Eigen::RowVector3d v1(1,2,3);

    nsx::ReciprocalVector rv1(v1);

    double& x = rv1[0];

    x = 100;

    NSX_CHECK_EQUAL(rv1[0],100);

    return 0;
}
