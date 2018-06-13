#pragma once

#include <nsxlib/DataTypes.h>
#include <nsxlib/InstrumentTypes.h>

#include "TreeItem.h"

class PeakListItem;

class PeaksItem: public TreeItem {

public:

    explicit PeaksItem();

    nsx::PeakList selectedPeaks();

    virtual void setData(const QVariant &value, int role) override;

    void integratePeaks();
    void findSpaceGroup();
    void showPeaksOpenGL();
    void absorptionCorrection();
    void buildShapeLibrary();
    void filterPeaks();
    void autoindex();
    void refine();
    void autoAssignUnitCell();


};