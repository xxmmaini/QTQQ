#include "sthread.h"

sThread::sThread(qintptr soc)
{
    this->socket = soc;
}

void sThread::getData(QString data)
{
    emit isGetData(data);
}

void sThread::run()
{
    ms = new mySocket();
    ms->setSocketDescriptor(this->socket);
    connect(ms, SIGNAL(isGetData(QString)), this, SLOT(getData(QString)));
    connect(ms, SIGNAL(isClose(QString)), this, SLOT(close(QString)));
    connect(this, SIGNAL(sendSignal(QString,QString,QString)), ms, SLOT(getFirendIP(QString,QString,QString)));
    connect(this, SIGNAL(quitConSg()), ms, SLOT(quitCon()));
    connect(ms, SIGNAL(closed()), this, SLOT(quit()));
    this->exec();//这个函数时保证run函数运行直到服务器关闭或者客户端断开连接
}

void sThread::close(QString data)
{
    emit isClose(data);
    this->quit();//关闭当前线程
}

void sThread::getFirendIP(QString mid, QString fid, QString ip)
{
    emit sendSignal(mid, fid, ip);
}

void sThread::quitCon()
{
    emit quitConSg();
}
