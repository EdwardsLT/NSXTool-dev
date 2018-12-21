#include <memory>
#include <QAbstractItemView>
#include <QFileDialog>
#include <QFileInfo>
#include <QKeyEvent>
#include <QList>
#include <QListIterator>
#include <QMenu>
#include <QModelIndexList>
#include <QStandardItem>
#include <QString>

#include <nsxlib/Diffractometer.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/Logger.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/PeakFilter.h>
#include <nsxlib/ReciprocalVector.h>
#include <nsxlib/UnitCell.h>

#include "DataItem.h"
#include "DetectorItem.h"
#include "DetectorSceneModel.h"
#include "DialogExperiment.h"
#include "DialogIsotopesDatabase.h"
#include "DialogRawData.h"
#include "DialogSpaceGroup.h"
#include "DialogTransformationMatrix.h"
#include "ExperimentItem.h"
#include "FrameAutoIndexer.h"
#include "FramePeakFinder.h"
#include "FrameStatistics.h"
#include "InstrumentItem.h"
#include "LibraryItem.h"
#include "MainWindow.h"
#include "MetaTypes.h"
#include "NumorItem.h"
#include "PeaksItem.h"
#include "PeakListItem.h"
#include "ProgressView.h"
#include "SampleItem.h"
#include "SessionModel.h"
#include "SessionModelDelegate.h"
#include "SessionTreeView.h"
#include "SourceItem.h"
#include "TreeItem.h"
#include "UnitCellItem.h"
#include "UnitCellsItem.h"

SessionTreeView::SessionTreeView(MainWindow *main_window)
: QTreeView(main_window),
  _main_window(main_window),
  _session_model(main_window->sessionModel()),
  _frame_autoindexer(nullptr),
  _frame_peak_finder(nullptr)

{
    setContextMenuPolicy(Qt::CustomContextMenu);

    expandAll();
    setSelectionMode(QAbstractItemView::ContiguousSelection);
    update();

    setExpandsOnDoubleClick(false);

    auto session_model_delegate = new SessionModelDelegate();

    setItemDelegate(session_model_delegate);

    connect(this,SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(onCustomMenuRequested(const QPoint&)));
    connect(this,SIGNAL(doubleClicked(const QModelIndex&)),this,SLOT(onDoubleClick(const QModelIndex&)));
    connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(onSingleClick(QModelIndex)));

    connect(_session_model,&SessionModel::signalResetScene,_main_window->detectorSceneModel(),&DetectorSceneModel::resetScene);
}

void SessionTreeView::onCustomMenuRequested(const QPoint& point)
{
    QModelIndex index = indexAt(point);
    QMenu* menu = new QMenu(this);
    menu->setAttribute(Qt::WA_DeleteOnClose);
    auto triggered = &QAction::triggered;

    if (index == rootIndex()) {
        QAction* newexp = menu->addAction("Add new experiment");
        connect(newexp, triggered, [=]() {_main_window->onNewExperiment();});
    } else {
        QStandardItem* item = _session_model->itemFromIndex(index);
        
        if (auto experiment_item = dynamic_cast<ExperimentItem*>(item)) {
            QAction* log = menu->addAction("Statistics");
            connect(log, triggered, [=](){openStatisticsDialog(experiment_item);});
        } else if (auto data_item = dynamic_cast<DataItem*>(item)) {
            QAction* load_data = menu->addAction("Load data");
            connect(load_data, &QAction::triggered, [=](){data_item->importData();});

            QAction* remove_selected_data = menu->addAction("Remove selected data");
            connect(remove_selected_data, &QAction::triggered, [=](){data_item->removeSelectedData();});

            QAction* convert_to_hdf5 = menu->addAction("Convert to HDF5");
            connect(convert_to_hdf5, &QAction::triggered, [=](){data_item->convertToHDF5();});

            QAction* import_raw = menu->addAction("Import raw data");
            connect(import_raw, &QAction::triggered, [=](){data_item->importRawData();});

            menu->addSeparator();

            QAction* find_peaks = menu->addAction("Peak finder");
            connect(find_peaks, &QAction::triggered, [=](){openPeakFinderDialog(data_item);});

            menu->addSeparator();

            QAction* open_instrument_states_dialog = menu->addAction("Open instrument states dialog");
            connect(open_instrument_states_dialog, &QAction::triggered, [=](){data_item->openInstrumentStatesDialog();});
        } else if (auto peaks_item = dynamic_cast<PeaksItem*>(item)) {

            QMenu *indexing_menu = new QMenu("Indexing");
            QAction* autoindex = indexing_menu->addAction("FFT auto indexer");
            connect(autoindex, triggered, [=](){openAutoIndexerDialog(peaks_item);});

            QAction* user_defined = indexing_menu->addAction("User defined cell parameters indexer");
            connect(user_defined, triggered, [=](){peaks_item->openUserDefinedUnitCellIndexerFrame();});

            QAction* assign = indexing_menu->addAction("Assign unit cell");
            connect(assign, triggered, [=](){peaks_item->autoAssignUnitCell();});

            menu->addSeparator();

            QAction* filter = menu->addAction("Filter peaks");
            connect(filter, triggered, [=](){peaks_item->openPeakFilterDialog();});

            QAction* remove_selected_data = menu->addAction("Remove selected peak collections");
            connect(remove_selected_data, &QAction::triggered, [=](){peaks_item->removeSelectedPeakCollections();});

            menu->addMenu(indexing_menu);

            QAction* refine = menu->addAction("Refine lattice and instrument parameters");
            connect(refine, triggered, [=](){peaks_item->refine();});

            menu->addMenu(indexing_menu);

            QAction* library = menu->addAction("Build shape library");
            connect(library, triggered, [=]{peaks_item->buildShapeLibrary();});

            QAction* integrate = menu->addAction("Integrate peaks");
            connect(integrate, triggered, [=](){peaks_item->integratePeaks();});

            menu->addMenu(indexing_menu);

            QAction* normalize = menu->addAction("Normalize to monitor");
            connect(normalize, triggered, [=](){peaks_item->normalizeToMonitor();});

            menu->addMenu(indexing_menu);

            QAction* abs = menu->addAction("Correct for Absorption");
            connect(abs, triggered, [=]{peaks_item->absorptionCorrection();});

            menu->addMenu(indexing_menu);

            QAction* scene3d = menu->addAction("Show 3D view");
            connect(scene3d, triggered, [=]{peaks_item->showPeaksOpenGL();});
        } else if (SampleItem* sample_item = dynamic_cast<SampleItem*>(item)) {
            QAction* openIsotopesDatabase = menu->addAction("Isotopes database");
            connect(openIsotopesDatabase, &QAction::triggered, [=](){sample_item->openIsotopesDatabase();});
            QAction* openSampleGlobalOffsets = menu->addAction("Sample goniometer global offsets");
            connect(openSampleGlobalOffsets, &QAction::triggered, [=](){sample_item->openSampleGlobalOffsetsFrame();});
        } else if (DetectorItem* detector_item = dynamic_cast<DetectorItem*>(item)) {
            QAction* openDetectorGlobalOffsets = menu->addAction("Detector goniometer global offsets");
            connect(openDetectorGlobalOffsets, &QAction::triggered, [=](){detector_item->openDetectorGlobalOffsetsFrame();});
        } else if (UnitCellItem* unit_cell_item = dynamic_cast<UnitCellItem*>(item)) {
            QAction* info = menu->addAction("Info");
            menu->addSeparator();
            QAction* setTolerance = menu->addAction("Set HKL tolerance");
            menu->addSeparator();
            QAction* cellParameters=menu->addAction("Change unit cell parameters");
            QAction* transformationMatrix=menu->addAction("Transformation unit cell");
            QAction* group = menu->addAction("Select space group");

            connect(info, &QAction::triggered,[=](){unit_cell_item->info();});
            connect(cellParameters, &QAction::triggered, [=](){unit_cell_item->openChangeUnitCellDialog();});
            connect(transformationMatrix, &QAction::triggered, [=](){unit_cell_item->openTransformationMatrixDialog();});
            connect(setTolerance, &QAction::triggered,[=](){unit_cell_item->openIndexingToleranceDialog();});
            connect(group, triggered, [=](){unit_cell_item->openSpaceGroupDialog();});
        } else if (auto numor_item = dynamic_cast<NumorItem*>(item)) {
            QAction* export_hdf = menu->addAction("Export to HDF5...");            

            auto export_fn = [=] {
                QString filename = QFileDialog::getSaveFileName(this, "Save File", "", "HDF5 (*.hdf *.hdf5)", nullptr, QFileDialog::Option::DontUseNativeDialog);
                numor_item->exportHDF5(filename.toStdString());
            };
            connect(export_hdf, &QAction::triggered, this, export_fn);
        } else if (auto library_item = dynamic_cast<LibraryItem*>(item)) {
            QAction* predict = menu->addAction("Predict peaks");
            connect(predict, triggered, [=](){library_item->incorporateCalculatedPeaks();});
        } else if (UnitCellsItem* unit_cells_item = dynamic_cast<UnitCellsItem*>(item)) {
            QAction* remove_unused_unit_cell = menu->addAction("Remove unused unit cells");
            connect(remove_unused_unit_cell, triggered, [=](){unit_cells_item->removeUnusedUnitCells();});
        } else {
            delete menu;
            return;
        }
    }

    menu->popup(viewport()->mapToGlobal(point));
}

void SessionTreeView::onDoubleClick(const QModelIndex& index)
{
    // Get the current item and check that is actually a Numor item. Otherwise, return.
    QStandardItem* item = _session_model->itemFromIndex(index);
    if (auto data_item = dynamic_cast<DataItem*>(item)) {
        if (_session_model->rowCount(data_item->index())==0) {
            data_item->importData();
        } else {
            for (auto i = 0; i < _session_model->rowCount(data_item->index());++i) {
                auto ci = data_item->child(i);
                Qt::CheckState new_state = ci->checkState() == Qt::Unchecked ? Qt::Checked : Qt::Unchecked;
                ci->setCheckState(new_state);
            }
        }
    } else if (auto ptr=dynamic_cast<NumorItem*>(item)) {
        _session_model->selectData(ptr->data(Qt::UserRole).value<nsx::sptrDataSet>());
    }
}

void SessionTreeView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete) {
        QList<QModelIndex> selIndexes = selectedIndexes();

        QListIterator<QModelIndex> it(selIndexes);
        it.toBack();
        while (it.hasPrevious()) {
            auto item = _session_model->itemFromIndex(it.previous());
            if (!item->parent()) {
                _session_model->removeRow(item->row());
            } else {
                _session_model->removeRow(item->row(),item->parent()->index());
            }
        }
    }
}

void SessionTreeView::onSingleClick(const QModelIndex &index)
{
    // Inspect this item if it is inspectable
    InspectableTreeItem* item = dynamic_cast<InspectableTreeItem*>(_session_model->itemFromIndex(index));
    if (item) {
        emit signalSelectSessionTreeItem(item->inspectItem());
    } else {
        QWidget* widget = new QWidget();
        emit signalSelectSessionTreeItem(widget);
    }
}

void SessionTreeView::openPeakFinderDialog(DataItem *data_item)
{
    if (_frame_peak_finder) {
        _frame_peak_finder->raise();
        return;
    }

    nsx::DataList data = data_item->selectedData();

    if (data.empty()) {
        nsx::error()<<"No numors selected for finding peaks";
        return;
    }

    auto experiment_item = data_item->experimentItem();

    _frame_peak_finder = new FramePeakFinder(_main_window,experiment_item,data);

    _frame_peak_finder->show();

    connect(_frame_peak_finder,&FramePeakFinder::destroyed,[this](){_frame_peak_finder = nullptr;});
}

void SessionTreeView::openAutoIndexerDialog(PeaksItem *peaks_item)
{
    if (_frame_autoindexer) {
        _frame_autoindexer->raise();
        return;
    }

    auto&& selected_peaks = peaks_item->selectedPeaks();

    _frame_autoindexer = new FrameAutoIndexer(peaks_item->experimentItem(), selected_peaks);

    _frame_autoindexer->show();

    connect(_frame_autoindexer,&FrameAutoIndexer::destroyed,[this](){_frame_autoindexer = nullptr;});
}

void SessionTreeView::openStatisticsDialog(ExperimentItem *experiment_item)
{
    if (_frame_statistics) {
        _frame_statistics->raise();
        return;
    }

    auto&& peaks = experiment_item->peaksItem()->selectedPeaks();

    nsx::PeakFilter peak_filter;
    nsx::PeakList filtered_peaks;
    filtered_peaks = peak_filter.enabled(peaks,true);
    filtered_peaks = peak_filter.hasUnitCell(filtered_peaks);

    if (filtered_peaks.empty()) {
        nsx::error() << "No valid peaks in the table";
        return;
    }

    auto unit_cell = filtered_peaks[0]->unitCell();
    for (auto peak : filtered_peaks) {
        if (peak->unitCell() != unit_cell) {
            nsx::error() << "The selected peaks have different unit cells";
            return;
        }
    }

    filtered_peaks = peak_filter.unitCell(filtered_peaks,unit_cell);
    filtered_peaks = peak_filter.indexed(filtered_peaks,*unit_cell,unit_cell->indexingTolerance());

    _frame_statistics = new FrameStatistics(filtered_peaks);

    _frame_statistics->show();

    connect(_frame_statistics,&FrameStatistics::destroyed,[this](){_frame_statistics = nullptr;});
}
