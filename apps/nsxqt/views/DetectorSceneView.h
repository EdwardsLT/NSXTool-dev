#pragma once

#include <QGraphicsView>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QTransform>

class DetectorSceneModel;
class MainWindow;

class DetectorSceneView : public QGraphicsView
{
    Q_OBJECT
public:

    explicit DetectorSceneView(MainWindow *main_window);

    void resizeEvent(QResizeEvent *event);

    virtual void keyPressEvent(QKeyEvent* event) override;

    void fitScene();

public slots:

    void onChangeDetectorViewTransformation(const QTransform &transformation);

private:

    void displayContextualMenu(const QPoint& point);

    void copyViewToClipboard();

private:

    MainWindow *_main_window;

    DetectorSceneModel* _detector_scene_model;
};
