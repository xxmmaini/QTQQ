#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QDateTime>

class mySocket : public QTcpSocket
{
    Q_OBJECT
public:
    mySocket();
signals:
    void isGetData(QString data);
    void isClose(QString data);
    void closed();//确认关闭连接
private slots:
    void getData();//获得客户端传来的数据
    void dError(QAbstractSocket::SocketError);//处理断开连接等错误
    void sError();//处理客户端断线情况（与客户端主动断开不相同，可能是网络差等原因）
    void getFirendIP(QString mid, QString fid, QString ip);//接受到服务器发来的信息（最初拟定为只接收好友信息，但后来用于接收所有来自服务器的信息）
    void quitCon();//结束所有连接
    void reTime();
private:
    QString user_id;//记录当前客户端对应的QQ号
    QString ip;//记录当前客户端对应的ip地址
    bool isTopen;//记录当前断开连接的是试图重连的还是正常断开的
    QTimer *time;//设置一个定时器，监测客户端心跳包发来的时间间隔
    QDateTime last_time;//记录上一个数据包到来的时间
};

#endif // MYSOCKET_H
