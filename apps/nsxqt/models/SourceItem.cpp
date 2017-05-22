#include <QIcon>

#include <nsxlib/instrument/Diffractometer.h>
#include <nsxlib/instrument/Experiment.h>
#include <nsxlib/instrument/Source.h>

#include "models/SourceItem.h"
#include "tree/SourcePropertyWidget.h"

SourceItem::SourceItem(nsx::sptrExperiment experiment) : InspectableTreeItem(experiment)
{
    setText(QString::fromStdString(_experiment->getDiffractometer()->getSource()->getName()));

    QIcon icon(":/resources/sourceIcon.png");
    setIcon(icon);
    setEditable(false);
    setSelectable(false);
    setDragEnabled(false);
    setDropEnabled(false);
}

QWidget* SourceItem::inspectItem()
{
    return new SourcePropertyWidget(this);
}
