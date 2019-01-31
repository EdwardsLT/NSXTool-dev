/********************************************************************************
** Form generated from reading UI file 'WidgetUnitCell.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETUNITCELL_H
#define UI_WIDGETUNITCELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetUnitCell
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDoubleSpinBox *alpha;
    QLabel *label_beta;
    QLabel *label_b;
    QDoubleSpinBox *beta;
    QLabel *label_c;
    QDoubleSpinBox *a;
    QDoubleSpinBox *b;
    QLabel *label_gamma;
    QDoubleSpinBox *gamma;
    QDoubleSpinBox *c;
    QLabel *label_a;
    QLabel *label_alpha;
    QLabel *label_bravais;
    QLineEdit *bravais;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *b00;
    QDoubleSpinBox *b01;
    QDoubleSpinBox *b02;
    QDoubleSpinBox *b11;
    QDoubleSpinBox *b10;
    QDoubleSpinBox *b20;
    QDoubleSpinBox *b12;
    QDoubleSpinBox *b21;
    QDoubleSpinBox *b22;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *u01;
    QDoubleSpinBox *u10;
    QDoubleSpinBox *u02;
    QDoubleSpinBox *u12;
    QDoubleSpinBox *u00;
    QDoubleSpinBox *u11;
    QDoubleSpinBox *u20;
    QDoubleSpinBox *u21;
    QDoubleSpinBox *u22;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WidgetUnitCell)
    {
        if (WidgetUnitCell->objectName().isEmpty())
            WidgetUnitCell->setObjectName(QStringLiteral("WidgetUnitCell"));
        WidgetUnitCell->resize(789, 359);
        verticalLayout = new QVBoxLayout(WidgetUnitCell);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(WidgetUnitCell);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        alpha = new QDoubleSpinBox(groupBox);
        alpha->setObjectName(QStringLiteral("alpha"));
        alpha->setReadOnly(true);
        alpha->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alpha->setDecimals(3);
        alpha->setMinimum(-180);
        alpha->setMaximum(180);

        gridLayout->addWidget(alpha, 2, 1, 1, 1);

        label_beta = new QLabel(groupBox);
        label_beta->setObjectName(QStringLiteral("label_beta"));

        gridLayout->addWidget(label_beta, 2, 2, 1, 1);

        label_b = new QLabel(groupBox);
        label_b->setObjectName(QStringLiteral("label_b"));

        gridLayout->addWidget(label_b, 1, 2, 1, 1);

        beta = new QDoubleSpinBox(groupBox);
        beta->setObjectName(QStringLiteral("beta"));
        beta->setReadOnly(true);
        beta->setButtonSymbols(QAbstractSpinBox::NoButtons);
        beta->setDecimals(3);
        beta->setMinimum(-180);
        beta->setMaximum(180);

        gridLayout->addWidget(beta, 2, 3, 1, 1);

        label_c = new QLabel(groupBox);
        label_c->setObjectName(QStringLiteral("label_c"));

        gridLayout->addWidget(label_c, 1, 4, 1, 1);

        a = new QDoubleSpinBox(groupBox);
        a->setObjectName(QStringLiteral("a"));
        a->setReadOnly(true);
        a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        a->setDecimals(3);
        a->setMaximum(1e+6);

        gridLayout->addWidget(a, 1, 1, 1, 1);

        b = new QDoubleSpinBox(groupBox);
        b->setObjectName(QStringLiteral("b"));
        b->setReadOnly(true);
        b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b->setDecimals(3);
        b->setMaximum(1e+6);

        gridLayout->addWidget(b, 1, 3, 1, 1);

        label_gamma = new QLabel(groupBox);
        label_gamma->setObjectName(QStringLiteral("label_gamma"));

        gridLayout->addWidget(label_gamma, 2, 4, 1, 1);

        gamma = new QDoubleSpinBox(groupBox);
        gamma->setObjectName(QStringLiteral("gamma"));
        gamma->setReadOnly(true);
        gamma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gamma->setDecimals(3);
        gamma->setMinimum(-180);
        gamma->setMaximum(180);

        gridLayout->addWidget(gamma, 2, 5, 1, 1);

        c = new QDoubleSpinBox(groupBox);
        c->setObjectName(QStringLiteral("c"));
        c->setReadOnly(true);
        c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        c->setDecimals(3);
        c->setMaximum(1e+6);

        gridLayout->addWidget(c, 1, 5, 1, 1);

        label_a = new QLabel(groupBox);
        label_a->setObjectName(QStringLiteral("label_a"));

        gridLayout->addWidget(label_a, 1, 0, 1, 1);

        label_alpha = new QLabel(groupBox);
        label_alpha->setObjectName(QStringLiteral("label_alpha"));

        gridLayout->addWidget(label_alpha, 2, 0, 1, 1);

        label_bravais = new QLabel(groupBox);
        label_bravais->setObjectName(QStringLiteral("label_bravais"));

        gridLayout->addWidget(label_bravais, 0, 0, 1, 1);

        bravais = new QLineEdit(groupBox);
        bravais->setObjectName(QStringLiteral("bravais"));
        bravais->setReadOnly(true);

        gridLayout->addWidget(bravais, 0, 1, 1, 1);


        horizontalLayout_3->addWidget(groupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_2 = new QGroupBox(WidgetUnitCell);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        b00 = new QDoubleSpinBox(groupBox_2);
        b00->setObjectName(QStringLiteral("b00"));
        b00->setReadOnly(true);
        b00->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b00->setDecimals(5);
        b00->setMaximum(10000);

        gridLayout_2->addWidget(b00, 0, 0, 1, 1);

        b01 = new QDoubleSpinBox(groupBox_2);
        b01->setObjectName(QStringLiteral("b01"));
        b01->setReadOnly(true);
        b01->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b01->setDecimals(5);
        b01->setMaximum(10000);

        gridLayout_2->addWidget(b01, 0, 1, 1, 1);

        b02 = new QDoubleSpinBox(groupBox_2);
        b02->setObjectName(QStringLiteral("b02"));
        b02->setReadOnly(true);
        b02->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b02->setDecimals(5);
        b02->setMaximum(10000);

        gridLayout_2->addWidget(b02, 0, 2, 1, 1);

        b11 = new QDoubleSpinBox(groupBox_2);
        b11->setObjectName(QStringLiteral("b11"));
        b11->setReadOnly(true);
        b11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b11->setDecimals(5);
        b11->setMaximum(10000);

        gridLayout_2->addWidget(b11, 1, 1, 1, 1);

        b10 = new QDoubleSpinBox(groupBox_2);
        b10->setObjectName(QStringLiteral("b10"));
        b10->setReadOnly(true);
        b10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b10->setDecimals(5);
        b10->setMaximum(10000);

        gridLayout_2->addWidget(b10, 1, 0, 1, 1);

        b20 = new QDoubleSpinBox(groupBox_2);
        b20->setObjectName(QStringLiteral("b20"));
        b20->setReadOnly(true);
        b20->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b20->setDecimals(5);
        b20->setMaximum(10000);

        gridLayout_2->addWidget(b20, 2, 0, 1, 1);

        b12 = new QDoubleSpinBox(groupBox_2);
        b12->setObjectName(QStringLiteral("b12"));
        b12->setReadOnly(true);
        b12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b12->setDecimals(5);
        b12->setMaximum(10000);

        gridLayout_2->addWidget(b12, 1, 2, 1, 1);

        b21 = new QDoubleSpinBox(groupBox_2);
        b21->setObjectName(QStringLiteral("b21"));
        b21->setReadOnly(true);
        b21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b21->setDecimals(5);
        b21->setMaximum(10000);

        gridLayout_2->addWidget(b21, 2, 1, 1, 1);

        b22 = new QDoubleSpinBox(groupBox_2);
        b22->setObjectName(QStringLiteral("b22"));
        b22->setReadOnly(true);
        b22->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b22->setDecimals(5);
        b22->setMaximum(10000);

        gridLayout_2->addWidget(b22, 2, 2, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(WidgetUnitCell);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        u01 = new QDoubleSpinBox(groupBox_3);
        u01->setObjectName(QStringLiteral("u01"));
        u01->setReadOnly(true);
        u01->setButtonSymbols(QAbstractSpinBox::NoButtons);
        u01->setDecimals(5);
        u01->setMinimum(-180);
        u01->setMaximum(180);

        gridLayout_3->addWidget(u01, 0, 1, 1, 1);

        u10 = new QDoubleSpinBox(groupBox_3);
        u10->setObjectName(QStringLiteral("u10"));
        u10->setReadOnly(true);
        u10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        u10->setDecimals(5);
        u10->setMinimum(-180);
        u10->setMaximum(180);

        gridLayout_3->addWidget(u10, 1, 0, 1, 1);

        u02 = new QDoubleSpinBox(groupBox_3);
        u02->setObjectName(QStringLiteral("u02"));
        u02->setReadOnly(true);
        u02->setButtonSymbols(QAbstractSpinBox::NoButtons);
        u02->setDecimals(5);
        u02->setMinimum(-180);
        u02->setMaximum(180);

        gridLayout_3->addWidget(u02, 0, 2, 1, 1);

        u12 = new QDoubleSpinBox(groupBox_3);
        u12->setObjectName(QStringLiteral("u12"));
        u12->setReadOnly(true);
        u12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        u12->setDecimals(5);
        u12->setMinimum(-180);
        u12->setMaximum(180);

        gridLayout_3->addWidget(u12, 1, 2, 1, 1);

        u00 = new QDoubleSpinBox(groupBox_3);
        u00->setObjectName(QStringLiteral("u00"));
        u00->setReadOnly(true);
        u00->setButtonSymbols(QAbstractSpinBox::NoButtons);
        u00->setDecimals(5);
        u00->setMinimum(-180);
        u00->setMaximum(180);

        gridLayout_3->addWidget(u00, 0, 0, 1, 1);

        u11 = new QDoubleSpinBox(groupBox_3);
        u11->setObjectName(QStringLiteral("u11"));
        u11->setReadOnly(true);
        u11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        u11->setDecimals(5);
        u11->setMinimum(-180);
        u11->setMaximum(180);

        gridLayout_3->addWidget(u11, 1, 1, 1, 1);

        u20 = new QDoubleSpinBox(groupBox_3);
        u20->setObjectName(QStringLiteral("u20"));
        u20->setReadOnly(true);
        u20->setButtonSymbols(QAbstractSpinBox::NoButtons);
        u20->setDecimals(5);
        u20->setMinimum(-180);
        u20->setMaximum(180);

        gridLayout_3->addWidget(u20, 2, 0, 1, 1);

        u21 = new QDoubleSpinBox(groupBox_3);
        u21->setObjectName(QStringLiteral("u21"));
        u21->setReadOnly(true);
        u21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        u21->setDecimals(5);
        u21->setMinimum(-180);
        u21->setMaximum(180);

        gridLayout_3->addWidget(u21, 2, 1, 1, 1);

        u22 = new QDoubleSpinBox(groupBox_3);
        u22->setObjectName(QStringLiteral("u22"));
        u22->setReadOnly(true);
        u22->setButtonSymbols(QAbstractSpinBox::NoButtons);
        u22->setDecimals(5);
        u22->setMinimum(-180);
        u22->setMaximum(180);

        gridLayout_3->addWidget(u22, 2, 2, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(WidgetUnitCell);

        QMetaObject::connectSlotsByName(WidgetUnitCell);
    } // setupUi

    void retranslateUi(QWidget *WidgetUnitCell)
    {
        WidgetUnitCell->setWindowTitle(QApplication::translate("WidgetUnitCell", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("WidgetUnitCell", "Unit cell parameters", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        alpha->setToolTip(QApplication::translate("WidgetUnitCell", "<html><head/><body><p>The \\u03B1 angle (in \\u00B0)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_beta->setText(QApplication::translate("WidgetUnitCell", "beta", Q_NULLPTR));
        label_b->setText(QApplication::translate("WidgetUnitCell", "b", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        beta->setToolTip(QApplication::translate("WidgetUnitCell", "<html><head/><body><p>The \\u03B2 angle (in \\u00B0)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_c->setText(QApplication::translate("WidgetUnitCell", "b", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        a->setToolTip(QApplication::translate("WidgetUnitCell", "<html><head/><body><p>The a axis length (in \\u212B)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        b->setToolTip(QApplication::translate("WidgetUnitCell", "<html><head/><body><p>The b axis length (in \\u212B)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_gamma->setText(QApplication::translate("WidgetUnitCell", "gamma", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gamma->setToolTip(QApplication::translate("WidgetUnitCell", "<html><head/><body><p>The \\u03B3 angle (in \\u00B0)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        c->setToolTip(QApplication::translate("WidgetUnitCell", "<html><head/><body><p>The c axis length (in \\u212B)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_a->setText(QApplication::translate("WidgetUnitCell", "a", Q_NULLPTR));
        label_alpha->setText(QApplication::translate("WidgetUnitCell", "alpha", Q_NULLPTR));
        label_bravais->setText(QApplication::translate("WidgetUnitCell", "Bravais type", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        bravais->setToolTip(QApplication::translate("WidgetUnitCell", "<html><head/><body><p>The Bravais type found after Gruber reduction</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("WidgetUnitCell", "B matrix (row form)", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("WidgetUnitCell", "U matrix (row form)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetUnitCell: public Ui_WidgetUnitCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETUNITCELL_H
