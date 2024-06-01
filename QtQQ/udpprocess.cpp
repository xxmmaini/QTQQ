#include "udpprocess.h"

udpProcess::udpProcess(QString mip, int mport, User_Type ut, QString gip, int gport)
{
    if(ut == User_lisgroup)//类型为监听群聊消息
    {
        this->groupip = gip;//组播地址
        this->groupport = gport;//组播端口
    }
    this->mip = mip;
    this->mport = mport;
    this->ut = ut;
    isClosed = false;
}

void udpProcess::read()
{
    userver = new QUdpSocket;
    if(ut == User_lisgroup)
    {
        userver->bind(QHostAddress::AnyIPv4, groupport, QUdpSocket::ReuseAddressHint);
        userver->joinMulticastGroup(QHostAddress(groupip));
        userver->setSocketOption(QAbstractSocket::MulticastLoopbackOption, 1);
        connect(userver, SIGNAL(readyRead()), this, SLOT(readGroupData()));
    }
    else
    {
        userver->bind(QHostAddress(mip), mport, QUdpSocket::ShareAddress);
        while(1)//不断检测是否有消息进来
        {
            if(isClosed) break;
            while(userver->hasPendingDatagrams())
            {
                //先将信息存起来，等信息都收完再处理
                QByteArray data;
                data.resize(userver->pendingDatagramSize());
                userver->readDatagram(data.data(),data.size());//读取数据
                datas.push_back((QString)data);
            }
            emit getData(datas);
            datas.clear();
        }
    }
}

void udpProcess::toClose()
{
    isClosed = true;
}

void udpProcess::readGroupData()
{
    QByteArray data;
    data.resize(userver->pendingDatagramSize());
    userver->readDatagram(data.data(),data.size());//读取数据
    datas.push_back((QString)data);
    emit getData(datas);
    datas.clear();
}
