#ifndef GROUPCHATBOX_H
#define GROUPCHATBOX_H

#include "sguser.h"
#include "chatitem.h"
#include <QWidget>
#include <QVector>
#include <QListWidgetItem>
#include <QUdpSocket>
#include <QPainter>
#include <QColor>
#include <QtMath>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class groupChatBox;
}

struct user
{
    QString userId;
    QString userName;
    QString userHead;
    QString userState;
    void setDetails(QString id, QString name, QString head, QString state)
    {
        userId = id;
        userName = name;
        userHead = head;
        userState = state;
    }
};

class groupChatBox : public QWidget
{
    Q_OBJECT

public:
    explicit groupChatBox(QString id, QString name, QString head, QString ip, int port, QString notice = "", QWidget *parent = 0);
    ~groupChatBox();
    void addUser(QString id, QString name, QString head, QString state);//添加群成员
    void setMuser(QString id);//添加对应主成员
signals:
    void isClosed(QString id, QString type);
    void sendData(QString data);//发送数据
public slots:
    void sendClosed();
    void tosendData();//向组播地址发送数据
    void showData(QString gid, QString fid, QString data);
    void stateChange(QString id, QString state);
protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    Ui::groupChatBox *ui;
    QString groupId;//记录当前群聊的群号
    QString groupName;//记录群名
    QString hPortraitName;//记录群头像
    QString notice;//记录群通知
    QString ip;//记录群聊的组播地址
    int port;//记录组播的端口
    QVector<user*> users;//记录群成员的信息
    QMap<QString, QListWidgetItem*> items;//记录群成员对应的QListWidgetItem，以便修改状态
    user *me;//记录本人QQ号等
    QUdpSocket* socket;

    QPoint mousePoint;
    bool mouse_press;
};

#endif // GROUPCHATBOX_H
