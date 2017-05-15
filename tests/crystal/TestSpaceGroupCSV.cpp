#define BOOST_TEST_MODULE "Test Space group CSV"
#define BOOST_TEST_DYN_LINK

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include <boost/test/unit_test.hpp>

#include <nsxlib/crystal/SpaceGroup.h>
#include <nsxlib/crystal/SpaceGroupSymbols.h>
#include <nsxlib/crystal/UnitCell.h>
#include <nsxlib/utils/CSV.h>

using namespace nsx::Crystal;
using namespace nsx::Utils;
using namespace std;

int run_test()
{
    ifstream csv_file;
    SpaceGroupSymbols* table = SpaceGroupSymbols::Instance();
    int num_rows = 0;

    std::map<std::string, int> counts;

    std::vector<std::string> symbols = table->getAllSymbols();

    for (auto&& symbol: symbols)
        counts[symbol] = 0;

    CSV csv_reader('\t', '#');
    std::vector<std::string> unrecognized_symbols;


    csv_file.open("crystallography.tsv", std::ifstream::in);

    BOOST_CHECK(csv_file.is_open());

    // skip header
    csv_reader.getRow(csv_file);

    while(!csv_file.eof()) {
        std::vector<std::string> row = csv_reader.getRow(csv_file);

        // extra newline at end of file
        if (csv_file.eof() && row.size() < 8)
            continue;

        BOOST_CHECK(row.size() == 8);

        if (row.size() != 8) {
            std::cout << "CSV READ ERROR ROW " << num_rows << std::endl;
            std::cout << "    ";

            for (auto&& item: row)
                std::cout << item << "#### ";

            std::cout << std::endl;
        }

        string sg, sgHall;

        sg = table->getReducedSymbol(row[0]);
        sgHall = row[1];

        std::string generators;

        bool found = table->getGenerators(sg, generators);

        if (!found) {
            found = table->getGenerators(sgHall, generators);
        }

        // still not found, add to list
        if (!found) {
            if (find(unrecognized_symbols.begin(), unrecognized_symbols.end(), sg) == unrecognized_symbols.end())
                unrecognized_symbols.push_back(sg);
        }

        if (found) {
            std::string full_name = table->getFullSymbol(sg);
            ++counts[full_name];
        }

        if ( num_rows%10000 == 0)
            std::cout << "row " << num_rows << std::endl;

        ++num_rows;
    }

    for (auto&& sg: unrecognized_symbols)
        std::cout << sg << std::endl;

    std::cout << unrecognized_symbols.size() << std::endl;

    for (auto&& item: counts)
        if ( item.second == 0)
            std::cout << item.first << std::endl;

    return 0;
}

BOOST_AUTO_TEST_CASE(Test_SpaceGroupCSV)
{
    BOOST_CHECK(run_test() == 0);
}
