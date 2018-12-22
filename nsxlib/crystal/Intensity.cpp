// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/crystal/Intensity.cpp
//! @brief     Implements module/class/test Intensity
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#include <cassert>
#include <cmath>

#include "Intensity.h"

namespace nsx {

Intensity::Intensity(double value, double sigma2): _value(value), _sigma2(sigma2)
{
    if (_sigma2 < 0.0 || std::isnan(_sigma2)) {
        _sigma2 = 0.0;
    }
}

Intensity::Intensity(const Intensity& other): _value(other._value), _sigma2(other._sigma2)
{
    if (_sigma2 < 0.0 || std::isnan(_sigma2)) {
        _sigma2 = 0.0;
    }
}

double Intensity::value() const
{
    return _value;
}

double Intensity::sigma() const
{
    return std::sqrt(_sigma2);
}

double Intensity::variance() const
{
    return _sigma2;
}

Intensity Intensity::operator+(const Intensity &other) const
{
    return Intensity(_value + other._value, _sigma2 + other._sigma2);
}

Intensity Intensity::operator-(const Intensity &other) const
{
    return Intensity(_value - other._value, _sigma2 + other._sigma2);
}

Intensity& Intensity::operator*=(double s)
{
    _value *= s;
    _sigma2 *= s*s;
    return *this;
}

Intensity Intensity::operator*(double scale) const
{
    return Intensity(scale*_value, scale*scale*_sigma2);
}

Intensity Intensity::operator/(double denominator) const
{
    const double scale = 1.0 / denominator;
    return Intensity(scale*_value, scale*scale*_sigma2);
}

Intensity& Intensity::operator+=(const Intensity& other)
{
    _value += other._value;
    _sigma2 += other._sigma2;
    return *this;
}

Intensity Intensity::operator/(const Intensity& other) const
{
    const double d = 1.0 / other._value;
    return Intensity(_value*d, d*d*(_sigma2 + _value*other._sigma2));
}

} // end namespace nsx
