/********************************************************************************
** Form generated from reading UI file 'DialogTransformationMatrix.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTRANSFORMATIONMATRIX_H
#define UI_DIALOGTRANSFORMATIONMATRIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogTransformationMatrix
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *P00;
    QDoubleSpinBox *P10;
    QDoubleSpinBox *P20;
    QDoubleSpinBox *P01;
    QDoubleSpinBox *P11;
    QDoubleSpinBox *P21;
    QDoubleSpinBox *P02;
    QDoubleSpinBox *P12;
    QDoubleSpinBox *P22;

    void setupUi(QDialog *DialogTransformationMatrix)
    {
        if (DialogTransformationMatrix->objectName().isEmpty())
            DialogTransformationMatrix->setObjectName(QStringLiteral("DialogTransformationMatrix"));
        DialogTransformationMatrix->resize(348, 263);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogTransformationMatrix->sizePolicy().hasHeightForWidth());
        DialogTransformationMatrix->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(DialogTransformationMatrix);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-20, 200, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox_2 = new QGroupBox(DialogTransformationMatrix);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 20, 271, 171));
        groupBox_2->setStyleSheet(QLatin1String(" QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFFFFF, stop: 1 #DDDDFF);\n"
"     border: 1px solid black;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #DDDDFF, stop: 1 #FFFFFF);\n"
" }"));
        gridLayoutWidget = new QWidget(groupBox_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 248, 101));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        P00 = new QDoubleSpinBox(gridLayoutWidget);
        P00->setObjectName(QStringLiteral("P00"));
        P00->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P00->setDecimals(3);
        P00->setMinimum(-10);
        P00->setMaximum(10);
        P00->setValue(1);

        gridLayout_2->addWidget(P00, 0, 1, 1, 1);

        P10 = new QDoubleSpinBox(gridLayoutWidget);
        P10->setObjectName(QStringLiteral("P10"));
        P10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P10->setDecimals(3);
        P10->setMinimum(-10);
        P10->setMaximum(10);

        gridLayout_2->addWidget(P10, 1, 1, 1, 1);

        P20 = new QDoubleSpinBox(gridLayoutWidget);
        P20->setObjectName(QStringLiteral("P20"));
        P20->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P20->setDecimals(3);
        P20->setMinimum(-10);
        P20->setMaximum(10);

        gridLayout_2->addWidget(P20, 2, 1, 1, 1);

        P01 = new QDoubleSpinBox(gridLayoutWidget);
        P01->setObjectName(QStringLiteral("P01"));
        P01->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P01->setDecimals(3);
        P01->setMinimum(-10);
        P01->setMaximum(10);

        gridLayout_2->addWidget(P01, 0, 2, 1, 1);

        P11 = new QDoubleSpinBox(gridLayoutWidget);
        P11->setObjectName(QStringLiteral("P11"));
        P11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P11->setDecimals(3);
        P11->setMinimum(-10);
        P11->setMaximum(10);
        P11->setValue(1);

        gridLayout_2->addWidget(P11, 1, 2, 1, 1);

        P21 = new QDoubleSpinBox(gridLayoutWidget);
        P21->setObjectName(QStringLiteral("P21"));
        P21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P21->setDecimals(3);
        P21->setMinimum(-10);
        P21->setMaximum(10);

        gridLayout_2->addWidget(P21, 2, 2, 1, 1);

        P02 = new QDoubleSpinBox(gridLayoutWidget);
        P02->setObjectName(QStringLiteral("P02"));
        P02->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P02->setDecimals(3);
        P02->setMinimum(-10);
        P02->setMaximum(10);

        gridLayout_2->addWidget(P02, 0, 3, 1, 1);

        P12 = new QDoubleSpinBox(gridLayoutWidget);
        P12->setObjectName(QStringLiteral("P12"));
        P12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P12->setDecimals(3);
        P12->setMinimum(-10);
        P12->setMaximum(10);

        gridLayout_2->addWidget(P12, 1, 3, 1, 1);

        P22 = new QDoubleSpinBox(gridLayoutWidget);
        P22->setObjectName(QStringLiteral("P22"));
        P22->setButtonSymbols(QAbstractSpinBox::NoButtons);
        P22->setDecimals(3);
        P22->setMinimum(-10);
        P22->setMaximum(10);
        P22->setValue(1);

        gridLayout_2->addWidget(P22, 2, 3, 1, 1);


        retranslateUi(DialogTransformationMatrix);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogTransformationMatrix, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogTransformationMatrix, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogTransformationMatrix);
    } // setupUi

    void retranslateUi(QDialog *DialogTransformationMatrix)
    {
        DialogTransformationMatrix->setWindowTitle(QApplication::translate("DialogTransformationMatrix", "Define transformation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        groupBox_2->setToolTip(QApplication::translate("DialogTransformationMatrix", "<html><head/><body><p>Basis transformation should be given in covariant form,</p><p>i.e. the coordinates of the new cell with respect to the old </p><p>one are given in columns.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("DialogTransformationMatrix", "Transformation matrix", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogTransformationMatrix: public Ui_DialogTransformationMatrix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTRANSFORMATIONMATRIX_H
