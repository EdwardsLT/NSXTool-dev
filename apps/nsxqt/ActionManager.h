#pragma once

#include <QObject>
#include <QList>

class DetectorMenu;
class QAction;
class QActionGroup;
class QMenu;
class QMenuBar;
class MainWindow;

class ActionManager : public QObject
{

public:

    ActionManager(MainWindow *main_window);

private slots:

    void onAboutApplication();

    void onDisplayIsotopesDatabase();

    void onToggleDockableWidgetState(QAction *dockable_widget_action);

private:

    void createActions();

    void createMenus();

private:

    MainWindow *_main_window;

    QMenuBar *_menu_bar;

    QMenu *_file_menu;
    QAction *_new_experiment_action;
    QAction *_quit_action;

    DetectorMenu *_detector_menu;

    QMenu *_dockable_widgets_menu;
    QActionGroup *_dockable_widget_state_group;
    QList<QAction*> _dockable_widget_state_actions;

    QMenu *_chemistry_menu;
    QAction *_display_isotopes_database_action;

    QMenu *_help_menu;
    QAction *_about_action;
};
