// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/TiffDataReader.h
//! @brief     Implements module/class/test TiffDataReader
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <tiffio.h>

#include "IDataReader.h"
#include "InstrumentTypes.h"

namespace nsx {

//! Read detector image from Tiff file
class TiffDataReader: public IDataReader {

public:

    TiffDataReader() = delete;

    TiffDataReader(const TiffDataReader &other);

    TiffDataReader(const std::string& filename, Diffractometer *diffractometer);

    ~TiffDataReader() = default;

    TiffDataReader& operator=(const TiffDataReader &other);

    IDataReader* clone() const final;

    void open() final;

    void close() final;

    Eigen::MatrixXi data(std::size_t frame) final;

private:

    //! Type of encoding for each pixel.
    uint16 _bits;

    //! The handler to the TIFF file
    TIFF* _file;
};

} // end namespace nsx
