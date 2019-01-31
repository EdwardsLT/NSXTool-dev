/********************************************************************************
** Form generated from reading UI file 'EmptyPropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPTYPROPERTYWIDGET_H
#define UI_EMPTYPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmptyPropertyWidget
{
public:

    void setupUi(QWidget *EmptyPropertyWidget)
    {
        if (EmptyPropertyWidget->objectName().isEmpty())
            EmptyPropertyWidget->setObjectName(QStringLiteral("EmptyPropertyWidget"));
        EmptyPropertyWidget->resize(400, 300);

        retranslateUi(EmptyPropertyWidget);

        QMetaObject::connectSlotsByName(EmptyPropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *EmptyPropertyWidget)
    {
        EmptyPropertyWidget->setWindowTitle(QApplication::translate("EmptyPropertyWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EmptyPropertyWidget: public Ui_EmptyPropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPTYPROPERTYWIDGET_H
