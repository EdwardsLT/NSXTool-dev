#pragma once

#include <string>

#include <QMainWindow>
#include <QVector>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/DataTypes.h>
#include <nsxlib/UtilsTypes.h>

class ActionManager;
class DetectorSceneModel;
class DetectorSceneView;
class NoteBook;
class QCloseEvent;
class QDockWidget;
class QSlider;
class QSpinBox;
class QStatusBar;
class QVBoxLayout;
class QWidget;
class SessionModel;
class SessionTreeView;
class SXPlot;
class TaskManagerModel;
class TaskManagerView;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:

    enum class DOCKABLE_WIDGETS {SESSION=0, TASK_MANAGER=0, LOGGER=2, PLOTTER=3, PROPERTY=4, COUNT=5};

    MainWindow(QWidget *parent=nullptr);

    ~MainWindow();

    virtual void closeEvent(QCloseEvent *event) override;

    DetectorSceneModel* detectorSceneModel();

    SessionModel* sessionModel();

    TaskManagerModel* taskManagerModel();

    void toggleDockableWidgetState(DOCKABLE_WIDGETS dockable_widget_index);

public slots:

    void onChangeContrastLevel(int contrast_level);

    void onChangeSelectedData(nsx::sptrDataSet, int frame);

    void onChangeSelectedFrame(int selected_frame);

    void onDisplaySessionItemPropertyWidget(QWidget*);

    void onNewExperiment();

    void onChangePlot(SXPlot *plot);

    void onChangeSelectedPeak(nsx::sptrPeak selected_peak);

private:

    void createActions();

    void createConnections();

    void createDockWindows();

    void createLoggers();

    void createMainWindow();

    void createModels();

    void createStatusBar();

private:

    DetectorSceneModel *_detector_scene_model;

    SessionModel *_session_model;

    TaskManagerModel *_task_manager_model;

    QVBoxLayout *_main_layout;

    std::vector<QDockWidget*> _dockable_widgets;

    DetectorSceneView *_detector_scene_view;

    QSlider *_frame_slider;

    QSpinBox *_frame_value;

    QSlider *_contrast_level_slider;

    QSpinBox *_contrast_level_value;

    SessionTreeView *_session_tree_view;

    TaskManagerView *_task_manager_view;

    NoteBook *_logger;

    SXPlot *_plotter;

    QWidget *_property_widget;

    ActionManager *_action_manager;
};
