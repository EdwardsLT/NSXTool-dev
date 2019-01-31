/********************************************************************************
** Form generated from reading UI file 'DialogMCAbsorption.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMCABSORPTION_H
#define UI_DIALOGMCABSORPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogMCAbsorption
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *unitCells;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_run;
    QProgressBar *progressBar_MCStatus;

    void setupUi(QDialog *DialogMCAbsorption)
    {
        if (DialogMCAbsorption->objectName().isEmpty())
            DialogMCAbsorption->setObjectName(QStringLiteral("DialogMCAbsorption"));
        DialogMCAbsorption->setWindowModality(Qt::ApplicationModal);
        DialogMCAbsorption->resize(254, 224);
        layoutWidget = new QWidget(DialogMCAbsorption);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 217, 146));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        unitCells = new QComboBox(layoutWidget);
        unitCells->setObjectName(QStringLiteral("unitCells"));

        horizontalLayout->addWidget(unitCells);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(100);
        spinBox->setMaximum(1000000);
        spinBox->setSingleStep(1000);
        spinBox->setValue(1000);

        horizontalLayout_2->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        pushButton_run = new QPushButton(layoutWidget);
        pushButton_run->setObjectName(QStringLiteral("pushButton_run"));
        pushButton_run->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #ffd9aa,\n"
"                stop :   0.5 #ffbb6e, stop :   0.55 #feae42, stop :   1.0 #fedb74);\n"
"}\n"
"\n"
"QPushButton {\n"
"        border: 1px solid #6593cf;\n"
"        border-radius: 2px;\n"
"        padding: 5px 15px 2px 5px;\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #f5f9ff,\n"
"                stop :   0.5 #c7dfff, stop :   0.55 #afd2ff, stop :   1.0 #c0dbff);\n"
"        color: #006aff;\n"
"        font: bold large \"Arial\";\n"
"        height: 30px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, stop :   0.0 #c0dbff,\n"
"        stop :   0.5 #cfd26f, stop :   0.55 #c7df6f, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton:on {\n"
"        background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 :   1, "
                        "stop :   0.0 #5AA72D,\n"
"        stop :   0.5 #B3E296, stop :   0.55 #B3E296, stop :   1.0 #f5f9ff);\n"
"        padding-top: 2px;\n"
"        padding-left: 3px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"        background: transparent #e5e9ee;\n"
"        padding-top: 2px;        \n"
"        padding-left: 3px;\n"
"        color: black;\n"
"}"));

        gridLayout->addWidget(pushButton_run, 2, 0, 1, 1);

        progressBar_MCStatus = new QProgressBar(layoutWidget);
        progressBar_MCStatus->setObjectName(QStringLiteral("progressBar_MCStatus"));
        progressBar_MCStatus->setStyleSheet(QLatin1String("QProgressBar {\n"
"                                         border: 1px solid black;\n"
"                                         text-align: center;\n"
"											  color: white;\n"
"                                         padding: 1px;\n"
"                                         border-bottom-right-radius: 7px;\n"
"                                         border-bottom-left-radius: 7px;\n"
"                                         background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"                                         stop: 0 #eee,\n"
"                                         stop: 0.5 #ddd,\n"
"                                         stop: 1 #eee );\n"
"                                         width: 15px;\n"
"                                         }\n"
"                                         \n"
"                                         QProgressBar::chunk {\n"
"                                         background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"                       "
                        "                  stop: 0 #78d,\n"
"                                         stop: 1 #238 );\n"
"                                         border-bottom-right-radius: 7px;\n"
"                                         border-bottom-left-radius: 7px;\n"
"                                         border: 1px solid black;\n"
"                                         }"));
        progressBar_MCStatus->setValue(24);

        gridLayout->addWidget(progressBar_MCStatus, 3, 0, 1, 1);


        retranslateUi(DialogMCAbsorption);

        QMetaObject::connectSlotsByName(DialogMCAbsorption);
    } // setupUi

    void retranslateUi(QDialog *DialogMCAbsorption)
    {
        DialogMCAbsorption->setWindowTitle(QApplication::translate("DialogMCAbsorption", "Monte-Carlo absorption Correction", Q_NULLPTR));
        label->setText(QApplication::translate("DialogMCAbsorption", "Crystal reference:", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogMCAbsorption", "Number of rays:", Q_NULLPTR));
        pushButton_run->setText(QApplication::translate("DialogMCAbsorption", "Run Monte-Carlo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogMCAbsorption: public Ui_DialogMCAbsorption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMCABSORPTION_H
