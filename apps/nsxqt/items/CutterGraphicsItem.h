#pragma once

#include <QPen>
#include <QPointF>

#include <nsxlib/DataTypes.h>

#include "DrawableGraphicsItem.h"

class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QWidget;

class CutterGraphicsItem : public DrawableGraphicsItem
{
public:

    //! Constructs a data cutter
    CutterGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent=nullptr);

    //! The mouse move event.
    //! If the item is selected when the event is triggered then the item will be moved on the scene
    //! Otherwise, that means that the item is being drawn and then the move event corresponds to a resize
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    //! Paint the contents of the item [pure virtual]
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;
};
