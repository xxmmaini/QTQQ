#ifndef TCPPROCESS_H
#define TCPPROCESS_H

#include <QTcpSocket>
#include <QTimer>

//TCP处理类：完成QQ的TCP连接与其他操作，并且实现心跳检测
class tcpProcess : public QObject
{
    Q_OBJECT
public:
    tcpProcess(QString userId);
signals:
    void sendClose(QString id);//通知QQ某好友下线
    void sendError();//通知登录界面登录失败（重复登录）
    void successCon();//通知QQ服务器连接成功，可以显示主界面
    void sendFriendIp(QString, QString, QString);//通知QQ自己的IP地址与好友的IP地址
    void sendDiscon();//通知QQ服务器断开
public slots:
    void getData();
    void dealDiscon();
    void toClose();//客户端主动与服务器断开连接
    void dealError();//处理重复登录：主动断开连接并销毁该线程
    void sendHeart();//向服务器发送心跳包
    void tryCon();//尝试重连
    void startTime();//线程开始，计时开始
private:
    QTcpSocket *client;
    QString userId;
    bool isClosed;//作为服务器是否断开与客户端联系的标志
    QTimer *time;//设置定时器，定时向服务器发送心跳包
};

#endif // TCPPROCESS_H
