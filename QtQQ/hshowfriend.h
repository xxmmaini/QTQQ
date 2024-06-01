#ifndef HSHOWFRIEND_H
#define HSHOWFRIEND_H
#include <QStyledItemDelegate>

//辅助类，继承委托，目的是修改QQ好友列表各项的大小
class hShowFriend : public QStyledItemDelegate
{
public:
    explicit hShowFriend(QObject *parent = nullptr) :
        QStyledItemDelegate(parent){
    }

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override {
        return QStyledItemDelegate::sizeHint(option, index)
                + index.data(Qt::UserRole).toSize();
    }
};

#endif // HSHOWFRIEND_H
