#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

#include "DetectorSceneModel.h"
#include "DrawableGraphicsItem.h"
#include "SessionModel.h"
#include "SXPlot.h"

DrawableGraphicsItem::DrawableGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent)
: SXGraphicsItem(data,parent),
  _previous_position(from),
  _first_move_event(true)
{
    setDeletable(true);
    setMovable(true);
    setFrom(from);
    setTo(from);
}

DrawableGraphicsItem::~DrawableGraphicsItem()
{
    auto *detector_scene_model = dynamic_cast<DetectorSceneModel*>(scene());
    if (detector_scene_model) {
        emit detector_scene_model->sessionModel()->signalChangePlot(nullptr);
    }
}

void DrawableGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)

    auto *detector_scene_model = dynamic_cast<DetectorSceneModel*>(scene());
    if (detector_scene_model) {
        emit detector_scene_model->sessionModel()->signalChangePlot(plot());
    }
    SXGraphicsItem::hoverEnterEvent(event);
}

void DrawableGraphicsItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)

    auto *detector_scene_model = dynamic_cast<DetectorSceneModel*>(scene());
    if (detector_scene_model) {
        emit detector_scene_model->sessionModel()->signalChangePlot(nullptr);
    }
    SXGraphicsItem::hoverLeaveEvent(event);
}

void DrawableGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    _first_move_event = true;
    SXGraphicsItem::mouseReleaseEvent(event);
}

void DrawableGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (!_movable || !isVisible()) {
        return;
    }

    if (isSelected()) {
        auto last_scene_pos = event->lastScenePos();
        if (!_first_move_event) {
            // The translation vector
            QPointF dr = last_scene_pos - _previous_position;
            QRectF itemRect = sceneBoundingRect();
            itemRect.translate(dr.x(),dr.y());

            // At target position the item must be fully inside the scene
            auto scene_rect = scene()->sceneRect();
            if (scene_rect.contains(itemRect.topLeft()) && scene_rect.contains(itemRect.bottomRight())) {
                moveBy(dr.x(),dr.y());
            }
        }
        _previous_position = last_scene_pos;
        _first_move_event = false;
    } else {
        auto last_scene_pos = event->lastScenePos();
        if (isInScene(last_scene_pos)) {
            setTo(last_scene_pos);
        }
    }
}

void DrawableGraphicsItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    Q_UNUSED(event)

    auto *detector_scene_model = dynamic_cast<DetectorSceneModel*>(scene());

    if (detector_scene_model) {
        emit detector_scene_model->sessionModel()->signalChangePlot(plot());
        detector_scene_model->update();
    }
}

QRectF DrawableGraphicsItem::boundingRect() const
{
    qreal w = std::fabs(_to.x()-_from.x());
    qreal h = std::fabs(_to.y()-_from.y());
    return QRectF(-w/2,-h/2,w,h);
}

void DrawableGraphicsItem::setFrom(const QPointF& pos)
{
    _from = pos;
    _to = pos;
    setPos(_from);
    update();
}

void DrawableGraphicsItem::setTo(const QPointF& pos)
{
    _to = pos;
    setPos(0.5*(_from+_to));
    update();
}
