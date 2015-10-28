#define BOOST_TEST_MODULE "Test Lattice Constraint Parser"
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <iostream>
#include <string>

#include "LatticeConstraintParser.h"

using namespace SX::Utils;

BOOST_AUTO_TEST_CASE(Test_LatticeConstraintParser)
{

	namespace filesystem=boost::filesystem;

	LatticeConstraintParser<std::string::iterator> parser;

	SX::Utils::constraints_set constraints;

	std::string s("a=2b");
	BOOST_CHECK(qi::phrase_parse(s.begin(),s.end(),parser,qi::blank,constraints));

}
