#define BOOST_TEST_MODULE "Test Space group symbols"
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <string>
#include <iostream>

#include "SpaceGroupSymbols.h"
#include "SpaceGroup.h"

using namespace SX::Crystal;

BOOST_AUTO_TEST_CASE(Test_SpaceGroupSymbols)
{
	auto table=SpaceGroupSymbols::Instance();
	std::string generators;
	bool test=table->getGenerators("P n m a",generators);

	BOOST_CHECK(test);
	// Check that string generator strings are OK s
	BOOST_CHECK(generators.compare(" -x+1/2,-y,z+1/2; -x,y+1/2,-z; -x,-y,-z")==0);


    auto symbols = table->getAllSymbols();

    for (auto&& symbol: symbols) {
        try {

            std::string reduced = table->getReducedSymbol(symbol);

            if (reduced != symbol)
                std::cout << symbol << " \t\t " << reduced << std::endl;

            BOOST_CHECK(symbol == table->getFullSymbol(symbol));
            BOOST_CHECK(table->getFullSymbol(reduced) == symbol);

            SpaceGroup grp(symbol);
        }
        catch(std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
            BOOST_ERROR("Caught exception");
        }
    }
}
