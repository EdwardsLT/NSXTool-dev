/********************************************************************************
** Form generated from reading UI file 'ReciprocalSpaceViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIPROCALSPACEVIEWER_H
#define UI_RECIPROCALSPACEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include "QCustomPlot.h"

QT_BEGIN_NAMESPACE

class Ui_ReciprocalSpaceViewer
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QSpinBox *unitCell;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_13;
    QSpinBox *hOrig;
    QLabel *label_14;
    QSpinBox *kOrig;
    QLabel *label_15;
    QSpinBox *lOrig;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *h1Dir;
    QLabel *label_4;
    QSpinBox *k1Dir;
    QLabel *label_5;
    QSpinBox *l1Dir;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QSpinBox *h2Dir;
    QLabel *label_7;
    QSpinBox *k2Dir;
    QLabel *label_8;
    QSpinBox *l2Dir;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QDoubleSpinBox *dq;
    QLabel *label_10;
    QDoubleSpinBox *width;
    QSpacerItem *verticalSpacer_2;
    QPushButton *view;
    QCustomPlot *plot;

    void setupUi(QDialog *ReciprocalSpaceViewer)
    {
        if (ReciprocalSpaceViewer->objectName().isEmpty())
            ReciprocalSpaceViewer->setObjectName(QStringLiteral("ReciprocalSpaceViewer"));
        ReciprocalSpaceViewer->resize(970, 474);
        gridLayout_2 = new QGridLayout(ReciprocalSpaceViewer);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_11 = new QLabel(ReciprocalSpaceViewer);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);

        unitCell = new QSpinBox(ReciprocalSpaceViewer);
        unitCell->setObjectName(QStringLiteral("unitCell"));
        unitCell->setMinimum(1);
        unitCell->setMaximum(99999);

        horizontalLayout_4->addWidget(unitCell);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

        label_12 = new QLabel(ReciprocalSpaceViewer);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_13 = new QLabel(ReciprocalSpaceViewer);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_5->addWidget(label_13);

        hOrig = new QSpinBox(ReciprocalSpaceViewer);
        hOrig->setObjectName(QStringLiteral("hOrig"));

        horizontalLayout_5->addWidget(hOrig);

        label_14 = new QLabel(ReciprocalSpaceViewer);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_5->addWidget(label_14);

        kOrig = new QSpinBox(ReciprocalSpaceViewer);
        kOrig->setObjectName(QStringLiteral("kOrig"));

        horizontalLayout_5->addWidget(kOrig);

        label_15 = new QLabel(ReciprocalSpaceViewer);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_5->addWidget(label_15);

        lOrig = new QSpinBox(ReciprocalSpaceViewer);
        lOrig->setObjectName(QStringLiteral("lOrig"));

        horizontalLayout_5->addWidget(lOrig);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        label = new QLabel(ReciprocalSpaceViewer);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(ReciprocalSpaceViewer);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        h1Dir = new QSpinBox(ReciprocalSpaceViewer);
        h1Dir->setObjectName(QStringLiteral("h1Dir"));

        horizontalLayout->addWidget(h1Dir);

        label_4 = new QLabel(ReciprocalSpaceViewer);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        k1Dir = new QSpinBox(ReciprocalSpaceViewer);
        k1Dir->setObjectName(QStringLiteral("k1Dir"));

        horizontalLayout->addWidget(k1Dir);

        label_5 = new QLabel(ReciprocalSpaceViewer);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        l1Dir = new QSpinBox(ReciprocalSpaceViewer);
        l1Dir->setObjectName(QStringLiteral("l1Dir"));

        horizontalLayout->addWidget(l1Dir);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        label_2 = new QLabel(ReciprocalSpaceViewer);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(ReciprocalSpaceViewer);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        h2Dir = new QSpinBox(ReciprocalSpaceViewer);
        h2Dir->setObjectName(QStringLiteral("h2Dir"));

        horizontalLayout_2->addWidget(h2Dir);

        label_7 = new QLabel(ReciprocalSpaceViewer);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        k2Dir = new QSpinBox(ReciprocalSpaceViewer);
        k2Dir->setObjectName(QStringLiteral("k2Dir"));

        horizontalLayout_2->addWidget(k2Dir);

        label_8 = new QLabel(ReciprocalSpaceViewer);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        l2Dir = new QSpinBox(ReciprocalSpaceViewer);
        l2Dir->setObjectName(QStringLiteral("l2Dir"));

        horizontalLayout_2->addWidget(l2Dir);


        gridLayout->addLayout(horizontalLayout_2, 7, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(ReciprocalSpaceViewer);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        dq = new QDoubleSpinBox(ReciprocalSpaceViewer);
        dq->setObjectName(QStringLiteral("dq"));
        dq->setDecimals(5);
        dq->setSingleStep(0.001);
        dq->setValue(0.01);

        horizontalLayout_3->addWidget(dq);

        label_10 = new QLabel(ReciprocalSpaceViewer);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        width = new QDoubleSpinBox(ReciprocalSpaceViewer);
        width->setObjectName(QStringLiteral("width"));
        width->setDecimals(5);
        width->setValue(1);

        horizontalLayout_3->addWidget(width);


        gridLayout->addLayout(horizontalLayout_3, 8, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 9, 0, 1, 1);

        view = new QPushButton(ReciprocalSpaceViewer);
        view->setObjectName(QStringLiteral("view"));

        gridLayout->addWidget(view, 10, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        plot = new QCustomPlot(ReciprocalSpaceViewer);
        plot->setObjectName(QStringLiteral("plot"));

        gridLayout_2->addWidget(plot, 0, 1, 1, 1);


        retranslateUi(ReciprocalSpaceViewer);

        QMetaObject::connectSlotsByName(ReciprocalSpaceViewer);
    } // setupUi

    void retranslateUi(QDialog *ReciprocalSpaceViewer)
    {
        ReciprocalSpaceViewer->setWindowTitle(QApplication::translate("ReciprocalSpaceViewer", "Dialog", Q_NULLPTR));
        label_11->setText(QApplication::translate("ReciprocalSpaceViewer", "Unit cell", Q_NULLPTR));
        label_12->setText(QApplication::translate("ReciprocalSpaceViewer", "Cut from", Q_NULLPTR));
        label_13->setText(QApplication::translate("ReciprocalSpaceViewer", "h", Q_NULLPTR));
        label_14->setText(QApplication::translate("ReciprocalSpaceViewer", "k", Q_NULLPTR));
        label_15->setText(QApplication::translate("ReciprocalSpaceViewer", "l", Q_NULLPTR));
        label->setText(QApplication::translate("ReciprocalSpaceViewer", "Cut plane 1", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReciprocalSpaceViewer", "h", Q_NULLPTR));
        label_4->setText(QApplication::translate("ReciprocalSpaceViewer", "k", Q_NULLPTR));
        label_5->setText(QApplication::translate("ReciprocalSpaceViewer", "l", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReciprocalSpaceViewer", "Cut plane 2", Q_NULLPTR));
        label_6->setText(QApplication::translate("ReciprocalSpaceViewer", "h", Q_NULLPTR));
        label_7->setText(QApplication::translate("ReciprocalSpaceViewer", "k", Q_NULLPTR));
        label_8->setText(QApplication::translate("ReciprocalSpaceViewer", "l", Q_NULLPTR));
        label_9->setText(QApplication::translate("ReciprocalSpaceViewer", "dq", Q_NULLPTR));
        label_10->setText(QApplication::translate("ReciprocalSpaceViewer", "width", Q_NULLPTR));
        view->setText(QApplication::translate("ReciprocalSpaceViewer", "View", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReciprocalSpaceViewer: public Ui_ReciprocalSpaceViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIPROCALSPACEVIEWER_H
