#pragma once

#include <QGraphicsView>
#include <QKeyEvent>
#include <QResizeEvent>

class DetectorSceneModel;
class MainWindow;

class DetectorSceneView : public QGraphicsView
{
    Q_OBJECT
public:

    explicit DetectorSceneView(MainWindow *main_window);

    void resizeEvent(QResizeEvent *event);

    DetectorSceneModel* getScene();

    void keyPressEvent(QKeyEvent* event);

    void fitScene();

private:

    void copyViewToClipboard();

private:

    DetectorSceneModel* _detector_scene_model;
};
