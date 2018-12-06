#include <QApplication>
#include <QClipboard>
#include <QMouseEvent>
#include <QPainter>

#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/IDataReader.h>

#include "DetectorGraphicsView.h"
#include "DetectorScene.h"
#include "MainWindow.h"

DetectorGraphicsView::DetectorGraphicsView(MainWindow *main_window) : QGraphicsView(main_window), _detector_scene_model(main_window->detectorSceneModel())
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);

    // Make sure that first views are rescaled, especially first created one
    connect(_detector_scene_model,&DetectorScene::dataChanged,this,[&](){fitInView(_detector_scene_model->sceneRect());});

    setMouseTracking(true);

    viewport()->setMouseTracking(true);

    setInteractive(true);

    // Invert the y-axis so that (0,0) coordinate is at bottom left (and not top left)
    // This match detector coordinates in NSXTool
    scale(1,-1);

    setContextMenuPolicy(Qt::CustomContextMenu);
}

void DetectorGraphicsView::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    fitInView(_detector_scene_model->sceneRect());
}

DetectorScene* DetectorGraphicsView::getScene()
{
    return _detector_scene_model;
}

void DetectorGraphicsView::copyViewToClipboard()
{
    // Create the image with the exact size of the shrunk scene
    QImage image(this->rect().size(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter painter;
    painter.begin(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    this->render(&painter);
    painter.end();
    QApplication::clipboard()->setImage(image,QClipboard::Clipboard);
}

void DetectorGraphicsView::keyPressEvent(QKeyEvent* event)
{
    if (event->matches(QKeySequence::Copy)) {
        copyViewToClipboard();
    }
    QGraphicsView::keyPressEvent(event);
}

void DetectorGraphicsView::fixDetectorAspectRatio(bool value)
{
    const auto* detector = _detector_scene_model->getData()->reader()->diffractometer()->detector();

    if (value) {
        int h = this->height();
        double dw = detector->width();
        double dh = detector->height();
        resize(int(h*dw/dh),h);
    } else {
        fitInView(_detector_scene_model->sceneRect());
    }
}

void DetectorGraphicsView::fitScene()
{
    fitInView(_detector_scene_model->sceneRect());
}
