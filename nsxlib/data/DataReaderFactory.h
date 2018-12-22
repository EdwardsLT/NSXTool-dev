// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/DataReaderFactory.h
//! @brief     Implements module/class/test DataReaderFactory
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>

namespace nsx {

    class IDataReader;
    class DataSet;
    class Diffractometer;

/** \brief DataReaderFactory. All IData formats must register their "create" method with the factory in order to
 * choose the correct DataReader at runtime. Reader selection is based on the extension of the datafile.
 *
 */
class DataReaderFactory {

public:
    //! Callback type of the factory
    using callback = std::function<IDataReader*(const std::string&, Diffractometer*)>;

    DataReaderFactory();

    IDataReader* create(const std::string& extension, const std::string& filename, Diffractometer *diffractometer) const;

private:
    std::map<std::string, callback> _callbacks;
};

} // end namespace nsx
