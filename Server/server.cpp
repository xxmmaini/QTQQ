#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);

    //数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      data_base = QSqlDatabase::database("qt_sql_default_connection");
    else
      data_base = QSqlDatabase::addDatabase("QMYSQL");
    data_base.setHostName("localhost");  //设置主机地址
    data_base.setPort(3306);  //mysql设置端口
    data_base.setDatabaseName("qtqq");  //设置数据库名称
    data_base.setUserName("root");  //设置用户名
    data_base.setPassword("chen144991");  //设置密码
    data_base.open();

    my_ip = "192.168.1.159";
    my_port = 8888;
    ui->l1->setText(my_ip);
    ui->l2->setText(QString("%1").arg(my_port));

    connect(ui->p1, &QPushButton::clicked, this, ocListen);
}

server::~server()
{
    delete ui;
}

void server::ocListen()//打开监听
{
    if(QString::compare(ui->p1->text(), "打开监听", Qt::CaseInsensitive) == 0)
    {
        ui->p1->setText("关闭监听");
        myserver = new myServer();
        myserver->listen(QHostAddress::Any, my_port);
        connect(myserver, SIGNAL(isGetData(QString)), this, SLOT(showConnect(QString)));//连接
        connect(myserver, SIGNAL(isClose(QString)), this, SLOT(showDisConnect(QString)));//客户端主动断开连接
        connect(this, SIGNAL(sendSignal(QString,QString,QString)), myserver, SLOT(getFirendIP(QString,QString,QString)));//接收信息
        connect(this, SIGNAL(quitConSg()), myserver, SLOT(quitCon()));//服务器断开与客户端的连接
    }
    else//关闭监听：断开与所有客户端的连接（结束所有线程）
    {
        ui->p1->setText("打开监听");
        emit quitConSg();
        ui->t1->append(QString("以上所有QQ断开连接！"));
        idip.clear();
    }
}

void server::showConnect(QString data)
{
    //将其QQ号与IP地址记录下来
    QString id = data.mid(0, data.indexOf(" "));
    QString ip = data.mid(data.indexOf(" ") + 2, data.size() - data.indexOf(" ") - 2);
    if(idip.find(id) != idip.end())//说明该QQ号已经登录了，不能重复登录，这里禁止顶号（毕竟只有一个电脑）
    {
        emit sendSignal(id, id, QString("false"));//通知该QQ登录失败
        return;
    }
    ui->t1->append(QString("%1连接成功！").arg(data));
    idip.insert(idip.end(), id, ip);
    //先通知该QQ连接服务器成功
    sendSignal(id, id, QString("success"));
    //查找该QQ号的好友并发送其在线好友ip地址以便建立udp连接
    QSqlQuery* q = new QSqlQuery(data_base);
    q->exec(QString("select friendId from friend where userId = %1").arg(id));
    while(q->next())
    {
        QString friendId = q->value(0).toString();
        if(idip.find(friendId) != idip.end())//说明该好友在线，将其ip地址发送出去，同时需要将其上线的消息通知好友
        {
            emit sendSignal(id, friendId, idip[friendId]);
            emit sendSignal(friendId, id, ip);
        }
    }

}

void server::showDisConnect(QString data)
{
    QString id = data.mid(0, data.indexOf(" "));//断开连接的QQ号
    ui->t1->append(QString("%1断开连接！").arg(data));
    //将idip中的记录删除
    idip.erase(idip.find(id));
    //需要告知其好友其下线消息
    QSqlQuery* q = new QSqlQuery(data_base);
    q->exec(QString("select friendId from friend where userId = %1").arg(id));
    while(q->next())
    {
        QString friendId = q->value(0).toString();
        if(idip.find(friendId) != idip.end())//说明该好友在线，将其下线的消息发送出去
            emit sendSignal(friendId, id, QString("close"));
    }
}
