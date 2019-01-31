/********************************************************************************
** Form generated from reading UI file 'DialogPredictPeaks.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPREDICTPEAKS_H
#define UI_DIALOGPREDICTPEAKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "PeakListView.h"

QT_BEGIN_NAMESPACE

class Ui_DialogPredictPeaks
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label_3;
    QComboBox *unitCells;
    QLabel *label;
    QDoubleSpinBox *dMinSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *dMaxSpinBox;
    QLabel *label_5;
    QSpinBox *neighborSpinBox;
    QLabel *label_10;
    QDoubleSpinBox *sigmaSpinBox;
    QLabel *label_7;
    QDoubleSpinBox *radius;
    QLabel *label_11;
    QDoubleSpinBox *nframes;
    QLabel *label_8;
    QComboBox *interpolation;
    PeakListView *predictedPeaks;
    QDialogButtonBox *actions;

    void setupUi(QDialog *DialogPredictPeaks)
    {
        if (DialogPredictPeaks->objectName().isEmpty())
            DialogPredictPeaks->setObjectName(QStringLiteral("DialogPredictPeaks"));
        DialogPredictPeaks->resize(800, 500);
        verticalLayout = new QVBoxLayout(DialogPredictPeaks);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_3 = new QLabel(DialogPredictPeaks);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        unitCells = new QComboBox(DialogPredictPeaks);
        unitCells->setObjectName(QStringLiteral("unitCells"));

        formLayout->setWidget(0, QFormLayout::FieldRole, unitCells);

        label = new QLabel(DialogPredictPeaks);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        dMinSpinBox = new QDoubleSpinBox(DialogPredictPeaks);
        dMinSpinBox->setObjectName(QStringLiteral("dMinSpinBox"));
        dMinSpinBox->setMaximum(1000);
        dMinSpinBox->setSingleStep(0.01);
        dMinSpinBox->setValue(1.5);

        formLayout->setWidget(1, QFormLayout::FieldRole, dMinSpinBox);

        label_2 = new QLabel(DialogPredictPeaks);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        dMaxSpinBox = new QDoubleSpinBox(DialogPredictPeaks);
        dMaxSpinBox->setObjectName(QStringLiteral("dMaxSpinBox"));
        dMaxSpinBox->setMaximum(1000);
        dMaxSpinBox->setSingleStep(0.01);
        dMaxSpinBox->setValue(50);

        formLayout->setWidget(2, QFormLayout::FieldRole, dMaxSpinBox);

        label_5 = new QLabel(DialogPredictPeaks);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        neighborSpinBox = new QSpinBox(DialogPredictPeaks);
        neighborSpinBox->setObjectName(QStringLiteral("neighborSpinBox"));
        neighborSpinBox->setMaximum(100000);
        neighborSpinBox->setValue(20);

        formLayout->setWidget(3, QFormLayout::FieldRole, neighborSpinBox);

        label_10 = new QLabel(DialogPredictPeaks);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_10);

        sigmaSpinBox = new QDoubleSpinBox(DialogPredictPeaks);
        sigmaSpinBox->setObjectName(QStringLiteral("sigmaSpinBox"));
        sigmaSpinBox->setMaximum(100000);
        sigmaSpinBox->setSingleStep(0.1);
        sigmaSpinBox->setValue(3);

        formLayout->setWidget(4, QFormLayout::FieldRole, sigmaSpinBox);

        label_7 = new QLabel(DialogPredictPeaks);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        radius = new QDoubleSpinBox(DialogPredictPeaks);
        radius->setObjectName(QStringLiteral("radius"));
        radius->setMaximum(10000);
        radius->setValue(400);

        formLayout->setWidget(5, QFormLayout::FieldRole, radius);

        label_11 = new QLabel(DialogPredictPeaks);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_11);

        nframes = new QDoubleSpinBox(DialogPredictPeaks);
        nframes->setObjectName(QStringLiteral("nframes"));
        nframes->setMaximum(10000);
        nframes->setValue(100);

        formLayout->setWidget(6, QFormLayout::FieldRole, nframes);

        label_8 = new QLabel(DialogPredictPeaks);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        interpolation = new QComboBox(DialogPredictPeaks);
        interpolation->setObjectName(QStringLiteral("interpolation"));

        formLayout->setWidget(7, QFormLayout::FieldRole, interpolation);


        horizontalLayout->addLayout(formLayout);

        predictedPeaks = new PeakListView(DialogPredictPeaks);
        predictedPeaks->setObjectName(QStringLiteral("predictedPeaks"));

        horizontalLayout->addWidget(predictedPeaks);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        actions = new QDialogButtonBox(DialogPredictPeaks);
        actions->setObjectName(QStringLiteral("actions"));
        actions->setOrientation(Qt::Horizontal);
        actions->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(actions);


        retranslateUi(DialogPredictPeaks);

        interpolation->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogPredictPeaks);
    } // setupUi

    void retranslateUi(QDialog *DialogPredictPeaks)
    {
        DialogPredictPeaks->setWindowTitle(QApplication::translate("DialogPredictPeaks", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogPredictPeaks", "Unit Cell", Q_NULLPTR));
        label->setText(QApplication::translate("DialogPredictPeaks", "d min (angstrom)", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogPredictPeaks", "d max (angstrom)", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogPredictPeaks", "minimum neighbors", Q_NULLPTR));
        label_10->setText(QApplication::translate("DialogPredictPeaks", "Minimum I/sigma", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogPredictPeaks", "Search radius", Q_NULLPTR));
        label_11->setText(QApplication::translate("DialogPredictPeaks", "Number of frames", Q_NULLPTR));
        label_8->setText(QApplication::translate("DialogPredictPeaks", "Interpolation", Q_NULLPTR));
        interpolation->clear();
        interpolation->insertItems(0, QStringList()
         << QApplication::translate("DialogPredictPeaks", "No interpolation", Q_NULLPTR)
         << QApplication::translate("DialogPredictPeaks", "Inverse distance", Q_NULLPTR)
         << QApplication::translate("DialogPredictPeaks", "Intensity", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class DialogPredictPeaks: public Ui_DialogPredictPeaks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPREDICTPEAKS_H
