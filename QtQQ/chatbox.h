#ifndef CHATBOX_H
#define CHATBOX_H

#include "chatItem.h"
#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QtMath>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QUdpSocket>
#include <QHostAddress>
#include <QMouseEvent>
#include <QTimer>

namespace Ui {
class chatBox;
}

class chatBox : public QWidget
{
    Q_OBJECT

public:
    explicit chatBox(QString uid, QString mid, QString uhead, QString mhead, QString name, QString p, QString uip, int uport, QWidget *parent = 0);
    ~chatBox();
    void setState(QString state);
protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void isClose(QString id, QString type);
    void getNew(QString id, QString name, QString h, QString state, QString news);
public slots:
    void showChatContent();//显示聊天文本
    void setNoSelected(QListWidgetItem*);//设置点击时不选中对话框
    void getData(QString id, QString data);//接受来自对方的消息
    void nclose(bool);//关闭聊天框
    void changeState(QString fid, QString state);//修改好友状态
    void sendAgain();//重传
private:
    Ui::chatBox *ui;
    QUdpSocket *userver;
    QString uid;//记录对方QQ号
    QString mid;//记录我方QQ号
    QString uname;
    QString upSignature;
    QString uhPortraitName;//记录对方头像
    QString mhPortraitName;//记录我方头像
    QString uip;//记录对方的IP地址
    int uport;//记录对方的端口号
    QString ustate;//记录对方的状态：在线或不在线
    QTimer *time;//定时器，定时重传
    QString nowData;//记录当前数据

    QPoint mousePoint;
    bool mouse_press;
};

#endif // CHATBOX_H
