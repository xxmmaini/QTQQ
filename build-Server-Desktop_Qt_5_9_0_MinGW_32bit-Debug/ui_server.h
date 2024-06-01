/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_server
{
public:
    QTextBrowser *t1;
    QPushButton *p1;
    QLineEdit *l1;
    QLineEdit *l2;
    QLabel *la1;
    QLabel *la2;

    void setupUi(QWidget *server)
    {
        if (server->objectName().isEmpty())
            server->setObjectName(QStringLiteral("server"));
        server->resize(535, 476);
        t1 = new QTextBrowser(server);
        t1->setObjectName(QStringLiteral("t1"));
        t1->setGeometry(QRect(20, 20, 371, 431));
        p1 = new QPushButton(server);
        p1->setObjectName(QStringLiteral("p1"));
        p1->setGeometry(QRect(410, 230, 111, 31));
        l1 = new QLineEdit(server);
        l1->setObjectName(QStringLiteral("l1"));
        l1->setGeometry(QRect(400, 70, 131, 31));
        l2 = new QLineEdit(server);
        l2->setObjectName(QStringLiteral("l2"));
        l2->setGeometry(QRect(400, 160, 131, 31));
        la1 = new QLabel(server);
        la1->setObjectName(QStringLiteral("la1"));
        la1->setGeometry(QRect(400, 30, 121, 31));
        la2 = new QLabel(server);
        la2->setObjectName(QStringLiteral("la2"));
        la2->setGeometry(QRect(400, 120, 121, 31));

        retranslateUi(server);

        QMetaObject::connectSlotsByName(server);
    } // setupUi

    void retranslateUi(QWidget *server)
    {
        server->setWindowTitle(QApplication::translate("server", "server", Q_NULLPTR));
        p1->setText(QApplication::translate("server", "\346\211\223\345\274\200\347\233\221\345\220\254", Q_NULLPTR));
        la1->setText(QApplication::translate("server", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        la2->setText(QApplication::translate("server", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class server: public Ui_server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
