#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <functional>
#include <stdexcept>
#include <utility>

#include <Eigen/Dense>

#include <QDateTime>
#include <QFileDialog>
#include <QGraphicsBlurEffect>
#include <QGraphicsEllipseItem>
#include <QShortcut>
#include <QThread>
#include <QMouseEvent>
#include <QProgressDialog>
#include <QtDebug>
#include <QTransform>
#include <QProgressDialog>

#include "AABB.h"
#include "Basis.h"
#include "BlobFinder.h"
#include "Cluster.h"
#include "ComponentState.h"
#include "Detector.h"
#include "Ellipsoid.h"
#include "GruberReduction.h"
#include "ILLAsciiData.h"
#include "NiggliReduction.h"
#include "Peak3D.h"
#include "Sample.h"
#include "Source.h"

#include "DetectorScene.h"
#include "DialogExperiment.h"
#include "Tree/ExperimentTree.h"
#include "Logger.h"
#include "NoteBook.h"
#include "NumorsConversionDialog.h"
#include "PeakTableView.h"
#include "UnitCell.h"
#include "Units.h"
#include "Plot/SXPlot.h"
#include "PeakTableView.h"
#include "Absorption/AbsorptionWidget.h"
#include "chemistry/IsotopeDatabaseDialog.h"
#include "chemistry/ElementManagerDialog.h"
#include "GraphicsItems/CutLineGraphicsItem.h"
#include "GraphicsItems/CutSliceGraphicsItem.h"
#include "GraphicsItems/CutterGraphicsItem.h"
#include "GraphicsItems/PeakGraphicsItem.h"
#include "GraphicsItems/PlottableGraphicsItem.h"
#include "Plot/PlotFactory.h"
#include "Tree/UnitCellPropertyWidget.h"
#include "Tree/PeakListPropertyWidget.h"

#include "DialogConvolve.h"

#include "Path.h"
#include "IFrameIterator.h"
#include "Types.h"

#include "PeakFinder.h"
#include "ProgressHandler.h"

#include "JobHandler.h"

// jmf debug testing
#include <functional>
extern std::function<void(void)> processEvents;

using namespace SX::Units;
using namespace SX::Instrument;
using SX::Types::RealMatrix;
using SX::Utils::ProgressHandler;
using SX::Data::PeakFinder;

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent),
  _ui(new Ui::MainWindow),
  //_experiments(),
  _currentData(nullptr)
{
    _ui->setupUi(this);
    // Set Date to the application window title
    QDateTime datetime=QDateTime::currentDateTime();
    this->setWindowTitle(QString("NSXTool version:")+ datetime.toString());

    // Starting the logger of the main application
    Logger::Instance()->setNoteBook(_ui->noteBook);
    qInstallMessageHandler(customMessageHandler);
    qDebug() << "[NSXTool log]" << QDateTime::currentDateTime().toString();

    //
    _ui->frameFrame->setEnabled(false);
    _ui->intensityFrame->setEnabled(false);

    _ui->selectionMode->addItem(QIcon(":/resources/zoomIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/cutlineIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/horizontalSliceIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/verticalSliceIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/selectionIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/slice3D.png"),"");

    // Vertical splitter between Tree and Inspector Widget
    _ui->splitterVertical->setStretchFactor(0,50);
    _ui->splitterVertical->setStretchFactor(1,50);

    // Horizontal splitter between Tree and DetectorScene
    _ui->splitterHorizontal->setStretchFactor(0,10);
    _ui->splitterHorizontal->setStretchFactor(1,90);

    // signals and slots
    connect(_ui->experimentTree, SIGNAL(plotData(std::shared_ptr<SX::Data::IData>)),
            _ui->_dview->getScene(), SLOT(setData(std::shared_ptr<SX::Data::IData>))
    );

    connect(_ui->experimentTree, SIGNAL(plotData(std::shared_ptr<SX::Data::IData>)),
            this, SLOT(changeData(std::shared_ptr<SX::Data::IData>)));

    connect(_ui->experimentTree, SIGNAL(showPeakList(std::vector<std::shared_ptr<SX::Data::IData>>)),
            this, SLOT(showPeakList(std::vector<std::shared_ptr<SX::Data::IData>>)));

    connect(_ui->frame,&QScrollBar::valueChanged,[=](const int& value){_ui->_dview->getScene()->changeFrame(value);});

    connect(_ui->intensity,SIGNAL(valueChanged(int)),_ui->_dview->getScene(),SLOT(setMaxIntensity(int)));
    connect(_ui->selectionMode,SIGNAL(currentIndexChanged(int)),_ui->_dview->getScene(),SLOT(changeInteractionMode(int)));
    connect(_ui->_dview->getScene(),SIGNAL(updatePlot(PlottableGraphicsItem*)),this,SLOT(updatePlot(PlottableGraphicsItem*)));
    connect(_ui->action_open,SIGNAL(triggered()),_ui->experimentTree,SLOT(createNewExperiment()));

    _ui->plotterDockWidget->show();
    _ui->dockWidget_Property->show();

    connect(_ui->experimentTree,SIGNAL(inspectWidget(QWidget*)),this,SLOT(setInspectorWidget(QWidget*)));

    qDebug() << "The resources directory is " << SX::Utils::Path().getResourcesDir().c_str();

    _progressHandler = std::shared_ptr<ProgressHandler>(new ProgressHandler());
    _peakFinder = std::shared_ptr<PeakFinder>(new PeakFinder());
}

MainWindow::~MainWindow()
{
    delete _ui;
}

Ui::MainWindow* MainWindow::getUI() const
{
    return _ui;
}


void MainWindow::changeData(std::shared_ptr<IData> data)
{
    _ui->frameFrame->setEnabled(true);
    _ui->intensityFrame->setEnabled(true);

    int frameMax = data->getNFrames()-1;

    int frame = _ui->frame->value();

    if (frame > frameMax)
        frame = frameMax;

    _ui->frame->setValue(frame);

    _ui->frame->setMaximum(frameMax);

    _ui->spinBox_Frame->setMaximum(frameMax);

    //_ui->intensity->setValue(10);

}

void MainWindow::showPeakList(std::vector<std::shared_ptr<SX::Data::IData>> data)
{

    if (data.empty())
        return;

    PeakTableView* table=new PeakTableView();
    table->setData(data);
    table->show();
    // Ensure plot1D is updated
    connect(table,SIGNAL(plotPeak(SX::Crystal::Peak3D*)),this,SLOT(plotPeak(SX::Crystal::Peak3D*)));
    connect(table,
            SIGNAL(plotData(const QVector<double>&,const QVector<double>&,const QVector<double>&)),
            this,
            SLOT(plotData(const QVector<double>&,const QVector<double>&,const QVector<double>&)));

}

void MainWindow::plotPeak(SX::Crystal::Peak3D* peak)
{
    auto scenePtr=_ui->_dview->getScene();
    // Ensure that frames
    changeData(peak->getData());
    // Get frame number to adjust the data
    int data_frame=std::round(peak->getPeak()->getAABBCenter()[2]);
    scenePtr->setData(peak->getData(),data_frame);
    // Update the scrollbar
    _ui->frame->setValue(data_frame);
    auto pgi=scenePtr->findPeakGraphicsItem(peak);
    if (pgi)
    {
        updatePlot(pgi);
    }
}




void MainWindow::on_actionPixel_position_triggered()
{
   _ui->_dview->getScene()->changeCursorMode(DetectorScene::PIXEL);
}

void MainWindow::on_actionGamma_Nu_triggered()
{
    _ui->_dview->getScene()->changeCursorMode(DetectorScene::GAMMA);
}

void MainWindow::on_action2_Theta_triggered()
{
     _ui->_dview->getScene()->changeCursorMode(DetectorScene::THETA);
}

void MainWindow::on_actionH_k_l_triggered()
{
     _ui->_dview->getScene()->changeCursorMode(DetectorScene::HKL);
}


void MainWindow::on_actionD_spacing_triggered()
{
  _ui->_dview->getScene()->changeCursorMode(DetectorScene::DSPACING);
}

void MainWindow::on_actionLogger_triggered()
{
    if (_ui->loggerDockWidget->isHidden())
        _ui->loggerDockWidget->show();
    else
        _ui->loggerDockWidget->hide();
}

void MainWindow::on_action1D_Peak_Ploter_triggered()
{
    if (_ui->plotterDockWidget->isHidden())
        _ui->plotterDockWidget->show();
    else
        _ui->plotterDockWidget->hide();
}

void MainWindow::plotData(const QVector<double>& x,const QVector<double>& y,const QVector<double>& e)
{

    if (_ui->plot1D->getType().compare("simple")!=0)
    {
        // Store the old size policy
        QSizePolicy oldSizePolicy = _ui->plot1D->sizePolicy();
        // Remove the current plotter from the ui
        _ui->horizontalLayout_4->removeWidget(_ui->plot1D);
        // Delete the plotter instance
        delete _ui->plot1D;

        PlotFactory* pFactory=PlotFactory::Instance();

        _ui->plot1D = pFactory->create("simple",_ui->dockWidgetContents_4);

        // Restore the size policy
        _ui->plot1D->setSizePolicy(oldSizePolicy);

        // Sets some properties of the plotter
        _ui->plot1D->setObjectName(QStringLiteral("1D plotter"));
        _ui->plot1D->setFocusPolicy(Qt::StrongFocus);
        _ui->plot1D->setStyleSheet(QStringLiteral(""));

        // Add the plot to the ui
        _ui->horizontalLayout_4->addWidget(_ui->plot1D);
    }

    _ui->plot1D->graph(0)->setDataValueError(x,y,e);
    _ui->plot1D->rescaleAxes();

    _ui->plot1D->replot();

}

void MainWindow::updatePlot(PlottableGraphicsItem* item)
{
    if (!item)
        return;

    if (!item->isPlottable(_ui->plot1D))
    {
        // Store the old size policy
        QSizePolicy oldSizePolicy = _ui->plot1D->sizePolicy();
        // Remove the current plotter from the ui
        _ui->horizontalLayout_4->removeWidget(_ui->plot1D);
        // Delete the plotter instance
        delete _ui->plot1D;

        PlotFactory* pFactory=PlotFactory::Instance();

        _ui->plot1D = pFactory->create(item->getPlotType(),_ui->dockWidgetContents_4);

        // Restore the size policy
        _ui->plot1D->setSizePolicy(oldSizePolicy);

        // Sets some properties of the plotter
        _ui->plot1D->setObjectName(QStringLiteral("1D plotter"));
        _ui->plot1D->setFocusPolicy(Qt::StrongFocus);
        _ui->plot1D->setStyleSheet(QStringLiteral(""));

        // Add the plot to the ui
        _ui->horizontalLayout_4->addWidget(_ui->plot1D);

    }

    // Plot the data
    item->plot(_ui->plot1D);
    update();

}

void MainWindow::on_actionFrom_Sample_triggered()
{
    QTransform trans;
    trans.scale(1,-1);
    _ui->_dview->setTransform(trans);
    _ui->_dview->fitScene();
}

void MainWindow::on_actionBehind_Detector_triggered()
{
    QTransform trans;
    trans.scale(-1,-1);
    _ui->_dview->setTransform(trans);
    _ui->_dview->fitScene();
}

void MainWindow::on_action_display_isotopes_database_triggered()
{

    // Opens the dialog that will diplay the isotopes database
    IsotopeDatabaseDialog* dlg=new IsotopeDatabaseDialog();
    dlg->exec();
}

void MainWindow::on_action_add_element_triggered()
{
    // Opens the dialog that will diplay the isotopes database
    ElementManagerDialog* dlg=new ElementManagerDialog();
    dlg->exec();
}

void MainWindow::on_actionShow_labels_triggered(bool checked)
{
    _ui->_dview->getScene()->showPeakLabels(checked);
    _ui->_dview->getScene()->update();
}


void MainWindow::setInspectorWidget(QWidget* w)
{
    // Ensure that previous Property Widget is deleted.
    auto widget=_ui->dockWidget_Property->widget();
    if (widget)
        delete widget;

    // Assign current property Widget
    _ui->dockWidget_Property->setWidget(w);

    // Handle specific actions from these widgets
    if (UnitCellPropertyWidget* widget=dynamic_cast<UnitCellPropertyWidget*>(w))
    {
        connect(widget,SIGNAL(activateIndexingMode(std::shared_ptr<SX::Crystal::UnitCell>)),_ui->_dview->getScene(),SLOT(activateIndexingMode(std::shared_ptr<SX::Crystal::UnitCell>)));
        connect(widget,SIGNAL(cellUpdated()),_ui->_dview->getScene(),SLOT(updatePeaks()));
    }

    if (PeakListPropertyWidget* widget=dynamic_cast<PeakListPropertyWidget*>(w))
    {
        // Ensure plot1D is updated
        connect(widget->getPeakTableView(),SIGNAL(plotPeak(SX::Crystal::Peak3D*)),this,SLOT(plotPeak(SX::Crystal::Peak3D*)));
        connect(widget->getPeakTableView(),
                SIGNAL(plotData(const QVector<double>&,const QVector<double>&,const QVector<double>&)),
                this,
                SLOT(plotData(const QVector<double>&,const QVector<double>&,const QVector<double>&)));
    }
}

void MainWindow::on_actionConvert_to_HDF5_triggered()
{

    NumorsConversionDialog* dlg=new NumorsConversionDialog();
    dlg->exec();
}


void MainWindow::on_actionShow_calculated_peak_positions_triggered(bool checked)
{
    _ui->_dview->getScene()->showPeakCalcs(checked);
    _ui->_dview->getScene()->update();
}

void MainWindow::on_checkBox_AspectRatio_toggled(bool checked)
{
    _ui->_dview->fixDetectorAspectRatio(checked);
}

void MainWindow::on_actionConvolution_Filter_triggered()
{
    Eigen::MatrixXi frame = _ui->_dview->getScene()->getCurrentFrame();
    auto dialog = new DialogConvolve(frame, this);
    dialog->show();
}
