#pragma once

#include <QGraphicsItem>
#include <QPen>
#include <QRectF>

#include "SXGraphicsItem.h"

class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsTextItem;
class QGraphicsSceneWheelEvent;
class QKeyEvent;
class QWidget;
class SXPlot;

class DrawableGraphicsItem : public SXGraphicsItem
{
public:

    DrawableGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent=nullptr);

    virtual ~DrawableGraphicsItem();

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    virtual void keyPressEvent(QKeyEvent* event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    //! Returns the bounding rectangle of the item
    QRectF boundingRect() const;

    //! Sets the top left corner of the item
    void setFrom(const QPointF& pos);

    //! Sets the bottom right corner of the item
    void setTo(const QPointF& pos);

protected:

    QPointF _from;

    QPointF _to;

    QPointF _previous_position;

    bool _first_move_event;
};
