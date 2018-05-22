#ifndef NSXQT_EXPERIMENTTREE_H
#define NSXQT_EXPERIMENTTREE_H

#include <memory>
#include <string>
#include <vector>

#include <QPoint>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTreeView>

#include <nsxlib/DataTypes.h>

class ExperimentItem;
class SessionModel;

class ExperimentTree : public QTreeView {
    Q_OBJECT
public:
    explicit ExperimentTree(QWidget *parent = 0);
    ~ExperimentTree();

signals:
    void plotData(nsx::sptrDataSet);
    void inspectWidget(QWidget*);
    void resetScene();

public slots:
    void keyPressEvent(QKeyEvent* event);
    void onCustomMenuRequested(const QPoint& point);
    void onDoubleClick(const QModelIndex& index);

    void onSingleClick(const QModelIndex& index);
    void absorptionCorrection();
    void showPeaksOpenGL();
   
    void setIndexingTolerance();

};

#endif // NSXQT_EXPERIMENTTREE_H
