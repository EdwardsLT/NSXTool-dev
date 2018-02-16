#include <Eigen/Dense>

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Ellipsoid.h>
#include <nsxlib/InstrumentState.h>
#include <nsxlib/IntegrationRegion.h>
#include <nsxlib/MetaData.h>
#include <nsxlib/MillerIndex.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/ReciprocalVector.h>
#include <nsxlib/UnitCell.h>
#include <nsxlib/Units.h>

#include "PeakGraphicsItem.h"
#include "PeakPlot.h"
#include "SXPlot.h"


bool PeakGraphicsItem::_labelVisible = false;
bool PeakGraphicsItem::_drawBackground = false;

PeakGraphicsItem::PeakGraphicsItem(nsx::sptrPeak3D p):
    PlottableGraphicsItem(nullptr,true,false),
    _peak(std::move(p)),
    _predictedCenter(0.0, 0.0, -1.0, -1.0)
{ 
    if (_peak) {
        Eigen::Vector3d c=_peak->getShape().center();
        setPos(c[0], c[1]);
    }
    _pen.setWidth(2);
    _pen.setCosmetic(true);
    _pen.setStyle(Qt::SolidLine);
    _pen.setColor(QColor(0,0,255,255));

    QString hkl;
    _label=new QGraphicsTextItem(this);
    //Ensure text is alwyas real size despite zoom
    _label->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    _label->setParentItem(this);
    setBoundingRegionGranularity(0.0);

    // A peak item is always put on foreground of the scene
    setZValue(2);
}

QRectF PeakGraphicsItem::boundingRect() const
{
    auto aabb = _peak->getShape().aabb();
    const Eigen::Vector3d& l = aabb.lower();
    const Eigen::Vector3d& u = aabb.upper();
    qreal w=u[0]-l[0];
    qreal h=u[1]-l[1];

    // currently debugging...

    if (w < 0.0) {
        //qDebug() << "width is less than zero!";
        w = 0.0;
    }

    if (h < 0.0) {
        //qDebug() << "height is less than zero!";
        h = 0.0;
    }

    return QRectF(-w/2.0,-h/2.0,w,h);
}

void PeakGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    if (!isVisible()) {
        return;
    }
    if (option->state & QStyle::State_Selected) {
        _pen.setStyle(Qt::DotLine);
    } else {
        _pen.setStyle(Qt::SolidLine);
    }
    painter->setRenderHint(QPainter::Antialiasing);

    if (_hovered) {
        painter->setBrush(QBrush(QColor(255,255,0,120)));
    }
    _label->setVisible(_hovered || _labelVisible);

    const auto aabb = _peak->getShape().aabb();
    const Eigen::Vector3d& peak_l = aabb.lower();
    const Eigen::Vector3d& peak_u = aabb.upper();
    qreal peak_w = peak_u[0]-peak_l[0];
    qreal peak_h = peak_u[1]-peak_l[1];

    _label->setPos(peak_w/2,peak_h/2);
    
    Eigen::Vector3d dx = _frameCenter - _peak->getShape().center();

    painter->setBrush(QBrush(QColor(127, 255, 127, 127)));
    //painter->drawEllipse(dx(0)-2, dx(1)-2, 4, 4);

    #if 0
    dx = _predictedCenter - _peak->getShape().center();
    painter->setBrush(QBrush(QColor(127, 127, 255, 255)));
    painter->drawEllipse(dx(0)-2, dx(1)-2, 4, 4);
    #endif
}

void PeakGraphicsItem::setFrame(unsigned long frame)
{
    const auto aabb = _peak->getShape().aabb();
    const Eigen::Vector3d& l = aabb.lower();
    const Eigen::Vector3d& u = aabb.upper();

    // out of bounds
    if (frame < l[2] || frame > u[2]) {
        setVisible(false);
        _label->setVisible(false);
        return;
    }

    setVisible(true);
    _label->setVisible(_labelVisible);
    QString hklString;

    if (auto cell = _peak->activeUnitCell()) {
        nsx::MillerIndex miller_index(_peak->q(), *cell);
        if (miller_index.indexed(cell->indexingTolerance())) {
            hklString = QString("%1,%2,%3").arg(miller_index[0]).arg(miller_index[1]).arg(miller_index[2]);
        } else {
            hklString = "unindexed";
        }
    } else {
        hklString = "no unit cell";
    }
    _label->setPlainText(hklString);
    _frameCenter = _peak->getShape().intersectionCenter({0,0,1.0}, {0, 0, double(frame)});
    _predictedCenter = _peak->predictCenter(frame);
}

std::string PeakGraphicsItem::getPlotType() const
{
    return "peak";
}

nsx::sptrPeak3D PeakGraphicsItem::getPeak()
{
    return _peak;
}

void PeakGraphicsItem::setLabelVisible(bool flag)
{
    _labelVisible = flag;
}

void PeakGraphicsItem::drawBackground(bool flag)
{
    _drawBackground = flag;
}

void PeakGraphicsItem::plot(SXPlot* plot)
{

    auto p=dynamic_cast<PeakPlot*>(plot);
    if (p == nullptr) {
        return;
    }

    const auto& rockingCurve =_peak->rockingCurve();
    const int N = int(rockingCurve.size());

    // Transform to QDouble
    QVector<double> q_frames(N);
    QVector<double> q_intensity(N);
    QVector<double> q_error(N);

    //Copy the data
    double center = std::round(_peak->getShape().center()(2));
    
    for (int i = 0; i < N; ++i) {
        q_frames[i]= center - i/2.0;
        q_intensity[i] = rockingCurve[i].value();
        q_error[i] = rockingCurve[i].sigma();
    }
    p->graph(0)->setDataValueError(q_frames, q_intensity, q_error);

    // Now update text info:
    Eigen::RowVector3d hkl;
    QString info;

    if (auto cell = _peak->activeUnitCell()) {
        nsx::MillerIndex miller_index(_peak->q(), *cell);
        if (miller_index.indexed(cell->indexingTolerance())) {
            info="(h,k,l):"+QString::number(miller_index[0])+","+QString::number(miller_index[1])+","+QString::number(miller_index[2]);
        } else {
            info = "unindexed";
        }
    } else {
        info = "no unit cell";
    }

    auto c = _peak->getShape().center();
    auto state = _peak->data()->interpolatedState(c[2]);
    auto position = _peak->data()->diffractometer()->getDetector()->pixelPosition(c[0], c[1]);
    double g = state.gamma(position);
    double n = state.nu(position);
    g/=nsx::deg;
    n/=nsx::deg;
    info+=" "+QString(QChar(0x03B3))+","+QString(QChar(0x03BD))+":"+QString::number(g,'f',2)+","+QString::number(n,'f',2)+"\n";
    double intensity=_peak->getScaledIntensity().value();
    double sI=_peak->getScaledIntensity().sigma();
    info+="Intensity ("+QString(QChar(0x03C3))+"I): "+QString::number(intensity)+" ("+QString::number(sI,'f',2)+")\n";
    double l = state.lorentzFactor(position);
    info+="Cor. int. ("+QString(QChar(0x03C3))+"I): "+QString::number(intensity/l,'f',2)+" ("+QString::number(sI/l,'f',2)+")\n";
    info += "p value (" + QString::number(_peak->pValue(), 'f', 3) + ")\n";

    double scale=_peak->getScale();
    double monitor=_peak->data()->metadata()->getKey<double>("monitor");
    info+="Monitor "+QString::number(monitor*scale)+" counts";
    QCPPlotTitle* title=dynamic_cast<QCPPlotTitle*>(p->plotLayout()->element(0,0));
    if (title != nullptr) {
        title->setText(info);
    }
    p->rescaleAxes();
    p->replot();
}
