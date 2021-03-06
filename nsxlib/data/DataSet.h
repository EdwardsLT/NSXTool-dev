// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/DataSet.h
//! @brief     Implements module/class/test DataSet
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <memory>
#include <mutex>
#include <set>
#include <string>

#include <Eigen/Dense>

#include "CrystalTypes.h"
#include "DataTypes.h"
#include "GeometryTypes.h"
#include "Mask.h"
#include "InstrumentTypes.h"
#include "InterpolatedState.h"
#include "UtilsTypes.h"

namespace nsx {

class Mask;

//! \brief Class used to manage loading detector images and metadata from disk.
class DataSet {
    friend class UnitTest_DataSet;

public:

    DataSet() = delete;

    DataSet(const std::string& filetype, const std::string& filename, Diffractometer* diffractometer);

    DataSet(const DataSet &other);

    //! Destructor
    ~DataSet();

    //! Assignment operator
    DataSet& operator=(const DataSet& other);

    //! Gets the data filename
    const std::string& filename() const;

    //! Return the number of frames
    std::size_t nFrames() const;

    //! Return the number of rows in each detector image
    std::size_t nRows() const;

    //! Return the number of columns in each detector image
    std::size_t nCols() const;

    //! Gets the the sample states
    InstrumentStateList& instrumentStates();

    //! Gets the the sample states
    const InstrumentStateList& instrumentStates() const;

    //! Get the interpolated state of a given component
    InterpolatedState interpolatedState(double frame) const;

    //! Add a new mask to the data
    void addMask(std::shared_ptr<Mask> mask);

    //! Remove a mask from the data, by reference
    void removeMask(std::shared_ptr<Mask> mask);

    //! Return the list of masks
    const std::set<std::shared_ptr<Mask>>& masks();

    //! Return the intensity at point x,y,z.
    int dataAt(unsigned int x=0, unsigned int y=0, unsigned int z=0);

    //! Read a single frame
    Eigen::MatrixXi frame(std::size_t idx) const;

    //! Return frame after transforming to account for detector gain and baseline
    Eigen::MatrixXd transformedFrame(std::size_t idx);

    //! Return a convolved frame
    Eigen::MatrixXd convolvedFrame(std::size_t idx, const std::string& convolver_type, const std::map<std::string,int>& parameters);

    //! Get the file handle.
    void open();

    //! Close file and release handle
    void close();

    //! True if file is open
    bool isOpened() const;

    //! Export dataset to HDF5 format
    void saveHDF5(const std::string& filename);

    //! Return detector events corresponding to the list of q values.  
    std::vector<DetectorEvent> events(const std::vector<ReciprocalVector>& sample_qs) const;

    //! Return the sample-space q vector corresponding to a detector event
    ReciprocalVector computeQ(const DetectorEvent& ev) const;

    //! Return a non-const to the data reader used to set this dataset
    IDataReader* reader();

    //! Return a non-const to the data reader used to set this dataset
    const IDataReader* reader() const;

private:

    bool _isOpened;

    std::string _filename;

    std::size_t _nFrames;

    std::size_t _nrows;

    std::size_t _ncols;

    std::vector<Eigen::MatrixXi> _data;

    InstrumentStateList _states;

    //! The set of masks bound to the data
    std::set<std::shared_ptr<Mask>> _masks;

    FrameIteratorCallback _iteratorCallback;

    std::unique_ptr<IDataReader> _reader;
};

} // end namespace nsx
