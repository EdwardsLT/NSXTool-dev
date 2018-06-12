
#pragma once

#include <string>

#include "H5Cpp.h"

#include "IDataReader.h"
#include "InstrumentTypes.h"

namespace nsx {

class HDF5MetaDataReader: public IDataReader
{

public:
    HDF5MetaDataReader(const std::string& filename, sptrDiffractometer instrument);
    virtual ~HDF5MetaDataReader();

    void open() override;
    void close() override;

protected:
    std::unique_ptr<H5::H5File> _file;
    std::unique_ptr<H5::DataSet> _dataset;
    std::unique_ptr<H5::DataSpace> _space;
    std::unique_ptr<H5::DataSpace> _memspace;
};

} // end namespace nsx
