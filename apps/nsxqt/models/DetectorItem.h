#ifndef NSXQT_DETECTORITEM_H
#define NSXQT_DETECTORITEM_H

#include <memory>
#include <string>

#include <QString>

#include <nsxlib/instrument/Experiment.h>

#include "InspectableTreeItem.h"

class QWidget;

class DetectorItem : public InspectableTreeItem
{
public:
    explicit DetectorItem(std::shared_ptr<Experiment> experiment);
    QWidget* inspectItem() override;

    QJsonObject toJson() override;
};

#endif // NSXQT_DETECTORITEM_H
