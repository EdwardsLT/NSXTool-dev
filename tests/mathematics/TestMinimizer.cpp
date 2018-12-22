// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/mathematics/TestMinimizer.cpp
//! @brief     Implements module/class/test TestMinimizer
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <vector>
#include <string>

#include <Eigen/Dense>

#include <nsxlib/FitParameters.h>
#include <nsxlib/Minimizer.h>
#include <nsxlib/NSXTest.h>

NSX_INIT_TEST

int main()
{
    Eigen::VectorXd y, wt, x;
    int nvalues = 40;
    const int num_points = 40;
    y.resize(num_points, 1);
    wt.resize(num_points, 1);

    x.resize(3);
    x << 4.0, 0.2, 0.5;

    for (int i = 0; i < nvalues; i++) {
        double t = i;
        double yi = 1.0 + 5 * exp (-0.1 * t);

        wt[i] = 1.0;
        y[i] = yi;
    }

    auto residual_fn = [y, &x] (Eigen::VectorXd& r) -> int {
        int n = r.rows();

        double A = x(0);
        double lambda = x(1);
        double b = x(2);

        for (int i = 0; i < n; i++) {
            /* Model Yi = A * exp(-lambda * i) + b */
            double t = i;
            double Yi = A * exp (-lambda * t) + b;
            r(i) = Yi - y[i];
        }
        return 0;
    };
 
    nsx::FitParameters params;
    params.addParameter(&x(0));
    params.addParameter(&x(1));
    params.addParameter(&x(2));

    nsx::Minimizer min;
    min.initialize(params, 40);
    min.set_f(residual_fn);
    NSX_CHECK_ASSERT(min.fit(100));

    NSX_CHECK_CLOSE(x(0), 5.0, 1e-6);
    NSX_CHECK_CLOSE(x(1), 0.1, 1e-6);
    NSX_CHECK_CLOSE(x(2), 1.0, 1e-6);

    return 0;
}
