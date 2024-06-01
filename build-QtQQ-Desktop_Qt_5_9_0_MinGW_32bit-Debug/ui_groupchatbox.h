/********************************************************************************
** Form generated from reading UI file 'groupchatbox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATBOX_H
#define UI_GROUPCHATBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupChatBox
{
public:
    QListWidget *lw1;
    QTextEdit *t1;
    QPushButton *pb2;
    QPushButton *pb1;
    QListWidget *lw2;
    QLabel *l4;
    QLabel *l1;
    QLabel *l2;
    QPushButton *p2;
    QPushButton *p1;
    QLabel *l3;
    QTextBrowser *l5;

    void setupUi(QWidget *groupChatBox)
    {
        if (groupChatBox->objectName().isEmpty())
            groupChatBox->setObjectName(QStringLiteral("groupChatBox"));
        groupChatBox->resize(748, 646);
        groupChatBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lw1 = new QListWidget(groupChatBox);
        lw1->setObjectName(QStringLiteral("lw1"));
        lw1->setGeometry(QRect(15, 100, 541, 390));
        lw1->setFocusPolicy(Qt::NoFocus);
        lw1->setStyleSheet(QLatin1String("QListWidget::Item:hover\n"
"{\n"
"background:rgb(255,255,255);\n"
"padding-top:0px; \n"
"padding-bottom:0px; \n"
"}"));
        t1 = new QTextEdit(groupChatBox);
        t1->setObjectName(QStringLiteral("t1"));
        t1->setGeometry(QRect(15, 520, 541, 111));
        pb2 = new QPushButton(groupChatBox);
        pb2->setObjectName(QStringLiteral("pb2"));
        pb2->setGeometry(QRect(360, 600, 93, 28));
        pb2->setStyleSheet(QStringLiteral("background-color: rgb(67, 152, 255);"));
        pb1 = new QPushButton(groupChatBox);
        pb1->setObjectName(QStringLiteral("pb1"));
        pb1->setGeometry(QRect(460, 600, 93, 28));
        pb1->setStyleSheet(QStringLiteral("background-color: rgb(67, 152, 255);"));
        lw2 = new QListWidget(groupChatBox);
        lw2->setObjectName(QStringLiteral("lw2"));
        lw2->setGeometry(QRect(555, 383, 185, 248));
        l4 = new QLabel(groupChatBox);
        l4->setObjectName(QStringLiteral("l4"));
        l4->setGeometry(QRect(560, 350, 183, 31));
        l1 = new QLabel(groupChatBox);
        l1->setObjectName(QStringLiteral("l1"));
        l1->setGeometry(QRect(15, 20, 81, 71));
        l2 = new QLabel(groupChatBox);
        l2->setObjectName(QStringLiteral("l2"));
        l2->setGeometry(QRect(110, 20, 321, 51));
        p2 = new QPushButton(groupChatBox);
        p2->setObjectName(QStringLiteral("p2"));
        p2->setGeometry(QRect(699, 5, 41, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        p2->setFont(font);
        p2->setMouseTracking(true);
        p2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        p1 = new QPushButton(groupChatBox);
        p1->setObjectName(QStringLiteral("p1"));
        p1->setGeometry(QRect(660, 5, 41, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(8);
        p1->setFont(font1);
        p1->setMouseTracking(true);
        p1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        l3 = new QLabel(groupChatBox);
        l3->setObjectName(QStringLiteral("l3"));
        l3->setGeometry(QRect(560, 95, 183, 31));
        l5 = new QTextBrowser(groupChatBox);
        l5->setObjectName(QStringLiteral("l5"));
        l5->setGeometry(QRect(555, 128, 185, 221));

        retranslateUi(groupChatBox);
        QObject::connect(p1, SIGNAL(clicked()), groupChatBox, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(groupChatBox);
    } // setupUi

    void retranslateUi(QWidget *groupChatBox)
    {
        groupChatBox->setWindowTitle(QApplication::translate("groupChatBox", "Form", Q_NULLPTR));
        pb2->setText(QApplication::translate("groupChatBox", "\345\205\263\351\227\255", Q_NULLPTR));
        pb1->setText(QApplication::translate("groupChatBox", "\345\217\221\351\200\201", Q_NULLPTR));
        l4->setText(QApplication::translate("groupChatBox", "\347\276\244\346\210\220\345\221\230", Q_NULLPTR));
        l1->setText(QString());
        l2->setText(QApplication::translate("groupChatBox", "TextLabel", Q_NULLPTR));
        p2->setText(QApplication::translate("groupChatBox", "\303\227", Q_NULLPTR));
        p1->setText(QApplication::translate("groupChatBox", "\342\200\224", Q_NULLPTR));
        l3->setText(QApplication::translate("groupChatBox", "\347\276\244\351\200\232\347\237\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class groupChatBox: public Ui_groupChatBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATBOX_H
