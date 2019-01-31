/********************************************************************************
** Form generated from reading UI file 'DialogPeakFilter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPEAKFILTER_H
#define UI_DIALOGPEAKFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "PeakListView.h"

QT_BEGIN_NAMESPACE

class Ui_DialogPeakFilter
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QGroupBox *state;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *selected;
    QCheckBox *masked;
    QCheckBox *predicted;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *indexed;
    QGroupBox *indexedByUnitCell;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QComboBox *unitCells;
    QLabel *label_3;
    QDoubleSpinBox *indexingTolerance;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *strength;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QDoubleSpinBox *strengthMin;
    QLabel *label_2;
    QDoubleSpinBox *strengthMax;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *dRange;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *dMin;
    QLabel *label_5;
    QDoubleSpinBox *dMax;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *extincted;
    QGroupBox *sparseDataSets;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpinBox *minNumPeaks;
    QSpacerItem *horizontalSpacer;
    QGroupBox *mergedPeakSignificance;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QDoubleSpinBox *significanceLevel;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *overlapping;
    QCheckBox *complementary;
    PeakListView *peaks;
    QDialogButtonBox *actions;

    void setupUi(QDialog *DialogPeakFilter)
    {
        if (DialogPeakFilter->objectName().isEmpty())
            DialogPeakFilter->setObjectName(QStringLiteral("DialogPeakFilter"));
        DialogPeakFilter->resize(803, 570);
        verticalLayout_2 = new QVBoxLayout(DialogPeakFilter);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        state = new QGroupBox(DialogPeakFilter);
        state->setObjectName(QStringLiteral("state"));
        state->setFlat(false);
        state->setCheckable(true);
        state->setChecked(true);
        horizontalLayout_4 = new QHBoxLayout(state);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        selected = new QCheckBox(state);
        selected->setObjectName(QStringLiteral("selected"));
        selected->setChecked(true);

        horizontalLayout_4->addWidget(selected);

        masked = new QCheckBox(state);
        masked->setObjectName(QStringLiteral("masked"));

        horizontalLayout_4->addWidget(masked);

        predicted = new QCheckBox(state);
        predicted->setObjectName(QStringLiteral("predicted"));

        horizontalLayout_4->addWidget(predicted);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalLayout_4->setStretch(3, 1);

        verticalLayout->addWidget(state);

        indexed = new QCheckBox(DialogPeakFilter);
        indexed->setObjectName(QStringLiteral("indexed"));

        verticalLayout->addWidget(indexed);

        indexedByUnitCell = new QGroupBox(DialogPeakFilter);
        indexedByUnitCell->setObjectName(QStringLiteral("indexedByUnitCell"));
        indexedByUnitCell->setCheckable(true);
        indexedByUnitCell->setChecked(false);
        horizontalLayout = new QHBoxLayout(indexedByUnitCell);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(indexedByUnitCell);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        unitCells = new QComboBox(indexedByUnitCell);
        unitCells->setObjectName(QStringLiteral("unitCells"));

        horizontalLayout->addWidget(unitCells);

        label_3 = new QLabel(indexedByUnitCell);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_3);

        indexingTolerance = new QDoubleSpinBox(indexedByUnitCell);
        indexingTolerance->setObjectName(QStringLiteral("indexingTolerance"));
        indexingTolerance->setDecimals(6);
        indexingTolerance->setMaximum(100);
        indexingTolerance->setValue(0.2);

        horizontalLayout->addWidget(indexingTolerance);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(3, 2);
        horizontalLayout->setStretch(4, 3);

        verticalLayout->addWidget(indexedByUnitCell);

        strength = new QGroupBox(DialogPeakFilter);
        strength->setObjectName(QStringLiteral("strength"));
        strength->setCheckable(true);
        strength->setChecked(false);
        horizontalLayout_3 = new QHBoxLayout(strength);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(strength);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        strengthMin = new QDoubleSpinBox(strength);
        strengthMin->setObjectName(QStringLiteral("strengthMin"));
        strengthMin->setDecimals(6);
        strengthMin->setMinimum(0);
        strengthMin->setMaximum(1e+6);
        strengthMin->setSingleStep(0.01);
        strengthMin->setValue(1);

        horizontalLayout_3->addWidget(strengthMin);

        label_2 = new QLabel(strength);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        strengthMax = new QDoubleSpinBox(strength);
        strengthMax->setObjectName(QStringLiteral("strengthMax"));
        strengthMax->setDecimals(6);
        strengthMax->setMinimum(0);
        strengthMax->setMaximum(1e+6);
        strengthMax->setSingleStep(0.01);
        strengthMax->setValue(3);

        horizontalLayout_3->addWidget(strengthMax);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_3->setStretch(4, 1);

        verticalLayout->addWidget(strength);

        dRange = new QGroupBox(DialogPeakFilter);
        dRange->setObjectName(QStringLiteral("dRange"));
        dRange->setCheckable(true);
        dRange->setChecked(false);
        horizontalLayout_2 = new QHBoxLayout(dRange);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(dRange);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        dMin = new QDoubleSpinBox(dRange);
        dMin->setObjectName(QStringLiteral("dMin"));
        dMin->setDecimals(6);
        dMin->setMaximum(1e+6);
        dMin->setSingleStep(0.01);

        horizontalLayout_2->addWidget(dMin);

        label_5 = new QLabel(dRange);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        dMax = new QDoubleSpinBox(dRange);
        dMax->setObjectName(QStringLiteral("dMax"));
        dMax->setDecimals(6);
        dMax->setMaximum(9999.99);
        dMax->setSingleStep(0.01);
        dMax->setValue(100);

        horizontalLayout_2->addWidget(dMax);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout_2->setStretch(4, 1);

        verticalLayout->addWidget(dRange);

        extincted = new QCheckBox(DialogPeakFilter);
        extincted->setObjectName(QStringLiteral("extincted"));

        verticalLayout->addWidget(extincted);

        sparseDataSets = new QGroupBox(DialogPeakFilter);
        sparseDataSets->setObjectName(QStringLiteral("sparseDataSets"));
        sparseDataSets->setCheckable(true);
        sparseDataSets->setChecked(false);
        horizontalLayout_5 = new QHBoxLayout(sparseDataSets);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(sparseDataSets);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        minNumPeaks = new QSpinBox(sparseDataSets);
        minNumPeaks->setObjectName(QStringLiteral("minNumPeaks"));
        minNumPeaks->setMaximum(100000);

        horizontalLayout_5->addWidget(minNumPeaks);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addWidget(sparseDataSets);

        mergedPeakSignificance = new QGroupBox(DialogPeakFilter);
        mergedPeakSignificance->setObjectName(QStringLiteral("mergedPeakSignificance"));
        mergedPeakSignificance->setCheckable(true);
        mergedPeakSignificance->setChecked(false);
        horizontalLayout_6 = new QHBoxLayout(mergedPeakSignificance);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(mergedPeakSignificance);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        significanceLevel = new QDoubleSpinBox(mergedPeakSignificance);
        significanceLevel->setObjectName(QStringLiteral("significanceLevel"));
        significanceLevel->setDecimals(6);
        significanceLevel->setMaximum(1);
        significanceLevel->setSingleStep(0.0001);
        significanceLevel->setValue(0.99);

        horizontalLayout_6->addWidget(significanceLevel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        horizontalLayout_6->setStretch(2, 1);

        verticalLayout->addWidget(mergedPeakSignificance);

        overlapping = new QCheckBox(DialogPeakFilter);
        overlapping->setObjectName(QStringLiteral("overlapping"));
        overlapping->setChecked(false);

        verticalLayout->addWidget(overlapping);

        complementary = new QCheckBox(DialogPeakFilter);
        complementary->setObjectName(QStringLiteral("complementary"));

        verticalLayout->addWidget(complementary);


        horizontalLayout_7->addLayout(verticalLayout);

        peaks = new PeakListView(DialogPeakFilter);
        peaks->setObjectName(QStringLiteral("peaks"));

        horizontalLayout_7->addWidget(peaks);

        horizontalLayout_7->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_7);

        actions = new QDialogButtonBox(DialogPeakFilter);
        actions->setObjectName(QStringLiteral("actions"));
        actions->setOrientation(Qt::Horizontal);
        actions->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(actions);


        retranslateUi(DialogPeakFilter);

        QMetaObject::connectSlotsByName(DialogPeakFilter);
    } // setupUi

    void retranslateUi(QDialog *DialogPeakFilter)
    {
        DialogPeakFilter->setWindowTitle(QApplication::translate("DialogPeakFilter", "Peak Filters", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        state->setToolTip(QApplication::translate("DialogPeakFilter", "<html><head/><body><p>Keep the peaks which are selected/unselected and/or masked/unmasked</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        state->setTitle(QApplication::translate("DialogPeakFilter", "State", Q_NULLPTR));
        selected->setText(QApplication::translate("DialogPeakFilter", "Selected", Q_NULLPTR));
        masked->setText(QApplication::translate("DialogPeakFilter", "Masked", Q_NULLPTR));
        predicted->setText(QApplication::translate("DialogPeakFilter", "Predicted", Q_NULLPTR));
        indexed->setText(QApplication::translate("DialogPeakFilter", "Indexed peak", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        indexedByUnitCell->setToolTip(QApplication::translate("DialogPeakFilter", "<html><head/><body><p>Keep the peaks which are indexable with a given unit cell</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        indexedByUnitCell->setTitle(QApplication::translate("DialogPeakFilter", "&Indexed peaks by unit cell", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogPeakFilter", "Unit cell", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogPeakFilter", "Tolerance", Q_NULLPTR));
        strength->setTitle(QApplication::translate("DialogPeakFilter", "Stren&gth (I/sigma)", Q_NULLPTR));
        label->setText(QApplication::translate("DialogPeakFilter", "Min.", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogPeakFilter", "Max.", Q_NULLPTR));
        dRange->setTitle(QApplication::translate("DialogPeakFilter", "&d range", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogPeakFilter", "Min.", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogPeakFilter", "Max.", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        extincted->setToolTip(QApplication::translate("DialogPeakFilter", "<html><head/><body><p>Keep the peaks which satisfy space group extinction law</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        extincted->setText(QApplication::translate("DialogPeakFilter", "Space-group extincted", Q_NULLPTR));
        sparseDataSets->setTitle(QApplication::translate("DialogPeakFilter", "Sparse datasets", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogPeakFilter", "Min. number of peaks", Q_NULLPTR));
        mergedPeakSignificance->setTitle(QApplication::translate("DialogPeakFilter", "&Merged peak significance", Q_NULLPTR));
        label_8->setText(QApplication::translate("DialogPeakFilter", "Significance level", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        overlapping->setToolTip(QApplication::translate("DialogPeakFilter", "<html><head/><body><p>Keep the peaks which do not overlap</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        overlapping->setText(QApplication::translate("DialogPeakFilter", "Remove overlapping peaks", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        complementary->setToolTip(QApplication::translate("DialogPeakFilter", "<html><head/><body><p>Keep the peaks filtered out by the aformentionned filters</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        complementary->setText(QApplication::translate("DialogPeakFilter", "Keep the complementary selection", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogPeakFilter: public Ui_DialogPeakFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPEAKFILTER_H
