#include "chatitem.h"

chatItem::chatItem(QString head, QString text, User_Type u, QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);//去除边框
    this->head = ":/" + head;
    this->text = text;
    this->user = u;
    //初始化各项参数
    hb_width = 10;//头像距离边框的宽度
    hb_height = 5;//头像距离边框的高度
    h_width = 45;//头像宽度
    h_height = 45;//头像高度
    triangle_width = 5;//小三角形线的宽度
    triangle_height = 5;//小三角形线的高度
    textb_width = 7;//文字到框的宽度
    textb_height = 10;//文字到框的高度
    b_width = 30;//文本框到边缘的宽度
    this->getTextHeight();//计算实际的文本宽度与高度
    this->resize(500, text_height + hb_height * 2 + textb_height * 2 + 7);
}

void chatItem::paintEvent(QPaintEvent *event)//绘制聊天框
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);//消锯齿
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::gray));

    text_color = QColor(0, 0, 0);

    if(user == User_you)
    {
        //绘制头像
        QRect head_rect = QRect(hb_width, hb_height, h_width, h_height);
        painter.drawPixmap(head_rect, QPixmap(head));

        //绘制三角形
        painter.setPen(QPen(QColor(195, 195, 195)));
        painter.setBrush(QColor(195, 195, 195));
        QPointF points[3] = { QPointF(hb_width + h_width + 2, hb_height + textb_height * 2),
                           QPointF(hb_width + h_width + 2 + triangle_width, hb_height + textb_height * 2 - triangle_height),
                           QPointF(hb_width + h_width + 2 + triangle_width, hb_height + textb_height * 2 + triangle_height)};
        painter.drawPolygon(points, 3);
        //painter.drawLine(QPoint(hb_width + h_width + 2, hb_height + textb_height * 2), QPoint(hb_width + h_width + 2 + triangle_width, hb_height + textb_height * 2 - triangle_height));
        //painter.drawLine(QPoint(hb_width + h_width + 2, hb_height + textb_height * 2), QPoint(hb_width + h_width + 2 + triangle_width, hb_height + textb_height * 2 + triangle_height));

        //根据文本长度绘制边框
        QRectF rect(hb_width + h_width + 2 + triangle_width, hb_height, textb_width * 2 + text_width, textb_height * 2 + text_height);
        painter.setPen(QPen(QColor(195, 195, 195)));
        painter.setBrush(QColor(195, 195, 195));
        painter.drawRoundedRect(rect, 8, 8);


        //绘制文字
        QPen penText;
        penText.setColor(text_color);
        painter.setPen(penText);
        painter.setFont(QFont("微软雅黑", 9));
        QTextOption option(Qt::AlignLeft);
        option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
        painter.drawText(QRect(hb_width + h_width + 2 + triangle_width + textb_width, hb_height + textb_height, text_width, text_height), text, option);
    }
    else if(user == User_me)
    {
        hb_width = 5;//头像距离边框的宽度
        //绘制头像
        QRect head_rect = QRect(520 - hb_width - h_width, hb_height, h_width, h_height);
        painter.drawPixmap(head_rect, QPixmap(head));

        //绘制三角形
        painter.setPen(QPen(QColor(195, 195, 195)));
        painter.setBrush(QColor(195, 195, 195));
        QPointF points[3] = { QPointF(520 - hb_width - h_width - 2, hb_height + textb_height * 2),
                           QPointF(520 - hb_width - h_width - 2 - triangle_width, hb_height + textb_height * 2 - triangle_height),
                           QPointF(520 - hb_width - h_width - 2 - triangle_width, hb_height + textb_height * 2 + triangle_height)};
        painter.drawPolygon(points, 3);

        //根据文本长度绘制边框
        QRectF rect(520 - hb_width - h_width - 2 - triangle_width - textb_width * 2 - text_width, hb_height, textb_width * 2 + text_width, textb_height * 2 + text_height);
        painter.setPen(QPen(QColor(195, 195, 195)));
        painter.setBrush(QColor(195, 195, 195));
        painter.drawRoundedRect(rect, 8, 8);


        //绘制文字
        QPen penText;
        penText.setColor(text_color);
        painter.setPen(penText);
        painter.setFont(QFont("微软雅黑", 9));
        QTextOption option(Qt::AlignLeft);
        option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
        painter.drawText(QRect(520 - hb_width - h_width - 2 - triangle_width - textb_width - text_width, hb_height + textb_height, text_width, text_height), text, option);

    }
}

void chatItem::getTextHeight()
{
    QFontMetrics fontMetrics(QFont("微软雅黑", 9));//获取文本宽度
    int width = fontMetrics.width(text);
    int text_maxlength = 500 - (hb_width + h_width + triangle_width + b_width);//一行文本最大长度
    if(width > text_maxlength)//若是实际文本长度大于最大值，则需要分行
    {
        QRect textRect = QRect(0, 0, text_maxlength, 0);
        int flags = Qt::TextWordWrap; // 自动换行
        textRect = fontMetrics.boundingRect(textRect, flags, text);
        text_height = textRect.height();
        text_width = text_maxlength;
    }
    else//若是实际文本长度小于最大值，则无需分行
    {
        text_height = fontMetrics.height();
        text_width = width;
    }
}

