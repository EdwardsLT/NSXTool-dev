#include <cmath>
#include <fstream>
#include <functional>
#include <stdexcept>

#include <Eigen/Dense>

#include <QDateTime>
#include <QDockWidget>
#include <QFileDialog>
#include <QGraphicsBlurEffect>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QProgressDialog>
#include <QShortcut>
#include <QThread>
#include <QTransform>

#include <nsxlib/AABB.h>
#include <nsxlib/AggregateStreamWrapper.h>
#include <nsxlib/Basis.h>
#include <nsxlib/BlobFinder.h>
#include <nsxlib/ComponentState.h>
#include <nsxlib/CrystalTypes.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Ellipsoid.h>
#include <nsxlib/GruberReduction.h>
#include <nsxlib/IFrameIterator.h>
#include <nsxlib/LogFileStreamWrapper.h>
#include <nsxlib/Logger.h>
#include <nsxlib/MathematicsTypes.h>
#include <nsxlib/NiggliReduction.h>
#include <nsxlib/Path.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/PeakFilter.h>
#include <nsxlib/PeakFinder.h>
#include <nsxlib/Profile3d.h>
#include <nsxlib/ProgressHandler.h>
#include <nsxlib/Sample.h>
#include <nsxlib/Source.h>
#include <nsxlib/SpaceGroup.h>
#include <nsxlib/UnitCell.h>
#include <nsxlib/Units.h>
#include <nsxlib/WeakPeakIntegrator.h>

#include "AbsorptionWidget.h"
#include "CollectedPeaksModel.h"
#include "ColorMap.h"
#include "CutLineGraphicsItem.h"
#include "CutSliceGraphicsItem.h"
#include "CutterGraphicsItem.h"
#include "DetectorScene.h"
#include "DialogConvolve.h"
#include "DialogExperiment.h"
#include "DialogIntegrate.h"
#include "DialogPeakFilter.h"
#include "ExperimentTree.h"
#include "IsotopeDatabaseDialog.h"
#include "JobHandler.h"
#include "MainWindow.h"
#include "NoteBook.h"
#include "NumorsConversionDialog.h"
#include "PeakGraphicsItem.h"
#include "PlottableGraphicsItem.h"
#include "ResolutionCutoffDialog.h"
#include "PeakListPropertyWidget.h"
#include "PeakTableView.h"
#include "PlotFactory.h"
#include "QtStreamWrapper.h"
#include "SessionModel.h"
#include "SXPlot.h"
#include "UnitCellPropertyWidget.h"

#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent),
  _ui(new Ui::MainWindow),
  //_experiments(),
  _currentData(nullptr),
  _session(new SessionModel)
{
    _ui->setupUi(this);

    // make experiment tree aware of the session
    _ui->experimentTree->setSession(_session);

    // Set Date to the application window title
    QDateTime datetime=QDateTime::currentDateTime();
    this->setWindowTitle(QString("NSXTool version:")+ datetime.toString());

    auto debug_log = [this]() -> nsx::Logger
    {
        auto initialize = []() -> std::string {return "[DEBUG] " + nsx::currentTime();};
        auto finalize = []() -> std::string {return "\n";};

        nsx::AggregateStreamWrapper* wrapper = new nsx::AggregateStreamWrapper();
        wrapper->addWrapper(new nsx::LogFileStreamWrapper("nsx_debug.txt",initialize,finalize));
        wrapper->addWrapper(new QtStreamWrapper(this->_ui->noteBook,initialize));

        return nsx::Logger(wrapper);
    };

    auto info_log = [this]() -> nsx::Logger
    {
        auto initialize = []() -> std::string {return "[INFO]  " + nsx::currentTime();};
        auto finalize = []() -> std::string {return "\n";};

        nsx::AggregateStreamWrapper* wrapper = new nsx::AggregateStreamWrapper();
        wrapper->addWrapper(new nsx::LogFileStreamWrapper("nsx_info.txt",initialize,finalize));
        wrapper->addWrapper(new QtStreamWrapper(this->_ui->noteBook,initialize));

        return nsx::Logger(wrapper);
    };

    auto error_log = [this]() -> nsx::Logger
    {
        auto initialize = []() -> std::string {return "[ERROR]" + nsx::currentTime();};
        auto finalize = []() -> std::string {return "\n";};

        nsx::AggregateStreamWrapper* wrapper = new nsx::AggregateStreamWrapper();
        wrapper->addWrapper(new nsx::LogFileStreamWrapper("nsx_error.txt",initialize,finalize));
        wrapper->addWrapper(new QtStreamWrapper(this->_ui->noteBook, initialize));

        return nsx::Logger(wrapper);
    };

    nsx::setDebug(debug_log);
    nsx::setInfo(info_log);
    nsx::setError(error_log);

    //
    _ui->frameFrame->setEnabled(false);
    _ui->intensityFrame->setEnabled(false);

    _ui->selectionMode->addItem(QIcon(":/resources/zoomIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/cutlineIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/horizontalSliceIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/verticalSliceIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/selectionIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/ellipseIcon.png"),"");
    _ui->selectionMode->addItem(QIcon(":/resources/slice3D.png"),"");

    // Vertical splitter between Tree and Inspector Widget
    _ui->splitterVertical->setStretchFactor(0,50);
    _ui->splitterVertical->setStretchFactor(1,50);

    // Horizontal splitter between Tree and DetectorScene
    _ui->splitterHorizontal->setStretchFactor(0,10);
    _ui->splitterHorizontal->setStretchFactor(1,90);

    // signals and slots
    connect(_ui->experimentTree, SIGNAL(plotData(nsx::sptrDataSet)),
            this, SLOT(changeData(nsx::sptrDataSet)));


    connect(_ui->frame,&QScrollBar::valueChanged,[=](const int value){_ui->_dview->getScene()->changeFrame(value);});

    connect(_ui->intensity,SIGNAL(valueChanged(int)),_ui->_dview->getScene(),SLOT(setMaxIntensity(int)));
    connect(_ui->selectionMode,SIGNAL(currentIndexChanged(int)),_ui->_dview->getScene(),SLOT(changeInteractionMode(int)));
    connect(_ui->_dview->getScene(),SIGNAL(updatePlot(PlottableGraphicsItem*)),this,SLOT(updatePlot(PlottableGraphicsItem*)));
    connect(_ui->action_open,SIGNAL(triggered()),_ui->experimentTree,SLOT(createNewExperiment()));

    connect(_ui->experimentTree, SIGNAL(resetScene()),
            _ui->_dview->getScene(), SLOT(resetScene()));

    connect(this, SIGNAL(findSpaceGroup(void)), _ui->experimentTree, SLOT(findSpaceGroup()));
    connect(this, SIGNAL(computeRFactors(void)), _ui->experimentTree, SLOT(computeRFactors()));
    connect(this,SIGNAL(findFriedelPairs(void)), _ui->experimentTree, SLOT(findFriedelPairs()));
    // connect(this, SIGNAL(integrateCalculatedPeaks()), _ui->experimentTree, SLOT(integrateCalculatedPeaks()));
    connect(this, SIGNAL(peakFitDialog()), _ui->experimentTree, SLOT(peakFitDialog()));
    connect(this, SIGNAL(incorporateCalculatedPeaks()), _ui->experimentTree, SLOT(incorporateCalculatedPeaks()));

    connect(_session.get(), SIGNAL(updatePeaks()), _ui->_dview->getScene(), SLOT(updatePeaks()));

    _ui->loggerDockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
    _ui->plotterDockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
    _ui->dockWidget_Property->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);

    _ui->plotterDockWidget->show();
    _ui->dockWidget_Property->show();

    connect(_ui->experimentTree,SIGNAL(inspectWidget(QWidget*)),this,SLOT(setInspectorWidget(QWidget*)));

    _progressHandler = nsx::sptrProgressHandler(new nsx::ProgressHandler());
    _peakFinder = nsx::sptrPeakFinder(new nsx::PeakFinder());

    for (auto&& action: _ui->menuColor_map->actions()) {
        _ui->menuColor_map->removeAction(action);
    }

    auto names = ColorMap::getColorMapNames();

    for (auto&& name: names) {
        QAction* action = new QAction(name.c_str(), _ui->menuColor_map);

        auto slot_fn = [=] () -> void
        {
            const std::string name_str = action->text().toStdString();
            _session->setColorMap(name_str);
            _ui->_dview->getScene()->setColorMap(name_str);
            _ui->_dview->getScene()->redrawImage();
        };

        connect(action, &QAction::triggered, this, slot_fn);
        _ui->menuColor_map->addAction(action);
    }
}

MainWindow::~MainWindow()
{
    qInstallMessageHandler(0);
    delete _ui;
}

void MainWindow::on_actionNew_session_triggered()
{
  nsx::error() << "save session: not implemented yet";
}

void MainWindow::saveSession(QString filename)
{
    Q_UNUSED(filename)

    nsx::error() << "This feature is not currently implemented!";
}

void MainWindow::on_actionSave_session_triggered()
{
    saveSession(_session->getFilename());
}

void MainWindow::on_actionSave_session_as_triggered()
{
    QString homeDir = nsx::homeDirectory().c_str();
    QString filename = QFileDialog::getSaveFileName(this, "Save session as..", homeDir, "Json document (*.json)", nullptr, QFileDialog::Option::DontUseNativeDialog);
    saveSession(filename);
}

void MainWindow::on_actionLoad_session_triggered()
{
    nsx::error() << "This feature is not currently implemented!";
}

void MainWindow::on_actionAbout_triggered()
{
    // Show splash
    QImage splashScrImage(":/resources/splashScreen.png");
    QPixmap Logo;
    Logo.convertFromImage(splashScrImage);
    QSplashScreen* splashScrWindow = new QSplashScreen(this, Logo, Qt::WindowStaysOnTopHint);
    QSize screenSize = QApplication::desktop()->geometry().size();
    splashScrWindow->move(screenSize.width()/2-300,screenSize.height()/2-150);
    splashScrWindow->show();
}

Ui::MainWindow* MainWindow::getUI() const
{
    return _ui;
}


void MainWindow::changeData(nsx::sptrDataSet data)
{
    _ui->frameFrame->setEnabled(true);
    _ui->intensityFrame->setEnabled(true);

    int frameMax = int(data->nFrames()-1);
    int frame = _ui->frame->value();

    if (frame > frameMax) {
        frame = frameMax;
    }
    // why do we do this? why is the signal not working properly?
    _ui->_dview->getScene()->setData(_session, data, frame);

    _ui->frame->setValue(frame);
    _ui->frame->setMaximum(frameMax);
    _ui->spinBox_Frame->setMaximum(frameMax);

    //_ui->intensity->setValue(10);
}

void MainWindow::plotPeak(nsx::sptrPeak3D peak)
{
    auto data = peak->data();
    auto scenePtr = _ui->_dview->getScene();
    // Ensure that frames
    changeData(data);
    // Get frame number to adjust the data
    size_t data_frame = size_t(std::lround(peak->getShape().aabb().center()[2]));
    scenePtr->setData(_session, data, data_frame);
    // Update the scrollbar
    _ui->frame->setValue(data_frame);
    auto pgi = scenePtr->findPeakGraphicsItem(peak);

    if (pgi) {
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

void MainWindow::on_actionProperty_triggered()
{
    if (_ui->dockWidget_Property->isHidden())
        _ui->dockWidget_Property->show();
    else
        _ui->dockWidget_Property->hide();
}

void MainWindow::plotData(const QVector<double>& x,const QVector<double>& y,const QVector<double>& e)
{
    if (_ui->plot1D->getType().compare("simple") != 0) {
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

    if (!item->isPlottable(_ui->plot1D)) {
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

    if (PeakListPropertyWidget* widget=dynamic_cast<PeakListPropertyWidget*>(w)) {
        // Ensure plot1D is updated
        connect(widget->getPeakTableView(),SIGNAL(plotPeak(nsx::sptrPeak3D)),this,SLOT(plotPeak(nsx::sptrPeak3D)));
        connect(widget->getPeakTableView(),
                SIGNAL(plotData(const QVector<double>&,const QVector<double>&,const QVector<double>&)),
                this,
                SLOT(plotData(const QVector<double>&,const QVector<double>&,const QVector<double>&)));

        CollectedPeaksModel* peakModel = dynamic_cast<CollectedPeaksModel*>(widget->getPeakTableView()->model());
        connect(peakModel,SIGNAL(unitCellUpdated()),_ui->_dview->getScene(),SLOT(updatePeaks()));
    }
}

void MainWindow::on_actionConvert_to_HDF5_triggered()
{
    NumorsConversionDialog* dlg=new NumorsConversionDialog();
    dlg->exec();
}

void MainWindow::on_checkBox_AspectRatio_toggled(bool checked)
{
    _ui->_dview->fixDetectorAspectRatio(checked);
}

void MainWindow::on_actionFind_space_group_triggered()
{
    emit findSpaceGroup();
}

void MainWindow::on_actionFind_Friedel_pairs_triggered()
{
    emit findFriedelPairs();
}


void MainWindow::on_actionCompute_R_factors_triggered()
{
    emit computeRFactors();
    // emit findFriedelPairs();
}

void MainWindow::on_actionIntegrate_calculated_peaks_triggered()
{
}

void MainWindow::on_actionPeak_fit_dialog_triggered()
{
    emit peakFitDialog();
}

void MainWindow::on_actionLogarithmic_Scale_triggered(bool checked)
{
    _ui->_dview->getScene()->setLogarithmic(checked);
}

void MainWindow::on_actionDraw_peak_integration_area_triggered(bool checked)
{
    _ui->_dview->getScene()->drawIntegrationRegion(checked);
}

void MainWindow::on_actionRemove_bad_peaks_triggered(bool checked)
{
    Q_UNUSED(checked)

    DialogPeakFilter* dlg = new DialogPeakFilter(_session->peaks(nullptr), this);
    if (dlg->exec()) {
        auto&& bad_peaks = dlg->badPeaks();
        for (auto peak: bad_peaks) {
            _session->removePeak(peak);
        }
        _session->updatePeaks();
    }    
}

void MainWindow::on_actionIncorporate_calculated_peaks_triggered(bool checked)
{
    Q_UNUSED(checked)
    emit incorporateCalculatedPeaks();
}

void MainWindow::on_actionApply_resolution_cutoff_triggered()
{
    ResolutionCutoffDialog dialog;

    if (!dialog.exec())
        return;

    _session->applyResolutionCutoff(dialog.dMin(), dialog.dMax());
}

void MainWindow::on_actionWrite_log_file_triggered()
{
    _session->writeLog();
}

void MainWindow::on_actionReintegrate_peaks_triggered()
{
    // TODO: weak peaks vs. strong peaks??

    nsx::info() << "Reintegrating peaks...";

    auto dialog = new DialogIntegrate();

    if (!dialog->exec()) {
        nsx::info() << "Peak integration canceled.";
        return;
    }

    const double peak_scale = dialog->peakScale();
    const double bkg_scale = dialog->backgroundScale();
    const double dmin = dialog->dMin();
    const double dmax = dialog->dMax();

    nsx::DataList numors = _session->getSelectedNumors();

    for (auto&& numor: numors) {
        // todo: bkg_begin and bkg_end
        auto&& peaks = nsx::PeakFilter().dRange(_session->peaks(numor.get()), dmin, dmax, true);
        nsx::info() << "Integrating " << peaks.size() << " peaks";
        nsx::WeakPeakIntegrator integrator;
        // todo: progress handler!!
        integrator.integrate(peaks, numor, peak_scale, 0.5*(peak_scale+bkg_scale), bkg_scale); //, _progressHandler);
    }

    _session->updatePeaks();
    nsx::info() << "Done reintegrating peaks";
}

void MainWindow::on_actionFit_peak_profiles_triggered()
{
    _session->peakFitDialog();
}

void MainWindow::on_actionAuto_assign_unit_cell_triggered()
{
    _session->autoAssignUnitCell();
}

void MainWindow::on_actionFit_profiles_triggered()
{
    nsx::info() << "This functionality is currently disabled in the GUI!";
    #if 0
    nsx::info() << "fit profiles triggered";


    auto numors = _session->getSelectedNumors();

    for (auto d: numors) {

        auto peaks = _session->peaks(nullptr);
        auto num_peaks = peaks.size();
        auto current_peak = 0;

        std::vector<Eigen::MatrixXd> frames;
        frames.reserve(d->nFrames());

        for (size_t f = 0; f < d->nFrames(); ++f) {
            frames.emplace_back(d->frame(f).cast<double>());
        }

        nsx::PeakList peak_list;

        for (auto peak: peaks) {

            ++current_peak;

            if (peak->data() != d) {
                continue;
            }

            double done = double(current_peak) * 100.0 / double(num_peaks);
            if (current_peak%200 == 0) {
                nsx::info() << "done: " << done;
                QApplication::processEvents();
            }

            auto bb = peak->getShape().aabb();
            auto lower = bb.lower();
            auto upper = bb.upper();

            int fmin = std::max(0, int(lower[2]));
            int fmax = std::min(int(peak->data()->nFrames())-1, int(upper[2]));

            int xmin = std::max(0, int(lower[0]));
            int ymin = std::max(0, int(lower[1]));

            int xmax = std::min(int(d->nCols())-1, int(upper[0]));
            int ymax = std::min(int(d->nRows())-1, int(upper[1]));

            int npoints = (fmax-fmin)*(xmax-xmin)*(ymax-ymin);
            int point = 0;

            if (npoints <= 0) {
                peak->setSelected(false);
                continue;
            }

            Eigen::ArrayXd x, y, z, I;
            x.setZero(npoints);
            y.setZero(npoints);
            z.setZero(npoints);
            I.setZero(npoints);

            // hard cutoff
            if (npoints > 50000) {
                peak->setSelected(false);
                continue;
            }

            for (int f = fmin; f < fmax; ++f) {
                for (int j = xmin; j < xmax; ++j) {
                    for (int i = ymin; i < ymax; ++i) {

                        if (region.classifySlice({double(j), double(i), double(f)}) < 0) {
                            continue;
                        }

                        x(point) = j;
                        y(point) = i;
                        z(point) = f;
                        I(point) = frames[f](i, j);
                        ++point;
                    }
                }
            }

            // too few points to get a fit
            if (point < 20) {
                peak->setSelected(false);
                continue;
            }

            nsx::Profile3d prof(x.head(point), y.head(point), z.head(point), I.head(point));
            nsx::Profile3d fit = prof.fit(x.head(point), y.head(point), z.head(point), I.head(point), 50);

            if (!fit.success() || fit.pearson() < 0.5) {
                peak->setSelected(false);
                continue;
            }

            Eigen::Matrix3d D;
            D << prof._Dxx, prof._Dxy, prof._Dxz,
                prof._Dxy, prof._Dyy, prof._Dyz,
                prof._Dxz, prof._Dyz, prof._Dzz;

            peak->setShape(nsx::Ellipsoid(prof._c, D));
            peak_list.push_back(peak);
        }
        // todo: change bkg_begin and bkg_end
        d->integratePeaks(peak_list, 3.0, 6.0, nullptr);
    }

    _session->updatePeaks();
    #endif 
}
