#ifndef NumorPropertyWidget_H
#define NumorPropertyWidget_H

#include <QWidget>

namespace Ui {
class NumorPropertyWidget;
}

class NumorItem;

class NumorPropertyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NumorPropertyWidget(NumorItem* caller,QWidget *parent = 0);
    ~NumorPropertyWidget();

private:
    Ui::NumorPropertyWidget *ui;
    NumorItem* _numorItem;
};

#endif // NumorPropertyWidget_H