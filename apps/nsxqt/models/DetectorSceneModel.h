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
    enum class INTERACTION_MODE {SELECT=0, ZOOM=1, CUTLINE=2, HORIZONTAL_SLICE=3, VERTICAL_SLICE=4, MASK=5, COUNT=6};

    //! Which mode is the cursor diplaying
    enum class CURSOR_MODE {PIXEL=0, GAMMA_NU=1, THETA=2, D_SPACING=3, MILLER_INDICES=4, COUNT=5};

    explicit DetectorSceneModel(SessionModel *session_model);

    const rowMatrix& currentFrame() const;

    void loadCurrentImage();

    void changeColorMap(const ColorMap& color_map);

    void changeContrastLevel(int contrast);

    void changeCursorMode(CURSOR_MODE cursor_mode);

    void changeEnabledPeak(nsx::sptrPeak3D peak);

    void changeInteractionMode(INTERACTION_MODE interaction_mode);

    void changeMaskedPeaks(const nsx::PeakList& peaks);

    void changeSelectedData(nsx::sptrDataSet peak, int frame);

    void changeSelectedFrame(int frame);

    void changeSelectedPeak(nsx::sptrPeak3D peak);

    template <typename T>
    void clearGraphicsItems();

    int contrastLevel() const;

    int currentFrameIndex() const;

    void resetScene();

    void restoreMasks();

    void restorePeaks();

    template <typename T>
    std::set<T*> selectGraphicsItems();

    SessionModel* sessionModel();

    void setLogarithmicScale(bool flag);

    void showPeakLabels(bool flag);

    void showPeakCenters(bool flag);

    void showPeakBox(nsx::sptrPeak3D peak);

    void showPeakIntegrationAreas(bool);

    void setInitialMousePosition(const QPointF& position);

    void setFinalMousePosition(const QPointF& position);

protected:

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

signals:

    void signalDetectorSceneChanged();

    void signalChangeSelectedData(nsx::sptrDataSet data);

    void signalChangeSelectedFrame(int selected_frame);

    void signalChangeSelectedPeak(nsx::sptrPeak3D peak);

private:

    void drawIntegrationRegion();

    void zoomIn();

    void zoomOut();

    //! Create the text of the tooltip depending on Scene Mode.
    void createToolTipText(QGraphicsSceneMouseEvent*);

private:

    SessionModel* _session_model;

    nsx::sptrDataSet _data;

    unsigned long _current_frame_index;

    int _contrast_level;

    rowMatrix _current_frame;

    ColorMap _color_map;

    CURSOR_MODE _cursor_mode;

    //! Current interaction mode
    INTERACTION_MODE _interaction_mode;

    //! Graphics Window representing the zoomed area
    QGraphicsRectItem* _zoom_window;

    //! Stack of zoom
    QStack<QRectF> _zoom_stack;

    QGraphicsPixmapItem* _image;
    
    SXGraphicsItem* _current_graphics_item;

    bool _logarithmic_scale;

    bool _draw_integration_region;

    QGraphicsPixmapItem* _integration_region;

    QPointF _top_left_position;

    QPointF _bottom_right_position;

    bool _show_peak_labels;

    bool _show_peak_centers;

    bool _show_peak_boxes;

    nsx::sptrPeak3D _selected_peak;
};

template <typename T>
void DetectorSceneModel::clearGraphicsItems()
{
    for (auto item : items()) {
        auto *graphics_item = dynamic_cast<T*>(item);
        if (graphics_item) {
            removeItem(graphics_item);
            delete graphics_item;
        }
    }
}

template <typename T>
std::set<T*> DetectorSceneModel::selectGraphicsItems()
{
    std::set<T*> graphics_items;
    for (auto item : items()) {
        auto *graphics_item = dynamic_cast<T*>(item);
        if (graphics_item) {
            graphics_items.insert(graphics_item);
        }
    }
    return graphics_items;
}

