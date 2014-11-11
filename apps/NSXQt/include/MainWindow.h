#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <unordered_map>
#include <vector>

#include <QGraphicsScene>
#include <QMainWindow>
#include <QMenu>
#include <QProgressBar>

#include <IData.h>
#include <DialogPeakFind.h>
#include "Experiment.h"
#include "ILLAsciiDataReader.h"
#include "Logger.h"

class QListWidgetItem;

namespace Ui
{
    class MainWindow;
}

namespace SX
{
    namespace Data
    {
        class IData;
    }
    namespace Instrument
    {
        class Experiment;
    }
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

private slots:
    void on_action_open_triggered();

    void on_action_peak_find_triggered();

    void on_actionUnit_Cell_triggered();

    void on_actionPeak_List_triggered();

    void on_actionPixel_position_triggered();

    void on_actionGamma_Nu_triggered();

    void on_action2_Theta_triggered();

    void on_actionD_spacing_triggered();

public slots:
    void changeData(SX::Data::IData*);

private:
    Ui::MainWindow* _ui;
    std::unordered_map<std::string,SX::Instrument::Experiment> _experiments;
    SX::Data::IData* _currentData;

};

#endif // MAINWINDOW_H
