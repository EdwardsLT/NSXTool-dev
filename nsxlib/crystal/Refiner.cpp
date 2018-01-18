/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2017- Laurent C. Chapon,  Eric Pellegrini, Jonathan Fisher

 Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr
 pellegrini[at]ill.fr

 Forschungszentrum Juelich GmbH
 52425 Juelich
 Germany
 j.fisher[at]fz-juelich.de


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


#include <algorithm>
#include <iterator>

#include "InstrumentState.h"
#include "Peak3D.h"
#include "PeakPredictor.h"
#include "Refiner.h"
#include "UnitCell.h"

namespace nsx {

Refiner::Refiner(sptrUnitCell cell, const PeakList& peaks, int nbatches)
: _batches(), _cell(cell)
{
    PeakList sorted_peaks(peaks);

    auto sort_peaks_by_frame = [](sptrPeak3D p1, sptrPeak3D p2) -> bool {
        auto&& c1 = p1->getShape().center();
        auto&& c2 = p2->getShape().center();
        return c1[2] < c2[2];
    };

    std::sort(sorted_peaks.begin(),sorted_peaks.end(),sort_peaks_by_frame);
    std::cout << "sorted peaks " << sorted_peaks.size() << " of " << peaks.size() << std::endl;

    double batch_size = sorted_peaks.size() / double(nbatches);
    size_t current_batch = 0;

    PeakList peaks_subset;

    for (size_t i = 0; i < sorted_peaks.size(); ++i) {
        peaks_subset.push_back(sorted_peaks[i]);

        if (i + 1.1 >= (current_batch+1)*batch_size) {
            RefinementBatch b(*cell, peaks_subset);
            _batches.emplace_back(std::move(b));
            peaks_subset.clear();
            ++current_batch;
        }
    }
}

void Refiner::refineDetectorOffset(InstrumentStateList& states)
{
    for (auto&& batch: _batches) {
        batch.refineDetectorOffset(states);
    }
}

void Refiner::refineSamplePosition(InstrumentStateList& states)
{
    for (auto&& batch: _batches) {
        batch.refineSamplePosition(states);
    }
}

void Refiner::refineSampleOrientation(InstrumentStateList& states)
{
    for (auto&& batch: _batches) {
        batch.refineSampleOrientation(states);
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

void Refiner::refineU()
{  
    for (auto&& batch: _batches) {
        batch.refineU(); 
    }
}

void Refiner::refineB()
{  
    for (auto&& batch: _batches) {
        batch.refineB();
    }
}

const std::vector<RefinementBatch>& Refiner::batches() const
{
    return _batches;
}

int Refiner::updatePredictions(PeakList& peaks) const
{
    PeakList pred_peaks;
    int updated = 0;

    for (auto&& peak: peaks) {

        if (!peak->isSelected() || peak->isObserved()) {
            continue;
        }

        if (peak->activeUnitCell() != _cell) {
            continue;
        }
                
        // find appropriate batch
        const RefinementBatch* b = nullptr;    
        double z = peak->getShape().center()[2];
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

        // update the position
        Eigen::RowVector3d hkl = b->cell()->getIntegerMillerIndices(peak->getQ()).cast<double>();
        PeakPredictor predictor(peak->data());
        auto pred = predictor.predictPeaks({MillerIndex(hkl(0), hkl(1), hkl(2))}, b->cell()->reciprocalBasis());

        // something wrong with new prediction...
        if (pred.size() != 1) {
            continue;
        }

        peak->setShape(Ellipsoid(pred[0]->getShape().center(), peak->getShape().metric()));
        ++updated;
    }
    return updated;
}

void Refiner::refineKi(InstrumentStateList& states)
{
    for (auto&& batch: _batches) {
        batch.refineKi(states); 
    }
}



} // end namespace nsx
