#include <fstream>
#include <functional>
#include <stdexcept>

#include <QDateTime>
#include <QDockWidget>
#include <QFileDialog>
#include <QMouseEvent>
#include <QProgressDialog>
#include <QSlider>
#include <QSpinBox>
#include <QStatusBar>
#include <QTransform>
#include <QLayout>

#include <nsxlib/AggregateStreamWrapper.h>
#include <nsxlib/CrystalTypes.h>
#include <nsxlib/Detector.h>
#include <nsxlib/LogFileStreamWrapper.h>
#include <nsxlib/Logger.h>
#include <nsxlib/Path.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/ProgressHandler.h>
#include <nsxlib/Sample.h>
#include <nsxlib/Source.h>
#include <nsxlib/SpaceGroup.h>
#include <nsxlib/UnitCell.h>
#include <nsxlib/Units.h>
#include <nsxlib/Version.h>

#include "ActionManager.h"
#include "DataItem.h"
#include "DetectorSceneModel.h"
#include "DetectorSceneView.h"
#include "DialogExperiment.h"
#include "DialogIntegrate.h"
#include "DialogPeakFilter.h"
#include "MainWindow.h"
#include "MouseInteractionModeModel.h"
#include "NoteBook.h"
#include "PeakGraphicsItem.h"
#include "PlottableGraphicsItem.h"
#include "PeakTableView.h"
#include "PlotterFactory.h"
#include "QtStreamWrapper.h"
#include "SessionModel.h"
#include "SessionTreeView.h"
#include "SimplePlot.h"
#include "SXPlot.h"
#include "TaskManagerModel.h"
#include "TaskManagerView.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    createModels();

    createMainWindow();

    createDockWindows();

    createActions();

    createStatusBar();

    createLoggers();

    createConnections();
}

void MainWindow::createActions()
{
    _action_manager = new ActionManager(this);
}

void MainWindow::createConnections()
{
    connect(_session_model,&SessionModel::signalSelectedDataChanged, this,&MainWindow::onChangeSelectedData);
    connect(_session_model,&SessionModel::signalChangeSelectedPeak, this,&MainWindow::onChangeSelectedPeak);

    connect(_frame_slider,&QSlider::valueChanged,this,&MainWindow::onChangeSelectedFrame);
    connect(_frame_value,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,&MainWindow::onChangeSelectedFrame);

    connect(_intensity_slider,&QSlider::valueChanged,this,&MainWindow::onChangeMaxIntensity);
    connect(_intensity_value,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,&MainWindow::onChangeMaxIntensity);

    connect(_session_model,&SessionModel::signalChangePlot,this,&MainWindow::onChangePlot);

    connect(_session_tree_view,&SessionTreeView::signalSelectSessionTreeItem,this,&MainWindow::onDisplaySessionItemPropertyWidget);
}

void MainWindow::createDockWindows()
{
    // Setup the session tree widget
    auto *session_tree_view_dock_widget = new QDockWidget("session",this);
    session_tree_view_dock_widget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
    session_tree_view_dock_widget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    _session_tree_view = new SessionTreeView(this);
    _session_tree_view->header()->hide();
    _session_tree_view->setModel(_session_model);
    session_tree_view_dock_widget->setWidget(_session_tree_view);
    addDockWidget(Qt::LeftDockWidgetArea,session_tree_view_dock_widget);
    _dockable_widgets.push_back(session_tree_view_dock_widget);

    // Setup the task manager widget
    auto *task_manager_view_dock_widget = new QDockWidget("tasks",this);
    task_manager_view_dock_widget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
    task_manager_view_dock_widget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    _task_manager_view = new TaskManagerView(this);
    _task_manager_view->setModel(_task_manager_model);
    task_manager_view_dock_widget->setWidget(_task_manager_view);
    addDockWidget(Qt::LeftDockWidgetArea,task_manager_view_dock_widget);
    _dockable_widgets.push_back(task_manager_view_dock_widget);

    // Setup the logger widget
    auto *logger_dock_widget = new QDockWidget("logger",this);
    logger_dock_widget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
    logger_dock_widget->setAllowedAreas(Qt::AllDockWidgetAreas);
    _logger = new NoteBook(this);
    logger_dock_widget->setWidget(_logger);
    addDockWidget(Qt::BottomDockWidgetArea,logger_dock_widget);
    _dockable_widgets.push_back(logger_dock_widget);

    // Setup the plotter widget
    auto *plotter_dock_widget = new QDockWidget("plot",this);
    plotter_dock_widget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
    plotter_dock_widget->setAllowedAreas(Qt::AllDockWidgetAreas);
    _plotter = new SXPlot(this);
    plotter_dock_widget->setWidget(_plotter);
    addDockWidget(Qt::BottomDockWidgetArea,plotter_dock_widget);
    _dockable_widgets.push_back(plotter_dock_widget);

    // Setup the property widget
    auto *property_widget_dock_widget = new QDockWidget("property",this);
    property_widget_dock_widget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
    property_widget_dock_widget->setAllowedAreas(Qt::AllDockWidgetAreas);
    _property_widget = new QWidget(this);
    property_widget_dock_widget->setWidget(_property_widget);
    addDockWidget(Qt::BottomDockWidgetArea,property_widget_dock_widget);
    _dockable_widgets.push_back(property_widget_dock_widget);
}

void MainWindow::createLoggers()
{
    auto debug_log = [this]() -> nsx::Logger
    {
        auto initialize = []() -> std::string {return "[DEBUG] " + nsx::currentTime();};
        auto finalize = []() -> std::string {return "\n";};

        nsx::AggregateStreamWrapper* wrapper = new nsx::AggregateStreamWrapper();
        wrapper->addWrapper(new nsx::LogFileStreamWrapper("nsx_debug.txt",initialize,finalize));
        wrapper->addWrapper(new QtStreamWrapper(_logger,initialize));

        return nsx::Logger(wrapper);
    };

    auto info_log = [this]() -> nsx::Logger
    {
        auto initialize = []() -> std::string {return "[INFO]  " + nsx::currentTime();};
        auto finalize = []() -> std::string {return "\n";};

        nsx::AggregateStreamWrapper* wrapper = new nsx::AggregateStreamWrapper();
        wrapper->addWrapper(new nsx::LogFileStreamWrapper("nsx_info.txt",initialize,finalize));
        wrapper->addWrapper(new QtStreamWrapper(_logger,initialize));

        return nsx::Logger(wrapper);
    };

    auto error_log = [this]() -> nsx::Logger
    {
        auto initialize = []() -> std::string {return "[ERROR]" + nsx::currentTime();};
        auto finalize = []() -> std::string {return "\n";};

        nsx::AggregateStreamWrapper* wrapper = new nsx::AggregateStreamWrapper();
        wrapper->addWrapper(new nsx::LogFileStreamWrapper("nsx_error.txt",initialize,finalize));
        wrapper->addWrapper(new QtStreamWrapper(_logger, initialize));

        return nsx::Logger(wrapper);
    };

    nsx::setDebug(debug_log);
    nsx::setInfo(info_log);
    nsx::setError(error_log);
}

void MainWindow::createMainWindow()
{
    _detector_scene_view = new DetectorSceneView(this);
    _detector_scene_view->setScene(_detector_scene_model);

    // The frame control settings

    QGridLayout *control_layout(new QGridLayout());

    QLabel *frame_label(new QLabel("frame"));

    _frame_slider = new QSlider(Qt::Horizontal);
    _frame_slider->setSingleStep(1);

    _frame_value = new QSpinBox();
    _frame_value->setSingleStep(1);
    _frame_value->setWrapping(true);

    control_layout->addWidget(frame_label,0,0);
    control_layout->addWidget(_frame_slider,0,1);
    control_layout->addWidget(_frame_value,0,2);

    // The intensity control settings

    QLabel *intensity_label(new QLabel("intensity"));

    _intensity_slider = new QSlider(Qt::Horizontal);
    _intensity_slider->setSingleStep(1);
    _intensity_slider->setRange(0,1000);

    _intensity_slider->setValue(_detector_scene_model->maxIntensity());
    _intensity_value = new QSpinBox();
    _intensity_value->setRange(0,1000);

    _intensity_value->setSingleStep(1);
    _intensity_value->setValue(_detector_scene_model->maxIntensity());
    _intensity_value->setWrapping(true);

    control_layout->addWidget(intensity_label,1,0);
    control_layout->addWidget(_intensity_slider,1,1);
    control_layout->addWidget(_intensity_value,1,2);

    control_layout->setColumnStretch(0,0);
    control_layout->setColumnStretch(1,1);
    control_layout->setColumnStretch(2,0);

    _main_layout = new QVBoxLayout();
    _main_layout->addWidget(_detector_scene_view);
    _main_layout->addLayout(control_layout);
    _main_layout->setStretch(0,1);
    _main_layout->setStretch(1,0);

    QWidget * main_window(new QWidget());
    main_window->setLayout(_main_layout);

    setCentralWidget(main_window);
}

void MainWindow::createModels()
{
    _session_model = new SessionModel();
    _detector_scene_model = new DetectorSceneModel(_session_model);
    _task_manager_model = new TaskManagerModel();
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage("NSXTool session started on " + QDateTime::currentDateTime().toString());
}

void MainWindow::onNewExperiment()
{
    std::unique_ptr<DialogExperiment> dlg;

    // DialogExperiment could throw an exception if it fails to read the resource files
    try {
        dlg = std::unique_ptr<DialogExperiment>(new DialogExperiment());

        // The user pressed cancel, return
        if (!dlg->exec()) {
            return;
        }

        // If no experiment name is provided, pop up a warning
        if (dlg->experimentName().isEmpty()) {
            throw std::runtime_error("Empty experiment name");
        }
    }
    catch(std::exception& e) {
        nsx::error() << e.what();
        return;
    }

    nsx::sptrExperiment experiment;

    try {
        auto experiment_name = dlg->experimentName().toStdString();
        auto instrument_name = dlg->instrumentName().toStdString();

        // Create an experiment
        experiment = std::make_shared<nsx::Experiment>(experiment_name,instrument_name);
    }
    catch(const std::runtime_error& e) {
        nsx::error() << e.what();
        return;
    }

    _session_model->addExperiment(experiment);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QApplication::closeAllWindows();

    QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow()
{
    qInstallMessageHandler(0);
}

DetectorSceneModel* MainWindow::detectorSceneModel()
{
    return _detector_scene_model;
}

SessionModel* MainWindow::sessionModel()
{
    return _session_model;
}

TaskManagerModel* MainWindow::taskManagerModel()
{
    return _task_manager_model;
}

void MainWindow::onChangeSelectedData(nsx::sptrDataSet data, int frame)
{
    int max_frames = int(data->nFrames()) - 1;

    _frame_slider->setRange(0,max_frames);
    _frame_slider->setValue(frame);

    _frame_value->setRange(0,max_frames);
    _frame_value->setValue(frame);
}

void MainWindow::onChangeSelectedPeak(nsx::sptrPeak3D selected_peak)
{
    auto ellipsoid = selected_peak->shape();
    ellipsoid.scale(selected_peak->bkgEnd());
    const auto& aabb = ellipsoid.aabb();

    auto data = selected_peak->data();

    // Get frame number to adjust the data
    int frame = static_cast<int>(std::lround(aabb.center()[2]));

    onChangeSelectedData(data,frame);

    auto *plot = new SimplePlot();

    Eigen::Vector3i lower = aabb.lower().cast<int>();

    lower[0] = (lower[0] < 0) ? 0 : lower[0];
    lower[1] = (lower[1] < 0) ? 0 : lower[1];
    lower[2] = (lower[2] < 0) ? 0 : lower[2];

    const int n_rows = data->nRows();
    const int n_cols = data->nCols();
    const int n_frames = data->nFrames();

    Eigen::Vector3i upper = aabb.upper().cast<int>();
    upper[0] = (upper[0] >= n_cols) ? n_cols - 1 : upper[0];
    upper[1] = (upper[1] >= n_rows) ? n_rows - 1 : upper[1];
    upper[2] = (upper[2] >= n_frames) ? n_frames - 1 : upper[2];

    QVector<double> x_values;
    QVector<double> y_values;
    QVector<double> err_y_values;

    for (int z = lower[2]; z <= upper[2]; ++z) {
        const auto& frame = data->frame(z);
        double counts = static_cast<double>(frame.block(lower[1],lower[0],upper[1]-lower[1],upper[0]-lower[0]).sum());
        x_values.append(static_cast<double>(z));
        y_values.append(counts);
        err_y_values.append(counts > 0 ? std::sqrt(counts) : 0.0);
    }

    plot->graph(0)->setDataValueError(x_values, y_values, err_y_values);

    plot->xAxis->setAutoTicks(false);
    plot->xAxis->setTickVector(x_values);

    plot->rescaleAxes();
    plot->replot();

    onChangePlot(plot);
}

void MainWindow::onChangeSelectedFrame(int selected_frame)
{
    _frame_slider->setValue(selected_frame);
    _frame_value->setValue(selected_frame);
    _detector_scene_model->changeSelectedFrame(selected_frame);
}

void MainWindow::onChangeMaxIntensity(int max_intensity)
{
    _intensity_slider->setValue(max_intensity);
    _intensity_value->setValue(max_intensity);
    _detector_scene_model->changeMaxIntensity(max_intensity);
}

void MainWindow::toggleDockableWidgetState(DOCKABLE_WIDGETS dockable_widget_index)
{
    auto index = static_cast<int>(dockable_widget_index);

    auto *dockable_widget = _dockable_widgets[index];

    if (dockable_widget->isHidden()) {
        dockable_widget->show();
    } else {
        dockable_widget->hide();
    }
}

void MainWindow::onChangePlot(SXPlot* plot)
{
    if (!plot) {
        return;
    }

    QDockWidget *plotter_dock_widget = _dockable_widgets[static_cast<int>(DOCKABLE_WIDGETS::PLOTTER)];

    QSizePolicy old_size_policy;

    if (_plotter) {
        // Store the old size policy
        old_size_policy = _plotter->sizePolicy();

        // Remove the current plotter from the ui
        plotter_dock_widget->setWidget(nullptr);

        // Delete the plotter instance
        delete _plotter;
    }

    _plotter = plot;

    // Restore the size policy
    _plotter->setSizePolicy(old_size_policy);

    // Sets some properties of the plotter
    _plotter->setObjectName(QStringLiteral("1D plotter"));
    _plotter->setFocusPolicy(Qt::StrongFocus);
    _plotter->setStyleSheet(QStringLiteral(""));

    // Add the plot to the ui
    plotter_dock_widget->setWidget(_plotter);

    update();
}

void MainWindow::onDisplaySessionItemPropertyWidget(QWidget* w)
{
    auto *property_dock_widget = _dockable_widgets[static_cast<int>(DOCKABLE_WIDGETS::PROPERTY)];

    // Ensure that previous Property Widget is deleted.
    auto previous_widget = property_dock_widget->widget();
    if (previous_widget) {
        delete previous_widget;
    }

    // Assign current property Widget
    property_dock_widget->setWidget(w);
}
