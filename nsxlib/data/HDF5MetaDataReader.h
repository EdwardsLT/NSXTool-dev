// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/HDF5MetaDataReader.h
//! @brief     Implements module/class/test HDF5MetaDataReader
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <string>

#include "H5Cpp.h"

#include "IDataReader.h"
#include "InstrumentTypes.h"

namespace nsx {

//! \brief Read the experiment metadata from and HDF file.
class HDF5MetaDataReader: public IDataReader
{

public:

    HDF5MetaDataReader() = delete;

    HDF5MetaDataReader(const HDF5MetaDataReader &other);

    HDF5MetaDataReader(const std::string& filename, Diffractometer* instrument);

    virtual ~HDF5MetaDataReader();

    HDF5MetaDataReader& operator=(const HDF5MetaDataReader & other);

    IDataReader* clone() const = 0;

    virtual void open() override;

    virtual void close() override;

protected:

    void init();

    std::unique_ptr<H5::H5File> _file;

    std::unique_ptr<H5::DataSet> _dataset;

    std::unique_ptr<H5::DataSpace> _space;

    std::unique_ptr<H5::DataSpace> _memspace;
};

} // end namespace nsx
