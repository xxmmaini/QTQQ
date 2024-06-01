#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QList>
#include "sthread.h"

//创建服务器以及开启监听（套娃式TCP连接）
class myServer : public QTcpServer
{
    Q_OBJECT
public:
    myServer();
    virtual void incomingConnection(qintptr socketDescriptor);//重写该函数，当有新客户端连接时会自动调用
signals:
    void isGetData(QString data);
    void isClose(QString data);
    void sendSignal(QString mid, QString fid, QString ip);
    void quitConSg();
public slots:
    void getData(QString);//获得数据
    void close(QString data);
    void getFirendIP(QString mid, QString fid, QString ip);
    void quitCon();//结束所有线程
private:
    QList<sThread*> sts;//存放所有线程

};

#endif // MYSERVER_H
