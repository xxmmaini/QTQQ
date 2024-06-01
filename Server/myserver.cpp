#include "myserver.h"

myServer::myServer()
{
}

void myServer::incomingConnection(qintptr socketDescriptor)
{
    sThread *st = new sThread(socketDescriptor);
    //建立一系列连接
    connect(st, &sThread::finished, &sThread::deleteLater);//线程结束则删除该线程
    connect(st, SIGNAL(isGetData(QString)), this, SLOT(getData(QString)));
    connect(st, SIGNAL(isClose(QString)), this, SLOT(close(QString)));
    connect(this, SIGNAL(sendSignal(QString,QString,QString)), st, SLOT(getFirendIP(QString,QString,QString)));//这里确保了服务器发来的消息所有线程都接收到
    connect(this, SIGNAL(quitConSg()), st, SLOT(quitCon()));
    sts.push_back(st);
    st->start();//打开线程
}

void myServer::getData(QString data)
{
    emit isGetData(data);
}

void myServer::close(QString data)
{
    emit isClose(data);
}

void myServer::getFirendIP(QString mid, QString fid, QString ip)
{
    emit sendSignal(mid, fid, ip);
}

void myServer::quitCon()
{
    emit quitConSg();
}
