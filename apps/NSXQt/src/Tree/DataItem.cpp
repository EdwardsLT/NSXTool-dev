#include <QIcon>

#include "Experiment.h"
#include "Tree/DataItem.h"

DataItem::DataItem(std::shared_ptr<Experiment> experiment) : TreeItem(experiment)
{
    setText("Data");

    QIcon icon(":/resources/dataIcon.png");
    setIcon(icon);

    setEditable(false);
    setSelectable(false);
}
