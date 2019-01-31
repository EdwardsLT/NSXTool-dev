/********************************************************************************
** Form generated from reading UI file 'FramePeakFinder.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEPEAKFINDER_H
#define UI_FRAMEPEAKFINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "NSXQFrame.h"

QT_BEGIN_NAMESPACE

class Ui_FramePeakFinder
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabs;
    QWidget *tab1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *threshold;
    QLabel *label_2;
    QDoubleSpinBox *merge_scale;
    QLabel *label_3;
    QSpinBox *min_blob_size;
    QLabel *label_4;
    QSpinBox *max_blob_size;
    QLabel *label_5;
    QSpinBox *max_blob_width;
    QLabel *label_6;
    QComboBox *convolution_kernels;
    QLabel *label_7;
    QTableWidget *convolution_parameters;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QComboBox *selected_data;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QSpinBox *selected_frame;
    QSlider *selected_frame_slider;
    QCheckBox *apply_threshold;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QDoubleSpinBox *peak_scale;
    QLabel *label_11;
    QDoubleSpinBox *background_begin_scale;
    QLabel *label_12;
    QDoubleSpinBox *background_end_scale;
    QSpacerItem *verticalSpacer;
    QGraphicsView *preview;
    QDialogButtonBox *actions;

    void setupUi(NSXQFrame *FramePeakFinder)
    {
        if (FramePeakFinder->objectName().isEmpty())
            FramePeakFinder->setObjectName(QStringLiteral("FramePeakFinder"));
        FramePeakFinder->resize(1000, 800);
        FramePeakFinder->setMinimumSize(QSize(1000, 600));
        verticalLayout_3 = new QVBoxLayout(FramePeakFinder);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabs = new QTabWidget(FramePeakFinder);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setTabsClosable(true);
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        verticalLayout_2 = new QVBoxLayout(tab1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(tab1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        threshold = new QSpinBox(groupBox);
        threshold->setObjectName(QStringLiteral("threshold"));
        threshold->setWrapping(true);
        threshold->setMinimum(1);
        threshold->setMaximum(1000000);
        threshold->setValue(3);

        formLayout->setWidget(0, QFormLayout::FieldRole, threshold);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        merge_scale = new QDoubleSpinBox(groupBox);
        merge_scale->setObjectName(QStringLiteral("merge_scale"));
        merge_scale->setWrapping(true);
        merge_scale->setDecimals(3);
        merge_scale->setMinimum(1);
        merge_scale->setMaximum(10);
        merge_scale->setSingleStep(0.001);

        formLayout->setWidget(1, QFormLayout::FieldRole, merge_scale);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        min_blob_size = new QSpinBox(groupBox);
        min_blob_size->setObjectName(QStringLiteral("min_blob_size"));
        min_blob_size->setWrapping(true);
        min_blob_size->setMinimum(1);
        min_blob_size->setMaximum(10000);
        min_blob_size->setValue(30);

        formLayout->setWidget(2, QFormLayout::FieldRole, min_blob_size);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        max_blob_size = new QSpinBox(groupBox);
        max_blob_size->setObjectName(QStringLiteral("max_blob_size"));
        max_blob_size->setWrapping(true);
        max_blob_size->setMinimum(1);
        max_blob_size->setMaximum(100000);
        max_blob_size->setValue(10000);

        formLayout->setWidget(3, QFormLayout::FieldRole, max_blob_size);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        max_blob_width = new QSpinBox(groupBox);
        max_blob_width->setObjectName(QStringLiteral("max_blob_width"));
        max_blob_width->setWrapping(true);
        max_blob_width->setMinimum(1);
        max_blob_width->setMaximum(100);
        max_blob_width->setValue(10);

        formLayout->setWidget(4, QFormLayout::FieldRole, max_blob_width);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        convolution_kernels = new QComboBox(groupBox);
        convolution_kernels->setObjectName(QStringLiteral("convolution_kernels"));

        formLayout->setWidget(5, QFormLayout::FieldRole, convolution_kernels);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        convolution_parameters = new QTableWidget(groupBox);
        if (convolution_parameters->columnCount() < 2)
            convolution_parameters->setColumnCount(2);
        convolution_parameters->setObjectName(QStringLiteral("convolution_parameters"));
        convolution_parameters->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        convolution_parameters->setColumnCount(2);
        convolution_parameters->horizontalHeader()->setVisible(false);
        convolution_parameters->horizontalHeader()->setStretchLastSection(true);
        convolution_parameters->verticalHeader()->setVisible(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, convolution_parameters);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab1);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        selected_data = new QComboBox(groupBox_2);
        selected_data->setObjectName(QStringLiteral("selected_data"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, selected_data);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        selected_frame = new QSpinBox(groupBox_2);
        selected_frame->setObjectName(QStringLiteral("selected_frame"));
        selected_frame->setWrapping(true);
        selected_frame->setMaximum(10000);

        horizontalLayout->addWidget(selected_frame);

        selected_frame_slider = new QSlider(groupBox_2);
        selected_frame_slider->setObjectName(QStringLiteral("selected_frame_slider"));
        selected_frame_slider->setMaximum(10000);
        selected_frame_slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(selected_frame_slider);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        apply_threshold = new QCheckBox(groupBox_2);
        apply_threshold->setObjectName(QStringLiteral("apply_threshold"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, apply_threshold);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab1);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        formLayout_3 = new QFormLayout(groupBox_3);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        peak_scale = new QDoubleSpinBox(groupBox_3);
        peak_scale->setObjectName(QStringLiteral("peak_scale"));
        peak_scale->setWrapping(true);
        peak_scale->setDecimals(1);
        peak_scale->setMinimum(1);
        peak_scale->setMaximum(10);
        peak_scale->setSingleStep(0.1);
        peak_scale->setValue(3);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, peak_scale);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_11);

        background_begin_scale = new QDoubleSpinBox(groupBox_3);
        background_begin_scale->setObjectName(QStringLiteral("background_begin_scale"));
        background_begin_scale->setWrapping(true);
        background_begin_scale->setDecimals(1);
        background_begin_scale->setMinimum(1);
        background_begin_scale->setMaximum(10);
        background_begin_scale->setSingleStep(0.1);
        background_begin_scale->setValue(4);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, background_begin_scale);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_12);

        background_end_scale = new QDoubleSpinBox(groupBox_3);
        background_end_scale->setObjectName(QStringLiteral("background_end_scale"));
        background_end_scale->setWrapping(true);
        background_end_scale->setDecimals(1);
        background_end_scale->setMinimum(1);
        background_end_scale->setMaximum(10);
        background_end_scale->setSingleStep(0.1);
        background_end_scale->setValue(4.5);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, background_end_scale);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        preview = new QGraphicsView(tab1);
        preview->setObjectName(QStringLiteral("preview"));

        horizontalLayout_2->addWidget(preview);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        tabs->addTab(tab1, QString());

        verticalLayout_3->addWidget(tabs);

        actions = new QDialogButtonBox(FramePeakFinder);
        actions->setObjectName(QStringLiteral("actions"));
        actions->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(actions);


        retranslateUi(FramePeakFinder);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FramePeakFinder);
    } // setupUi

    void retranslateUi(NSXQFrame *FramePeakFinder)
    {
        FramePeakFinder->setWindowTitle(QApplication::translate("FramePeakFinder", "Peak finder", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The parameters  for performing the blob search.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("FramePeakFinder", "Blob parameters", Q_NULLPTR));
        label->setText(QApplication::translate("FramePeakFinder", "threshold", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        threshold->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The intensity threshold over which a pixel is considered as part of a blob.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("FramePeakFinder", "merging scale", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        merge_scale->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The blob merging scale (in \\u03C3 unit). Two blobs whose corresponding  ellipsoids overlap will be merged as a sigle blob.  </p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("FramePeakFinder", "minimum size", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        min_blob_size->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The minimum size of a blob for being considered as a peak</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("FramePeakFinder", "maximum size", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        max_blob_size->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The maximum size of a blob for being considered as a peak.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("FramePeakFinder", "maximum width", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        max_blob_width->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The maximum width in frames of a blob for being considered as a peak.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("FramePeakFinder", "convolution kernel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        convolution_kernels->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The convolution kernel used for smoothing the image prior finding peaks.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("FramePeakFinder", "convolution parameters", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        convolution_parameters->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The parameters of the convolution kernel used for smoothing the image prior finding peaks.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("FramePeakFinder", "Preview", Q_NULLPTR));
        label_8->setText(QApplication::translate("FramePeakFinder", "data", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        selected_data->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The selected data for previewing the peak search.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("FramePeakFinder", "frame", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        selected_frame->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The selected frame for previewing the peak search.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        selected_frame_slider->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The selected frame for previewing the peak search.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        apply_threshold->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The intensity threshold will be applied for clipping the preview.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        apply_threshold->setText(QApplication::translate("FramePeakFinder", "apply threshold to preview", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("FramePeakFinder", "Integration parameters", Q_NULLPTR));
        label_10->setText(QApplication::translate("FramePeakFinder", "peak area", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        peak_scale->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The peak area scale (in \\u03C3 unit).</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("FramePeakFinder", "background lower limit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        background_begin_scale->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The background lower limit area scale (in \\u03C3 unit).</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("FramePeakFinder", "background upper limit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        background_end_scale->setToolTip(QApplication::translate("FramePeakFinder", "<html><head/><body><p>The background upper limit area scale (in \\u03C3 unit).</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        tabs->setTabText(tabs->indexOf(tab1), QApplication::translate("FramePeakFinder", "settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FramePeakFinder: public Ui_FramePeakFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEPEAKFINDER_H
