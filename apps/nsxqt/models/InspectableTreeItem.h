#ifndef NSXQT_INSPECTABLETREEITEM_H
#define NSXQT_INSPECTABLETREEITEM_H

#include <nsxlib/instrument/InstrumentTypes.h>

#include "TreeItem.h"

//! Interface for tree Items for which
//! one wants to show internal properties
//! or interact.
class InspectableTreeItem : public TreeItem
{
public:
    InspectableTreeItem(nsx::sptrExperiment experiment);
    ~InspectableTreeItem();
    //! Tree items can expose a QWidget that show their internal properties.
    virtual QWidget* inspectItem() = 0;
};

#endif // NSXQT_INSPECTABLETREEITEM_H
