#pragma once

#include <QGraphicsView>
#include <QKeyEvent>
#include <QResizeEvent>

class DetectorScene;
class MainWindow;

class DetectorGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:

    explicit DetectorGraphicsView(MainWindow *main_window);

    void resizeEvent(QResizeEvent *event);

    DetectorScene* getScene();

    void keyPressEvent(QKeyEvent* event);

public:

    void fixDetectorAspectRatio(bool);

    void fitScene();

private:

    void copyViewToClipboard();

private:

    DetectorScene* _detector_scene_model;
};
