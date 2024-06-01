#ifndef SGUSER_H
#define SGUSER_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QRect>
#include <QPoint>

class sgUser : public QWidget
{
    Q_OBJECT
public:
    explicit sgUser(QString head, QString id, QString name, QWidget *parent = nullptr);
    QString getHead() { return head; }
    QString getId() { return id; }
    QString getName() { return name; }
protected:
    void paintEvent(QPaintEvent *event);//绘制群成员框
private:
    QString head;//记录群成员头像
    QString id;//记录群成员QQ号
    QString name;//记录群成员名字
};

#endif // SGUSER_H
