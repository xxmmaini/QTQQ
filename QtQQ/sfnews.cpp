#include "sfnews.h"
#include "ui_sfnews.h"

sfnews::sfnews(QString id, QString name, QString h, QString state, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sfnews)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去除边框
    ui->l2->setAttribute(Qt::WA_TranslucentBackground);
    ui->l3->setAttribute(Qt::WA_TranslucentBackground);
    this->id = id;
    this->name = name;
    this->hPortraitName = h;
    this->state = state;
    ui->l1->setStyleSheet(QString("border-image: url(:/%1);").arg(hPortraitName));
    ui->l2->setText(name);
    ui->l2->setFont(QFont(tr("微软雅黑"), 9, QFont::Bold));
}

void sfnews::setLastNews(QString lastNews)
{
    this->lastNews = lastNews;
    ui->l3->setText(lastNews);
    ui->l3->setFont(QFont(tr("微软雅黑"), 8));
    ui->l3->setStyleSheet("color:rgb(184,184,184);");
}


void sfnews::setState(QString state)
{
    this->state = state;
    if(state == "不在线")
        ui->l1->setStyleSheet(QString("border-image: url(:/%1);").arg(hPortraitName + "_h"));
    else
        ui->l1->setStyleSheet(QString("border-image: url(:/%1);").arg(hPortraitName));
}


sfnews::~sfnews()
{
    delete ui;
}
