#include <algorithm>
#include <numeric>

#include <Eigen/Dense>

#include <QGraphicsSceneWheelEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <nsxlib/AABB.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/Mask.h>

#include "DetectorSceneModel.h"
#include "MaskGraphicsItem.h"
#include "SessionModel.h"

MaskGraphicsItem::MaskGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent)
: DrawableGraphicsItem(data,from,parent),
  _mask(std::shared_ptr<nsx::Mask>(new nsx::Mask(nsx::AABB())))
{
    _pen.setWidth(1);
    _pen.setCosmetic(true);
    _pen.setStyle(Qt::SolidLine);

    _text = new QGraphicsTextItem(this);
    _text->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    _text->setParentItem(this);

    _data->addMask(_mask);
}

void MaskGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)

    QPointF tl = sceneBoundingRect().topLeft();
    QPointF br = sceneBoundingRect().bottomRight();

    _mask->aabb().setLower({tl.x(),tl.y(),0});

    _mask->aabb().setUpper({br.x(),br.y(),static_cast<double>(_data->nFrames())});

    _data->addMask(_mask);

    auto *detector_scene_model = dynamic_cast<DetectorSceneModel*>(scene());
    if (detector_scene_model) {
        emit detector_scene_model->sessionModel()->signalMaskedPeaksChanged(_data);
    }
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

void MaskGraphicsItem::keyPressEvent(QKeyEvent* event)
{
    if (!isSelected()) {
        return;
    }

    // The user pressed on Delete key
    if (event->key() == Qt::Key_Delete) {
        _data->removeMask(_mask);
    }
}
