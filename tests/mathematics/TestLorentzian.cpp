#include <nsxlib/Lorentzian.h>
#include <nsxlib/NSXTest.h>

const double eps = 1e-10;

NSX_INIT_TEST

int main()
{
    nsx::Lorentzian l1(2.0, 3.0, 1.0);
    NSX_CHECK_CLOSE(l1.evaluate(1.0), 4.0 / 9.0, eps);

    return 0;
}
