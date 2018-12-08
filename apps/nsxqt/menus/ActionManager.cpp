#include <algorithm>

#include <QAction>
#include <QActionGroup>
#include <QKeySequence>
#include <QMenu>
#include <QMenuBar>

#include "ActionManager.h"
#include "DetectorMenu.h"
#include "DialogAbout.h"
#include "DialogIsotopesDatabase.h"
#include "GlobalInfo.h"
#include "MainWindow.h"

ActionManager::ActionManager(MainWindow *main_window) : _main_window(main_window)
{
    createActions();
    createMenus();
}

void ActionManager::createActions()
{
    _new_experiment_action = new QAction("&New experiment",_main_window);
    _new_experiment_action->setStatusTip("Create new experiment");
    _new_experiment_action->setShortcut(QKeySequence("Ctrl+E"));
    connect(_new_experiment_action,&QAction::triggered,_main_window,&MainWindow::onNewExperiment);

    _quit_action = new QAction("&Quit",_main_window);
    _quit_action->setStatusTip("Quit application");
    _quit_action->setShortcut(QKeySequence::Quit);
    connect(_quit_action,&QAction::triggered,_main_window,&MainWindow::close);

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

    connect(_dockable_widget_state_group,&QActionGroup::triggered,this,&ActionManager::onToggleDockableWidgetState);

    _display_isotopes_database_action = new QAction("Display isotopes database",_main_window);
    _display_isotopes_database_action->setStatusTip("Display isotopes database");
    connect(_display_isotopes_database_action,&QAction::triggered,this,&ActionManager::onDisplayIsotopesDatabase);
    _display_isotopes_database_action->setShortcut(QKeySequence("Ctrl+I"));

    _about_action = new QAction("&About",_main_window);
    _about_action->setStatusTip("About application");
    _about_action->setShortcut(QKeySequence("Ctrl+A"));
    connect(_about_action,&QAction::triggered,this,&ActionManager::onAboutApplication);
}

void ActionManager::createMenus()
{
    _menu_bar = new QMenuBar(nullptr);

    if (hostOS() != OSType::MAC_OS) {
        _main_window->setMenuBar(_menu_bar);
    }

    _file_menu = _menu_bar->addMenu("&File");
    _file_menu->addAction(_new_experiment_action);
    _file_menu->addSeparator();
    _file_menu->addAction(_quit_action);

    _detector_menu = new DetectorMenu(_main_window);
    _menu_bar->addMenu(_detector_menu);

    _dockable_widgets_menu = _menu_bar->addMenu("&Panels");
    _dockable_widgets_menu->addActions(_dockable_widget_state_actions);

    _chemistry_menu = _menu_bar->addMenu("&Chemistry");
    _chemistry_menu->addAction(_display_isotopes_database_action);

    _help_menu = _menu_bar->addMenu("&Help");
    _help_menu->addAction(_about_action);
}

void ActionManager::onAboutApplication()
{
    DialogAbout dlg;

    dlg.exec();
}
void ActionManager::onDisplayIsotopesDatabase()
{
    DialogIsotopesDatabase dlg;

    dlg.exec();
}

void ActionManager::onToggleDockableWidgetState(QAction *dockable_widget_action)
{
    auto it = std::find(_dockable_widget_state_actions.begin(),_dockable_widget_state_actions.end(),dockable_widget_action);
    if (it == _dockable_widget_state_actions.end()) {
        return;
    }

    auto dockable_widget_index = static_cast<MainWindow::DOCKABLE_WIDGETS>(std::distance(_dockable_widget_state_actions.begin(),it));

    _main_window->toggleDockableWidgetState(dockable_widget_index);
}
