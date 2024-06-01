#include "sguser.h"

sgUser::sgUser(QString head, QString id, QString name, QWidget *parent) : QWidget(parent)
{
    this->head = head;
    this->id = id;
    this->name = name;
    this->resize(180, 40);
}

void sgUser::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);//消锯齿
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::gray));

    //绘制头像
    QRect head_rect = QRect(5, 5, 30, 30);
    painter.drawPixmap(head_rect, QPixmap(head));

    //绘制昵称和QQ号
    QPen penText;
    penText.setColor(QColor(0, 0, 0));
    painter.setPen(penText);
    painter.setFont(QFont("微软雅黑", 7));
    QTextOption option(Qt::AlignLeft);
    painter.drawText(QRect(40, 10, 120, 15), name + "(" + id + ")", option);
}
