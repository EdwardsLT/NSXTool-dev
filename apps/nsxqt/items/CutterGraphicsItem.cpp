#include <iostream>

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QtDebug>
#include <cmath>

#include "items/CutterGraphicsItem.h"

CutterGraphicsItem::CutterGraphicsItem(std::shared_ptr<SX::Data::IData> data)
: PlottableGraphicsItem(nullptr,true,true),
  _data(data),
  _from(0,0),
  _to(0,0)
{

    setZValue(1);

    _pen.setWidth(1);
    _pen.setCosmetic(true);
    _pen.setStyle(Qt::SolidLine);

}

CutterGraphicsItem::~CutterGraphicsItem()
{
}

void CutterGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->buttons() & Qt::LeftButton)
    {
        // If the cutter is not selected, the move event corresponds to a modification of the size of cutter
        if (!isSelected())
        {
            if (isInScene(event->lastScenePos()))
                setTo(event->lastScenePos());
        }
        // Otherwise it is a standard move of the item
        else
            SXGraphicsItem::mouseMoveEvent(event);
    }
}

std::shared_ptr<SX::Data::IData> CutterGraphicsItem::getData()
{
    return _data;
}

QRectF CutterGraphicsItem::boundingRect() const
{
    qreal w=std::fabs(_to.x()-_from.x());
    qreal h=std::fabs(_to.y()-_from.y());
    return QRectF(-w/2,-h/2,w,h);
}

void CutterGraphicsItem::setFrom(const QPointF& pos)
{
    _from=pos;
    _to=pos;
    setPos(_from);
    update();
}

void CutterGraphicsItem::setTo(const QPointF& pos)
{
    _to=pos;
    setPos(0.5*(_from+_to));
    update();
}