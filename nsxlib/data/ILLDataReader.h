// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/ILLDataReader.h
//! @brief     Implements module/class/test ILLDataReader
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <map>
#include <sstream>
#include <string>
#include <vector>

#include <boost/interprocess/mapped_region.hpp>

#include <Eigen/Dense>

#include "IDataReader.h"
#include "InstrumentTypes.h"

namespace nsx {

//! ILL ascii data format
class ILLDataReader: public IDataReader {

public:

    ILLDataReader() = delete;

    //! Copy constructor
    ILLDataReader(const ILLDataReader &other);

    //! Default constructor
    ILLDataReader(const std::string& filename, Diffractometer *diffractometer);

    //! Destructor
    ~ILLDataReader() = default;

    //! Assignment operator
    ILLDataReader& operator=(const ILLDataReader& other);

    IDataReader* clone() const final;

    // Other methods
    void open() final;

    void close() final;

    //! Read a single frame
    Eigen::MatrixXi data(size_t frame) final;

private:

    static std::size_t BlockSize;

    //! Invoke seekg to beginning the line number, at position pos. First line is 1
    void goToLine(std::stringstream& buffer, int number,int pos);

    //! Read the control block containing all float parameters.
    void readControlFBlock(std::stringstream&);

    //! Read the control block containing all Integer Metadata.
    void readControlIBlock(std::stringstream&);

    //! Read the file header containing the numor, user, instr, local contact, date and time
    //! This is all fixed format.
    void readHeader(std::stringstream&);

    //! Reads MetaData from a chain of characters as written in legacy ILL format
    //! return a MetaData Object
    void readMetadata(const char* buf);

    std::size_t _dataPoints;

    std::size_t _nAngles;

    std::size_t _headerSize;

    std::size_t _skipChar;

    std::size_t _dataLength;

    boost::interprocess::mapped_region _map;

    const char* _mapAddress;

    std::size_t _currentLine;
};

} // end namespace nsx
