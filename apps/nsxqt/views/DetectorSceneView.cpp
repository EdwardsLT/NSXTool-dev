#include <QApplication>
#include <QClipboard>
#include <QMouseEvent>
#include <QPainter>

#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/IDataReader.h>

#include "DetectorSceneModel.h"
#include "DetectorSceneView.h"
#include "MainWindow.h"

DetectorSceneView::DetectorSceneView(MainWindow *main_window) : QGraphicsView(main_window), _detector_scene_model(main_window->detectorSceneModel())
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);

    // Make sure that first views are rescaled, especially first created one
    connect(_detector_scene_model,&DetectorSceneModel::dataChanged,this,[&](){fitInView(_detector_scene_model->sceneRect());});

    setMouseTracking(true);

    viewport()->setMouseTracking(true);

    setInteractive(true);

    // Invert the y-axis so that (0,0) coordinate is at bottom left (and not top left)
    // This match detector coordinates in NSXTool
    scale(1,-1);

    setContextMenuPolicy(Qt::CustomContextMenu);
}

void DetectorSceneView::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    fitInView(_detector_scene_model->sceneRect());
}

DetectorSceneModel* DetectorSceneView::getScene()
{
    return _detector_scene_model;
}

void DetectorSceneView::copyViewToClipboard()
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

void DetectorSceneView::keyPressEvent(QKeyEvent* event)
{
    if (event->matches(QKeySequence::Copy)) {
        copyViewToClipboard();
    }
    QGraphicsView::keyPressEvent(event);
}

void DetectorSceneView::fitScene()
{
    fitInView(_detector_scene_model->sceneRect());
}
