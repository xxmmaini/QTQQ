#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QSqlDatabase> //sql驱动基础
#include <QSqlQuery>//sql查询相关
#include <QSqlError>//sql输出错误
#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QtMath>
#include <QMessageBox>
#include <QTcpSocket>
#include <QMouseEvent>

namespace Ui {
class SignIn;
}

class SignIn : public QWidget
{
    Q_OBJECT
public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();
    QString userId;
protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void isSignIn();//登录信号
private slots:
    void showHead();
    void login();
public slots:
    void loginError();
private:
    QSqlDatabase data_base;
    Ui::SignIn *ui;
    QPoint mousePoint;
    bool mouse_press;
};

#endif // SIGNIN_H
