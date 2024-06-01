#ifndef UDPPROCESS_H
#define UDPPROCESS_H

#include <QUdpSocket>
#include <QVector>
#include <QDebug>

//UDP处理类：每个QQ在显示时开一个线程出来处理消息，目的降低UDP丢包率
class udpProcess : public QObject
{
    Q_OBJECT
public:
    enum User_Type//设置类型枚举
    {
        User_lisfriend,//监听好友消息
        User_lisgroup//监听群聊消息
    };
    udpProcess(QString, int, User_Type, QString gip = "", int gport = 0);
signals:
    void getData(const QVector<QString>& data);
public slots:
    void read();//不断读取数据
    void toClose();//停止线程循环，以便销毁线程
    void readGroupData();//读取群聊消息
private:
    QUdpSocket *userver;
    QVector<QString> datas;
    bool isClosed;//作为销毁标志，停止线程循环
    QString mip;//记录自己的IP地址
    QString groupip;//记录监听群聊消息类型下的组播地址
    int groupport;//记录监听群聊消息类型下的端口
    int mport;//记录自己的端口
    User_Type ut;//记录该UDP处理类型
};

#endif // UDPPROCESS_H
