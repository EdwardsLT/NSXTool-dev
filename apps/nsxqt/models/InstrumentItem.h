#ifndef NSXQT_INSTRUMENTITEM_H
#define NSXQT_INSTRUMENTITEM_H

#include <QJsonObject>

#include "models/TreeItem.h"

namespace nsx {
class Experiment;
}

class DetectorItem;
class SampleItem;
class SourceItem;

class InstrumentItem : public TreeItem
{
public:
    explicit InstrumentItem(std::shared_ptr<nsx::Experiment> experiment);

    QJsonObject toJson() override;
    void fromJson(const QJsonObject& obj) override;

public:

    DetectorItem* getDetectorItem();
    SampleItem* getSampleItem();
    SourceItem* getSourceItem();

private:
    DetectorItem* _detector;
    SampleItem* _sample;
    SourceItem* _source;
};

#endif // NSXQT_INSTRUMENTITEM_H
