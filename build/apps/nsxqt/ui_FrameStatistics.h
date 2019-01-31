/********************************************************************************
** Form generated from reading UI file 'FrameStatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMESTATISTICS_H
#define UI_FRAMESTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CopyPasteTableView.h"
#include "NSXQFrame.h"
#include "SXPlot.h"

QT_BEGIN_NAMESPACE

class Ui_FrameStatistics
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabs;
    QWidget *statistics_tab;
    QVBoxLayout *verticalLayout_2;
    CopyPasteTableView *statistics;
    QHBoxLayout *horizontalLayout_5;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *dmin;
    QLabel *label_2;
    QDoubleSpinBox *dmax;
    QLabel *label_3;
    QSpinBox *n_shells;
    QCheckBox *friedel;
    QLabel *label_4;
    QComboBox *selected_statistics;
    SXPlot *plot;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *save_statistics;
    QWidget *merged_peaks_tab;
    QGridLayout *gridLayout_4;
    CopyPasteTableView *merged_peaks;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *merged_peaks_format;
    QPushButton *save_merged_peaks;
    QWidget *unmerged_peaks_tab;
    QGridLayout *gridLayout_3;
    CopyPasteTableView *unmerged_peaks;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *unmerged_peaks_format;
    QPushButton *save_unmerged_peaks;
    QDialogButtonBox *actions;

    void setupUi(NSXQFrame *FrameStatistics)
    {
        if (FrameStatistics->objectName().isEmpty())
            FrameStatistics->setObjectName(QStringLiteral("FrameStatistics"));
        FrameStatistics->resize(863, 624);
        FrameStatistics->setFrameShape(QFrame::StyledPanel);
        FrameStatistics->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(FrameStatistics);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabs = new QTabWidget(FrameStatistics);
        tabs->setObjectName(QStringLiteral("tabs"));
        statistics_tab = new QWidget();
        statistics_tab->setObjectName(QStringLiteral("statistics_tab"));
        verticalLayout_2 = new QVBoxLayout(statistics_tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        statistics = new CopyPasteTableView(statistics_tab);
        statistics->setObjectName(QStringLiteral("statistics"));

        verticalLayout_2->addWidget(statistics);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(statistics_tab);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dmin = new QDoubleSpinBox(statistics_tab);
        dmin->setObjectName(QStringLiteral("dmin"));
        dmin->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dmin->setDecimals(6);
        dmin->setMaximum(100000);
        dmin->setSingleStep(0.0001);
        dmin->setValue(0.1);

        formLayout->setWidget(0, QFormLayout::FieldRole, dmin);

        label_2 = new QLabel(statistics_tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        dmax = new QDoubleSpinBox(statistics_tab);
        dmax->setObjectName(QStringLiteral("dmax"));
        dmax->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dmax->setDecimals(6);
        dmax->setMaximum(100000);
        dmax->setSingleStep(0.0001);
        dmax->setValue(10);

        formLayout->setWidget(1, QFormLayout::FieldRole, dmax);

        label_3 = new QLabel(statistics_tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        n_shells = new QSpinBox(statistics_tab);
        n_shells->setObjectName(QStringLiteral("n_shells"));
        n_shells->setButtonSymbols(QAbstractSpinBox::NoButtons);
        n_shells->setMinimum(1);
        n_shells->setMaximum(100);
        n_shells->setValue(10);

        formLayout->setWidget(2, QFormLayout::FieldRole, n_shells);

        friedel = new QCheckBox(statistics_tab);
        friedel->setObjectName(QStringLiteral("friedel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, friedel);

        label_4 = new QLabel(statistics_tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        selected_statistics = new QComboBox(statistics_tab);
        selected_statistics->setObjectName(QStringLiteral("selected_statistics"));

        formLayout->setWidget(4, QFormLayout::FieldRole, selected_statistics);


        horizontalLayout_5->addLayout(formLayout);

        plot = new SXPlot(statistics_tab);
        plot->setObjectName(QStringLiteral("plot"));

        horizontalLayout_5->addWidget(plot);

        horizontalLayout_5->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        save_statistics = new QPushButton(statistics_tab);
        save_statistics->setObjectName(QStringLiteral("save_statistics"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(save_statistics->sizePolicy().hasHeightForWidth());
        save_statistics->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(save_statistics);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);
        tabs->addTab(statistics_tab, QString());
        merged_peaks_tab = new QWidget();
        merged_peaks_tab->setObjectName(QStringLiteral("merged_peaks_tab"));
        gridLayout_4 = new QGridLayout(merged_peaks_tab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        merged_peaks = new CopyPasteTableView(merged_peaks_tab);
        merged_peaks->setObjectName(QStringLiteral("merged_peaks"));

        gridLayout_4->addWidget(merged_peaks, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        merged_peaks_format = new QComboBox(merged_peaks_tab);
        merged_peaks_format->setObjectName(QStringLiteral("merged_peaks_format"));

        horizontalLayout_3->addWidget(merged_peaks_format);

        save_merged_peaks = new QPushButton(merged_peaks_tab);
        save_merged_peaks->setObjectName(QStringLiteral("save_merged_peaks"));
        sizePolicy.setHeightForWidth(save_merged_peaks->sizePolicy().hasHeightForWidth());
        save_merged_peaks->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(save_merged_peaks);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        tabs->addTab(merged_peaks_tab, QString());
        unmerged_peaks_tab = new QWidget();
        unmerged_peaks_tab->setObjectName(QStringLiteral("unmerged_peaks_tab"));
        gridLayout_3 = new QGridLayout(unmerged_peaks_tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        unmerged_peaks = new CopyPasteTableView(unmerged_peaks_tab);
        unmerged_peaks->setObjectName(QStringLiteral("unmerged_peaks"));

        gridLayout_3->addWidget(unmerged_peaks, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        unmerged_peaks_format = new QComboBox(unmerged_peaks_tab);
        unmerged_peaks_format->setObjectName(QStringLiteral("unmerged_peaks_format"));

        horizontalLayout_4->addWidget(unmerged_peaks_format);

        save_unmerged_peaks = new QPushButton(unmerged_peaks_tab);
        save_unmerged_peaks->setObjectName(QStringLiteral("save_unmerged_peaks"));
        sizePolicy.setHeightForWidth(save_unmerged_peaks->sizePolicy().hasHeightForWidth());
        save_unmerged_peaks->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(save_unmerged_peaks);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        tabs->addTab(unmerged_peaks_tab, QString());

        verticalLayout->addWidget(tabs);

        actions = new QDialogButtonBox(FrameStatistics);
        actions->setObjectName(QStringLiteral("actions"));
        actions->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(actions);


        retranslateUi(FrameStatistics);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrameStatistics);
    } // setupUi

    void retranslateUi(NSXQFrame *FrameStatistics)
    {
        FrameStatistics->setWindowTitle(QApplication::translate("FrameStatistics", "Frame", Q_NULLPTR));
        label->setText(QApplication::translate("FrameStatistics", "dmin", Q_NULLPTR));
        label_2->setText(QApplication::translate("FrameStatistics", "dmax", Q_NULLPTR));
        label_3->setText(QApplication::translate("FrameStatistics", "# d-shells", Q_NULLPTR));
        friedel->setText(QApplication::translate("FrameStatistics", "Include Friedel", Q_NULLPTR));
        label_4->setText(QApplication::translate("FrameStatistics", "Plot", Q_NULLPTR));
        save_statistics->setText(QApplication::translate("FrameStatistics", "Save", Q_NULLPTR));
        tabs->setTabText(tabs->indexOf(statistics_tab), QApplication::translate("FrameStatistics", "Statistics", Q_NULLPTR));
        merged_peaks_format->clear();
        merged_peaks_format->insertItems(0, QStringList()
         << QApplication::translate("FrameStatistics", "ShelX", Q_NULLPTR)
         << QApplication::translate("FrameStatistics", "FullProf", Q_NULLPTR)
        );
        save_merged_peaks->setText(QApplication::translate("FrameStatistics", "Save", Q_NULLPTR));
        tabs->setTabText(tabs->indexOf(merged_peaks_tab), QApplication::translate("FrameStatistics", "Merged hkls", Q_NULLPTR));
        unmerged_peaks_format->clear();
        unmerged_peaks_format->insertItems(0, QStringList()
         << QApplication::translate("FrameStatistics", "ShelX", Q_NULLPTR)
         << QApplication::translate("FrameStatistics", "FullProf", Q_NULLPTR)
        );
        save_unmerged_peaks->setText(QApplication::translate("FrameStatistics", "Save", Q_NULLPTR));
        tabs->setTabText(tabs->indexOf(unmerged_peaks_tab), QApplication::translate("FrameStatistics", "Unmerged hkls", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FrameStatistics: public Ui_FrameStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMESTATISTICS_H
