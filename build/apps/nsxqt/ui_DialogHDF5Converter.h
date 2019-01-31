/********************************************************************************
** Form generated from reading UI file 'DialogHDF5Converter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGHDF5CONVERTER_H
#define UI_DIALOGHDF5CONVERTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogHDF5Converter
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *outputDirectory;
    QPushButton *browseOutputDirectory;
    QProgressBar *progressBar_conversion;
    QDialogButtonBox *cancelOK;

    void setupUi(QDialog *DialogHDF5Converter)
    {
        if (DialogHDF5Converter->objectName().isEmpty())
            DialogHDF5Converter->setObjectName(QStringLiteral("DialogHDF5Converter"));
        DialogHDF5Converter->resize(700, 145);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogHDF5Converter->sizePolicy().hasHeightForWidth());
        DialogHDF5Converter->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DialogHDF5Converter);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DialogHDF5Converter);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        outputDirectory = new QLineEdit(DialogHDF5Converter);
        outputDirectory->setObjectName(QStringLiteral("outputDirectory"));
        outputDirectory->setReadOnly(true);

        horizontalLayout->addWidget(outputDirectory);

        browseOutputDirectory = new QPushButton(DialogHDF5Converter);
        browseOutputDirectory->setObjectName(QStringLiteral("browseOutputDirectory"));
        browseOutputDirectory->setAutoDefault(false);

        horizontalLayout->addWidget(browseOutputDirectory);


        verticalLayout->addLayout(horizontalLayout);

        progressBar_conversion = new QProgressBar(DialogHDF5Converter);
        progressBar_conversion->setObjectName(QStringLiteral("progressBar_conversion"));
        progressBar_conversion->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        progressBar_conversion->setValue(0);

        verticalLayout->addWidget(progressBar_conversion);

        cancelOK = new QDialogButtonBox(DialogHDF5Converter);
        cancelOK->setObjectName(QStringLiteral("cancelOK"));
        cancelOK->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(cancelOK);


        retranslateUi(DialogHDF5Converter);

        QMetaObject::connectSlotsByName(DialogHDF5Converter);
    } // setupUi

    void retranslateUi(QDialog *DialogHDF5Converter)
    {
        DialogHDF5Converter->setWindowTitle(QApplication::translate("DialogHDF5Converter", "HDF5 converter", Q_NULLPTR));
        label->setText(QApplication::translate("DialogHDF5Converter", "Output directory:", Q_NULLPTR));
        browseOutputDirectory->setText(QApplication::translate("DialogHDF5Converter", "Browse", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogHDF5Converter: public Ui_DialogHDF5Converter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGHDF5CONVERTER_H
