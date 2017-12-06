#include "DialogCalculatedPeaks.h"
#include "ui_DialogCalculatedPeaks.h"

DialogCalculatedPeaks::DialogCalculatedPeaks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCalculatedPeaks)
{
    ui->setupUi(this);
}

DialogCalculatedPeaks::~DialogCalculatedPeaks()
{
    delete ui;
}

double DialogCalculatedPeaks::dMin()
{
    return ui->dMinSpinBox->value();
}

double DialogCalculatedPeaks::dMax()
{
    return ui->dMaxSpinBox->value();
}

double DialogCalculatedPeaks::peakScale()
{
    return ui->peakScaleSpinBox->value();
}

double DialogCalculatedPeaks::bkgScale()
{
    return ui->bkgScaleSpinBox->value();
}

double DialogCalculatedPeaks::Isigma()
{
    return ui->sigmaSpinBox->value();
}

int DialogCalculatedPeaks::minimumNeighbors()
{
    return ui->neighborSpinBox->value();
}
