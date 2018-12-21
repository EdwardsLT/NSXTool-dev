#pragma once

#include <memory>
#include <string>
#include <vector>

#include <QPoint>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTreeView>

#include <nsxlib/DataTypes.h>

class DataItem;
class ExperimentItem;
class FrameAutoIndexer;
class FramePeakFinder;
class FrameStatistics;
class MainWindow;
class PeaksItem;
class SessionModel;

class SessionTreeView: public QTreeView {
    Q_OBJECT

public:

    explicit SessionTreeView(MainWindow *main_window);

    SessionModel* model();

signals:

    void signalSelectSessionTreeItem(QWidget*);

public slots:

    void keyPressEvent(QKeyEvent* event);

    void onCustomMenuRequested(const QPoint& point);

    void onDoubleClick(const QModelIndex& index);

    void onSingleClick(const QModelIndex& index);

private:

    void openAutoIndexerDialog(PeaksItem *peaks_item);

    void openInstrumentStatesDialog();

    void openPeakFinderDialog(DataItem *data_item);

    void openStatisticsDialog(ExperimentItem *experiment_item);

private:

    MainWindow *_main_window;

    SessionModel *_session_model;

    FrameAutoIndexer *_frame_autoindexer;

    FramePeakFinder *_frame_peak_finder;

    FrameStatistics *_frame_statistics;
};
