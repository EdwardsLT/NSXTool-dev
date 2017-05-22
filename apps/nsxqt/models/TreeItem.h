#ifndef NSXQT_TREEITEM_H
#define NSXQT_TREEITEM_H

#include <memory>
#include <string>

#include <QStandardItem>
#include <QVariant>
#include <QJsonObject>

#include <nsxlib/instrument/Experiment.h>
#include <nsxlib/instrument/InstrumentTypes.h>

class QWidget;

class TreeItem : public QStandardItem
{

public:

    explicit TreeItem(nsx::sptrExperiment experiment);
    nsx::sptrExperiment getExperiment();
    virtual ~TreeItem();

    virtual void setData(const QVariant & value, int role=Qt::UserRole + 1) override;

    virtual QJsonObject toJson();
    virtual void fromJson(const QJsonObject& obj);

protected:
    nsx::sptrExperiment _experiment;

};

#endif // NSXQT_TREEITEM_H
