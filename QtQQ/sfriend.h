#ifndef SFRIEND_H
#define SFRIEND_H

#include <QWidget>
#include <qpalette.h>
namespace Ui {
class sfriend;
}

class sfriend : public QWidget
{
    Q_OBJECT

public:
    explicit sfriend(QWidget *parent = 0);
    ~sfriend();
    enum User_Type//设置类型枚举
    {
        User_friend,
        User_group
    };
    void setDetails(QString id, QString name, QString pSignature, QString hPortraitName, int port, User_Type user, QString ip = "", QString notice = "");
    QString getName() { return name; }
    QString getpSignature() { return pSignature; }
    QString gethPortraitName() { return hPortraitName; }
    QString getId() { return id; }
    QString getState() { return state;}
    QString getIp() { return ip; }
    int getPort() { return port; }
    User_Type getUT() { return user; }
    QString getNotice() { return notice; }
    void setState(QString state);
private:
    Ui::sfriend *ui;
    QString id;//QQ号或群号
    QString name;//QQ昵称或群名称
    QString pSignature;//个性签名
    QString hPortraitName;//头像名称
    QString state;//记录该好友状态
    int port;//记录其QQ端口号或组播端口号
    QString ip;//记录其IP地址（只有群聊才需要用到）
    QString notice;//记录群通知
    User_Type user;//记录使用类型
};

#endif // SFRIEND_H
