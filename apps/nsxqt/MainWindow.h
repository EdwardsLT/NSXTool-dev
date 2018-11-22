#pragma once

#include <string>

#include <QGraphicsScene>
#include <QMainWindow>
#include <QMenu>
#include <QProgressBar>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/DataTypes.h>
#include <nsxlib/UtilsTypes.h>

#include "ProgressView.h"
#include "TaskManagerModel.h"

class DataItem;
class PlottableGraphicsItem;
class QListWidgetItem;
class SessionModel;

namespace Ui {
class MainWindow;
}

class QProgressDialog;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:

    MainWindow(QWidget *parent=nullptr);

    ~MainWindow();

    virtual void closeEvent(QCloseEvent *event) override;

    void setColorMap(const std::string& name);

    TaskManagerModel* taskManagerModel();

signals:
    void plotDetectorData(nsx::DataSet*,int frame);

private slots:
    void on_actionAbout_triggered();

    void on_actionPixel_position_triggered();
    void on_actionGamma_Nu_triggered();
    void on_action2_Theta_triggered();
    void on_actionD_spacing_triggered();
    void on_actionMiller_indices_triggered();
    void on_actionLogger_triggered();
    void on_action1D_Peak_Ploter_triggered();
    void on_actionProperty_triggered();
    void updatePlot(PlottableGraphicsItem* cutter);
    void on_actionFrom_Sample_triggered();
    void on_actionBehind_Detector_triggered();
    void on_action_display_isotopes_database_triggered();
    void on_checkBox_AspectRatio_toggled(bool checked);

    void on_actionLogarithmic_Scale_triggered(bool checked);

    void on_actionDraw_peak_integration_area_triggered(bool checked);
     

public slots:

    void plotData(const QVector<double>&,const QVector<double>&,const QVector<double>&);

    void setInspectorWidget(QWidget*);

    void onOpenPeakFinderDialog(DataItem *data_item);

private slots:

    void slotChangeSelectedData(nsx::sptrDataSet, int frame);

    void slotChangeSelectedPeak(nsx::sptrPeak3D peak);

    void slotChangeSelectedFrame(int selected_frame);

private:

    Ui::MainWindow* _ui;

    SessionModel *_session_model;

    TaskManagerModel *_task_manager_model;

    std::string _colormap;
};
