#ifndef QTQQ_H
#define QTQQ_H

#include <QMainWindow>
#include "signin.h"
#include "sfriend.h"
#include "hshowfriend.h"
#include "chatbox.h"
#include "tcpprocess.h"
#include "udpprocess.h"
#include "sfnews.h"
#include "groupchatbox.h"
#include <QSqlDatabase> //sql驱动基础
#include <QSqlQuery>//sql查询相关
#include <QSqlError>//sql输出错误
#include <QDebug>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QLabel>
#include <QList>
#include <QPainter>
#include <QColor>
#include <QtMath>
#include <QThread>
#include <QMap>
#include <QSet>
#include <QHostAddress>
#include <QMouseEvent>
#include <QVector>
#include <QMetaType>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class Qtqq;
}

class Qtqq : public QWidget
{
    Q_OBJECT

public:
    explicit Qtqq(QWidget *parent = 0);
    ~Qtqq();
    void showFriend();//显示好友
    void showGroup();//显示群聊
signals:
    void sendData(QString fid, QString data);//接收到消息，将其发给好友聊天框
    void sendGroupData(QString gid, QString fid, QString data);//接收到消息，将其发给群聊聊天框
    void openError();//打开主窗口失败（重复登录了）
    void stateChanged(QString id, QString state);//好友状态变化
    void toCloseUDP();//销毁UDP线程信号
public slots:
    void showThis();//显示QQ主窗口
    void showTreeWidgetItem(QTreeWidgetItem* item, int col);//显示列表内容
    void showChatBox(QTreeWidgetItem* item, int col);//显示聊天框
    void recvInfo(QVector<QString>);//处理来自别人的信息
    void chatClose(QString id, QString user);//处理对话框关闭
    void addNews(QString id, QString name, QString h, QString state, QString news);//添加消息框
    void setConnect();//处理客户端与服务器的连接
    void dealDiscon();//处理服务器主动断开连接
    void dealError();//处理重复登录
    void dealFout(QString fid);//处理好友下线
    void dealFip(QString mip, QString fid, QString fip);//处理好友ip
protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::Qtqq *ui;
    SignIn *si;
    tcpProcess *tp;
    udpProcess *up;//监听好友消息
    QVector<udpProcess *> ups;//监听所有群聊消息
    QVector<QThread *> uhs;
    QThread *th;
    QThread *uh;
    QSqlDatabase data_base;
    QMap<QString, QString> fsip;//记录好友及其IP地址
    QTreeWidgetItem *qfriend;//好友分组
    QTreeWidgetItem *qgroup;//群聊分组
    QTreeWidgetItem *qblacklist;//黑名单分组
    QString mhead;//记录自己的头像
    int mport;//记录自己的端口号
    QString mip;//记录自己的IP地址
    QSet<QString> qqs;//记录当前已打开聊天框的QQ号
    QMap<QString, QTreeWidgetItem*> fsTree;//记录好友对应的那个分支
    bool isOpen;//记录当前QQ界面是否已打开，用来防止重复上线
    QMap<QString, QListWidgetItem*> fnews;//记录好友对应的消息分支
//    QString state;//记录自己的状态
    QSet<QString> gs;//记录当前已打开聊天框的群聊
    QMap<QString, QString> nowDataFirst;//记录当前接收到的数据

    QPoint mousePoint;
    bool mouse_press;
};

#endif // QTQQ_H
