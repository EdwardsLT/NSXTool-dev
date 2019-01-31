// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/HDF5DataReader.h
//! @brief     Implements module/class/test HDF5DataReader
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

#include "HDF5MetaDataReader.h"
#include "InstrumentTypes.h"

namespace nsx {

//! Read data from HDF5 format
class HDF5DataReader: public HDF5MetaDataReader
{

public:

    HDF5DataReader() = delete;

    HDF5DataReader(const HDF5DataReader & other) = default;

    // Note that we need this constructor explicitly defined for SWIG.
    HDF5DataReader(const std::string& filename, Diffractometer *diffractometer);

    ~HDF5DataReader() = default;

    HDF5DataReader& operator=(const HDF5DataReader &other) = default;

    IDataReader* clone() const final;

    Eigen::MatrixXi data(size_t frame) final;
};

} // end namespace nsx
