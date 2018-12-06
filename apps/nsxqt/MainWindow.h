#pragma once

#include <string>

#include <QMainWindow>
#include <QVector>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/DataTypes.h>
#include <nsxlib/UtilsTypes.h>

class DetectorGraphicsView;
class DetectorScene;
class ExperimentTree;
class NoteBook;
class NSXMenu;
class PlottableGraphicsItem;
class QCloseEvent;
class QDockWidget;
class QSlider;
class QSpinBox;
class QStatusBar;
class QVBoxLayout;
class QWidget;
class SessionModel;
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

    DetectorScene* detectorSceneModel();

    SessionModel* sessionModel();

    TaskManagerModel* taskManagerModel();

    void toggleDockableWidgetState(DOCKABLE_WIDGETS dockable_widget_index, bool flag);

public slots:

    void plotData(const QVector<double>&,const QVector<double>&,const QVector<double>&);

    void onChangeMaxIntensity(int max_intensity);

    void onChangeSelectedData(nsx::sptrDataSet, int frame);

    void onChangeSelectedFrame(int selected_frame);

    void onChangeSelectedPeak(nsx::sptrPeak3D peak);

    void onDisplaySessionItemPropertyWidget(QWidget*);

    void onNewExperiment();

    void onPlotDetectorItem(PlottableGraphicsItem *cutter);

    void onViewDetectorFromBehind();

    void onViewDetectorFromSample();

    void on_checkBox_AspectRatio_toggled(bool checked);

    void on_actionLogarithmic_Scale_triggered(bool checked);

private:

    void createActions();

    void createConnections();

    void createDockWindows();

    void createLoggers();

    void createMainWindow();

    void createModels();

    void createStatusBar();

private:

    DetectorScene *_detector_scene_model;

    SessionModel *_session_model;

    TaskManagerModel *_task_manager_model;

    QVBoxLayout *_main_layout;

    std::vector<QDockWidget*> _dockable_widgets;

    DetectorGraphicsView *_detector_view;

    QSlider *_frame_slider;

    QSpinBox *_frame_value;

    QSlider *_intensity_slider;

    QSpinBox *_intensity_value;

    ExperimentTree *_session_view;

    TaskManagerView *_task_manager_view;

    NoteBook *_logger;

    SXPlot *_plotter;

    QWidget *_property_widget;

    NSXMenu *_menu_bar;
};
