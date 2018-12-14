#include <algorithm>
#include <numeric>

#include <Eigen/Dense>

#include <QPainter>
#include <QGraphicsSceneWheelEvent>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/IDataReader.h>

#include "DetectorSceneModel.h"
#include "HorizontalSliceGraphicsItem.h"
#include "SimplePlot.h"
#include "SXPlot.h"

HorizontalSliceGraphicsItem::HorizontalSliceGraphicsItem(nsx::sptrDataSet data, const QPointF& from, QGraphicsItem *parent)
: CutterGraphicsItem(data,from,parent)
{
}

SXPlot* HorizontalSliceGraphicsItem::plot() const
{
    auto *plot = new SimplePlot();

    plot->xAxis->setLabel("Frame (a.u.)");
    plot->yAxis->setLabel("Intensity (counts)");

    auto detector = _data->reader()->diffractometer()->detector();
    
    int nrows = detector->nRows();
    int ncols = detector->nCols();

    // Define the position on the scene of the cutter
    int xmin = sceneBoundingRect().left();
    int xmax = sceneBoundingRect().right();
    int ymin = sceneBoundingRect().top();
    int ymax = sceneBoundingRect().bottom();

    xmin = std::max(xmin,0);
    xmax = std::min(xmax,ncols);
    ymin = std::max(ymin,0);
    ymax = std::min(ymax,nrows);

    int length;
    int start;

    int dx = xmax-xmin;
    int dy = ymax-ymin;

    length = dx;
    start = xmin;

    QVector<double> x(length);
    QVector<double> y(length);
    QVector<double> e(length);
    std::iota(x.begin(),x.end(),start);

    auto *detector_scene_model = dynamic_cast<DetectorSceneModel*>(scene());
    const rowMatrix& current_frame = detector_scene_model->currentFrame();

    int comp=0;
    for (int i=xmin;i<xmax;++i) {
        y[comp++] = current_frame.col(i).segment(ymin,dy).sum();
    }

    std::transform(y.begin(),y.end(),e.begin(),[](double p){ return sqrt(p);});
    plot->graph(0)->setDataValueError(x,y,e);
    plot->rescaleAxes();
    plot->replot(QCustomPlot::rpHint);

    return plot;
}

void HorizontalSliceGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(widget);

    painter->setBrush(QBrush(QColor(0,255,0,50)));

    // Color depending on selection
    if (option->state & QStyle::State_Selected) {
        _pen.setStyle(Qt::DashLine);
    } else {
        _pen.setStyle(Qt::SolidLine);
    }
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(_pen);
    qreal w=std::abs(_to.x()-_from.x());
    qreal h=std::abs(_to.y()-_from.y());
    painter->drawRect(-w/2.0,-h/2.0,w,h);
}

void HorizontalSliceGraphicsItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (!isVisible()) {
        return;
    }

    if (!isSelected()) {
        return;
    }

    int step = event->delta()/120;

    _from += QPointF(0,-step);
    _to += QPointF(0,step);

    CutterGraphicsItem::wheelEvent(event);
}
