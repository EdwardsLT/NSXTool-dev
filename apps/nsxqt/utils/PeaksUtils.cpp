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
        // black
        return QColor(0,0,0);
    case nsx::Peak3D::Status::Unselected:
        // red
        return QColor(255,0,0);
    case nsx::Peak3D::Status::OutOfBounds:
        // orange
        return QColor(255,128,0);
    case nsx::Peak3D::Status::NotIndexed:
        // green
        return QColor(0,153,0);
    case nsx::Peak3D::Status::BadlyIntegrated:
        return QColor(153,0,76);
    case nsx::Peak3D::Status::BadlyPredicted:
        return QColor(153,153,0);
    case nsx::Peak3D::Status::Unknown:
        return QColor(0,51,102);
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
