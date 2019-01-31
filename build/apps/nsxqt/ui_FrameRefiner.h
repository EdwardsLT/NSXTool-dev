/********************************************************************************
** Form generated from reading UI file 'FrameRefiner.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEREFINER_H
#define UI_FRAMEREFINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "NSXQFrame.h"
#include "PeakListView.h"

QT_BEGIN_NAMESPACE

class Ui_FrameRefiner
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabs;
    QWidget *settings;
    QVBoxLayout *verticalLayout_3;
    PeakListView *peaks;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *refine_ub;
    QCheckBox *refine_sample_position;
    QCheckBox *refine_detector_position;
    QCheckBox *refine_sample_orientation;
    QCheckBox *refine_ki;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *n_batches;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *actions;

    void setupUi(NSXQFrame *FrameRefiner)
    {
        if (FrameRefiner->objectName().isEmpty())
            FrameRefiner->setObjectName(QStringLiteral("FrameRefiner"));
        FrameRefiner->resize(1100, 772);
        FrameRefiner->setMinimumSize(QSize(1100, 600));
        FrameRefiner->setFrameShape(QFrame::StyledPanel);
        FrameRefiner->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(FrameRefiner);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabs = new QTabWidget(FrameRefiner);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setTabsClosable(true);
        settings = new QWidget();
        settings->setObjectName(QStringLiteral("settings"));
        verticalLayout_3 = new QVBoxLayout(settings);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        peaks = new PeakListView(settings);
        peaks->setObjectName(QStringLiteral("peaks"));

        verticalLayout_3->addWidget(peaks);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(settings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        refine_ub = new QCheckBox(groupBox);
        refine_ub->setObjectName(QStringLiteral("refine_ub"));
        refine_ub->setChecked(true);

        verticalLayout->addWidget(refine_ub);

        refine_sample_position = new QCheckBox(groupBox);
        refine_sample_position->setObjectName(QStringLiteral("refine_sample_position"));
        refine_sample_position->setChecked(true);

        verticalLayout->addWidget(refine_sample_position);

        refine_detector_position = new QCheckBox(groupBox);
        refine_detector_position->setObjectName(QStringLiteral("refine_detector_position"));

        verticalLayout->addWidget(refine_detector_position);

        refine_sample_orientation = new QCheckBox(groupBox);
        refine_sample_orientation->setObjectName(QStringLiteral("refine_sample_orientation"));
        refine_sample_orientation->setChecked(true);

        verticalLayout->addWidget(refine_sample_orientation);

        refine_ki = new QCheckBox(groupBox);
        refine_ki->setObjectName(QStringLiteral("refine_ki"));
        refine_ki->setChecked(true);

        verticalLayout->addWidget(refine_ki);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(settings);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        n_batches = new QSpinBox(settings);
        n_batches->setObjectName(QStringLiteral("n_batches"));
        n_batches->setWrapping(true);
        n_batches->setMinimum(1);
        n_batches->setMaximum(100);
        n_batches->setValue(1);

        horizontalLayout->addWidget(n_batches);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        tabs->addTab(settings, QString());

        verticalLayout_4->addWidget(tabs);

        actions = new QDialogButtonBox(FrameRefiner);
        actions->setObjectName(QStringLiteral("actions"));
        actions->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(actions);


        retranslateUi(FrameRefiner);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrameRefiner);
    } // setupUi

    void retranslateUi(NSXQFrame *FrameRefiner)
    {
        FrameRefiner->setWindowTitle(QApplication::translate("FrameRefiner", "Frame", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FrameRefiner", "Refinable parameters", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        refine_ub->setToolTip(QApplication::translate("FrameRefiner", "<html><head/><body><p>Refine the cell parameters (B matrix) alongside with the U matrix</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        refine_ub->setText(QApplication::translate("FrameRefiner", "lattice parameters (UB)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        refine_sample_position->setToolTip(QApplication::translate("FrameRefiner", "<html><head/><body><p>Refine the sample position (offset according 0,0,0)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        refine_sample_position->setText(QApplication::translate("FrameRefiner", "sample position", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        refine_detector_position->setToolTip(QApplication::translate("FrameRefiner", "<html><head/><body><p>Refine the detector offsets (according to (0,detector-to-sample-distance,0))</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        refine_detector_position->setText(QApplication::translate("FrameRefiner", "detector position", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        refine_sample_orientation->setToolTip(QApplication::translate("FrameRefiner", "<html><head/><body><p>Refine the sample orientation (sample goniometer angles)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        refine_sample_orientation->setText(QApplication::translate("FrameRefiner", "sample orientation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        refine_ki->setToolTip(QApplication::translate("FrameRefiner", "<html><head/><body><p>The direction and norm of the incident beam. By refining the norm of this vector this corresponds to refining the wavelength.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        refine_ki->setText(QApplication::translate("FrameRefiner", "ki", Q_NULLPTR));
        label->setText(QApplication::translate("FrameRefiner", "Number of batches", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        n_batches->setToolTip(QApplication::translate("FrameRefiner", "<html><head/><body><p>Set the number batches used for refining. A batch being a frame interval in which the refined parameters will be constant.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        tabs->setTabText(tabs->indexOf(settings), QApplication::translate("FrameRefiner", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FrameRefiner: public Ui_FrameRefiner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEREFINER_H
