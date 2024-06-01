/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

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

class Ui_SignIn
{
public:
    QLabel *l1;
    QPushButton *p1;
    QPushButton *p2;
    QPushButton *p3;
    QLabel *l2;
    QTextBrowser *t3;
    QTextBrowser *t4;
    QLineEdit *t1;
    QLineEdit *t2;

    void setupUi(QWidget *SignIn)
    {
        if (SignIn->objectName().isEmpty())
            SignIn->setObjectName(QStringLiteral("SignIn"));
        SignIn->resize(434, 305);
        l1 = new QLabel(SignIn);
        l1->setObjectName(QStringLiteral("l1"));
        l1->setGeometry(QRect(5, 5, 424, 145));
        p1 = new QPushButton(SignIn);
        p1->setObjectName(QStringLiteral("p1"));
        p1->setGeometry(QRect(330, 5, 51, 31));
        p1->setMouseTracking(true);
        p1->setStyleSheet(QStringLiteral(""));
        p2 = new QPushButton(SignIn);
        p2->setObjectName(QStringLiteral("p2"));
        p2->setGeometry(QRect(378, 5, 51, 31));
        p2->setMouseTracking(true);
        p3 = new QPushButton(SignIn);
        p3->setObjectName(QStringLiteral("p3"));
        p3->setGeometry(QRect(142, 260, 171, 28));
        l2 = new QLabel(SignIn);
        l2->setObjectName(QStringLiteral("l2"));
        l2->setGeometry(QRect(40, 160, 81, 81));
        l2->setStyleSheet(QStringLiteral("border-image: url(:/tx01.jpg);"));
        t3 = new QTextBrowser(SignIn);
        t3->setObjectName(QStringLiteral("t3"));
        t3->setGeometry(QRect(330, 160, 81, 31));
        t4 = new QTextBrowser(SignIn);
        t4->setObjectName(QStringLiteral("t4"));
        t4->setGeometry(QRect(330, 210, 81, 31));
        t1 = new QLineEdit(SignIn);
        t1->setObjectName(QStringLiteral("t1"));
        t1->setGeometry(QRect(140, 160, 171, 31));
        t2 = new QLineEdit(SignIn);
        t2->setObjectName(QStringLiteral("t2"));
        t2->setGeometry(QRect(140, 210, 171, 31));
        t2->setEchoMode(QLineEdit::Password);

        retranslateUi(SignIn);
        QObject::connect(p2, SIGNAL(clicked()), SignIn, SLOT(close()));
        QObject::connect(p1, SIGNAL(clicked()), SignIn, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(SignIn);
    } // setupUi

    void retranslateUi(QWidget *SignIn)
    {
        SignIn->setWindowTitle(QApplication::translate("SignIn", "Form", Q_NULLPTR));
        l1->setText(QApplication::translate("SignIn", "TextLabel", Q_NULLPTR));
        p1->setText(QApplication::translate("SignIn", "\342\200\224", Q_NULLPTR));
        p2->setText(QApplication::translate("SignIn", "\303\227", Q_NULLPTR));
        p3->setText(QApplication::translate("SignIn", "\347\231\273\345\275\225", Q_NULLPTR));
        l2->setText(QString());
        t3->setHtml(QApplication::translate("SignIn", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline; color:#092ec2;\">\346\263\250\345\206\214\350\264\246\345\217\267</span></p></body></html>", Q_NULLPTR));
        t4->setHtml(QApplication::translate("SignIn", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline; color:#092ec2;\">\345\277\230\350\256\260\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        t1->setText(QString());
        t2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignIn: public Ui_SignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
