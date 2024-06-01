#include "tcpprocess.h"

tcpProcess::tcpProcess(QString userId)
{
    isClosed = false;
    this->userId = userId;
}

void tcpProcess::startTime()//线程开始，计时开始
{
    time = new QTimer(this);
    time->setInterval(10000);
    connect(time, SIGNAL(timeout()), this, SLOT(sendHeart()));//每隔10s发送一次心跳包，这过程接收到数据不重置，依旧10s发一次

    client = new QTcpSocket;
    client->connectToHost("192.168.220.82", 8888);
    client->write(userId.toUtf8());//向服务器发送个人的QQ号
    connect(client, SIGNAL(readyRead()), this, SLOT(getData()));//处理服务器发来消息
    connect(client, SIGNAL(disconnected()), this, SLOT(dealDiscon()));//处理服务器主动断开与客户端的连接

    time->start();
}

void tcpProcess::getData()//获取来自服务器的消息
{
    auto data = client->readAll();
    QString ndata = (QString)data;
    if(ndata.contains("close"))//说明发送来的消息是通知好友下线
    {
        QString id = ndata.mid(0, ndata.indexOf(";"));
        emit sendClose(id);
    }
    else if(ndata.contains("false"))//说明发送来的消息是登录失败（暂时只有一个错误：该QQ已登录）
    {
        emit sendError();//发送了消息之后还需要确定要关闭的连接与线程是哪个
    }
    else if(ndata.contains("success"))//服务器验证通过后即登录成功
    {
        emit successCon();
    }
    else//说明发送来的消息是好友IP信息
    {
        QString mip = ndata.mid(0, ndata.indexOf(";"));
        QString id = ndata.mid(ndata.indexOf(";") + 1, ndata.lastIndexOf(";") - ndata.indexOf(";") - 1);
        QString ip = ndata.mid(ndata.lastIndexOf(",") + 1, ndata.size() - ndata.lastIndexOf(";") - 1);
        emit sendFriendIp(mip, id, ip);
    }
}

void tcpProcess::dealDiscon()
{
    emit sendDiscon();//告知QQ服务器断开连接
    isClosed = true;
    connect(time, SIGNAL(timeout()), this, SLOT(tryCon()));//断开连接之后尝试重连
    time->start(10000);
}

void tcpProcess::toClose()
{
    client->disconnectFromHost();//主动断开与服务器的连接
}

void tcpProcess::dealError()
{
    QString data = "topen";
    this->client->write(data.toUtf8());//告知服务器该线程负责的QQ是重复登录的，需要断开
    this->client->waitForReadyRead(500);//等待服务器接收
    this->client->disconnectFromHost();//主动断开与服务器的连接
}

void tcpProcess::sendHeart()
{
    if(isClosed) return;
    QString data = "heart";
    this->client->write(data.toUtf8());//发送心跳包
}

void tcpProcess::tryCon()
{
    if(!isClosed) return;
    client->connectToHost("192.168.220.82", 8888);
    if(client->waitForConnected(100))//等待连接0.1s，连接上即告知服务器其QQ号
    {
        client->write(userId.toUtf8());
        time->stop();//计时停止，重新发送心跳包
        isClosed = false;
        time->start(10000);
    }
}
