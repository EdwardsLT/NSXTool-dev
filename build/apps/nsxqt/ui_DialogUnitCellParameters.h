/********************************************************************************
** Form generated from reading UI file 'DialogUnitCellParameters.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUNITCELLPARAMETERS_H
#define UI_DIALOGUNITCELLPARAMETERS_H

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

QT_BEGIN_NAMESPACE

class Ui_DialogUnitCellParameters
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *labelA;
    QDoubleSpinBox *a;
    QLabel *labelB;
    QDoubleSpinBox *b;
    QLabel *labelC;
    QDoubleSpinBox *c;
    QLabel *labelAlpha;
    QDoubleSpinBox *alpha;
    QLabel *labelBeta;
    QDoubleSpinBox *beta;
    QLabel *labelGamma;
    QDoubleSpinBox *gamma;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogUnitCellParameters)
    {
        if (DialogUnitCellParameters->objectName().isEmpty())
            DialogUnitCellParameters->setObjectName(QStringLiteral("DialogUnitCellParameters"));
        DialogUnitCellParameters->resize(390, 113);
        DialogUnitCellParameters->setMaximumSize(QSize(400, 16777215));
        gridLayout_2 = new QGridLayout(DialogUnitCellParameters);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelA = new QLabel(DialogUnitCellParameters);
        labelA->setObjectName(QStringLiteral("labelA"));

        gridLayout->addWidget(labelA, 0, 0, 1, 1);

        a = new QDoubleSpinBox(DialogUnitCellParameters);
        a->setObjectName(QStringLiteral("a"));
        a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        a->setDecimals(4);
        a->setMaximum(1000);
        a->setValue(1);

        gridLayout->addWidget(a, 0, 1, 1, 1);

        labelB = new QLabel(DialogUnitCellParameters);
        labelB->setObjectName(QStringLiteral("labelB"));

        gridLayout->addWidget(labelB, 0, 2, 1, 1);

        b = new QDoubleSpinBox(DialogUnitCellParameters);
        b->setObjectName(QStringLiteral("b"));
        b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b->setDecimals(4);
        b->setMaximum(1000);
        b->setValue(1);

        gridLayout->addWidget(b, 0, 3, 1, 1);

        labelC = new QLabel(DialogUnitCellParameters);
        labelC->setObjectName(QStringLiteral("labelC"));

        gridLayout->addWidget(labelC, 0, 4, 1, 1);

        c = new QDoubleSpinBox(DialogUnitCellParameters);
        c->setObjectName(QStringLiteral("c"));
        c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        c->setDecimals(4);
        c->setMaximum(1000);
        c->setValue(1);

        gridLayout->addWidget(c, 0, 5, 1, 1);

        labelAlpha = new QLabel(DialogUnitCellParameters);
        labelAlpha->setObjectName(QStringLiteral("labelAlpha"));
        labelAlpha->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(labelAlpha, 1, 0, 1, 1);

        alpha = new QDoubleSpinBox(DialogUnitCellParameters);
        alpha->setObjectName(QStringLiteral("alpha"));
        alpha->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alpha->setDecimals(4);
        alpha->setMaximum(1000);
        alpha->setValue(90);

        gridLayout->addWidget(alpha, 1, 1, 1, 1);

        labelBeta = new QLabel(DialogUnitCellParameters);
        labelBeta->setObjectName(QStringLiteral("labelBeta"));

        gridLayout->addWidget(labelBeta, 1, 2, 1, 1);

        beta = new QDoubleSpinBox(DialogUnitCellParameters);
        beta->setObjectName(QStringLiteral("beta"));
        beta->setButtonSymbols(QAbstractSpinBox::NoButtons);
        beta->setDecimals(4);
        beta->setMaximum(1000);
        beta->setValue(90);

        gridLayout->addWidget(beta, 1, 3, 1, 1);

        labelGamma = new QLabel(DialogUnitCellParameters);
        labelGamma->setObjectName(QStringLiteral("labelGamma"));

        gridLayout->addWidget(labelGamma, 1, 4, 1, 1);

        gamma = new QDoubleSpinBox(DialogUnitCellParameters);
        gamma->setObjectName(QStringLiteral("gamma"));
        gamma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gamma->setDecimals(4);
        gamma->setMaximum(1000);
        gamma->setValue(90);

        gridLayout->addWidget(gamma, 1, 5, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogUnitCellParameters);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(DialogUnitCellParameters);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogUnitCellParameters, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogUnitCellParameters, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogUnitCellParameters);
    } // setupUi

    void retranslateUi(QDialog *DialogUnitCellParameters)
    {
        DialogUnitCellParameters->setWindowTitle(QApplication::translate("DialogUnitCellParameters", "Dialog", Q_NULLPTR));
        labelA->setText(QApplication::translate("DialogUnitCellParameters", "a", Q_NULLPTR));
        labelB->setText(QApplication::translate("DialogUnitCellParameters", "b", Q_NULLPTR));
        labelC->setText(QApplication::translate("DialogUnitCellParameters", "c", Q_NULLPTR));
        labelAlpha->setText(QApplication::translate("DialogUnitCellParameters", "a", Q_NULLPTR));
        labelBeta->setText(QApplication::translate("DialogUnitCellParameters", "a", Q_NULLPTR));
        labelGamma->setText(QApplication::translate("DialogUnitCellParameters", "a", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogUnitCellParameters: public Ui_DialogUnitCellParameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUNITCELLPARAMETERS_H
