/********************************************************************************
** Form generated from reading UI file 'WidgetFoundPeaks.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETFOUNDPEAKS_H
#define UI_WIDGETFOUNDPEAKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "PeakListView.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetFoundPeaks
{
public:
    QVBoxLayout *verticalLayout;
    PeakListView *peaks;
    QCheckBox *keep_selected_peaks;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(840, 639);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        peaks = new PeakListView(Form);
        peaks->setObjectName(QStringLiteral("peaks"));

        verticalLayout->addWidget(peaks);

        keep_selected_peaks = new QCheckBox(Form);
        keep_selected_peaks->setObjectName(QStringLiteral("keep_selected_peaks"));

        verticalLayout->addWidget(keep_selected_peaks);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("WidgetFoundPeaks", "Form", Q_NULLPTR));
        keep_selected_peaks->setText(QApplication::translate("WidgetFoundPeaks", "keep only selected peaks", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetFoundPeaks: public Ui_WidgetFoundPeaks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETFOUNDPEAKS_H
