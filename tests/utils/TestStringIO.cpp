// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      tests/utils/TestStringIO.cpp
//! @brief     Implements module/class/test TestStringIO
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <string>
#include <vector>

#include <nsxlib/NSXTest.h>
#include <nsxlib/StringIO.h>

NSX_INIT_TEST

int main()
{
    std::string str_to_trim("   blabla    ");

    NSX_CHECK_NOT_EQUAL(str_to_trim,"blabla");
    NSX_CHECK_EQUAL(nsx::trim(str_to_trim),"blabla");
    NSX_CHECK_NOT_EQUAL(str_to_trim,"blabla");

    std::string str_to_trim2("hello");
    NSX_CHECK_EQUAL(nsx::trim(str_to_trim2),"hello");

    std::string str_with_spaces("   bla      bla    ");
    NSX_CHECK_EQUAL(nsx::clear_spaces(str_with_spaces),"blabla");

    std::string str_to_compress("   bla      bla    ");
    NSX_CHECK_EQUAL(nsx::compress(str_to_compress),"bla bla");

    std::string str_to_compress2("nothing-to-compress");
    NSX_CHECK_EQUAL(nsx::compress(str_to_compress2),"nothing-to-compress");

    std::vector<std::string> to_be_joined({"toto","titi","tata"});
    NSX_CHECK_EQUAL(nsx::join(to_be_joined,","),"toto,titi,tata");

    std::vector<std::string> to_be_joined2({"good morning","everybody","!"});
    NSX_CHECK_EQUAL(nsx::join(to_be_joined2," "),"good morning everybody !");

    NSX_CHECK_NOT_EQUAL(nsx::split("hello how are you ?"," "),std::vector<std::string>({"hello","how","are","you"}));
    NSX_CHECK_EQUAL(nsx::split("hello how are you ?"," "),std::vector<std::string>({"hello","how","are","you","?"}));

    NSX_CHECK_EQUAL(nsx::split("hello ; how    ; are; you ;?",";"),std::vector<std::string>({"hello","how","are","you","?"}));
    NSX_CHECK_NOT_EQUAL(nsx::split("hello ; how    ; are; you ;?"," "),std::vector<std::string>({"hello","how","are","you","?"}));
}
