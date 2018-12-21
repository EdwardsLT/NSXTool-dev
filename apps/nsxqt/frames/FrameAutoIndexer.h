#pragma once

#include <utility>
#include <vector>

#include <nsxlib/CrystalTypes.h>

#include "NSXQFrame.h"

namespace Ui {
class FrameAutoIndexer;
}

class ExperimentItem;
class PeakListModel;
class QAbstractButton;

class FrameAutoIndexer : public NSXQFrame
{
    Q_OBJECT

public:

    FrameAutoIndexer(ExperimentItem* experiment_item, const nsx::PeakList& peaks);

    ~FrameAutoIndexer();

private slots:

    void slotActionClicked(QAbstractButton* button);

    void slotTabEdited(int index);

    void slotTabRemoved(int index);

    void selectSolution(int);

private:

    void accept();

    void buildSolutionsTable();

    void resetUnitCell();

    void run();

private:

    Ui::FrameAutoIndexer *_ui;

    ExperimentItem *_experiment_item;

    PeakListModel *_peaks_model;

    std::vector<std::pair<nsx::sptrPeak3D,std::shared_ptr<nsx::UnitCell>>> _defaults;

    std::vector<std::pair<nsx::sptrUnitCell,double>> _solutions;
};
