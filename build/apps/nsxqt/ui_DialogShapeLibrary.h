/********************************************************************************
** Form generated from reading UI file 'DialogShapeLibrary.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSHAPELIBRARY_H
#define UI_DIALOGSHAPELIBRARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogShapeLibrary
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabs;
    QWidget *libraryTab;
    QFormLayout *formLayout_2;
    QLabel *label;
    QSpinBox *nx;
    QLabel *label_2;
    QSpinBox *ny;
    QLabel *label_3;
    QSpinBox *nz;
    QGroupBox *kabsch;
    QFormLayout *formLayout;
    QLabel *label_sigmaD;
    QDoubleSpinBox *sigmaD;
    QLabel *label_sigmaM;
    QDoubleSpinBox *sigmaM;
    QLabel *label_4;
    QDoubleSpinBox *Isigma;
    QLabel *label_5;
    QDoubleSpinBox *dMin;
    QLabel *label_6;
    QDoubleSpinBox *dMax;
    QLabel *label_7;
    QDoubleSpinBox *peakScale;
    QLabel *label_16;
    QDoubleSpinBox *bkgBegin;
    QLabel *label_17;
    QDoubleSpinBox *bkgEnd;
    QPushButton *build;
    QWidget *previewTab;
    QGridLayout *gridLayout_2;
    QTableView *peaks;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout_3;
    QLabel *label_11;
    QDoubleSpinBox *x;
    QLabel *label_12;
    QDoubleSpinBox *y;
    QLabel *label_13;
    QDoubleSpinBox *frame;
    QLabel *label_14;
    QDoubleSpinBox *radius;
    QLabel *label_15;
    QDoubleSpinBox *nframes;
    QPushButton *calculate;
    QVBoxLayout *verticalLayout;
    QGraphicsView *preview;
    QSlider *drawFrame;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogShapeLibrary)
    {
        if (DialogShapeLibrary->objectName().isEmpty())
            DialogShapeLibrary->setObjectName(QStringLiteral("DialogShapeLibrary"));
        DialogShapeLibrary->resize(643, 570);
        gridLayout = new QGridLayout(DialogShapeLibrary);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabs = new QTabWidget(DialogShapeLibrary);
        tabs->setObjectName(QStringLiteral("tabs"));
        libraryTab = new QWidget();
        libraryTab->setObjectName(QStringLiteral("libraryTab"));
        formLayout_2 = new QFormLayout(libraryTab);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label = new QLabel(libraryTab);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        nx = new QSpinBox(libraryTab);
        nx->setObjectName(QStringLiteral("nx"));
        nx->setMinimum(5);
        nx->setValue(20);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, nx);

        label_2 = new QLabel(libraryTab);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        ny = new QSpinBox(libraryTab);
        ny->setObjectName(QStringLiteral("ny"));
        ny->setMinimum(5);
        ny->setValue(20);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, ny);

        label_3 = new QLabel(libraryTab);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        nz = new QSpinBox(libraryTab);
        nz->setObjectName(QStringLiteral("nz"));
        nz->setMinimum(5);
        nz->setValue(20);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, nz);

        kabsch = new QGroupBox(libraryTab);
        kabsch->setObjectName(QStringLiteral("kabsch"));
        formLayout = new QFormLayout(kabsch);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_sigmaD = new QLabel(kabsch);
        label_sigmaD->setObjectName(QStringLiteral("label_sigmaD"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_sigmaD);

        sigmaD = new QDoubleSpinBox(kabsch);
        sigmaD->setObjectName(QStringLiteral("sigmaD"));
        sigmaD->setDecimals(4);
        sigmaD->setSingleStep(0.0001);
        sigmaD->setValue(0.5);

        formLayout->setWidget(0, QFormLayout::FieldRole, sigmaD);

        label_sigmaM = new QLabel(kabsch);
        label_sigmaM->setObjectName(QStringLiteral("label_sigmaM"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_sigmaM);

        sigmaM = new QDoubleSpinBox(kabsch);
        sigmaM->setObjectName(QStringLiteral("sigmaM"));
        sigmaM->setDecimals(4);
        sigmaM->setSingleStep(0.0001);
        sigmaM->setValue(0.3);

        formLayout->setWidget(1, QFormLayout::FieldRole, sigmaM);

        label_sigmaD->raise();
        label_sigmaM->raise();
        sigmaD->raise();
        sigmaM->raise();

        formLayout_2->setWidget(3, QFormLayout::LabelRole, kabsch);

        label_4 = new QLabel(libraryTab);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_4);

        Isigma = new QDoubleSpinBox(libraryTab);
        Isigma->setObjectName(QStringLiteral("Isigma"));
        Isigma->setSingleStep(0.01);
        Isigma->setValue(3);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, Isigma);

        label_5 = new QLabel(libraryTab);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_5);

        dMin = new QDoubleSpinBox(libraryTab);
        dMin->setObjectName(QStringLiteral("dMin"));
        dMin->setWrapping(true);
        dMin->setDecimals(2);
        dMin->setMaximum(10000);
        dMin->setSingleStep(0.01);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, dMin);

        label_6 = new QLabel(libraryTab);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_6);

        dMax = new QDoubleSpinBox(libraryTab);
        dMax->setObjectName(QStringLiteral("dMax"));
        dMax->setWrapping(true);
        dMax->setDecimals(2);
        dMax->setMaximum(10000);
        dMax->setSingleStep(0.01);
        dMax->setValue(100);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, dMax);

        label_7 = new QLabel(libraryTab);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_7);

        peakScale = new QDoubleSpinBox(libraryTab);
        peakScale->setObjectName(QStringLiteral("peakScale"));
        peakScale->setSingleStep(0.1);
        peakScale->setValue(3);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, peakScale);

        label_16 = new QLabel(libraryTab);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_16);

        bkgBegin = new QDoubleSpinBox(libraryTab);
        bkgBegin->setObjectName(QStringLiteral("bkgBegin"));
        bkgBegin->setSingleStep(0.1);
        bkgBegin->setValue(4);

        formLayout_2->setWidget(8, QFormLayout::FieldRole, bkgBegin);

        label_17 = new QLabel(libraryTab);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_17);

        bkgEnd = new QDoubleSpinBox(libraryTab);
        bkgEnd->setObjectName(QStringLiteral("bkgEnd"));
        bkgEnd->setSingleStep(0.1);
        bkgEnd->setValue(4.5);

        formLayout_2->setWidget(9, QFormLayout::FieldRole, bkgEnd);

        build = new QPushButton(libraryTab);
        build->setObjectName(QStringLiteral("build"));

        formLayout_2->setWidget(10, QFormLayout::LabelRole, build);

        tabs->addTab(libraryTab, QString());
        previewTab = new QWidget();
        previewTab->setObjectName(QStringLiteral("previewTab"));
        gridLayout_2 = new QGridLayout(previewTab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        peaks = new QTableView(previewTab);
        peaks->setObjectName(QStringLiteral("peaks"));

        gridLayout_2->addWidget(peaks, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_11 = new QLabel(previewTab);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_11);

        x = new QDoubleSpinBox(previewTab);
        x->setObjectName(QStringLiteral("x"));
        x->setSingleStep(0.01);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, x);

        label_12 = new QLabel(previewTab);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_12);

        y = new QDoubleSpinBox(previewTab);
        y->setObjectName(QStringLiteral("y"));
        y->setSingleStep(0.01);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, y);

        label_13 = new QLabel(previewTab);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_13);

        frame = new QDoubleSpinBox(previewTab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setSingleStep(0.01);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, frame);

        label_14 = new QLabel(previewTab);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_14);

        radius = new QDoubleSpinBox(previewTab);
        radius->setObjectName(QStringLiteral("radius"));
        radius->setSingleStep(0.01);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, radius);

        label_15 = new QLabel(previewTab);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_15);

        nframes = new QDoubleSpinBox(previewTab);
        nframes->setObjectName(QStringLiteral("nframes"));
        nframes->setSingleStep(0.01);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, nframes);

        calculate = new QPushButton(previewTab);
        calculate->setObjectName(QStringLiteral("calculate"));

        formLayout_3->setWidget(5, QFormLayout::SpanningRole, calculate);


        horizontalLayout->addLayout(formLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        preview = new QGraphicsView(previewTab);
        preview->setObjectName(QStringLiteral("preview"));

        verticalLayout->addWidget(preview);

        drawFrame = new QSlider(previewTab);
        drawFrame->setObjectName(QStringLiteral("drawFrame"));
        drawFrame->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(drawFrame);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        tabs->addTab(previewTab, QString());

        gridLayout->addWidget(tabs, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogShapeLibrary);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);


        retranslateUi(DialogShapeLibrary);
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogShapeLibrary, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogShapeLibrary, SLOT(accept()));

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogShapeLibrary);
    } // setupUi

    void retranslateUi(QDialog *DialogShapeLibrary)
    {
        DialogShapeLibrary->setWindowTitle(QApplication::translate("DialogShapeLibrary", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogShapeLibrary", "nx", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogShapeLibrary", "ny", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogShapeLibrary", "nz", Q_NULLPTR));
        kabsch->setTitle(QApplication::translate("DialogShapeLibrary", "Kabsch coordinates", Q_NULLPTR));
        label_sigmaD->setText(QApplication::translate("DialogShapeLibrary", "sigma D", Q_NULLPTR));
        label_sigmaM->setText(QApplication::translate("DialogShapeLibrary", "sigma M", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogShapeLibrary", "min I/sigma", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogShapeLibrary", "min. d", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogShapeLibrary", "max d.", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogShapeLibrary", "peak scale", Q_NULLPTR));
        label_16->setText(QApplication::translate("DialogShapeLibrary", "background begin", Q_NULLPTR));
        label_17->setText(QApplication::translate("DialogShapeLibrary", "background end", Q_NULLPTR));
        build->setText(QApplication::translate("DialogShapeLibrary", "Build Shape Library", Q_NULLPTR));
        tabs->setTabText(tabs->indexOf(libraryTab), QApplication::translate("DialogShapeLibrary", "Library", Q_NULLPTR));
        label_11->setText(QApplication::translate("DialogShapeLibrary", "x", Q_NULLPTR));
        label_12->setText(QApplication::translate("DialogShapeLibrary", "y", Q_NULLPTR));
        label_13->setText(QApplication::translate("DialogShapeLibrary", "frame", Q_NULLPTR));
        label_14->setText(QApplication::translate("DialogShapeLibrary", "radius", Q_NULLPTR));
        label_15->setText(QApplication::translate("DialogShapeLibrary", "n frames", Q_NULLPTR));
        calculate->setText(QApplication::translate("DialogShapeLibrary", "Calculate Mean Profile", Q_NULLPTR));
        tabs->setTabText(tabs->indexOf(previewTab), QApplication::translate("DialogShapeLibrary", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogShapeLibrary: public Ui_DialogShapeLibrary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSHAPELIBRARY_H
