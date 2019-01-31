/********************************************************************************
** Form generated from reading UI file 'SourcePropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOURCEPROPERTYWIDGET_H
#define UI_SOURCEPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SourcePropertyWidget
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *wavelength;
    QLabel *label_6;
    QLabel *label_4;
    QDoubleSpinBox *height;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *fwhm;
    QLabel *label_3;
    QDoubleSpinBox *width;
    QLabel *label_5;
    QComboBox *source_type;
    QComboBox *monochromators;

    void setupUi(QWidget *SourcePropertyWidget)
    {
        if (SourcePropertyWidget->objectName().isEmpty())
            SourcePropertyWidget->setObjectName(QStringLiteral("SourcePropertyWidget"));
        SourcePropertyWidget->resize(378, 259);
        gridLayout = new QGridLayout(SourcePropertyWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        wavelength = new QDoubleSpinBox(SourcePropertyWidget);
        wavelength->setObjectName(QStringLiteral("wavelength"));
        wavelength->setButtonSymbols(QAbstractSpinBox::NoButtons);
        wavelength->setDecimals(6);

        gridLayout->addWidget(wavelength, 2, 1, 1, 2);

        label_6 = new QLabel(SourcePropertyWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_4 = new QLabel(SourcePropertyWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        height = new QDoubleSpinBox(SourcePropertyWidget);
        height->setObjectName(QStringLiteral("height"));
        height->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(height, 5, 1, 1, 2);

        label = new QLabel(SourcePropertyWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(SourcePropertyWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        fwhm = new QDoubleSpinBox(SourcePropertyWidget);
        fwhm->setObjectName(QStringLiteral("fwhm"));
        fwhm->setButtonSymbols(QAbstractSpinBox::NoButtons);
        fwhm->setDecimals(6);

        gridLayout->addWidget(fwhm, 3, 1, 1, 2);

        label_3 = new QLabel(SourcePropertyWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        width = new QDoubleSpinBox(SourcePropertyWidget);
        width->setObjectName(QStringLiteral("width"));
        width->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(width, 4, 1, 1, 2);

        label_5 = new QLabel(SourcePropertyWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        source_type = new QComboBox(SourcePropertyWidget);
        source_type->setObjectName(QStringLiteral("source_type"));
        source_type->setEnabled(false);

        gridLayout->addWidget(source_type, 0, 1, 1, 2);

        monochromators = new QComboBox(SourcePropertyWidget);
        monochromators->setObjectName(QStringLiteral("monochromators"));
        monochromators->setEnabled(true);
        monochromators->setEditable(false);

        gridLayout->addWidget(monochromators, 1, 1, 1, 2);


        retranslateUi(SourcePropertyWidget);

        QMetaObject::connectSlotsByName(SourcePropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *SourcePropertyWidget)
    {
        SourcePropertyWidget->setWindowTitle(QApplication::translate("SourcePropertyWidget", "Form", Q_NULLPTR));
        label_6->setText(QApplication::translate("SourcePropertyWidget", "Monochromator:", Q_NULLPTR));
        label_4->setText(QApplication::translate("SourcePropertyWidget", "Height (mm):", Q_NULLPTR));
        label->setText(QApplication::translate("SourcePropertyWidget", "Type:", Q_NULLPTR));
        label_2->setText(QApplication::translate("SourcePropertyWidget", "Wavelength (ang):", Q_NULLPTR));
        label_3->setText(QApplication::translate("SourcePropertyWidget", "Width (mm):", Q_NULLPTR));
        label_5->setText(QApplication::translate("SourcePropertyWidget", "FWHM (ang):", Q_NULLPTR));
        source_type->clear();
        source_type->insertItems(0, QStringList()
         << QApplication::translate("SourcePropertyWidget", "Neutron", Q_NULLPTR)
         << QApplication::translate("SourcePropertyWidget", "X-ray", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class SourcePropertyWidget: public Ui_SourcePropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOURCEPROPERTYWIDGET_H
