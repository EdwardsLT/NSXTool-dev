/********************************************************************************
** Form generated from reading UI file 'FrameSampleGlobalOffsets.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMESAMPLEGLOBALOFFSETS_H
#define UI_FRAMESAMPLEGLOBALOFFSETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include "NSXQFrame.h"
#include "ScientificNotationSpinBox.h"
#include "plot/SXPlot.h"

QT_BEGIN_NAMESPACE

class Ui_FrameSampleGlobalOffsets
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *selected_data;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *n_iterations;
    QLabel *label_2;
    ScientificNotationSpinBox *tolerance;
    QTableWidget *offsets;
    SXPlot *plot;
    QDialogButtonBox *actions;

    void setupUi(NSXQFrame *FrameSampleGlobalOffsets)
    {
        if (FrameSampleGlobalOffsets->objectName().isEmpty())
            FrameSampleGlobalOffsets->setObjectName(QStringLiteral("FrameSampleGlobalOffsets"));
        FrameSampleGlobalOffsets->resize(925, 529);
        FrameSampleGlobalOffsets->setMinimumSize(QSize(600, 300));
        FrameSampleGlobalOffsets->setFrameShape(QFrame::StyledPanel);
        FrameSampleGlobalOffsets->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(FrameSampleGlobalOffsets);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        selected_data = new QListWidget(FrameSampleGlobalOffsets);
        selected_data->setObjectName(QStringLiteral("selected_data"));

        verticalLayout->addWidget(selected_data);

        groupBox = new QGroupBox(FrameSampleGlobalOffsets);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        n_iterations = new QSpinBox(groupBox);
        n_iterations->setObjectName(QStringLiteral("n_iterations"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(n_iterations->sizePolicy().hasHeightForWidth());
        n_iterations->setSizePolicy(sizePolicy);
        n_iterations->setWrapping(true);
        n_iterations->setMinimum(1);
        n_iterations->setMaximum(1000000);
        n_iterations->setValue(1000);

        formLayout->setWidget(1, QFormLayout::FieldRole, n_iterations);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        tolerance = new ScientificNotationSpinBox(groupBox);
        tolerance->setObjectName(QStringLiteral("tolerance"));
        tolerance->setWrapping(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, tolerance);


        verticalLayout->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout);

        offsets = new QTableWidget(FrameSampleGlobalOffsets);
        if (offsets->columnCount() < 2)
            offsets->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        offsets->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        offsets->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        offsets->setObjectName(QStringLiteral("offsets"));
        offsets->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(offsets);


        verticalLayout_2->addLayout(horizontalLayout);

        plot = new SXPlot(FrameSampleGlobalOffsets);
        plot->setObjectName(QStringLiteral("plot"));

        verticalLayout_2->addWidget(plot);

        actions = new QDialogButtonBox(FrameSampleGlobalOffsets);
        actions->setObjectName(QStringLiteral("actions"));
        actions->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(actions);

        verticalLayout_2->setStretch(1, 1);

        retranslateUi(FrameSampleGlobalOffsets);

        QMetaObject::connectSlotsByName(FrameSampleGlobalOffsets);
    } // setupUi

    void retranslateUi(NSXQFrame *FrameSampleGlobalOffsets)
    {
        FrameSampleGlobalOffsets->setWindowTitle(QApplication::translate("FrameSampleGlobalOffsets", "Frame", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FrameSampleGlobalOffsets", "Fit parameters", Q_NULLPTR));
        label->setText(QApplication::translate("FrameSampleGlobalOffsets", "# iterations", Q_NULLPTR));
        label_2->setText(QApplication::translate("FrameSampleGlobalOffsets", "tolerance", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = offsets->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FrameSampleGlobalOffsets", "Axis", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = offsets->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FrameSampleGlobalOffsets", "Offset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FrameSampleGlobalOffsets: public Ui_FrameSampleGlobalOffsets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMESAMPLEGLOBALOFFSETS_H
