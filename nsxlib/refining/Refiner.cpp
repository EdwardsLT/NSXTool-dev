// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/refining/Refiner.cpp
//! @brief     Implements module/class/test Refiner
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <algorithm>
#include <iterator>

#include "CrystalTypes.h"
#include "DataSet.h"
#include "DetectorEvent.h"
#include "InstrumentState.h"
#include "MillerIndex.h"
#include "Peak.h"
#include "PeakFilter.h"
#include "Refiner.h"
#include "UnitCell.h"

namespace nsx {

Refiner::Refiner(InstrumentStateList& states, sptrUnitCell cell, const PeakList& peaks, int nbatches)
: _batches(), _cell(cell)
{

    PeakFilter peak_filter;
    PeakList filtered_peaks;
    filtered_peaks = peak_filter.enabled(peaks,true);
    filtered_peaks = peak_filter.indexed(filtered_peaks,*cell,cell->indexingTolerance());

    auto sort_peaks_by_frame = [](sptrPeak p1, sptrPeak p2) -> bool {
        auto&& c1 = p1->shape().center();
        auto&& c2 = p2->shape().center();
        return c1[2] < c2[2];
    };

    std::sort(filtered_peaks.begin(),filtered_peaks.end(),sort_peaks_by_frame);

    double batch_size = filtered_peaks.size() / double(nbatches);
    size_t current_batch = 0;

    PeakList peaks_subset;

    for (size_t i = 0; i < filtered_peaks.size(); ++i) {
        peaks_subset.push_back(filtered_peaks[i]);

        if (i + 1.1 >= (current_batch+1)*batch_size) {
            RefinementBatch b(states,*cell, peaks_subset);
            _batches.emplace_back(std::move(b));
            peaks_subset.clear();
            ++current_batch;
        }
    }
}

void Refiner::refineDetectorOffset()
{
    for (auto&& batch: _batches) {
        batch.refineDetectorOffset();
    }
}

void Refiner::refineSamplePosition()
{
    for (auto&& batch: _batches) {
        batch.refineSamplePosition();
    }
}

void Refiner::refineSampleOrientation()
{
    for (auto&& batch: _batches) {
        batch.refineSampleOrientation();
    }
}

void Refiner::refineKi()
{
    for (auto&& batch: _batches) {
        batch.refineKi();
    }
}

void Refiner::refineUB()
{
    for (auto&& batch: _batches) {
        batch.refineUB();
    }
}

bool Refiner::refine(unsigned int max_iter)
{ 
    if (_batches.size() == 0) {
        return false;
    }

    for (auto&& batch: _batches) {
        if (!batch.refine(max_iter)) {
            return false;
        }
    }
    return true;
}

const std::vector<RefinementBatch>& Refiner::batches() const
{
    return _batches;
}

int Refiner::updatePredictions(PeakList& peaks) const
{
    PeakFilter peak_filter;
    PeakList filtered_peaks;
    filtered_peaks = peak_filter.enabled(peaks,true);
//    filtered_peaks = peak_filter.predicted(filtered_peaks,true);
    filtered_peaks = peak_filter.unitCell(filtered_peaks,_cell);
    filtered_peaks = peak_filter.indexed(filtered_peaks,*_cell,_cell->indexingTolerance());

    PeakList pred_peaks;
    int updated = 0;

    for (auto&& peak: filtered_peaks) {
                
        // find appropriate batch
        const RefinementBatch* b = nullptr;    
        double z = peak->shape().center()[2];
        for (auto&& batch: _batches) {
            
            if (batch.contains(z)) {
                b = &batch;
                break;
            }
        }

        // no appropriate batch
        if (b == nullptr) {
            continue;
        }

        auto batch_cell = b->cell();

        // update the position
        MillerIndex hkl(peak->q(), *batch_cell);
        ReciprocalVector q_pred(hkl.rowVector().cast<double>()*batch_cell->reciprocalBasis());
        auto events = peak->data()->events({q_pred});

        // something wrong with new prediction...
        if (events.size() != 1) {
            peak->setStatus(Peak::Status::BadlyPredicted);
            continue;
        }
        
        try {
            peak->setShape(Ellipsoid({events[0]._px, events[0]._py, events[0]._frame}, peak->shape().metric()));
            ++updated;
        } catch(...) {
            peak->setStatus(Peak::Status::BadlyPredicted);
        }
        
    }
    return updated;
}

} // end namespace nsx
