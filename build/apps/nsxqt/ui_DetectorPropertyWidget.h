/********************************************************************************
** Form generated from reading UI file 'DetectorPropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTORPROPERTYWIDGET_H
#define UI_DETECTORPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectorPropertyWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QDoubleSpinBox *width;
    QLabel *label_5;
    QSpinBox *rows;
    QDoubleSpinBox *height;
    QLabel *label_7;
    QDoubleSpinBox *sample_to_detector_distance;
    QSpinBox *columns;
    QLabel *label_2;
    QLabel *label_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTableWidget *axes;

    void setupUi(QWidget *DetectorPropertyWidget)
    {
        if (DetectorPropertyWidget->objectName().isEmpty())
            DetectorPropertyWidget->setObjectName(QStringLiteral("DetectorPropertyWidget"));
        DetectorPropertyWidget->resize(479, 381);
        verticalLayout_2 = new QVBoxLayout(DetectorPropertyWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_2 = new QGroupBox(DetectorPropertyWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        width = new QDoubleSpinBox(groupBox_2);
        width->setObjectName(QStringLiteral("width"));
        width->setReadOnly(true);
        width->setButtonSymbols(QAbstractSpinBox::NoButtons);
        width->setDecimals(5);
        width->setMaximum(10000);

        gridLayout->addWidget(width, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        rows = new QSpinBox(groupBox_2);
        rows->setObjectName(QStringLiteral("rows"));
        rows->setReadOnly(true);
        rows->setButtonSymbols(QAbstractSpinBox::NoButtons);
        rows->setMaximum(100000);

        gridLayout->addWidget(rows, 1, 1, 1, 1);

        height = new QDoubleSpinBox(groupBox_2);
        height->setObjectName(QStringLiteral("height"));
        height->setReadOnly(true);
        height->setButtonSymbols(QAbstractSpinBox::NoButtons);
        height->setDecimals(5);
        height->setMaximum(10000);

        gridLayout->addWidget(height, 0, 3, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        sample_to_detector_distance = new QDoubleSpinBox(groupBox_2);
        sample_to_detector_distance->setObjectName(QStringLiteral("sample_to_detector_distance"));
        sample_to_detector_distance->setReadOnly(true);
        sample_to_detector_distance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sample_to_detector_distance->setDecimals(5);
        sample_to_detector_distance->setMinimum(0);

        gridLayout->addWidget(sample_to_detector_distance, 2, 1, 1, 1);

        columns = new QSpinBox(groupBox_2);
        columns->setObjectName(QStringLiteral("columns"));
        columns->setReadOnly(true);
        columns->setButtonSymbols(QAbstractSpinBox::NoButtons);
        columns->setMaximum(100000);

        gridLayout->addWidget(columns, 1, 3, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(DetectorPropertyWidget);
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


        retranslateUi(DetectorPropertyWidget);

        QMetaObject::connectSlotsByName(DetectorPropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *DetectorPropertyWidget)
    {
        DetectorPropertyWidget->setWindowTitle(QApplication::translate("DetectorPropertyWidget", "Form", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("DetectorPropertyWidget", "Parameters", Q_NULLPTR));
        label_3->setText(QApplication::translate("DetectorPropertyWidget", "Height", Q_NULLPTR));
        label_5->setText(QApplication::translate("DetectorPropertyWidget", "Rows", Q_NULLPTR));
        label_7->setText(QApplication::translate("DetectorPropertyWidget", "Distance", Q_NULLPTR));
        label_2->setText(QApplication::translate("DetectorPropertyWidget", "Width", Q_NULLPTR));
        label_4->setText(QApplication::translate("DetectorPropertyWidget", "Columns", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DetectorPropertyWidget", "Goniometer", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = axes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DetectorPropertyWidget", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = axes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DetectorPropertyWidget", "Type", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DetectorPropertyWidget: public Ui_DetectorPropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTORPROPERTYWIDGET_H
