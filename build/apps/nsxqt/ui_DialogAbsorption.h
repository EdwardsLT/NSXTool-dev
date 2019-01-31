/********************************************************************************
** Form generated from reading UI file 'DialogAbsorption.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGABSORPTION_H
#define UI_DIALOGABSORPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAbsorption
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QScrollBar *horizontalScrollBar;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_openFile;
    QPushButton *button_calibrateDistance;
    QPushButton *button_pickCenter;
    QPushButton *button_pickingPoints;
    QPushButton *button_removingPoints;
    QPushButton *button_triangulate;

    void setupUi(QDialog *DialogAbsorption)
    {
        if (DialogAbsorption->objectName().isEmpty())
            DialogAbsorption->setObjectName(QStringLiteral("DialogAbsorption"));
        DialogAbsorption->setWindowModality(Qt::ApplicationModal);
        DialogAbsorption->resize(893, 639);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogAbsorption->sizePolicy().hasHeightForWidth());
        DialogAbsorption->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(DialogAbsorption);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 9, 802, 621));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(layoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(800, 600));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(graphicsView);

        horizontalScrollBar = new QScrollBar(layoutWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);

        layoutWidget1 = new QWidget(DialogAbsorption);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 51, 331));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        button_openFile = new QPushButton(layoutWidget1);
        button_openFile->setObjectName(QStringLiteral("button_openFile"));
        button_openFile->setEnabled(true);
        button_openFile->setStyleSheet(QStringLiteral(""));
        button_openFile->setText(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/openFileIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_openFile->setIcon(icon);
        button_openFile->setIconSize(QSize(40, 40));
        button_openFile->setFlat(false);

        verticalLayout_2->addWidget(button_openFile);

        button_calibrateDistance = new QPushButton(layoutWidget1);
        button_calibrateDistance->setObjectName(QStringLiteral("button_calibrateDistance"));
        button_calibrateDistance->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/IconcalibrateDistance.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_calibrateDistance->setIcon(icon1);
        button_calibrateDistance->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(button_calibrateDistance);

        button_pickCenter = new QPushButton(layoutWidget1);
        button_pickCenter->setObjectName(QStringLiteral("button_pickCenter"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resources/IconpickCenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_pickCenter->setIcon(icon2);
        button_pickCenter->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(button_pickCenter);

        button_pickingPoints = new QPushButton(layoutWidget1);
        button_pickingPoints->setObjectName(QStringLiteral("button_pickingPoints"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/resources/IconpickingPoints.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_pickingPoints->setIcon(icon3);
        button_pickingPoints->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(button_pickingPoints);

        button_removingPoints = new QPushButton(layoutWidget1);
        button_removingPoints->setObjectName(QStringLiteral("button_removingPoints"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/resources/IconremovingPoints.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_removingPoints->setIcon(icon4);
        button_removingPoints->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(button_removingPoints);

        button_triangulate = new QPushButton(layoutWidget1);
        button_triangulate->setObjectName(QStringLiteral("button_triangulate"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/resources/Icontriangulate.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_triangulate->setIcon(icon5);
        button_triangulate->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(button_triangulate);


        retranslateUi(DialogAbsorption);

        QMetaObject::connectSlotsByName(DialogAbsorption);
    } // setupUi

    void retranslateUi(QDialog *DialogAbsorption)
    {
        DialogAbsorption->setWindowTitle(QApplication::translate("DialogAbsorption", "NSXTool - Absorption Correction", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        button_openFile->setToolTip(QApplication::translate("DialogAbsorption", "Open ILL *jpr file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        button_calibrateDistance->setToolTip(QApplication::translate("DialogAbsorption", "Calibrate distance using ruler", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        button_calibrateDistance->setText(QString());
#ifndef QT_NO_TOOLTIP
        button_pickCenter->setToolTip(QApplication::translate("DialogAbsorption", "Calibrate the pin position", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        button_pickCenter->setText(QString());
#ifndef QT_NO_TOOLTIP
        button_pickingPoints->setToolTip(QApplication::translate("DialogAbsorption", "Add point to the Hull", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        button_pickingPoints->setText(QString());
#ifndef QT_NO_TOOLTIP
        button_removingPoints->setToolTip(QApplication::translate("DialogAbsorption", "Remove existing points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        button_removingPoints->setText(QString());
#ifndef QT_NO_TOOLTIP
        button_triangulate->setToolTip(QApplication::translate("DialogAbsorption", "Construct convex hull from points", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        button_triangulate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogAbsorption: public Ui_DialogAbsorption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGABSORPTION_H
