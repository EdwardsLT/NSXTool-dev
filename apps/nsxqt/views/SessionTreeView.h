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

class SessionTreeView: public QTreeView {
    Q_OBJECT

public:

    explicit SessionTreeView(MainWindow *main_window);

    SessionModel* model();

signals:

    void signalSelectSessionTreeItem(QWidget*);

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
