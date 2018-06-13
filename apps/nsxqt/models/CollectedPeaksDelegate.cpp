#include <QApplication>
#include <QCheckBox>
#include <QComboBox>
#include <QKeyEvent>
#include <QModelIndex>
#include <QPainter>
#include <QPixmap>

#include "CollectedPeaksDelegate.h"
#include "CollectedPeaksModel.h"

CollectedPeaksDelegate::CollectedPeaksDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    _icon.addPixmap(QPixmap(":/resources/peakSelectedIcon.png"),QIcon::Normal,QIcon::On);
    _icon.addPixmap(QPixmap(":/resources/peakDeselectedIcon.png"),QIcon::Disabled,QIcon::On);
}

void CollectedPeaksDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int column = index.column();
    if (column == CollectedPeaksModel::Column::selected) {
        bool value  = index.model()->data(index,Qt::CheckStateRole).toBool();
        QStyleOptionButton buttonVis;
        buttonVis.rect = option.rect;
        int h = option.rect.height()/2 + 1;
        buttonVis.iconSize = QSize(h,h);
        buttonVis.icon = _icon;
        buttonVis.features |= QStyleOptionButton::Flat;
        buttonVis.state |= value ? QStyle::State_Enabled : QStyle::State_None;
        QApplication::style()->drawControl(QStyle::CE_PushButton,&buttonVis,painter);
    }
    else {
        QStyledItemDelegate::paint(painter,option,index);
    }
}

bool CollectedPeaksDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    Q_UNUSED(option);
    if(event->type() == QEvent::MouseButtonRelease) {
        int column = index.column();
        if (column == CollectedPeaksModel::Column::selected) {
            bool value  = model->data(index,Qt::CheckStateRole).toBool();
            model->setData(index, !value, Qt::CheckStateRole);
        }
    } else if (event->type() == QEvent::KeyPress) {
        auto evt = dynamic_cast<QKeyEvent*>(event);
        if (evt->key() == Qt::Key_Space) {
            QModelIndex idx = model->index(index.row(),CollectedPeaksModel::Column::selected,QModelIndex());
            auto value  = model->data(idx,Qt::CheckStateRole).toBool();
            model->setData(idx, !value, Qt::CheckStateRole);
            value  = model->data(idx,Qt::CheckStateRole).toBool();
        }
    }
    return QStyledItemDelegate::editorEvent(event,model,option,index);
}
