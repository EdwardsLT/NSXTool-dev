#ifndef DETECTORVIEW_H
#define DETECTORVIEW_H
#include <QGraphicsView>
#include <QWidget>
#include <QMouseEvent>
#include <QToolTip>
#include "Data.h"
#include "Plotter1D.h"
#include <QStack>
#include "PeakPlotter.h"

class SliceRect;

class DetectorView : public QGraphicsView
{
    Q_OBJECT
public:
    enum CrossMode {THETA, GAMMA, D, PIXEL};
    //
    enum CutterMode {ZOOM=0, LINE=1, HORIZONTALSLICE=2, VERTICALSLICE=3};

    DetectorView(QWidget* parent);
    // Set the number of pixels in the detector
    void setNpixels(int hor,int vert);
    // Set the dimensions of the detector
    void setDimensions(double gammaRange, double height);
    // Set the detector distance
    void setDetectorDistance(double distance);
    // Is Data present
    bool hasData() const;
public slots:
    // Add a cut line to the scene.
    void addCutLine(double xstart, double ystart, double xend, double yend);
    // Add a horizontal cut slicer to the scene.
    void addHorizontalCutSlice(double x, double y, double width, double height);
    // Add a vertical cut slicer to the scene.
    void addVerticalCutSlice(double x, double y, double width, double height);
    // Remove a cut line from the scene.
    void removeCutLine(int idx);
    // Remove a horizontal cut slicer from the scene.
    void removeHorizontalCutSlice(int idx);
    // Remove a vertical cut slicer from the scene.
    void removeVerticalCutSlice(int idx);
    // Remove all cut objects (line/horizontal/vertical cutters) from the scene.
    void clearCutObjects();
    // Remove all cut line from the scene.
    void clearCutLines();
    // Remove all horizontal cut slicers from the scene.
    void clearHorizontalCutSlices();
    // Remove all vertical cut slicers from the scene.
    void clearVerticalCutSlices();
    // Remove all graphs from the plotter.
    void clearPlotter();
    void updateView(Data* ptr,int frame);
    void setCutterMode(int i);
    // Set the zoom window to (x1,x2,y1,y2) in detector space coordinates;
    void setZoom(int x1,int y1, int x2, int y2);
    void setMaxIntensity(int);
    // Register this zoom level in the stack
    void registerZoomLevel(int xmin, int xmax, int ymin, int ymax);
    // Go to previous zoom level
    void setPreviousZoomLevel();
    // Integrate in vertical direction
    void integrateVertical(int xmin,int xmax, int ymin, int ymax, QVector<double>& projection, QVector<double>& error);
    // Integrate in horizontal direction
    void integrateHorizontal(int xmin,int xmax, int ymin, int ymax, QVector<double>& projection, QVector<double>& error);

protected:
    // Mouse events
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);
    void detectorToScene(double& x, double& y);
    void sceneToDetector(double& x, double& y);
    void keyPressEvent(QKeyEvent* event);
    void wheelEvent(QWheelEvent *event);
private:
    // Copy the current view to the clipboard.
    void copyViewToClipboard();
    //
    void plotIntensityMap();
    //
    void plotEllipsoids();
    //
    void updatePlot();
    // Get gamma,nu in degrees for a pixel at (x,y) in detector space
    void getGammaNu(double x, double y, double& gamma, double& nu);
    // Get 2theta in degrees for a pixel (x,y) in detector space.
    void get2Theta(double x, double y, double& th2);
    // Get d-spacing for a pixel (x,y) in detector space
    void getDSpacing(double x, double y, double& dspacing);
    // Update the horizontal cut slicer.
    void updateHorizontalSliceCutter();
    // Update line cutter, x and y in scene coordinates
    void updateLineCutter();
    // Update the vertical cut slicer.
    void updateVerticalSliceCutter();
    // Update zoom cutter, x and y in scene coordinates
    void updateZoomCutter(const QPointF&);
    // Check pixel x y is in the detector scene
    bool pointInScene(const QPointF&);
    // Pointer to Data
    Data* _ptrData;
    int pixels_h;
    int pixels_v;
    // Width of detector in gamma
    double _gammawidth;
    // Height of detector in m
    double _height;
    // Distance of detector
    double _distance;
    // Pointer to the scene
    QGraphicsScene* _scene;
    // Mode for cursor information
    CrossMode _mode;
    //
    CutterMode _cutterMode;
    QGraphicsRectItem *_zoom;
    //
    QImage* _currentImage;

    //
    Plotter1D* _cutPloter;
    // Zoom corners in detector space coordinates.
    int _zoomLeft, _zoomTop, _zoomRight, _zoomBottom;
    double _maxIntensity;
    // Maintain the stack of zoom levels
    QStack<QRect> _zoomStack;
    int _currentFrame;
    double _previousX, _previousY;
    Plotter1D* _plotter;
    int _sliceThickness;
    QGraphicsPixmapItem *_pixmap;
    QList<QGraphicsRectItem*> _currentPeaks;
    PeakPlotter* _peakplotter;
    int _nCutPoints;

    QList<SliceRect*> _hSlices,_vSlices;
    int _selectedSlice, _selectedLine;

    QList<QGraphicsLineItem*> _lines;

    static QStringList _lineColors;

};

#endif // DETECTORVIEW_H