/********************************************************************************
** Form generated from reading UI file 'PeakFilterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEAKFILTERDIALOG_H
#define UI_PEAKFILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogPeakFilter
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QCheckBox *checkPValue;
    QDoubleSpinBox *spinBoxDmax;
    QCheckBox *checkDmin;
    QCheckBox *checkDmax;
    QDoubleSpinBox *spinBoxIsigma;
    QDoubleSpinBox *spinBoxDmin;
    QDoubleSpinBox *spinBoxPValue;
    QCheckBox *checkOverlapping;
    QCheckBox *checkIsigma;
    QCheckBox *checkUnselected;
    QCheckBox *checkUnindexed;
    QCheckBox *checkSpaceGroup;
    QCheckBox *checkBoxMergedP;
    QDoubleSpinBox *spinBoxMergedP;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogPeakFilter)
    {
        if (DialogPeakFilter->objectName().isEmpty())
            DialogPeakFilter->setObjectName(QStringLiteral("DialogPeakFilter"));
        DialogPeakFilter->resize(512, 400);
        gridLayout_2 = new QGridLayout(DialogPeakFilter);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkPValue = new QCheckBox(DialogPeakFilter);
        checkPValue->setObjectName(QStringLiteral("checkPValue"));

        gridLayout->addWidget(checkPValue, 4, 0, 1, 1);

        spinBoxDmax = new QDoubleSpinBox(DialogPeakFilter);
        spinBoxDmax->setObjectName(QStringLiteral("spinBoxDmax"));

        gridLayout->addWidget(spinBoxDmax, 8, 2, 1, 1);

        checkDmin = new QCheckBox(DialogPeakFilter);
        checkDmin->setObjectName(QStringLiteral("checkDmin"));

        gridLayout->addWidget(checkDmin, 7, 0, 1, 1);

        checkDmax = new QCheckBox(DialogPeakFilter);
        checkDmax->setObjectName(QStringLiteral("checkDmax"));

        gridLayout->addWidget(checkDmax, 8, 0, 1, 1);

        spinBoxIsigma = new QDoubleSpinBox(DialogPeakFilter);
        spinBoxIsigma->setObjectName(QStringLiteral("spinBoxIsigma"));
        spinBoxIsigma->setMinimum(-1000);
        spinBoxIsigma->setMaximum(1000);
        spinBoxIsigma->setSingleStep(0.01);
        spinBoxIsigma->setValue(0.5);

        gridLayout->addWidget(spinBoxIsigma, 3, 2, 1, 1);

        spinBoxDmin = new QDoubleSpinBox(DialogPeakFilter);
        spinBoxDmin->setObjectName(QStringLiteral("spinBoxDmin"));

        gridLayout->addWidget(spinBoxDmin, 7, 2, 1, 1);

        spinBoxPValue = new QDoubleSpinBox(DialogPeakFilter);
        spinBoxPValue->setObjectName(QStringLiteral("spinBoxPValue"));
        spinBoxPValue->setDecimals(6);
        spinBoxPValue->setSingleStep(1e-6);
        spinBoxPValue->setValue(0.0001);

        gridLayout->addWidget(spinBoxPValue, 4, 2, 1, 1);

        checkOverlapping = new QCheckBox(DialogPeakFilter);
        checkOverlapping->setObjectName(QStringLiteral("checkOverlapping"));

        gridLayout->addWidget(checkOverlapping, 6, 0, 1, 1);

        checkIsigma = new QCheckBox(DialogPeakFilter);
        checkIsigma->setObjectName(QStringLiteral("checkIsigma"));

        gridLayout->addWidget(checkIsigma, 3, 0, 1, 1);

        checkUnselected = new QCheckBox(DialogPeakFilter);
        checkUnselected->setObjectName(QStringLiteral("checkUnselected"));

        gridLayout->addWidget(checkUnselected, 1, 0, 1, 1);

        checkUnindexed = new QCheckBox(DialogPeakFilter);
        checkUnindexed->setObjectName(QStringLiteral("checkUnindexed"));

        gridLayout->addWidget(checkUnindexed, 0, 0, 1, 1);

        checkSpaceGroup = new QCheckBox(DialogPeakFilter);
        checkSpaceGroup->setObjectName(QStringLiteral("checkSpaceGroup"));

        gridLayout->addWidget(checkSpaceGroup, 2, 0, 1, 1);

        checkBoxMergedP = new QCheckBox(DialogPeakFilter);
        checkBoxMergedP->setObjectName(QStringLiteral("checkBoxMergedP"));

        gridLayout->addWidget(checkBoxMergedP, 5, 0, 1, 1);

        spinBoxMergedP = new QDoubleSpinBox(DialogPeakFilter);
        spinBoxMergedP->setObjectName(QStringLiteral("spinBoxMergedP"));
        spinBoxMergedP->setDecimals(4);
        spinBoxMergedP->setMaximum(1);
        spinBoxMergedP->setSingleStep(0.0001);
        spinBoxMergedP->setValue(0.99);

        gridLayout->addWidget(spinBoxMergedP, 5, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogPeakFilter);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(DialogPeakFilter);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogPeakFilter, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogPeakFilter, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogPeakFilter);
    } // setupUi

    void retranslateUi(QDialog *DialogPeakFilter)
    {
        DialogPeakFilter->setWindowTitle(QApplication::translate("DialogPeakFilter", "Peak Filters", Q_NULLPTR));
        checkPValue->setText(QApplication::translate("DialogPeakFilter", "Remove peaks with raw p-value greater than", Q_NULLPTR));
        checkDmin->setText(QApplication::translate("DialogPeakFilter", "Remove peaks with d less than", Q_NULLPTR));
        checkDmax->setText(QApplication::translate("DialogPeakFilter", "Remove peaks with d greater than", Q_NULLPTR));
        checkOverlapping->setText(QApplication::translate("DialogPeakFilter", "Remove overlapping peaks", Q_NULLPTR));
        checkIsigma->setText(QApplication::translate("DialogPeakFilter", "Remove peaks with I/sigma less than", Q_NULLPTR));
        checkUnselected->setText(QApplication::translate("DialogPeakFilter", "Remove unselected peaks", Q_NULLPTR));
        checkUnindexed->setText(QApplication::translate("DialogPeakFilter", "Remove unindexed peaks", Q_NULLPTR));
        checkSpaceGroup->setText(QApplication::translate("DialogPeakFilter", "Remove peaks forbidden by space group", Q_NULLPTR));
        checkBoxMergedP->setText(QApplication::translate("DialogPeakFilter", "Remove merged peaks with p-value greater than", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogPeakFilter: public Ui_DialogPeakFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEAKFILTERDIALOG_H
