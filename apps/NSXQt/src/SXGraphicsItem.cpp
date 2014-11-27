#include <QCursor>
#include <QtDebug>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include "DetectorScene.h"
#include "SXGraphicsItem.h"
#include "SXPlot.h"

SXGraphicsItem::SXGraphicsItem(QGraphicsItem *parent)
: QGraphicsItem(parent),
  _deletable(false),
  _hoverable(true),
  _movable(true),
  _label(nullptr)
{

    _pen.setWidth(1);
    _pen.setCosmetic(true);
    _pen.setStyle(Qt::SolidLine);

    // By default a plottable graphics can be selected and moved
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    // By default a plottable graphics accepts hove event.
    setAcceptHoverEvents(true);
}

SXGraphicsItem::~SXGraphicsItem()
{
}

void SXGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    _hoverable=true;
    setCursor(QCursor(Qt::PointingHandCursor));
    update();
}

void SXGraphicsItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    _hoverable=false;
    setCursor(QCursor(Qt::CrossCursor));
    update();
}

bool SXGraphicsItem::isInScene(const QPointF& pos) const
{
    QRectF rect=scene()->sceneRect();

    return (pos.x()>rect.left() && pos.x()<rect.right() && pos.y() > rect.top() && pos.y() <rect.bottom());
}

void SXGraphicsItem::setDeletable(bool deletable)
{
    _deletable = deletable;
}

void SXGraphicsItem::setMovable(bool movable)
{
    _movable = movable;
}

bool SXGraphicsItem::isDeletable() const
{
    return _deletable;
}

bool SXGraphicsItem::isMovable() const
{
    return _movable;
}

void SXGraphicsItem::showLabel(bool show)
{
    _label->setVisible(show);
}

void SXGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
}

void SXGraphicsItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
}

void SXGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{

    // The item must be movable ... to be moved
    if (!_movable)
        return;

    // The item must be visible to be moved
    if (!isVisible())
        return;

    // The item must be selected to be moved
    if (!isSelected())
        return;

    // The translation vector
    QPointF dr = event->lastScenePos() - pos();

    QRectF itemRect=sceneBoundingRect();
    itemRect.translate(dr);

    // At target position the item must be fully inside the scene
    if (scene()->sceneRect().contains(itemRect.topLeft()) && scene()->sceneRect().contains(itemRect.bottomRight()))
        moveBy(dr.x(),dr.y());

}

