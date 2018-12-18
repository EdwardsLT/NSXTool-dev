#include <QGraphicsSceneMouseEvent>

#include <nsxlib/DataSet.h>

#include "CutterGraphicsItem.h"
#include "DrawableGraphicsItem.h"

CutterGraphicsItem::CutterGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent)
: DrawableGraphicsItem(data,from,parent)
{
    setZValue(1);

    _pen.setWidth(1);
    _pen.setCosmetic(true);
    _pen.setStyle(Qt::SolidLine);
}

void CutterGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        DrawableGraphicsItem::mouseMoveEvent(event);
    }
}
