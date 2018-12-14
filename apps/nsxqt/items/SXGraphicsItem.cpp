#include <QCursor>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

#include "DetectorSceneModel.h"
#include "SessionModel.h"
#include "SXGraphicsItem.h"
#include "SXPlot.h"

SXGraphicsItem::SXGraphicsItem(nsx::sptrDataSet data, QGraphicsItem *parent, bool deletable, bool movable)
: QGraphicsItem(parent),
  _data(data),
  _deletable(deletable),
  _movable(movable)
{
    _pen.setWidth(1);
    _pen.setCosmetic(true);
    _pen.setStyle(Qt::SolidLine);

    // By default a plottable graphics can be selected
    setFlags(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable,_movable);
    setAcceptHoverEvents(true);
}

void SXGraphicsItem::keyPressEvent(QKeyEvent* event)
{
    QGraphicsItem::keyPressEvent(event);
}

void SXGraphicsItem::updatePlot()
{
    auto *detector_scene_model = dynamic_cast<DetectorSceneModel*>(scene());
    if (detector_scene_model) {
        emit detector_scene_model->sessionModel()->signalChangePlot(plot());
    }
}

void SXGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    Q_UNUSED(event)
    updatePlot();
}

void SXGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}

void SXGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    setCursor(QCursor(Qt::PointingHandCursor));
    update();
}

void SXGraphicsItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    setCursor(QCursor(Qt::CrossCursor));
    update();
}

bool SXGraphicsItem::isInScene(const QPointF& pos) const
{
    QRectF rect = scene()->sceneRect();
    return (pos.x()>rect.left() && pos.x()<rect.right() && pos.y() > rect.top() && pos.y() <rect.bottom());
}

void SXGraphicsItem::setDeletable(bool deletable)
{
    _deletable = deletable;
}

void SXGraphicsItem::setMovable(bool movable)
{
    _movable = movable;
    setFlag(QGraphicsItem::ItemIsMovable,_movable);
}

bool SXGraphicsItem::isDeletable() const
{
    return _deletable;
}

bool SXGraphicsItem::isMovable() const
{
    return _movable;
}

SXPlot* SXGraphicsItem::plot() const
{
    return nullptr;
}

