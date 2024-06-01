#include "signin.h"
#include "ui_signin.h"
#include "qmovie.h"
#include "qlineedit.h"

SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn)
{
    //暂时放弃进入按钮变色的想法
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去除边框
    setAttribute(Qt::WA_TranslucentBackground);
    QMovie *movie = new QMovie(":/blue70-2.gif");
    ui->l1->setMovie(movie);
    ui->l1->setScaledContents(true);
    movie->start();
    ui->p1->setFlat(true);//按钮透明化
    ui->p2->setFlat(true);
    ui->p1->setStyleSheet("color: white");//文本白色
    ui->p2->setStyleSheet("color: white");
    ui->t3->setStyleSheet("background:transparent;border-width:0;border-style:outset;");//文本透明且无框
    ui->t4->setStyleSheet("background:transparent;border-width:0;border-style:outset;");
    ui->t1->setPlaceholderText("请输入您的账号");//设置初始文字
    ui->t2->setPlaceholderText("请输入您的密码");
    connect(ui->t1, &QLineEdit::textChanged, this, showHead);
//    connect(ui->t2, &QLineEdit::textChanged, this, hideLe);
    connect(ui->p3, &QPushButton::clicked, this, login);

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
    if(!data_base.open())
        QMessageBox::critical(NULL, "错误", "数据库连接失败！", QMessageBox::Yes, QMessageBox::Yes);
}

void SignIn::mousePressEvent(QMouseEvent *event)
{
    if( (event->button() == Qt::LeftButton) )
    {
        mouse_press = true;
        mousePoint = event->globalPos() - this->pos();
    }
}

void SignIn::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
        move(event->globalPos() - mousePoint);
}

void SignIn::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::paintEvent(QPaintEvent *event) // 绘出假阴影效果
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(5, 5, this->width() - 5, this->height() - 5); //

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

void SignIn::showHead()//根据输入的QQ号变换头像
{
    QString userId = ui->t1->text();
    if(userId.size() < 9) return;
    //数据库查询
    QSqlQuery* q = new QSqlQuery(data_base);
    q->exec(QString("select hPortraitName from user where iduser = %1").arg(userId));
    QString head;
    if(q->next())
    {
        head = q->value(0).toString();
        head = "border-image: url(:/" + head + ");";
        ui->l2->setStyleSheet(head);
    }
}

void SignIn::login()//点击按钮登录
{
    QString userId = ui->t1->text();
    QString pw = ui->t2->text();
    //数据库查询
    QSqlQuery* q = new QSqlQuery(data_base);
    q->exec(QString("select password from user where iduser = %1").arg(userId));
    if(q->next())//数据库中存在该账号，则登录成功，显示QQ主界面的同时连接服务器
    {
        QString psw = q->value(0).toString();
        if(psw.compare(pw) == 0)
        {
            this->userId = userId;
            data_base.close();
            isSignIn();
        }
        else
            QMessageBox::critical(NULL, "错误", "账号或密码出错！", QMessageBox::Yes, QMessageBox::Yes);
    }
}

void SignIn::loginError()//登录失败
{
    QMessageBox::critical(NULL, "错误", "QQ已登录，请勿重复！", QMessageBox::Yes, QMessageBox::Yes);
    this->close();//当QQ已重复登录时直接退出程序
}

