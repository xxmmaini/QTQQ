/********************************************************************************
** Form generated from reading UI file 'chatbox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOX_H
#define UI_CHATBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatBox
{
public:
    QPushButton *p1;
    QPushButton *p2;
    QLabel *l1;
    QTextEdit *t1;
    QListWidget *lw1;
    QPushButton *pb1;
    QPushButton *pb2;
    QLabel *l2;
    QLabel *l3;
    QLabel *l4;

    void setupUi(QWidget *chatBox)
    {
        if (chatBox->objectName().isEmpty())
            chatBox->setObjectName(QStringLiteral("chatBox"));
        chatBox->resize(748, 646);
        chatBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        p1 = new QPushButton(chatBox);
        p1->setObjectName(QStringLiteral("p1"));
        p1->setGeometry(QRect(660, 5, 41, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(8);
        p1->setFont(font);
        p1->setMouseTracking(true);
        p1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        p2 = new QPushButton(chatBox);
        p2->setObjectName(QStringLiteral("p2"));
        p2->setGeometry(QRect(699, 5, 41, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(10);
        p2->setFont(font1);
        p2->setMouseTracking(true);
        p2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        l1 = new QLabel(chatBox);
        l1->setObjectName(QStringLiteral("l1"));
        l1->setGeometry(QRect(569, 100, 171, 531));
        l1->setStyleSheet(QStringLiteral("border-image: url(:/personman.png);"));
        t1 = new QTextEdit(chatBox);
        t1->setObjectName(QStringLiteral("t1"));
        t1->setGeometry(QRect(15, 520, 541, 111));
        lw1 = new QListWidget(chatBox);
        lw1->setObjectName(QStringLiteral("lw1"));
        lw1->setGeometry(QRect(15, 100, 541, 390));
        lw1->setFocusPolicy(Qt::NoFocus);
        lw1->setStyleSheet(QLatin1String("QListWidget::Item:hover\n"
"{\n"
"background:rgb(255,255,255);\n"
"padding-top:0px; \n"
"padding-bottom:0px; \n"
"}"));
        pb1 = new QPushButton(chatBox);
        pb1->setObjectName(QStringLiteral("pb1"));
        pb1->setGeometry(QRect(460, 600, 93, 28));
        pb1->setStyleSheet(QStringLiteral("background-color: rgb(67, 152, 255);"));
        pb2 = new QPushButton(chatBox);
        pb2->setObjectName(QStringLiteral("pb2"));
        pb2->setGeometry(QRect(360, 600, 93, 28));
        pb2->setStyleSheet(QStringLiteral("background-color: rgb(67, 152, 255);"));
        l2 = new QLabel(chatBox);
        l2->setObjectName(QStringLiteral("l2"));
        l2->setGeometry(QRect(30, 30, 71, 61));
        l3 = new QLabel(chatBox);
        l3->setObjectName(QStringLiteral("l3"));
        l3->setGeometry(QRect(120, 30, 111, 21));
        l4 = new QLabel(chatBox);
        l4->setObjectName(QStringLiteral("l4"));
        l4->setGeometry(QRect(120, 60, 431, 21));

        retranslateUi(chatBox);
        QObject::connect(p1, SIGNAL(clicked()), chatBox, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(chatBox);
    } // setupUi

    void retranslateUi(QWidget *chatBox)
    {
        chatBox->setWindowTitle(QApplication::translate("chatBox", "Form", Q_NULLPTR));
        p1->setText(QApplication::translate("chatBox", "\342\200\224", Q_NULLPTR));
        p2->setText(QApplication::translate("chatBox", "\303\227", Q_NULLPTR));
        l1->setText(QString());
        pb1->setText(QApplication::translate("chatBox", "\345\217\221\351\200\201", Q_NULLPTR));
        pb2->setText(QApplication::translate("chatBox", "\345\205\263\351\227\255", Q_NULLPTR));
        l2->setText(QString());
        l3->setText(QApplication::translate("chatBox", "TextLabel", Q_NULLPTR));
        l4->setText(QApplication::translate("chatBox", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chatBox: public Ui_chatBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOX_H
