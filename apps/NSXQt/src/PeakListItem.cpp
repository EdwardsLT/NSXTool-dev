#include "PeakListItem.h"

#include <QIcon>

PeakListItem::PeakListItem(Experiment* experiment) : TreeItem(experiment)
{

	setText("Peaks");

    QIcon icon(":/resources/peakListIcon.png");
    setIcon(icon);

    setEditable(false);

    setDragEnabled(true);
    setDropEnabled(true);

    setSelectable(false);
}