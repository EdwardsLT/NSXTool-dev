/*
 * nsxtool : Neutron Single Crystal analysis toolkit
    ------------------------------------------------------------------------------------------
    Copyright (C)
    2012- Laurent C. Chapon, Eric C. Pellegrini Institut Laue-Langevin
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

#ifndef NSXTOOL_IDATA_H_
#define NSXTOOL_IDATA_H_

#include <memory>
#include <string>
#include <set>

#include <Eigen/Dense>

#include "AABB.h"
#include "ComponentState.h"
#include "MetaData.h"
#include "Diffractometer.h"
#include "Peak3D.h"

namespace SX
{

namespace Instrument
{
	class Component;
}

namespace Data
{

using namespace SX::Crystal;
using namespace SX::Geometry;
using namespace SX::Instrument;

/*! \brief Interface for diffraction data
 *
 * Base interface for all diffraction data. IData handles the IO
 */
class IData
{
public:

	// Constructors and destructor

	/*! Construct a IData Object from a file on disk, and pointer to a diffractometer.
	 *  @param inMemory: whether the file should be loaded in memory straight away or kept on disk
	 */
	IData(const std::string& filename, std::shared_ptr<Diffractometer> instrument);
	//! Copy constructor
	IData(const IData& other)=delete;
	//! Destructor
	virtual ~IData()=0;
	// Operators
	//! Assignment operator
	IData& operator=(const IData& other)=delete;

	// Getters and setters

    //! Gets the data basename
	std::string getBasename() const;
	//! Gets a pointer to the data
	const std::vector<Eigen::MatrixXi>& getData() const;
	//! Gets a pointer to the ith data
	const Eigen::MatrixXi& getData(std::size_t idx) const;
    //! Gets the interpolated state between two consecutive detector states
    ComponentState getDetectorInterpolatedState(double frame);
	//! Gets the the detector states.
    const ComponentState& getDetectorState(int frame) const;
	const std::vector<ComponentState>& getDetectorStates() const;
    //! Gets the data filename
	const std::string& getFilename() const;
	//! Gets a shared pointer to the diffractometer used to collect the data
	std::shared_ptr<Diffractometer> getDiffractometer() const;
	//! Return the number of frames
	std::size_t getNFrames() const;
	std::size_t getNRows() const;
	std::size_t getNCols() const;
	//! Gets a pointer to the metadata of the data
	MetaData* const getMetadata() const;
	//! Return the peaks
	std::set<Peak3D*>& getPeaks();
	//! Get the sample state for frame
	const ComponentState& getSampleState(int frame) const;
    //! Gets the interpolated state between two consecutive sample states
    ComponentState getSampleInterpolatedState(double frame);
	//! Gets the the detector states.
	const std::vector<ComponentState>& getSampleStates() const;

	// Other methods

	//! Add a new mask to the data
	void addMask(AABB<double,3>* mask);
	//! Add a new peak to the data
	void addPeak(Peak3D* peak);
	//! Remove a mask from the data
	void removeMask(AABB<double,3>* mask);
	//! Remove a peak from the data
	bool removePeak(Peak3D* peak);
	//! Clear the peaks collected for this data
	void clearPeaks();
	//! Return true if the file is stored in memory
	bool isInMemory() const;
	 //! Load all the frames in memory
	virtual void readInMemory()=0;
  // Release the data from memory
	void releaseMemory();
	//! Return true if a given point (in detector space) belong to a mask
	bool inMasked(const Eigen::Vector3d& point) const;
	//! Mask the peaks collected in the data with the masks defined up to now
	void maskPeaks() const;
	//! Return the intensity at point x,y,z.
	int dataAt(int x=0, int y=0, int z=0);
    //! Read a given Frame of the data
    virtual Eigen::MatrixXi getFrame(std::size_t i)=0;
    //! Read a single frame
    virtual Eigen::MatrixXi readFrame(std::size_t idx)=0;
    //! Get the file handle. Necessary to call before readInMemory or any IO of data.
    virtual void open()=0;
    //! Close file and release handle
    virtual void close()=0;
    //! True if file is open
    bool isOpened() const;
    //!
    std::size_t getFileSize() const;//
    void saveHDF5(const std::string& filename) const;

protected:
    bool _isOpened;
	std::string _filename;
	std::size_t _nFrames;
	std::size_t _nrows;
	std::size_t _ncols;
	std::shared_ptr<Diffractometer> _diffractometer;
	MetaData* _metadata;
	bool _inMemory;
	std::vector<Eigen::MatrixXi> _data;
	std::vector<ComponentState> _detectorStates;
	std::vector<ComponentState> _sampleStates;
    std::set<Peak3D*> _peaks;
    std::size_t _fileSize;
    //! The set of masks bound to the data
    std::set<AABB<double,3>*> _masks;

};

} // end namespace Data

} // end namespace SX


#endif // NSXTOOL_IDATA_H_
