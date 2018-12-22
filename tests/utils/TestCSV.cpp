// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/utils/TestCSV.cpp
//! @brief     Implements module/class/test TestCSV
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <sstream>
#include <string>
#include <vector>

#include <nsxlib/CSV.h>
#include <nsxlib/NSXTest.h>

NSX_INIT_TEST

int main() {
    std::string csv_file =
        //    ",,,\n"
        //    "a, b, c, d\n"
        //    "e, f, g, h\n"
        //    "1, 2, 3, 4\n"
            "\"\", \"\"\"\"\", \"as,df\", \" \"\"\" \"";

    std::istringstream stream(csv_file);
    nsx::CSV csv;
    std::vector<std::string> row;

    while(!stream.eof()) {
        row = csv.getRow(stream);
        NSX_CHECK_ASSERT(row.size() == 4);
    }

    return 0;
}
