// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/utils/CSV.h
//! @brief     Implements module/class/test CSV
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace nsx {

//! @class CSV
//! @brief Simple CSV parser
class CSV {
public:
    CSV(char delim=',', char quotchar='"');
    ~CSV();

    std::vector<std::string> getRow(std::istream& stream);

private:
    char _delim;
    char _quotchar;

    std::string getToken(std::istream& stream, char& delim); //!<< Get next token, write delimeter type
};

} // end namespace nsx
