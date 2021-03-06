// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/DataSet.cpp
//! @brief     Implements module/class/test DataSet
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <cmath>
#include <stdexcept>
#include <utility>
#include <vector>

#include "blosc.h"

#include "H5Cpp.h"

#include <Eigen/Dense>

#include "AABB.h"
#include "BloscFilter.h"
#include "ConvolverFactory.h"
#include "CrystalTypes.h"
#include "DataSet.h"
#include "Detector.h"
#include "DataReaderFactory.h"
#include "DetectorEvent.h"
#include "Diffractometer.h"
#include "Ellipsoid.h"
#include "Gonio.h"
#include "IDataReader.h"
#include "IntegrationRegion.h"
#include "Logger.h"
#include "Mask.h"
#include "MathematicsTypes.h"
#include "Monochromator.h"
#include "Path.h"
#include "Peak.h"
#include "PeakFilter.h"
#include "IPeakIntegrator.h"
#include "ProgressHandler.h"
#include "ReciprocalVector.h"
#include "Sample.h"
#include "Source.h"
#include "SpaceGroup.h"
#include "UnitCell.h"
#include "Units.h"

namespace nsx {

DataSet::DataSet(const std::string &filetype, const std::string &filename, Diffractometer *diffractometer)
{
    _nrows = diffractometer->detector()->nRows();
    _ncols = diffractometer->detector()->nCols();

    DataReaderFactory factory;

    auto* reader = factory.create(filetype,filename,diffractometer);

    _reader.reset(reader);

    _filename = reader->filename();

    _nFrames = _reader->metadata().key<int>("npdone");

    double wav = _reader->metadata().key<double>("wavelength");
    diffractometer->source().selectedMonochromator().setWavelength(wav);

    // Getting Scan parameters for the detector
    _states.reserve(_nFrames);

    for (unsigned int i=0;i<_nFrames;++i) {
        _states.push_back(_reader->state(i));
    }
}

DataSet::DataSet(const DataSet &other)
{
    _isOpened = other._isOpened;;

    _filename = other._filename;

    _nFrames = other._nFrames;

    _nrows = other._nrows;

    _ncols = other._ncols;

    _data = other._data;

    _states = other._states;

    for (auto m : other._masks) {
        _masks.insert(std::shared_ptr<Mask>(new Mask(*m)));
    }

    _iteratorCallback = other._iteratorCallback;

    _reader.reset(other._reader->clone());
}

DataSet::~DataSet()
{
    blosc_destroy();
}

DataSet& DataSet::operator=(const DataSet &other)
{
    if (this != &other) {
        _isOpened = other._isOpened;;
        _filename = other._filename;
        _nFrames = other._nFrames;
        _nrows = other._nrows;
        _ncols = other._ncols;
        _data = other._data;
        _states = other._states;

        for (auto m : other._masks) {
            _masks.insert(std::shared_ptr<Mask>(new Mask(*m)));
        }

        _iteratorCallback = other._iteratorCallback;
        _reader.reset(other._reader->clone());
    }
    return *this;
}


int DataSet::dataAt(unsigned int x, unsigned int y, unsigned int z)
{
    // Check that the voxel is inside the limit of the data
    if (z>=_nFrames || y>=_ncols || x>=_nrows) {
        return 0;
    }
    return frame(z)(x,y);
}

Eigen::MatrixXi DataSet::frame(std::size_t idx) const
{
    return _reader->data(idx);
}

Eigen::MatrixXd DataSet::convolvedFrame(std::size_t idx, const std::string& convolver_type, const std::map<std::string,int>& parameters)
{
    ConvolverFactory convolver_factory;
    auto convolver = convolver_factory.create(convolver_type,parameters);
    Eigen::MatrixXi frame_data = _reader->data(idx);
    return convolver->convolve(frame_data.cast<double>());
}

void DataSet::open()
{
    _reader->open();
}

void DataSet::close()
{
    _reader->close();
}

const std::string& DataSet::filename() const
{
    return _filename;
}

std::size_t DataSet::nFrames() const
{
    return _nFrames;
}

std::size_t DataSet::nCols() const
{
    return _ncols;
}

std::size_t DataSet::nRows() const
{
    return _nrows;
}

InterpolatedState DataSet::interpolatedState(double frame) const
{
    if (frame>(_states.size()-1) || frame<0) {
        throw std::runtime_error("Error when interpolating state: invalid frame value: " + std::to_string(frame));
    }

    const std::size_t idx = std::size_t(std::lround(std::floor(frame)));
    const std::size_t next = std::min(idx+1, _states.size()-1);
    const double t = frame-idx;

    const auto& nextState = _states[next];
    const auto& prevState = _states[idx];

    return InterpolatedState(prevState, nextState, t);
}

const std::vector<InstrumentState>& DataSet::instrumentStates() const
{
    return _states;
}

std::vector<InstrumentState>& DataSet::instrumentStates()
{
    return _states;
}

bool DataSet::isOpened() const
{
    return _isOpened;
}

void DataSet::saveHDF5(const std::string& filename) //const
{
    blosc_init();
    blosc_set_nthreads(4);

    hsize_t dims[3] = {_nFrames, _nrows,_ncols};
    hsize_t chunk[3] = {1, _nrows,_ncols};
    hsize_t count[3] = {1, _nrows,_ncols};

    H5::H5File file(filename.c_str(), H5F_ACC_TRUNC);
    H5::DataSpace space(3, dims, nullptr);
    H5::DSetCreatPropList plist;

    plist.setChunk(3, chunk);

    char *version, *date;
    int r;
    unsigned int cd_values[7];
    cd_values[4] = 9;       // Highest compression level
    cd_values[5] = 1;       // Bit shuffling active
    cd_values[6] = BLOSC_BLOSCLZ; // Seem to be the best compromise speed/compression for diffraction data

    r = register_blosc(&version, &date);
    if (r<=0) {
        throw std::runtime_error("Problem registering BLOSC filter in HDF5 library");
    }

    // caught by valgrind memcheck
    free(version); version = nullptr;
    free(date); date = nullptr;
    plist.setFilter(FILTER_BLOSC, H5Z_FLAG_OPTIONAL, 7, cd_values);

    H5::DataSpace memspace(3, count, nullptr);
    H5::Group dataGroup(file.createGroup("/Data"));
    H5::DataSet dset(dataGroup.createDataSet("Counts", H5::PredType::NATIVE_INT32, space, plist));

    hsize_t offset[3];
    offset[0] = 0;
    offset[1] = 0;
    offset[2] = 0;

    for(offset[0]=0; offset[0] < _nFrames; offset[0] += count[0]) {
        space.selectHyperslab(H5S_SELECT_SET, count, offset, nullptr, nullptr);
        // HDF5 requires row-major storage, so copy frame into a row-major matrix
        IntMatrix current_frame(frame(offset[0]));
        dset.write(current_frame.data(), H5::PredType::NATIVE_INT32, memspace, space);
    }

    // Saving the scans parameters (detector, sample and source)
    H5::Group scanGroup(dataGroup.createGroup("Scan"));

    // Write detector states
    H5::Group detectorGroup(scanGroup.createGroup("Detector"));

    hsize_t nf[1]={_nFrames};
    H5::DataSpace scanSpace(1,nf);

    const auto& detectorStates = _reader->detectorStates();

    const auto &detector_gonio = _reader->diffractometer()->detector()->gonio();
    size_t n_detector_gonio_axes = detector_gonio.nAxes();
    for (size_t i = 0; i < n_detector_gonio_axes; ++i) {
        const auto &axis = detector_gonio.axis(i);
        Eigen::VectorXd values(_nFrames);
        for (size_t j = 0; j < _nFrames; ++j) {
            auto&& v = detectorStates[j];
            values(j) = v[i] / deg;
        }
        H5::DataSet detectorScan(detectorGroup.createDataSet(axis.name(), H5::PredType::NATIVE_DOUBLE, scanSpace));
        detectorScan.write(&values(0), H5::PredType::NATIVE_DOUBLE, scanSpace, scanSpace);
    }

    // Write sample states
    H5::Group sampleGroup(scanGroup.createGroup("Sample"));

    const auto& sampleStates = _reader->sampleStates();

    const auto &sample_gonio = _reader->diffractometer()->sample().gonio();
    size_t n_sample_gonio_axes = sample_gonio.nAxes();;

    for (size_t i = 0; i < n_sample_gonio_axes; ++i) {
        const auto &axis = sample_gonio.axis(i);
        Eigen::VectorXd values(_nFrames);
        for (size_t j = 0; j < _nFrames; ++j) {
            auto&& v = sampleStates[j];
            values(j) = v[i]/deg;
        }
        H5::DataSet sampleScan(sampleGroup.createDataSet(axis.name(), H5::PredType::NATIVE_DOUBLE, scanSpace));
        sampleScan.write(&values(0), H5::PredType::NATIVE_DOUBLE, scanSpace, scanSpace);
    }

    const auto& map = _reader->metadata().map();

    // Write all string metadata into the "Info" group
    H5::Group infogroup(file.createGroup("/Info"));
    H5::DataSpace metaSpace(H5S_SCALAR);
    H5::StrType str80(H5::PredType::C_S1, 80);
    std::string info;

    for (const auto& item: map) {
        std::string info;

        try {
            info = item.second.as<std::string>();
            H5::Attribute intAtt(infogroup.createAttribute(item.first, str80, metaSpace));
            intAtt.write(str80, info);
        } catch(...) {
            // shouldn't there be some error handling here?
        }
    }

    // Write all other metadata (int and double) into the "Experiment" Group
    H5::Group metadatagroup(file.createGroup("/Experiment"));

    for (const auto& item: map)	{
        int value;

        try {
            value = item.second.as<int>();
            H5::Attribute intAtt(metadatagroup.createAttribute(item.first, H5::PredType::NATIVE_INT32, metaSpace));
            intAtt.write(H5::PredType::NATIVE_INT, &value);
        } catch(...) {
            try {
                double dvalue;
                dvalue = item.second.as<double>();
                H5::Attribute intAtt(metadatagroup.createAttribute(item.first, H5::PredType::NATIVE_DOUBLE, metaSpace));
                intAtt.write(H5::PredType::NATIVE_DOUBLE, &dvalue);
            } catch(...) {
                // shouldn't there be some error handling here?
            }
        }
    }
    file.close();

    blosc_destroy();
}

void DataSet::addMask(std::shared_ptr<Mask> mask)
{
    _masks.insert(mask);
}

void DataSet::removeMask(std::shared_ptr<Mask> mask)
{
    auto&& p = _masks.find(mask);
    if (p != _masks.end()) {
        _masks.erase(mask);
    }
}

const std::set<std::shared_ptr<Mask>>& DataSet::masks()
{
    return _masks;
}

std::vector<DetectorEvent> DataSet::events(const std::vector<ReciprocalVector>& sample_qs) const
{
    std::vector<DetectorEvent> events;  

    // return true if inside Ewald sphere, false otherwise
    auto compute_sign = [](const Eigen::RowVector3d& q, const InterpolatedState& state) -> bool
    {
        const Eigen::RowVector3d ki = state.ki().rowVector();
        const Eigen::RowVector3d kf = ki + q*state.sampleOrientationMatrix().transpose();
        return kf.squaredNorm() < ki.squaredNorm();
    };

    // lfor each sample q, determine the rotation that makes it intersect the Ewald sphere
    for (const ReciprocalVector& sample_q : sample_qs) {
        const Eigen::RowVector3d& q_vect = sample_q.rowVector();

        double f0 = 0.0;
        double f1 = nFrames()-1;

        auto state0 = interpolatedState(f0);
        auto state1 = interpolatedState(f1);

        bool s0 = compute_sign(q_vect, state0);
        bool s1 = compute_sign(q_vect, state1);

        // does not cross Ewald sphere, or crosses more than once
        if (s0 == s1) {
            continue;
        }

        // now use bisection method to compute intersection to good accuracy
        while (f1-f0 > 1e-10) {
            double f = 0.5*(f0+f1);
            auto state = interpolatedState(f);
            auto sign = compute_sign(q_vect, state);

            // branch right
            if (sign == s0) {
                s0 = sign;
                state0 = state;
                f0 = f;
            } 
            // branch left
            else {
                s1 = sign;
                state1 = state;
                f1 = f;
            }
        }

        // now f stores the frame value at the intersection
        const double f = 0.5*(f0+f1);
        const auto state = interpolatedState(f);
        Eigen::RowVector3d kf = state.ki().rowVector() + q_vect*state.sampleOrientationMatrix().transpose();
        const auto* detector = _reader->diffractometer()->detector();
        auto event = detector->constructEvent(DirectVector(state.samplePosition), ReciprocalVector((kf*state.detectorOrientation)));
        bool accept = event._tof > 0;

        if (accept) {
            event._frame = f;
            events.emplace_back(event);
        }       
    }
    return events;
}

ReciprocalVector DataSet::computeQ(const DetectorEvent& ev) const
{
    const auto& state = interpolatedState(ev._frame);
    const auto* detector = _reader->diffractometer()->detector();
    const auto& detector_position = DirectVector(detector->pixelPosition(ev._px, ev._py));
    return state.sampleQ(detector_position);
}

Eigen::MatrixXd DataSet::transformedFrame(std::size_t idx)
{
    const auto* detector = _reader->diffractometer()->detector();
    Eigen::ArrayXXd new_frame = frame(idx).cast<double>();
    new_frame -= detector->baseline();
    new_frame /= detector->gain();
    return new_frame;
}

const IDataReader* DataSet::reader() const
{
    return _reader.get();
}

IDataReader* DataSet::reader()
{
    return _reader.get();
}

} // end namespace nsx
