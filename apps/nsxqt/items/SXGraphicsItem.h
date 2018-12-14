#pragma once

#include <QGraphicsItem>
#include <QPen>
#include <QRectF>

#include <nsxlib/DataTypes.h>

class DetectorSceneModel;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsTextItem;
class QGraphicsSceneWheelEvent;
class QWidget;
class SXPlot;

class SXGraphicsItem : public QGraphicsItem
{
public:

	// Construct a SX graphics item
    SXGraphicsItem(nsx::sptrDataSet data, QGraphicsItem *parent=0, bool deletable=false, bool movable=false);

    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;

    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

    virtual void keyPressEvent(QKeyEvent* event) override;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

    virtual QRectF boundingRect() const=0;

    //! Set whether or not the item is deletable
    void setDeletable(bool deletable);

    //! Set whether or not the item is movable
    void setMovable(bool movable);

    //! Returns whether or not the item is deletable
    bool isDeletable() const;

    //! Return whether or not the item at the given position is fully inside the scene
    virtual bool isInScene(const QPointF& pos) const;

    //! Returns whether or not the item is movable
    bool isMovable() const;

    //! Paint the graphics item
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;

    //! Show or does not show the label bound to the item
    void showLabel(bool);

    virtual SXPlot* plot() const;

protected:

    nsx::sptrDataSet _data;

    bool _deletable;

    bool _movable;

    QPen _pen;
};
