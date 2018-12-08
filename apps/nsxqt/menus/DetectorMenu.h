#pragma once

#include <QList>
#include <QMenu>

class MainWindow;
class QAction;
class QActionGroup;

class DetectorMenu : public QMenu
{
    Q_OBJECT

public:

    explicit DetectorMenu(MainWindow *main_window);

private slots:

    void onChangeColorMap(QAction *color_map_action);

    void onChangeCursorMode(QAction *cursor_mode_action);

    void onChangeInteractionMode(QAction *interaction_mode_action);

private:

    void createActions();

    void createMenus();

private:

    MainWindow *_main_window;

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

};
