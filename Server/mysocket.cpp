#include "mysocket.h"

mySocket::mySocket()
{
    time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(sError()));
    isTopen = false;
    last_time = QDateTime::currentDateTime();//记录当前时间
    connect(this, SIGNAL(readyRead()), this, SLOT(reTime()));//只要收到数据就重新计时
    connect(this, SIGNAL(readyRead()), this, SLOT(getData()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(dError(QAbstractSocket::SocketError)));
    time->start(10000);
}

void mySocket::reTime()
{
    if(!time->isActive())
        time->start();
    last_time = QDateTime::currentDateTime();//记录当前时间
}

void mySocket::getData()
{
    QByteArray data = readAll();
    QString s = (QString)data;
    if(s.contains("topen"))//说明当前的连接是尝试重复连接
    {
        isTopen = true;
    }
    else if(!s.contains("heart"))//说明当前发来的数据包是数据
    {
        this->user_id = (QString)data;
        this->ip = this->QAbstractSocket::peerAddress().toString();
        QString ndata = user_id + "  " + ip;
        emit isGetData(ndata);//发送收到数据的信号
    }
}

void mySocket::dError(QAbstractSocket::SocketError)
{
    int error = this->error();
    switch(error)
    {
       case QAbstractSocket::RemoteHostClosedError://客户端主动断开
       {
          if(isTopen) return;//重复连接断开无需理会
          QString ndata = user_id + "  " + ip;
          emit isClose(ndata);
          break;
       }
       default: return;
    }
}

void mySocket::sError()
{
    if(last_time.secsTo(QDateTime::currentDateTime()) < 10) return;
    QString ndata = user_id + "  " + ip;//告知服务器该客户端掉线
    time->stop();
    emit isClose(ndata);
    this->close();
    emit closed();
}

void mySocket::getFirendIP(QString mid, QString fid, QString ip)
{
    if(this->user_id == mid)//当这个客户端与服务器所要找的客户端相同时发送数据
    {
        time->stop();//发送数据时暂停计时器
        if(ip.contains("close"))
        {
            QString data = fid + ";" + ip;//将好友下线的消息发送出去
            QByteArray ndata = data.toLatin1();
            this->write(ndata);
            this->waitForReadyRead(100);
        }
        else if(ip.contains("false"))
        {
            QString data = "false";
            QByteArray ndata = data.toLatin1();
            this->write(ndata);
            this->waitForReadyRead(100);
        }
        else if(ip.contains("success"))//登录成功
        {
            QString data = "success";
            QByteArray ndata = data.toLatin1();
            this->write(ndata);
            this->waitForReadyRead(100);
        }
        else
        {
            QString data = this->ip + ";" + fid + ";" + ip;//将自己的ip地址与好友ip地址都发送出去
            QByteArray ndata = data.toLatin1();
            this->write(ndata);
            this->waitForReadyRead(100);
        }
        time->start(10000);
    }
}

void mySocket::quitCon()
{
    this->close();
    emit closed();
}
