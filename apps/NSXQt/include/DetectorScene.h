#ifndef DETECTORSCENE_H
#define DETECTORSCENE_H

#include <set>

#include <QRect>
#include <QStack>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

// Forward declarations
namespace SX
{
namespace Data
{
class IData;
}
namespace Crystal
{
class Peak3D;
}
}
class QImage;
class QGraphicsSceneWheelEvent;
class PeakGraphicsItem;
class PlottableGraphicsItem;

//! Master Scene containing the pixmap of the detector counts
//! peaks, and other Graphics Items
class DetectorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum MODE {ZOOM=0, LINE=1, HORIZONTALSLICE=2, VERTICALSLICE=3};
    //! Which mode is the cursor diplaying
    enum CURSORMODE {THETA=0, GAMMA=1, DSPACING=2, PIXEL=3, HKL=4};
    explicit DetectorScene(QObject *parent = 0);
    SX::Data::IData* getData();
    const std::vector<int>& getCurrentFrame() const;

signals:
     //! Signal emitted for all changes of the image
    void dataChanged();
    void updatePlot(PlottableGraphicsItem* cutter);
    //!
    void plotPeak(SX::Crystal::Peak3D*);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);

public slots:
    // To be called to update detector image
    void setData(SX::Data::IData*,int frame);
    void setData(SX::Data::IData*);
    void changeFrame(int frame=0);
    void setMaxIntensity(int);
    void updatePeaks();
    //! Change interaction mode in the scene
    void changeInteractionMode(int);
    //!
    void changeCursorMode(int);
private:

    //! Load image from current Data and frame
    void loadCurrentImage();
    //! Create the text of the tooltip depending on Scene Mode.
    void createToolTipText(QGraphicsSceneMouseEvent*);
    //! Point coordinates of the start of zoom region
    QPoint _zoomstart;
    //! Point coordinates of the end of zoom regiom
    QPoint _zoomend;
    //! Graphics Window representing the zoomed area
    QGraphicsRectItem* _zoomrect;
    // Stack of zoom
    QStack<QRect> _zoomStack;
    SX::Data::IData* _currentData;
    int _currentFrameIndex;
    int _currentIntensity;
    std::vector<int> _currentFrame;
    //! Current interaction mode
    MODE _mode;
    CURSORMODE _cursorMode;
    //! Contains peaks item of current data, reinitialized with new data set.
    std::set<PeakGraphicsItem*> _peaks;
    PlottableGraphicsItem* _currentItem;
    bool _itemSelected;
    QGraphicsPixmapItem* _image;
};

#endif // DETECTORSCENE_H
