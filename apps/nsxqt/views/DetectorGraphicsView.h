#ifndef NSXQT_DETECTORGRAPHICSVIEW_H
#define NSXQT_DETECTORGRAPHICSVIEW_H

#include <QGraphicsView>

class DetectorScene;
class DetectorGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit DetectorGraphicsView(QWidget *parent = 0);
    void resizeEvent(QResizeEvent *event);
    DetectorScene* getScene();
    void keyPressEvent(QKeyEvent* event);
signals:
public slots:
    void fitScene();
    void fixDetectorAspectRatio(bool);
private:
    void copyViewToClipboard();
    DetectorScene* _scene;
};

#endif // NSXQT_DETECTORGRAPHICSVIEW_H
