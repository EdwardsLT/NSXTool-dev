/********************************************************************************
** Form generated from reading UI file 'WidgetRefinerFit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETREFINERFIT_H
#define UI_WIDGETREFINERFIT_H

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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plot/SXPlot.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetRefinerFit
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_13;
    QListWidget *selected_data;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QSpinBox *selected_batch;
    QSpacerItem *horizontalSpacer_3;
    SXPlot *plot;
    QLabel *refined;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_11;
    QDoubleSpinBox *sample_position_x;
    QDoubleSpinBox *sample_position_y;
    QDoubleSpinBox *sample_position_z;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_12;
    QDoubleSpinBox *detector_position_offset_x;
    QDoubleSpinBox *detector_position_offset_y;
    QDoubleSpinBox *detector_position_offset_z;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QDoubleSpinBox *ni_x;
    QDoubleSpinBox *ni_y;
    QDoubleSpinBox *ni_z;
    QLabel *label_8;
    QDoubleSpinBox *wavelength;
    QDoubleSpinBox *wavelength_offset;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_15;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *sample_orientation_00;
    QDoubleSpinBox *sample_orientation_01;
    QDoubleSpinBox *sample_orientation_02;
    QDoubleSpinBox *sample_orientation_10;
    QDoubleSpinBox *sample_orientation_11;
    QDoubleSpinBox *sample_orientation_12;
    QDoubleSpinBox *sample_orientation_20;
    QDoubleSpinBox *sample_orientation_21;
    QDoubleSpinBox *sample_orientation_22;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout_16;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_6;
    QDoubleSpinBox *detector_orientation_00;
    QDoubleSpinBox *detector_orientation_01;
    QDoubleSpinBox *detector_orientation_02;
    QDoubleSpinBox *detector_orientation_10;
    QDoubleSpinBox *detector_orientation_11;
    QDoubleSpinBox *detector_orientation_12;
    QDoubleSpinBox *detector_orientation_20;
    QDoubleSpinBox *detector_orientation_21;
    QDoubleSpinBox *detector_orientation_22;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QSpinBox *selected_frame;
    QSlider *selected_frame_slider;

    void setupUi(QWidget *WidgetRefinerFit)
    {
        if (WidgetRefinerFit->objectName().isEmpty())
            WidgetRefinerFit->setObjectName(QStringLiteral("WidgetRefinerFit"));
        WidgetRefinerFit->resize(1023, 603);
        verticalLayout = new QVBoxLayout(WidgetRefinerFit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_8 = new QGroupBox(WidgetRefinerFit);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        verticalLayout_13 = new QVBoxLayout(groupBox_8);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        selected_data = new QListWidget(groupBox_8);
        selected_data->setObjectName(QStringLiteral("selected_data"));

        verticalLayout_13->addWidget(selected_data);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_9->addWidget(label_6);

        selected_batch = new QSpinBox(groupBox_8);
        selected_batch->setObjectName(QStringLiteral("selected_batch"));
        selected_batch->setWrapping(true);
        selected_batch->setReadOnly(false);
        selected_batch->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

        horizontalLayout_9->addWidget(selected_batch);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        verticalLayout_13->addLayout(horizontalLayout_9);


        verticalLayout_2->addWidget(groupBox_8);


        horizontalLayout->addLayout(verticalLayout_2);

        plot = new SXPlot(WidgetRefinerFit);
        plot->setObjectName(QStringLiteral("plot"));

        horizontalLayout->addWidget(plot);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_12->addLayout(horizontalLayout);

        refined = new QLabel(WidgetRefinerFit);
        refined->setObjectName(QStringLiteral("refined"));
        refined->setFrameShape(QFrame::Box);
        refined->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(refined);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        groupBox_9 = new QGroupBox(WidgetRefinerFit);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_9);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        sample_position_x = new QDoubleSpinBox(groupBox_9);
        sample_position_x->setObjectName(QStringLiteral("sample_position_x"));
        sample_position_x->setReadOnly(true);
        sample_position_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_position_x->setDecimals(5);
        sample_position_x->setMinimum(-100);
        sample_position_x->setMaximum(100);
        sample_position_x->setSingleStep(1e-5);

        horizontalLayout_11->addWidget(sample_position_x);

        sample_position_y = new QDoubleSpinBox(groupBox_9);
        sample_position_y->setObjectName(QStringLiteral("sample_position_y"));
        sample_position_y->setReadOnly(true);
        sample_position_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_position_y->setDecimals(5);
        sample_position_y->setMinimum(-100);
        sample_position_y->setMaximum(100);
        sample_position_y->setSingleStep(1e-5);

        horizontalLayout_11->addWidget(sample_position_y);

        sample_position_z = new QDoubleSpinBox(groupBox_9);
        sample_position_z->setObjectName(QStringLiteral("sample_position_z"));
        sample_position_z->setReadOnly(true);
        sample_position_z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_position_z->setDecimals(5);
        sample_position_z->setMinimum(-100);
        sample_position_z->setMaximum(100);
        sample_position_z->setSingleStep(1e-5);

        horizontalLayout_11->addWidget(sample_position_z);


        verticalLayout_14->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(WidgetRefinerFit);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        horizontalLayout_12 = new QHBoxLayout(groupBox_10);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        detector_position_offset_x = new QDoubleSpinBox(groupBox_10);
        detector_position_offset_x->setObjectName(QStringLiteral("detector_position_offset_x"));
        detector_position_offset_x->setReadOnly(true);
        detector_position_offset_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_position_offset_x->setDecimals(5);
        detector_position_offset_x->setMinimum(-100);
        detector_position_offset_x->setMaximum(100);
        detector_position_offset_x->setSingleStep(1e-5);

        horizontalLayout_12->addWidget(detector_position_offset_x);

        detector_position_offset_y = new QDoubleSpinBox(groupBox_10);
        detector_position_offset_y->setObjectName(QStringLiteral("detector_position_offset_y"));
        detector_position_offset_y->setReadOnly(true);
        detector_position_offset_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_position_offset_y->setDecimals(5);
        detector_position_offset_y->setMinimum(-100);
        detector_position_offset_y->setMaximum(100);
        detector_position_offset_y->setSingleStep(1e-5);

        horizontalLayout_12->addWidget(detector_position_offset_y);

        detector_position_offset_z = new QDoubleSpinBox(groupBox_10);
        detector_position_offset_z->setObjectName(QStringLiteral("detector_position_offset_z"));
        detector_position_offset_z->setReadOnly(true);
        detector_position_offset_z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_position_offset_z->setDecimals(5);
        detector_position_offset_z->setMinimum(-100);
        detector_position_offset_z->setMaximum(100);
        detector_position_offset_z->setSingleStep(1e-5);

        horizontalLayout_12->addWidget(detector_position_offset_z);


        verticalLayout_14->addWidget(groupBox_10);

        groupBox_11 = new QGroupBox(WidgetRefinerFit);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        gridLayout_4 = new QGridLayout(groupBox_11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_7 = new QLabel(groupBox_11);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        ni_x = new QDoubleSpinBox(groupBox_11);
        ni_x->setObjectName(QStringLiteral("ni_x"));
        ni_x->setReadOnly(true);
        ni_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ni_x->setDecimals(5);
        ni_x->setMinimum(-100);
        ni_x->setMaximum(100);
        ni_x->setSingleStep(1e-5);

        gridLayout_4->addWidget(ni_x, 0, 1, 1, 1);

        ni_y = new QDoubleSpinBox(groupBox_11);
        ni_y->setObjectName(QStringLiteral("ni_y"));
        ni_y->setReadOnly(true);
        ni_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ni_y->setDecimals(5);
        ni_y->setMinimum(-100);
        ni_y->setMaximum(100);
        ni_y->setSingleStep(1e-5);

        gridLayout_4->addWidget(ni_y, 0, 2, 1, 1);

        ni_z = new QDoubleSpinBox(groupBox_11);
        ni_z->setObjectName(QStringLiteral("ni_z"));
        ni_z->setReadOnly(true);
        ni_z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ni_z->setDecimals(5);
        ni_z->setMinimum(-100);
        ni_z->setMaximum(100);
        ni_z->setSingleStep(1e-5);

        gridLayout_4->addWidget(ni_z, 0, 3, 1, 1);

        label_8 = new QLabel(groupBox_11);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        wavelength = new QDoubleSpinBox(groupBox_11);
        wavelength->setObjectName(QStringLiteral("wavelength"));
        wavelength->setReadOnly(true);
        wavelength->setButtonSymbols(QAbstractSpinBox::NoButtons);
        wavelength->setDecimals(5);
        wavelength->setMinimum(-100);
        wavelength->setMaximum(100);
        wavelength->setSingleStep(1e-5);

        gridLayout_4->addWidget(wavelength, 1, 1, 1, 1);

        wavelength_offset = new QDoubleSpinBox(groupBox_11);
        wavelength_offset->setObjectName(QStringLiteral("wavelength_offset"));
        wavelength_offset->setReadOnly(true);
        wavelength_offset->setButtonSymbols(QAbstractSpinBox::NoButtons);
        wavelength_offset->setDecimals(5);
        wavelength_offset->setMinimum(-100);
        wavelength_offset->setMaximum(100);
        wavelength_offset->setSingleStep(1e-5);

        gridLayout_4->addWidget(wavelength_offset, 1, 2, 1, 1);


        verticalLayout_14->addWidget(groupBox_11);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_4);


        horizontalLayout_10->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        groupBox_12 = new QGroupBox(WidgetRefinerFit);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        gridLayout_5 = new QGridLayout(groupBox_12);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        sample_orientation_00 = new QDoubleSpinBox(groupBox_12);
        sample_orientation_00->setObjectName(QStringLiteral("sample_orientation_00"));
        sample_orientation_00->setReadOnly(true);
        sample_orientation_00->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_00->setDecimals(3);
        sample_orientation_00->setMaximum(10);

        gridLayout_5->addWidget(sample_orientation_00, 0, 0, 1, 1);

        sample_orientation_01 = new QDoubleSpinBox(groupBox_12);
        sample_orientation_01->setObjectName(QStringLiteral("sample_orientation_01"));
        sample_orientation_01->setReadOnly(true);
        sample_orientation_01->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_01->setDecimals(3);
        sample_orientation_01->setMaximum(10);

        gridLayout_5->addWidget(sample_orientation_01, 0, 1, 1, 1);

        sample_orientation_02 = new QDoubleSpinBox(groupBox_12);
        sample_orientation_02->setObjectName(QStringLiteral("sample_orientation_02"));
        sample_orientation_02->setReadOnly(true);
        sample_orientation_02->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_02->setDecimals(3);
        sample_orientation_02->setMaximum(10);

        gridLayout_5->addWidget(sample_orientation_02, 0, 2, 1, 1);

        sample_orientation_10 = new QDoubleSpinBox(groupBox_12);
        sample_orientation_10->setObjectName(QStringLiteral("sample_orientation_10"));
        sample_orientation_10->setReadOnly(true);
        sample_orientation_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_10->setDecimals(3);
        sample_orientation_10->setMaximum(10);

        gridLayout_5->addWidget(sample_orientation_10, 1, 0, 1, 1);

        sample_orientation_11 = new QDoubleSpinBox(groupBox_12);
        sample_orientation_11->setObjectName(QStringLiteral("sample_orientation_11"));
        sample_orientation_11->setReadOnly(true);
        sample_orientation_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_11->setDecimals(3);
        sample_orientation_11->setMaximum(10);

        gridLayout_5->addWidget(sample_orientation_11, 1, 1, 1, 1);

        sample_orientation_12 = new QDoubleSpinBox(groupBox_12);
        sample_orientation_12->setObjectName(QStringLiteral("sample_orientation_12"));
        sample_orientation_12->setReadOnly(true);
        sample_orientation_12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_12->setDecimals(3);
        sample_orientation_12->setMaximum(10);

        gridLayout_5->addWidget(sample_orientation_12, 1, 2, 1, 1);

        sample_orientation_20 = new QDoubleSpinBox(groupBox_12);
        sample_orientation_20->setObjectName(QStringLiteral("sample_orientation_20"));
        sample_orientation_20->setReadOnly(true);
        sample_orientation_20->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_20->setDecimals(3);
        sample_orientation_20->setMaximum(10);

        gridLayout_5->addWidget(sample_orientation_20, 2, 0, 1, 1);

        sample_orientation_21 = new QDoubleSpinBox(groupBox_12);
        sample_orientation_21->setObjectName(QStringLiteral("sample_orientation_21"));
        sample_orientation_21->setReadOnly(true);
        sample_orientation_21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_21->setDecimals(3);
        sample_orientation_21->setMaximum(10);

        gridLayout_5->addWidget(sample_orientation_21, 2, 1, 1, 1);

        sample_orientation_22 = new QDoubleSpinBox(groupBox_12);
        sample_orientation_22->setObjectName(QStringLiteral("sample_orientation_22"));
        sample_orientation_22->setReadOnly(true);
        sample_orientation_22->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_orientation_22->setDecimals(3);
        sample_orientation_22->setMaximum(10);

        gridLayout_5->addWidget(sample_orientation_22, 2, 2, 1, 1);


        verticalLayout_15->addWidget(groupBox_12);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_5);


        horizontalLayout_10->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        groupBox_13 = new QGroupBox(WidgetRefinerFit);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        gridLayout_6 = new QGridLayout(groupBox_13);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        detector_orientation_00 = new QDoubleSpinBox(groupBox_13);
        detector_orientation_00->setObjectName(QStringLiteral("detector_orientation_00"));
        detector_orientation_00->setReadOnly(true);
        detector_orientation_00->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_00->setDecimals(3);
        detector_orientation_00->setMaximum(10);

        gridLayout_6->addWidget(detector_orientation_00, 0, 0, 1, 1);

        detector_orientation_01 = new QDoubleSpinBox(groupBox_13);
        detector_orientation_01->setObjectName(QStringLiteral("detector_orientation_01"));
        detector_orientation_01->setReadOnly(true);
        detector_orientation_01->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_01->setDecimals(3);
        detector_orientation_01->setMaximum(10);

        gridLayout_6->addWidget(detector_orientation_01, 0, 1, 1, 1);

        detector_orientation_02 = new QDoubleSpinBox(groupBox_13);
        detector_orientation_02->setObjectName(QStringLiteral("detector_orientation_02"));
        detector_orientation_02->setReadOnly(true);
        detector_orientation_02->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_02->setDecimals(3);
        detector_orientation_02->setMaximum(10);

        gridLayout_6->addWidget(detector_orientation_02, 0, 2, 1, 1);

        detector_orientation_10 = new QDoubleSpinBox(groupBox_13);
        detector_orientation_10->setObjectName(QStringLiteral("detector_orientation_10"));
        detector_orientation_10->setReadOnly(true);
        detector_orientation_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_10->setDecimals(3);
        detector_orientation_10->setMaximum(10);

        gridLayout_6->addWidget(detector_orientation_10, 1, 0, 1, 1);

        detector_orientation_11 = new QDoubleSpinBox(groupBox_13);
        detector_orientation_11->setObjectName(QStringLiteral("detector_orientation_11"));
        detector_orientation_11->setReadOnly(true);
        detector_orientation_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_11->setDecimals(3);
        detector_orientation_11->setMaximum(10);

        gridLayout_6->addWidget(detector_orientation_11, 1, 1, 1, 1);

        detector_orientation_12 = new QDoubleSpinBox(groupBox_13);
        detector_orientation_12->setObjectName(QStringLiteral("detector_orientation_12"));
        detector_orientation_12->setReadOnly(true);
        detector_orientation_12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_12->setDecimals(3);
        detector_orientation_12->setMaximum(10);

        gridLayout_6->addWidget(detector_orientation_12, 1, 2, 1, 1);

        detector_orientation_20 = new QDoubleSpinBox(groupBox_13);
        detector_orientation_20->setObjectName(QStringLiteral("detector_orientation_20"));
        detector_orientation_20->setReadOnly(true);
        detector_orientation_20->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_20->setDecimals(3);
        detector_orientation_20->setMaximum(10);

        gridLayout_6->addWidget(detector_orientation_20, 2, 0, 1, 1);

        detector_orientation_21 = new QDoubleSpinBox(groupBox_13);
        detector_orientation_21->setObjectName(QStringLiteral("detector_orientation_21"));
        detector_orientation_21->setReadOnly(true);
        detector_orientation_21->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_21->setDecimals(3);
        detector_orientation_21->setMaximum(10);

        gridLayout_6->addWidget(detector_orientation_21, 2, 1, 1, 1);

        detector_orientation_22 = new QDoubleSpinBox(groupBox_13);
        detector_orientation_22->setObjectName(QStringLiteral("detector_orientation_22"));
        detector_orientation_22->setReadOnly(true);
        detector_orientation_22->setButtonSymbols(QAbstractSpinBox::NoButtons);
        detector_orientation_22->setDecimals(3);
        detector_orientation_22->setMaximum(10);

        gridLayout_6->addWidget(detector_orientation_22, 2, 2, 1, 1);


        verticalLayout_16->addWidget(groupBox_13);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_6);


        horizontalLayout_10->addLayout(verticalLayout_16);


        verticalLayout_12->addLayout(horizontalLayout_10);

        verticalLayout_12->setStretch(0, 1);

        verticalLayout->addLayout(verticalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_9 = new QLabel(WidgetRefinerFit);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_13->addWidget(label_9);

        selected_frame = new QSpinBox(WidgetRefinerFit);
        selected_frame->setObjectName(QStringLiteral("selected_frame"));

        horizontalLayout_13->addWidget(selected_frame);

        selected_frame_slider = new QSlider(WidgetRefinerFit);
        selected_frame_slider->setObjectName(QStringLiteral("selected_frame_slider"));
        selected_frame_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(selected_frame_slider);


        verticalLayout->addLayout(horizontalLayout_13);


        retranslateUi(WidgetRefinerFit);

        QMetaObject::connectSlotsByName(WidgetRefinerFit);
    } // setupUi

    void retranslateUi(QWidget *WidgetRefinerFit)
    {
        WidgetRefinerFit->setWindowTitle(QApplication::translate("WidgetRefinerFit", "Form", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("WidgetRefinerFit", "Data", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        selected_data->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>Select the data for which the cost function shold be inspected.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("WidgetRefinerFit", "Batch", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        selected_batch->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>Select the batch for which the cost function and the offsets should be inspected.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        refined->setText(QApplication::translate("WidgetRefinerFit", "Refined", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("WidgetRefinerFit", "Sample position", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("WidgetRefinerFit", "Detector position offset", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        detector_position_offset_x->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>The refined detector position offset in x.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        detector_position_offset_y->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>The refined detector position offset in y.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        detector_position_offset_z->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>The refined detector position offset in z.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_11->setTitle(QApplication::translate("WidgetRefinerFit", "Incident beam", Q_NULLPTR));
        label_7->setText(QApplication::translate("WidgetRefinerFit", "ni", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ni_x->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>The refined incident beam in x.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ni_y->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>The refined incident beam in y.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ni_z->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>The refined incident beam in z.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("WidgetRefinerFit", "wavelength", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        wavelength->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>The wavelength set in the metadata</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        wavelength_offset->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>The refined wavelength offset</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_12->setTitle(QApplication::translate("WidgetRefinerFit", "Sample orientation", Q_NULLPTR));
        groupBox_13->setTitle(QApplication::translate("WidgetRefinerFit", "Detector orientation", Q_NULLPTR));
        label_9->setText(QApplication::translate("WidgetRefinerFit", "Frame", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        selected_frame->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>Select the frame for which the cost function and offsets shou</p><p>ld be inspected.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        selected_frame_slider->setToolTip(QApplication::translate("WidgetRefinerFit", "<html><head/><body><p>Select the frame for which the cost function and offsets shou</p><p>ld be inspected.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class WidgetRefinerFit: public Ui_WidgetRefinerFit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETREFINERFIT_H
