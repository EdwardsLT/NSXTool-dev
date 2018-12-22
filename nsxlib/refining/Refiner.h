// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/refining/Refiner.h
//! @brief     Implements module/class/test Refiner
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <vector>

#include "CrystalTypes.h"
#include "InstrumentTypes.h"
#include "RefinementBatch.h"

namespace nsx {

//! \class Refiner
//! \brief Class used to refine lattice and instrument parameters.
class Refiner {
public:
    //! Construct an instance to refine the given cell based on the given peak list, using
    //! the given number of frame batches. The peaks must belong to the same dataset.
    Refiner(InstrumentStateList& states, sptrUnitCell cell, const PeakList& peaks, int nbatches);
    //! Set the lattice B matrix to be refined.
    void refineUB();
    //! Set detector offsets in the given list of instrument states to be refined.
    void refineDetectorOffset();
    //! Set the sample position in the given list of instrument states to be refined.
    void refineSamplePosition();
    //! Set the sample orientation in the given list of instrument states to be refined.
    void refineSampleOrientation();
    //! Set the source ki in the given list of instrument states to be refined.
    void refineKi();
    //! Perform the refinement with the maximum number of iterations as given.
    bool refine(unsigned int max_iter = 100);
    //! Update the centers of predicted peaks, after refinement.
    int updatePredictions(PeakList& peaks) const;
    //! Return the individual peak/frame batches used during refinement.
    const std::vector<RefinementBatch>& batches() const;

private:

    sptrUnitCell _cell;

    std::vector<RefinementBatch> _batches;
};

} // end namespace nsx
