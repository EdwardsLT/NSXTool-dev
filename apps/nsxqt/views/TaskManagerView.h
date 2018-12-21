#pragma once

#include <QModelIndex>
#include <QTableView>

class MainWindow;
class TaskManagerModel;

class TaskManagerView : public QTableView
{
    Q_OBJECT

public:

    TaskManagerView(MainWindow *main_window);

    void setModel(TaskManagerModel *task_manager_model);

signals:

    void abortTask(QModelIndex index);

    void runTask(QModelIndex index);

private:

    void onActionButtonClicked(QModelIndex index);
};
