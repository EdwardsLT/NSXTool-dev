#pragma once

#include <string>

#include <QFileDialog>
#include <QTableView>

#include <nsxlib/CrystalTypes.h>

class QAction;
class QActionGroup;
class QContextMenuEvent;
class QMouseEvent;
class QString;
class QWidget;

class PeakCustomPlot;

class PeakListView : public QTableView
{
    Q_OBJECT
public:

    explicit PeakListView(QWidget* parent = 0);

    void contextMenuEvent(QContextMenuEvent *);

    virtual void keyPressEvent(QKeyEvent *event) override;

signals:
    void plotData(const QVector<double>&,const QVector<double>&,const QVector<double>&);
    void plotPeak(nsx::sptrPeak);
    void autoIndexed();
    void updateShapeLibrary(nsx::sptrShapeLibrary);

public slots:
    //! Normalize to monitor.
    void normalizeToMonitor();
    //! Plot as function of parameter. Needs to be a numeric type
    void plotAs(const std::string& key);

    void selectPeak(QModelIndex index);

    void clearSelectedPeaks();
    void selectAllPeaks();
    void selectValidPeaks();
    void selectUnindexedPeaks();

    void togglePeaksSelection();

private slots:

    void togglePeakSelection(QModelIndex index);

private:

    void sortByHKL(bool up);
    void sortByIntensity(bool up);
    void sortByNumor(bool up);
    void sortBySelected(bool up);
    void sortByTransmission(bool up);
    void constructTable();
    void displayColumn(QAction *column_action);

private:

    QActionGroup *_display_column_action_group;

    QVector<bool> _display_column_states;
};
