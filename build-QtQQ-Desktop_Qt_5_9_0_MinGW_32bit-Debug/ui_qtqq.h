/********************************************************************************
** Form generated from reading UI file 'qtqq.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTQQ_H
#define UI_QTQQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qtqq
{
public:
    QLabel *l1;
    QPushButton *p1;
    QPushButton *p2;
    QLabel *l2;
    QLabel *l3;
    QTextBrowser *t4;
    QLineEdit *l5;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QListWidget *lw;
    QWidget *tab2;
    QTreeWidget *tw;
    QLabel *l6;

    void setupUi(QWidget *Qtqq)
    {
        if (Qtqq->objectName().isEmpty())
            Qtqq->setObjectName(QStringLiteral("Qtqq"));
        Qtqq->resize(335, 775);
        Qtqq->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        l1 = new QLabel(Qtqq);
        l1->setObjectName(QStringLiteral("l1"));
        l1->setGeometry(QRect(5, 5, 81, 31));
        l1->setStyleSheet(QStringLiteral("border-image: url(:/myicon_3.png);"));
        p1 = new QPushButton(Qtqq);
        p1->setObjectName(QStringLiteral("p1"));
        p1->setGeometry(QRect(230, 5, 51, 31));
        p1->setMouseTracking(true);
        p1->setStyleSheet(QStringLiteral(""));
        p2 = new QPushButton(Qtqq);
        p2->setObjectName(QStringLiteral("p2"));
        p2->setGeometry(QRect(280, 5, 51, 31));
        p2->setMouseTracking(true);
        l2 = new QLabel(Qtqq);
        l2->setObjectName(QStringLiteral("l2"));
        l2->setGeometry(QRect(30, 60, 71, 71));
        l3 = new QLabel(Qtqq);
        l3->setObjectName(QStringLiteral("l3"));
        l3->setGeometry(QRect(120, 60, 131, 31));
        t4 = new QTextBrowser(Qtqq);
        t4->setObjectName(QStringLiteral("t4"));
        t4->setGeometry(QRect(120, 100, 191, 31));
        l5 = new QLineEdit(Qtqq);
        l5->setObjectName(QStringLiteral("l5"));
        l5->setGeometry(QRect(15, 150, 321, 31));
        tabWidget = new QTabWidget(Qtqq);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(14, 189, 311, 581));
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setContextMenuPolicy(Qt::NoContextMenu);
        tabWidget->setAcceptDrops(false);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral("QTabBar::tab{height:25;width:155}"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        tab1->setAutoFillBackground(false);
        lw = new QListWidget(tab1);
        lw->setObjectName(QStringLiteral("lw"));
        lw->setGeometry(QRect(-1, -1, 311, 558));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        tw = new QTreeWidget(tab2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tw->setHeaderItem(__qtreewidgetitem);
        tw->setObjectName(QStringLiteral("tw"));
        tw->setGeometry(QRect(-5, -2, 311, 561));
        tw->setIndentation(0);
        tw->header()->setVisible(false);
        tabWidget->addTab(tab2, QString());
        l6 = new QLabel(Qtqq);
        l6->setObjectName(QStringLiteral("l6"));
        l6->setGeometry(QRect(190, 5, 41, 31));
        l6->setStyleSheet(QStringLiteral("border-image: url(:/myicon_2.png);"));

        retranslateUi(Qtqq);
        QObject::connect(p1, SIGNAL(clicked()), Qtqq, SLOT(showMinimized()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Qtqq);
    } // setupUi

    void retranslateUi(QWidget *Qtqq)
    {
        Qtqq->setWindowTitle(QApplication::translate("Qtqq", "Form", Q_NULLPTR));
        l1->setText(QString());
        p1->setText(QApplication::translate("Qtqq", "\342\200\224", Q_NULLPTR));
        p2->setText(QApplication::translate("Qtqq", "\303\227", Q_NULLPTR));
        l2->setText(QString());
        l3->setText(QApplication::translate("Qtqq", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("Qtqq", "\346\266\210\346\201\257", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("Qtqq", "\350\201\224\347\263\273\344\272\272", Q_NULLPTR));
        l6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Qtqq: public Ui_Qtqq {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTQQ_H
