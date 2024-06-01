#ifndef CHATITEM_H
#define CHATITEM_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QRect>
#include <QPoint>
#include <QBrush>
#include <QDebug>
//气泡聊天框类（暂时没考虑显示时间）
class chatItem : public QWidget
{
    Q_OBJECT
public:
    enum User_Type//设置类型枚举
    {
        User_me,
        User_you
    };
    explicit chatItem(QString head, QString text, User_Type u, QWidget *parent = nullptr);
    void getTextHeight();//计算文本实际的高度
protected:
    void paintEvent(QPaintEvent *event);//绘制聊天框
signals:

public slots:
private:
    QString head;//记录头像名称
    QString text;//聊天文字
    User_Type user;//记录该聊天框对象是自己还是聊天对象
    //以下为绘制聊天框的各项参数
    int hb_width;//头像距离边框的宽度
    int hb_height;//头像距离边框的高度
    int h_width;//头像宽度
    int h_height;//头像高度
    int triangle_width;//小三角形线的宽度
    int triangle_height;//小三角形线的高度
    int textb_width;//文字到框的宽度
    int textb_height;//文字到框的高度
    int b_width;//文本框到边缘的宽度
    int text_height;//文本实际的高度（分行之后的高度）
    int text_width;//文本实际的宽度（有可能为最长文本长度也可能不是）
    QColor text_color;//文本颜色

};

#endif // CHATITEM_H
