#include <iostream>

#include <Eigen/Dense>

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Ellipsoid.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/InstrumentState.h>
#include <nsxlib/IntegrationRegion.h>
#include <nsxlib/MetaData.h>
#include <nsxlib/MillerIndex.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/ReciprocalVector.h>
#include <nsxlib/UnitCell.h>
#include <nsxlib/Units.h>

#include "PeakGraphicsItem.h"
#include "SimplePlot.h"
#include "SXPlot.h"

bool PeakGraphicsItem::_show_label = false;
bool PeakGraphicsItem::_show_center = false;

PeakGraphicsItem::PeakGraphicsItem(nsx::sptrPeak3D peak, int frame)
: SXGraphicsItem(nullptr,true,false),
  _peak(peak),
  _area(nullptr)
{
    setVisible(true);

    QString peak_label;
    auto unit_cell = _peak->unitCell();
    if (unit_cell) {
        nsx::MillerIndex miller_index(_peak->q(), *unit_cell);
        if (miller_index.indexed(unit_cell->indexingTolerance())) {
            peak_label = QString("%1,%2,%3").arg(miller_index[0]).arg(miller_index[1]).arg(miller_index[2]);
        } else {
            peak_label = "not indexed";
        }

    } else {
        peak_label = "no unit cell";
    }

    _label_gi = new QGraphicsTextItem(this);
    _label_gi->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    _label_gi->setParentItem(this);
    _label_gi->setPlainText(peak_label);
    _label_gi->setAcceptHoverEvents(false);
    _label_gi->setZValue(-1);
    _label_gi->setPos(3,3);
    _label_gi->setVisible(_show_label);

    QPen center_pen;
    center_pen.setCosmetic(true);
    center_pen.setColor(Qt::red);
    center_pen.setStyle(Qt::SolidLine);

    _center_gi = new QGraphicsEllipseItem(this);
    _center_gi->setPen(center_pen);
    _center_gi->setRect(-1,-1,2,2);
    _center_gi->setParentItem(this);
    _center_gi->setBrush(QBrush(Qt::red));
    _center_gi->setAcceptHoverEvents(false);
    _center_gi->setZValue(-1);
    _center_gi->setVisible(_show_center);

    auto peak_ellipsoid = _peak->shape();

    peak_ellipsoid.scale(_peak->peakEnd());

    auto& aabb = peak_ellipsoid.aabb();

    _lower = aabb.lower();

    _upper = aabb.upper();

    auto center = peak_ellipsoid.intersectionCenter({0.0,0.0,1.0},{0.0,0.0,static_cast<double>(frame)});

    setPos(center[0],center[1]);

    setBoundingRegionGranularity(0.0);

    // A peak item is always put on foreground of the scene
    setZValue(2);
}

nsx::sptrPeak3D PeakGraphicsItem::peak() const
{
    return _peak;
}

QRectF PeakGraphicsItem::boundingRect() const
{

    double width = _upper[0] - _lower[0];

    double height = _upper[1] - _lower[1];

    return QRectF(-width/2.0,-height/2.0,width,height);
}

void PeakGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)

    Q_UNUSED(option)

    Q_UNUSED(painter)

    _label_gi->setVisible(_hovered || _show_label);

    _center_gi->setVisible(_hovered || _show_center);
}

std::string PeakGraphicsItem::getPlotType() const
{
    return "peak";
}

void PeakGraphicsItem::showLabel(bool flag)
{
    _show_label = flag;
}

void PeakGraphicsItem::showCenter(bool flag)
{
    _show_center = flag;
}
