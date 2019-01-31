/********************************************************************************
** Form generated from reading UI file 'FrameInstrumentStates.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEINSTRUMENTSTATES_H
#define UI_FRAMEINSTRUMENTSTATES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "NSXQFrame.h"

QT_BEGIN_NAMESPACE

class Ui_FrameInstrumentStates
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QListWidget *data;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *frameIndex;
    QSlider *frameSlider;
    QVBoxLayout *verticalLayout_2;
    QLabel *refined;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *sample_position_x;
    QDoubleSpinBox *sample_position_y;
    QDoubleSpinBox *sample_position_z;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QDoubleSpinBox *sample_orientation_10;
    QDoubleSpinBox *sample_orientation_00;
    QDoubleSpinBox *sample_orientation_21;
    QDoubleSpinBox *sample_orientation_22;
    QDoubleSpinBox *sample_orientation_11;
    QDoubleSpinBox *sample_orientation_20;
    QDoubleSpinBox *sample_orientation_12;
    QDoubleSpinBox *sample_orientation_01;
    QDoubleSpinBox *sample_orientation_02;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *sample_orientation_offset_10;
    QDoubleSpinBox *sample_orientation_offset_02;
    QDoubleSpinBox *sample_orientation_offset_21;
    QDoubleSpinBox *sample_orientation_offset_11;
    QDoubleSpinBox *sample_orientation_offset_20;
    QDoubleSpinBox *sample_orientation_offset_22;
    QDoubleSpinBox *sample_orientation_offset_00;
    QDoubleSpinBox *sample_orientation_offset_12;
    QDoubleSpinBox *sample_orientation_offset_01;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *detector_orientation_00;
    QDoubleSpinBox *detector_orientation_01;
    QDoubleSpinBox *detector_orientation_02;
    QDoubleSpinBox *detector_orientation_10;
    QDoubleSpinBox *detector_orientation_11;
    QDoubleSpinBox *detector_orientation_12;
    QDoubleSpinBox *detector_orientation_20;
    QDoubleSpinBox *detector_orientation_21;
    QDoubleSpinBox *detector_orientation_22;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *ni_x;
    QDoubleSpinBox *ni_y;
    QDoubleSpinBox *ni_z;
    QDialogButtonBox *actions;

    void setupUi(NSXQFrame *FrameInstrumentStates)
    {
        if (FrameInstrumentStates->objectName().isEmpty())
            FrameInstrumentStates->setObjectName(QStringLiteral("FrameInstrumentStates"));
        FrameInstrumentStates->resize(815, 647);
        FrameInstrumentStates->setFrameShape(QFrame::StyledPanel);
        FrameInstrumentStates->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FrameInstrumentStates);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        data = new QListWidget(FrameInstrumentStates);
        data->setObjectName(QStringLiteral("data"));

        verticalLayout->addWidget(data);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(FrameInstrumentStates);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        frameIndex = new QSpinBox(FrameInstrumentStates);
        frameIndex->setObjectName(QStringLiteral("frameIndex"));
        frameIndex->setReadOnly(false);
        frameIndex->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        frameIndex->setSingleStep(1);

        horizontalLayout->addWidget(frameIndex);

        frameSlider = new QSlider(FrameInstrumentStates);
        frameSlider->setObjectName(QStringLiteral("frameSlider"));
        frameSlider->setTracking(true);
        frameSlider->setOrientation(Qt::Horizontal);
        frameSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout->addWidget(frameSlider);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        refined = new QLabel(FrameInstrumentStates);
        refined->setObjectName(QStringLiteral("refined"));

        verticalLayout_2->addWidget(refined);

        groupBox = new QGroupBox(FrameInstrumentStates);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sample_position_x = new QDoubleSpinBox(groupBox);
        sample_position_x->setObjectName(QStringLiteral("sample_position_x"));
        sample_position_x->setReadOnly(true);
        sample_position_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_position_x->setDecimals(6);
        sample_position_x->setMinimum(-1e+6);
        sample_position_x->setMaximum(1e+6);

        horizontalLayout_2->addWidget(sample_position_x);

        sample_position_y = new QDoubleSpinBox(groupBox);
        sample_position_y->setObjectName(QStringLiteral("sample_position_y"));
        sample_position_y->setReadOnly(true);
        sample_position_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_position_y->setDecimals(6);
        sample_position_y->setMinimum(-1e+6);
        sample_position_y->setMaximum(1e+6);

        horizontalLayout_2->addWidget(sample_position_y);

        sample_position_z = new QDoubleSpinBox(groupBox);
        sample_position_z->setObjectName(QStringLiteral("sample_position_z"));
        sample_position_z->setReadOnly(true);
        sample_position_z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_position_z->setDecimals(6);
        sample_position_z->setMinimum(-1e+6);
        sample_position_z->setMaximum(1e+6);

        horizontalLayout_2->addWidget(sample_position_z);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(FrameInstrumentStates);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sample_orientation_10 = new QDoubleSpinBox(groupBox_2);
        sample_orientation_10->setObjectName(QStringLiteral("sample_orientation_10"));
        sample_orientation_10->setReadOnly(true);
        sample_orientation_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_10->setDecimals(6);
        sample_orientation_10->setMinimum(-1e+6);
        sample_orientation_10->setMaximum(1e+6);

        gridLayout->addWidget(sample_orientation_10, 1, 0, 1, 1);

        sample_orientation_00 = new QDoubleSpinBox(groupBox_2);
        sample_orientation_00->setObjectName(QStringLiteral("sample_orientation_00"));
        sample_orientation_00->setEnabled(true);
        sample_orientation_00->setReadOnly(true);
        sample_orientation_00->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_00->setDecimals(6);
        sample_orientation_00->setMinimum(-1e+6);
        sample_orientation_00->setMaximum(1e+6);

        gridLayout->addWidget(sample_orientation_00, 0, 0, 1, 1);

        sample_orientation_21 = new QDoubleSpinBox(groupBox_2);
        sample_orientation_21->setObjectName(QStringLiteral("sample_orientation_21"));
        sample_orientation_21->setReadOnly(true);
        sample_orientation_21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_21->setDecimals(6);
        sample_orientation_21->setMinimum(-1e+6);
        sample_orientation_21->setMaximum(1e+6);

        gridLayout->addWidget(sample_orientation_21, 2, 1, 1, 1);

        sample_orientation_22 = new QDoubleSpinBox(groupBox_2);
        sample_orientation_22->setObjectName(QStringLiteral("sample_orientation_22"));
        sample_orientation_22->setReadOnly(true);
        sample_orientation_22->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_22->setDecimals(6);
        sample_orientation_22->setMinimum(-1e+6);
        sample_orientation_22->setMaximum(1e+6);

        gridLayout->addWidget(sample_orientation_22, 2, 2, 1, 1);

        sample_orientation_11 = new QDoubleSpinBox(groupBox_2);
        sample_orientation_11->setObjectName(QStringLiteral("sample_orientation_11"));
        sample_orientation_11->setReadOnly(true);
        sample_orientation_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_11->setDecimals(6);
        sample_orientation_11->setMinimum(-1e+6);
        sample_orientation_11->setMaximum(1e+6);

        gridLayout->addWidget(sample_orientation_11, 1, 1, 1, 1);

        sample_orientation_20 = new QDoubleSpinBox(groupBox_2);
        sample_orientation_20->setObjectName(QStringLiteral("sample_orientation_20"));
        sample_orientation_20->setReadOnly(true);
        sample_orientation_20->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_20->setDecimals(6);
        sample_orientation_20->setMinimum(-1e+6);
        sample_orientation_20->setMaximum(1e+6);

        gridLayout->addWidget(sample_orientation_20, 2, 0, 1, 1);

        sample_orientation_12 = new QDoubleSpinBox(groupBox_2);
        sample_orientation_12->setObjectName(QStringLiteral("sample_orientation_12"));
        sample_orientation_12->setReadOnly(true);
        sample_orientation_12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_12->setDecimals(6);
        sample_orientation_12->setMinimum(-1e+6);
        sample_orientation_12->setMaximum(1e+6);

        gridLayout->addWidget(sample_orientation_12, 1, 2, 1, 1);

        sample_orientation_01 = new QDoubleSpinBox(groupBox_2);
        sample_orientation_01->setObjectName(QStringLiteral("sample_orientation_01"));
        sample_orientation_01->setReadOnly(true);
        sample_orientation_01->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_01->setDecimals(6);
        sample_orientation_01->setMinimum(-1e+6);
        sample_orientation_01->setMaximum(1e+6);

        gridLayout->addWidget(sample_orientation_01, 0, 1, 1, 1);

        sample_orientation_02 = new QDoubleSpinBox(groupBox_2);
        sample_orientation_02->setObjectName(QStringLiteral("sample_orientation_02"));
        sample_orientation_02->setReadOnly(true);
        sample_orientation_02->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_02->setDecimals(6);
        sample_orientation_02->setMinimum(-1e+6);
        sample_orientation_02->setMaximum(1e+6);

        gridLayout->addWidget(sample_orientation_02, 0, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(FrameInstrumentStates);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        sample_orientation_offset_10 = new QDoubleSpinBox(groupBox_3);
        sample_orientation_offset_10->setObjectName(QStringLiteral("sample_orientation_offset_10"));
        sample_orientation_offset_10->setReadOnly(true);
        sample_orientation_offset_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_offset_10->setDecimals(6);
        sample_orientation_offset_10->setMinimum(-1e+6);
        sample_orientation_offset_10->setMaximum(1e+6);

        gridLayout_3->addWidget(sample_orientation_offset_10, 1, 0, 1, 1);

        sample_orientation_offset_02 = new QDoubleSpinBox(groupBox_3);
        sample_orientation_offset_02->setObjectName(QStringLiteral("sample_orientation_offset_02"));
        sample_orientation_offset_02->setReadOnly(true);
        sample_orientation_offset_02->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_offset_02->setDecimals(6);
        sample_orientation_offset_02->setMinimum(-1e+6);
        sample_orientation_offset_02->setMaximum(1e+6);

        gridLayout_3->addWidget(sample_orientation_offset_02, 0, 2, 1, 1);

        sample_orientation_offset_21 = new QDoubleSpinBox(groupBox_3);
        sample_orientation_offset_21->setObjectName(QStringLiteral("sample_orientation_offset_21"));
        sample_orientation_offset_21->setReadOnly(true);
        sample_orientation_offset_21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_offset_21->setDecimals(6);
        sample_orientation_offset_21->setMinimum(-1e+6);
        sample_orientation_offset_21->setMaximum(1e+6);

        gridLayout_3->addWidget(sample_orientation_offset_21, 2, 1, 1, 1);

        sample_orientation_offset_11 = new QDoubleSpinBox(groupBox_3);
        sample_orientation_offset_11->setObjectName(QStringLiteral("sample_orientation_offset_11"));
        sample_orientation_offset_11->setReadOnly(true);
        sample_orientation_offset_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_offset_11->setDecimals(6);
        sample_orientation_offset_11->setMinimum(-1e+6);
        sample_orientation_offset_11->setMaximum(1e+6);

        gridLayout_3->addWidget(sample_orientation_offset_11, 1, 1, 1, 1);

        sample_orientation_offset_20 = new QDoubleSpinBox(groupBox_3);
        sample_orientation_offset_20->setObjectName(QStringLiteral("sample_orientation_offset_20"));
        sample_orientation_offset_20->setReadOnly(true);
        sample_orientation_offset_20->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_offset_20->setDecimals(6);
        sample_orientation_offset_20->setMinimum(-1e+6);
        sample_orientation_offset_20->setMaximum(1e+6);

        gridLayout_3->addWidget(sample_orientation_offset_20, 2, 0, 1, 1);

        sample_orientation_offset_22 = new QDoubleSpinBox(groupBox_3);
        sample_orientation_offset_22->setObjectName(QStringLiteral("sample_orientation_offset_22"));
        sample_orientation_offset_22->setReadOnly(true);
        sample_orientation_offset_22->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_offset_22->setDecimals(6);
        sample_orientation_offset_22->setMinimum(-1e+6);
        sample_orientation_offset_22->setMaximum(1e+6);

        gridLayout_3->addWidget(sample_orientation_offset_22, 2, 2, 1, 1);

        sample_orientation_offset_00 = new QDoubleSpinBox(groupBox_3);
        sample_orientation_offset_00->setObjectName(QStringLiteral("sample_orientation_offset_00"));
        sample_orientation_offset_00->setEnabled(true);
        sample_orientation_offset_00->setReadOnly(true);
        sample_orientation_offset_00->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_offset_00->setDecimals(6);
        sample_orientation_offset_00->setMinimum(-1e+6);
        sample_orientation_offset_00->setMaximum(1e+6);

        gridLayout_3->addWidget(sample_orientation_offset_00, 0, 0, 1, 1);

        sample_orientation_offset_12 = new QDoubleSpinBox(groupBox_3);
        sample_orientation_offset_12->setObjectName(QStringLiteral("sample_orientation_offset_12"));
        sample_orientation_offset_12->setReadOnly(true);
        sample_orientation_offset_12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_offset_12->setDecimals(6);
        sample_orientation_offset_12->setMinimum(-1e+6);
        sample_orientation_offset_12->setMaximum(1e+6);

        gridLayout_3->addWidget(sample_orientation_offset_12, 1, 2, 1, 1);

        sample_orientation_offset_01 = new QDoubleSpinBox(groupBox_3);
        sample_orientation_offset_01->setObjectName(QStringLiteral("sample_orientation_offset_01"));
        sample_orientation_offset_01->setReadOnly(true);
        sample_orientation_offset_01->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_offset_01->setDecimals(6);
        sample_orientation_offset_01->setMinimum(-1e+6);
        sample_orientation_offset_01->setMaximum(1e+6);

        gridLayout_3->addWidget(sample_orientation_offset_01, 0, 1, 1, 1);

        sample_orientation_offset_00->raise();
        sample_orientation_offset_11->raise();
        sample_orientation_offset_01->raise();
        sample_orientation_offset_10->raise();
        sample_orientation_offset_02->raise();
        sample_orientation_offset_20->raise();
        sample_orientation_offset_21->raise();
        sample_orientation_offset_12->raise();
        sample_orientation_offset_22->raise();

        verticalLayout_2->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(FrameInstrumentStates);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        detector_orientation_00 = new QDoubleSpinBox(groupBox_5);
        detector_orientation_00->setObjectName(QStringLiteral("detector_orientation_00"));
        detector_orientation_00->setEnabled(true);
        detector_orientation_00->setReadOnly(true);
        detector_orientation_00->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_00->setDecimals(6);
        detector_orientation_00->setMinimum(-1e+6);
        detector_orientation_00->setMaximum(1e+6);

        gridLayout_4->addWidget(detector_orientation_00, 0, 0, 1, 1);

        detector_orientation_01 = new QDoubleSpinBox(groupBox_5);
        detector_orientation_01->setObjectName(QStringLiteral("detector_orientation_01"));
        detector_orientation_01->setReadOnly(true);
        detector_orientation_01->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_01->setDecimals(6);
        detector_orientation_01->setMinimum(-1e+6);
        detector_orientation_01->setMaximum(1e+6);

        gridLayout_4->addWidget(detector_orientation_01, 0, 1, 1, 1);

        detector_orientation_02 = new QDoubleSpinBox(groupBox_5);
        detector_orientation_02->setObjectName(QStringLiteral("detector_orientation_02"));
        detector_orientation_02->setReadOnly(true);
        detector_orientation_02->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_02->setDecimals(6);
        detector_orientation_02->setMinimum(-1e+6);
        detector_orientation_02->setMaximum(1e+6);

        gridLayout_4->addWidget(detector_orientation_02, 0, 2, 1, 1);

        detector_orientation_10 = new QDoubleSpinBox(groupBox_5);
        detector_orientation_10->setObjectName(QStringLiteral("detector_orientation_10"));
        detector_orientation_10->setReadOnly(true);
        detector_orientation_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_10->setDecimals(6);
        detector_orientation_10->setMinimum(-1e+6);
        detector_orientation_10->setMaximum(1e+6);

        gridLayout_4->addWidget(detector_orientation_10, 1, 0, 1, 1);

        detector_orientation_11 = new QDoubleSpinBox(groupBox_5);
        detector_orientation_11->setObjectName(QStringLiteral("detector_orientation_11"));
        detector_orientation_11->setReadOnly(true);
        detector_orientation_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_11->setDecimals(6);
        detector_orientation_11->setMinimum(-1e+6);
        detector_orientation_11->setMaximum(1e+6);

        gridLayout_4->addWidget(detector_orientation_11, 1, 1, 1, 1);

        detector_orientation_12 = new QDoubleSpinBox(groupBox_5);
        detector_orientation_12->setObjectName(QStringLiteral("detector_orientation_12"));
        detector_orientation_12->setReadOnly(true);
        detector_orientation_12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_12->setDecimals(6);
        detector_orientation_12->setMinimum(-1e+6);
        detector_orientation_12->setMaximum(1e+6);

        gridLayout_4->addWidget(detector_orientation_12, 1, 2, 1, 1);

        detector_orientation_20 = new QDoubleSpinBox(groupBox_5);
        detector_orientation_20->setObjectName(QStringLiteral("detector_orientation_20"));
        detector_orientation_20->setReadOnly(true);
        detector_orientation_20->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_20->setDecimals(6);
        detector_orientation_20->setMinimum(-1e+6);
        detector_orientation_20->setMaximum(1e+6);

        gridLayout_4->addWidget(detector_orientation_20, 2, 0, 1, 1);

        detector_orientation_21 = new QDoubleSpinBox(groupBox_5);
        detector_orientation_21->setObjectName(QStringLiteral("detector_orientation_21"));
        detector_orientation_21->setReadOnly(true);
        detector_orientation_21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_21->setDecimals(6);
        detector_orientation_21->setMinimum(-1e+6);
        detector_orientation_21->setMaximum(1e+6);

        gridLayout_4->addWidget(detector_orientation_21, 2, 1, 1, 1);

        detector_orientation_22 = new QDoubleSpinBox(groupBox_5);
        detector_orientation_22->setObjectName(QStringLiteral("detector_orientation_22"));
        detector_orientation_22->setReadOnly(true);
        detector_orientation_22->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_22->setDecimals(6);
        detector_orientation_22->setMinimum(-1e+6);
        detector_orientation_22->setMaximum(1e+6);

        gridLayout_4->addWidget(detector_orientation_22, 2, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox_5);

        groupBox_4 = new QGroupBox(FrameInstrumentStates);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        ni_x = new QDoubleSpinBox(groupBox_4);
        ni_x->setObjectName(QStringLiteral("ni_x"));
        ni_x->setReadOnly(true);
        ni_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ni_x->setDecimals(6);
        ni_x->setMinimum(-1e+6);
        ni_x->setMaximum(1e+6);

        horizontalLayout_4->addWidget(ni_x);

        ni_y = new QDoubleSpinBox(groupBox_4);
        ni_y->setObjectName(QStringLiteral("ni_y"));
        ni_y->setReadOnly(true);
        ni_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ni_y->setDecimals(6);
        ni_y->setMinimum(-1e+6);
        ni_y->setMaximum(1e+6);

        horizontalLayout_4->addWidget(ni_y);

        ni_z = new QDoubleSpinBox(groupBox_4);
        ni_z->setObjectName(QStringLiteral("ni_z"));
        ni_z->setReadOnly(true);
        ni_z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ni_z->setDecimals(6);
        ni_z->setMinimum(-1e+6);
        ni_z->setMaximum(1e+6);

        horizontalLayout_4->addWidget(ni_z);


        verticalLayout_2->addWidget(groupBox_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(1, 3);

        verticalLayout_3->addLayout(horizontalLayout_3);

        actions = new QDialogButtonBox(FrameInstrumentStates);
        actions->setObjectName(QStringLiteral("actions"));
        actions->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(actions);


        retranslateUi(FrameInstrumentStates);

        QMetaObject::connectSlotsByName(FrameInstrumentStates);
    } // setupUi

    void retranslateUi(NSXQFrame *FrameInstrumentStates)
    {
        FrameInstrumentStates->setWindowTitle(QApplication::translate("FrameInstrumentStates", "Frame", Q_NULLPTR));
        label->setText(QApplication::translate("FrameInstrumentStates", "Frame", Q_NULLPTR));
        refined->setText(QApplication::translate("FrameInstrumentStates", "Refined", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FrameInstrumentStates", "Sample position", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("FrameInstrumentStates", "Sample orientation", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("FrameInstrumentStates", "Sample orientation offsets", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("FrameInstrumentStates", "Detector orientation", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("FrameInstrumentStates", "Normalized incoming beam", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FrameInstrumentStates: public Ui_FrameInstrumentStates {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEINSTRUMENTSTATES_H
