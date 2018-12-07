#include <algorithm>
#include <numeric>

#include <QPainter>
#include <QGraphicsSceneWheelEvent>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <Eigen/Dense>

#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/IDataReader.h>

#include "CutSliceGraphicsItem.h"
#include "DetectorSceneModel.h"
#include "SimplePlot.h"
#include "SXPlot.h"

CutSliceGraphicsItem::CutSliceGraphicsItem(nsx::sptrDataSet data, bool horizontal)
: CutterGraphicsItem(data),
  _horizontal(horizontal)
{
}

SXPlot* CutSliceGraphicsItem::plot() const
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

    bool horizontal = isHorizontal();

    int dx = xmax-xmin;
    int dy = ymax-ymin;

    if (horizontal) {
        length = dx;
        start = xmin;
    } else {
        length = dy;
        start = ymin;
    }

    QVector<double> x(length);
    QVector<double> y(length);
    QVector<double> e(length);
    std::iota(x.begin(),x.end(),start);

    auto *detector_scene_model = dynamic_cast<DetectorSceneModel*>(scene());
    const rowMatrix& current_frame = detector_scene_model->currentFrame();

    if (horizontal) {
        int comp=0;
        for (int i=xmin;i<xmax;++i) {
            y[comp++] = current_frame.col(i).segment(ymin,dy).sum();
        }
    } else {
        int comp=0;
        for (int i=ymin;i<ymax;++i) {
            y[comp++] = current_frame.row(i).segment(xmin,dx).sum();
        }
    }
    std::transform(y.begin(),y.end(),e.begin(),[](double p){ return sqrt(p);});
    plot->graph(0)->setDataValueError(x,y,e);
    plot->rescaleAxes();
    plot->replot(QCustomPlot::rpHint);

    return plot;
}

bool CutSliceGraphicsItem::isHorizontal() const
{
    return _horizontal;
}

void CutSliceGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(widget);

    if (_horizontal) {
        painter->setBrush(QBrush(QColor(0,255,0,50)));
    } else {
        painter->setBrush(QBrush(QColor(0,0,255,50)));
    }
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

std::string CutSliceGraphicsItem::getPlotType() const
{
    return "simple";
}

void CutSliceGraphicsItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (!isVisible()) {
        return;
    }
    if (!isSelected()) {
        return;
    }
    int step=event->delta()/120;

    if (_horizontal) {
        _from += QPointF(0,-step);
        _to += QPointF(0,step);
    } else {
        _from += QPointF(-step,0);
        _to += QPointF(step,0);
    }
    update();
}
