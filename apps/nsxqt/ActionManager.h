#pragma once

#include <QObject>
#include <QList>

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

    void onChangeColorMap(QAction *color_map_action);

    void onChangeCursorMode(QAction *cursor_mode_action);

    void onChangeInteractionMode(QAction *interaction_mode_action);

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

    QMenu *_detector_menu;
    QMenu *_view_from_menu;
    QActionGroup *_view_action_group;
    QAction *_view_detector_from_sample_action;
    QAction *_view_detector_from_behind_action;

    QMenu *_cursor_mode_menu;
    QActionGroup *_cursor_mode_action_group;
    QList<QAction*> _cursor_mode_actions;

    QMenu *_interaction_mode_menu;
    QActionGroup *_interaction_mode_action_group;
    QList<QAction*> _interaction_mode_actions;

    QAction *_logarithmic_scale_action;

    QMenu *_peaks_menu;
    QAction *_display_peak_labels_action;
    QAction *_display_peak_centers_action;
    QAction *_display_peak_integration_areas_action;

    QMenu *_color_map_menu;
    QActionGroup *_color_map_action_group;
    QList<QAction*> _color_map_actions;

    QMenu *_dockable_widgets_menu;
    QActionGroup *_dockable_widget_state_group;
    QList<QAction*> _dockable_widget_state_actions;

    QMenu *_chemistry_menu;
    QAction *_display_isotopes_database_action;

    QMenu *_help_menu;
    QAction *_about_action;
};
