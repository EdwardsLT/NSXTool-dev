#pragma once

#include <QPointF>

#include <string>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/GeometryTypes.h>

#include "SXGraphicsItem.h"

class QGraphicsSceneHoverEvent;
class QGraphicsTextItem;
class QWidget;
class SXPlot;

class PeakGraphicsItem : public SXGraphicsItem
{
public:

    PeakGraphicsItem(nsx::sptrPeak peak, int current_frame, QGraphicsItem *parent=nullptr);

    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;

    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const;

    nsx::sptrPeak peak() const;

    void showLabel(bool flag);

    void showCenter(bool flag);

    void showBox(bool flag);

    SXPlot* plot() const override;

private:

    //! Pointer to the Peak object
    nsx::sptrPeak _peak;

    bool _show_label;

    bool _show_center;

    bool _show_box;

    QGraphicsTextItem* _label_graphics_item;

    QGraphicsEllipseItem* _center_graphics_item;

    QGraphicsRectItem* _box_graphics_item;

    Eigen::Vector3d _lower;

    Eigen::Vector3d _upper;
};
