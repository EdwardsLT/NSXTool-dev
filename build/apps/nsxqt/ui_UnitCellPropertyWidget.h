/********************************************************************************
** Form generated from reading UI file 'UnitCellPropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITCELLPROPERTYWIDGET_H
#define UI_UNITCELLPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnitCellPropertyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *name;
    QLabel *label_3;
    QComboBox *spaceGroup;
    QLabel *label_2;
    QLineEdit *chemicalFormula;
    QLabel *label;
    QSpinBox *z;
    QLabel *label_4;
    QDoubleSpinBox *indexingTolerance;
    QSpacerItem *horizontalSpacer;
    QGroupBox *cellParameters;
    QGridLayout *gridLayout;
    QLabel *labelbeta;
    QDoubleSpinBox *a;
    QDoubleSpinBox *beta;
    QLabel *labelgamma;
    QDoubleSpinBox *alpha;
    QLabel *labelc;
    QDoubleSpinBox *b;
    QDoubleSpinBox *gamma;
    QLabel *labelb;
    QLabel *labelalpha;
    QLabel *labela;
    QDoubleSpinBox *c;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *UnitCellPropertyWidget)
    {
        if (UnitCellPropertyWidget->objectName().isEmpty())
            UnitCellPropertyWidget->setObjectName(QStringLiteral("UnitCellPropertyWidget"));
        UnitCellPropertyWidget->resize(522, 295);
        verticalLayout = new QVBoxLayout(UnitCellPropertyWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_5 = new QLabel(UnitCellPropertyWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        name = new QLineEdit(UnitCellPropertyWidget);
        name->setObjectName(QStringLiteral("name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, name);

        label_3 = new QLabel(UnitCellPropertyWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        spaceGroup = new QComboBox(UnitCellPropertyWidget);
        spaceGroup->setObjectName(QStringLiteral("spaceGroup"));
        spaceGroup->setEditable(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, spaceGroup);

        label_2 = new QLabel(UnitCellPropertyWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        chemicalFormula = new QLineEdit(UnitCellPropertyWidget);
        chemicalFormula->setObjectName(QStringLiteral("chemicalFormula"));

        formLayout->setWidget(2, QFormLayout::FieldRole, chemicalFormula);

        label = new QLabel(UnitCellPropertyWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        z = new QSpinBox(UnitCellPropertyWidget);
        z->setObjectName(QStringLiteral("z"));
        z->setMaximum(100000);
        z->setValue(1);

        formLayout->setWidget(3, QFormLayout::FieldRole, z);

        label_4 = new QLabel(UnitCellPropertyWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        indexingTolerance = new QDoubleSpinBox(UnitCellPropertyWidget);
        indexingTolerance->setObjectName(QStringLiteral("indexingTolerance"));
        indexingTolerance->setMaximum(1);
        indexingTolerance->setSingleStep(0.01);
        indexingTolerance->setValue(0.2);

        formLayout->setWidget(4, QFormLayout::FieldRole, indexingTolerance);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        cellParameters = new QGroupBox(UnitCellPropertyWidget);
        cellParameters->setObjectName(QStringLiteral("cellParameters"));
        cellParameters->setFlat(false);
        gridLayout = new QGridLayout(cellParameters);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelbeta = new QLabel(cellParameters);
        labelbeta->setObjectName(QStringLiteral("labelbeta"));

        gridLayout->addWidget(labelbeta, 1, 3, 1, 1);

        a = new QDoubleSpinBox(cellParameters);
        a->setObjectName(QStringLiteral("a"));
        a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        a->setDecimals(4);
        a->setMaximum(1000);
        a->setValue(1);

        gridLayout->addWidget(a, 0, 2, 1, 1);

        beta = new QDoubleSpinBox(cellParameters);
        beta->setObjectName(QStringLiteral("beta"));
        beta->setButtonSymbols(QAbstractSpinBox::NoButtons);
        beta->setDecimals(4);
        beta->setMaximum(1000);
        beta->setValue(90);

        gridLayout->addWidget(beta, 1, 4, 1, 1);

        labelgamma = new QLabel(cellParameters);
        labelgamma->setObjectName(QStringLiteral("labelgamma"));

        gridLayout->addWidget(labelgamma, 1, 5, 1, 1);

        alpha = new QDoubleSpinBox(cellParameters);
        alpha->setObjectName(QStringLiteral("alpha"));
        alpha->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alpha->setDecimals(4);
        alpha->setMaximum(1000);
        alpha->setValue(90);

        gridLayout->addWidget(alpha, 1, 2, 1, 1);

        labelc = new QLabel(cellParameters);
        labelc->setObjectName(QStringLiteral("labelc"));

        gridLayout->addWidget(labelc, 0, 5, 1, 1);

        b = new QDoubleSpinBox(cellParameters);
        b->setObjectName(QStringLiteral("b"));
        b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b->setDecimals(4);
        b->setMaximum(1000);
        b->setValue(1);

        gridLayout->addWidget(b, 0, 4, 1, 1);

        gamma = new QDoubleSpinBox(cellParameters);
        gamma->setObjectName(QStringLiteral("gamma"));
        gamma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gamma->setDecimals(4);
        gamma->setMaximum(1000);
        gamma->setValue(90);

        gridLayout->addWidget(gamma, 1, 6, 1, 1);

        labelb = new QLabel(cellParameters);
        labelb->setObjectName(QStringLiteral("labelb"));

        gridLayout->addWidget(labelb, 0, 3, 1, 1);

        labelalpha = new QLabel(cellParameters);
        labelalpha->setObjectName(QStringLiteral("labelalpha"));
        labelalpha->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(labelalpha, 1, 0, 1, 1);

        labela = new QLabel(cellParameters);
        labela->setObjectName(QStringLiteral("labela"));

        gridLayout->addWidget(labela, 0, 0, 1, 1);

        c = new QDoubleSpinBox(cellParameters);
        c->setObjectName(QStringLiteral("c"));
        c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        c->setDecimals(4);
        c->setMaximum(1000);
        c->setValue(1);

        gridLayout->addWidget(c, 0, 6, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 7, 1, 1);


        verticalLayout->addWidget(cellParameters);

        QWidget::setTabOrder(a, b);
        QWidget::setTabOrder(b, c);
        QWidget::setTabOrder(c, alpha);
        QWidget::setTabOrder(alpha, beta);
        QWidget::setTabOrder(beta, gamma);

        retranslateUi(UnitCellPropertyWidget);

        QMetaObject::connectSlotsByName(UnitCellPropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *UnitCellPropertyWidget)
    {
        UnitCellPropertyWidget->setWindowTitle(QApplication::translate("UnitCellPropertyWidget", "Form", Q_NULLPTR));
        label_5->setText(QApplication::translate("UnitCellPropertyWidget", "Name", Q_NULLPTR));
        label_3->setText(QApplication::translate("UnitCellPropertyWidget", "Spacegroup", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spaceGroup->setToolTip(QApplication::translate("UnitCellPropertyWidget", "<html><head/><body><p>Enter or select space group and </p><p>press Enter to validate your choice</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("UnitCellPropertyWidget", "Chemical Formula ", Q_NULLPTR));
        label->setText(QApplication::translate("UnitCellPropertyWidget", "Z ", Q_NULLPTR));
        label_4->setText(QApplication::translate("UnitCellPropertyWidget", "Indexing tolerance", Q_NULLPTR));
        cellParameters->setTitle(QApplication::translate("UnitCellPropertyWidget", "Cell parameters", Q_NULLPTR));
        labelbeta->setText(QApplication::translate("UnitCellPropertyWidget", "a", Q_NULLPTR));
        labelgamma->setText(QApplication::translate("UnitCellPropertyWidget", "a", Q_NULLPTR));
        labelc->setText(QApplication::translate("UnitCellPropertyWidget", "c", Q_NULLPTR));
        labelb->setText(QApplication::translate("UnitCellPropertyWidget", "b", Q_NULLPTR));
        labelalpha->setText(QApplication::translate("UnitCellPropertyWidget", "a", Q_NULLPTR));
        labela->setText(QApplication::translate("UnitCellPropertyWidget", "a", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UnitCellPropertyWidget: public Ui_UnitCellPropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITCELLPROPERTYWIDGET_H
