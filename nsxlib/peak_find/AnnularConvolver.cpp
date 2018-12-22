// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/peak_find/AnnularConvolver.cpp
//! @brief     Implements module/class/test AnnularConvolver
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include "AnnularConvolver.h"
#include "RadialConvolver.h"

namespace nsx {

AnnularConvolver::AnnularConvolver()
: IConvolver({{"inner_radius",5},{"middle_radius",10},{"outer_radius",15}})
{
    _radial_convolver_peak.reset(new RadialConvolver({{"inner_radius",0},{"outer_radius",_parameters.at("inner_radius")}}));
    _radial_convolver_background.reset(new RadialConvolver({{"inner_radius",_parameters.at("middle_radius")},{"outer_radius",_parameters.at("outer_radius")}}));
}

AnnularConvolver::AnnularConvolver(const std::map<std::string,int>& parameters)
: AnnularConvolver()
{
    setParameters(parameters);

    // An annular convolver is made of two concentric radial convolver.
    _radial_convolver_peak.reset(new RadialConvolver({{"inner_radius",0},{"outer_radius",_parameters.at("inner_radius")}}));
    _radial_convolver_background.reset(new RadialConvolver({{"inner_radius",_parameters.at("middle_radius")},{"outer_radius",_parameters.at("outer_radius")}}));
}

AnnularConvolver::AnnularConvolver(const AnnularConvolver& other)
{
    _radial_convolver_peak.reset(new RadialConvolver(*other._radial_convolver_peak));
    _radial_convolver_background.reset(new RadialConvolver(*other._radial_convolver_background));
}

AnnularConvolver& AnnularConvolver::operator =(const AnnularConvolver& other)
{
    if (this != &other) {
        _radial_convolver_peak.reset(new RadialConvolver(*other._radial_convolver_peak));
        _radial_convolver_background.reset(new RadialConvolver(*other._radial_convolver_background));
    }
    return *this;
}

void AnnularConvolver::setParameters(const std::map<std::string,int>& parameters)
{
    IConvolver::setParameters(parameters);
    _radial_convolver_peak->setParameters({{"inner_radius",0},{"outer_radius",_parameters.at("inner_radius")}});
    _radial_convolver_background->setParameters({{"inner_radius",_parameters.at("middle_radius")},{"outer_radius",_parameters.at("outer_radius")}});
}

IConvolver* AnnularConvolver::clone() const
{
    return new AnnularConvolver(*this);
}

std::pair<size_t,size_t> AnnularConvolver::kernelSize() const
{
    return _radial_convolver_background->kernelSize();
}

RealMatrix AnnularConvolver::convolve(const RealMatrix& image)
{
    RealMatrix conv_peak = _radial_convolver_peak->convolve(image);

    RealMatrix conv_bkg = _radial_convolver_background->convolve(image);

    RealMatrix result = conv_peak - conv_bkg;

    return result;
}

RealMatrix AnnularConvolver::matrix() const
{
    if ((_parameters.at("inner_radius") < 0) ||
        (_parameters.at("inner_radius") > _parameters.at("middle_radius")) ||
        (_parameters.at("middle_radius") > _parameters.at("outer_radius"))) {
        throw std::runtime_error("AnnularConvolver convolver called with invalid parameters");
    }

    const int inner_radius = _parameters.at("inner_radius");

    const int outer_radius = _parameters.at("outer_radius");
    const double center = outer_radius;

    RealMatrix outer_kernel = -_radial_convolver_background->matrix();

    RealMatrix inner_kernel = _radial_convolver_peak->matrix();

    // Insert the inner kernel inside the outer one
    const int topleft_pixel = center-inner_radius;
    outer_kernel.block(topleft_pixel,topleft_pixel,inner_kernel.rows(),inner_kernel.cols()) = inner_kernel;

    return outer_kernel;
}

} // end namespace nsx

