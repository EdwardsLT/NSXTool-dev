#include <memory>

#include <QMessageBox>

#include <Eigen/Dense>

#include <nsxlib/DataSet.h>

#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/Gonio.h>
#include <nsxlib/InstrumentState.h>
#include <nsxlib/Material.h>
#include <nsxlib/MCAbsorption.h>
#include <nsxlib/Monochromator.h>
#include <nsxlib/Peak3D.h>
#include <nsxlib/ReciprocalVector.h>
#include <nsxlib/Sample.h>
#include <nsxlib/Source.h>
#include <nsxlib/Units.h>

#include "MCAbsorptionDialog.h"

#include "ui_MCAbsorptionDialog.h"

MCAbsorptionDialog::MCAbsorptionDialog(std::shared_ptr<SessionModel> session, nsx::sptrExperiment experiment, QWidget *parent):
    QDialog(parent),
    ui(new Ui::MCAbsorptionDialog),
    _experiment(experiment),
    _session(session)
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
        const auto& peaks = _session->peaks(d.second.get());
        ui->progressBar_MCStatus->setMaximum(peaks.size());
        ui->progressBar_MCStatus->setFormat(QString::fromStdString(d.second->getFilename()) + ": "+QString::number(progress)+"%");
        for (auto& p: peaks) {
            auto data = p->data();
            auto coord = p->getShape().center();
            auto state = data->getInterpolatedState(coord[2]);
            auto position = data->getDiffractometer()->getDetector()->pixelPosition(coord[0], coord[1]);
            auto kf = state.kfLab(position);
            // todo: check coordinate systems here, may not be consistent
            double transmission=mca.run(ui->spinBox->value(),kf.rowVector(),state.sampleOrientation());
            p->setTransmission(transmission);
            ui->progressBar_MCStatus->setValue(++progress);
        }
    }
}
