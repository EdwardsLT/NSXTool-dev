#include <limits>

#include <nsxlib/Peak.h>

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

QColor PeakStatusToColor(nsx::sptrPeak peak)
{
    auto status = peak->status();

    switch (status) {
    case nsx::Peak::Status::Selected:
        // black
        return QColor(0,0,0);
    case nsx::Peak::Status::Unselected:
        // red
        return QColor(255,0,0);
    case nsx::Peak::Status::OutOfBounds:
        // orange
        return QColor(255,128,0);
    case nsx::Peak::Status::NotIndexed:
        // green
        return QColor(0,153,0);
    case nsx::Peak::Status::BadlyIntegrated:
        return QColor(153,0,76);
    case nsx::Peak::Status::BadlyPredicted:
        return QColor(153,153,0);
    case nsx::Peak::Status::Unknown:
        return QColor(0,51,102);
    }
}

QString PeakStatusToString(nsx::sptrPeak peak)
{
    auto status = peak->status();

    switch (status) {
    case nsx::Peak::Status::Selected:
        return "selected";
    case nsx::Peak::Status::Unselected:
        return "unselected";
    case nsx::Peak::Status::OutOfBounds:
        return "out of bounds";
    case nsx::Peak::Status::NotIndexed:
        return "not indexed";
    case nsx::Peak::Status::BadlyIntegrated:
        return "badly integrated";
    case nsx::Peak::Status::BadlyPredicted:
        return "badly predicted";
    case nsx::Peak::Status::Unknown:
        return "unknown";
    }
}
