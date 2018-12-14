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

    PeakGraphicsItem(nsx::sptrPeak3D peak, int current_frame, QGraphicsItem *parent=nullptr);

    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;

    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const;

    nsx::sptrPeak3D peak() const;

    void showLabel(bool flag);

    void showCenter(bool flag);

    void showBox(bool flag);

private:

    //! Pointer to the Peak3D object
    nsx::sptrPeak3D _peak;

    bool _show_label;

    bool _show_center;

    bool _show_box;

    QGraphicsTextItem* _label_gi;

    QGraphicsEllipseItem* _center_gi;

    QGraphicsRectItem* _box_gi;

    Eigen::Vector3d _lower;

    Eigen::Vector3d _upper;
};
