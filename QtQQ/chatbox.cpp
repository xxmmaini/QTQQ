#include "chatbox.h"
#include "ui_chatbox.h"

chatBox::chatBox(QString uid, QString mid, QString uhead, QString mhead, QString name, QString p, QString uip, int uport, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatBox)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去除边框
    setAttribute(Qt::WA_TranslucentBackground);
    ui->l3->setStyleSheet("QLabel {background-color: transparent;}");
    ui->l4->setStyleSheet("QLabel {background-color: transparent;}");
    ui->p1->setFlat(true);//按钮透明化
    ui->p2->setFlat(true);
    this->uid = uid;
    this->mid = mid;
    this->uname = name;
    this->upSignature = p;
    this->uhPortraitName = uhead;
    this->mhPortraitName = mhead;
    this->uip = uip;
    this->uport = uport;
    ui->l2->setStyleSheet(QString("border-image: url(:/%1);").arg(uhead));
    ui->l3->setText(name);
    ui->l3->setFont(QFont(tr("微软雅黑"), 9, QFont::Bold));
    ui->l4->setText(p);
    ui->l4->setFont(QFont(tr("微软雅黑"), 8));
    ui->l4->setStyleSheet("color:rgb(184,184,184);");
    connect(ui->pb1, QPushButton::clicked, this, showChatContent);//点击按钮发送我方内容并显示
    connect(ui->lw1, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(setNoSelected(QListWidgetItem*)));
    connect(ui->lw1, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(setNoSelected(QListWidgetItem*)));
    connect(ui->p2, SIGNAL(clicked(bool)), this, SLOT(nclose(bool)));
    connect(ui->pb2, SIGNAL(clicked(bool)), this, SLOT(nclose(bool)));
    userver = new QUdpSocket;
    time = new QTimer;
}

void chatBox::mousePressEvent(QMouseEvent *event)
{
    if( (event->button() == Qt::LeftButton) )
    {
        mouse_press = true;
        mousePoint = event->globalPos() - this->pos();
    }
}

void chatBox::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
        move(event->globalPos() - mousePoint);
}

void chatBox::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}

void chatBox::paintEvent(QPaintEvent *event) //假阴影
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

void chatBox::showChatContent()//显示聊天文本，还要将信息发送给对方QQ
{
    if(ui->t1->toPlainText() == "") return;//说明没有文本
    if(ustate == "不在线")//不在线的情况下内容是无法发送给对方的，只能单方面显示
    {
        QString data = ui->t1->toPlainText() + "[离线消息，无法送达]";
        chatItem *ci = new chatItem(mhPortraitName, data, ci->User_Type :: User_me, ui->lw1);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(ci->size());
        ui->lw1->addItem(item);
        ui->lw1->setItemWidget(item, ci);
        emit getNew(uid, uname, uhPortraitName, ustate, data);
        ui->t1->clear();
        return;
    }
    nowData = mid + "(first):" + ui->t1->toPlainText() + "\0";//确保发送出去的中文成功接收
    QByteArray ndata = nowData.toUtf8().data();
    userver->writeDatagram(ndata.data(), ndata.size(), QHostAddress(uip), uport);//发送信息给对方QQ
    time = new QTimer;
    time->setInterval(3000);//3s后重传
    time->start();
    connect(time, SIGNAL(timeout()), this, SLOT(sendAgain()));//定时重传当前数据
    chatItem *ci = new chatItem(mhPortraitName, ui->t1->toPlainText(), ci->User_Type :: User_me, ui->lw1);
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(ci->size());
    ui->lw1->addItem(item);
    ui->lw1->setItemWidget(item, ci);
    emit getNew(uid, uname, uhPortraitName, ustate, ui->t1->toPlainText());
    ui->t1->clear();
}

void chatBox::sendAgain()//重传当前数据，这一机制确保了非重复数据不丢失，但重复数据还是存在丢失的问题
{
    nowData.replace(QRegExp("(first)"), "(twist)");//告知对方这是重传的数据，方便对方判断
    QByteArray ndata = nowData.toUtf8().data();
    userver->writeDatagram(ndata.data(), ndata.size(), QHostAddress(uip), uport);//发送信息给对方QQ
}

void chatBox::setNoSelected(QListWidgetItem* item)
{
    item->setSelected(false);
}

void chatBox::getData(QString id, QString data)
{
    if(id != uid) return;//说明该消息不是发送给这个聊天框的
    data += "\n";
    chatItem *ci = new chatItem(uhPortraitName, data, ci->User_Type :: User_you, ui->lw1);//显示对方发来的聊天信息
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(ci->size());
    ui->lw1->addItem(item);
    ui->lw1->setItemWidget(item, ci);
    emit getNew(uid, uname, uhPortraitName, ustate, data);
    if(time->isActive())
        time->stop();//当接收到数据了就停止当前重传（不太实际）
}

void chatBox::nclose(bool b)
{
    emit isClose(uid, "friend");
    this->close();
}

void chatBox::changeState(QString fid, QString state)
{
    if(fid != uid) return;
    if(state == "不在线")
    {
        this->ustate = "不在线";
        ui->l2->setStyleSheet(QString("border-image: url(:/%1);").arg(this->uhPortraitName + "_h"));
        if(time->isActive())//还在不断重传数据则停止
            time->stop();
    }
    else
    {
        this->ustate = "在线";
        ui->l2->setStyleSheet(QString("border-image: url(:/%1);").arg(this->uhPortraitName));
    }
}

void chatBox::setState(QString state)
{
    this->ustate = state;
    if(state == "不在线")
        ui->l2->setStyleSheet(QString("border-image: url(:/%1);").arg(uhPortraitName + "_h"));
    else
        ui->l2->setStyleSheet(QString("border-image: url(:/%1);").arg(uhPortraitName));
}

chatBox::~chatBox()
{
    delete ui;
}
