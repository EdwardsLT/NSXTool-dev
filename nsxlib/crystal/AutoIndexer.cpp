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
        auto cell = newSolutions[idx].first;
        cell->setHKLTolerance(_params.HKLTolerance);
        Eigen::Matrix3d B = cell->reciprocalBasis();
        std::vector<Eigen::RowVector3d> hkls;
        std::vector<Eigen::RowVector3d> qs;

        int success = 0;
        for (auto peak : _peaks) {
            Eigen::RowVector3d hkl;
            bool indexingSuccess = peak->getMillerIndices(*cell,hkl,true);
            if (indexingSuccess && peak->isSelected() && !peak->isMasked()) {
                hkls.emplace_back(hkl);
                qs.emplace_back(peak->getQ());
                ++success;
            }
        }

        // The number of peaks must be at least for a proper minimization
        if (success < 10) {
            continue;
        }

        auto residuals = [&B, &hkls, &qs] (Eigen::VectorXd& f) -> int
        {
            int n = f.size() / 3;

            for (int i = 0; i < n; ++i) {
                auto dq = qs[i]-hkls[i]*B;
                f(3*i+0) = dq(0);
                f(3*i+1) = dq(1);
                f(3*i+2) = dq(2);
            }
            return 0;
        };

        FitParameters params;

        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                params.addParameter(&B(r,c));
            }
        }

        Minimizer minimizer;
        minimizer.initialize(params, 3*success);     
        minimizer.set_f(residuals);  
        minimizer.setxTol(1e-10);
        minimizer.setfTol(1e-10);
        minimizer.setgTol(1e-10);
        auto ret = minimizer.fit(100);

        if (ret) {
            try {
                cell = sptrUnitCell(new UnitCell(B, true));
                cell->setHKLTolerance(_params.HKLTolerance);
                cell->reduce(_params.niggliReduction, _params.niggliTolerance, _params.gruberTolerance);
                *cell = cell->applyNiggliConstraints();
            } catch(std::exception& e) {
                if (_handler) {
                    _handler->log("exception: " +std::string(e.what()));
                }
                continue;
            }

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
