/********************************************************************************
** Form generated from reading UI file 'SamplePropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLEPROPERTYWIDGET_H
#define UI_SAMPLEPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SamplePropertyWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTableWidget *axes;

    void setupUi(QWidget *SamplePropertyWidget)
    {
        if (SamplePropertyWidget->objectName().isEmpty())
            SamplePropertyWidget->setObjectName(QStringLiteral("SamplePropertyWidget"));
        SamplePropertyWidget->resize(346, 253);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SamplePropertyWidget->sizePolicy().hasHeightForWidth());
        SamplePropertyWidget->setSizePolicy(sizePolicy);
        SamplePropertyWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(SamplePropertyWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(SamplePropertyWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        axes = new QTableWidget(groupBox);
        if (axes->columnCount() < 2)
            axes->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        axes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        axes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        axes->setObjectName(QStringLiteral("axes"));
        axes->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(axes);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(SamplePropertyWidget);

        QMetaObject::connectSlotsByName(SamplePropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *SamplePropertyWidget)
    {
        SamplePropertyWidget->setWindowTitle(QApplication::translate("SamplePropertyWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SamplePropertyWidget", "Goniometer", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = axes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SamplePropertyWidget", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = axes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SamplePropertyWidget", "Type", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SamplePropertyWidget: public Ui_SamplePropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLEPROPERTYWIDGET_H
