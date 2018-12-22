// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/instrument/TestTransAxis.cpp
//! @brief     Implements module/class/test TestTransAxis
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <Eigen/Dense>

#include <nsxlib/NSXTest.h>
#include <nsxlib/TransAxis.h>

const double tolerance=1e-6;

NSX_INIT_TEST

int main()
{
    nsx::TransAxis t("x",Eigen::Vector3d(1,0,0));

    // Translate the vector 0,1,2 by 0.4
    Eigen::Vector3d v=t.transform(Eigen::Vector3d(0,1,2),0.4);

    NSX_CHECK_CLOSE(v[0],0.4,tolerance);
    NSX_CHECK_CLOSE(v[1],1.0,tolerance);
    NSX_CHECK_CLOSE(v[2],2.0,tolerance);

    return 0;
}
