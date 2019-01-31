/********************************************************************************
** Form generated from reading UI file 'FrameUserDefinedUnitCellIndexer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEUSERDEFINEDUNITCELLINDEXER_H
#define UI_FRAMEUSERDEFINEDUNITCELLINDEXER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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

class Ui_FrameUserDefinedUnitCellIndexer
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabs;
    QWidget *settings;
    QVBoxLayout *verticalLayout_2;
    PeakListView *peaks;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QDoubleSpinBox *gruber_tolerance;
    QDoubleSpinBox *niggli_tolerance;
    QDoubleSpinBox *beta;
    QLabel *label_gamma;
    QLabel *label_a;
    QDoubleSpinBox *a;
    QLabel *label_c;
    QDoubleSpinBox *c;
    QLabel *label_b;
    QLabel *label_alpha;
    QLabel *label_beta;
    QCheckBox *niggli_only;
    QDoubleSpinBox *alpha;
    QDoubleSpinBox *b;
    QDoubleSpinBox *gamma;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_wavelength;
    QDoubleSpinBox *wavelength;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *angular_tolerance;
    QLabel *indexing_tolerance_label;
    QLabel *label_6;
    QDoubleSpinBox *indexing_threshold;
    QLabel *label_5;
    QDoubleSpinBox *indexing_tolerance;
    QDoubleSpinBox *distance_tolerance;
    QLabel *indexing_threshold_label;
    QLabel *label_4;
    QSpinBox *n_solutions;
    QLabel *label_3;
    QSpinBox *max_n_q_vectors;
    QTableView *unit_cells;
    QDialogButtonBox *actions;

    void setupUi(NSXQFrame *FrameUserDefinedUnitCellIndexer)
    {
        if (FrameUserDefinedUnitCellIndexer->objectName().isEmpty())
            FrameUserDefinedUnitCellIndexer->setObjectName(QStringLiteral("FrameUserDefinedUnitCellIndexer"));
        FrameUserDefinedUnitCellIndexer->resize(931, 834);
        FrameUserDefinedUnitCellIndexer->setFrameShape(QFrame::StyledPanel);
        FrameUserDefinedUnitCellIndexer->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FrameUserDefinedUnitCellIndexer);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabs = new QTabWidget(FrameUserDefinedUnitCellIndexer);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setTabsClosable(true);
        settings = new QWidget();
        settings->setObjectName(QStringLiteral("settings"));
        verticalLayout_2 = new QVBoxLayout(settings);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        peaks = new PeakListView(settings);
        peaks->setObjectName(QStringLiteral("peaks"));

        verticalLayout_2->addWidget(peaks);

        groupBox_2 = new QGroupBox(settings);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gruber_tolerance = new QDoubleSpinBox(groupBox_3);
        gruber_tolerance->setObjectName(QStringLiteral("gruber_tolerance"));
        gruber_tolerance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gruber_tolerance->setDecimals(6);
        gruber_tolerance->setMaximum(1);
        gruber_tolerance->setSingleStep(0.0001);
        gruber_tolerance->setValue(0.04);

        gridLayout->addWidget(gruber_tolerance, 3, 1, 1, 1);

        niggli_tolerance = new QDoubleSpinBox(groupBox_3);
        niggli_tolerance->setObjectName(QStringLiteral("niggli_tolerance"));
        niggli_tolerance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        niggli_tolerance->setDecimals(6);
        niggli_tolerance->setMaximum(1);
        niggli_tolerance->setSingleStep(0.0001);
        niggli_tolerance->setValue(0.0001);

        gridLayout->addWidget(niggli_tolerance, 3, 3, 1, 1);

        beta = new QDoubleSpinBox(groupBox_3);
        beta->setObjectName(QStringLiteral("beta"));
        beta->setReadOnly(false);
        beta->setButtonSymbols(QAbstractSpinBox::NoButtons);
        beta->setDecimals(4);
        beta->setMinimum(-180);
        beta->setMaximum(180);

        gridLayout->addWidget(beta, 1, 3, 1, 1);

        label_gamma = new QLabel(groupBox_3);
        label_gamma->setObjectName(QStringLiteral("label_gamma"));

        gridLayout->addWidget(label_gamma, 1, 4, 1, 1);

        label_a = new QLabel(groupBox_3);
        label_a->setObjectName(QStringLiteral("label_a"));

        gridLayout->addWidget(label_a, 0, 0, 1, 1);

        a = new QDoubleSpinBox(groupBox_3);
        a->setObjectName(QStringLiteral("a"));
        a->setReadOnly(false);
        a->setButtonSymbols(QAbstractSpinBox::NoButtons);
        a->setDecimals(4);
        a->setMaximum(1e+6);

        gridLayout->addWidget(a, 0, 1, 1, 1);

        label_c = new QLabel(groupBox_3);
        label_c->setObjectName(QStringLiteral("label_c"));

        gridLayout->addWidget(label_c, 0, 4, 1, 1);

        c = new QDoubleSpinBox(groupBox_3);
        c->setObjectName(QStringLiteral("c"));
        c->setReadOnly(false);
        c->setButtonSymbols(QAbstractSpinBox::NoButtons);
        c->setDecimals(4);
        c->setMaximum(1e+6);

        gridLayout->addWidget(c, 0, 5, 1, 1);

        label_b = new QLabel(groupBox_3);
        label_b->setObjectName(QStringLiteral("label_b"));

        gridLayout->addWidget(label_b, 0, 2, 1, 1);

        label_alpha = new QLabel(groupBox_3);
        label_alpha->setObjectName(QStringLiteral("label_alpha"));

        gridLayout->addWidget(label_alpha, 1, 0, 1, 1);

        label_beta = new QLabel(groupBox_3);
        label_beta->setObjectName(QStringLiteral("label_beta"));

        gridLayout->addWidget(label_beta, 1, 2, 1, 1);

        niggli_only = new QCheckBox(groupBox_3);
        niggli_only->setObjectName(QStringLiteral("niggli_only"));

        gridLayout->addWidget(niggli_only, 3, 4, 1, 1);

        alpha = new QDoubleSpinBox(groupBox_3);
        alpha->setObjectName(QStringLiteral("alpha"));
        alpha->setReadOnly(false);
        alpha->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alpha->setDecimals(4);
        alpha->setMinimum(-180);
        alpha->setMaximum(180);

        gridLayout->addWidget(alpha, 1, 1, 1, 1);

        b = new QDoubleSpinBox(groupBox_3);
        b->setObjectName(QStringLiteral("b"));
        b->setReadOnly(false);
        b->setButtonSymbols(QAbstractSpinBox::NoButtons);
        b->setDecimals(4);
        b->setMaximum(1e+6);

        gridLayout->addWidget(b, 0, 3, 1, 1);

        gamma = new QDoubleSpinBox(groupBox_3);
        gamma->setObjectName(QStringLiteral("gamma"));
        gamma->setReadOnly(false);
        gamma->setButtonSymbols(QAbstractSpinBox::NoButtons);
        gamma->setDecimals(4);
        gamma->setMinimum(-180);
        gamma->setMaximum(180);

        gridLayout->addWidget(gamma, 1, 5, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 3, 2, 1, 1);

        label_wavelength = new QLabel(groupBox_3);
        label_wavelength->setObjectName(QStringLiteral("label_wavelength"));

        gridLayout->addWidget(label_wavelength, 2, 0, 1, 1);

        wavelength = new QDoubleSpinBox(groupBox_3);
        wavelength->setObjectName(QStringLiteral("wavelength"));
        wavelength->setButtonSymbols(QAbstractSpinBox::NoButtons);
        wavelength->setDecimals(3);
        wavelength->setSingleStep(0.01);

        gridLayout->addWidget(wavelength, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        angular_tolerance = new QDoubleSpinBox(groupBox_4);
        angular_tolerance->setObjectName(QStringLiteral("angular_tolerance"));
        angular_tolerance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        angular_tolerance->setDecimals(3);
        angular_tolerance->setMaximum(1);
        angular_tolerance->setSingleStep(0.01);
        angular_tolerance->setValue(0.01);

        gridLayout_2->addWidget(angular_tolerance, 0, 3, 1, 1);

        indexing_tolerance_label = new QLabel(groupBox_4);
        indexing_tolerance_label->setObjectName(QStringLiteral("indexing_tolerance_label"));

        gridLayout_2->addWidget(indexing_tolerance_label, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        indexing_threshold = new QDoubleSpinBox(groupBox_4);
        indexing_threshold->setObjectName(QStringLiteral("indexing_threshold"));
        indexing_threshold->setButtonSymbols(QAbstractSpinBox::NoButtons);
        indexing_threshold->setDecimals(3);
        indexing_threshold->setMinimum(0.5);
        indexing_threshold->setMaximum(1);
        indexing_threshold->setSingleStep(0.1);
        indexing_threshold->setValue(0.9);

        gridLayout_2->addWidget(indexing_threshold, 1, 3, 1, 1);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        indexing_tolerance = new QDoubleSpinBox(groupBox_4);
        indexing_tolerance->setObjectName(QStringLiteral("indexing_tolerance"));
        indexing_tolerance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        indexing_tolerance->setDecimals(3);
        indexing_tolerance->setMaximum(1);
        indexing_tolerance->setSingleStep(0.1);
        indexing_tolerance->setValue(0.2);

        gridLayout_2->addWidget(indexing_tolerance, 1, 1, 1, 1);

        distance_tolerance = new QDoubleSpinBox(groupBox_4);
        distance_tolerance->setObjectName(QStringLiteral("distance_tolerance"));
        distance_tolerance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        distance_tolerance->setDecimals(3);
        distance_tolerance->setMaximum(1);
        distance_tolerance->setSingleStep(0.01);
        distance_tolerance->setValue(0.01);

        gridLayout_2->addWidget(distance_tolerance, 0, 1, 1, 1);

        indexing_threshold_label = new QLabel(groupBox_4);
        indexing_threshold_label->setObjectName(QStringLiteral("indexing_threshold_label"));

        gridLayout_2->addWidget(indexing_threshold_label, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 1, 4, 1, 1);

        n_solutions = new QSpinBox(groupBox_4);
        n_solutions->setObjectName(QStringLiteral("n_solutions"));
        n_solutions->setWrapping(true);
        n_solutions->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        n_solutions->setMinimum(1);
        n_solutions->setMaximum(1000);
        n_solutions->setValue(10);

        gridLayout_2->addWidget(n_solutions, 1, 5, 1, 1);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 4, 1, 1);

        max_n_q_vectors = new QSpinBox(groupBox_4);
        max_n_q_vectors->setObjectName(QStringLiteral("max_n_q_vectors"));
        max_n_q_vectors->setWrapping(true);
        max_n_q_vectors->setMinimum(10);
        max_n_q_vectors->setMaximum(500);
        max_n_q_vectors->setValue(100);

        gridLayout_2->addWidget(max_n_q_vectors, 0, 5, 1, 1);


        verticalLayout->addWidget(groupBox_4);


        verticalLayout_2->addWidget(groupBox_2);

        unit_cells = new QTableView(settings);
        unit_cells->setObjectName(QStringLiteral("unit_cells"));
        unit_cells->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        verticalLayout_2->addWidget(unit_cells);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(2, 1);
        tabs->addTab(settings, QString());

        verticalLayout_3->addWidget(tabs);

        actions = new QDialogButtonBox(FrameUserDefinedUnitCellIndexer);
        actions->setObjectName(QStringLiteral("actions"));
        actions->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Reset);

        verticalLayout_3->addWidget(actions);

        QWidget::setTabOrder(peaks, a);
        QWidget::setTabOrder(a, b);
        QWidget::setTabOrder(b, c);
        QWidget::setTabOrder(c, alpha);
        QWidget::setTabOrder(alpha, beta);
        QWidget::setTabOrder(beta, gamma);
        QWidget::setTabOrder(gamma, wavelength);
        QWidget::setTabOrder(wavelength, gruber_tolerance);
        QWidget::setTabOrder(gruber_tolerance, niggli_tolerance);
        QWidget::setTabOrder(niggli_tolerance, niggli_only);
        QWidget::setTabOrder(niggli_only, distance_tolerance);
        QWidget::setTabOrder(distance_tolerance, angular_tolerance);
        QWidget::setTabOrder(angular_tolerance, max_n_q_vectors);
        QWidget::setTabOrder(max_n_q_vectors, indexing_tolerance);
        QWidget::setTabOrder(indexing_tolerance, indexing_threshold);
        QWidget::setTabOrder(indexing_threshold, n_solutions);
        QWidget::setTabOrder(n_solutions, unit_cells);
        QWidget::setTabOrder(unit_cells, tabs);

        retranslateUi(FrameUserDefinedUnitCellIndexer);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FrameUserDefinedUnitCellIndexer);
    } // setupUi

    void retranslateUi(NSXQFrame *FrameUserDefinedUnitCellIndexer)
    {
        FrameUserDefinedUnitCellIndexer->setWindowTitle(QApplication::translate("FrameUserDefinedUnitCellIndexer", "User defined unit cell indexer", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Parameters", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Unit cell", Q_NULLPTR));
        niggli_tolerance->setPrefix(QString());
#ifndef QT_NO_TOOLTIP
        beta->setToolTip(QApplication::translate("FrameUserDefinedUnitCellIndexer", "<html><head/><body><p>The \\u03B2 angle (in \\u00B0)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_gamma->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "gamma", Q_NULLPTR));
        label_a->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "a", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        a->setToolTip(QApplication::translate("FrameUserDefinedUnitCellIndexer", "<html><head/><body><p>The a axis length (in \\u212B)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_c->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "c", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        c->setToolTip(QApplication::translate("FrameUserDefinedUnitCellIndexer", "<html><head/><body><p>The c axis length (in \\u212B)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_b->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "b", Q_NULLPTR));
        label_alpha->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "alpha", Q_NULLPTR));
        label_beta->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "beta", Q_NULLPTR));
        niggli_only->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Niggli cell only", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        alpha->setToolTip(QApplication::translate("FrameUserDefinedUnitCellIndexer", "<html><head/><body><p>The \\u03B1 angle (in \\u00B0)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        b->setToolTip(QApplication::translate("FrameUserDefinedUnitCellIndexer", "<html><head/><body><p>The b axis length (in \\u212B)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        gamma->setToolTip(QApplication::translate("FrameUserDefinedUnitCellIndexer", "<html><head/><body><p>The \\u03B3 angle (in \\u00B0)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Gruber tolerance", Q_NULLPTR));
        label->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Niggli tolerance", Q_NULLPTR));
        label_wavelength->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Wavelength", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Indexing", Q_NULLPTR));
        indexing_tolerance_label->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Indexing tolerance", Q_NULLPTR));
        label_6->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Angular tolerance", Q_NULLPTR));
        label_5->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Distance tolerance", Q_NULLPTR));
        indexing_threshold_label->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Indexing threshold", Q_NULLPTR));
        label_4->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Number of solutions", Q_NULLPTR));
        label_3->setText(QApplication::translate("FrameUserDefinedUnitCellIndexer", "Max Q vectors", Q_NULLPTR));
        tabs->setTabText(tabs->indexOf(settings), QApplication::translate("FrameUserDefinedUnitCellIndexer", "settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FrameUserDefinedUnitCellIndexer: public Ui_FrameUserDefinedUnitCellIndexer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEUSERDEFINEDUNITCELLINDEXER_H
