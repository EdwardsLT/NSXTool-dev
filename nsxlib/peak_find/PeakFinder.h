// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/PeakFinder.h
//! @brief     Implements module/class/test PeakFinder
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <memory>

#include "Blob3D.h"
#include "IConvolver.h"
#include "CrystalTypes.h"
#include "DataTypes.h"
#include "GeometryTypes.h"
#include "ITask.h"
#include "UtilsTypes.h"

namespace nsx {

//! \brief Class to handle peak search in datasets
//! The algorithm used is based on connected component labelling
//! see https://en.wikipedia.org/wiki/Connected-component_labeling#Two-pass for info
class PeakFinder : public ITask {

public:

    PeakFinder(const DataList &datasets);

    bool doTask() final;

    void setPeakMergingScale(double scale);

    void setMinSize(int minComp);
    int minSize() const;

    void setMaxSize(int maxComp);
    int maxSize() const;

    void setMaxFrames(int maxComp);
    int maxFrames() const;

    const PeakList& peaks() const;

#ifndef SWIG
    void setConvolver(std::unique_ptr<IConvolver> convolver);
#endif

    void setConvolver(const IConvolver& convolver);

    void setThreshold(double value);

private:

    void eliminateBlobs(std::map<int, Blob3D>& blobs) const;

    void findPrimaryBlobs(const DataSet &data, std::map<int,Blob3D>& blobs,EquivalenceList& equivalences, size_t begin, size_t end);

    void findCollisions(const DataSet &data, std::map<int,Blob3D>& blobs, EquivalenceList& equivalences) const;

    void mergeCollidingBlobs(const DataSet &data, std::map<int,Blob3D>& blobs) const;

    void mergeEquivalentBlobs(std::map<int,Blob3D>& blobs, EquivalenceList& equivalences) const;

private:

    std::unique_ptr<IConvolver> _convolver;

    DataList _datasets;

    double _threshold;

    double _peak_merging_scale;

    int _current_label;

    int _minSize;

    int _maxSize;

    int _maxFrames;

    PeakList _peaks;
};

} // end namespace nsx
