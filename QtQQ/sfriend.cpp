#include "sfriend.h"
#include "ui_sfriend.h"

sfriend::sfriend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sfriend)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去除边框
    ui->l2->setAttribute(Qt::WA_TranslucentBackground);
    ui->l3->setAttribute(Qt::WA_TranslucentBackground);
    this->state = "不在线";
}

void sfriend::setDetails(QString id, QString name, QString pSignature, QString hPortraitName, int port, User_Type user, QString ip, QString notice)
{
    if(user == User_friend)
    {
        this->id = id;
        this->name = name;
        this->pSignature = pSignature;
        this->hPortraitName = hPortraitName;//默认显示灰度图像（不在线）
        this->port = port;//这里的端口是好友端口
        this->user = user;
        ui->l1->setStyleSheet(QString("border-image: url(:/%1);").arg(hPortraitName + "_h"));
        ui->l2->setText(name + "（" + state + "）");//初始状态都是不在线，后续其他账号登录时再修改状态
        ui->l2->setFont(QFont(tr("微软雅黑"), 9, QFont::Bold));
        ui->l3->setText(pSignature);
        ui->l3->setFont(QFont(tr("微软雅黑"), 8));
        ui->l3->setStyleSheet("color:rgb(184,184,184);");
    }
    else
    {
        this->id = id;
        this->name = name;
        this->hPortraitName = hPortraitName;
        this->ip = ip;//这里的端口是组播端口
        this->port = port;
        this->notice = notice;
        this->user = user;
        ui->l1->setStyleSheet(QString("border-image: url(:/%1);").arg(hPortraitName));
        ui->l2->setText(name);
        ui->l2->setFont(QFont(tr("微软雅黑"), 9, QFont::Bold));
    }
}


void sfriend::setState(QString state)
{
    this->state = state;
    if(state == "不在线")
    {
        ui->l1->setStyleSheet(QString("border-image: url(:/%1);").arg(hPortraitName + "_h"));
        ui->l2->setText(name + "（" + state + "）");
    }
    else
    {
        ui->l1->setStyleSheet(QString("border-image: url(:/%1);").arg(hPortraitName));
        ui->l2->setText(name + "（" + state + "）");
    }
}


sfriend::~sfriend()
{
    delete ui;
}
