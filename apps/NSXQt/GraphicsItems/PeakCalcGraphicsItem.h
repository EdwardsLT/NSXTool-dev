#ifndef PEAKCALCGRAPHICSITEM_H
#define PEAKCALCGRAPHICSITEM_H
#include "SXGraphicsItem.h"

namespace SX{
    namespace Crystal{
        class PeakCalc;
    }
}

class PeakCalcGraphicsItem : public SXGraphicsItem
{
public:
    PeakCalcGraphicsItem(SX::Crystal::PeakCalc);
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
     void setFrame(int frame);
     static void setLabelVisible(bool flag=true);
     virtual QRectF boundingRect() const;
private:
     double _x, _y, _frame;
      static bool _labelVisible;
};

#endif // PEAKCALCGRAPHICSITEM_H