/********************************************************************************
** Form generated from reading UI file 'DialogCalibrateDistance.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCALIBRATEDISTANCE_H
#define UI_DIALOGCALIBRATEDISTANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogCalibrateDistance
{
public:
    QDialogButtonBox *calibrateDistanceButtonOK;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QDoubleSpinBox *calibrateDistanceSpinBox;
    QLabel *calibrateDistanceLabel;

    void setupUi(QDialog *DialogCalibrateDistance)
    {
        if (DialogCalibrateDistance->objectName().isEmpty())
            DialogCalibrateDistance->setObjectName(QStringLiteral("DialogCalibrateDistance"));
        DialogCalibrateDistance->setWindowModality(Qt::ApplicationModal);
        DialogCalibrateDistance->resize(385, 119);
        calibrateDistanceButtonOK = new QDialogButtonBox(DialogCalibrateDistance);
        calibrateDistanceButtonOK->setObjectName(QStringLiteral("calibrateDistanceButtonOK"));
        calibrateDistanceButtonOK->setGeometry(QRect(290, 20, 81, 241));
        calibrateDistanceButtonOK->setOrientation(Qt::Vertical);
        calibrateDistanceButtonOK->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(DialogCalibrateDistance);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 269, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        calibrateDistanceSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        calibrateDistanceSpinBox->setObjectName(QStringLiteral("calibrateDistanceSpinBox"));
        calibrateDistanceSpinBox->setValue(1);

        gridLayout->addWidget(calibrateDistanceSpinBox, 1, 0, 1, 1);

        calibrateDistanceLabel = new QLabel(gridLayoutWidget);
        calibrateDistanceLabel->setObjectName(QStringLiteral("calibrateDistanceLabel"));
        calibrateDistanceLabel->setAutoFillBackground(true);

        gridLayout->addWidget(calibrateDistanceLabel, 0, 0, 1, 1);


        retranslateUi(DialogCalibrateDistance);
        QObject::connect(calibrateDistanceButtonOK, SIGNAL(accepted()), DialogCalibrateDistance, SLOT(accept()));
        QObject::connect(calibrateDistanceButtonOK, SIGNAL(rejected()), DialogCalibrateDistance, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogCalibrateDistance);
    } // setupUi

    void retranslateUi(QDialog *DialogCalibrateDistance)
    {
        DialogCalibrateDistance->setWindowTitle(QApplication::translate("DialogCalibrateDistance", "Distance calibration", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogCalibrateDistance", "mm", Q_NULLPTR));
        calibrateDistanceLabel->setText(QApplication::translate("DialogCalibrateDistance", "Please enter the length (mm) ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogCalibrateDistance: public Ui_DialogCalibrateDistance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCALIBRATEDISTANCE_H
