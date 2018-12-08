#pragma once

#include <memory>
#include <string>

#include <nsxlib/RectangularMask.h>
#include <nsxlib/DataTypes.h>
#include <nsxlib/GeometryTypes.h>

#include "SXGraphicsItem.h"

class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

/*! Creates a mask that will be used to unselect/select peaks whether their intercept or
 * not the mask
 */
class RectangularMaskGraphicsItem : public SXGraphicsItem {
public:
    // Constructs a mask
    RectangularMaskGraphicsItem(nsx::sptrDataSet data, const nsx::AABB& aabb);

    ~RectangularMaskGraphicsItem();

    // Getters and setters

    //! Returns the bounding rectangle of the mask
    QRectF boundingRect() const;

    // Other methods

    //! Paint the slice
    void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    //! The data on which the cutter will act upon
    nsx::sptrDataSet _data;

    nsx::RectangularMask *_mask;

    QPointF _from;
    QPointF _to;
    QGraphicsTextItem* _text;

    void updateAABB();

};
