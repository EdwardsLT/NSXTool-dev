#include <utility>
#include <stdexcept>
#include <memory>

#include "../utils/Units.h"

#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>

#include "../data/IData.h"
#include "../instrument/Detector.h"
#include "../instrument/Gonio.h"
#include "../instrument/Monochromator.h"
#include "../instrument/Sample.h"
#include "../instrument/Source.h"

#include "H5Cpp.h"
#include "blosc_filter.h"
#include "blosc.h"
#include "../geometry/Ellipsoid.h"

#include "IFrameIterator.h"
#include "BasicFrameIterator.h"
#include "ThreadedFrameIterator.h"

namespace SX {
namespace Data {

using Eigen::Matrix3d;
using boost::filesystem::path;

IData::IData(std::string filename, std::shared_ptr<Diffractometer> diffractometer):
    _isOpened(false),
    _filename(std::move(filename)),
    _nFrames(0),
    _nrows(0),
    _ncols(0),
    _diffractometer(std::move(diffractometer)),
    _metadata(std::unique_ptr<MetaData>(new MetaData())),
    _data(),
    _states(),
    _peaks(),
    _fileSize(0),
    _masks(),
    _background(0.0)
{
    if ( !boost::filesystem::exists(_filename.c_str())) {
        throw std::runtime_error("IData, file: " + _filename + " does not exist");
    }

    _nrows = _diffractometer->getDetector()->getNRows();
    _ncols = _diffractometer->getDetector()->getNCols();
}

std::unique_ptr<IFrameIterator> IData::getIterator(int idx)
{
    // use default frame iterator if one hasn't been set
    if ( !_iteratorCallback) {
        _iteratorCallback = [] (IData& data, int index) {
            return new BasicFrameIterator(data, static_cast<unsigned int>(index));
            //return new ThreadedFrameIterator(data, index);
        };
    }
    return std::unique_ptr<IFrameIterator>(_iteratorCallback(*this, idx));
}

void IData::setIteratorCallback(FrameIteratorCallback callback)
{
    _iteratorCallback = std::move(callback);
}

IData::~IData()
{
    clearPeaks();
    blosc_destroy();
}

std::string IData::getBasename() const
{
    path pathname(_filename);
    return pathname.filename().string();
}


int IData::dataAt(unsigned int x, unsigned int y, unsigned int z)
{
    // Check that the voxel is inside the limit of the data
    if (z>=_nFrames || y>=_ncols || x>=_nrows) {
        return 0;
    }
    return getFrame(z)(x,y);
}

const std::string& IData::getFilename() const
{
    return _filename;
}

std::shared_ptr<Diffractometer> IData::getDiffractometer() const
{
    return _diffractometer;
}

MetaData*  IData::getMetadata() const
{
    return _metadata.get();
}

std::size_t IData::getNFrames() const
{
    return _nFrames;
}

std::size_t IData::getNCols() const
{
    return _ncols;
}

std::size_t IData::getNRows() const
{
    return _nrows;
}

std::set<sptrPeak3D>& IData::getPeaks()
{
    return _peaks;
}

void IData::addPeak(const sptrPeak3D& peak)
{
    _peaks.insert(peak);
    maskPeak(peak);
}

void IData::clearPeaks()
{
    for (auto&& ptr : _peaks) {
        ptr->unlinkData();
    }
    _peaks.clear();
}

ComponentState IData::getInterpolatedState(std::shared_ptr<Component> component, double frame) const
{
    if (frame>(_states.size()-1) || frame<0) {
        throw std::runtime_error("Error when interpolating state: invalid frame value");
    }

    std::size_t idx = static_cast<std::size_t>(std::floor(frame));
    std::size_t next = std::min(idx+1, _states.size()-1);
    std::size_t nPhysicalAxes=component->getGonio()->getNPhysicalAxes();

    const std::vector<double>& prevState=_states[idx].detector.getValues();
    const std::vector<double>& nextState=_states[next].detector.getValues();
    std::vector<double> state(nPhysicalAxes);

    for (std::size_t i=0; i < nPhysicalAxes; ++i) {
        state[i] = prevState[i] + (frame-static_cast<double>(idx))*(nextState[i]-prevState[i]);
    }
    return component->createState(state);
}

const ComponentState& IData::getDetectorState(size_t frame) const
{
    if (frame > (_states.size()-1)) {
        throw std::runtime_error("Error when returning detector state: invalid frame value");
    }
    return _states[frame].detector;
}

const ComponentState& IData::getSampleState(size_t frame) const
{
    if (frame > (_states.size()-1)) {
        throw std::runtime_error("Error when returning sample state: invalid frame value");
    }
    return _states[frame].sample;
}

const ComponentState& IData::getSourceState(size_t frame) const
{
    if (frame>(_states.size()-1)) {
        throw std::runtime_error("Error when returning source state: invalid frame value");
    }
    return _states[frame].source;
}


const std::vector<SX::Instrument::InstrumentState>& IData::getInstrumentStates() const
{
    return _states;
}

bool IData::removePeak(const sptrPeak3D& peak)
{
    auto&& it=_peaks.find(peak);

    if (it == _peaks.end()) {
        return false;
    }
    _peaks.erase(it);
    return true;
}

bool IData::isOpened() const
{
    return _isOpened;
}

std::size_t IData::getFileSize() const
{
    return _fileSize;
}

void IData::saveHDF5(const std::string& filename) //const
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
        RowMatrixi frame(getFrame(offset[0]));
        dset.write(frame.data(), H5::PredType::NATIVE_INT32, memspace, space);
    }

    // Saving the scans parameters (detector, sample and source)
    H5::Group scanGroup(dataGroup.createGroup("Scan"));

    // Write detector states
    H5::Group detectorGroup(scanGroup.createGroup("Detector"));

    std::vector<std::string> names=_diffractometer->getDetector()->getGonio()->getPhysicalAxesNames();
    hsize_t nf[1]={_nFrames};
    H5::DataSpace scanSpace(1,nf);
    RowMatrixd vals(names.size(),_nFrames);

    for (unsigned int i = 0; i < _states.size(); ++i) {
        const std::vector<double>& v = _states[i].detector.getValues();

        for (unsigned int j = 0; j < names.size(); ++j) {
            vals(j,i) = v[j] / SX::Units::deg;
        }
    }

    for (unsigned int j = 0; j < names.size(); ++j) {
        H5::DataSet detectorScan(detectorGroup.createDataSet(names[j], H5::PredType::NATIVE_DOUBLE, scanSpace));
        detectorScan.write(&vals(j,0), H5::PredType::NATIVE_DOUBLE, scanSpace, scanSpace);
    }

    // Write sample states
    H5::Group sampleGroup(scanGroup.createGroup("Sample"));
    std::vector<std::string> samplenames=_diffractometer->getSample()->getGonio()->getPhysicalAxesNames();
    RowMatrixd valsSamples(samplenames.size(), _nFrames);

    for (unsigned int i = 0; i < _states.size(); ++i) {
        const std::vector<double>& v = _states[i].sample.getValues();

        for (unsigned int j = 0; j < samplenames.size(); ++j) {
            valsSamples(j,i) = v[j]/SX::Units::deg;
        }
    }

    for (unsigned int j = 0; j < samplenames.size(); ++j) {
        H5::DataSet sampleScan(sampleGroup.createDataSet(samplenames[j], H5::PredType::NATIVE_DOUBLE, scanSpace));
        sampleScan.write(&valsSamples(j,0), H5::PredType::NATIVE_DOUBLE, scanSpace, scanSpace);
    }

    // Write source states
    H5::Group sourceGroup(scanGroup.createGroup("Source"));
    std::vector<std::string> sourcenames = _diffractometer->getSource()->getGonio()->getPhysicalAxesNames();
    RowMatrixd valsSources(sourcenames.size(),_nFrames);

    for (unsigned int i = 0; i < _states.size(); ++i) {
        const std::vector<double>& v=_states[i].source.getValues();

        for (unsigned int j = 0; j < sourcenames.size(); ++j) {
            valsSources(j,i) = v[j] / SX::Units::deg;
        }
    }

    for (unsigned int j = 0; j < sourcenames.size(); ++j) {
        H5::DataSet sourceScan(sourceGroup.createDataSet(sourcenames[j], H5::PredType::NATIVE_DOUBLE, scanSpace));
        sourceScan.write(&valsSources(j,0), H5::PredType::NATIVE_DOUBLE, scanSpace, scanSpace);
    }

    const auto& map=_metadata->getMap();

    // Write all string metadata into the "Info" group
    H5::Group infogroup(file.createGroup("/Info"));
    H5::DataSpace metaSpace(H5S_SCALAR);
    H5::StrType str80(H5::PredType::C_S1, 80);
    std::string info;

    for (const auto& item: map) {
        std::string info;

        try {
            info = boost::any_cast<std::string>(item.second);
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
            value = boost::any_cast<int>(item.second);
            H5::Attribute intAtt(metadatagroup.createAttribute(item.first, H5::PredType::NATIVE_INT32, metaSpace));
            intAtt.write(H5::PredType::NATIVE_INT, &value);
        } catch(...) {
            try {
                double dvalue;
                dvalue = boost::any_cast<double>(item.second);
                H5::Attribute intAtt(metadatagroup.createAttribute(item.first, H5::PredType::NATIVE_DOUBLE, metaSpace));
                intAtt.write(H5::PredType::NATIVE_DOUBLE, &dvalue);
            } catch(...) {
                // shouldn't there be some error handling here?
            }
        }
    }
    file.close();
    // blosc_destroy();
}

void IData::addMask(AABB<double,3>* mask)
{
    _masks.insert(mask);
    maskPeaks();
}

void IData::removeMask(AABB<double,3>* mask)
{
    auto&& p = _masks.find(mask);
    if (p != _masks.end()) {
        _masks.erase(mask);
    }
    maskPeaks();
}

const std::set<AABB<double, 3> *>& IData::getMasks()
{
    return _masks;
}

void IData::maskPeaks() const
{
    for (auto&& p : _peaks) {
        maskPeak(p);
    }
}

void IData::maskPeak(sptrPeak3D peak) const
{
    peak->setMasked(false);
    for (auto&& m : _masks) {
        // If the background of the peak intercept the mask, unselected the peak
        if (m->intercept(peak->getBackground())) {
            peak->setMasked(true);
            break;
        }
    }
}

bool IData::inMasked(const Eigen::Vector3d& point) const
{
    // Loop over the defined masks and return true if one of them contains the point
    for (auto&& m : _masks) {
        if (m->isInsideAABB(point)) {
            return true;
        }
    }
    // No mask contains the point, return false
    return false;
}

std::vector<PeakCalc> IData::hasPeaks(const std::vector<Eigen::Vector3d>& hkls, const Matrix3d& BU)
{
    std::vector<PeakCalc> peaks;
    unsigned int scanSize = static_cast<unsigned int>(_states.size());
    Eigen::Matrix3d UB = BU.transpose();
    auto& mono = _diffractometer->getSource()->getSelectedMonochromator();
    Eigen::Vector3d ki=mono.getKi();
    std::vector<Eigen::Matrix3d> rotMatrices;
    rotMatrices.reserve(scanSize);
    auto gonio = _diffractometer->getSample()->getGonio();
    double wavelength_2 = -0.5 * mono.getWavelength();

    for (unsigned int s=0; s<scanSize; ++s) {
        rotMatrices.push_back(gonio->getHomMatrix(_states[s].sample.getValues()).rotation());
    }

    for (const Eigen::Vector3d& hkl: hkls) {
        // Get q at rest
        Eigen::Vector3d q=UB*hkl;

        double normQ2=q.squaredNorm();
        // y component of q when in Bragg condition y=-sin(theta)*||Q||
        double qy=normQ2*wavelength_2;

        Eigen::Vector3d qi0=rotMatrices[0]*q;
        Eigen::Vector3d qi;

        bool sign = (qi0[1] > qy);
        bool found = false;
        unsigned int i;

        for (i = 1; i < scanSize; ++i) {
            qi=rotMatrices[i]*q;
            bool sign2=(qi[1] > qy);
            if (sign != sign2) {
                found = true;
                break;
            }
            qi0 = qi;
        }

        if (!found) {
            continue;
        }
        double t = (qy-qi0[1]) / (qi[1]-qi0[1]);
        Eigen::Vector3d kf=ki+qi0+(qi-qi0)*t;
        t+=(i-1);

        ComponentState dis=getInterpolatedState(_diffractometer->getDetector(),t);
        double px,py;
        // If hit detector, new peak
        ComponentState cs=getInterpolatedState(_diffractometer->getSample(),t);
        Eigen::Vector3d from=_diffractometer->getSample()->getPosition(cs.getValues());

        double time;
        bool accept=_diffractometer->getDetector()->receiveKf(px,py,kf,from,time,dis.getValues());

        if (accept) {
            //peaks.emplace_back(PeakCalc(hkl[0],hkl[1],hkl[2],px,py,t));
            peaks.emplace_back(hkl[0],hkl[1],hkl[2],px,py,t);
        }
    }
    return peaks;
}

double IData::getBackgroundLevel(const std::shared_ptr<SX::Utils::ProgressHandler>& progress)
{
    if ( _background > 0.0 ) {
        return _background;
    }

    // we calculate background in local variable bg for thread safety reasons--
    // this method is called from a thread which could be aborted, so we do not want
    // to write to _background until the calculation has been completed
    double bg = 0.0;
    double factor = 1.0 / (_nFrames * _nrows * _ncols);

    if ( progress) {
        progress->setStatus("Computing background level...");
        progress->setProgress(0);
    }

    for (auto it = getIterator(0); it->index() != _nFrames; it->advance()) {
        // cast matrix to double (instead of int) -- necessary due to integer overflow!
        // _background += factor * it->cast<double>().sum();
        bg += factor * it->getFrame().sum();

        if (progress) {
            double done = 100.0 * it->index() / static_cast<double>(_nFrames);
            progress->setProgress(int(done));
        }
    }

    if ( progress ) {
        progress->setProgress(100);
    }

    _background = bg;
    return _background;
}

void IData::integratePeaks(const std::shared_ptr<Utils::ProgressHandler>& handler)
{
    if (handler) {
        handler->setStatus(("Integrating " + std::to_string(getPeaks().size()) + " peaks...").c_str());
        handler->setProgress(0);
    }

    std::set<sptrPeak3D>& peaks = getPeaks();

    for (auto&& peak: peaks ) {
        peak->framewiseIntegrateBegin();
    }

    //progressDialog->setValue(0);
    //progressDialog->setLabelText("Integrating peak intensities...");

    size_t idx = 0;
    int num_frames_done = 0;

    #pragma omp parallel for
    for ( idx = 0; idx < getNFrames(); ++idx ) {
        Eigen::MatrixXi frame;
        #pragma omp critical
        frame = getFrame(idx);

        for ( auto& peak: peaks ) {
            peak->framewiseIntegrateStep(frame, idx);
        }

        if (handler) {
            #pragma omp atomic
            ++num_frames_done;
            double progress = num_frames_done * 100.0 / getNFrames();
            handler->setProgress(progress);
        }
    }

    for (auto&& peak: peaks) {
        peak->framewiseIntegrateEnd();
    }
}

} // end namespace Data
} // end namespace SX
