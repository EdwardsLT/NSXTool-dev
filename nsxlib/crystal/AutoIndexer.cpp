/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2017- Laurent C. Chapon, Eric Pellegrini, Jonathan Fisher

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

#include "../crystal/AutoIndexer.h"
#include "../crystal/FFTIndexing.h"
#include "../crystal/GruberReduction.h"
#include "../crystal/NiggliReduction.h"
#include "../crystal/Peak3D.h"
#include "../crystal/UBMinimizer.h"
#include "../crystal/UBSolution.h"
#include "../instrument/Detector.h"
#include "../instrument/Diffractometer.h"
#include "../instrument/Experiment.h"
#include "../instrument/Gonio.h"
#include "../instrument/Sample.h"
#include "../utils/ProgressHandler.h"

#include <string>

namespace nsx {

 
AutoIndexer::AutoIndexer(std::shared_ptr<Experiment>& expt, const std::shared_ptr<ProgressHandler>& handler):
    _peaks(),
    _experiment(expt),
    _solutions(),
    _handler(handler)
{
}

bool AutoIndexer::autoIndex(const IndexerParameters& _params)
{
    const int npeaks = _peaks.size();

    // Check that a minimum number of peaks have been selected for indexing
    if (npeaks < 10) {
        if (_handler) {
            _handler->log("AutoIndexer: too few peaks to index!");
        }
        return false;
    }
    if (_experiment == nullptr) {
        if (_handler) {
            _handler->log("AutoIndexer: cannot index without an experiment!");
        }
        return false;
    }

    if (_handler) {
        _handler->log("Searching direct lattice vectors using" + std::to_string(npeaks) + "peaks defined on numors:");
    }

    // Store Q vectors at rest
    std::vector<Eigen::Vector3d> qvects;
    qvects.reserve(npeaks);
    for (auto peak : _peaks) {
        if (peak->isSelected() && !peak->isMasked()) {
            qvects.push_back(peak->getQ());
        }
    }

    // Set up a FFT indexer object
    FFTIndexing indexing(_params.subdiv, _params.maxdim);

    // Find the best tvectors
    std::vector<tVector> tvects = indexing.findOnSphere(qvects, _params.nStacks, _params.nSolutions);
    qvects.clear();

    auto source = _experiment->getDiffractometer()->getSource();
    auto detector = _experiment->getDiffractometer()->getDetector();
    auto sample = _experiment->getDiffractometer()->getSample();

    std::vector<std::pair<sptrUnitCell,double>> newSolutions;
    newSolutions.reserve(_params.nSolutions*_params.nSolutions*_params.nSolutions);

    for (int i = 0; i < _params.nSolutions; ++i) {
        for (int j = i+1; j < _params.nSolutions; ++j) {
            for (int k = j+1; k < _params.nSolutions; ++k) {
                Eigen::Matrix3d A;
                A.col(0) = tvects[i]._vect;
                A.col(1) = tvects[j]._vect;
                A.col(2) = tvects[k]._vect;

                auto cell = std::shared_ptr<UnitCell>(new UnitCell(A));
                // todo: 20.0 should not be hard-coded
                if (cell->volume() < 20.0) {                    
                    continue;
                }

                bool equivalent = false;

                // check to see if the cell is equivalent to a previous one
                // todo: tolerance should not be hard-coded
                for (auto solution: newSolutions) {
                    if (cell->equivalent(*solution.first, 0.05)) {
                        equivalent = true;
                        break;
                    }
                }

                // cell is equivalent to a previous one in the list
                if (equivalent) {
                    continue;
                }

                newSolutions.push_back(std::make_pair(cell, 0.0));
            }
        }
    }

    //#pragma omp parallel for
    for (int idx = 0; idx < newSolutions.size(); ++idx) {

        UBMinimizer minimizer;

        UBSolution ub_state;
        ub_state.setSample(sample);
        ub_state.setDetector(detector);
        ub_state.setSource(source);

        auto cell = newSolutions[idx].first;
        cell->setHKLTolerance(_params.HKLTolerance);

        // Only the UB matrix parameters are used for fit
        //for (int i = 0; i < ub_state.inputs(); ++i) {
        //    const bool refine = (i < 9);
        //    ub_state.refineParameter(i, refine);
        //}

        int success = 0;
        for (auto peak : _peaks) {
            Eigen::RowVector3d hkl;
            bool indexingSuccess = peak->getMillerIndices(*cell,hkl,true);
            if (indexingSuccess && peak->isSelected() && !peak->isMasked()) {
                minimizer.addPeak(*peak,hkl);
                ++success;
            }
        }

        // The number of peaks must be at least for a proper minimization
        if (success < 10) {
            continue;
        }

        //ub_state._ub = cell->getReciprocalStandardM();
        ub_state.setCell(cell);
        ub_state.resetParameters();
        ub_state.unzip(ub_state.zip());
       
        int ret = minimizer.run(ub_state, 100);
        if (ret == 1) {
            UBSolution sln = minimizer.solution();
            try {
                Eigen::Matrix3d ub = sln.ub();
                cell = sptrUnitCell(new UnitCell(ub, true));
                cell->setReciprocalCovariance(sln.covub());

            } catch(std::exception& e) {
                if (_handler) {
                    _handler->log("exception: " +std::string(e.what()));
                }
                continue;
            }

            cell->setHKLTolerance(_params.HKLTolerance);
            cell->reduce(_params.niggliReduction, _params.niggliTolerance, _params.gruberTolerance);
            //*cell = cell->applyNiggliConstraints(100.0);

            double score = 0.0;
            double maxscore = 0.0;
            for (auto peak : _peaks) {
                if (peak->isSelected() && !peak->isMasked()) {
                    maxscore++;
                    Eigen::RowVector3d hkl;
                    bool indexingSuccess = peak->getMillerIndices(*cell,hkl,true);
                    if (indexingSuccess) {
                        score++;
                    }
                }
            }
            // Percentage of indexing
            score /= 0.01*maxscore;
            newSolutions[idx].first = cell;
            newSolutions[idx].second = score;
        }
        //ub_state.resetParameters();
    }

    _solutions.clear();
    _solutions.reserve(newSolutions.size());

    // remove the false solutions
    for (auto&& it = newSolutions.begin(); it != newSolutions.end(); ++it) {
        if (it->second > 0.1) {
            _solutions.push_back(*it);
        }
    }
    _solutions.shrink_to_fit();
    if (_handler) {
        _handler->log("Done refining solutions, building solutions table.");
    }

    // Sort solutions by decreasing quality.
    // For equal quality, smallest volume is first

    using soluce = std::pair<sptrUnitCell,double>;
    std::sort(_solutions.begin(),_solutions.end(),[](const soluce& s1, const soluce& s2) -> bool
    {
        if (s1.second==s2.second)
            return (s1.first->volume()<s2.first->volume());
        else
            return (s1.second>s2.second);
    }
    );


    return true;
}

void AutoIndexer::addPeak(const sptrPeak3D &peak)
{
    _peaks.emplace_back(peak);
}

const std::vector<std::pair<sptrUnitCell, double> > &AutoIndexer::getSolutions() const
{
    return _solutions;
}

} // end namespace nsx
