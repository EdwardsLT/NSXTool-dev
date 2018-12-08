#include <algorithm>

#include <QAction>
#include <QActionGroup>
#include <QString>

#include "ColorMap.h"
#include "DetectorSceneModel.h"
#include "DetectorMenu.h"
#include "MainWindow.h"
#include "SessionModel.h"

DetectorMenu::DetectorMenu(MainWindow *main_window)
: _main_window(main_window)
{
    setTitle("&Detector");
    createActions();
    createMenus();
}

void DetectorMenu::createActions()
{
    _view_action_group = new QActionGroup(_main_window);

    _view_detector_from_sample_action = new QAction("sample",_main_window);
    _view_detector_from_sample_action->setStatusTip("View the detector looking from the sample");
    _view_detector_from_sample_action->setCheckable(true);
    _view_detector_from_sample_action->setChecked(true);
    _view_detector_from_sample_action->setActionGroup(_view_action_group);
    connect(_view_detector_from_sample_action,&QAction::triggered,[=](){_main_window->sessionModel()->setDetectorViewTransformation(SessionModel::DETECTOR_VIEW::FROM_SAMPLE);});

    _view_detector_from_behind_action = new QAction("behind", _main_window);
    _view_detector_from_behind_action->setStatusTip("View the detector looking to the sample");
    _view_detector_from_behind_action->setCheckable(true);
    _view_detector_from_behind_action->setChecked(false);
    _view_detector_from_behind_action->setActionGroup(_view_action_group);
    connect(_view_detector_from_behind_action,&QAction::triggered,[=](){_main_window->sessionModel()->setDetectorViewTransformation(SessionModel::DETECTOR_VIEW::FROM_BEHIND);});

    // Cursor mode settings

    _cursor_mode_action_group = new QActionGroup(_main_window);
    _cursor_mode_action_group->setExclusive(true);

    auto *pixel_position_cursor_mode_action(new QAction("pixel position",_main_window));
    pixel_position_cursor_mode_action->setStatusTip("Show pixel position when mouse pointing the detector view");
    pixel_position_cursor_mode_action->setCheckable(true);
    pixel_position_cursor_mode_action->setChecked(true);
    pixel_position_cursor_mode_action->setActionGroup(_cursor_mode_action_group);
    _cursor_mode_actions.append(pixel_position_cursor_mode_action);

    auto *gamma_nu_cursor_mode_action(new QAction(QString("%1 %2").arg(QChar(0x03B3)).arg(QChar(0x03B7)),_main_window));
    gamma_nu_cursor_mode_action->setStatusTip(QString("Show %1 and %2 when mouse pointing the detector view").arg(QChar(0x03B3)).arg(QChar(0x03B7)));
    gamma_nu_cursor_mode_action->setCheckable(true);
    gamma_nu_cursor_mode_action->setChecked(false);
    gamma_nu_cursor_mode_action->setActionGroup(_cursor_mode_action_group);
    _cursor_mode_actions.append(gamma_nu_cursor_mode_action);

    auto *two_theta_cursor_mode_action(new QAction(QString("2%1").arg(QChar(0x03B8)),_main_window));
    two_theta_cursor_mode_action->setStatusTip(QString("Show 2%1 when mouse pointing the detector view").arg(QChar(0x03B8)));
    two_theta_cursor_mode_action->setCheckable(true);
    two_theta_cursor_mode_action->setChecked(false);
    two_theta_cursor_mode_action->setActionGroup(_cursor_mode_action_group);
    _cursor_mode_actions.append(two_theta_cursor_mode_action);

    auto *d_spacing_cursor_mode_action(new QAction("d spacing",_main_window));
    d_spacing_cursor_mode_action->setStatusTip("Show d-spacing when mouse pointing the detector view");
    d_spacing_cursor_mode_action->setCheckable(true);
    d_spacing_cursor_mode_action->setChecked(false);
    d_spacing_cursor_mode_action->setActionGroup(_cursor_mode_action_group);
    _cursor_mode_actions.append(d_spacing_cursor_mode_action);

    auto *miller_indices_cursor_mode_action(new QAction("miller indices",_main_window));
    miller_indices_cursor_mode_action->setStatusTip("Show miller indices when mouse pointing the detector view");
    miller_indices_cursor_mode_action->setCheckable(true);
    miller_indices_cursor_mode_action->setChecked(false);
    miller_indices_cursor_mode_action->setActionGroup(_cursor_mode_action_group);
    _cursor_mode_actions.append(miller_indices_cursor_mode_action);
    connect(_cursor_mode_action_group,&QActionGroup::triggered,this,&DetectorMenu::onChangeCursorMode);

    // Interaction modes settings

    _interaction_mode_action_group = new QActionGroup(_main_window);
    _interaction_mode_action_group->setExclusive(true);

    auto *select_interaction_mode_action(new QAction(QIcon(":/resources/selectIcon.png"),"select",_main_window));
    select_interaction_mode_action->setStatusTip("Switch mouse interaction mode to select");
    select_interaction_mode_action->setShortcut(QKeySequence("s"));
    select_interaction_mode_action->setCheckable(true);
    select_interaction_mode_action->setChecked(true);
    select_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(select_interaction_mode_action);

    auto *zoomin_interaction_mode_action(new QAction(QIcon(":/resources/zoomInIcon.png"),"zoom",_main_window));
    zoomin_interaction_mode_action->setStatusTip(QString("Switch mouse interaction mode to zoom"));
    zoomin_interaction_mode_action->setShortcut(QKeySequence("z"));
    zoomin_interaction_mode_action->setCheckable(true);
    zoomin_interaction_mode_action->setChecked(false);
    zoomin_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(zoomin_interaction_mode_action);

    auto *cutline_interaction_mode_action(new QAction(QIcon(":/resources/cutlineIcon.png"),"cutline",_main_window));
    cutline_interaction_mode_action->setStatusTip(QString("Switch mouse interaction mode to cutline"));
    cutline_interaction_mode_action->setShortcut(QKeySequence("c"));
    cutline_interaction_mode_action->setCheckable(true);
    cutline_interaction_mode_action->setChecked(false);
    cutline_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(cutline_interaction_mode_action);

    auto *horizontal_slice_interaction_mode_action(new QAction(QIcon(":/resources/horizontalSliceIcon.png"),"horizontal slice",_main_window));
    horizontal_slice_interaction_mode_action->setStatusTip("Switch mouse interaction mode to horizontal slice");
    horizontal_slice_interaction_mode_action->setShortcut(QKeySequence("h"));
    horizontal_slice_interaction_mode_action->setCheckable(true);
    horizontal_slice_interaction_mode_action->setChecked(false);
    horizontal_slice_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(horizontal_slice_interaction_mode_action);

    auto *vertical_slice_interaction_mode_action(new QAction(QIcon(":/resources/verticalSliceIcon.png"),"vertical slice",_main_window));
    vertical_slice_interaction_mode_action->setStatusTip("Switch mouse interaction mode to vertical slice");
    vertical_slice_interaction_mode_action->setShortcut(QKeySequence("v"));
    vertical_slice_interaction_mode_action->setCheckable(true);
    vertical_slice_interaction_mode_action->setChecked(false);
    vertical_slice_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(vertical_slice_interaction_mode_action);

    auto *rectangular_mask_interaction_mode_action(new QAction(QIcon(":/resources/rectangularMaskIcon.png"),"rectangular mask",_main_window));
    rectangular_mask_interaction_mode_action->setStatusTip("Switch mouse interaction mode to rectangular mask");
    rectangular_mask_interaction_mode_action->setShortcut(QKeySequence("r"));
    rectangular_mask_interaction_mode_action->setCheckable(true);
    rectangular_mask_interaction_mode_action->setChecked(false);
    rectangular_mask_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(rectangular_mask_interaction_mode_action);

    connect(_interaction_mode_action_group,&QActionGroup::triggered,this,&DetectorMenu::onChangeInteractionMode);

    _display_peak_labels_action = new QAction("Display peak labels",_main_window);
    _display_peak_labels_action->setCheckable(true);
    _display_peak_labels_action->setChecked(false);
    connect(_display_peak_labels_action,&QAction::triggered,[=](bool flag){_main_window->detectorSceneModel()->showPeakLabels(flag);});

    _display_peak_centers_action = new QAction("Display peak center",_main_window);
    _display_peak_centers_action->setCheckable(true);
    _display_peak_centers_action->setChecked(false);
    connect(_display_peak_centers_action,&QAction::triggered,[=](bool flag){_main_window->detectorSceneModel()->showPeakCenters(flag);});

    _display_peak_integration_areas_action = new QAction("Display peak integration areas",_main_window);
    _display_peak_integration_areas_action->setCheckable(true);
    _display_peak_integration_areas_action->setChecked(false);
    connect(_display_peak_integration_areas_action,&QAction::triggered,[=](bool flag){_main_window->detectorSceneModel()->showPeakIntegrationAreas(flag);});

    // Color map menu settings

    auto color_maps = ColorMap::colorMaps();
    _color_map_action_group = new QActionGroup(_main_window);
    for (auto&& color_map : color_maps) {
        QAction* color_map_action = new QAction(color_map.c_str(),_main_window);
        color_map_action->setCheckable(true);
        color_map_action->setChecked(false);
        color_map_action->setActionGroup(_color_map_action_group);
        _color_map_actions.append(color_map_action);
    }

    auto idx = std::distance(_color_map_actions.begin(),std::find_if(_color_map_actions.begin(),
                                                                     _color_map_actions.end(),
                                                                     [](QAction* action){return action->text().toStdString().compare("blue white") == 0;}));
    _color_map_actions[idx]->setChecked(true);

    connect(_color_map_action_group,&QActionGroup::triggered,this,&DetectorMenu::onChangeColorMap);

    // Logarithmic scale action

    _logarithmic_scale_action = new QAction("Set logarithmic scale",_main_window);
    _logarithmic_scale_action->setStatusTip("Toggle detector view between normal/logarithmic scale");
    _logarithmic_scale_action->setCheckable(true);
    _logarithmic_scale_action->setChecked(false);
    connect(_logarithmic_scale_action,&QAction::triggered,_main_window->detectorSceneModel(),&DetectorSceneModel::onSetLogarithmicScale);

}

void DetectorMenu::createMenus()
{
    _view_from_menu = addMenu("&View from");
    _view_from_menu->addAction(_view_detector_from_sample_action);
    _view_from_menu->addAction(_view_detector_from_behind_action);

    addSeparator();

    _cursor_mode_menu = addMenu("Cursor mode");
    _cursor_mode_menu->addActions(_cursor_mode_actions);

    _interaction_mode_menu = addMenu("Mouse interaction mode");
    _interaction_mode_menu->addActions(_interaction_mode_actions);

    _peaks_menu = addMenu("Peaks");
    _peaks_menu->addAction(_display_peak_labels_action);
    _peaks_menu->addAction(_display_peak_centers_action);
    _peaks_menu->addAction(_display_peak_integration_areas_action);

    addSeparator();

    _color_map_menu = addMenu("Color maps");
    for (auto color_map_action : _color_map_actions) {
        _color_map_menu->addAction(color_map_action);
    }

    addAction(_logarithmic_scale_action);
}

void DetectorMenu::onChangeColorMap(QAction *color_map_action)
{
    _main_window->sessionModel()->setColorMap(ColorMap(color_map_action->text().toStdString()));
}

void DetectorMenu::onChangeCursorMode(QAction *cursor_mode_action)
{
    auto it = std::find(_cursor_mode_actions.begin(),_cursor_mode_actions.end(),cursor_mode_action);
    if (it == _cursor_mode_actions.end()) {
        return;
    }

    auto cursor_mode_index = static_cast<DetectorSceneModel::CURSOR_MODE>(std::distance(_cursor_mode_actions.begin(),it));

    _main_window->detectorSceneModel()->changeCursorMode(cursor_mode_index);

}

void DetectorMenu::onChangeInteractionMode(QAction *interaction_mode_action)
{
    auto it = std::find(_interaction_mode_actions.begin(),_interaction_mode_actions.end(),interaction_mode_action);
    if (it == _interaction_mode_actions.end()) {
        return;
    }

    auto interaction_mode_index = static_cast<DetectorSceneModel::INTERACTION_MODE>(std::distance(_interaction_mode_actions.begin(),it));

    _main_window->detectorSceneModel()->changeInteractionMode(interaction_mode_index);
}
