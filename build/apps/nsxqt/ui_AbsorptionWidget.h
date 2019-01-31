/********************************************************************************
** Form generated from reading UI file 'AbsorptionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABSORPTIONWIDGET_H
#define UI_ABSORPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AbsorptionWidget
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QScrollBar *horizontalScrollBar;
    QPushButton *pushButton;

    void setupUi(QWidget *AbsorptionWidget)
    {
        if (AbsorptionWidget->objectName().isEmpty())
            AbsorptionWidget->setObjectName(QStringLiteral("AbsorptionWidget"));
        AbsorptionWidget->resize(787, 411);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AbsorptionWidget->sizePolicy().hasHeightForWidth());
        AbsorptionWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(AbsorptionWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(AbsorptionWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);

        gridLayout->addWidget(graphicsView, 0, 1, 1, 1);

        horizontalScrollBar = new QScrollBar(AbsorptionWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setEnabled(false);
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalScrollBar, 1, 1, 1, 1);

        pushButton = new QPushButton(AbsorptionWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);


        retranslateUi(AbsorptionWidget);

        QMetaObject::connectSlotsByName(AbsorptionWidget);
    } // setupUi

    void retranslateUi(QWidget *AbsorptionWidget)
    {
        AbsorptionWidget->setWindowTitle(QApplication::translate("AbsorptionWidget", "Absorption correction", Q_NULLPTR));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AbsorptionWidget: public Ui_AbsorptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABSORPTIONWIDGET_H
