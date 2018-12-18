#pragma once

#include <functional>
#include <utility>

#include <QColor>
#include <QString>

#include <nsxlib/CrystalTypes.h>

std::pair<double,double> dRange(const nsx::PeakList& peaks); 

QColor PeakStatusToColor(nsx::sptrPeak3D peak);

QString PeakStatusToString(nsx::sptrPeak3D peak);
