// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/TiffDataReader.cpp
//! @brief     Implements module/class/test TiffDataReader
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "Detector.h"
#include "Diffractometer.h"
#include "Macros.h"
#include "Sample.h"
#include "TiffDataReader.h"

namespace nsx {

TiffDataReader::TiffDataReader(const TiffDataReader &other) : IDataReader(other)
{
    _bits = other._bits;

    if (other._isOpened) {
        open();
    }
}

TiffDataReader::TiffDataReader(const std::string& filename, Diffractometer *diffractometer)
: IDataReader(filename,diffractometer)
{
    uint32 w,h;

    _file = TIFFOpen(filename.c_str(),"r");

    if (!_file) {
        throw std::runtime_error("Could not read "+filename+" as tif file");
    }

    TIFFGetField(_file, TIFFTAG_IMAGEWIDTH, &w);
    TIFFGetField(_file, TIFFTAG_IMAGELENGTH, &h);

    if (w!=_nCols || h!=_nRows) {
        close();
        throw std::range_error("Tiff file "+filename+ " not consistent with diffractometer definition");
    }
    _isOpened = false;
    TIFFGetField(_file, TIFFTAG_BITSPERSAMPLE, &_bits);

    if (_bits!=16 && _bits!=32) {
        close();
        throw std::runtime_error("Can't read TIFF file "+filename+" : only 16/32bits format supported");
    }

    _nFrames = 1;

    _sampleStates.resize(_nFrames);
    _detectorStates.resize(_nFrames);

    _detectorStates[0] = {};
    _sampleStates[0] = {};

    _metadata.add<std::string>("Instrument",diffractometer->name());

    close();
}

TiffDataReader& TiffDataReader::operator=(const TiffDataReader &other)
{
    if (this != &other) {
        IDataReader::operator=(other);
        _bits = other._bits;

        if (other._isOpened) {
            open();
        }
    }
    return *this;
}

IDataReader* TiffDataReader::clone() const
{
    return new TiffDataReader(*this);
}

void TiffDataReader::open()
{
    if (_isOpened) {
        return;
    }

    try {
        _file = TIFFOpen(_metadata.key<std::string>("filename").c_str(),"r");
    } catch(...) {
        throw;
    }
    _isOpened = true;
}

void TiffDataReader::close()
{
    if (_isOpened) {
        TIFFClose(_file);
    }
    _isOpened = false;
}


Eigen::MatrixXi TiffDataReader::data(std::size_t frame)
{
    NSX_UNUSED(frame)

    if (!_isOpened) {
        open();
    }

    if (_bits==16) {

        Eigen::Matrix<uint16,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> data16(_nRows,_nCols);
        // Read line per line
        for(unsigned short int i=0; i< _nRows; ++i)
            TIFFReadScanline(_file, (char*)&data16(i,0), i);
        // Not very nice, but need to copy the 16bits data to int
        return data16.cast<int>();

    } else {

        Eigen::Matrix<uint32,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> data32(_nRows,_nCols);
        // Read line per line
        for(unsigned short int i=0; i< _nRows; ++i) {
            TIFFReadScanline(_file, (char*)&data32(i,0), i);
        }
        // Not very nice, but need to copy the 32bits data to int
        return data32.cast<int>();

    }
}

} // end namespace nsx
