#include <memory>

#include <QMessageBox>

#include <Eigen/Dense>

#include <nsxlib/chemistry/Material.h>
#include <nsxlib/crystal/Peak3D.h>
#include <nsxlib/data/DataSet.h>
#include <nsxlib/geometry/MCAbsorption.h>
#include <nsxlib/instrument/Diffractometer.h>
#include <nsxlib/instrument/Experiment.h>
#include <nsxlib/instrument/Gonio.h>
#include <nsxlib/instrument/Monochromator.h>
#include <nsxlib/instrument/Sample.h>
#include <nsxlib/instrument/Source.h>
#include <nsxlib/utils/Units.h>

#include "MCAbsorptionDialog.h"

#include "ui_MCAbsorptionDialog.h"

MCAbsorptionDialog::MCAbsorptionDialog(nsx::sptrExperiment experiment, QWidget *parent):
    QDialog(parent),
     ui(new Ui::MCAbsorptionDialog),
    _experiment(experiment)
{
    ui->setupUi(this);
    auto ncrystals=_experiment->getDiffractometer()->getSample()->getNCrystals();
    if (ncrystals>0) {
        ui->comboBox->setEnabled(true);
        for (unsigned int i=0;i<ncrystals;++i) {
            ui->comboBox->addItem("Crystal"+QString::number(i+1));
        }
    }
    ui->progressBar_MCStatus->setValue(0);
}

MCAbsorptionDialog::~MCAbsorptionDialog()
{
    delete ui;
}

void MCAbsorptionDialog::on_pushButton_run_pressed()
{

    if (!ui->comboBox->isEnabled()) {
        return;
    }
    // Get the source
    auto source=_experiment->getDiffractometer()->getSource();
    auto sample=_experiment->getDiffractometer()->getSample();

    // Get the material
    unsigned int cellIndex=static_cast<unsigned int>(ui->comboBox->currentIndex());
    auto material=sample->getMaterial(cellIndex);
    if (material==nullptr) {
        QMessageBox::critical(this,"NSXTOOL","No material defined for this crystal");
            return;
    }

    auto& mono = source->getSelectedMonochromator();

    nsx::MCAbsorption mca(mono.getWidth(),mono.getHeight(),-1.0);
    auto& hull=sample->getShape();
    if (!hull.checkEulerConditions()) {
        QMessageBox::critical(this,"NSXTOOL","The sample shape (hull) is ill-defined");
        return;
    }

    mca.setSample(&hull,material->muIncoherent(),material->muAbsorption(mono.getWavelength()*nsx::ang));
    const auto& data=_experiment->getData();
    ui->progressBar_MCStatus->setValue(0);
    ui->progressBar_MCStatus->setTextVisible(true);
    int progress=0;

    for (auto& d: data) {
        const auto& peaks=d.second->getPeaks();
        ui->progressBar_MCStatus->setMaximum(peaks.size());
        ui->progressBar_MCStatus->setFormat(QString::fromStdString(d.second->getBasename()) + ": "+QString::number(progress)+"%");
        for (auto& p: peaks) {
            Eigen::Transform<double,3,2> hommat=sample->getGonio()->getHomMatrix(p->getSampleState().getValues());
            Eigen::Matrix3d rot=hommat.rotation();
            double transmission=mca.run(ui->spinBox->value(),p->getKf(),rot);
            p->setTransmission(transmission);
            ui->progressBar_MCStatus->setValue(++progress);
        }
    }
}
