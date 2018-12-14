#pragma once

#include <memory>
#include <string>

#include <nsxlib/RectangularMask.h>
#include <nsxlib/DataTypes.h>
#include <nsxlib/GeometryTypes.h>

#include "DrawableGraphicsItem.h"
#include "SXGraphicsItem.h"

namespace nsx {
class Mask;
}

class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;
class QKeyEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

/*! Creates a mask that will be used to unselect/select peaks whether their intercept or
 * not the mask
 */
class MaskGraphicsItem : public DrawableGraphicsItem {
public:
    // Constructs a mask
    MaskGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent=nullptr);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    virtual void keyPressEvent(QKeyEvent* event) override;

    //! Paint the slice
    void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:

    std::shared_ptr<nsx::Mask> _mask;

    QGraphicsTextItem* _text;
};
