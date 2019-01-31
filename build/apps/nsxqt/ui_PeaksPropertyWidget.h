/********************************************************************************
** Form generated from reading UI file 'PeaksPropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEAKSPROPERTYWIDGET_H
#define UI_PEAKSPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "PeakListView.h"

QT_BEGIN_NAMESPACE

class Ui_PeaksPropertyWidget
{
public:
    QGridLayout *gridLayout;
    PeakListView *tableView;

    void setupUi(QWidget *PeaksPropertyWidget)
    {
        if (PeaksPropertyWidget->objectName().isEmpty())
            PeaksPropertyWidget->setObjectName(QStringLiteral("PeaksPropertyWidget"));
        PeaksPropertyWidget->resize(995, 728);
        gridLayout = new QGridLayout(PeaksPropertyWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new PeakListView(PeaksPropertyWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setFocusPolicy(Qt::StrongFocus);
        tableView->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(PeaksPropertyWidget);

        QMetaObject::connectSlotsByName(PeaksPropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *PeaksPropertyWidget)
    {
        PeaksPropertyWidget->setWindowTitle(QApplication::translate("PeaksPropertyWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PeaksPropertyWidget: public Ui_PeaksPropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEAKSPROPERTYWIDGET_H
