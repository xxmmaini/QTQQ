#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include "myserver.h"
#include <QPushButton>
#include <QMap>
#include <QSqlDatabase> //sql驱动基础
#include <QSqlQuery>//sql查询相关
#include <QSqlError>//sql输出错误

//服务器使用TCP与多线程实现
namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = 0);
    ~server();
signals:
    void sendSignal(QString mid, QString fid, QString ip);//发送信息
    void quitConSg();//主动断开与客户端的连接
private slots:
    void ocListen();
    void showConnect(QString data);//显示连接
    void showDisConnect(QString data);//显示断开连接
private:
    Ui::server *ui;
    QSqlDatabase data_base;
    myServer * myserver;

    QMap<QString, QString> idip;//记录所有已连接QQ号及其IP地址
    QString my_ip;
    int my_port;
};

#endif // SERVER_H
