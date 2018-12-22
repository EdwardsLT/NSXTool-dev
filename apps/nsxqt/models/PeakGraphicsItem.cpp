#include <Eigen/Dense>

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Ellipsoid.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/MillerIndex.h>
#include <nsxlib/Peak.h>
#include <nsxlib/UnitCell.h>

#include "PeakGraphicsItem.h"
#include "PeaksUtils.h"
#include "SimplePlot.h"
#include "SXPlot.h"

PeakGraphicsItem::PeakGraphicsItem(nsx::sptrPeak peak, int current_frame, QGraphicsItem *parent)
: SXGraphicsItem(peak->data(),parent),
  _peak(peak),
  _show_label(false),
  _show_center(false),
  _show_box(false)
{
    setDeletable(false);

    setMovable(false);

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

    _label_graphics_item = new QGraphicsTextItem(this);
    _label_graphics_item->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    _label_graphics_item->setParentItem(this);
    _label_graphics_item->setPlainText(peak_label);
    _label_graphics_item->setAcceptHoverEvents(false);
    _label_graphics_item->setZValue(-1);
    _label_graphics_item->setPos(3,3);
    _label_graphics_item->setVisible(_show_label);

    QPen center_pen;
    center_pen.setCosmetic(true);
    center_pen.setColor(PeakStatusToColor(_peak));
    center_pen.setStyle(Qt::SolidLine);

    _center_graphics_item = new QGraphicsEllipseItem(this);
    _center_graphics_item->setPen(center_pen);
    _center_graphics_item->setRect(-1,-1,2,2);
    _center_graphics_item->setParentItem(this);
    _center_graphics_item->setBrush(QBrush(PeakStatusToColor(_peak)));
    _center_graphics_item->setAcceptHoverEvents(false);
    _center_graphics_item->setZValue(-1);
    _center_graphics_item->setVisible(_show_center);

    auto peak_ellipsoid = _peak->shape();

    peak_ellipsoid.scale(_peak->bkgEnd());

    auto& aabb = peak_ellipsoid.aabb();

    _lower = aabb.lower();
    _upper = aabb.upper();

    auto aabb_center = aabb.center();
    auto aabb_extents = aabb.extents();

    // Compute the center of the ellipse resulting from the intersection between the peak ellipsoid and the plane (0,0,frame)
    auto&& center = peak_ellipsoid.intersectionCenter({0.0,0.0,1.0},{0.0,0.0,static_cast<double>(current_frame)});

    _box_graphics_item = new QGraphicsRectItem(this);
    _box_graphics_item->setPos(aabb_center[0] - center[0],aabb_center[1] - center[1]);
    _box_graphics_item->setRect(-aabb_extents[0]/2,-aabb_extents[1]/2,aabb_extents[0],aabb_extents[1]);
    _box_graphics_item->setZValue(-1);
    _box_graphics_item->setAcceptHoverEvents(false);
    _box_graphics_item->setVisible(_show_box);

    setPos(center[0],center[1]);

    setBoundingRegionGranularity(0.0);

    // A peak item is always put on foreground of the scene
    setZValue(2);
}

void PeakGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen info_box_pen;
    info_box_pen.setColor(PeakStatusToColor(_peak));
    info_box_pen.setStyle(Qt::DotLine);

    _box_graphics_item->setPen(info_box_pen);
}

void PeakGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    _box_graphics_item->setVisible(true);

    SXGraphicsItem::hoverEnterEvent(event);
}

void PeakGraphicsItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    _box_graphics_item->setVisible(false);

    SXGraphicsItem::hoverLeaveEvent(event);
}

nsx::sptrPeak PeakGraphicsItem::peak() const
{
    return _peak;
}

QRectF PeakGraphicsItem::boundingRect() const
{
    double width = _upper[0] - _lower[0];

    double height = _upper[1] - _lower[1];

    return QRectF(-width/2.0,-height/2.0,width,height);
}

void PeakGraphicsItem::showLabel(bool flag)
{
    _show_label = flag;
    _label_graphics_item->setVisible(_show_label);
    update();
}

void PeakGraphicsItem::showCenter(bool flag)
{
    _show_center = flag;
    _center_graphics_item->setVisible(_show_center);
    update();
}

void PeakGraphicsItem::showBox(bool flag)
{
    _show_box = flag;
    _box_graphics_item->setVisible(_show_box);
    update();
}

SXPlot* PeakGraphicsItem::plot() const
{
    auto ellipsoid = _peak->shape();
    ellipsoid.scale(_peak->bkgEnd());
    const auto& aabb = ellipsoid.aabb();

    auto data = _peak->data();

    auto *plot = new SimplePlot();

    Eigen::Vector3i lower = aabb.lower().cast<int>();

    lower[0] = (lower[0] < 0) ? 0 : lower[0];
    lower[1] = (lower[1] < 0) ? 0 : lower[1];
    lower[2] = (lower[2] < 0) ? 0 : lower[2];

    const int n_rows = data->nRows();
    const int n_cols = data->nCols();
    const int n_frames = data->nFrames();

    Eigen::Vector3i upper = aabb.upper().cast<int>();
    upper[0] = (upper[0] >= n_cols) ? n_cols - 1 : upper[0];
    upper[1] = (upper[1] >= n_rows) ? n_rows - 1 : upper[1];
    upper[2] = (upper[2] >= n_frames) ? n_frames - 1 : upper[2];

    QVector<double> x_values;
    QVector<double> y_values;
    QVector<double> err_y_values;

    for (int z = lower[2]; z <= upper[2]; ++z) {
        const auto& frame = data->frame(z);
        double counts = static_cast<double>(frame.block(lower[1],lower[0],upper[1]-lower[1],upper[0]-lower[0]).sum());
        x_values.append(static_cast<double>(z));
        y_values.append(counts);
        err_y_values.append(counts > 0 ? std::sqrt(counts) : 0.0);
    }

    plot->graph(0)->setDataValueError(x_values, y_values, err_y_values);

    plot->xAxis->setAutoTicks(false);
    plot->xAxis->setTickVector(x_values);

    plot->rescaleAxes();
    plot->replot();

    return plot;
}
