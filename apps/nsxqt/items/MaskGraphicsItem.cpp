#include <algorithm>
#include <numeric>

#include <Eigen/Dense>

#include <QPainter>
#include <QGraphicsSceneWheelEvent>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <nsxlib/AABB.h>
#include <nsxlib/DataSet.h>

#include "MaskGraphicsItem.h"

MaskGraphicsItem::MaskGraphicsItem(nsx::sptrDataSet data, const nsx::AABB& aabb)
: SXGraphicsItem(nullptr,true,true),
  _data(data)
{
    _pen.setWidth(1);
    _pen.setCosmetic(true);
    _pen.setStyle(Qt::SolidLine);
    _text = new QGraphicsTextItem(this);
    _text->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    _text->setParentItem(this);

    _mask.reset(new nsx::BoxMask(aabb));

}

MaskGraphicsItem::~MaskGraphicsItem()
{
}

void MaskGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setBrush(QBrush(QColor(255,0,0,100)));

    // Color depending on selection
    if (option->state & QStyle::State_Selected)
        _pen.setStyle(Qt::DashLine);
    else
        _pen.setStyle(Qt::SolidLine);

    painter->setRenderHint(QPainter::HighQualityAntialiasing);
    painter->setPen(_pen);
    painter->drawRect(boundingRect());

    QPointF tl = sceneBoundingRect().topLeft();
    QPointF br = sceneBoundingRect().bottomRight();
    QString text2 = QString::number(tl.x())+"\n"+QString::number(tl.y())+"\n"+QString::number(br.x())+"\n"+QString::number(br.y());

}

QRectF MaskGraphicsItem::boundingRect() const
{
    const auto& aabb = _mask->aabb();

    auto&& lower = aabb.lower();
    auto&& upper = aabb.upper();

    qreal w = upper[0] - lower[0];
    qreal h = upper[1] - lower[1];

    return QRectF(-w/2,-h/2,w,h);
}
