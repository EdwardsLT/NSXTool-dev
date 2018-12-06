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
class MainWindow;
class SessionModel;

class ExperimentTree: public QTreeView {
    Q_OBJECT

public:

    explicit ExperimentTree(MainWindow *main_window);

    SessionModel* model();

signals:

    void inspectWidget(QWidget*);

    void plotData(nsx::sptrDataSet);

public slots:

    void keyPressEvent(QKeyEvent* event);


    void onCustomMenuRequested(const QPoint& point);

    void onDoubleClick(const QModelIndex& index);

    void onSingleClick(const QModelIndex& index);

private:

    void openPeakFinderDialog(DataItem *data_item);

    void openInstrumentStatesDialog();

private:

    MainWindow *_main_window;

    SessionModel *_session_model;
};
