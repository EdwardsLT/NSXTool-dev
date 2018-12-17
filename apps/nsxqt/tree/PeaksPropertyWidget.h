#pragma once

#include <QStandardItem>
#include <QWidget>

namespace Ui {
class PeaksPropertyWidget;
}

class PeakListModel;
class PeaksItem;

class PeaksPropertyWidget : public QWidget {
    Q_OBJECT

public:

    explicit PeaksPropertyWidget(PeaksItem* caller, QWidget *parent = 0);

    ~PeaksPropertyWidget();

    PeakListModel* model();

private:

    PeaksItem* _peaks_item;

    Ui::PeaksPropertyWidget *ui;
};
