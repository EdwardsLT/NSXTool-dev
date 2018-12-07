#pragma once

#include <map>
#include <vector>
#include <utility>

#include <Eigen/Dense>

#include <QRect>
#include <QStack>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/DataTypes.h>
#include <nsxlib/IMask.h>

#include "ColorMap.h"

class CutterGraphicsItem;
class EllipseMaskGraphicsItem;
class QImage;
class QGraphicsSceneWheelEvent;
class MaskGraphicsItem;
class PeakGraphicsItem;
class PlottableGraphicsItem;
class SessionModel;
class SXGraphicsItem;

// For the plotting part, better to have RowMajor matrix to use QImage scanline function and
// optimize cache hit.
typedef Eigen::Matrix<int,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> rowMatrix;

//! Master Scene containing the pixmap of the detector counts
//! and overlayed graphics items (peaks, data cutters, masks ...)
class DetectorSceneModel: public QGraphicsScene
{
    Q_OBJECT

public:
    enum class INTERACTION_MODE {SELECT=0, ZOOM=1, CUTLINE=2, HORIZONTAL_SLICE=3, VERTICAL_SLICE=4, RECTANGULAR_MASK=5, ELLIPSOIDAL_MASK=6};

    //! Which mode is the cursor diplaying
    enum class CURSOR_MODE {PIXEL=0, GAMMA_NU=1, THETA=2, D_SPACING=3, MILLER_INDICES=4};

    explicit DetectorSceneModel(SessionModel *session_model);

    nsx::sptrDataSet getData();

    const rowMatrix& getCurrentFrame() const;

    void loadCurrentImage();

    void clearPeakGraphicsItems();

    void changeMaxIntensity(int max_intensity);

    void changeSelectedData(nsx::sptrDataSet peak, int frame);

    void changeSelectedFrame(int frame);

    void changeSelectedPeak(nsx::sptrPeak3D peak);

    void changeEnabledPeak(nsx::sptrPeak3D peak);

    void changeMaskedPeaks(const nsx::PeakList& peaks);

    void showPeakLabels(bool flag);

    void showPeakCenters(bool flag);

    void showPeakIntegrationAreas(bool);

    int maxIntensity() const;

    int currentFrame() const;

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

    void wheelEvent(QGraphicsSceneWheelEvent *event);

public slots:

    void onResetScene();

    void resetPeakGraphicsItems();

    void changeInteractionMode(INTERACTION_MODE interaction_mode);

    void changeCursorMode(CURSOR_MODE cursor_mode);

    void updateMasks();

    void onSetLogarithmicScale(bool flag);

    void onChangeColorMap(const ColorMap& color_map);

signals:
     //! Signal emitted for all changes of the image
    void dataChanged();

    void signalHoverPlottableGraphicsItem(PlottableGraphicsItem* cutter);

    void signalChangeSelectedData(nsx::sptrDataSet data);

    void signalChangeSelectedFrame(int selected_frame);

    void signalChangeSelectedPeak(nsx::sptrPeak3D peak);

private:

    //! Create the text of the tooltip depending on Scene Mode.
    void createToolTipText(QGraphicsSceneMouseEvent*);

    // find the iterator corresponding to given graphics item
    std::vector<std::pair<QGraphicsItem*, nsx::IMask*>>::iterator findMask(QGraphicsItem* item);

private:

    SessionModel* _session_model;

    nsx::sptrDataSet _currentData;

    unsigned long _currentFrameIndex;

    int _max_intensity;

    rowMatrix _currentFrame;

    ColorMap _color_map;

    CURSOR_MODE _cursor_mode;

    //! Current interaction mode
    INTERACTION_MODE _interaction_mode;

    //! Point coordinates of the start of zoom region
    QPoint _zoomstart;

    //! Point coordinates of the end of zoom regiom
    QPoint _zoomend;

    //! Graphics Window representing the zoomed area
    QGraphicsRectItem* _zoomrect;

    //! Stack of zoom
    QStack<QRect> _zoomStack;

    bool _itemSelected;

    QGraphicsPixmapItem* _image;

    std::vector<std::pair<QGraphicsItem*, nsx::IMask*>> _masks;
    
    SXGraphicsItem* _lastClickedGI;

    bool _logarithmic_scale;

    bool _drawIntegrationRegion;

    QGraphicsPixmapItem* _integrationRegion;

    QGraphicsRectItem* _selected_peak_gi;

    std::map<nsx::sptrPeak3D,PeakGraphicsItem*> _peak_graphics_items;

    nsx::sptrPeak3D _selected_peak;
};
