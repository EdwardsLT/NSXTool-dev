#include <ctime>
#include <vector>

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QMenu>
#include <QPixmap>
#include <QToolTip>

#include <nsxlib/AABB.h>
#include <nsxlib/BoxMask.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/EllipseMask.h>
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
#include "CutSliceGraphicsItem.h"
#include "DetectorSceneModel.h"
#include "EllipseMaskGraphicsItem.h"
#include "ExperimentItem.h"
#include "MaskGraphicsItem.h"
#include "MetaTypes.h"
#include "PeakGraphicsItem.h"
#include "SessionModel.h"
#include "UnitCellItem.h"
#include "UnitCellsItem.h"

DetectorSceneModel::DetectorSceneModel(SessionModel *session_model)
: QGraphicsScene(nullptr),
  _session_model(session_model),
  _currentData(nullptr),
  _current_frame_index(0),
  _max_intensity(10),
  _currentFrame(),
  _color_map(session_model->colorMap()),
  _cursor_mode(CURSOR_MODE::PIXEL),
  _interaction_mode(INTERACTION_MODE::SELECT),
  _zoomstart(0,0),
  _zoomend(0,0),
  _zoomrect(nullptr),
  _zoomStack(),
  _itemSelected(false),
  _image(nullptr),
  _masks(),
  _lastClickedGI(nullptr),
  _logarithmic_scale(false),
  _drawIntegrationRegion(false),
  _integrationRegion(nullptr),
  _selected_peak_gi(nullptr),
  _peak_graphics_items(),
  _selected_peak(nullptr)
{
    connect(_session_model,&SessionModel::signalEnabledPeakChanged,this,&DetectorSceneModel::onChangeEnabledPeak);
    connect(_session_model,&SessionModel::signalMaskedPeaksChanged,this,&DetectorSceneModel::changeMaskedPeaks);
    connect(_session_model,&SessionModel::signalSelectedDataChanged,this,&DetectorSceneModel::changeSelectedData);
    connect(_session_model,&SessionModel::signalChangeSelectedPeak,this,&DetectorSceneModel::onChangeSelectedPeak);
    connect(_session_model,&SessionModel::updatePeaks,this,&DetectorSceneModel::resetPeakGraphicsItems);
    connect(_session_model,&SessionModel::signalChangeColorMap,this,&DetectorSceneModel::onChangeColorMap);
}

void DetectorSceneModel::clearPeakGraphicsItems()
{
    if (!_currentData) {
        return;
    }

    for (auto p : _peak_graphics_items) {
        removeItem(p.second);
        delete p.second;
    }

    _peak_graphics_items.clear();
}

void DetectorSceneModel::resetPeakGraphicsItems()
{
    if (!_currentData) {
        return;
    }

    clearPeakGraphicsItems();

    auto peaks = _session_model->peaks(_currentData);

    // Loop over the peaks found for this dataset
    for (auto peak : peaks) {

        auto peak_ellipsoid = peak->shape();

        peak_ellipsoid.scale(peak->peakEnd());

        auto& aabb = peak_ellipsoid.aabb();

        auto lower = aabb.lower();

        auto upper = aabb.upper();

        // If the current frame of the scene is out of the peak bounds do not paint it
        if (_current_frame_index < lower[2] || _current_frame_index > upper[2]) {
            continue;
        }

        PeakGraphicsItem* peak_gi = new PeakGraphicsItem(peak,_current_frame_index);

        addItem(peak_gi);

        _peak_graphics_items.insert(std::make_pair(peak,peak_gi));
    }

    if (_selected_peak_gi) {
        removeItem(_selected_peak_gi);
        delete _selected_peak_gi;
        _selected_peak_gi = nullptr;
    }

    auto it = _peak_graphics_items.find(_selected_peak);

    if (it != _peak_graphics_items.end()) {
        it->second->setVisible(true);
    }

    if (_selected_peak) {

        auto selected_peak_ellipsoid = _selected_peak->shape();

        selected_peak_ellipsoid.scale(_selected_peak->peakEnd());

        double frame_index = static_cast<double>(_current_frame_index);

        auto& aabb = selected_peak_ellipsoid.aabb();

        auto&& lower = aabb.lower();
        auto&& upper = aabb.upper();

        if (frame_index >= lower[2] && frame_index <= upper[2]) {

            auto center = selected_peak_ellipsoid.intersectionCenter({0.0,0.0,1.0},{0.0,0.0,static_cast<double>(_current_frame_index)});

            _selected_peak_gi = new QGraphicsRectItem(nullptr);
            _selected_peak_gi->setPos(center[0],center[1]);
            _selected_peak_gi->setRect(-10,-10,20,20);

            QPen pen;
            pen.setColor(Qt::darkCyan);
            pen.setStyle(Qt::DotLine);
            _selected_peak_gi->setPen(pen);
            _selected_peak_gi->setZValue(-1);
            _selected_peak_gi->setAcceptHoverEvents(false);

            addItem(_selected_peak_gi);

        }
    }
}

void DetectorSceneModel::onChangeEnabledPeak(nsx::sptrPeak3D peak)
{
    Q_UNUSED(peak)

    loadCurrentImage();
}

void DetectorSceneModel::changeMaskedPeaks(const nsx::PeakList& peaks)
{
    Q_UNUSED(peaks)

    loadCurrentImage();
}

void DetectorSceneModel::changeSelectedData(nsx::sptrDataSet data, int frame)
{
    _currentData = data;

    _currentData->open();

    auto det = _currentData->reader()->diffractometer()->detector();

    _current_frame_index = -1;

    _zoomStack.clear();
    _zoomStack.push_back(QRect(0,0,int(det->nCols()),int(det->nRows())));

    if (_lastClickedGI != nullptr) {
        removeItem(_lastClickedGI);
        _lastClickedGI=nullptr;
    }

    changeSelectedFrame(frame);
}

void DetectorSceneModel::onChangeSelectedPeak(nsx::sptrPeak3D peak)
{
    if (peak == _selected_peak) {
        return;
    }

    _selected_peak = peak;

    auto data = peak->data();

    auto peak_ellipsoid = peak->shape();

    // Get frame number to adjust the data
    size_t frame = size_t(std::lround(peak_ellipsoid.aabb().center()[2]));

    changeSelectedData(data,frame);

    update();
}

void DetectorSceneModel::changeSelectedFrame(int frame)
{
    if (!_currentData) {
        return;
    }

    if (!_currentData->isOpened()) {
        _currentData->open();
    }

    _current_frame_index = frame;

    resetPeakGraphicsItems();

    loadCurrentImage();

    updateMasks();
}

int DetectorSceneModel::maxIntensity() const
{
    return _max_intensity;
}

void DetectorSceneModel::changeMaxIntensity(int max_intensity)
{
    if (_max_intensity == max_intensity) {
        return;
    }

    _max_intensity = max_intensity;

    if (!_currentData) {
        return;
    }

    if (!_currentData->isOpened()) {
        _currentData->open();
    }

    loadCurrentImage();
}

void DetectorSceneModel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // If no data is loaded, do nothing
    if (!_currentData) {
        return;
    }
    createToolTipText(event);

    // The left button was pressed
    if (event->buttons() & Qt::LeftButton) {

        if (event->modifiers() == Qt::ControlModifier) {
            return;
        }

        // Case of the Zoom mode, update the scene
        if (_interaction_mode == INTERACTION_MODE::ZOOM) {
            QRectF zoom=_zoomrect->rect();
            zoom.setBottomRight(event->lastScenePos());
            _zoomrect->setRect(zoom);
            return;
        }

        if (!_lastClickedGI) {
            return;
        }

        _lastClickedGI->mouseMoveEvent(event);

        auto plottable_graphics_item = dynamic_cast<PlottableGraphicsItem*>(_lastClickedGI);
        if (plottable_graphics_item) {
            emit _session_model->signalChangePlot(plottable_graphics_item->plot());
        }
    }
    // No button was pressed, just a mouse move
    else if (event->button() == Qt::NoButton) {
        auto lastPos = event->lastScenePos();
        auto point = lastPos.toPoint();
        QTransform trans;
        QGraphicsItem* gItem = itemAt(point, trans);
        if (!gItem) {
            return;
        }
    }
}

void DetectorSceneModel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    CutterGraphicsItem* cutter(nullptr);
    MaskGraphicsItem* mask(nullptr);
    EllipseMaskGraphicsItem* ellipse_mask(nullptr);
    //_masks.emplace_back(new graphicsItem(nullptr));
    
    QPen pen1;

    // If no data is loaded, do nothing
    if (!_currentData) {
        return;
    }
    // The left button was pressed
    if (event->buttons() & Qt::LeftButton) {
        // Get the graphics item on which the user has clicked
        auto item = itemAt(event->lastScenePos(),QTransform());

        if (event->modifiers() == Qt::ControlModifier) {
            item->setSelected(!item->isSelected());
            return;
        }
        // If the item is a NSXTools GI and is selected it will become the current active GI
        if (auto p = dynamic_cast<SXGraphicsItem*>(item)) {
            if (p->isSelected()) {
                _lastClickedGI = p;
                return;
            }
        }
        switch(_interaction_mode) {

        case INTERACTION_MODE::SELECT: {
            break;
        }
        case INTERACTION_MODE::ZOOM: {
            _zoomstart = event->lastScenePos().toPoint();
            _zoomend = _zoomstart;
            _zoomrect = addRect(QRect(_zoomstart,_zoomend));

            pen1 = QPen(QBrush(QColor("gray")),1.0);
            pen1.setWidth(1);
            pen1.setCosmetic(true);
            _zoomrect->setPen(pen1);
            _zoomrect->setBrush(QBrush(QColor(255,0,0,30)));
            break;
        }
        case INTERACTION_MODE::HORIZONTAL_SLICE: {
            cutter = new CutSliceGraphicsItem(_currentData,true);
            break;
        }
        case INTERACTION_MODE::VERTICAL_SLICE: {
            cutter = new CutSliceGraphicsItem(_currentData,false);
            break;
        }
        case INTERACTION_MODE::CUTLINE: {
            cutter = new CutLineGraphicsItem(_currentData);
            break;
        }
        case INTERACTION_MODE::RECTANGULAR_MASK: {
            mask = new MaskGraphicsItem(_currentData, new nsx::AABB);
            mask->setFrom(event->lastScenePos());
            mask->setTo(event->lastScenePos());
            addItem(mask);
            _lastClickedGI = mask;
            _masks.emplace_back(mask, nullptr);
            break;
        }
        case INTERACTION_MODE::ELLIPSOIDAL_MASK: {
            ellipse_mask = new EllipseMaskGraphicsItem(_currentData, new nsx::AABB);
            ellipse_mask->setFrom(event->lastScenePos());
            ellipse_mask->setTo(event->lastScenePos());
            addItem(ellipse_mask);
            _lastClickedGI = ellipse_mask;
            _masks.emplace_back(ellipse_mask, nullptr);
            break;
        }
        }
        if (cutter != nullptr) {
            cutter->setFrom(event->lastScenePos());
            addItem(cutter);
            _lastClickedGI = cutter;
        }
    }
    // The right button was pressed
    else if (event->buttons() & Qt::RightButton) {
        if (_zoomStack.size()>1) {
            // Remove the last zoom area stored in the stack
            _zoomStack.pop();
            // If not root, then update the scene
            if (!_zoomStack.isEmpty()) {
                setSceneRect(_zoomStack.top());
                emit dataChanged();
            }
        }
    }
}

void DetectorSceneModel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // If no data is loaded, do nothing
    if (!_currentData) {
        return;
    }

    // The user released the left mouse button
    if (event->button() & Qt::LeftButton) {

        if (event->modifiers() == Qt::ControlModifier) {
            return;
        }

        if (_interaction_mode == INTERACTION_MODE::ZOOM) {

            qreal top = _zoomrect->rect().top();
            qreal bot = _zoomrect->rect().bottom();
            qreal left = _zoomrect->rect().left();
            qreal right = _zoomrect->rect().right();

            // If the user just clicked on the left mouse button with holding it, skip the event
            if (qAbs(top-bot)<=1 || qAbs(left-right)<=1) {
                removeItem(_zoomrect);
                delete _zoomrect;
                return;
            }

            if (top > bot) {
                std::swap(top,bot);
            }

            if (right < left) {
                std::swap(left,right);
            }

            QRect max = _zoomStack.front();

            if (top < max.top()) {
                top = max.top();
            }

            if (bot > max.bottom()) {
                bot = max.bottom()+1;
            }

            if (left < max.left()) {
                left = max.left();
            }

            if (right > max.right()) {
                right = max.right()+1;
            }

            _zoomrect->setRect(left,top,right-left,bot-top);
            _zoomStack.push_back(_zoomrect->rect().toRect());
            setSceneRect(_zoomrect->rect());
            removeItem(_zoomrect);
            delete _zoomrect;
            emit dataChanged();

        } else {

            auto peaks = _session_model->peaks(_currentData);

            if (auto p = dynamic_cast<CutterGraphicsItem*>(_lastClickedGI)) {
                // delete p....
                 _lastClickedGI = nullptr;
                removeItem(p);
            } else if (auto p=dynamic_cast<MaskGraphicsItem*>(_lastClickedGI)) {
                // add a new mask
                auto it = findMask(p);
                if (it != _masks.end()) {
                    it->second = new nsx::BoxMask(*p->getAABB());
                    _currentData->addMask(it->second);                    
                    _lastClickedGI = nullptr;
                }
                _currentData->maskPeaks(peaks);
                update();
                updateMasks();
                emit _session_model->signalMaskedPeaksChanged(peaks);
            }else if (auto p=dynamic_cast<EllipseMaskGraphicsItem*>(_lastClickedGI)) {
                auto it = findMask(p);
                if (it != _masks.end()) {
                    it->second = new nsx::EllipseMask(*p->getAABB());
                    _currentData->addMask(it->second);                    
                    _lastClickedGI = nullptr;
                }
                _currentData->maskPeaks(peaks);
                update();
                updateMasks();
                emit _session_model->signalMaskedPeaksChanged(peaks);
            }
        }
    }
}

void DetectorSceneModel::wheelEvent(QGraphicsSceneWheelEvent* event)
{
    // If no data, returns
    if (!_currentData) {
        return;
    }
    // Get the graphics item on which the user has performed the wheel event
    auto item=itemAt(event->scenePos(),QTransform());
    auto p = dynamic_cast<SXGraphicsItem*>(item);

    if (p == nullptr) {
        return;
    }
    if (!(p->isSelected())) {
        return;
    }
    auto q = dynamic_cast<CutterGraphicsItem*>(item);
    if (q != nullptr) {
        q->wheelEvent(event);
//        emit signalHoverPlottableGraphicsItem(q);
    }
}

void DetectorSceneModel::keyPressEvent(QKeyEvent* event)
{
    // If no data, returns
    if (!_currentData)
        return;

    // The user pressed on Delete key
    if (event->key() == Qt::Key_Delete) {
        QList<QGraphicsItem*> items = selectedItems();
        int nPeaksUnselected = int(_peak_graphics_items.size());
        for (auto item: items) {
            auto p = dynamic_cast<SXGraphicsItem*>(item);

            if (p == nullptr) {
                continue;
            }

            // The item must be deletable ... to be deleted
            if (!p->isDeletable()) {
                continue;
            }
            // If the item is a peak graphics item, remove its corresponding peak from the data,
            // update the set of peak graphics items and update the scene
            if (auto p = dynamic_cast<PeakGraphicsItem*>(item)) {
                p->peak()->setSelected(false);
            }
            // If the item is a mask graphics item, remove its corresponding mask from the data,
            // update the QList of mask graphics items and update the scene
            else if (auto p = dynamic_cast<MaskGraphicsItem*>(item)) {
                auto it = findMask(p);
                if (it != _masks.end()) {
                    _currentData->removeMask(it->second);
                    _masks.erase(it);
                    auto peaks = _session_model->peaks(_currentData);
                    _currentData->maskPeaks(peaks);
                    update();
                    updateMasks();
                    emit _session_model->signalMaskedPeaksChanged(peaks);
                }
            }
            else if (auto p = dynamic_cast<EllipseMaskGraphicsItem*>(item)) {
                auto it = findMask(p);
                if (it != _masks.end()) {
                    _currentData->removeMask(it->second);
                    _masks.erase(it);
                    auto peaks =  _session_model->peaks(_currentData);
                    _currentData->maskPeaks(peaks);
                    update();
                    updateMasks();
                    emit _session_model->signalMaskedPeaksChanged(peaks);
                }
            }
            if (p == _lastClickedGI) {
                _lastClickedGI=nullptr;
            }
            // Remove the item from the scene
            removeItem(item);
        }
        // Computes the new number of peaks, and if it changes log it
        nPeaksUnselected -= _peak_graphics_items.size();
        if (nPeaksUnselected > 0) {
            nsx::info() << "Unselected "<< nPeaksUnselected << " peaks";
        }
    }
}

void DetectorSceneModel::createToolTipText(QGraphicsSceneMouseEvent* event)
{
    if (!_currentData) {
        return;
    }
    auto instr = _currentData->reader()->diffractometer();
    auto det = instr->detector();

    int nrows = int(det->nRows());
    int ncols = int(det->nCols());

    int col = static_cast<int>(event->lastScenePos().x());
    int row = static_cast<int>(event->lastScenePos().y());

    if (col<0 || col>ncols-1 || row<0 || row>nrows-1) {
        return;
    }

    int count = _currentFrame(row,col);

    nsx::InstrumentState state = _currentData->interpolatedState(_current_frame_index);

    const auto &mono = instr->source().selectedMonochromator();
    double wave = mono.wavelength();

    QString ttip;

    auto pos = _currentData->reader()->diffractometer()->detector()->pixelPosition(col, row);

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

        auto experiment_item = _session_model->selectExperiment(_currentData);
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
    }
    QToolTip::showText(event->screenPos(),ttip);
}

void DetectorSceneModel::changeInteractionMode(INTERACTION_MODE interaction_mode)
{
    _interaction_mode = interaction_mode;
}

void DetectorSceneModel::loadCurrentImage()
{
    if (!_currentData) {
        return;
    }

    const unsigned int green =   (128u << 24) | (255u << 8);
    const unsigned int yellow =  (128u << 24) | (255u << 16) | (255u << 8);
    const unsigned int transparent = 0;

    using EventType = nsx::IntegrationRegion::EventType;

    // Full image size, front of the stack
    QRect& full = _zoomStack.front();

    if (_current_frame_index >= _currentData->nFrames()) {
        _current_frame_index = _currentData->nFrames()-1;
    }

    _currentFrame =_currentData->frame(_current_frame_index);

    if (_image == nullptr) {
        _image = addPixmap(QPixmap::fromImage(_color_map.matToImage(_currentFrame.cast<double>(), full, _max_intensity, _logarithmic_scale)));
        _image->setZValue(-2);
    } else {
        _image->setPixmap(QPixmap::fromImage(_color_map.matToImage(_currentFrame.cast<double>(), full, _max_intensity, _logarithmic_scale)));
    }

    // update the integration region pixmap
    if (_drawIntegrationRegion) {

        const int ncols = _currentData->nCols();
        const int nrows = _currentData->nRows();
        Eigen::MatrixXi mask(nrows, ncols);
        mask.setConstant(int(EventType::EXCLUDED));

        auto peaks = _session_model->peaks(_currentData);
        for (auto peak : peaks) {
            if (peak->enabled()) {
                // IntegrationRegion constructor can throw if the region is invalid
                try {
                    auto region = nsx::IntegrationRegion(peak, peak->peakEnd(), peak->bkgBegin(), peak->bkgEnd());
                    region.updateMask(mask, _current_frame_index);
                } catch (...) {
                    peak->setSelected(false);
                }
            }
        }

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

        if (!_integrationRegion) {
            _integrationRegion = addPixmap(QPixmap::fromImage(region_img));
            _integrationRegion->setZValue(-1);
        } else {
            _integrationRegion->setPixmap(QPixmap::fromImage(region_img));
        }
    }

    setSceneRect(_zoomStack.back());
    emit dataChanged();
}

nsx::sptrDataSet DetectorSceneModel::getData()
{
    return _currentData;
}

const rowMatrix& DetectorSceneModel::currentFrame() const
{
    return _currentFrame;
}

void DetectorSceneModel::changeCursorMode(CURSOR_MODE cursor_mode)
{
    _cursor_mode = cursor_mode;
}

int DetectorSceneModel::currentFrameIndex() const
{
    return _current_frame_index;
}

void DetectorSceneModel::updateMasks()
{
    _lastClickedGI = nullptr;
}

void DetectorSceneModel::showPeakLabels(bool flag)
{
    for (auto p : _peak_graphics_items) {
        p.second->showLabel(flag);
    }
    update();
}

void DetectorSceneModel::showPeakCenters(bool flag)
{
    for (auto p : _peak_graphics_items) {
        p.second->showCenter(flag);
    }
    update();
}

void DetectorSceneModel::showPeakIntegrationAreas(bool flag)
{
    // clear the background if necessary
    if (_integrationRegion && flag == false) {
        removeItem(_integrationRegion);
        delete _integrationRegion;
        _integrationRegion = nullptr;
    }

    _drawIntegrationRegion = flag;

    loadCurrentImage();
}

void DetectorSceneModel::onSetLogarithmicScale(bool flag)
{
    _logarithmic_scale = flag;

    loadCurrentImage();
}

void DetectorSceneModel::onChangeColorMap(const ColorMap &color_map)
{
    _color_map = color_map;
    loadCurrentImage();
}

void DetectorSceneModel::onResetScene()
{
    clearPeakGraphicsItems();
    clear();
    _currentData = nullptr;
    _current_frame_index = 0;
    _zoomrect = nullptr;
    _zoomStack.clear();
    _image = nullptr;
    _integrationRegion = nullptr;
    _masks.clear();
    _lastClickedGI = nullptr;
}

std::vector<std::pair<QGraphicsItem*, nsx::IMask*>>::iterator DetectorSceneModel::findMask(QGraphicsItem* item)
{
    return std::find_if(_masks.begin(), _masks.end(), [item](const std::pair<QGraphicsItem*, nsx::IMask*>& x) {return x.first == item;});
}
