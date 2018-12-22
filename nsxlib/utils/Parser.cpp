// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/utils/Parser.cpp
//! @brief     Implements module/class/test Parser
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <boost/spirit/include/qi.hpp>

#include "Parser.h"

namespace nsx {

void readIntsFromChar(const char* begin, const char* end, std::vector<int>& v)
{
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;
    qi::phrase_parse(begin, end, *qi::int_ >> qi::eoi, ascii::space, v);
}

void readDoublesFromChar(const char* begin, const char* end, std::vector<double>& v)
{
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;
    qi::phrase_parse(begin, end, *qi::double_ >> qi::eoi, ascii::space, v);
}

} // end namespace nsx

