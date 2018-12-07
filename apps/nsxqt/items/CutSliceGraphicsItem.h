#pragma once

#include <nsxlib/DataTypes.h>

#include "CutterGraphicsItem.h"

class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

class SXPlot;

class CutSliceGraphicsItem : public CutterGraphicsItem
{
public:

    //! Construct a data slicer
    CutSliceGraphicsItem(nsx::sptrDataSet, bool horizontal=true);

    //! Handles a mouse wheel event
    void wheelEvent(QGraphicsSceneWheelEvent* event);

    //! Returns the type of plot related to this item
    std::string getPlotType() const;

    SXPlot* plot() const override;

    //! Return true if the slice is horizontal.
    bool isHorizontal() const;

    //! Paint the slice
    void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    //! Horizontal or vertical integration
    bool _horizontal;
};
