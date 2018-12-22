// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/crystal/TestSpaceGroupCSV.cpp
//! @brief     Implements module/class/test TestSpaceGroupCSV
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <fstream>
#include <map>
#include <string>

#include <nsxlib/CSV.h>
#include <nsxlib/NSXTest.h>
#include <nsxlib/SpaceGroup.h>
#include <nsxlib/UnitCell.h>

NSX_INIT_TEST

int main()
{
    std::ifstream csv_file;

    nsx::CSV csv_reader('\t', '#');

    csv_file.open("crystallography.tsv", std::ifstream::in);

    NSX_CHECK_ASSERT(csv_file.is_open());

    // skip header
    csv_reader.getRow(csv_file);

    while(!csv_file.eof()) {
        std::vector<std::string> row = csv_reader.getRow(csv_file);

        // extra newline at end of file
        if (csv_file.eof() && row.size() < 8)
            continue;

        NSX_CHECK_ASSERT(row.size() == 8);

        std::cout<<row[0]<<std::endl;

        NSX_CHECK_NO_THROW(nsx::SpaceGroup sg(row[0]));
    }

    return 0;
}
