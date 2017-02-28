#include "ui_MainWindow.h"
#include "dialogs/DialogConvolve.h"
#include <nsxlib/utils/ProgressHandler.h>
#include "views/ProgressView.h"

#include <memory>
#include <stdexcept>
#include <utility>
#include <map>
#include <array>
#include <tuple>
#include <vector>

#include <QAbstractItemView>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QKeyEvent>
#include <QList>
#include <QListIterator>
#include <QMenu>
#include <QModelIndexList>
#include <QStandardItem>
#include <QString>
#include <QtDebug>

#include <nsxlib/data/DataReaderFactory.h>
#include <nsxlib/instrument/Detector.h>
#include "dialogs/DialogExperiment.h"
#include <nsxlib/instrument/Diffractometer.h>
#include <nsxlib/instrument/Sample.h>
#include <nsxlib/instrument/Source.h>

#include "views/PeakTableView.h"
#include "absorption/AbsorptionDialog.h"
#include "models/DataItem.h"
#include "models/DetectorItem.h"
#include "models/ExperimentItem.h"
#include "tree/ExperimentTree.h"
#include "models/TreeItem.h"
#include "models/InstrumentItem.h"
#include "models/NumorItem.h"
#include "models/PeakListItem.h"
#include "models/SampleItem.h"
#include "models/SourceItem.h"
#include "models/UnitCellItem.h"
#include "absorption/MCAbsorptionDialog.h"
#include "OpenGL/GLWidget.h"
#include "OpenGL/GLSphere.h"
#include "Logger.h"
#include "views/ReciprocalSpaceViewer.h"
#include "DetectorScene.h"
#include "dialogs/DialogTransformationMatrix.h"

#include "dialogs/DialogRawData.h"
#include "dialogs/DialogAutoIndexing.h"

#include <nsxlib/crystal/SpaceGroupSymbols.h>
#include <nsxlib/crystal/SpaceGroup.h>

#include "dialogs/SpaceGroupDialog.h"

#include <QVector>
#include "Externals/qcustomplot.h"
#include "ui_ScaleDialog.h"

#include "dialogs/ScaleDialog.h"
#include "dialogs/FriedelDialog.h"

#include <nsxlib/crystal/RFactor.h>
#include <hdf5.h>
#include <H5Exception.h>

#include "dialogs/PeakFitDialog.h"
#include "models/SessionModel.h"

#include "models/DataItem.h"


using std::vector;
using SX::Data::IData;
using std::shared_ptr;
using SX::Utils::ProgressHandler;

ExperimentTree::ExperimentTree(QWidget *parent):
    QTreeView(parent)//,
    //_session(nullptr)
{
    setContextMenuPolicy(Qt::CustomContextMenu);

    //_session=new QStandardItemModel(this);
    //setModel(_session);
    expandAll();
    setSelectionMode(QAbstractItemView::ContiguousSelection);
    update();

    setExpandsOnDoubleClick(false);

    connect(this,SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(onCustomMenuRequested(const QPoint&)));
    connect(this,SIGNAL(doubleClicked(const QModelIndex&)),this,SLOT(onDoubleClick(const QModelIndex&)));
    connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(onSingleClick(QModelIndex)));
}

ExperimentTree::~ExperimentTree()
{
    // _session should be deleted automatically during destructor by QT
    //delete _session;
}

void ExperimentTree::setSession(std::shared_ptr<SessionModel> session)
{
    _session = session;
    setModel(_session.get());
}

void ExperimentTree::setHKLTolerance()
{
    QStandardItem* item=_session->itemFromIndex(currentIndex());
    auto ucitem=dynamic_cast<UnitCellItem*>(item);
    if (!ucitem)
        return;

    bool ok;
    double tolerance = QInputDialog::getDouble(this,tr("HKL integer tolerance"),tr("value:"),ucitem->getUnitCell()->getHKLTolerance(),0.0,1.0,2,&ok);
    if (!ok)
        return;

    ucitem->getUnitCell()->setHKLTolerance(tolerance);

    onSingleClick(currentIndex());
}

void ExperimentTree::createNewExperiment()
{
    std::unique_ptr<DialogExperiment> dlg;

    // DialogExperiment could throw an exception if it fails to read the resource files
    try {
        dlg = std::unique_ptr<DialogExperiment>(new DialogExperiment());

        // The user pressed cancel, return
        if (!dlg->exec())
            return;

        // If no experiment name is provided, pop up a warning
        if (dlg->getExperimentName().isEmpty()) {
            qWarning() << "Empty experiment name";
            return;
        }
    }
    catch(std::exception& e) {
        qDebug() << "Runtime error: " << e.what();
        return;
    }

    // Add the experiment
    try {
        _session->addExperiment(dlg->getExperimentName().toStdString(),dlg->getInstrumentName().toStdString());
    }
    catch(const std::runtime_error& e) {
        qWarning() << e.what();
        return;
    }
}

void ExperimentTree::onCustomMenuRequested(const QPoint& point)
{
    QModelIndex index = indexAt(point);

    if (index == rootIndex()) {
        QMenu* menu = new QMenu(this);
        QAction* newexp = menu->addAction("Add new experiment");
        menu->popup(viewport()->mapToGlobal(point));
        connect(newexp, SIGNAL(triggered()), this, SLOT(createNewExperiment()));
    }
    else {
        QStandardItem* item = _session->itemFromIndex(index);
        if (dynamic_cast<DataItem*>(item))
        {
            QMenu* menu = new QMenu(this);
            QAction* import = menu->addAction("Import data");
            QAction* rawImport = menu->addAction("Import raw data...");
            QAction* findpeaks = menu->addAction("Peak finder");
            QAction* rviewer = menu->addAction("Reciprocal space viewer");
            menu->popup(viewport()->mapToGlobal(point));
            connect(import, SIGNAL(triggered()), this, SLOT(importData()));
            connect(rawImport, SIGNAL(triggered()), this, SLOT(importRawData()));
            connect(findpeaks, &QAction::triggered, [=](){findPeaks(index);});
            connect(rviewer, &QAction::triggered, [=](){viewReciprocalSpace(index);});
        }
        else if (dynamic_cast<PeakListItem*>(item))
        {
            QMenu* menu = new QMenu(this);
            QAction* abs = menu->addAction("Correct for Absorption");
            QAction* scene3d = menu->addAction("Show 3D view");
            menu->popup(viewport()->mapToGlobal(point));
            // Call the slot
            connect(abs, SIGNAL(triggered()), this, SLOT(absorptionCorrection()));
            connect(scene3d, SIGNAL(triggered()), this, SLOT(showPeaksOpenGL()));
        }
        else if (SampleItem* sitem=dynamic_cast<SampleItem*>(item))
        {
            QMenu* menu = new QMenu(this);
            QAction* addUnitCell = menu->addAction("Add unit cell");
            menu->popup(viewport()->mapToGlobal(point));

            auto addUnitCellLambda = [=] {sitem->addUnitCell();};
            connect(addUnitCell, &QAction::triggered, this, addUnitCellLambda);

        }
        else if (UnitCellItem* ucitem=dynamic_cast<UnitCellItem*>(item))
        {
            QMenu* menu = new QMenu(this);
            QAction* info = menu->addAction("Info");
            menu->addSeparator();
            QAction* setTolerance = menu->addAction("Set HKL tolerance");
            menu->addSeparator();
            QAction* cellParameters=menu->addAction("Change unit cell parameters");
            QAction* transformationMatrix=menu->addAction("Transformation matrix");
            menu->popup(viewport()->mapToGlobal(point));

            auto infoLambda = [=]{ucitem->info();};
            connect(info, &QAction::triggered, this, infoLambda);

            auto cellParametersLambda = [=]{ucitem->openChangeUnitCellDialog();};
            connect(cellParameters, &QAction::triggered, this, cellParametersLambda);

            auto transformationMatrixLambda = [=]{ucitem->openTransformationMatrixDialog();};
            connect(transformationMatrix, &QAction::triggered, this, transformationMatrixLambda);

            connect(setTolerance, SIGNAL(triggered()),this, SLOT(setHKLTolerance()));

        }
        else if (NumorItem* nitem = dynamic_cast<NumorItem*>(item))
            {
            QMenu* menu = new QMenu(this);
            QAction* export_hdf = menu->addAction("Export to HDF5...");
            menu->popup(viewport()->mapToGlobal(point));

            auto export_fn = [=] {
                QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "HDF5 (*.hdf *.hdf5)", nullptr, QFileDialog::Option::DontUseNativeDialog);
                nitem->exportHDF5(filename.toStdString());
            };

            connect(export_hdf, &QAction::triggered, this, export_fn);
        }
    }
}

void ExperimentTree::absorptionCorrection()
{
    // Get the current item and check that is actually a Data item. Otherwise, return.
    QStandardItem* item=_session->itemFromIndex(currentIndex());
    auto pitem=dynamic_cast<PeakListItem*>(item);
    if (!pitem)
        return;
    MCAbsorptionDialog* dialog = new MCAbsorptionDialog(pitem->getExperiment(), this);
    dialog->open();
}

void ExperimentTree::importData()
{
    // Get the current item and check that is actually a Data item. Otherwise, return.
    DataItem* dataItem = dynamic_cast<DataItem*>(_session->itemFromIndex(currentIndex()));
    if (!dataItem)
        return;

    QStringList fileNames;
    fileNames = QFileDialog::getOpenFileNames(this,"select numors","","",nullptr,QFileDialog::Option::DontUseNativeDialog);

    // No files selected, do nothing
    if (fileNames.isEmpty())
        return;

    // QModelIndex parentIndex = _session->parent(currentIndex());
    // auto expItem = dynamic_cast<ExperimentItem*>(_session->itemFromIndex(parentIndex));

    for (int i = 0; i < fileNames.size(); ++i) {
        dataItem->importData(fileNames[i].toStdString());
    }
}

void ExperimentTree::importRawData()
{
    // Get the current item and check that is actually a Data item. Otherwise, return.
    DataItem* dataItem = dynamic_cast<DataItem*>(_session->itemFromIndex(currentIndex()));

    if (!dataItem)
        return;

    std::shared_ptr<SX::Instrument::Experiment> exmt = dataItem->getExperiment();

    if (!exmt)
        return;

//    QStringList files = QFileDialog::getOpenFileNames(
//                            //this,
//                            nullptr,
//                            "Select one or more files to open",
//                            ".",
//                            "Raw data (*)");

    QStringList files;
    files = QFileDialog::getOpenFileNames(this,"import raw data","","",nullptr,QFileDialog::Option::DontUseNativeDialog);


    files.sort();

    if (files.isEmpty())
        return;

    DialogRawData dialog(this);
    //dialog.setWavelength(exmt->getDiffractometer()->getSource()->getWavelength());

    if (!dialog.exec())
        return;

    const double wavelength = dialog.wavelength();
    const double delta_phi = dialog.deltaPhi();
    const double delta_omega = dialog.deltaOmega();
    const double delta_chi = dialog.deltaChi();
    const bool swap_endian = dialog.swapEndian();
    const int bpp = dialog.bpp();
    const bool row_major = dialog.rowMajor();

    std::vector<std::string> filenames;

    for (auto&& file: files)
        filenames.push_back(file.toStdString());

    dataItem->importRawData(filenames, wavelength, delta_chi, delta_omega, delta_phi, row_major, swap_endian, bpp);
}



void ExperimentTree::findPeaks(const QModelIndex& index)
{
    _session->findPeaks(index);
}

void ExperimentTree::viewReciprocalSpace(const QModelIndex& index)
{
    QStandardItem* item=_session->itemFromIndex(index);

    TreeItem* titem=dynamic_cast<TreeItem*>(item);
    if (!titem)
        return;

    std::shared_ptr<SX::Instrument::Experiment> expt(titem->getExperiment());

    if (!expt)
        return;

    QStandardItem* ditem=_session->itemFromIndex(index);

    std::vector<std::shared_ptr<SX::Data::IData>> selectedNumors;
    int nTotalNumors(_session->rowCount(ditem->index()));
    selectedNumors.reserve(size_t(nTotalNumors));

    for (auto i = 0; i < nTotalNumors; ++i) {
        if (ditem->child(i)->checkState() == Qt::Checked) {
            if (auto ptr = dynamic_cast<NumorItem*>(ditem->child(i)))
                selectedNumors.push_back(ptr->getExperiment()->getData(ptr->text().toStdString()));
        }
    }

    if (selectedNumors.empty()) {
        qWarning() << "No numor selected for reciprocal viewer";
        return;
    }

    try {
        ReciprocalSpaceViewer* dialog = new ReciprocalSpaceViewer(expt);
        dialog->setData(selectedNumors);
        if (!dialog->exec())
            return;
    } catch(std::exception& e) {
        qWarning()<<e.what();
        return;
    }
}

void ExperimentTree::onDoubleClick(const QModelIndex& index)
{
    // Get the current item and check that is actually a Numor item. Otherwise, return.
    QStandardItem* item=_session->itemFromIndex(index);
    if (auto ptr=dynamic_cast<DataItem*>(item)) {
        if (ptr->model()->rowCount(ptr->index())==0)
            importData();
        else {
            for (auto i=0;i<ptr->model()->rowCount(ptr->index());++i) {
                if (ptr->child(i)->checkState() == Qt::Unchecked)
                    ptr->child(i)->setCheckState(Qt::Checked);
                else
                    ptr->child(i)->setCheckState(Qt::Unchecked);
            }
        }
    }
    else if (auto ptr=dynamic_cast<SampleItem*>(item))
        ptr->addUnitCell();
    else if (auto ptr=dynamic_cast<NumorItem*>(item)) {
        std::shared_ptr<SX::Instrument::Experiment> exp = ptr->getExperiment();
        emit plotData(exp->getData(item->text().toStdString()));
    }
}

void ExperimentTree::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete) {
        QList<QModelIndex> selIndexes = selectedIndexes();

        QListIterator<QModelIndex> it(selIndexes);
        it.toBack();
        while (it.hasPrevious()) {
            QStandardItem* item = _session->itemFromIndex(it.previous());
            if (!item->parent())
                 _session->removeRow(item->row());
            else
                _session->removeRow(item->row(),item->parent()->index());
        }
    }
}


void ExperimentTree::onSingleClick(const QModelIndex &index)
{
    // Inspect this item if it is inspectable
    InspectableTreeItem* item = dynamic_cast<InspectableTreeItem*>(_session->itemFromIndex(index));
    if (item)
        emit inspectWidget(item->inspectItem());
    else {
        QWidget* widget=new QWidget();
        emit inspectWidget(widget);
    }
}

void ExperimentTree::showPeaksOpenGL()
{
    GLWidget* glw = new GLWidget();
    auto& scene = glw->getScene();
    auto datav = _session->getSelectedNumors();

    for (auto idata : datav) {
       auto peaks=idata->getPeaks();
       for (auto peak: peaks) {
           GLSphere* sphere=new GLSphere("");
           Eigen::Vector3d pos=peak->getQ();
           sphere->setPos(pos[0]*100,pos[1]*100,pos[2]*100);
           sphere->setColor(0,1,0);
           scene.addActor(sphere);
       }
    }
    glw->show();
}

void ExperimentTree::findSpaceGroup()
{
    SpaceGroupDialog* dialog = new SpaceGroupDialog(_session->getSelectedNumors(), this);
    dialog->exec();
    // update the space group elsewhere
}

void ExperimentTree::computeRFactors()
{
    _session->computeRFactors();

//    qDebug() << "Finding peak equivalences...";

//    std::vector<std::shared_ptr<IData>> numors = _session->getSelectedNumors();
//    std::vector<std::vector<Peak3D*>> peak_equivs;
//    std::vector<Peak3D*> peak_list;

//    std::shared_ptr<UnitCell> unit_cell;

//    for (std::shared_ptr<IData> numor: numors) {
//        std::set<Peak3D*> peaks = numor->getPeaks();
//        for (Peak3D* peak: peaks)
//            if ( peak && peak->isSelected() && !peak->isMasked() )
//                peak_list.push_back(peak);
//    }

//    if ( peak_list.size() == 0) {
//        qDebug() << "No peaks -- cannot search for equivalences!";
//        return;
//    }

//    for (Peak3D* peak: peak_list) {
//        // what do we do if there is more than one sample/unit cell??
//        unit_cell = peak->getUnitCell();

//        if (unit_cell)
//            break;
//    }

//    if (!unit_cell) {
//        qDebug() << "No unit cell selected! Cannot compute R factors.";
//        return;
//    }

//    SpaceGroup grp("P 1");

//    // spacegroup construct can throw
//    try {
//        grp = SpaceGroup(unit_cell->getSpaceGroup());
//    }
//    catch(std::exception& e) {
//        qDebug() << "Caught exception: " << e.what() << endl;
//        return;
//    }

//    peak_equivs = grp.findEquivalences(peak_list, true);

//    qDebug() << "Found " << peak_equivs.size() << " equivalence classes of peaks:";

//    std::map<int, int> size_counts;

//    for (auto& peaks: peak_equivs) {
//        ++size_counts[peaks.size()];
//    }

//    for (auto& it: size_counts) {
//        qDebug() << "Found " << it.second << " classes of size " << it.first;
//    }

//    qDebug() << "Computing R factors:";

//    RFactor rfactor(peak_equivs);

//    qDebug() << "    Rmerge = " << rfactor.Rmerge();
//    qDebug() << "    Rmeas  = " << rfactor.Rmeas();
//    qDebug() << "    Rpim   = " << rfactor.Rpim();

    // WIP: disabled for now
    // ScaleDialog* scaleDialog = new ScaleDialog(peak_equivs, this);
    // scaleDialog->exec();
}

void ExperimentTree::findFriedelPairs()
{
    qDebug() << "findFriedelParis() is not yet implemented!";
    return;

//    std::vector<Peak3D*> peaks;
//    std::vector<std::shared_ptr<IData>> numors = getSelectedNumors();

//    for (std::shared_ptr<IData> numor: numors) {
//        std::set<Peak3D*> peak_list = numor->getPeaks();

//        for (Peak3D* peak: peak_list)
//            peaks.push_back(peak);
//    }



    // todo: something with FriedelDialog!
    //FriedelDialog* friedelDialog = new FriedelDialog(peaks, this);
    //friedelDialog->exec();
    //delete friedelDialog;
}

//void ExperimentTree::integrateCalculatedPeaks()
//{
//    qDebug() << "Integrating calculated peaks...";

//    int count = 0;
//    Eigen::Vector3d peak_extent, bg_extent;
//    peak_extent << 0.0, 0.0, 0.0;
//    bg_extent << 0.0, 0.0, 0.0;

//    std::shared_ptr<UnitCell> unit_cell;

//    for (std::shared_ptr<IData> numor: _session->getSelectedNumors())
//    {
//        for (sptrPeak3D peak: numor->getPeaks())
//            if ( peak && peak->isSelected() && !peak->isMasked() )
//            {
//                peak_extent += peak->getPeak()->getAABBExtents();
//                bg_extent += peak->getBackground()->getAABBExtents();
//                ++count;
//            }
//    }

//    if ( count == 0) {
//        qDebug() << "No peaks -- cannot search for equivalences!";
//        return;
//    }

//    peak_extent /= count;
//    bg_extent /= count;

//    qDebug() << "Done calculating average bounding box";

//    qDebug() << peak_extent(0) << " " << peak_extent(1) << " " << peak_extent(2);
//    qDebug() << bg_extent(0) << " " << bg_extent(1) << " " << bg_extent(2);

//    for (std::shared_ptr<IData> numor: _session->getSelectedNumors()) {

//        std::vector<sptrPeak3D> calculated_peaks;

//        shared_ptr<Sample> sample = numor->getDiffractometer()->getSample();
//        int ncrystals = sample->getNCrystals();

//        if (ncrystals) {
//            for (int i = 0; i < ncrystals; ++i) {
//                SX::Crystal::SpaceGroup group(sample->getUnitCell(i)->getSpaceGroup());
//                auto ub = sample->getUnitCell(i)->getReciprocalStandardM();

//                qDebug() << "Calculating peak locations...";

//                auto hkls = sample->getUnitCell(i)->generateReflectionsInSphere(1.5);
//                std::vector<SX::Crystal::PeakCalc> peaks = numor->hasPeaks(hkls, ub);
//                calculated_peaks.reserve(calculated_peaks.size() + peaks.size());

//                qDebug() << "Adding calculated peaks...";

//                //for(auto&& p: peaks) {
//                    //calculated_peaks.push_back(p);
//                //}
//            }
//        }

//        qDebug() << "Done.";
//    }
//}

void ExperimentTree::peakFitDialog()
{
    _session->peakFitDialog();
}

void ExperimentTree::incorporateCalculatedPeaks()
{
    _session->incorporateCalculatedPeaks();
}