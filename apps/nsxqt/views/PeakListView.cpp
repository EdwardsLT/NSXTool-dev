#include <cstdio>
#include <memory>
#include <set>

#include <QAction>
#include <QActionGroup>
#include <QContextMenuEvent>
#include <QHeaderView>
#include <QInputDialog>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QMenu>
#include <QMouseEvent>
#include <QStandardItemModel>

#include <nsxlib/DataSet.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/Logger.h>
#include <nsxlib/MetaData.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/ProgressHandler.h>
#include <nsxlib/UnitCell.h>

#include "PeakListModel.h"
#include "PeakListView.h"
#include "SessionModel.h"

PeakListView::PeakListView(QWidget *parent)
: QTableView(parent)
{
    setEditTriggers(QAbstractItemView::SelectedClicked);

    // Selection of a cell in the table select the whole line.
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::ExtendedSelection);

    setSortingEnabled(true);
    sortByColumn(0, Qt::AscendingOrder);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    verticalHeader()->show();

    setFocusPolicy(Qt::StrongFocus);

    _display_column_states.resize(PeakListModel::Column::Count);
    _display_column_states.fill(true);

    connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(selectPeak(QModelIndex)));

    connect(this,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(togglePeakSelection(QModelIndex)));
}

void PeakListView::selectPeak(QModelIndex index)
{
    if (!index.isValid()) {
        return;
    }

    PeakListModel* peaks_model = dynamic_cast<PeakListModel*>(model());

    peaks_model->selectPeak(index);
}

void PeakListView::keyPressEvent(QKeyEvent *event)
{
    auto previous_index = currentIndex();

    QTableView::keyPressEvent(event);

    auto current_index = currentIndex();

    auto key = event->key();

    if (event->modifiers() == Qt::NoModifier) {

        if (key == Qt::Key_Down || key == Qt::Key_Tab || key == Qt::Key_PageDown) {
            if (current_index == previous_index) {
                setCurrentIndex(model()->index(0,0));
            }
            selectPeak(currentIndex());
        } else if (key == Qt::Key_Up || key == Qt::Key_Backspace || key == Qt::Key_PageDown) {
            if (current_index == previous_index) {
                setCurrentIndex(model()->index(model()->rowCount()-1,0));
            }
            selectPeak(currentIndex());
        } else if (key == Qt::Key_Return || key == Qt::Key_Space) {
            togglePeakSelection(currentIndex());
        }
    }
}

void PeakListView::togglePeakSelection(QModelIndex index)
{
    auto peaks_model = dynamic_cast<PeakListModel*>(model());
    if (peaks_model == nullptr) {
        return;
    }

    peaks_model->togglePeakSelection(index);
}

void PeakListView::contextMenuEvent(QContextMenuEvent* event)
{
    auto peaksModel = dynamic_cast<PeakListModel*>(model());
    if (peaksModel == nullptr) {
        return;
    }

    auto peaks = peaksModel->peaks();
    if (peaks.empty()) {
        return;
    }
    // Show all peaks as selected when context menu is requested
    auto menu = new QMenu(this);
    menu->setAttribute(Qt::WA_DeleteOnClose);

    QAction* sortbyEquivalence = menu->addAction("Sort by equivalences");
    connect(sortbyEquivalence,SIGNAL(triggered()),peaksModel,SLOT(sortEquivalents()));

    menu->addSeparator();

    auto normalize = menu->addAction("Normalize to monitor");
    connect(normalize,SIGNAL(triggered()),this,SLOT(normalizeToMonitor()));

    menu->addSeparator();

    auto *column_menu = menu->addMenu("Column");
    _display_column_action_group = new QActionGroup(column_menu);
    _display_column_action_group->setExclusive(false);
    for (int i = 0; i < PeakListModel::Column::Count; ++i) {
        auto * action = _display_column_action_group->addAction(PeakListModelColumnToString(i));
        action->setCheckable(true);
        action->setChecked(_display_column_states[i]);
        column_menu->addAction(action);
    }
    connect(_display_column_action_group,&QActionGroup::triggered,this,&PeakListView::displayColumn);

    menu->addSeparator();

    // Menu to plot against metadata
    QModelIndexList indexList = selectionModel()->selectedIndexes();

    if (!indexList.empty()) {
        QMenu* plotasmenu=menu->addMenu("Plot as");
        const auto& metadata = peaks[indexList[0].row()]->data()->reader()->metadata();
        const auto& keys = metadata.keys();
        for (const auto& key : keys) {
            try {
                //Ensure metadata is a Numeric type
                metadata.key<double>(key);
            } catch(std::exception& e) {
                continue;
            }
            QAction* newparam = plotasmenu->addAction(QString::fromStdString(key));
            connect(newparam,&QAction::triggered,this,[&](){plotAs(key);});
        }
    }

    menu->addSeparator();

    QMenu* selectionMenu = menu->addMenu("Selection");

    auto *selectAllPeaks = selectionMenu->addAction("all peaks");
    connect(selectAllPeaks,SIGNAL(triggered()),this,SLOT(selectAllPeaks()));

    auto *selectValidPeaks = selectionMenu->addAction("valid peaks");
    connect(selectValidPeaks,SIGNAL(triggered()),this,SLOT(selectValidPeaks()));

    auto *selectUnindexedPeaks = selectionMenu->addAction("unindexed peaks");
    connect(selectUnindexedPeaks,SIGNAL(triggered()),this,SLOT(selectUnindexedPeaks()));

    auto *clearSelectedPeaks = selectionMenu->addAction("clear selection");
    connect(clearSelectedPeaks,SIGNAL(triggered()),this,SLOT(clearSelectedPeaks()));

    auto *togglePeaksSelection = selectionMenu->addAction("toggle selection");
    connect(togglePeaksSelection,SIGNAL(triggered()),this,SLOT(togglePeaksSelection()));

    menu->popup(event->globalPos());
}

void PeakListView::displayColumn(QAction *column_action)
{
    Q_UNUSED(column_action)

    auto column_actions = _display_column_action_group->actions();
    for (int i = 0; i < column_actions.size(); ++i) {
        _display_column_states[i] = column_actions[i]->isChecked();
        if (column_actions[i]->isChecked()) {
            showColumn(i);
        } else {
            hideColumn(i);
        }
    }
}

void PeakListView::normalizeToMonitor()
{
    bool ok;
    double factor = QInputDialog::getDouble(this,"Enter normalization factor","",1,1,100000000,1,&ok);

    if(!ok) {
        return;
    }

    auto peaksModel = dynamic_cast<PeakListModel*>(model());
    if (peaksModel == nullptr) {
        return;
    }

    auto peaks = peaksModel->peaks();
    if (peaks.empty()) {
        return;
    }

    peaksModel->normalizeToMonitor(factor);

    // Keep track of the last selected index before rebuilding the table
    QModelIndex index=currentIndex();

    selectRow(index.row());

    // If no row selected do nothing else.
    if (!index.isValid()) {
        return;
    }
    nsx::sptrPeak3D peak=peaks[index.row()];
    emit plotPeak(peak);
}

void PeakListView::plotAs(const std::string& key)
{
    QModelIndexList indexList = selectionModel()->selectedIndexes();
    if (!indexList.size()) {
        return;
    }

    auto peaksModel = dynamic_cast<PeakListModel*>(model());
    if (peaksModel == nullptr) {
        return;
    }

    auto peaks = peaksModel->peaks();
    if (peaks.empty()) {
        return;
    }

    int nPoints=indexList.size();

    QVector<double> x(nPoints);
    QVector<double> y(nPoints);
    QVector<double> e(nPoints);

    for (int i=0;i<nPoints;++i) {
        nsx::sptrPeak3D p=peaks[indexList[i].row()];
        x[i]=p->data()->reader()->metadata().key<double>(key);
        y[i]=p->correctedIntensity().value();
        e[i]=p->correctedIntensity().sigma();
    }
    emit plotData(x,y,e);
}

void PeakListView::selectUnindexedPeaks()
{
    auto peaksModel = dynamic_cast<PeakListModel*>(model());
    if (peaksModel == nullptr) {
        return;
    }
    QModelIndexList unindexedPeaks = peaksModel->unindexedPeaks();

    for (QModelIndex index : unindexedPeaks) {
        selectRow(index.row());
    }
}

void PeakListView::selectAllPeaks()
{
    selectAll();
}

void PeakListView::clearSelectedPeaks()
{
    clearSelection();
}

void PeakListView::togglePeaksSelection()
{
    QItemSelectionModel *selection = selectionModel();

    for (int i=0;i<model()->rowCount();++i) {
        selection->select(model()->index(i,0),QItemSelectionModel::Rows|QItemSelectionModel::Toggle);
    }
}

void PeakListView::selectValidPeaks()
{
    auto peaksModel = dynamic_cast<PeakListModel*>(model());
    if (peaksModel == nullptr) {
        return;
    }
    QModelIndexList validPeaksIndexes = peaksModel->selectedPeaks();

    for (QModelIndex index : validPeaksIndexes) {
        selectRow(index.row());
    }
}
