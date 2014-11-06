#include "SampleItem.h"

#include <QIcon>

#include "Diffractometer.h"
#include "Sample.h"

SampleItem::SampleItem(Experiment* experiment) : TreeItem(experiment)
{
    setText(QString::fromStdString(_experiment->getDiffractometer()->getSample()->getName()));
    QIcon icon(":/resources/sampleIcon.png");
    setIcon(icon);

    setEditable(true);

    setDragEnabled(false);
    setDropEnabled(false);
}

void SampleItem::setData(const QVariant &value, int role)
{
    QStandardItem::setData(value,role);
    _experiment->getDiffractometer()->getSample()->setName(text().toStdString());
}

