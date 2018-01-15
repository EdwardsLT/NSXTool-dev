#include <Eigen/Dense>

#include "MillerIndices.h"

namespace nsx {

MillerIndices::MillerIndices(int h, int k, int l) : _hkl(h,k,l)
{
}

MillerIndices::MillerIndices(const Eigen::RowVector3i& hkl) : _hkl(hkl)
{
}

MillerIndices::operator const Eigen::RowVector3i& () const
{
    return _hkl;
}

MillerIndices::operator Eigen::RowVector3d () const
{
    return _hkl.cast<double>();
}

int MillerIndices::operator[](int index) const
{
    if (index < 0 || index > 2) {
        throw std::runtime_error("Invalid index for a 3D vector");
    }

    return _hkl[index];
}

int& MillerIndices::operator[](int index)
{
    if (index < 0 || index > 2) {
        throw std::runtime_error("Invalid index for a 3D vector");
    }

    return _hkl[index];
}

int MillerIndices::operator()(int index) const
{
    if (index < 0 || index > 2) {
        throw std::runtime_error("Invalid index for a 3D vector");
    }
    return _hkl[index];
}

int& MillerIndices::operator()(int index)
{
    if (index < 0 || index > 2) {
        throw std::runtime_error("Invalid index for a 3D vector");
    }
    return _hkl[index];
}

void MillerIndices::print(std::ostream& os) const
{
    os << _hkl;
}

std::ostream& operator<<(std::ostream& os, const MillerIndices& hkl)
{
    hkl.print(os);
    return os;
}

} // end namespace nsx
