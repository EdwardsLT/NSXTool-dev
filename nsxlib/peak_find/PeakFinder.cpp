#include <utility>
#include <vector>

#include "AABB.h"
#include "ConvolverFactory.h"
#include "DataSet.h"
#include "Detector.h"
#include "Diffractometer.h"
#include "ErfInv.h"
#include "Experiment.h"
#include "GeometryTypes.h"
#include "MathematicsTypes.h"
#include "Octree.h"
#include "Peak3D.h"
#include "PeakFinder.h"
#include "ProgressHandler.h"
#include "Sample.h"
#include "StrongPeakIntegrator.h"

using EquivalencePair = std::pair<int,int>;
using EquivalenceList = std::vector<EquivalencePair>;

namespace {

    void registerEquivalence(int a, int b, EquivalenceList& equivalences)
    {
        if (a < b) {
            equivalences.emplace_back(EquivalenceList::value_type(b,a));
        } else {
            equivalences.emplace_back(EquivalenceList::value_type(a,b));
        }
    }

    bool sortEquivalences(const EquivalencePair& pa, const EquivalencePair& pb)
    {
        if (pa.first<pb.first) {
            return true;
        }
        if (pa.first>pb.first) {
            return false;
        }
        return (pa.second<pb.second);
    }

    std::map<int,int> removeDuplicates(EquivalenceList& equivalences)
    {
        auto beg = equivalences.begin();
        auto last = std::unique(equivalences.begin(),equivalences.end());

        std::map<int,int> mequiv;

        for (auto it = beg; it != last; ++it) {
            mequiv.insert(*it);
        }
        return mequiv;
    }

    void reassignEquivalences(std::map<int,int>& equivalences)
    {
        for (auto it = equivalences.begin(); it != equivalences.end(); ++it) {
            auto found = equivalences.find(it->second);
            if (found != equivalences.end()) {
                it->second = found->second;
            }
        }
    }

}

namespace nsx {

PeakFinder::PeakFinder()
: _handler(nullptr),
  _peakScale(1.0),  
  _current_label(0),
  _minSize(30),
  _maxSize(10000),
  _maxFrames(10),
  _threshold(3.0)
{
    ConvolverFactory convolver_factory;
    _convolver = convolver_factory.create("annular",{});
}

/*
 * blob finding stages:
 *
 * initialize
 * iterate through frames
 *    add to collection if new label
 *    register equivalences
 * merge equivalent blobs
 * register collisions
 * merge colliding blobs
 *
 */
PeakList PeakFinder::find(DataList numors)
{
    std::size_t npeaks=0;
    PeakList peaks;

    for (auto&& numor : numors) {
        PeakList numor_peaks;

        auto dectector = numor->diffractometer()->detector();
        int nrows = dectector->nRows();
        int ncols = dectector->nCols();
        int nframes = numor->nFrames();

        // The blobs found for this numor
        std::map<int,Blob3D> blobs;

        try {

            if ( _handler ) {
                _handler->log("min comp is " + std::to_string(_minSize));
                _handler->log("max comp is " + std::to_string(_maxSize));
                _handler->log("search scalee is " + std::to_string(_peakScale));
            }

            if (_handler) {
                _handler->log("kernel " + std::string(_convolver->name()) + " selected");
                for (auto& it: _convolver->parameters()) {
                    _handler->log(it.first + " " + std::to_string(it.second));
                }
            }

            _current_label = 0;

            #pragma omp parallel
            {
                int loop_begin = -1;
                int loop_end = -1;

                std::map<int,Blob3D> local_blobs = {{}};
                EquivalenceList local_equivalences;

                // determine begining and ending index of current thread
                #pragma omp for
                for (size_t i = 0; i < numor->nFrames(); ++i) {
                    if ( loop_begin == -1) {
                        loop_begin = i;
                    }
                    loop_end = i+1;
                }

                // find blobs within the current frame range
                findPrimaryBlobs(numor, local_blobs, local_equivalences, loop_begin, loop_end);

                // merge adjacent blobs
                mergeEquivalentBlobs(local_blobs, local_equivalences);

                #pragma omp critical
                {
                    // merge the blobs into the global set
                    for (auto&& blob: local_blobs) {
                        blobs.insert(blob);
                    }
                }
            }

            mergeCollidingBlobs(numor, blobs);

            if (_handler) {
                _handler->setStatus("Blob finding complete.");
                _handler->log("Blob finding complete.");
                _handler->log("Found " + std::to_string(blobs.size()) + " blobs");
                _handler->setProgress(100);
            }
        }
        // Warning if error
        catch(std::exception& e) {
            if ( _handler ) {
                _handler->log(std::string("Peak finder caused an exception: ") + e.what());
            }
            // pass exception back to callee
            throw e;
        }

        if (_handler ) {
            _handler->setStatus("Computing bounding boxes...");
            _handler->setProgress(0);
        }

        int count = 0;

        AABB dAABB(Eigen::Vector3d(0,0,0),
                   Eigen::Vector3d(ncols, nrows, nframes-1)
                    );

        for (auto& blob : blobs) {

            Eigen::Vector3d center, eigenvalues;
            Eigen::Matrix3d eigenvectors;

            blob.second.toEllipsoid(nsx::getConfidence(1.0), center, eigenvalues, eigenvectors);
            auto shape = Ellipsoid(center, eigenvalues, eigenvectors);

            auto p = sptrPeak3D(new Peak3D(numor, shape));
            const auto extents = p->getShape().aabb().extents();

            // peak too small or too large
            if (extents.maxCoeff() > 1e5 || extents.minCoeff() < 1e-5) {
                p->setSelected(false);
            }

            if (extents(2) > _maxFrames) {
                p->setSelected(false);
            }

            // peak's bounding box not completely contained in detector image
            if (!dAABB.contains(p->getShape().aabb())) {
                p->setSelected(false);
            }

            p->setPredicted(false);
            numor_peaks.push_back(p);
            peaks.push_back(p);

            npeaks++;
            ++count;

            if ( _handler ) {
                double progress = count * 100.0 / blobs.size();
                _handler->setProgress(progress);
            }
        }

        if (_handler) {
            _handler->setStatus(("Integrating " + std::to_string(numor_peaks.size()) + " peaks...").c_str());
            _handler->setProgress(0);
        }

        numor->close();
        if (_handler) {
            _handler->log("Found " + std::to_string(numor_peaks.size()) + " peaks.");
        }
    }

    if (_handler) {
        _handler->setStatus("Peak finding completed.");
        _handler->setProgress(100);
    }
    return peaks;
}

void PeakFinder::setHandler(const sptrProgressHandler& handler)
{
    _handler = handler;
}

void PeakFinder::setMaxFrames(int maxFrames)
{
    _maxFrames = maxFrames;
}

int PeakFinder::maxFrames() const
{
    return _maxFrames;
}

void PeakFinder::setMinSize(int size)
{
    _minSize = size;
}

int PeakFinder::minSize() const
{
    return _minSize;
}

void PeakFinder::setMaxSize(int size)
{
    _maxSize = size;
}

int PeakFinder::maxSize() const
{
    return _maxSize;
}

sptrConvolver PeakFinder::convolver() const
{
    return _convolver;
}

void PeakFinder::setConvolver(const std::string& convolver_type, const std::map<std::string,double>& parameters)
{
    ConvolverFactory convolver_factory;
    _convolver = convolver_factory.create(convolver_type,parameters);
}

void PeakFinder::setThreshold(double value)
{
    _threshold = value;
}

void PeakFinder::eliminateBlobs(std::map<int, Blob3D>& blobs) const
{
    // update progress handler
    if ( _handler ) {
        _handler->setStatus("Eliminating blobs which are too small or too large...");
        _handler->setProgress(0);
    }

    // dummies use to help progress handler
    int dummy = 0;
    int magic = 0.2 * std::distance(blobs.begin(), blobs.end());

    for (auto it = blobs.begin(); it != blobs.end();) {
        ++dummy;

        Blob3D& p=it->second;
        if (p.getComponents() < _minSize || p.getComponents() > _maxSize) {
            it = blobs.erase(it);
        } else {
            it++;
        }
        // update progress handler
        if ( (dummy&magic) == 0 && _handler) {
            double total_dist = std::distance(blobs.begin(), blobs.end());
            double current_dist = std::distance(blobs.begin(), it);
            double progress = 100.0 * current_dist / total_dist;
            _handler->setProgress(50 + 0.5*progress);
        }
    }

    if ( _handler ) {
        _handler->log("After elimination, " + std::to_string(blobs.size()) + " blobs remain");
        _handler->setProgress(100);
    }
}

void PeakFinder::mergeCollidingBlobs(sptrDataSet data, std::map<int,Blob3D>& blobs) const
{
    // serial section below
    size_t num_blobs;

    do {
        EquivalenceList equivalences;
        num_blobs = blobs.size();

        if (_handler) {
            _handler->log("number of blobs is " + std::to_string(num_blobs));
        }

        // determine which additional blobs should be merged due to collisions / intersection
        findCollisions(data, blobs, equivalences);
        // merge the remaining blobs
        mergeEquivalentBlobs(blobs, equivalences);
    } while (num_blobs != blobs.size());

    // remove blobs which are too small or too large
    eliminateBlobs(blobs);
}

void PeakFinder::findPrimaryBlobs(sptrDataSet data, std::map<int,Blob3D>& blobs,EquivalenceList& equivalences, size_t begin, size_t end)
{
    // update via handler if necessary
    if ( _handler ) {
        _handler->setStatus("Finding blobs...");
        _handler->setProgress(0);
    }

    auto dectector = data->diffractometer()->detector();
    int nrows = dectector->nRows();
    int ncols = dectector->nCols();

    // used to pass to progress handler
    double progress = 0.0;

    // this is the filter function to be applied to each frame
    auto convolve_frame = [&] (const RealMatrix& input) -> RealMatrix {
        RealMatrix output;
        #pragma omp critical
        output = _convolver->convolve(input);
        return output;
    };

    // Map of Blobs (key : label, value : blob)
    blobs.clear();

    nrows = data->nRows();
    ncols = data->nCols();

    // Store labels of current and previous frames.
    std::vector<int> labels(nrows*ncols,0);
    std::vector<int> labels2(nrows*ncols,0);

    // Create empty equivalence table
    equivalences.clear();
    equivalences.reserve(100000);

    // Labels of the left and top pixels with respect to current one and the one above in previous frame
    int left, top, previous;

    int label;
    bool newlabel;
    int index2D = 0;

    // int representing the 8 possible nearest neighbor operations.
    int code;

    int nframes(0);

    // Iterate on all pixels in the image
    // #pragma omp for schedule(dynamic, DYNAMIC_CHUNK)
    for (size_t idx = begin; idx < end; ++idx) {

        #pragma omp atomic
        ++nframes;

        RealMatrix frame_data;

        #pragma omp critical
        frame_data = data->frame(idx).cast<double>();

        auto filtered_frame = convolve_frame(frame_data);

        // Go the the beginning of data
        index2D=0;
        for (unsigned int row = 0; row < nrows; ++row) {
            for (unsigned int col = 0; col < ncols; ++col) {
                // Discard pixel if value < threshold
                if (filtered_frame(row, col) < _threshold) {
                    labels[index2D]=labels2[index2D]=0;
                    index2D++;
                    continue;
                }

                newlabel = false;

                // Get labels of adjacent pixels
                left= (col == 0 ? 0 : labels[index2D-1]);
                top=  (row == 0 ? 0 : labels[index2D-ncols]) ;
                previous= (idx == begin ? 0 : labels2[index2D]);
                // Encode type of config.
                code=0;
                code |= ( (left!=0) << 0);
                code |= ( (top!=0) << 1);
                code |= ( (previous!=0)  << 2);

                switch (code) {
                case 0:
                    #pragma omp critical
                    label = ++_current_label;
                    newlabel=true;
                    break;
                case 1: // Only left pixel
                    label=left;
                    break;
                case 2: // Only top pixel
                    label=top;
                    break;
                case 3: // Top and left
                    label=top;
                    if (top!=left)
                        registerEquivalence(top, left, equivalences);
                    break;
                case 4: // Only previous
                    label=previous;
                    break;
                case 5: // Left and previous
                    label=left;
                    if (left!=previous)
                        registerEquivalence(left, previous, equivalences);
                    break;
                case 6: // Top and previous
                    label=top;
                    if (top!=previous)
                        registerEquivalence(top, previous, equivalences);
                    break;
                case 7: // All three
                    label=left;
                    if ((top==left) && (top!=previous)) {
                        registerEquivalence(top, previous, equivalences);
                    }
                    else if ((top==previous) && (top!=left)) {
                        registerEquivalence(top, left, equivalences);
                    }
                    else if ((left==previous) && (left!=top)) {
                        registerEquivalence(left, top, equivalences);
                    }
                    else if ((left!=previous) && (left!=top) && (top!=previous)) {
                        registerEquivalence(top, previous, equivalences);
                        registerEquivalence(top, left, equivalences);
                        registerEquivalence(left, previous, equivalences);
                    }
                    break;
                default:
                    break;
                }
                // If none of the neighbors have labels, create new one

                labels[index2D] = labels2[index2D] = label;
                index2D++;
                auto value = frame_data(row, col);
                // Create a new blob if necessary
                if (newlabel) {
                    blobs.insert(std::make_pair(label,Blob3D(col,row,idx,value)));
                } else {
                    auto it = blobs.find(label);
                    it->second.addPoint(col,row,idx,value);
                }
            }
        }

        progress = static_cast<double>(nframes) / static_cast<double>(data->nFrames()) * 100.0;

        if (_handler )
            _handler->setProgress(progress);
    }

    if (_handler) {
        _handler->log("Found " + std::to_string(blobs.size()) + " blobs");
        _handler->setProgress(100);
    }
}

void PeakFinder::findCollisions(sptrDataSet data, std::map<int,Blob3D>& blobs, EquivalenceList& equivalences) const
{
    // Clear the equivalence vectors for reuse purpose
    equivalences.clear();

    // update progress handler
    if (_handler) {
        _handler->setStatus("Finding blob collisions...");
        _handler->setProgress(0);
    }

    // Determine the AABB of the blobs
    std::map<const Ellipsoid*,int> boxes;

    Eigen::Vector3d center,extents;
    Eigen::Matrix3d axis;

    // dummies used to help progress handler
    int dummy = 0;
    int magic =0.2 * std::distance(blobs.begin(), blobs.end());

    if (magic < 1) {
        magic = 1;
    }

    for (auto it = blobs.begin(); it != blobs.end();) {
        ++dummy;

        try {
            // toEllipsoid throws exception if mass is too small
            it->second.toEllipsoid(_peakScale,center,extents,axis);
        } catch(...) {
            it = blobs.erase(it);
            continue;
        }

        // if the threshold is too small it will break the OpenMP peak search
        // when the number of threads is very large
        if (extents.minCoeff()<1.0e-13) {
            it = blobs.erase(it);
            continue;
        }

        auto ellipse = new Ellipsoid(center,extents,axis);
        boxes.insert(std::make_pair(ellipse, it->first));
        it++;

        // update progress handler
        if ( (dummy % magic) == 0 && _handler) {
            double total_dist = std::distance(blobs.begin(), blobs.end());
            double current_dist = std::distance(blobs.begin(), it);
            double progress = 100.0 * current_dist / total_dist;
            _handler->setProgress(0.5*progress);
            _handler->log("blob loop: " + std::to_string(progress));
        }
    }

    auto dectector = data->diffractometer()->detector();
    int nrows = dectector->nRows();
    int ncols = dectector->nCols();
    int nframes = data->nFrames();

    Octree oct(Eigen::Vector3d(0.0,0.0,0.0),Eigen::Vector3d(double(ncols),double(nrows),double(nframes)));
    oct.setMaxDepth(6);
    oct.setMaxStorage(6);

    std::vector<const Ellipsoid*> xyz_sorted_ellipsoids;
    xyz_sorted_ellipsoids.reserve(boxes.size());
    for (auto&& it : boxes)
        xyz_sorted_ellipsoids.push_back(it.first);

    // Sort the ellipsoid by increasing x, y and z
    auto cmp = [](const Ellipsoid* ell1, const Ellipsoid* ell2) -> bool {
        auto&& c1 = ell1->center();
        auto&& c2 = ell2->center();

        if (c1[0] < c2[0]) return true;
        if (c1[0] > c2[0]) return false;

        if (c1[0] < c2[0]) return true;
        if (c1[0] > c2[0]) return false;

        if (c1[0] < c2[0]) return true;
        if (c1[0] > c2[0]) return false;

        return false;
    };
    std::sort(xyz_sorted_ellipsoids.begin(),xyz_sorted_ellipsoids.end(),cmp);

    for (auto it: xyz_sorted_ellipsoids) {
        oct.addData(it);
    }

    auto collisions = oct.getCollisions();

    // dummies used to help progress handler
    dummy = 0;
    magic = 0.02 * std::distance(collisions.begin(), collisions.end());

    if (magic < 1) {
        magic = 1;
    }

    for (auto&& it = collisions.begin(); it != collisions.end(); ++it) {

        auto&& bit1 = boxes.find(it->first);
        auto&& bit2 = boxes.find(it->second);
        registerEquivalence(bit1->second, bit2->second, equivalences);

        // update progress handler
        if ( (dummy % magic) == 0 && _handler) {
            const double total_dist = std::distance(collisions.begin(), collisions.end());
            const double current_dist = std::distance(collisions.begin(), it);
            const double progress = 100.0 * current_dist / total_dist;
            _handler->setProgress(50 + 0.5*progress);
        }
        ++dummy;
    }


    // calculation complete
    if (_handler) {
        _handler->log("Found " + std::to_string(equivalences.size()) + " equivalences");
        _handler->setProgress(100);
    }

    // free memory stored in unordered map
    for (auto&& it: boxes) {
        delete it.first;
    }
}

void PeakFinder::mergeEquivalentBlobs(std::map<int,Blob3D>& blobs, EquivalenceList& equivalences) const
{
    // initialize progress handler if necessary
    if (_handler) {
        _handler->setProgress(0);
    }

    // Sort the equivalences pair by ascending order of the first element
    // and if equal by ascending order of their second element.
    std::sort(equivalences.begin(), equivalences.end(), sortEquivalences);

    // Remove the duplicate pairs
    auto mequiv = removeDuplicates(equivalences);

    reassignEquivalences(mequiv);

    // dummy for calling progress updater
    int dummy = 0;
    int magic = 0.02 * std::distance(blobs.begin(), blobs.end());
    if ( magic == 0 ) {
        magic = 1;
    }

    // Iterate on blobs and merge equivalences
    for (auto it = blobs.begin(); it != blobs.end();) {
        ++dummy;

        auto match = mequiv.find(it->first);
        if (match == mequiv.end()) {
            // Nothing is found get to the next blob
            it++;
        } else {
            auto tomerge = blobs.find(match->second);
            // Should never be the case
            if (tomerge != blobs.end()) {
                tomerge->second.merge(it->second);
                it = blobs.erase(it);
            }
        }

        // update progress handler
        if ( (dummy%magic) == 0 && _handler) {
            double total_dist = std::distance(blobs.begin(), blobs.end());
            double current_dist = std::distance(blobs.begin(), it);
            int progress = static_cast<int>( 100.0 * current_dist / total_dist);
            _handler->setProgress(progress);
        }
    }

    // finalize update handler
    if ( _handler ) {
        _handler->log("After merging, " + std::to_string(blobs.size()) + " blobs remain.");
    }
}

} // end namespace nsx
