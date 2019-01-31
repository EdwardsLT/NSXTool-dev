/********************************************************************************
** Form generated from reading UI file 'DialogIsotopesDatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGISOTOPESDATABASE_H
#define UI_DIALOGISOTOPESDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogIsotopesDatabase
{
public:
    QGridLayout *gridLayout;
    QTableView *isotopeDatabaseView;

    void setupUi(QDialog *DialogIsotopesDatabase)
    {
        if (DialogIsotopesDatabase->objectName().isEmpty())
            DialogIsotopesDatabase->setObjectName(QStringLiteral("DialogIsotopesDatabase"));
        DialogIsotopesDatabase->resize(400, 300);
        gridLayout = new QGridLayout(DialogIsotopesDatabase);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        isotopeDatabaseView = new QTableView(DialogIsotopesDatabase);
        isotopeDatabaseView->setObjectName(QStringLiteral("isotopeDatabaseView"));

        gridLayout->addWidget(isotopeDatabaseView, 0, 0, 1, 1);


        retranslateUi(DialogIsotopesDatabase);

        QMetaObject::connectSlotsByName(DialogIsotopesDatabase);
    } // setupUi

    void retranslateUi(QDialog *DialogIsotopesDatabase)
    {
        DialogIsotopesDatabase->setWindowTitle(QApplication::translate("DialogIsotopesDatabase", "Isotopes database", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogIsotopesDatabase: public Ui_DialogIsotopesDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGISOTOPESDATABASE_H
