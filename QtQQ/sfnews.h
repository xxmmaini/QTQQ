#ifndef SFNEWS_H
#define SFNEWS_H

#include <QWidget>

//显示最新消息等
namespace Ui {
class sfnews;
}

class sfnews : public QWidget
{
    Q_OBJECT

public:
    explicit sfnews(QString id, QString name, QString h, QString state, QWidget *parent = 0);
    void setLastNews(QString lastNews);
    void setState(QString state);
    ~sfnews();
private:
    Ui::sfnews *ui;
    QString id;//记录该消息的好友QQ号
    QString name;//记录该消息的好友昵称
    QString hPortraitName;//头像名称
    QString lastNews;//最后一条消息的内容
    QString state;//好友状态
};

#endif // SFNEWS_H
