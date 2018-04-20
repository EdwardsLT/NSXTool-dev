#include <iostream>
#include <unordered_map>

#include "Macros.h"
#include "BlobFinder.h"
#include "DataSet.h"
#include "IFrameIterator.h"
#include "Octree.h"
#include "ProgressHandler.h"

namespace nsx {

void BlobFinder::registerEquivalence(int a, int b, EquivalenceList& equivalences)
{
    if (a < b) {
        equivalences.emplace_back(EquivalenceList::value_type(b,a));
    } else {
        equivalences.emplace_back(EquivalenceList::value_type(a,b));
    }
}

bool BlobFinder::sortEquivalences(const EquivalencePair& pa, const EquivalencePair& pb)
{
    if (pa.first<pb.first) {
        return true;
    }
    if (pa.first>pb.first) {
        return false;
    }
    return (pa.second<pb.second);
}

std::map<int,int> BlobFinder::removeDuplicates(EquivalenceList& equivalences)
{
    auto beg = equivalences.begin();
    auto last = std::unique(equivalences.begin(),equivalences.end());

    std::map<int,int> mequiv;

    for (auto it = beg; it != last; ++it) {
        mequiv.insert(*it);
    }
    return mequiv;
}

void BlobFinder::reassignEquivalences(std::map<int,int>& equivalences)
{
    for (auto it = equivalences.begin(); it != equivalences.end(); ++it) {
        auto found = equivalences.find(it->second);
        if (found != equivalences.end()) {
            it->second = found->second;
        }
    }
}


void BlobFinder::eliminateBlobs(std::unordered_map<int, Blob3D>& blobs) const
{
    // update progress handler
    if ( _progressHandler ) {
        _progressHandler->setStatus("Eliminating blobs which are too small or too large...");
        _progressHandler->setProgress(0);
    }

    // dummies use to help progress handler
    int dummy = 0;
    int magic = int(0.2 * std::distance(blobs.begin(), blobs.end()));

    for (auto it = blobs.begin(); it != blobs.end();) {
        ++dummy;

        Blob3D& p=it->second;
        if (p.getComponents() < _minComp || p.getComponents() > _maxComp) {
            it = blobs.erase(it);
        } else {
            it++;
        }
        // update progress handler
        if ( (dummy&magic) == 0 && _progressHandler) {
            auto total_dist = std::distance(blobs.begin(), blobs.end());
            auto current_dist = std::distance(blobs.begin(), it);
            double progress = 100.0 * current_dist / double(total_dist);
            _progressHandler->setProgress(int(50 + 0.5*progress));
        }
    }

    if ( _progressHandler ) {
        _progressHandler->log("After elimination, " + std::to_string(blobs.size()) + " blobs remain");
        _progressHandler->setProgress(100);
    }
}

    /*
     * blob finding stages:
     *
     * initialize
     * iterate through frames
     *  add to collection if new label
     *  register equivalences
     * merge equivalences
     * register collisions
     * merge collisions
     *
     */
Blob3DUMap BlobFinder::find() {

    // find all blobs, possibly with multiple labels
    std::unordered_map<int,Blob3D> blobs;

    _nframes = 0;
    _currentlabel = 0;

    #pragma omp parallel
    {
        int loop_begin = -1;
        int loop_end = -1;

        std::unordered_map<int,Blob3D> local_blobs = {{}};
        EquivalenceList local_equivalences;

        // determine begining and ending index of current thread
        #pragma omp for
        for (size_t i = 0; i < _data->nFrames(); ++i) {
            if ( loop_begin == -1) {
                loop_begin = i;
            }
            loop_end = i+1;
        }

        // find blobs within the current frame range
        findBlobs(local_blobs, local_equivalences, loop_begin, loop_end);

        // merge adjacent blobs
        mergeBlobs(local_blobs, local_equivalences);

        // remove blobs which are too small or too large
        // eliminateBlobs(local_blobs);

        #pragma omp critical
        {
            // merge the blobs into the global set
            for (auto&& blob: local_blobs) {
                blobs.insert(blob);
            }
        }
    }

    // serial section below
    size_t num_blobs;

    do {
        EquivalenceList equivalences;
        num_blobs = blobs.size();

        if (_progressHandler) {
            _progressHandler->log("number of blobs is " + std::to_string(num_blobs));
        }

        // determine which additional blobs should be merged due to collisions / intersection
        findCollisions(blobs, equivalences);
        // merge the remaining blobs
        mergeBlobs(blobs, equivalences);
    } while (num_blobs != blobs.size());

    // remove blobs which are too small or too large
    eliminateBlobs(blobs);

    if (_progressHandler) {
        _progressHandler->setStatus("Blob finding complete.");
        _progressHandler->log("Blob finding complete.");
        _progressHandler->setProgress(100);
    }

    return blobs;
}

void BlobFinder::findBlobs(std::unordered_map<int,Blob3D>& blobs,
                           EquivalenceList& equivalences,
                           unsigned int begin, unsigned int end)
{
    // update via handler if necessary
    if ( _progressHandler ) {
        _progressHandler->setStatus("Finding blobs...");
        _progressHandler->setProgress(0);
    }

    // used to pass to progress handler
    double progress = 0.0;

    auto callback = _filterCallback;

    // threshold for blob addition
    double threshold = _isRelative ? _threshold*_median : _threshold;

    // Number of frames
    //_nframes = 0;

    // Map of Blobs (key : label, value : blob)
    blobs.clear();
    blobs.reserve(1000000);

    // determine the number of rows and columns
    // auto frame_it = _data->getIterator(begin);
    _nrows = _data->nRows();
    _ncols = _data->nCols();

    // Store labels of current and previous frames.
    std::vector<int> labels(_nrows*_ncols,0);
    std::vector<int> labels2(_nrows*_ncols,0);

    // Create empty equivalence table
    equivalences.clear();
    equivalences.reserve(100000);

    // Labels of the left and top pixels with respect to current one and the one above in previous frame
    int left, top, previous;

    //int currentlabel=0;
    // initialize currentlabel to begin so that parallel version of algorithm works
    // int currentlabel = begin;

    int label;
    bool newlabel;
    int index2D = 0;

    // int representing the 8 possible nearest neighbor operations.
    int code;

    // Iterate on all pixels in the image
    // #pragma omp for schedule(dynamic, DYNAMIC_CHUNK)
    for (size_t idx = begin; idx < end; ++idx) {

        #pragma omp atomic
        ++_nframes;

        RealMatrix frame_data;

        #pragma omp critical
        frame_data = _data->frame(idx).cast<double>();

        auto filtered_frame = callback ? callback(frame_data) : frame_data;

        // Go the the beginning of data
        index2D=0;
        for (unsigned int row = 0; row < _nrows; ++row) {
            for (unsigned int col = 0; col < _ncols; ++col) {
                auto value = frame_data(row, col);
                //auto filterd_value = filtered_frame(row, col);

                // Discard pixel if value < threshold
                if (filtered_frame(row, col) < threshold) {
                    labels[index2D]=labels2[index2D]=0;
                    index2D++;
                    continue;
                }

                newlabel=false;
                // Get labels of adjacent pixels
                left= (col == 0 ? 0 : labels[index2D-1]);
                top=  (row == 0 ? 0 : labels[index2D-_ncols]) ;
                previous= (idx == begin ? 0 : labels2[index2D]);
                // Encode type of config.
                code=0;
                code |= ( (left!=0) << 0);
                code |= ( (top!=0) << 1);
                code |= ( (previous!=0)  << 2);

                switch (code) {
                case 0:
                    #pragma omp critical
                    label = ++_currentlabel;
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

                labels[index2D]=labels2[index2D]=label;
                index2D++;
                // Create a new blob if necessary
                if (newlabel) {
                    blobs.insert(Blob3DUMap::value_type(label,Blob3D(col,row,double(idx),value)));
                } else {
                    auto it = blobs.find(label);
                    it->second.addPoint(col,row,double(idx),value);
                }
            }
        }

        progress = static_cast<double>(_nframes) / static_cast<double>(_data->nFrames()) * 100.0;

        if ( _progressHandler ) {
            _progressHandler->setProgress(int(progress));
        }
    }

    if (_progressHandler) {
        _progressHandler->log("Found " + std::to_string(blobs.size()) + " blobs");
        _progressHandler->setProgress(100);
    }
}

void BlobFinder::setProgressHandler(sptrProgressHandler callback)
{
    _progressHandler = callback;
}

void BlobFinder::setThreshold(double threshold)
{
    _threshold = threshold;
}

void BlobFinder::setScale(double scale)
{
    _scale = scale;
}

void BlobFinder::setMedian(double median)
{
    _median = median;
}

void BlobFinder::setMinComp(int minComp)
{
    _minComp = minComp;
}

void BlobFinder::setMaxComp(int maxComp)
{
    _maxComp = maxComp;
}

void BlobFinder::setRelative(bool isRelative)
{
    _isRelative = isRelative;
}

void BlobFinder::findCollisions(std::unordered_map<int,Blob3D>& blobs, EquivalenceList& equivalences) const
{
    // Clear the equivalence vectors for reuse purpose
    equivalences.clear();

    // update progress handler
    if (_progressHandler) {
        _progressHandler->setStatus("Finding blob collisions...");
        _progressHandler->setProgress(0);
    }

    // Determine the AABB of the blobs
    std::unordered_map<const Ellipsoid*,int> boxes;
    boxes.reserve(blobs.size());

    Eigen::Vector3d center,extents;
    Eigen::Matrix3d axis;

    // dummies used to help progress handler
    int dummy = 0;
    int magic = int(0.2 * std::distance(blobs.begin(), blobs.end()));

    if (magic < 1) {
        magic = 1;
    }

    for (auto it = blobs.begin(); it != blobs.end();) {
        ++dummy;

        try {
            // toEllipsoid throws exception if mass is too small
            it->second.toEllipsoid(_scale,center,extents,axis);
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
        if ( (dummy % magic) == 0 && _progressHandler) {
            auto total_dist = std::distance(blobs.begin(), blobs.end());
            auto current_dist = std::distance(blobs.begin(), it);
            double progress = 100.0 * current_dist / double(total_dist);
            _progressHandler->setProgress(int(0.5*progress));
            _progressHandler->log("blob loop: " + std::to_string(progress));
        }
    }

    Octree oct(Eigen::Vector3d(0.0,0.0,0.0),Eigen::Vector3d(double(_ncols),double(_nrows),double(_nframes)));
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
    magic = int(0.02 * std::distance(collisions.begin(), collisions.end()));

    if (magic < 1) {
        magic = 1;
    }

    for (auto&& it = collisions.begin(); it != collisions.end(); ++it) {

        auto&& bit1 = boxes.find(it->first);
        auto&& bit2 = boxes.find(it->second);
        registerEquivalence(bit1->second, bit2->second, equivalences);

        // update progress handler
        if ( (dummy % magic) == 0 && _progressHandler) {
            auto total_dist = std::distance(collisions.begin(), collisions.end());
            auto current_dist = std::distance(collisions.begin(), it);
            const double progress = 100.0 * current_dist / double(total_dist);
            _progressHandler->setProgress(int(50 + 0.5*progress));
        }
        ++dummy;
    }


    // calculation complete
    if ( _progressHandler ) {
        _progressHandler->log("Found " + std::to_string(equivalences.size()) + " equivalences");
        _progressHandler->setProgress(100);
    }

    // free memory stored in unordered map
    for (auto&& it: boxes) {
        delete it.first;
    }
}

void BlobFinder::setFilter(FilterCallback callback)
{
    _filterCallback = callback;
}

/**/

BlobFinder::BlobFinder(sptrDataSet data)
{
    _data = data;
}


void BlobFinder::mergeBlobs(std::unordered_map<int,Blob3D>& blobs, EquivalenceList& equivalences) const
{
    // initialize progress handler if necessary
    std::cout << "Merging blobs..." << std::endl;
    if (_progressHandler) {
        _progressHandler->setProgress(0);
    }

    // Sort the equivalences pair by ascending order of the first element
    // and if equal by ascending order of their second element.
    std::sort(equivalences.begin(), equivalences.end(), sortEquivalences);

    // Remove the duplicate pairs
    auto mequiv = removeDuplicates(equivalences);

    reassignEquivalences(mequiv);

    // dummy for calling progress updater
    int dummy = 0;
    int magic = int(0.02 * std::distance(blobs.begin(), blobs.end()));
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
        if ( (dummy%magic) == 0 && _progressHandler) {
            auto total_dist = std::distance(blobs.begin(), blobs.end());
            auto current_dist = std::distance(blobs.begin(), it);
            int progress = static_cast<int>( 100.0 * current_dist / double(total_dist));
            _progressHandler->setProgress(progress);
        }
    }

    // finalize update handler
    if ( _progressHandler ) {
        _progressHandler->log("After merging, " + std::to_string(blobs.size()) + " blobs remain.");
        _progressHandler->setProgress(100);
    }
}

} // end namespace nsx
