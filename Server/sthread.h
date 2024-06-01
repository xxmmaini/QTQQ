#ifndef STHREAD_H
#define STHREAD_H

#include <QThread>
#include "mysocket.h"

//一个线程对应一个客户端
class sThread : public QThread
{
    Q_OBJECT
public:
    sThread(qintptr soc);
signals:
    void isGetData(QString data);
    void isClose(QString data);
    void sendSignal(QString mid, QString fid, QString ip);
    void quitConSg();
private slots:
    void getData(QString data);
    void close(QString data);
    void getFirendIP(QString mid, QString fid, QString ip);
    void quitCon();//结束所有线程
private:
    qintptr socket;//记录该线程对应的客户端套接字描述符（qintptr为指针类型）
    mySocket *ms;//每个客户端对应一个套接字，以便实现内容读取
    virtual void run();

};

#endif // STHREAD_H
