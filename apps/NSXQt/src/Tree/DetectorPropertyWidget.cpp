#include "ui_DetectorPropertyWidget.h"

#include "Tree/DetectorPropertyWidget.h"

DetectorPropertyWidget::DetectorPropertyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetectorPropertyWidget)
{
    ui->setupUi(this);
}

DetectorPropertyWidget::~DetectorPropertyWidget()
{
    delete ui;
}