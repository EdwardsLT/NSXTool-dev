#include <QApplication>
#include <QClipboard>
#include <QMouseEvent>
#include <QPainter>

#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/IDataReader.h>

#include "DetectorMenu.h"
#include "DetectorSceneModel.h"
#include "DetectorSceneView.h"
#include "MainWindow.h"
#include "SessionModel.h"

DetectorSceneView::DetectorSceneView(MainWindow *main_window) : QGraphicsView(main_window), _main_window(main_window),_detector_scene_model(main_window->detectorSceneModel())
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);

    // Make sure that first views are rescaled, especially first created one
    connect(_detector_scene_model,&DetectorSceneModel::signalDetectorSceneChanged,this,[&](){fitInView(_detector_scene_model->sceneRect());});

    setMouseTracking(true);

    viewport()->setMouseTracking(true);

    setInteractive(true);

    setTransform(_main_window->sessionModel()->detectorViewTranformation());

    setContextMenuPolicy(Qt::CustomContextMenu);

    connect(_main_window->sessionModel(),&SessionModel::signalChangeDetectorViewTransformation,this,&DetectorSceneView::onChangeDetectorViewTransformation);

    connect(this,&DetectorSceneView::customContextMenuRequested,[=](const QPoint& point){displayContextualMenu(point);});
}

void DetectorSceneView::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    fitInView(_detector_scene_model->sceneRect());
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

void DetectorSceneView::onChangeDetectorViewTransformation(const QTransform& transformation)
{
    setTransform(transformation);
    fitScene();
}

void DetectorSceneView::displayContextualMenu(const QPoint& point)
{
    auto *detector_menu = new DetectorMenu(_main_window);
    detector_menu->setAttribute(Qt::WA_DeleteOnClose);
    detector_menu->popup(viewport()->mapToGlobal(point));
}
