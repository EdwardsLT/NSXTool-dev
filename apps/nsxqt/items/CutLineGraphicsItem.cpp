#include <algorithm>
#include <numeric>

#include <Eigen/Dense>

#include <QDrag>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QMimeData>
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>

#include "CutLineGraphicsItem.h"
#include "DetectorSceneModel.h"
#include "SimplePlot.h"
#include "SXPlot.h"

CutLineGraphicsItem::CutLineGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent)
: CutterGraphicsItem(data,from,parent),
  _nPoints(10)
{
}

SXPlot* CutLineGraphicsItem::plot() const
{
    SXPlot *plot = new SimplePlot();

    plot->xAxis->setLabel("Interpolation point");
    plot->yAxis->setLabel("Intensity (counts)");

    QVector<double> x(_nPoints);
    QVector<double> y(_nPoints);
    QVector<double> e(_nPoints);

    QLineF line;
    line.setP1(sceneBoundingRect().bottomLeft());
    line.setP2(sceneBoundingRect().topRight());

    auto *detector_scene_model = dynamic_cast<DetectorSceneModel*>(scene());
    const rowMatrix& current_frame = detector_scene_model->currentFrame();

    std::iota(x.begin(),x.end(),0);

    for (int i=0; i<_nPoints; ++i) {

        QPointF point=line.pointAt(i/static_cast<double>(_nPoints));
        int ipx=static_cast<int>(point.x());
        int ipy=static_cast<int>(point.y());
        QPoint lowestCorner = QPoint(ipx,ipy);
        double sdist2 = 0.0;

        for (int pi=0;pi<2;++pi) {
            for (int pj=0;pj<2;++pj) {
                QPoint currentCorner = lowestCorner + QPoint(pi,pj);
                QPointF dp = point - currentCorner;
                double dist2 = dp.x()*dp.x() + dp.y()*dp.y();
                int count = current_frame(currentCorner.y(),currentCorner.x());
                y[i] += dist2*count;
                sdist2 += dist2;
            }
        }
        y[i] /= sdist2;
    }
    std::transform(y.begin(),y.end(),e.begin(),[](double y_val){ return sqrt(y_val);});
    plot->graph(0)->setDataValueError(x, y, e);
    plot->rescaleAxes();
    plot->replot();

    return plot;
}

void CutLineGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(widget);

    // Color depending on selection
    if (option->state & QStyle::State_Selected) {
       _pen.setStyle(Qt::DashLine);
    } else {
       _pen.setStyle(Qt::SolidLine);
    }
    painter->setRenderHint(QPainter::HighQualityAntialiasing);
    painter->setPen(_pen);
    qreal w=_to.x()-_from.x();
    qreal h=_to.y()-_from.y();
    painter->drawLine(-w/2,-h/2,w/2,h/2);
}

void CutLineGraphicsItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (!isVisible()) {
        return;
    }

    if (!isSelected()) {
        return;
    }
    _nPoints += event->delta()>0 ? 1 : -1;
    if (_nPoints <= 0) {
        _nPoints = 1;
    }

    CutterGraphicsItem::wheelEvent(event);
}

