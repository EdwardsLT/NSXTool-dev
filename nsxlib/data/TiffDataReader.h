/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon Eric Pellegrini
 Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr
 pellegrini[at]ill.fr

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef NSXLIB_TIFFDATAREADER_H
#define NSXLIB_TIFFDATAREADER_H

#include <tiffio.h>

#include "../data/IDataReader.h"
#include "../instrument/InstrumentTypes.h"

namespace nsx {

class TiffDataReader: public IDataReader {

public:
    static IDataReader* create(const std::string& filename, const sptrDiffractometer& diffractometer);

    TiffDataReader(const std::string& filename, const sptrDiffractometer& diffractometer);

    virtual ~TiffDataReader()=default;

    void open() override;

    void close() override;

    Eigen::MatrixXi getData(std::size_t frame) override;

private:

    //! Type of encoding for each pixel.
    uint16 _bits;
    //!
    TIFF* _file;
};

} // end namespace nsx

#endif // NSXLIB_TIFFDATAREADER_H
