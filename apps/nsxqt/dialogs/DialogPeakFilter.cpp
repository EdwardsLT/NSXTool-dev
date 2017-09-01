#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>

#include <nsxlib/data/DataSet.h>
#include <nsxlib/crystal/Peak3D.h>
#include <nsxlib/crystal/PeakFilter.h>

#include "ui_PeakFilterDialog.h"
#include "DialogPeakFilter.h"



DialogPeakFilter::DialogPeakFilter(const nsx::DataList& data, QWidget* parent):
    QDialog(parent),
    _ui(new Ui::PeakFilterDialog),
    _data(data)
{
    _ui->setupUi(this);
}

DialogPeakFilter::~DialogPeakFilter()
{
    delete _ui;
}

void DialogPeakFilter::accept()
{
    nsx::PeakFilter filter;

    filter._removeUnindexed = _ui->checkUnindexed->isChecked();
    filter._removeMasked = _ui->checkMasked->isChecked();
    filter._removeUnselected = _ui->checkUnselected->isChecked();
    filter._removeMultiplyIndexed = _ui->checkMultiplyIndexed->isChecked();
    filter._removeIsigma = _ui->checkIsigma->isChecked();
    filter._removeSignificance = _ui->checkSignificance->isChecked();
    filter._removeOverlapping = _ui->checkOverlapping->isChecked();
    filter._removeDmin = _ui->checkDmin->isChecked();
    filter._removeDmax = _ui->checkDmax->isChecked();

    filter._Isigma = _ui->spinBoxIsigma->value();
    filter._dmin = _ui->spinBoxDmin->value();
    filter._dmax = _ui->spinBoxDmax->value();
    filter._significance = _ui->spinBoxSignificance->value();

    QDialog::accept();
}
