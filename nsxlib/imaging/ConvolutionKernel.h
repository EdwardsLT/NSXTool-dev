/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon, Eric Pellegrini, Jonathan Fisher
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

#ifndef NSXTOOL_CONVOLUTIONKERNEL_H_
#define NSXTOOL_CONVOLUTIONKERNEL_H_

#include <map>
#include <stdexcept>
#include <string>
#include <ostream>

#include <string>
#include <map>

#include <Eigen/Dense>


#include "Convolver.h"
#include "../utils/Types.h"



namespace SX
{

namespace Imaging
{

class ConvolutionKernel
{
public:
    typedef std::map<std::string, double> ParameterMap;

    ConvolutionKernel(int nrows, int ncols);
    ConvolutionKernel(const ConvolutionKernel& rhs);
    ConvolutionKernel(int nrows, int ncols, const ParameterMap& parameters);

    // used to get/set parameters
    ParameterMap& getParameters();
    const ParameterMap& getParameters() const;


    const SX::Types::RealMatrix& getKernel();
    virtual const char* getName() = 0;

    void print(std::ostream& os) const;

    ConvolutionKernel& operator=(const ConvolutionKernel& rhs);

    virtual ~ConvolutionKernel()=0;


protected:
    // update the kernel using current parameters
    virtual void update() {};

    int _nrows, _ncols;

    SX::Types::RealMatrix _kernel;
    bool _hasChanged; // used to record if parameters have changed since last update
    ParameterMap _params;
};

std::ostream& operator<<(std::ostream& os, const ConvolutionKernel& kernel);

} // namespace Imaging 
} // namespace SX 

#endif /* NSXTOOL_CONVOLUTIONKERNEL_H_ */
