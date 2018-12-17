#include <ctime>
#include <vector>

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QMenu>
#include <QPixmap>
#include <QToolTip>

#include <nsxlib/AABB.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Gonio.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/InstrumentState.h>
#include <nsxlib/IntegrationRegion.h>
#include <nsxlib/Logger.h>
#include <nsxlib/MillerIndex.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/ReciprocalVector.h>
#include <nsxlib/Sample.h>
#include <nsxlib/SpaceGroup.h>
#include <nsxlib/Source.h>
#include <nsxlib/UnitCell.h>
#include <nsxlib/Units.h>

#include "ColorMap.h"
#include "CutLineGraphicsItem.h"
#include "DetectorSceneModel.h"
#include "ExperimentItem.h"
#include "HorizontalSliceGraphicsItem.h"
#include "MaskGraphicsItem.h"
#include "MetaTypes.h"
#include "PeakGraphicsItem.h"
#include "SessionModel.h"
#include "UnitCellItem.h"
#include "UnitCellsItem.h"
#include "VerticalSliceGraphicsItem.h"

DetectorSceneModel::DetectorSceneModel(SessionModel *session_model)
: QGraphicsScene(nullptr),
  _session_model(session_model),
  _data(nullptr),
  _current_frame_index(0),
  _contrast_level(10),
  _current_frame(),
  _color_map(session_model->colorMap()),
  _cursor_mode(CURSOR_MODE::PIXEL),
  _interaction_mode(INTERACTION_MODE::SELECT),
  _zoom_window(nullptr),
  _zoom_stack(),
  _image(nullptr),
  _current_graphics_item(nullptr),
  _logarithmic_scale(false),
  _draw_integration_region(false),
  _integration_region(nullptr),
  _top_left_position(),
  _bottom_right_position(),
  _show_peak_labels(false),
  _show_peak_centers(false),
  _show_peak_boxes(false),
  _selected_peak(nullptr)
{
    connect(_session_model,&SessionModel::signalEnabledPeakChanged,this,&DetectorSceneModel::changeEnabledPeak);
    connect(_session_model,&SessionModel::signalSelectedDataChanged,this,&DetectorSceneModel::changeSelectedData);
    connect(_session_model,&SessionModel::signalChangeSelectedPeak,this,&DetectorSceneModel::changeSelectedPeak);
    connect(_session_model,&SessionModel::signalUpdatePeaks,this,&DetectorSceneModel::restorePeaks);
    connect(_session_model,&SessionModel::signalChangeColorMap,this,&DetectorSceneModel::changeColorMap);
}

void DetectorSceneModel::restoreMasks()
{
    if (!_data) {
        return;
    }

    clearGraphicsItems<MaskGraphicsItem>();
    auto masks = _data->masks();
    for (auto m : masks) {
        const auto& aabb = m->aabb();
        auto&& lower = aabb.lower();
        auto&& upper = aabb.upper();
        QRectF rect;
        rect.setBottomLeft(QPointF(lower[0],lower[1]));
        rect.setTopRight(QPointF(upper[0],upper[1]));
        auto *mask_graphics_item = new MaskGraphicsItem(_data,rect.topLeft());
        mask_graphics_item->setTo(rect.bottomRight());
        addItem(mask_graphics_item);
    }
}

void DetectorSceneModel::restorePeaks()
{
    if (!_data) {
        return;
    }

    clearGraphicsItems<PeakGraphicsItem>();

    auto peaks = _session_model->peaks(_data);

    // Loop over the peaks found for this dataset
    for (auto peak : peaks) {

        auto peak_ellipsoid = peak->shape();

        peak_ellipsoid.scale(peak->peakEnd());

        auto& aabb = peak_ellipsoid.aabb();

        auto&& lower = aabb.lower();
        auto&& upper = aabb.upper();

        // If the current frame of the scene is out of the peak bounds do not paint it
        if (_current_frame_index < lower[2] || _current_frame_index > upper[2]) {
            continue;
        }

        PeakGraphicsItem* peak_gi = new PeakGraphicsItem(peak,_current_frame_index);
        peak_gi->showLabel(_show_peak_labels);
        peak_gi->showCenter(_show_peak_centers);
        peak_gi->showBox(_show_peak_boxes);

        addItem(peak_gi);
    }
}

void DetectorSceneModel::changeEnabledPeak(nsx::sptrPeak3D peak)
{
    Q_UNUSED(peak)

    loadCurrentImage();

    update();
}

void DetectorSceneModel::changeMaskedPeaks(const nsx::PeakList& peaks)
{
    Q_UNUSED(peaks)

    loadCurrentImage();
}

void DetectorSceneModel::changeSelectedData(nsx::sptrDataSet data, int frame)
{
    resetScene();

    _data = data;

    _data->open();

    const auto* detector = _data->reader()->diffractometer()->detector();
    _zoom_stack.push_back(QRect(0,0,int(detector->nCols()),int(detector->nRows())));

    restoreMasks();

    changeSelectedFrame(frame);
}

void DetectorSceneModel::changeSelectedFrame(int frame)
{
    if (!_data) {
        return;
    }

    if (!_data->isOpened()) {
        _data->open();
    }

    _current_frame_index = frame;

    // Restore the peaks for this frame
    restorePeaks();

    loadCurrentImage();

    showPeakBox(_selected_peak);
}

void DetectorSceneModel::changeSelectedPeak(nsx::sptrPeak3D peak)
{
    if (!peak) {
        return;
    }

    _selected_peak = peak;

    auto peak_ellipsoid = _selected_peak->shape();

    size_t frame = size_t(std::lround(peak_ellipsoid.aabb().center()[2]));

    changeSelectedData(_selected_peak->data(),frame);

    showPeakBox(_selected_peak);
}


void DetectorSceneModel::showPeakBox(nsx::sptrPeak3D peak)
{
    auto peak_graphics_item = selectGraphicsItems<PeakGraphicsItem>();
    for (auto item : peak_graphics_item) {
        if (_selected_peak == item->peak()) {
            item->showBox(true);
            item->updatePlot();
            break;
        }
    }
    update();
}

int DetectorSceneModel::contrastLevel() const
{
    return _contrast_level;
}

SessionModel* DetectorSceneModel::sessionModel()
{
    return _session_model;
}

void DetectorSceneModel::changeContrastLevel(int contrast_level)
{
    if (!_data) {
        return;
    }

    if (!_data->isOpened()) {
        _data->open();
    }

    if (_contrast_level == contrast_level) {
        return;
    }

    _contrast_level = contrast_level;

    loadCurrentImage();
}

void DetectorSceneModel::setInitialMousePosition(const QPointF& position)
{
    _top_left_position = _bottom_right_position = position;
}

void DetectorSceneModel::setFinalMousePosition(const QPointF& position)
{
    auto min_x = std::min(_top_left_position.x(),position.x());
    auto min_y = std::min(_top_left_position.y(),position.y());

    auto max_x = std::max(_top_left_position.x(),position.x());
    auto max_y = std::max(_top_left_position.y(),position.y());

    _top_left_position.setX(min_x);
    _top_left_position.setY(max_y);

    _bottom_right_position.setX(max_x);
    _bottom_right_position.setY(min_y);
}

void DetectorSceneModel::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)

    // If no data is loaded, do nothing
    if (!_data) {
        return;
    }

    // Case of the zoom mode, update the scene
    if (_interaction_mode == INTERACTION_MODE::ZOOM) {
        zoomOut();
        return;
    }
}

void DetectorSceneModel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // If no data is loaded, do nothing
    if (!_data) {
        return;
    }

    if (event->modifiers() == Qt::ControlModifier) {
        return;
    }

    if (!event->buttons()) {
           createToolTipText(event);
    } else if (event->buttons() & Qt::LeftButton) {

        setFinalMousePosition(event->lastScenePos());

        // Case of the Zoom mode, update the scene
        if (_interaction_mode == INTERACTION_MODE::ZOOM) {
            if (_zoom_window) {
                _zoom_window->setRect(QRectF(_top_left_position,_bottom_right_position));
            }
            return;
        }

        if (_current_graphics_item) {
            _current_graphics_item->mouseMoveEvent(event);
        }
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void DetectorSceneModel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{    
    // If no data is loaded, do nothing
    if (!_data) {
        return;
    }

    // The left button was pressed
    if (event->buttons() & Qt::LeftButton) {

        // Keep track of the detector scene position when the event occured
        setInitialMousePosition(event->lastScenePos());

        // Declare those variable before outside switch scope to avoid cross-initialization compiler error
        SXGraphicsItem* current_graphics_item = nullptr;
        QPen pen;

        // Get the graphics item on which the user has clicked
        current_graphics_item = dynamic_cast<SXGraphicsItem*>(itemAt(_top_left_position,QTransform()));

        // If the user clicked on a SX graphics item it will become the current graphics item
        if (current_graphics_item) {
            auto nsx_graphics_items = selectGraphicsItems<SXGraphicsItem>();
            for (auto item : nsx_graphics_items) {
                item->setSelected(false);
            }
            _current_graphics_item = current_graphics_item;
            // Left clicking and pressing Ctrl key will toggle item selection state
            _current_graphics_item->setSelected(!_current_graphics_item->isSelected());
            return;
        }

        // The user click on the scene.
        switch(_interaction_mode) {

        case INTERACTION_MODE::ZOOM:
            pen = QPen(QBrush(QColor("gray")),1.0);
            pen.setWidth(1);
            pen.setCosmetic(true);
            _zoom_window = addRect(QRectF(_top_left_position,_bottom_right_position));
            _zoom_window->setPen(pen);
            _zoom_window->setBrush(QBrush(QColor(255,0,0,30)));
            break;

        case INTERACTION_MODE::HORIZONTAL_SLICE:
            _current_graphics_item = new HorizontalSliceGraphicsItem(_data,_top_left_position);
            addItem(_current_graphics_item);
            break;

        case INTERACTION_MODE::VERTICAL_SLICE:
            _current_graphics_item = new VerticalSliceGraphicsItem(_data,_top_left_position);
            addItem(_current_graphics_item);
            break;

        case INTERACTION_MODE::CUTLINE:
            _current_graphics_item = new CutLineGraphicsItem(_data,_top_left_position);
            addItem(_current_graphics_item);
            break;

        case INTERACTION_MODE::MASK:
            _current_graphics_item = new MaskGraphicsItem(_data,_top_left_position);
            addItem(_current_graphics_item);
            break;

        default:
            break;
        }
    }
}

void DetectorSceneModel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // If no data is loaded, do nothing
    if (!_data) {
        return;
    }

    // The user released the left mouse button
    if (event->button() & Qt::LeftButton) {

        if (event->modifiers() == Qt::ControlModifier) {
            return;
        }

        setFinalMousePosition(event->lastScenePos());

        if (_interaction_mode == INTERACTION_MODE::ZOOM) {
            zoomIn();
        }

        if (_current_graphics_item) {
            _current_graphics_item->mouseReleaseEvent(event);
        }
    }
}

void DetectorSceneModel::keyPressEvent(QKeyEvent* event)
{
    // If no data, returns
    if (!_data) {
        return;
    }

    // The user press u key, unzoom
    if (event->key() == Qt::Key_U) {
        zoomOut();
        return;
    }

    if (_current_graphics_item) {
        _current_graphics_item->keyPressEvent(event);
    }

    // The user pressed on Delete key
    if (event->key() == Qt::Key_Delete) {

        delete _current_graphics_item;
        removeItem(_current_graphics_item);
        _current_graphics_item = nullptr;
    }
}

void DetectorSceneModel::createToolTipText(QGraphicsSceneMouseEvent* event)
{
    if (!_data) {
        return;
    }

    auto diffractometer = _data->reader()->diffractometer();
    const auto *detector = diffractometer->detector();

    int nrows = int(detector->nRows());
    int ncols = int(detector->nCols());

    int col = static_cast<int>(event->lastScenePos().x());
    int row = static_cast<int>(event->lastScenePos().y());

    if (col < 0 || col > ncols-1 || row < 0 || row > nrows-1) {
        return;
    }

    int count = _current_frame(row,col);

    nsx::InstrumentState state = _data->interpolatedState(_current_frame_index);

    const auto &mono = diffractometer->source().selectedMonochromator();
    double wave = mono.wavelength();

    QString ttip;

    auto pos = _data->reader()->diffractometer()->detector()->pixelPosition(col, row);

    double gamma = state.gamma(pos);
    double nu = state.nu(pos);
    double th2 = state.twoTheta(pos);

    switch (_cursor_mode) {
    case CURSOR_MODE::PIXEL: {
        ttip = QString("(%1,%2) I:%3").arg(col).arg(row).arg(count);
        break;
    }
    case CURSOR_MODE::GAMMA_NU: {
        ttip = QString("(%1,%2) I: %3").arg(gamma/nsx::deg,0,'f',3).arg(nu/nsx::deg,0,'f',3).arg(count);
        break;
    }
    case CURSOR_MODE::THETA: {
        ttip = QString("(%1) I: %2").arg(th2/nsx::deg,0,'f',3).arg(count);
        break;
    }
    case CURSOR_MODE::D_SPACING: {
        ttip = QString("(%1) I: %2").arg(wave/(2*sin(0.5*th2)),0,'f',3).arg(count);
        break;
    }
    case CURSOR_MODE::MILLER_INDICES: {

        auto experiment_item = _session_model->selectExperiment(_data);
        if (!experiment_item) {
            ttip = QString("No experiment found");
        } else {
            auto selected_unit_cell_item = experiment_item->unitCellsItem()->selectedUnitCellItem();
            if (selected_unit_cell_item) {
                auto q = state.sampleQ(pos);
                auto miller_indices = nsx::MillerIndex(q,*(selected_unit_cell_item->data(Qt::UserRole).value<nsx::sptrUnitCell>()));

                Eigen::RowVector3d hkl = miller_indices.rowVector().cast<double>() + miller_indices.error();
                ttip = QString("(%1,%2,%3) I: %4").arg(hkl[0],0,'f',2).arg(hkl[1],0,'f',2).arg(hkl[2],0,'f',2).arg(count);
            } else {
                ttip = QString("No unit cell selected");
            }
        }
        break;
    }
    default:
        return;
    }
    QToolTip::showText(event->screenPos(),ttip);
}

void DetectorSceneModel::changeInteractionMode(INTERACTION_MODE interaction_mode)
{
    _interaction_mode = interaction_mode;
}

void DetectorSceneModel::loadCurrentImage()
{
    if (!_data) {
        return;
    }

    // Full image size, front of the stack
    auto image_rect = _zoom_stack.front().toRect();

    _current_frame = _data->frame(_current_frame_index);

    if (_image == nullptr) {
        _image = addPixmap(QPixmap::fromImage(_color_map.matToImage(_current_frame.cast<double>(), image_rect, _contrast_level, _logarithmic_scale)));
        _image->setZValue(-2);
    } else {
        _image->setPixmap(QPixmap::fromImage(_color_map.matToImage(_current_frame.cast<double>(), image_rect, _contrast_level, _logarithmic_scale)));
    }

    drawIntegrationRegion();

    setSceneRect(_zoom_stack.back());
    emit signalDetectorSceneChanged();
}

void DetectorSceneModel::drawIntegrationRegion()
{
    // update the integration region pixmap
    if (!_draw_integration_region) {
        return;
    }

    using EventType = nsx::IntegrationRegion::EventType;

    const int ncols = _data->nCols();
    const int nrows = _data->nRows();
    Eigen::MatrixXi mask = Eigen::MatrixXi::Constant(nrows, ncols,static_cast<int>(EventType::EXCLUDED));

    auto peaks = _session_model->peaks(_data);
    for (auto peak : peaks) {
        if (peak->enabled()) {
            // IntegrationRegion constructor can throw if the region is invalid
            try {
                auto region = nsx::IntegrationRegion(peak, peak->peakEnd(), peak->bkgBegin(), peak->bkgEnd());
                region.updateMask(mask, _current_frame_index);
            } catch (...) {
                peak->setStatus(nsx::Peak3D::Status::BadlyIntegrated);
            }
        }
    }

    const unsigned int green =   (128u << 24) | (255u << 8);
    const unsigned int yellow =  (128u << 24) | (255u << 16) | (255u << 8);
    const unsigned int transparent = 0;

    QImage region_img(ncols, nrows, QImage::Format_ARGB32);

    for (auto c = 0; c < ncols; ++c) {
        for (auto r = 0; r < nrows; ++r) {
            EventType ev = EventType(mask(r, c));
            unsigned int color;

            switch(ev) {
            case EventType::PEAK:
                color = green;
                break;
            case EventType::BACKGROUND:
                color = yellow;
                break;
            default:
                color = transparent;
                break;
            }

            // todo: what about unselected peaks?
            region_img.setPixel(c, r, color);
        }
    }

    if (_integration_region) {
        _integration_region->setPixmap(QPixmap::fromImage(region_img));
    } else {
        _integration_region = addPixmap(QPixmap::fromImage(region_img));
        _integration_region->setZValue(-1);
    }
}

const rowMatrix& DetectorSceneModel::currentFrame() const
{
    return _current_frame;
}

void DetectorSceneModel::changeCursorMode(CURSOR_MODE cursor_mode)
{
    _cursor_mode = cursor_mode;
}

int DetectorSceneModel::currentFrameIndex() const
{
    return _current_frame_index;
}

void DetectorSceneModel::showPeakLabels(bool flag)
{
    _show_peak_labels = flag;
    auto peak_graphics_items = selectGraphicsItems<PeakGraphicsItem>();
    for (auto item : peak_graphics_items) {
        item->showLabel(_show_peak_labels);
    }
}

void DetectorSceneModel::showPeakCenters(bool flag)
{
    _show_peak_centers = flag;
    auto peak_graphics_items = selectGraphicsItems<PeakGraphicsItem>();
    for (auto item : peak_graphics_items) {
        item->showCenter(_show_peak_centers);
    }
}

void DetectorSceneModel::showPeakIntegrationAreas(bool flag)
{
    // clear the background if necessary
    if (_integration_region && flag == false) {
        removeItem(_integration_region);
        delete _integration_region;
        _integration_region = nullptr;
    }

    _draw_integration_region = flag;

    loadCurrentImage();
}

void DetectorSceneModel::setLogarithmicScale(bool flag)
{
    _logarithmic_scale = flag;
    loadCurrentImage();
}

void DetectorSceneModel::changeColorMap(const ColorMap &color_map)
{
    _color_map = color_map;
    loadCurrentImage();
}

void DetectorSceneModel::resetScene()
{
    clear();
    _data = nullptr;
    _current_frame_index = -1;
    _zoom_window = nullptr;
    _zoom_stack.clear();
    _image = nullptr;
    _integration_region = nullptr;
    _current_graphics_item = nullptr;
}

void DetectorSceneModel::zoomIn()
{
    if (!_zoom_window) {
        return;
    }

    auto zoom_rect = _zoom_window->rect();

    // Remove the zoom graphics item from the scene
    removeItem(_zoom_window);
    // Delete the zoom graphics item pointer
    delete _zoom_window;
    // Set the zoom graphics pointer to nullptr
    _zoom_window = nullptr;

    // If the user just clicked on the left mouse button with holding it, skip the event
    if (std::abs(zoom_rect.width()) > 1 || std::abs(zoom_rect.height()) > 1) {
        _zoom_stack.push_back(zoom_rect);
        setSceneRect(zoom_rect);
        emit signalDetectorSceneChanged();
    }
}

void DetectorSceneModel::zoomOut()
{
    if (_zoom_stack.size() > 1) {
        // Remove the last zoom area stored in the stack
        _zoom_stack.pop();
        // If not root, then update the scene
        if (!_zoom_stack.isEmpty()) {
            setSceneRect(_zoom_stack.top());
            emit signalDetectorSceneChanged();
        }
    }
}
