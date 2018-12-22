// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/data/FakeDataReader.cpp
//! @brief     Implements module/class/test FakeDataReader
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <memory>

#include "blosc.h"

#include "BloscFilter.h"
#include "Detector.h"
#include "Diffractometer.h"
#include "EigenToVector.h"
#include "Gonio.h"
#include "FakeDataReader.h"
#include "Sample.h"
#include "Source.h"
#include "Units.h"

namespace nsx {
 
FakeDataReader::FakeDataReader(const std::string& filename, Diffractometer *diffractometer)
    :HDF5MetaDataReader(filename, diffractometer)
{
    _frames.resize(_nFrames);

    for (size_t i = 0; i < _nFrames; ++i) {
        _frames[i].resize(_nRows, _nCols);
    }
}

IDataReader* FakeDataReader::clone() const
{
    return new FakeDataReader(*this);
}

Eigen::MatrixXi FakeDataReader::data(size_t frame)
{
    return _frames[frame];
}

void FakeDataReader::setData(size_t frame, const Eigen::MatrixXi& data)
{
    _frames[frame] = data;
}

} // end namespace nsx
