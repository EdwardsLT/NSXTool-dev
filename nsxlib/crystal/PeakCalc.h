/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon Eric Pellegrini, Jonathan Fisher
 Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr
 pellegrini[at]ill.fr
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
#ifndef NSXTOOL_PEAKCALC_H_
#define NSXTOOL_PEAKCALC_H_

#include <memory>
#include <vector>
#include <set>

namespace SX {

namespace Data {
class DataSet;
}

namespace Geometry {
template<typename T, unsigned int D> class NDTree;
}

namespace Crystal {

class Peak3D;

struct PeakCalc {
    using PeakList = std::vector<std::shared_ptr<Peak3D>>;
    using PeakSet = std::set<std::shared_ptr<Peak3D>>;
    using sptrPeak3D = std::shared_ptr<Peak3D>;
    using IData = SX::Data::DataSet;
    using Octree = SX::Geometry::NDTree<double, 3>;

    PeakCalc(double h,double k,double l, double x,double y, double frame); //:
        //_h(h), _k(k), _l(l), _x(x), _y(y), _frame(frame) = default;
    ~PeakCalc() = default;

    double _h,_k,_l;
    double _x,_y,_frame;

    sptrPeak3D averagePeaks(const Octree& tree, double distance);
};

} // namespace Crystal
} // namespace SX

#endif /* NSXTOOL_PEAKCALC_H_ */
