/********************************************************************************
** Form generated from reading UI file 'PeakListPropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEAKLISTPROPERTYWIDGET_H
#define UI_PEAKLISTPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "views/PeakListView.h"

QT_BEGIN_NAMESPACE

class Ui_PeakListPropertyWidget
{
public:
    QGridLayout *gridLayout;
    PeakListView *tableView;

    void setupUi(QWidget *PeakListPropertyWidget)
    {
        if (PeakListPropertyWidget->objectName().isEmpty())
            PeakListPropertyWidget->setObjectName(QStringLiteral("PeakListPropertyWidget"));
        PeakListPropertyWidget->resize(995, 728);
        gridLayout = new QGridLayout(PeakListPropertyWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new PeakListView(PeakListPropertyWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setFocusPolicy(Qt::StrongFocus);
        tableView->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(PeakListPropertyWidget);

        QMetaObject::connectSlotsByName(PeakListPropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *PeakListPropertyWidget)
    {
        PeakListPropertyWidget->setWindowTitle(QApplication::translate("PeakListPropertyWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PeakListPropertyWidget: public Ui_PeakListPropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEAKLISTPROPERTYWIDGET_H
