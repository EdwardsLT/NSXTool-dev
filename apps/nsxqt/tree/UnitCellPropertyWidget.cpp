#include <QCompleter>
#include <QMessageBox>
#include <QSortFilterProxyModel>

#include <nsxlib/chemistry/ChemistryTypes.h>
#include <nsxlib/chemistry/Material.h>
#include <nsxlib/crystal/Peak3D.h>
#include <nsxlib/crystal/SpaceGroupSymbols.h>
#include <nsxlib/crystal/UnitCell.h>
#include <nsxlib/data/DataSet.h>
#include <nsxlib/instrument/Gonio.h>
#include <nsxlib/utils/Units.h>

#include "LatticeIndexer.h"
#include "Logger.h"
#include "models/SessionModel.h"
#include "models/UnitCellItem.h"
#include "tree/UnitCellPropertyWidget.h"

#include "ui_UnitCellPropertyWidget.h"

UnitCellPropertyWidget::UnitCellPropertyWidget(UnitCellItem* caller,QWidget *parent) :
    QWidget(parent),
    _unitCellItem(caller),
    ui(new Ui::UnitCellPropertyWidget)
{
    ui->setupUi(this);
    // Special character
    ui->labelalpha->setText(QString((QChar) 0x03B1));
    ui->labelbeta->setText(QString((QChar) 0x03B2));
    ui->labelgamma->setText(QString((QChar) 0x03B3));

    connect(ui->doubleSpinBoxa,SIGNAL(editingFinished()),this,SLOT(setLatticeParams()));
    connect(ui->doubleSpinBoxb,SIGNAL(editingFinished()),this,SLOT(setLatticeParams()));
    connect(ui->doubleSpinBoxc,SIGNAL(editingFinished()),this,SLOT(setLatticeParams()));
    connect(ui->doubleSpinBoxalpha,SIGNAL(editingFinished()),this,SLOT(setLatticeParams()));
    connect(ui->doubleSpinBoxbeta,SIGNAL(editingFinished()),this,SLOT(setLatticeParams()));
    connect(ui->doubleSpinBoxgamma,SIGNAL(editingFinished()),this,SLOT(setLatticeParams()));

    SessionModel* sessionModel = dynamic_cast<SessionModel*>(_unitCellItem->model());

    connect(sessionModel,SIGNAL(updateCellParameters(nsx::sptrUnitCell)),this,SLOT(updateCellParameters(nsx::sptrUnitCell)));

    auto cell = _unitCellItem->getUnitCell();

    ui->spinBox_Z->setValue(cell->getZ());
    auto material=cell->getMaterial();
    if (material)
        ui->lineEdit_ChemicalFormula->setText(material->formula().c_str());

    updateCellParameters(cell);

    nsx::SpaceGroupSymbols* sgs=nsx::SpaceGroupSymbols::Instance();
    std::vector<std::string> symbols=sgs->getAllSymbols();

    for (const auto& symbol : symbols)
        ui->comboBox->addItem(QString::fromStdString(symbol));

    ui->comboBox->setCurrentText(cell->getSpaceGroup().c_str());

    ui->hklTolerance->setValue(cell->getHKLTolerance());

    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ui->comboBox->model());

    QCompleter* completer = new QCompleter(proxyModel,ui->comboBox);
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    completer->setCaseSensitivity(Qt::CaseSensitive);
    ui->comboBox->setCompleter(completer);

    connect(ui->comboBox->lineEdit(), SIGNAL(textChanged(QString)), proxyModel, SLOT(setFilterFixedString(QString)));
    connect(completer, SIGNAL(activated(const QString &)), this, SLOT(onCompleterActivated(const QString &)));

    connect(ui->hklTolerance,SIGNAL(valueChanged(double)),this,SLOT(setHKLTolerance(double)));

}

UnitCellPropertyWidget::~UnitCellPropertyWidget()
{
    delete ui;
}

void UnitCellPropertyWidget::setLatticeParams()
{
    double a=ui->doubleSpinBoxa->value();
    double b=ui->doubleSpinBoxb->value();
    double c=ui->doubleSpinBoxc->value();
    double alpha=ui->doubleSpinBoxalpha->value();
    double beta=ui->doubleSpinBoxbeta->value();
    double gamma=ui->doubleSpinBoxgamma->value();

    try
    {
        _unitCellItem->getUnitCell()->setParams(a,b,c,alpha*nsx::deg,beta*nsx::deg,gamma*nsx::deg);
    }catch(...)
    {

    }

    setMassDensity();

}

void UnitCellPropertyWidget::setMassDensity() const
{
    auto material=_unitCellItem->getUnitCell()->getMaterial();
    if (material)
    {
        double mm=material->molarMass();
        mm*=ui->spinBox_Z->value()/nsx::avogadro;
        double volume=_unitCellItem->getUnitCell()->getVolume()*nsx::ang3;
        material->setMassDensity(mm/volume);
    }
}


void UnitCellPropertyWidget::updateCellParameters(nsx::sptrUnitCell cell)
{
    ui->doubleSpinBoxa->setValue(cell->getA());
    ui->doubleSpinBoxb->setValue(cell->getB());
    ui->doubleSpinBoxc->setValue(cell->getC());
    ui->doubleSpinBoxalpha->setValue(cell->getAlpha()/nsx::deg);
    ui->doubleSpinBoxbeta->setValue(cell->getBeta()/nsx::deg);
    ui->doubleSpinBoxgamma->setValue(cell->getGamma()/nsx::deg);
}

void UnitCellPropertyWidget::getLatticeParams()
{
}

void UnitCellPropertyWidget::setChemicalFormula(const QString &formula)
{
    try
    {
        nsx::sptrMaterial material(new nsx::Material(formula.toStdString()));
        _unitCellItem->getUnitCell()->setMaterial(material);
    }
    catch(std::exception& e)
    {
       QMessageBox::critical(this, tr("NSXTool"),tr(e.what()));
        return;
   }
}

void UnitCellPropertyWidget::on_spinBox_Z_valueChanged(int arg1)
{
        _unitCellItem->getUnitCell()->setZ(arg1);
        setMassDensity();
}

void UnitCellPropertyWidget::on_lineEdit_ChemicalFormula_editingFinished()
{
    setChemicalFormula(ui->lineEdit_ChemicalFormula->text());
    setMassDensity();
}

void UnitCellPropertyWidget::onCompleterActivated(const QString& text)
{
    if (text.isEmpty())
        return;

    ui->comboBox->setCurrentIndex(ui->comboBox->findText(text));
    ui->comboBox->activated(ui->comboBox->currentIndex());
}

void UnitCellPropertyWidget::setHKLTolerance(double tolerance)
{
    _unitCellItem->getUnitCell()->setHKLTolerance(tolerance);
}
