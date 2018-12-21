#pragma once

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/MergedData.h>
#include <nsxlib/SpaceGroup.h>

#include "NSXQFrame.h"

namespace Ui {
class FrameStatistics;
}

class ExperimentItem;
class QAbstractButton;
class QTableView;
class QWidget;

class FrameStatistics : public NSXQFrame
{
    Q_OBJECT

public:

    FrameStatistics(const nsx::PeakList& peaks);

    ~FrameStatistics();

private slots:

    void update();

    void saveStatistics();

    void saveMergedPeaks();

    void saveUnmergedPeaks();

    void slotActionClicked(QAbstractButton *button);

private:

    void plotStatistics(int column);

    void saveToFullProf(QTableView* table);

    void saveToShelX(QTableView* table);

    void updateMergedPeaksTab();

    void updateUnmergedPeaksTab();

    void updateStatisticsTab();

private:

    Ui::FrameStatistics *_ui;

    ExperimentItem *_experiment_item;

    nsx::PeakList _peaks;

    nsx::SpaceGroup _space_group;

    nsx::MergedData _merged_data;
};
