/********************************************************************************
** Form generated from reading UI file 'NumorPropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMORPROPERTYWIDGET_H
#define UI_NUMORPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NumorPropertyWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_Data;
    QTableWidget *tableWidget;

    void setupUi(QWidget *NumorPropertyWidget)
    {
        if (NumorPropertyWidget->objectName().isEmpty())
            NumorPropertyWidget->setObjectName(QStringLiteral("NumorPropertyWidget"));
        NumorPropertyWidget->resize(300, 300);
        NumorPropertyWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(NumorPropertyWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(NumorPropertyWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_Data = new QLabel(NumorPropertyWidget);
        label_Data->setObjectName(QStringLiteral("label_Data"));

        horizontalLayout->addWidget(label_Data);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableWidget = new QTableWidget(NumorPropertyWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);


        retranslateUi(NumorPropertyWidget);

        QMetaObject::connectSlotsByName(NumorPropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *NumorPropertyWidget)
    {
        NumorPropertyWidget->setWindowTitle(QApplication::translate("NumorPropertyWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("NumorPropertyWidget", "Data:", Q_NULLPTR));
        label_Data->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NumorPropertyWidget: public Ui_NumorPropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMORPROPERTYWIDGET_H
