/********************************************************************************
** Form generated from reading UI file 'DialogRawData.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRAWDATA_H
#define UI_DIALOGRAWDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogRawData
{
public:
    QGridLayout *gridLayout;
    QComboBox *dataArrangement;
    QLabel *label_2;
    QComboBox *dataFormat;
    QLabel *label_7;
    QDoubleSpinBox *deltaOmega;
    QCheckBox *swapEndian;
    QDoubleSpinBox *deltaChi;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *deltaPhi;
    QLabel *label_6;
    QDoubleSpinBox *wavelength;
    QLabel *label;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogRawData)
    {
        if (DialogRawData->objectName().isEmpty())
            DialogRawData->setObjectName(QStringLiteral("DialogRawData"));
        DialogRawData->resize(311, 280);
        gridLayout = new QGridLayout(DialogRawData);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dataArrangement = new QComboBox(DialogRawData);
        dataArrangement->setObjectName(QStringLiteral("dataArrangement"));

        gridLayout->addWidget(dataArrangement, 0, 1, 1, 1);

        label_2 = new QLabel(DialogRawData);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        dataFormat = new QComboBox(DialogRawData);
        dataFormat->setObjectName(QStringLiteral("dataFormat"));

        gridLayout->addWidget(dataFormat, 1, 1, 1, 1);

        label_7 = new QLabel(DialogRawData);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        deltaOmega = new QDoubleSpinBox(DialogRawData);
        deltaOmega->setObjectName(QStringLiteral("deltaOmega"));
        deltaOmega->setDecimals(3);
        deltaOmega->setMinimum(-100);
        deltaOmega->setMaximum(100);
        deltaOmega->setSingleStep(0.001);

        gridLayout->addWidget(deltaOmega, 5, 1, 1, 1);

        swapEndian = new QCheckBox(DialogRawData);
        swapEndian->setObjectName(QStringLiteral("swapEndian"));
        swapEndian->setChecked(true);

        gridLayout->addWidget(swapEndian, 2, 1, 1, 1);

        deltaChi = new QDoubleSpinBox(DialogRawData);
        deltaChi->setObjectName(QStringLiteral("deltaChi"));
        deltaChi->setDecimals(3);
        deltaChi->setMinimum(-100);
        deltaChi->setMaximum(100);
        deltaChi->setSingleStep(0.001);

        gridLayout->addWidget(deltaChi, 4, 1, 1, 1);

        label_4 = new QLabel(DialogRawData);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_5 = new QLabel(DialogRawData);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        deltaPhi = new QDoubleSpinBox(DialogRawData);
        deltaPhi->setObjectName(QStringLiteral("deltaPhi"));
        deltaPhi->setMinimum(-100);
        deltaPhi->setMaximum(100);
        deltaPhi->setSingleStep(0.001);

        gridLayout->addWidget(deltaPhi, 6, 1, 1, 1);

        label_6 = new QLabel(DialogRawData);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        wavelength = new QDoubleSpinBox(DialogRawData);
        wavelength->setObjectName(QStringLiteral("wavelength"));
        wavelength->setDecimals(3);
        wavelength->setSingleStep(0.001);

        gridLayout->addWidget(wavelength, 7, 1, 1, 1);

        label = new QLabel(DialogRawData);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(DialogRawData);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogRawData);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 1, 1, 1);


        retranslateUi(DialogRawData);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogRawData, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogRawData, SLOT(reject()));

        dataArrangement->setCurrentIndex(1);
        dataFormat->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DialogRawData);
    } // setupUi

    void retranslateUi(QDialog *DialogRawData)
    {
        DialogRawData->setWindowTitle(QApplication::translate("DialogRawData", "Import Raw Data", Q_NULLPTR));
        dataArrangement->clear();
        dataArrangement->insertItems(0, QStringList()
         << QApplication::translate("DialogRawData", "Column major", Q_NULLPTR)
         << QApplication::translate("DialogRawData", "Row major", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("DialogRawData", "Data format", Q_NULLPTR));
        dataFormat->clear();
        dataFormat->insertItems(0, QStringList()
         << QApplication::translate("DialogRawData", "8 bit integer", Q_NULLPTR)
         << QApplication::translate("DialogRawData", "16 bit integer", Q_NULLPTR)
         << QApplication::translate("DialogRawData", "32 bit integer", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("DialogRawData", "Swap endianness", Q_NULLPTR));
        swapEndian->setText(QString());
        label_4->setText(QApplication::translate("DialogRawData", "delta omega", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogRawData", "delta phi", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogRawData", "wavelength", Q_NULLPTR));
        label->setText(QApplication::translate("DialogRawData", "Data arrangement", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogRawData", "delta chi", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogRawData: public Ui_DialogRawData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRAWDATA_H
