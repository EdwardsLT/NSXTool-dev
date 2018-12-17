#include <limits>

#include <nsxlib/Peak3D.h>

#include "PeaksUtils.h"

std::pair<double,double> dRange(const nsx::PeakList& peaks)
{
    std::pair<double,double> drange;
    double dmin = std::numeric_limits<double>::infinity();
    double dmax =  -std::numeric_limits<double>::infinity();

    for (auto peak : peaks) {
        double d = 1.0/peak->q().rowVector().norm();
        dmin = std::min(dmin,d);
        dmax = std::max(dmax,d);
    }

    return std::make_pair(dmin,dmax);
}

QColor PeakStatusToColor(nsx::sptrPeak3D peak)
{
    auto status = peak->status();

    switch (status) {
    case nsx::Peak3D::Status::Selected:
        return Qt::black;
    case nsx::Peak3D::Status::Unselected:
        return Qt::red;
    case nsx::Peak3D::Status::OutOfBounds:
        return Qt::yellow;
    case nsx::Peak3D::Status::NotIndexed:
        return Qt::green;
    case nsx::Peak3D::Status::BadlyIntegrated:
        return Qt::magenta;
    case nsx::Peak3D::Status::BadlyPredicted:
        return Qt::darkRed;
    case nsx::Peak3D::Status::Unknown:
        return Qt::cyan;
    }
}

QString PeakStatusToString(nsx::sptrPeak3D peak)
{
    auto status = peak->status();

    switch (status) {
    case nsx::Peak3D::Status::Selected:
        return "selected";
    case nsx::Peak3D::Status::Unselected:
        return "unselected";
    case nsx::Peak3D::Status::OutOfBounds:
        return "out of bounds";
    case nsx::Peak3D::Status::NotIndexed:
        return "not indexed";
    case nsx::Peak3D::Status::BadlyIntegrated:
        return "badly integrated";
    case nsx::Peak3D::Status::BadlyPredicted:
        return "badly predicted";
    case nsx::Peak3D::Status::Unknown:
        return "unknown";
    }
}
