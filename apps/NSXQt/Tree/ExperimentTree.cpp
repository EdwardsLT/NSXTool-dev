#include "ui_MainWindow.h"
#include "DialogConvolve.h"
#include "ProgressHandler.h"
#include "ProgressView.h"

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

//#include "BlobFinder.h"
#include "DataReaderFactory.h"
#include "Detector.h"
#include "DialogExperiment.h"
#include "Diffractometer.h"
#include "Sample.h"
#include "Source.h"

#include "PeakTableView.h"
#include "AbsorptionDialog.h"
#include "Tree/DataItem.h"
#include "Tree/DetectorItem.h"
#include "Tree/ExperimentItem.h"
#include "Tree/ExperimentTree.h"
#include "Tree/TreeItem.h"
#include "Tree/InstrumentItem.h"
#include "Tree/NumorItem.h"
#include "Tree/PeakListItem.h"
#include "Tree/SampleItem.h"
#include "Tree/SourceItem.h"
#include "MCAbsorptionDialog.h"
#include "OpenGL/GLWidget.h"
#include "OpenGL/GLSphere.h"
#include "Logger.h"
#include "ReciprocalSpaceViewer.h"
#include "DetectorScene.h"

#include "SpaceGroupSymbols.h"
#include "SpaceGroup.h"

#include "SpaceGroupDialog.h"

#include <QVector>
#include "Externals/qcustomplot.h"
#include "ui_ScaleDialog.h"

#include "ScaleDialog.h"
#include "FriedelDialog.h"

#include "RFactor.h"
#include <hdf5.h>
#include <H5Exception.h>

#include "PeakFitDialog.h"

#include "SessionModel.h"

#include "DataItem.h"


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

void ExperimentTree::createNewExperiment()
{
    DialogExperiment* dlg;

    // DialogExperiment could throw an exception if it fails to read the resource files
    try {
        dlg = new DialogExperiment();

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
        addExperiment(dlg->getExperimentName().toStdString(),dlg->getInstrumentName().toStdString());
    }
    catch(const std::runtime_error& e) {
        qWarning() << e.what();
        return;
    }
}

void ExperimentTree::addExperiment(const std::string& experimentName, const std::string& instrumentName)
{
    assert(_session != nullptr);

    // Create an experiment
    std::shared_ptr<SX::Instrument::Experiment> expPtr = _session->addExperiment(experimentName,instrumentName);

//    // Create an instrument item
//    InstrumentItem* instr = new InstrumentItem(expPtr);

//    // Create a detector item and add it to the instrument item
//    DetectorItem* detector = new DetectorItem(expPtr);
//    instr->appendRow(detector);

//    // Create a sample item and add it to the instrument item
//    SampleItem* sample = new SampleItem(expPtr);
//    instr->appendRow(sample);

//    // Create a source item and add it to the instrument leaf
//    SourceItem* source = new SourceItem(expPtr);
//    instr->appendRow(source);

//    // Create an experiment item
//    ExperimentItem* expt = new ExperimentItem(expPtr);

//    // Add the instrument item to the experiment item
//    expt->appendRow(instr);

//    // Create a data item and add it to the experiment item
//    DataItem* data = new DataItem(expPtr);
//    expt->appendRow(data);

//    // Create a peaks item and add it to the experiment item
//    PeakListItem* peaks = new PeakListItem(expPtr);
//    expt->appendRow(peaks);

//    // Add the experiment item to the root of the experiment tree
//    _session->appendRow(expt);

    update();

}

vector<shared_ptr<IData>> ExperimentTree::getSelectedNumors(ExperimentItem* item) const
{
//    vector<shared_ptr<IData>> numors;

//    QList<QStandardItem*> dataItems = _session->findItems(QString("Data"),Qt::MatchCaseSensitive|Qt::MatchRecursive);

//    for (const auto& it : dataItems)
//    {
//        for (auto i=0;i<_session->rowCount(it->index());++i)
//        {
//            if (it->child(i)->checkState() == Qt::Checked)
//            {
//                if (auto ptr = dynamic_cast<NumorItem*>(it->child(i)))
//                {
//                    if (it->parent() == item)
//                        numors.push_back(ptr->getExperiment()->getData(ptr->text().toStdString()));
//                }
//            }
//        }
//    }

//    return numors;
    return _session->getSelectedNumors(item);
}

vector<shared_ptr<IData>> ExperimentTree::getSelectedNumors() const
{
//    vector<shared_ptr<IData>> numors;

//    QList<QStandardItem*> dataItems = _session->findItems(QString("Data"),Qt::MatchCaseSensitive|Qt::MatchRecursive);

//    for (const auto& it : dataItems)
//    {
//        for (auto i=0;i<_session->rowCount(it->index());++i)
//        {
//            if (it->child(i)->checkState() == Qt::Checked)
//            {
//                if (auto ptr = dynamic_cast<NumorItem*>(it->child(i)))
//                    numors.push_back(ptr->getExperiment()->getData(ptr->text().toStdString()));
//            }
//        }
//    }

//    return numors;
    return _session->getSelectedNumors();
}

void ExperimentTree::onCustomMenuRequested(const QPoint& point)
{
    QModelIndex index = indexAt(point);

    if (index == rootIndex())
    {
        QMenu* menu = new QMenu(this);
        QAction* newexp=menu->addAction("Add new experiment");
        menu->popup(viewport()->mapToGlobal(point));
        connect(newexp,SIGNAL(triggered()),this,SLOT(createNewExperiment()));

    }
    else
    {
        QStandardItem* item=_session->itemFromIndex(index);
        if (dynamic_cast<DataItem*>(item))
        {
            QMenu* menu = new QMenu(this);
            QAction* import=menu->addAction("Import");
            QAction* findpeaks=menu->addAction("Peak finder");
            QAction* rviewer=menu->addAction("Reciprocal space viewer");
            menu->popup(viewport()->mapToGlobal(point));
            connect(import,SIGNAL(triggered()),this,SLOT(importData()));
            connect(findpeaks,&QAction::triggered,[=](){findPeaks(index);});
            connect(rviewer,&QAction::triggered,[=](){viewReciprocalSpace(index);});
        }
        else if (dynamic_cast<PeakListItem*>(item))
        {
            QMenu* menu = new QMenu(this);
            QAction* abs=menu->addAction("Correct for Absorption"); // Absorption menu
            QAction* scene3d=menu->addAction("Show 3D view"); // Peak in 3D OpenGL window
            menu->popup(viewport()->mapToGlobal(point));
            // Call the slot
            connect(abs,SIGNAL(triggered()),this,SLOT(absorptionCorrection()));
            connect(scene3d,SIGNAL(triggered()),this,SLOT(showPeaksOpenGL()));
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
    fileNames= QFileDialog::getOpenFileNames(this,"select numors","","",nullptr,QFileDialog::Option::DontUseNativeDialog);

    // No files selected, do nothing
    if (fileNames.isEmpty())
        return;



    QModelIndex parentIndex = _session->parent(currentIndex());
    auto expItem=dynamic_cast<ExperimentItem*>(_session->itemFromIndex(parentIndex));

    for (int i=0;i<fileNames.size();++i)
    {
        dataItem->importData(fileNames[i].toStdString());

//        // Get the basename of the current numor
//        QFileInfo fileinfo(fileNames[i]);
//        std::string basename=fileinfo.fileName().toStdString();
//         std::shared_ptr<SX::Instrument::Experiment> exp = expItem->getExperiment();

//        // If the experience already stores the current numor, skip it
//        if (exp->hasData(basename))
//            continue;

//        std::shared_ptr<IData> data_ptr;

//        try
//        {
//            std::string extension=fileinfo.completeSuffix().toStdString();

//            IData* raw_ptr = DataReaderFactory::Instance()->create(
//                        extension,fileNames[i].toStdString(),exp->getDiffractometer()
//                        );

//            data_ptr = std::shared_ptr<IData>(raw_ptr);

//            exp->addData(data_ptr);
//        }
//        catch(std::exception& e)
//        {
//           qWarning() << "Error reading numor: " + fileNames[i] + " " + QString(e.what());
//           continue;
//        }
//        catch(...)
//        {
//        	qWarning() << "Error reading numor: " + fileNames[i] + " reason not known:";
//        	continue;
//        }
//        QStandardItem* item = new NumorItem(exp, data_ptr);
//        item->setText(QString::fromStdString(basename));
//        item->setCheckable(true);
//        dataItem->appendRow(item);

    }
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
    selectedNumors.reserve(nTotalNumors);

    for (auto i=0;i<nTotalNumors;++i)
    {
        if (ditem->child(i)->checkState() == Qt::Checked)
        {
            if (auto ptr = dynamic_cast<NumorItem*>(ditem->child(i)))
                selectedNumors.push_back(ptr->getExperiment()->getData(ptr->text().toStdString()));
        }
    }

    if (selectedNumors.empty())
    {
        qWarning()<<"No numor selected for reciprocal viewer";
        return;
    }

    try
    {
        ReciprocalSpaceViewer* dialog = new ReciprocalSpaceViewer(expt);
        dialog->setData(selectedNumors);
        if (!dialog->exec())
            return;
    }
    catch(std::exception& e)
    {
        qWarning()<<e.what();
        return;
    }
}

void ExperimentTree::onDoubleClick(const QModelIndex& index)
{
    // Get the current item and check that is actually a Numor item. Otherwise, return.
    QStandardItem* item=_session->itemFromIndex(index);

    if (auto ptr=dynamic_cast<DataItem*>(item))
    {
        if (ptr->model()->rowCount(ptr->index())==0)
            importData();
        else
        {
            for (auto i=0;i<ptr->model()->rowCount(ptr->index());++i)
            {
                if (ptr->child(i)->checkState() == Qt::Unchecked)
                    ptr->child(i)->setCheckState(Qt::Checked);
                else
                    ptr->child(i)->setCheckState(Qt::Unchecked);
            }
        }
    }
    else if (auto ptr=dynamic_cast<NumorItem*>(item))
    {
        std::shared_ptr<SX::Instrument::Experiment> exp = ptr->getExperiment();
        emit plotData(exp->getData(item->text().toStdString()));
    }
}

void ExperimentTree::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        QList<QModelIndex> selIndexes = selectedIndexes();

        QListIterator<QModelIndex> it(selIndexes);
        it.toBack();
        while (it.hasPrevious())
        {
            QStandardItem* item = _session->itemFromIndex(it.previous());
            if (!item->parent())
                 _session->removeRow(item->row());
            else
                _session->removeRow(item->row(),item->parent()->index());
        }
    }
}


// jmf: this method no longer used?
//ExperimentItem* ExperimentTree::getExperimentItem(SX::Instrument::Experiment* exp)
//{

//    QModelIndex rootIdx = rootIndex();

//    for (auto i=0;i<_session->rowCount(rootIdx);++i)
//    {
//        auto idx = _session->index(i,0,rootIdx);
//        auto ptr=dynamic_cast<ExperimentItem*>(_session->itemFromIndex(idx));
//        if (ptr && ptr->getExperiment().get()==exp)
//            return ptr;
//    }

//    return nullptr;

// }

void ExperimentTree::onSingleClick(const QModelIndex &index)
{
        // Inspect this item if it is inspectable
        InspectableTreeItem* item=dynamic_cast<InspectableTreeItem*>(_session->itemFromIndex(index));
        if (item)
            emit inspectWidget(item->inspectItem());
        else
        {
            QWidget* widget=new QWidget();
            emit inspectWidget(widget);
        }
}

void ExperimentTree::showPeaksOpenGL()
{
    GLWidget* glw=new GLWidget();
    auto& scene=glw->getScene();
    auto datav=getSelectedNumors();
    for (auto idata : datav)
    {
       auto peaks=idata->getPeaks();
       for (auto peak: peaks)
       {
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
    SpaceGroupDialog* dialog = new SpaceGroupDialog(getSelectedNumors(), this);
    dialog->exec();
    // update the space group elsewhere
}

void ExperimentTree::computeRFactors()
{
    qDebug() << "Finding peak equivalences...";

    std::vector<std::shared_ptr<IData>> numors = getSelectedNumors();
    std::vector<std::vector<Peak3D*>> peak_equivs;
    std::vector<Peak3D*> peak_list;

    std::shared_ptr<UnitCell> unit_cell;

    for (std::shared_ptr<IData> numor: numors) {
        std::set<Peak3D*> peaks = numor->getPeaks();
        for (Peak3D* peak: peaks)
            if ( peak && peak->isSelected() && !peak->isMasked() )
                peak_list.push_back(peak);
    }

    if ( peak_list.size() == 0) {
        qDebug() << "No peaks -- cannot search for equivalences!";
        return;
    }

    for (Peak3D* peak: peak_list) {
        // what do we do if there is more than one sample/unit cell??
        unit_cell = peak->getUnitCell();

        if (unit_cell)
            break;
    }

    if (!unit_cell) {
        qDebug() << "No unit cell selected! Cannot compute R factors.";
        return;
    }

    SpaceGroup grp("P 1");

    // spacegroup construct can throw
    try {
        grp = SpaceGroup(unit_cell->getSpaceGroup());
    }
    catch(std::exception& e) {
        qDebug() << "Caught exception: " << e.what() << endl;
        return;
    }

    peak_equivs = grp.findEquivalences(peak_list, true);

    qDebug() << "Found " << peak_equivs.size() << " equivalence classes of peaks:";

    std::map<int, int> size_counts;

    for (auto& peaks: peak_equivs) {
        ++size_counts[peaks.size()];
    }

    for (auto& it: size_counts) {
        qDebug() << "Found " << it.second << " classes of size " << it.first;
    }

    qDebug() << "Computing R factors:";

    RFactor rfactor(peak_equivs);

    qDebug() << "    Rmerge = " << rfactor.Rmerge();
    qDebug() << "    Rmeas  = " << rfactor.Rmeas();
    qDebug() << "    Rpim   = " << rfactor.Rpim();

    //ScaleDialog* scaleDialog = new ScaleDialog(peak_equivs, this);
    //scaleDialog->exec();
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

void ExperimentTree::integrateCalculatedPeaks()
{
    qDebug() << "Integrating calculated peaks...";

    int count = 0;
    Eigen::Vector3d peak_extent, bg_extent;
    peak_extent << 0.0, 0.0, 0.0;
    bg_extent << 0.0, 0.0, 0.0;

    std::shared_ptr<UnitCell> unit_cell;

    for (std::shared_ptr<IData> numor: getSelectedNumors()) {
        for (Peak3D* peak: numor->getPeaks())
            if ( peak && peak->isSelected() && !peak->isMasked() ) {
                peak_extent += peak->getPeak()->getAABBExtents();
                bg_extent += peak->getBackground()->getAABBExtents();
                ++count;
            }
    }

    if ( count == 0) {
        qDebug() << "No peaks -- cannot search for equivalences!";
        return;
    }

    peak_extent /= count;
    bg_extent /= count;

    qDebug() << "Done calculating average bounding box";

    qDebug() << peak_extent(0) << " " << peak_extent(1) << " " << peak_extent(2);
    qDebug() << bg_extent(0) << " " << bg_extent(1) << " " << bg_extent(2);

    for (std::shared_ptr<IData> numor: getSelectedNumors()) {



        std::vector<Peak3D*> calculated_peaks;

        shared_ptr<Sample> sample = numor->getDiffractometer()->getSample();
        int ncrystals = sample->getNCrystals();

        if (ncrystals) {
            for (int i = 0; i < ncrystals; ++i) {
                SX::Crystal::SpaceGroup group(sample->getUnitCell(i)->getSpaceGroup());
                auto ub = sample->getUnitCell(i)->getReciprocalStandardM();

                qDebug() << "Calculating peak locations...";

                auto hkls = sample->getUnitCell(i)->generateReflectionsInSphere(1.5);
                std::vector<SX::Crystal::PeakCalc> peaks = numor->hasPeaks(hkls, ub);
                calculated_peaks.reserve(calculated_peaks.size() + peaks.size());

                qDebug() << "Adding calculated peaks...";

                for(auto&& p: peaks) {
                    //calculated_peaks.push_back(p);
                }
            }
        }

        qDebug() << "Done.";
    }
}

void ExperimentTree::peakFitDialog()
{
    qDebug() << "peakFitDialog() triggered";
    PeakFitDialog* dialog = new PeakFitDialog(this);
    dialog->exec();
}

void ExperimentTree::incorporateCalculatedPeaks()
{
    qDebug() << "Incorporating missing peaks into current data set...";

    std::vector<std::shared_ptr<IData>> numors = getSelectedNumors();

    std::shared_ptr<SX::Utils::ProgressHandler> handler(new SX::Utils::ProgressHandler);
    ProgressView progressView(this);
    progressView.watch(handler);

    int current_numor = 0;

    class compare_fn {
    public:
        auto operator()(const Eigen::RowVector3i a, const Eigen::RowVector3i b) -> bool
        {
            if (a(0) != b(0))
                return a(0) < b(0);

            if (a(1) != b(1))
                return a(1) < b(1);

            return a(2) < b(2);
        }
    };

    int last_done = 0;

    for(std::shared_ptr<IData> numor: numors) {
        qDebug() << "Finding missing peaks for numor " << ++current_numor << " of " << numors.size();

        std::vector<Peak3D*> calculated_peaks;

        shared_ptr<Sample> sample = numor->getDiffractometer()->getSample();
        int ncrystals = sample->getNCrystals();

        for (int i = 0; i < ncrystals; ++i) {
            SX::Crystal::SpaceGroup group(sample->getUnitCell(i)->getSpaceGroup());
            auto ub = sample->getUnitCell(i)->getReciprocalStandardM();

            handler->setStatus("Calculating peak locations...");

            //auto predicted_hkls = sample->getUnitCell(i)->generateReflectionsInSphere(1.5);
            auto predicted_hkls = sample->getUnitCell(i)->generateReflectionsInSphere(1.0   );
            std::vector<SX::Crystal::PeakCalc> peaks = numor->hasPeaks(predicted_hkls, ub);
            calculated_peaks.reserve(peaks.size());

            int current_peak = 0;

            handler->setStatus("Building set of previously found peaks...");

            std::set<Peak3D*> found_peaks = numor->getPeaks();
            std::set<Eigen::RowVector3i, compare_fn> found_hkls;

            for (Peak3D* p: found_peaks)
                found_hkls.insert(p->getIntegerMillerIndices());


            handler->setStatus("Adding calculated peaks...");

            for(PeakCalc& p: peaks) {
                ++current_peak;

                Eigen::RowVector3i hkl(std::round(p._h), std::round(p._k), std::round(p._l));

                // try to find this reflection in the list of peaks, skip if found
                if (std::find(found_hkls.begin(), found_hkls.end(), hkl) != found_hkls.end() )
                    continue;

                // now we must add it, calculating shape from nearest peaks
                Peak3D* new_peak = p.averagePeaks(numor, 200);

                if (!new_peak)
                    continue;

                new_peak->setSelected(true);
                calculated_peaks.push_back(new_peak);

                int done = std::round(current_peak * 100.0 / peaks.size());

                if ( done != last_done) {
                    handler->setProgress(done);
                    last_done = done;
                }
            }
        }

        for (Peak3D* peak: calculated_peaks)
            numor->addPeak(peak);

        numor->integratePeaks(handler);
    }

    qDebug() << "Done incorporating missing peaks.";
}
