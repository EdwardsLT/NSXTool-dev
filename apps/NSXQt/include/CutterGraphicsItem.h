#ifndef CUTTERGRAPHICSITEM_H
#define CUTTERGRAPHICSITEM_H

#include <QPen>
#include <QPointF>

#include "PlottableGraphicsItem.h"

namespace SX
{
namespace Data
{
class IData;
}
}

class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QWidget;
class SXCustomPlot;

class CutterGraphicsItem : public PlottableGraphicsItem
{
public:

    // Constructors and destructor

    //! Constructs a data cutter
    CutterGraphicsItem(SX::Data::IData* data);
    //! Destructor
    virtual ~CutterGraphicsItem();

    // Events

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    // Getters and setters

    //! Returns the bounding rectangle of the item
    QRectF boundingRect() const;
    //! Returns the data bound to the item
    SX::Data::IData* getData();
    //! Sets the top left corner of the item
    void setFrom(const QPointF& pos);
    //! Sets the bottom right corner of the item
    void setTo(const QPointF& pos);

    // Other methods

//    //! Return an instance of the plot related to the item [pure virtual]
//    virtual SXCustomPlot* createPlot(QWidget* parent=0)=0;
    //! Paint the contents of the item [pure virtual]
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;


protected:
    //! The data on which the cutter will act upon
    SX::Data::IData* _data;
    //! The top left coordinates of the slice
    QPointF _from;
    //! The bottom right coordinates of the slice
    QPointF _to;


};

#endif // CUTTERGRAPHICSITEM_H
