/********************************************************************************
** Form generated from reading UI file 'sfnews.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SFNEWS_H
#define UI_SFNEWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sfnews
{
public:
    QLabel *l1;
    QLabel *l2;
    QLabel *l3;

    void setupUi(QWidget *sfnews)
    {
        if (sfnews->objectName().isEmpty())
            sfnews->setObjectName(QStringLiteral("sfnews"));
        sfnews->resize(309, 70);
        l1 = new QLabel(sfnews);
        l1->setObjectName(QStringLiteral("l1"));
        l1->setGeometry(QRect(10, 5, 61, 61));
        l2 = new QLabel(sfnews);
        l2->setObjectName(QStringLiteral("l2"));
        l2->setGeometry(QRect(85, 5, 201, 31));
        l3 = new QLabel(sfnews);
        l3->setObjectName(QStringLiteral("l3"));
        l3->setGeometry(QRect(85, 32, 210, 31));

        retranslateUi(sfnews);

        QMetaObject::connectSlotsByName(sfnews);
    } // setupUi

    void retranslateUi(QWidget *sfnews)
    {
        sfnews->setWindowTitle(QApplication::translate("sfnews", "Form", Q_NULLPTR));
        l1->setText(QString());
        l2->setText(QString());
        l3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class sfnews: public Ui_sfnews {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SFNEWS_H
