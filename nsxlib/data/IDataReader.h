// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/IDataReader.h
//! @brief     Implements module/class/test IDataReader
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <string>
#include <vector>

#include <Eigen/Dense>

#include "InstrumentState.h"
#include "InstrumentTypes.h"
#include "MetaData.h"

namespace nsx {

class Diffractometer;

//! \brief Interface used to provide access to detector images and metadata.
class IDataReader {

public:
    //! Construct data reader from given filename and diffractometer
    IDataReader(const std::string& filename, Diffractometer* diffractometer);

    //! Destructor
    virtual ~IDataReader() = 0;

    //! Clone this reader
    virtual IDataReader* clone() const = 0;

    //! Open the file
    virtual void open() = 0;

    //! Close file and release handle
    virtual void close() = 0;

    //! Return the a detector image
    virtual Eigen::MatrixXi data(size_t frame) = 0;

    //! Return the instrument state as read from the metadata
    InstrumentState state(size_t frame) const;

    //! Return the list of sample states associated to the detector images
    const std::vector<std::vector<double>>& sampleStates() const;

    //! Return the list of detector states associated to the detecot images
    const std::vector<std::vector<double>>& detectorStates() const;

    //! Return the metadata in the file
    const MetaData& metadata() const;

    //! Return the metadata in the file
    MetaData& metadata();

    //! Return number of detector images
    size_t nFrames() const;

    //! Return number of columns in each detector image
    size_t nCols() const;

    //! Return number of rows in each detector image
    size_t nRows() const;

    //! Return a const pointer to the diffractometer bound to the data
    const Diffractometer* diffractometer() const;

    //! Return a pointer to the diffractometer bound to the data
    Diffractometer* diffractometer();

    //! Gets the data basename
    std::string basename() const;

    //! Gets the data filename
    std::string filename() const;

    //! True if file is open
    bool isOpened() const;

protected:

    IDataReader() = delete;

    IDataReader(const IDataReader &other) = default;

    IDataReader& operator=(const IDataReader &other) = default;

    std::string _filename;

    //! A pointer to the diffractometer. The actual resource is not owned by this object which is just a borrower.
    Diffractometer* _diffractometer;

    //! Stores the metadata
    MetaData _metadata;

    //! Number of frames of data
    std::size_t _nFrames;

    //! Number of rows
    std::size_t _nRows;

    //! Number of columns
    std::size_t _nCols;

    //! Vector of sample states
    std::vector<std::vector<double>> _sampleStates;

    //! Vector of detector states
    std::vector<std::vector<double>> _detectorStates;

    //! Status of file handle
    bool _isOpened;
};

} // end namespace nsx
