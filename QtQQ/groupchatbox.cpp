#include "groupchatbox.h"
#include "ui_groupchatbox.h"

groupChatBox::groupChatBox(QString id, QString name, QString head, QString ip, int port, QString notice, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::groupChatBox)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去除边框
    //setAttribute(Qt::WA_TranslucentBackground);
    ui->l2->setStyleSheet("QLabel {background-color: transparent;}");//文本背景透明化
    ui->p1->setFlat(true);//按钮透明化
    ui->p2->setFlat(true);
    this->groupId = id;
    this->groupName = name;
    this->hPortraitName = head;
    this->notice = notice;
    this->ip = ip;
    this->port = port;
    ui->l1->setStyleSheet(QString("border-image: url(:/%1);").arg(head));//显示群聊头像
    ui->l2->setText(name);//群名
    ui->l5->setText(notice);//群通知
    connect(ui->p2, SIGNAL(clicked(bool)), this, SLOT(sendClosed()));
    connect(ui->pb2, SIGNAL(clicked(bool)), this, SLOT(sendClosed()));
    connect(ui->pb1, SIGNAL(clicked(bool)), this, SLOT(tosendData()));

    socket = new QUdpSocket;
//    socket->bind(QHostAddress::AnyIPv4, port, QUdpSocket::ShareAddress);
//    socket->setSocketOption(QAbstractSocket::MulticastLoopbackOption, 1);
//    socket->joinMulticastGroup(QHostAddress(ip));
}

void groupChatBox::mousePressEvent(QMouseEvent *event)
{
    if( (event->button() == Qt::LeftButton) )
    {
        mouse_press = true;
        mousePoint = event->globalPos() - this->pos();
    }
}

void groupChatBox::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
        move(event->globalPos() - mousePoint);
}

void groupChatBox::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}

void groupChatBox::paintEvent(QPaintEvent *event) //假阴影
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(5, 5, this->width() - 5, this->height() - 5);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 19);
    for(int i = 0; i < 5; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(5 - i, 5 - i, this->width()- (5 - i)*2, this->height()- (5 - i) * 2);
        color.setAlpha(21 - qSqrt(i) * 7);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void groupChatBox::setMuser(QString id)
{
    for(int i = 0; i < users.size(); ++i)
        if(users[i]->userId == id) me = users[i];
}

void groupChatBox::addUser(QString id, QString name, QString head, QString state)
{
    user *u = new user;
    u->setDetails(id, name, head, state);
    users.push_back(u);
    sgUser *su;
    if(state == "不在线") su = new sgUser(":/" + head + "_h", id, name);
    else su = new sgUser(":/" + head, id, name);
    QListWidgetItem *t = new QListWidgetItem();
    t->setSizeHint(su->size());
    ui->lw2->addItem(t);
    ui->lw2->setItemWidget(t, su);
}

void groupChatBox::sendClosed()
{
    emit isClosed(groupId, "group");
    this->close();
}

void groupChatBox::tosendData()
{
    if(ui->t1->toPlainText() == "") return;//说明没有文本
    QString nowData = me->userId + "(group" + groupId + "):" + ui->t1->toPlainText() + "\0";//确保发送出去的中文成功接收
    QByteArray ndata = nowData.toUtf8().data();
    socket->writeDatagram(ndata.data(), ndata.size(), QHostAddress(ip), port);//发送信息给组播地址
    chatItem *ci = new chatItem(me->userHead, ui->t1->toPlainText(), chatItem::User_me);
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(ci->size());
    ui->lw1->addItem(item);
    ui->lw1->setItemWidget(item, ci);
    ui->t1->clear();
    socket->waitForReadyRead(1000);//等待1s接收
}

void groupChatBox::showData(QString gid, QString fid, QString data)
{
    if(gid != groupId) return;
    data += "\n";
    QString head = "";
    for(int i = 0; i < users.size(); ++i)
        if(fid == users[i]->userId) head = users[i]->userHead;
    chatItem *ci = new chatItem(head, data, chatItem::User_you);
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(ci->size());
    ui->lw1->addItem(item);
    ui->lw1->setItemWidget(item, ci);
}

void groupChatBox::stateChange(QString id, QString state)
{
    if(items.find(id) == items.end()) return;
    if(state == "不在线")
    {
        auto t = items[id];
        auto tt = dynamic_cast<sgUser *>(ui->lw1->itemWidget(t));
        sgUser *su;
        su = new sgUser(":/" + tt->getHead() + "_h", id, tt->getName());
        ui->lw1->setItemWidget(items[id], su);
    }
    else
    {
        auto t = items[id];
        auto tt = dynamic_cast<sgUser *>(ui->lw1->itemWidget(t));
        sgUser *su;
        su = new sgUser(":/" + tt->getHead(), id, tt->getName());
        ui->lw1->setItemWidget(items[id], su);
    }
}

groupChatBox::~groupChatBox()
{
    delete ui;
}
