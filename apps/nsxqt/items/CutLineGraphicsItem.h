#pragma once

#include <string>

#include <QGraphicsItem>

#include <nsxlib/DataTypes.h>

#include "CutterGraphicsItem.h"

class QGraphicsSceneWheelEvent;
class QWidget;
class SXPlot;

class CutLineGraphicsItem : public CutterGraphicsItem
{
public:

    CutLineGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent=nullptr);

    virtual SXPlot* plot() const override;

    void wheelEvent(QGraphicsSceneWheelEvent* event);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int _nPoints;

};
