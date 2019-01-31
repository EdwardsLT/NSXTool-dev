/********************************************************************************
** Form generated from reading UI file 'DialogExperiment.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEXPERIMENT_H
#define UI_DIALOGEXPERIMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogExperiment
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *experiment;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *instrument;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogExperiment)
    {
        if (DialogExperiment->objectName().isEmpty())
            DialogExperiment->setObjectName(QStringLiteral("DialogExperiment"));
        DialogExperiment->setWindowModality(Qt::ApplicationModal);
        DialogExperiment->resize(500, 130);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogExperiment->sizePolicy().hasHeightForWidth());
        DialogExperiment->setSizePolicy(sizePolicy);
        DialogExperiment->setMinimumSize(QSize(500, 130));
        DialogExperiment->setMaximumSize(QSize(500, 130));
        gridLayout = new QGridLayout(DialogExperiment);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DialogExperiment);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        experiment = new QTextEdit(DialogExperiment);
        experiment->setObjectName(QStringLiteral("experiment"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(experiment->sizePolicy().hasHeightForWidth());
        experiment->setSizePolicy(sizePolicy2);
        experiment->setMaximumSize(QSize(200, 30));
        experiment->setStyleSheet(QLatin1String("QTextEdit {\n"
"    border: 1px solid blue;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: white;\n"
"    selection-background-color: white;\n"
"}"));

        horizontalLayout->addWidget(experiment);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(DialogExperiment);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        instrument = new QComboBox(DialogExperiment);
        instrument->setObjectName(QStringLiteral("instrument"));
        instrument->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_2->addWidget(instrument);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DialogExperiment);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStyleSheet(QStringLiteral(""));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);


        retranslateUi(DialogExperiment);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogExperiment, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogExperiment, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogExperiment);
    } // setupUi

    void retranslateUi(QDialog *DialogExperiment)
    {
        DialogExperiment->setWindowTitle(QApplication::translate("DialogExperiment", "New Experiment", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        DialogExperiment->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("DialogExperiment", "Name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogExperiment", "Instrument:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogExperiment: public Ui_DialogExperiment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEXPERIMENT_H
