/********************************************************************************
** Form generated from reading UI file 'DialogSpaceGroup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSPACEGROUP_H
#define UI_DIALOGSPACEGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogSpaceGroup
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QDialogButtonBox *cancelOK;

    void setupUi(QDialog *DialogSpaceGroup)
    {
        if (DialogSpaceGroup->objectName().isEmpty())
            DialogSpaceGroup->setObjectName(QStringLiteral("DialogSpaceGroup"));
        DialogSpaceGroup->resize(919, 590);
        DialogSpaceGroup->setModal(false);
        gridLayout = new QGridLayout(DialogSpaceGroup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(DialogSpaceGroup);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        cancelOK = new QDialogButtonBox(DialogSpaceGroup);
        cancelOK->setObjectName(QStringLiteral("cancelOK"));
        cancelOK->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(cancelOK, 1, 0, 1, 1);


        retranslateUi(DialogSpaceGroup);

        QMetaObject::connectSlotsByName(DialogSpaceGroup);
    } // setupUi

    void retranslateUi(QDialog *DialogSpaceGroup)
    {
        DialogSpaceGroup->setWindowTitle(QApplication::translate("DialogSpaceGroup", "Compatible Space Groups", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogSpaceGroup: public Ui_DialogSpaceGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSPACEGROUP_H
