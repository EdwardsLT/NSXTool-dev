#include <algorithm>

#include <QAction>
#include <QActionGroup>
#include <QKeySequence>
#include <QMenu>
#include <QMenuBar>

#include "ColorMap.h"
#include "DetectorScene.h"
#include "DialogAbout.h"
#include "DialogIsotopesDatabase.h"
#include "GlobalInfo.h"
#include "MainWindow.h"
#include "NSXMenu.h"

NSXMenu::NSXMenu(MainWindow *main_window) : _main_window(main_window)
{
    createActions();
    createMenus();
}

void NSXMenu::createActions()
{
    _new_experiment_action = new QAction("&New experiment",_main_window);
    _new_experiment_action->setStatusTip("Create new experiment");
    _new_experiment_action->setShortcut(QKeySequence("Ctrl+E"));
    connect(_new_experiment_action,&QAction::triggered,_main_window,&MainWindow::onNewExperiment);

    _quit_action = new QAction("&Quit",_main_window);
    _quit_action->setStatusTip("Quit application");
    _quit_action->setShortcut(QKeySequence::Quit);
    connect(_quit_action,&QAction::triggered,_main_window,&MainWindow::close);

    _view_action_group = new QActionGroup(_main_window);

    _view_detector_from_sample_action = new QAction("sample",_main_window);
    _view_detector_from_sample_action->setStatusTip("View the detector looking from the sample");
    _view_detector_from_sample_action->setCheckable(true);
    _view_detector_from_sample_action->setChecked(true);
    _view_detector_from_sample_action->setActionGroup(_view_action_group);
    connect(_view_detector_from_sample_action,&QAction::triggered,_main_window,&MainWindow::onViewDetectorFromSample);

    _view_detector_from_behind_action = new QAction("behind", _main_window);
    _view_detector_from_behind_action->setStatusTip("View the detector looking to the sample");
    _view_detector_from_behind_action->setCheckable(true);
    _view_detector_from_behind_action->setChecked(false);
    _view_detector_from_behind_action->setActionGroup(_view_action_group);
    connect(_view_detector_from_behind_action,&QAction::triggered,_main_window,&MainWindow::onViewDetectorFromBehind);

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
    connect(_cursor_mode_action_group,&QActionGroup::triggered,this,&NSXMenu::onChangeCursorMode);

    // Interaction modes settings

    _interaction_mode_action_group = new QActionGroup(_main_window);
    _interaction_mode_action_group->setExclusive(true);

    auto *select_interaction_mode_action(new QAction("select",_main_window));
    select_interaction_mode_action->setStatusTip("Switch mouse interaction mode to select");
    select_interaction_mode_action->setCheckable(true);
    select_interaction_mode_action->setChecked(true);
    select_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(select_interaction_mode_action);

    auto *zoom_interaction_mode_action(new QAction(QString("zoom"),_main_window));
    zoom_interaction_mode_action->setStatusTip(QString("Switch mouse interaction mode to zoom"));
    zoom_interaction_mode_action->setCheckable(true);
    zoom_interaction_mode_action->setChecked(false);
    zoom_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(zoom_interaction_mode_action);

    auto *cutline_interaction_mode_action(new QAction(QString("cutline"),_main_window));
    cutline_interaction_mode_action->setStatusTip(QString("Switch mouse interaction mode to cutline"));
    cutline_interaction_mode_action->setCheckable(true);
    cutline_interaction_mode_action->setChecked(false);
    cutline_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(cutline_interaction_mode_action);

    auto *horizontal_slice_interaction_mode_action(new QAction(QString("horizontal slice"),_main_window));
    horizontal_slice_interaction_mode_action->setStatusTip("Switch mouse interaction mode to horizontal slice");
    horizontal_slice_interaction_mode_action->setCheckable(true);
    horizontal_slice_interaction_mode_action->setChecked(false);
    horizontal_slice_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(horizontal_slice_interaction_mode_action);

    auto *vertical_slice_interaction_mode_action(new QAction(QString("vertical slice"),_main_window));
    vertical_slice_interaction_mode_action->setStatusTip("Switch mouse interaction mode to vertical slice");
    vertical_slice_interaction_mode_action->setCheckable(true);
    vertical_slice_interaction_mode_action->setChecked(false);
    vertical_slice_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(vertical_slice_interaction_mode_action);

    auto *rectangular_mask_interaction_mode_action(new QAction(QString("rectangular mask"),_main_window));
    rectangular_mask_interaction_mode_action->setStatusTip("Switch mouse interaction mode to rectangular mask");
    rectangular_mask_interaction_mode_action->setCheckable(true);
    rectangular_mask_interaction_mode_action->setChecked(false);
    rectangular_mask_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(rectangular_mask_interaction_mode_action);

    auto *ellipsoidal_mask_interaction_mode_action(new QAction(QString("ellipsoidal mask"),_main_window));
    ellipsoidal_mask_interaction_mode_action->setStatusTip("Switch mouse interaction mode to ellipsoidal mask");
    ellipsoidal_mask_interaction_mode_action->setCheckable(true);
    ellipsoidal_mask_interaction_mode_action->setChecked(false);
    ellipsoidal_mask_interaction_mode_action->setActionGroup(_interaction_mode_action_group);
    _interaction_mode_actions.append(ellipsoidal_mask_interaction_mode_action);

    connect(_interaction_mode_action_group,&QActionGroup::triggered,this,&NSXMenu::onChangeInteractionMode);

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

    connect(_color_map_action_group,&QActionGroup::triggered,this,&NSXMenu::onChangeColorMap);

    // Dockable widgets menu settings

    _dockable_widget_state_group = new QActionGroup(_main_window);
    _dockable_widget_state_group->setExclusive(false);

    auto *session_action(new QAction("Session panel",_main_window));
    session_action->setStatusTip("Show/hide session panel");
    session_action->setCheckable(true);
    session_action->setChecked(true);
    session_action->setActionGroup(_dockable_widget_state_group);
    _dockable_widget_state_actions.append(session_action);

    auto *task_manager_action(new QAction("Task manager panel",_main_window));
    task_manager_action->setStatusTip("Show/hide monitor panel");
    task_manager_action->setCheckable(true);
    task_manager_action->setChecked(true);
    task_manager_action->setActionGroup(_dockable_widget_state_group);
    _dockable_widget_state_actions.append(task_manager_action);

    auto *logger_action = new QAction("Logger panel",_main_window);
    logger_action->setStatusTip("Show/hide monitor panel");
    logger_action->setCheckable(true);
    logger_action->setChecked(true);
    logger_action->setActionGroup(_dockable_widget_state_group);
    _dockable_widget_state_actions.append(logger_action);

    auto *plotter_action(new QAction("Plotter panel",_main_window));
    plotter_action->setStatusTip("Show/hide plotter panel");
    plotter_action->setCheckable(true);
    plotter_action->setChecked(true);
    plotter_action->setActionGroup(_dockable_widget_state_group);
    _dockable_widget_state_actions.append(plotter_action);

    auto *widget_property_action(new QAction("Widget property panel",_main_window));
    widget_property_action->setStatusTip("Show/hide widget property panel");
    widget_property_action->setCheckable(true);
    widget_property_action->setChecked(true);
    widget_property_action->setActionGroup(_dockable_widget_state_group);
    _dockable_widget_state_actions.append(widget_property_action);

    connect(_dockable_widget_state_group,&QActionGroup::triggered,this,&NSXMenu::onToggleDockableWidgetState);

    _display_isotopes_database_action = new QAction("Display isotopes database",_main_window);
    _display_isotopes_database_action->setStatusTip("Display isotopes database");
    connect(_display_isotopes_database_action,&QAction::triggered,this,&NSXMenu::onDisplayIsotopesDatabase);
    _display_isotopes_database_action->setShortcut(QKeySequence("Ctrl+I"));

    _about_action = new QAction("&About",_main_window);
    _about_action->setStatusTip("About application");
    _about_action->setShortcut(QKeySequence("Ctrl+A"));
    connect(_about_action,&QAction::triggered,this,&NSXMenu::onAboutApplication);
}

void NSXMenu::createMenus()
{
    _menu_bar = new QMenuBar(nullptr);

    if (hostOS() != OSType::MAC_OS) {
        _main_window->setMenuBar(_menu_bar);
    }

    _file_menu = _menu_bar->addMenu("&File");
    _file_menu->addAction(_new_experiment_action);
    _file_menu->addSeparator();
    _file_menu->addAction(_quit_action);

    _detector_menu = _menu_bar->addMenu("Detector");
    _view_from_menu = _detector_menu->addMenu("&View from");
    _view_from_menu->addAction(_view_detector_from_sample_action);
    _view_from_menu->addAction(_view_detector_from_behind_action);

    _cursor_mode_menu = _detector_menu->addMenu("Cursor mode");
    _cursor_mode_menu->addActions(_cursor_mode_actions);

    _interaction_mode_menu = _detector_menu->addMenu("Mouse interaction mode");
    _interaction_mode_menu->addActions(_interaction_mode_actions);

    _peaks_menu = _detector_menu->addMenu("Peaks");
    _peaks_menu->addAction(_display_peak_labels_action);
    _peaks_menu->addAction(_display_peak_centers_action);
    _peaks_menu->addAction(_display_peak_integration_areas_action);

    _detector_menu->addSeparator();

    _color_map_menu = _detector_menu->addMenu("Color maps");
    for (auto color_map_action : _color_map_actions) {
        _color_map_menu->addAction(color_map_action);
    }

    _dockable_widgets_menu = _menu_bar->addMenu("&Dockable widgets");
    _dockable_widgets_menu->addActions(_dockable_widget_state_actions);

    _chemistry_menu = _menu_bar->addMenu("&Chemistry");
    _chemistry_menu->addAction(_display_isotopes_database_action);

    _help_menu = _menu_bar->addMenu("&Help");
    _help_menu->addAction(_about_action);
}

void NSXMenu::onAboutApplication()
{
    DialogAbout dlg;

    dlg.exec();
}
void NSXMenu::onDisplayIsotopesDatabase()
{
    DialogIsotopesDatabase dlg;

    dlg.exec();
}

void NSXMenu::onChangeColorMap(QAction *color_map_action)
{
    _main_window->detectorSceneModel()->changeColorMap(color_map_action->text().toStdString());
}

void NSXMenu::onChangeCursorMode(QAction *cursor_mode_action)
{
    auto it = std::find(_cursor_mode_actions.begin(),_cursor_mode_actions.end(),cursor_mode_action);
    if (it == _cursor_mode_actions.end()) {
        return;
    }

    auto cursor_mode_index = static_cast<DetectorScene::CURSOR_MODE>(std::distance(_cursor_mode_actions.begin(),it));

    _main_window->detectorSceneModel()->changeCursorMode(cursor_mode_index);

}

void NSXMenu::onChangeInteractionMode(QAction *interaction_mode_action)
{
    auto it = std::find(_interaction_mode_actions.begin(),_interaction_mode_actions.end(),interaction_mode_action);
    if (it == _interaction_mode_actions.end()) {
        return;
    }

    auto interaction_mode_index = static_cast<DetectorScene::INTERACTION_MODE>(std::distance(_interaction_mode_actions.begin(),it));

    _main_window->detectorSceneModel()->changeInteractionMode(interaction_mode_index);
}

void NSXMenu::onToggleDockableWidgetState(QAction *dockable_widget_action)
{
    auto it = std::find(_dockable_widget_state_actions.begin(),_dockable_widget_state_actions.end(),dockable_widget_action);
    if (it == _dockable_widget_state_actions.end()) {
        return;
    }

    auto dockable_widget_index = static_cast<MainWindow::DOCKABLE_WIDGETS>(std::distance(_dockable_widget_state_actions.begin(),it));

    _main_window->toggleDockableWidgetState(dockable_widget_index,dockable_widget_action->isChecked());
}
