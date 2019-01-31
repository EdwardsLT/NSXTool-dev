/********************************************************************************
** Form generated from reading UI file 'DialogIntegrate.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINTEGRATE_H
#define UI_DIALOGINTEGRATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DialogIntegrate
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_7;
    QComboBox *method;
    QCheckBox *fitCenter;
    QCheckBox *fitCov;
    QLabel *label_2;
    QDoubleSpinBox *peakScale;
    QLabel *label_8;
    QDoubleSpinBox *bkgBegin;
    QLabel *label;
    QDoubleSpinBox *bkgEnd;
    QLabel *label_3;
    QDoubleSpinBox *dMin;
    QLabel *label_4;
    QDoubleSpinBox *dMax;
    QLabel *label_6;
    QDoubleSpinBox *nframes;
    QDoubleSpinBox *radius;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *DialogIntegrate)
    {
        if (DialogIntegrate->objectName().isEmpty())
            DialogIntegrate->setObjectName(QStringLiteral("DialogIntegrate"));
        DialogIntegrate->resize(479, 407);
        DialogIntegrate->setModal(false);
        gridLayout = new QGridLayout(DialogIntegrate);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_7 = new QLabel(DialogIntegrate);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        method = new QComboBox(DialogIntegrate);
        method->setObjectName(QStringLiteral("method"));

        formLayout->setWidget(0, QFormLayout::FieldRole, method);

        fitCenter = new QCheckBox(DialogIntegrate);
        fitCenter->setObjectName(QStringLiteral("fitCenter"));

        formLayout->setWidget(1, QFormLayout::FieldRole, fitCenter);

        fitCov = new QCheckBox(DialogIntegrate);
        fitCov->setObjectName(QStringLiteral("fitCov"));

        formLayout->setWidget(2, QFormLayout::FieldRole, fitCov);

        label_2 = new QLabel(DialogIntegrate);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        peakScale = new QDoubleSpinBox(DialogIntegrate);
        peakScale->setObjectName(QStringLiteral("peakScale"));
        peakScale->setSingleStep(0.01);
        peakScale->setValue(3);

        formLayout->setWidget(3, QFormLayout::FieldRole, peakScale);

        label_8 = new QLabel(DialogIntegrate);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        bkgBegin = new QDoubleSpinBox(DialogIntegrate);
        bkgBegin->setObjectName(QStringLiteral("bkgBegin"));
        bkgBegin->setSingleStep(0.01);
        bkgBegin->setValue(4);

        formLayout->setWidget(4, QFormLayout::FieldRole, bkgBegin);

        label = new QLabel(DialogIntegrate);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label);

        bkgEnd = new QDoubleSpinBox(DialogIntegrate);
        bkgEnd->setObjectName(QStringLiteral("bkgEnd"));
        bkgEnd->setSingleStep(0.01);
        bkgEnd->setValue(4.5);

        formLayout->setWidget(5, QFormLayout::FieldRole, bkgEnd);

        label_3 = new QLabel(DialogIntegrate);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_3);

        dMin = new QDoubleSpinBox(DialogIntegrate);
        dMin->setObjectName(QStringLiteral("dMin"));
        dMin->setDecimals(3);
        dMin->setMaximum(1000);
        dMin->setSingleStep(0.001);

        formLayout->setWidget(6, QFormLayout::FieldRole, dMin);

        label_4 = new QLabel(DialogIntegrate);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_4);

        dMax = new QDoubleSpinBox(DialogIntegrate);
        dMax->setObjectName(QStringLiteral("dMax"));
        dMax->setDecimals(1);
        dMax->setMaximum(1000);
        dMax->setSingleStep(0.001);
        dMax->setValue(1000);

        formLayout->setWidget(7, QFormLayout::FieldRole, dMax);

        label_6 = new QLabel(DialogIntegrate);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_6);

        nframes = new QDoubleSpinBox(DialogIntegrate);
        nframes->setObjectName(QStringLiteral("nframes"));
        nframes->setDecimals(1);
        nframes->setMaximum(1000);
        nframes->setValue(5);

        formLayout->setWidget(9, QFormLayout::FieldRole, nframes);

        radius = new QDoubleSpinBox(DialogIntegrate);
        radius->setObjectName(QStringLiteral("radius"));
        radius->setDecimals(1);
        radius->setMaximum(10000);
        radius->setSingleStep(1);
        radius->setValue(300);

        formLayout->setWidget(8, QFormLayout::FieldRole, radius);

        label_5 = new QLabel(DialogIntegrate);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_5);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(DialogIntegrate);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        okButton = new QPushButton(DialogIntegrate);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(DialogIntegrate);

        QMetaObject::connectSlotsByName(DialogIntegrate);
    } // setupUi

    void retranslateUi(QDialog *DialogIntegrate)
    {
        DialogIntegrate->setWindowTitle(QApplication::translate("DialogIntegrate", "Reintegrate Peaks", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogIntegrate", "Method", Q_NULLPTR));
        fitCenter->setText(QApplication::translate("DialogIntegrate", "fit center (Gaussian, pixel sum)", Q_NULLPTR));
        fitCov->setText(QApplication::translate("DialogIntegrate", "fit covariance (Gaussian, pixel sum)", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogIntegrate", "Peak shape scale", Q_NULLPTR));
        label_8->setText(QApplication::translate("DialogIntegrate", "Background begin", Q_NULLPTR));
        label->setText(QApplication::translate("DialogIntegrate", "Peak background scale", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogIntegrate", "minimum d", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogIntegrate", "maximum d", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogIntegrate", "number of frames", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogIntegrate", "search radius", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("DialogIntegrate", "Cancel", Q_NULLPTR));
        okButton->setText(QApplication::translate("DialogIntegrate", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogIntegrate: public Ui_DialogIntegrate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINTEGRATE_H
