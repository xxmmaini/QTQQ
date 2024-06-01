/********************************************************************************
** Form generated from reading UI file 'sfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SFRIEND_H
#define UI_SFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sfriend
{
public:
    QLabel *l2;
    QLabel *l3;
    QLabel *l1;

    void setupUi(QWidget *sfriend)
    {
        if (sfriend->objectName().isEmpty())
            sfriend->setObjectName(QStringLiteral("sfriend"));
        sfriend->resize(314, 65);
        l2 = new QLabel(sfriend);
        l2->setObjectName(QStringLiteral("l2"));
        l2->setGeometry(QRect(70, 0, 241, 31));
        l2->setStyleSheet(QStringLiteral(""));
        l3 = new QLabel(sfriend);
        l3->setObjectName(QStringLiteral("l3"));
        l3->setGeometry(QRect(70, 30, 251, 31));
        l1 = new QLabel(sfriend);
        l1->setObjectName(QStringLiteral("l1"));
        l1->setGeometry(QRect(0, 0, 61, 61));

        retranslateUi(sfriend);

        QMetaObject::connectSlotsByName(sfriend);
    } // setupUi

    void retranslateUi(QWidget *sfriend)
    {
        sfriend->setWindowTitle(QApplication::translate("sfriend", "Form", Q_NULLPTR));
        l2->setText(QString());
        l3->setText(QString());
        l1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class sfriend: public Ui_sfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SFRIEND_H
