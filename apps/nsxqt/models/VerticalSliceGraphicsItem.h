#pragma once

#include <nsxlib/DataTypes.h>

#include "CutterGraphicsItem.h"

class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

class SXPlot;

class VerticalSliceGraphicsItem : public CutterGraphicsItem
{
public:

    //! Construct a data slicer
    VerticalSliceGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent=nullptr);

    //! Handles a mouse wheel event
    void wheelEvent(QGraphicsSceneWheelEvent* event);

    SXPlot* plot() const override;

    //! Paint the slice
    void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};
