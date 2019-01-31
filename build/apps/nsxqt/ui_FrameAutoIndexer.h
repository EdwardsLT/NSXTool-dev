/********************************************************************************
** Form generated from reading UI file 'FrameAutoIndexer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEAUTOINDEXER_H
#define UI_FRAMEAUTOINDEXER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "NSXQFrame.h"
#include "PeakListView.h"

QT_BEGIN_NAMESPACE

class Ui_FrameAutoIndexer
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabs;
    QWidget *settings;
    QVBoxLayout *verticalLayout_2;
    PeakListView *peaks;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QDoubleSpinBox *gruberTolerance;
    QLabel *label;
    QDoubleSpinBox *niggliTolerance;
    QCheckBox *niggli_only;
    QLabel *label_3;
    QDoubleSpinBox *maxCellDim;
    QLabel *label_5;
    QSpinBox *nVertices;
    QLabel *label_4;
    QSpinBox *nSolutions;
    QLabel *label_7;
    QSpinBox *subdiv;
    QLabel *label_8;
    QDoubleSpinBox *cellVolume;
    QLabel *indexingToleranceLabel;
    QDoubleSpinBox *indexingTolerance;
    QTableView *solutions;
    QDialogButtonBox *actions;

    void setupUi(NSXQFrame *FrameAutoIndexer)
    {
        if (FrameAutoIndexer->objectName().isEmpty())
            FrameAutoIndexer->setObjectName(QStringLiteral("FrameAutoIndexer"));
        FrameAutoIndexer->resize(1034, 739);
        FrameAutoIndexer->setFrameShape(QFrame::StyledPanel);
        FrameAutoIndexer->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(FrameAutoIndexer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabs = new QTabWidget(FrameAutoIndexer);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setTabsClosable(true);
        settings = new QWidget();
        settings->setObjectName(QStringLiteral("settings"));
        verticalLayout_2 = new QVBoxLayout(settings);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        peaks = new PeakListView(settings);
        peaks->setObjectName(QStringLiteral("peaks"));

        verticalLayout_2->addWidget(peaks);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(settings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        gruberTolerance = new QDoubleSpinBox(groupBox);
        gruberTolerance->setObjectName(QStringLiteral("gruberTolerance"));
        gruberTolerance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gruberTolerance->setDecimals(6);
        gruberTolerance->setMaximum(1);
        gruberTolerance->setSingleStep(0.0001);
        gruberTolerance->setValue(0.04);

        formLayout->setWidget(0, QFormLayout::FieldRole, gruberTolerance);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        niggliTolerance = new QDoubleSpinBox(groupBox);
        niggliTolerance->setObjectName(QStringLiteral("niggliTolerance"));
        niggliTolerance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        niggliTolerance->setDecimals(4);
        niggliTolerance->setMaximum(1);
        niggliTolerance->setSingleStep(0.0001);
        niggliTolerance->setValue(0.0001);

        formLayout->setWidget(1, QFormLayout::FieldRole, niggliTolerance);

        niggli_only = new QCheckBox(groupBox);
        niggli_only->setObjectName(QStringLiteral("niggli_only"));

        formLayout->setWidget(2, QFormLayout::LabelRole, niggli_only);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        maxCellDim = new QDoubleSpinBox(groupBox);
        maxCellDim->setObjectName(QStringLiteral("maxCellDim"));
        maxCellDim->setButtonSymbols(QAbstractSpinBox::NoButtons);
        maxCellDim->setMaximum(1e+8);
        maxCellDim->setSingleStep(0);
        maxCellDim->setValue(120);

        formLayout->setWidget(3, QFormLayout::FieldRole, maxCellDim);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        nVertices = new QSpinBox(groupBox);
        nVertices->setObjectName(QStringLiteral("nVertices"));
        nVertices->setButtonSymbols(QAbstractSpinBox::NoButtons);
        nVertices->setMaximum(100000);
        nVertices->setValue(1000);

        formLayout->setWidget(4, QFormLayout::FieldRole, nVertices);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        nSolutions = new QSpinBox(groupBox);
        nSolutions->setObjectName(QStringLiteral("nSolutions"));
        nSolutions->setWrapping(true);
        nSolutions->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        nSolutions->setMinimum(1);
        nSolutions->setMaximum(100000);
        nSolutions->setValue(10);

        formLayout->setWidget(5, QFormLayout::FieldRole, nSolutions);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        subdiv = new QSpinBox(groupBox);
        subdiv->setObjectName(QStringLiteral("subdiv"));
        subdiv->setWrapping(true);
        subdiv->setMaximum(999999);

        formLayout->setWidget(6, QFormLayout::FieldRole, subdiv);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        cellVolume = new QDoubleSpinBox(groupBox);
        cellVolume->setObjectName(QStringLiteral("cellVolume"));

        formLayout->setWidget(7, QFormLayout::FieldRole, cellVolume);

        indexingToleranceLabel = new QLabel(groupBox);
        indexingToleranceLabel->setObjectName(QStringLiteral("indexingToleranceLabel"));

        formLayout->setWidget(8, QFormLayout::LabelRole, indexingToleranceLabel);

        indexingTolerance = new QDoubleSpinBox(groupBox);
        indexingTolerance->setObjectName(QStringLiteral("indexingTolerance"));
        indexingTolerance->setDecimals(3);
        indexingTolerance->setMaximum(1);
        indexingTolerance->setSingleStep(0.1);
        indexingTolerance->setValue(0.2);

        formLayout->setWidget(8, QFormLayout::FieldRole, indexingTolerance);


        horizontalLayout->addWidget(groupBox);

        solutions = new QTableView(settings);
        solutions->setObjectName(QStringLiteral("solutions"));
        solutions->setStyleSheet(QLatin1String("QPushButton {\n"
"        border: 1px solid #6593cf;\n"
"        border-radius: 2px;\n"
"        padding: 5px 15px 2px 5px;\n"
"        background: #ffeeee;\n"
"        color: #006aff;\n"
"        font: bold large \"Arial\";\n"
"        height: 30px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #c0dbff,\n"
"        stop :   0.5 #cfd26f, stop :   0.55 #c7df6f, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton:on {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #5AA72D,\n"
"        stop :   0.5 #B3E296, stop :   0.55 #B3E296, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"        background: transparent #e5e9ee;\n"
"        padding-top: 2px;        \n"
"        padding-left: 3px;\n"
"        color: black;\n"
"}"));
        solutions->setEditTriggers(QAbstractItemView::NoEditTriggers);
        solutions->setSelectionMode(QAbstractItemView::SingleSelection);

        horizontalLayout->addWidget(solutions);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        tabs->addTab(settings, QString());

        verticalLayout->addWidget(tabs);

        actions = new QDialogButtonBox(FrameAutoIndexer);
        actions->setObjectName(QStringLiteral("actions"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(actions->sizePolicy().hasHeightForWidth());
        actions->setSizePolicy(sizePolicy);
        actions->setStyleSheet(QStringLiteral(""));
        actions->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Reset);
        actions->setCenterButtons(false);

        verticalLayout->addWidget(actions);


        retranslateUi(FrameAutoIndexer);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrameAutoIndexer);
    } // setupUi

    void retranslateUi(NSXQFrame *FrameAutoIndexer)
    {
        FrameAutoIndexer->setWindowTitle(QApplication::translate("FrameAutoIndexer", "Frame", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FrameAutoIndexer", "Parameters", Q_NULLPTR));
        label_2->setText(QApplication::translate("FrameAutoIndexer", "Gruber tolerance", Q_NULLPTR));
        label->setText(QApplication::translate("FrameAutoIndexer", "Niggli tolerance", Q_NULLPTR));
        niggliTolerance->setPrefix(QString());
        niggli_only->setText(QApplication::translate("FrameAutoIndexer", "Find Niggli cell only", Q_NULLPTR));
        label_3->setText(QApplication::translate("FrameAutoIndexer", "Maximum cell dimension", Q_NULLPTR));
        label_5->setText(QApplication::translate("FrameAutoIndexer", "Number of Q vertices", Q_NULLPTR));
        label_4->setText(QApplication::translate("FrameAutoIndexer", "Number of solutions", Q_NULLPTR));
        label_7->setText(QApplication::translate("FrameAutoIndexer", "Number of subdivisions", Q_NULLPTR));
        label_8->setText(QApplication::translate("FrameAutoIndexer", "Minimum cell volume", Q_NULLPTR));
        indexingToleranceLabel->setText(QApplication::translate("FrameAutoIndexer", "Indexing tolerance", Q_NULLPTR));
        tabs->setTabText(tabs->indexOf(settings), QApplication::translate("FrameAutoIndexer", "settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FrameAutoIndexer: public Ui_FrameAutoIndexer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEAUTOINDEXER_H
