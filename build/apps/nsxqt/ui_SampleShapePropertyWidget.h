/********************************************************************************
** Form generated from reading UI file 'SampleShapePropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLESHAPEPROPERTYWIDGET_H
#define UI_SAMPLESHAPEPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SampleShapePropertyWidget
{
public:
    QFormLayout *formLayout;
    QLineEdit *lineEdit_MovieFilename;
    QLabel *label_3;
    QLineEdit *lineEdit_Volume;
    QLabel *label_4;
    QLineEdit *lineEdit_Faces;
    QLabel *label_5;
    QLineEdit *lineEdit_Edges;
    QLabel *label_6;
    QLineEdit *lineEdit_Vertices;
    QPushButton *pushButton_LoadMovie;

    void setupUi(QWidget *SampleShapePropertyWidget)
    {
        if (SampleShapePropertyWidget->objectName().isEmpty())
            SampleShapePropertyWidget->setObjectName(QStringLiteral("SampleShapePropertyWidget"));
        SampleShapePropertyWidget->resize(350, 208);
        formLayout = new QFormLayout(SampleShapePropertyWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lineEdit_MovieFilename = new QLineEdit(SampleShapePropertyWidget);
        lineEdit_MovieFilename->setObjectName(QStringLiteral("lineEdit_MovieFilename"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_MovieFilename->sizePolicy().hasHeightForWidth());
        lineEdit_MovieFilename->setSizePolicy(sizePolicy);
        lineEdit_MovieFilename->setStyleSheet(QStringLiteral(""));
        lineEdit_MovieFilename->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_MovieFilename);

        label_3 = new QLabel(SampleShapePropertyWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_Volume = new QLineEdit(SampleShapePropertyWidget);
        lineEdit_Volume->setObjectName(QStringLiteral("lineEdit_Volume"));
        lineEdit_Volume->setStyleSheet(QStringLiteral(""));
        lineEdit_Volume->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_Volume);

        label_4 = new QLabel(SampleShapePropertyWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        lineEdit_Faces = new QLineEdit(SampleShapePropertyWidget);
        lineEdit_Faces->setObjectName(QStringLiteral("lineEdit_Faces"));
        lineEdit_Faces->setStyleSheet(QStringLiteral(""));
        lineEdit_Faces->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_Faces);

        label_5 = new QLabel(SampleShapePropertyWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        lineEdit_Edges = new QLineEdit(SampleShapePropertyWidget);
        lineEdit_Edges->setObjectName(QStringLiteral("lineEdit_Edges"));
        lineEdit_Edges->setStyleSheet(QStringLiteral(""));
        lineEdit_Edges->setReadOnly(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_Edges);

        label_6 = new QLabel(SampleShapePropertyWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_6);

        lineEdit_Vertices = new QLineEdit(SampleShapePropertyWidget);
        lineEdit_Vertices->setObjectName(QStringLiteral("lineEdit_Vertices"));
        lineEdit_Vertices->setStyleSheet(QStringLiteral(""));
        lineEdit_Vertices->setReadOnly(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit_Vertices);

        pushButton_LoadMovie = new QPushButton(SampleShapePropertyWidget);
        pushButton_LoadMovie->setObjectName(QStringLiteral("pushButton_LoadMovie"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_LoadMovie->sizePolicy().hasHeightForWidth());
        pushButton_LoadMovie->setSizePolicy(sizePolicy1);
        pushButton_LoadMovie->setStyleSheet(QStringLiteral(""));

        formLayout->setWidget(1, QFormLayout::LabelRole, pushButton_LoadMovie);

        QWidget::setTabOrder(lineEdit_MovieFilename, lineEdit_Volume);
        QWidget::setTabOrder(lineEdit_Volume, lineEdit_Faces);
        QWidget::setTabOrder(lineEdit_Faces, lineEdit_Edges);
        QWidget::setTabOrder(lineEdit_Edges, lineEdit_Vertices);

        retranslateUi(SampleShapePropertyWidget);

        QMetaObject::connectSlotsByName(SampleShapePropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *SampleShapePropertyWidget)
    {
        SampleShapePropertyWidget->setWindowTitle(QApplication::translate("SampleShapePropertyWidget", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("SampleShapePropertyWidget", "Volume", Q_NULLPTR));
        label_4->setText(QApplication::translate("SampleShapePropertyWidget", "Faces", Q_NULLPTR));
        label_5->setText(QApplication::translate("SampleShapePropertyWidget", "Edges", Q_NULLPTR));
        label_6->setText(QApplication::translate("SampleShapePropertyWidget", "Vertices", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_LoadMovie->setToolTip(QApplication::translate("SampleShapePropertyWidget", "<html><head/><body><p>Load a info file containing Video</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_LoadMovie->setText(QApplication::translate("SampleShapePropertyWidget", "Load Crystal Movie", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SampleShapePropertyWidget: public Ui_SampleShapePropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLESHAPEPROPERTYWIDGET_H
