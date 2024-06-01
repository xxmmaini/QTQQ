#include "qtqq.h"
#include "ui_qtqq.h"

Qtqq::Qtqq(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qtqq)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去除边框
    setAttribute(Qt::WA_TranslucentBackground);
    ui->l5->setPlaceholderText("请输入查询的QQ号");
    ui->p1->setFlat(true);//按钮透明化
    ui->p2->setFlat(true);
    ui->l5->setStyleSheet("background:transparent;border-width:0;border-style:outset;");//文本透明且无框
    ui->t4->setStyleSheet("background:transparent;border-width:0;border-style:outset;");
    this->hide();
    si = new SignIn;
    si->show();  
    isOpen = false;

    qfriend = new QTreeWidgetItem(ui->tw);
    qfriend->setText(0, QString(" ▶ 我的好友"));
    qgroup = new QTreeWidgetItem(ui->tw);
    qgroup->setText(0, QString(" ▶ 群聊"));
    qblacklist = new QTreeWidgetItem(ui->tw);
    qblacklist->setText(0, QString(" ▶ 黑名单"));
    ui->tw->addTopLevelItem(qfriend);
    ui->tw->addTopLevelItem(qgroup);
    ui->tw->addTopLevelItem(qblacklist);
    ui->tw->setItemDelegate(new hShowFriend(this));//添加委托，目的改变列表高
    qfriend->setData(0, Qt::UserRole, QSize(0, 10));
    qgroup->setData(0, Qt::UserRole, QSize(0, 10));
    qblacklist->setData(0, Qt::UserRole, QSize(0, 10));
    connect(ui->tw, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(showTreeWidgetItem(QTreeWidgetItem*, int)));
    connect(ui->tw, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(showChatBox(QTreeWidgetItem*,int)));
    ui->lw->clear();//一开始消息框为空（暂未考虑历史消息处理）

    connect(this->si, SIGNAL(isSignIn()), this, SLOT(setConnect()));//登录先建立与服务器的连接


    //数据库设置
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      data_base = QSqlDatabase::database("qt_sql_default_connection");
    else
      data_base = QSqlDatabase::addDatabase("QMYSQL");
    data_base.setHostName("localhost");  //设置主机地址
    data_base.setPort(3306);  //mysql设置端口
    data_base.setDatabaseName("qtqq");  //设置数据库名称
    data_base.setUserName("root");  //设置用户名
    data_base.setPassword("chen144991");  //设置密码
}

void Qtqq::mousePressEvent(QMouseEvent *event)
{
    if( (event->button() == Qt::LeftButton) )
    {
        mouse_press = true;
        mousePoint = event->globalPos() - this->pos();
    }
}

void Qtqq::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
        move(event->globalPos() - mousePoint);
}

void Qtqq::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}

void Qtqq::paintEvent(QPaintEvent *event) // 绘出假阴影效果
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(5, 5, this->width() - 5, this->height() - 5);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 19);
    for(int i = 0; i < 5; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(5 - i, 5 - i, this->width()- (5 - i) * 2, this->height()- (5 - i) * 2);
        color.setAlpha(21 - qSqrt(i) * 7);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

Qtqq::~Qtqq()
{
    delete ui;
}

void Qtqq::showTreeWidgetItem(QTreeWidgetItem* item, int col)
{
    QString str = item->text(col);
    if(str.contains("▶", Qt::CaseSensitive))
    {
        str.replace(QRegExp("▶"), "▼");
        item->setText(col, str);
        ui->tw->expandItem(item);
    }
    else if(str.contains("▼", Qt::CaseSensitive))
    {
        str.replace(QRegExp("▼"), "▶");
        item->setText(col, str);
        ui->tw->collapseItem(item);
    }
}

void Qtqq::showFriend()
{
    //查询数据库中该QQ的好友
    data_base.open();
    QSqlQuery* q = new QSqlQuery(data_base);
    q->exec(QString("select friendId from friend where userId = %1").arg(si->userId));
    while(q->next())
    {
        QString friendId = q->value(0).toString();
        QSqlQuery* p = new QSqlQuery(data_base);
        p->exec(QString("select userName, pSignature, hPortraitName, port from user where iduser = %1").arg(friendId));
        if(p->next())
        {
            QTreeWidgetItem *pf = new QTreeWidgetItem();
            sfriend* sf = new sfriend(ui->tw);
            sf->setDetails(friendId, p->value(0).toString(), p->value(1).toString(), p->value(2).toString(), p->value(3).toInt(), sfriend::User_friend);
            qfriend->addChild(pf);
            ui->tw->setItemWidget(pf, 0, sf);
            pf->setData(0, Qt::UserRole, QSize(0, 40));
            fsTree.insert(fsTree.end(), friendId, pf);
        }
    }
    data_base.close();
}

void Qtqq::showGroup()
{
    //查询数据库该QQ所在的所有群聊
    data_base.open();
    QSqlQuery* q = new QSqlQuery(data_base);
    q->exec(QString("select groupId, groupName, hPortraitName, notice, groupIp, groupPort from user_group, qtqq.group where user_id = %1 and groupId = group_id").arg(si->userId));
    while(q->next())
    {
        QTreeWidgetItem *pg = new QTreeWidgetItem();
        sfriend* sg = new sfriend(ui->tw);//由于格式差不多，因此选择与好友列表同一个结构
        sg->setDetails(q->value(0).toString(), q->value(1).toString(), "", q->value(2).toString(), q->value(5).toInt(), sfriend::User_group, q->value(4).toString(), q->value(3).toString());
        qgroup->addChild(pg);
        ui->tw->setItemWidget(pg, 0, sg);
        pg->setData(0, Qt::UserRole, QSize(0, 40));
    }
    data_base.close();
}

void Qtqq::showThis()
{
    si->hide();
    this->show();
    //数据库查询
    data_base.open();
    QSqlQuery* q = new QSqlQuery(data_base);
    q->exec(QString("select * from user where iduser = %1").arg(si->userId));
    if(q->next())
    {
        ui->l3->setText(q->value(1).toString());
        ui->l3->setFont(QFont(tr("微软雅黑"), 11, QFont::Bold));
        ui->t4->setText(q->value(3).toString());
        ui->t4->setFont(QFont(tr("微软雅黑"), 9));
        QString head = q->value(4).toString();
        mhead = head;
        mport = q->value(5).toInt();
        head = "border-image: url(:/" + head + ");";
        ui->l2->setStyleSheet(head);
    }
    up = new udpProcess(mip, mport, udpProcess::User_lisfriend);//监听好友消息（该线程监听所有好友）
    uh = new QThread;
    up->moveToThread(uh);
    qRegisterMetaType<QVector<QString>>("QVector<QString>");
    connect(up, SIGNAL(getData(const QVector<QString>&)), this, SLOT(recvInfo(const QVector<QString>&)));
    connect(uh, SIGNAL(started()), up, SLOT(read()));//线程开始则开始监听数据
    connect(this, SIGNAL(toCloseUDP()), up, SLOT(toClose()));
    uh->start();
    if(!isOpen)
    {
        showFriend();//若界面已打开说明是断线重连，无需再显示好友这一操作
        showGroup();
        if(qgroup->childCount() !=  0)//说明有群聊，需要为每一个群聊建立一个线程监听消息
        {
            for(int i = 0; i < qgroup->childCount(); ++i)
            {
                auto g = qgroup->child(i);
                auto gg = dynamic_cast<sfriend *>(ui->tw->itemWidget(g, 0));//取出该列表的信息
                udpProcess *uup = new udpProcess(mip, mport, udpProcess::User_lisgroup, gg->getIp(), gg->getPort());
                QThread *uuh = new QThread;
                uup->moveToThread(uuh);
                connect(uup, SIGNAL(getData(const QVector<QString>&)), this, SLOT(recvInfo(const QVector<QString>&)));//当线程接收到信息
                connect(uuh, SIGNAL(started()), uup, SLOT(read()));//线程开始则开始监听数据
                ups.push_back(uup);
                uhs.push_back(uuh);
                uuh->start();
            }
        }
    }
    isOpen = true;
    data_base.close();
}

void Qtqq::recvInfo(QVector<QString> datas)
{
    for(int i = 0; i < datas.size(); ++i)//处理每条消息
    {
        QString ndata = datas[i];
        if(ndata.contains("(group"))//当消息为群聊消息（不可避免会出现误判的现象，还未解决）
        {
            QString id = ndata.mid(0, ndata.indexOf("("));
            if(id == si->userId) return;//说明该消息为自己发出，无需显示
            QString groupid = ndata.mid(ndata.indexOf("p") + 1, ndata.indexOf(")") - ndata.indexOf("p") - 1);
            if(gs.find(groupid) != gs.end())//说明该窗口已打开，只需要将信息发给该窗口显示即可
            {
                emit sendGroupData(groupid, id, ndata.mid(ndata.indexOf(":") + 1, ndata.size() - ndata.indexOf(":") - 1));
            }
            else//说明窗口未打开，需要将窗口打开，在此之前需要去数据库查找该好友的一些信息
            {
                data_base.open();
                QSqlQuery* q = new QSqlQuery(data_base);
                q->exec(QString("select * from qtqq.group where groupId = %1").arg(groupid));
                if(q->next())
                {
                    groupChatBox *gcb = new groupChatBox(q->value(0).toString(), q->value(1).toString(), q->value(2).toString(), q->value(4).toString(), q->value(5).toInt(), q->value(3).toString());
                    gs.insert(q->value(0).toString());
                    //查数据库，将该群聊的其他好友包括自己加入群聊
                    QSqlQuery* p = new QSqlQuery(data_base);
                    p->exec(QString("select iduser, userName, hPortraitName from user_group, user where group_id = %1 and iduser = user_id").arg(groupid));
                    while(p->next())
                    {
                        QString sta = "在线";
                        if(fsip.find(p->value(0).toString()) == fsip.end()) sta = "不在线";
                        gcb->addUser(p->value(0).toString(), p->value(1).toString(), p->value(2).toString(), sta);
                        if(p->value(0).toString() == si->userId)
                            gcb->setMuser(si->userId);
                    }
                    connect(gcb, SIGNAL(isClosed(QString,QString)), this, SLOT(chatClose(QString,QString)));
                    connect(this, SIGNAL(sendGroupData(QString,QString,QString)), gcb, SLOT(showData(QString,QString,QString)));
                    connect(this, SIGNAL(stateChanged(QString,QString)), gcb, SLOT(stateChange(QString,QString)));
                    gcb->show();
                    emit sendGroupData(groupid, id, ndata.mid(ndata.indexOf(":") + 1, ndata.size() - ndata.indexOf(":") - 1));
                }
                data_base.close();
            }
        }
        else
        {
            QString id = ndata.mid(0, ndata.indexOf("("));//提取出发送者的QQ号
            if(ndata.contains("first")) nowDataFirst[id] = ndata.mid(ndata.indexOf(":") + 1, ndata.size() - ndata.indexOf(":") - 1);
            else if(ndata.contains("twist"))
            {
                QString s = ndata.mid(ndata.indexOf(":") + 1, ndata.size() - ndata.indexOf(":") - 1);
                if(s == nowDataFirst[id]) return;
                else nowDataFirst[id] = s;//当前消息是重发，但是当前qq还未收过
            }
            if(qqs.find(id) != qqs.end())//说明该窗口已打开，只需要将信息发给该窗口显示即可
            {
                emit sendData(id, nowDataFirst[id]);
            }
            else//说明窗口未打开，需要将窗口打开，在此之前需要去数据库查找该好友的一些信息
            {
                data_base.open();
                QSqlQuery* q = new QSqlQuery(data_base);
                q->exec(QString("select userName, pSignature, hPortraitName, port from user where iduser = %1").arg(id));
                if(q->next())
                {
                    chatBox *cb = new chatBox(id, this->si->userId, q->value(2).toString(), mhead, q->value(0).toString(), q->value(1).toString(), fsip[id], q->value(3).toInt());
                    cb->setState("在线");
                    qqs.insert(id);
                    cb->show();
                    connect(this, SIGNAL(sendData(QString,QString)), cb, SLOT(getData(QString,QString)));
                    connect(cb, SIGNAL(isClose(QString,QString)), this, SLOT(chatClose(QString,QString)));
                    connect(cb, SIGNAL(getNew(QString,QString,QString,QString,QString)), this, SLOT(addNews(QString,QString,QString,QString,QString)));
                    connect(this, SIGNAL(stateChanged(QString,QString)), cb, SLOT(changeState(QString,QString)));
                    emit sendData(id, nowDataFirst[id]);
                }
                data_base.close();
            }
        }
    }
}

void Qtqq::showChatBox(QTreeWidgetItem* item, int col)
{
    if(item->text(0).contains("▶") || item->text(0).contains("▼")) return;//说明双击的是列表
    //根据类型打开聊天框
    auto t = dynamic_cast<sfriend *>(ui->tw->itemWidget(item, col));//将widget转为sfriend
    if(t->getUT() == sfriend::User_friend)
    {
        //显示聊天框的同时建立二者的UDP连接：需要有ip地址和端口号（对每个QQ的端口号，我选择在数据库中存储一个固定值，在现实应用中显然不太行）
        if(qqs.find(t->getId()) != qqs.end()) return;//说明要打开的聊天框已经打开
        chatBox *cb = new chatBox(t->getId(), this->si->userId, t->gethPortraitName(), mhead, t->getName(), t->getpSignature(), fsip[t->getId()], t->getPort());
        if(t->getState() == "在线")
            cb->setState("在线");
        else
            cb->setState("不在线");
        qqs.insert(t->getId());
        connect(this, SIGNAL(sendData(QString,QString)), cb, SLOT(getData(QString,QString)));
        connect(cb, SIGNAL(isClose(QString,QString)), this, SLOT(chatClose(QString,QString)));
        connect(cb, SIGNAL(getNew(QString,QString,QString,QString,QString)), this, SLOT(addNews(QString,QString,QString,QString,QString)));
        connect(this, SIGNAL(stateChanged(QString,QString)), cb, SLOT(changeState(QString,QString)));
        connect(ui->p2, SIGNAL(clicked(bool)), cb, SLOT(close()));//QQ主界面关闭时聊天界面也关闭
        cb->show();
    }
    else
    {
        if(gs.find(t->getId()) != gs.end()) return;//说明要打开的聊天框已经打开
        groupChatBox *gcb = new groupChatBox(t->getId(), t->getName(), t->gethPortraitName(), t->getIp(), t->getPort(), t->getNotice());
        gs.insert(t->getId());
        //查数据库，将该群聊的其他好友包括自己加入群聊
        data_base.open();
        QSqlQuery* q = new QSqlQuery(data_base);
        q->exec(QString("select iduser, userName, hPortraitName from user_group, user where group_id = %1 and iduser = user_id").arg(t->getId()));
        while(q->next())
        {
            QString sta = "在线";
            if(fsip.find(q->value(0).toString()) == fsip.end() && q->value(0).toString() != si->userId) sta = "不在线";
            gcb->addUser(q->value(0).toString(), q->value(1).toString(), q->value(2).toString(), sta);
            if(q->value(0).toString() == si->userId)
                gcb->setMuser(si->userId);
        }
        data_base.close();
        connect(gcb, SIGNAL(isClosed(QString,QString)), this, SLOT(chatClose(QString,QString)));
        connect(this, SIGNAL(sendGroupData(QString,QString,QString)), gcb, SLOT(showData(QString,QString,QString)));
        connect(this, SIGNAL(stateChanged(QString,QString)), gcb, SLOT(stateChange(QString,QString)));
        gcb->show();
    }
}

void Qtqq::setConnect()
{
    tp = new tcpProcess(si->userId);
    th = new QThread;
    tp->moveToThread(th);
    connect(th, SIGNAL(started()), tp, SLOT(startTime()));
    th->start();
    connect(tp, SIGNAL(sendError()), this, SLOT(dealError()));
    connect(this, SIGNAL(openError()), tp, SLOT(dealError()));//通知连接关闭（还需要结束进程，还没整）
    connect(this, SIGNAL(openError()), si, SLOT(loginError()));//通知登录界面应对
    connect(tp, SIGNAL(successCon()), this, SLOT(showThis()));//实现主界面与登录界面切换，与掉线重连的情况
    connect(tp, SIGNAL(sendClose(QString)), this, SLOT(dealFout(QString)));//通知好友下线
    connect(tp, SIGNAL(sendFriendIp(QString,QString,QString)), this, SLOT(dealFip(QString,QString,QString)));
    connect(tp, SIGNAL(sendDiscon()), this, SLOT(dealDiscon()));
    connect(ui->p2, SIGNAL(clicked(bool)), tp, SLOT(toClose()));//关闭客户端时主动断开与服务器的连接
    connect(ui->p2, SIGNAL(clicked(bool)), this, SLOT(close()));//关闭客户端
}

void Qtqq::dealError()//处理重复登录问题（防止误关）
{
    if(!isOpen)//说明主界面还未开启，该QTQQ需要被销毁
    {
        emit openError();
        th->quit();
        this->close();
    }
}

void Qtqq::dealFout(QString fid)
{
    emit stateChanged(fid, "不在线");//修改所有与该好友相关的状态：聊天框，消息框，好友列表
    QTreeWidgetItem* t = fsTree[fid];//找到对应分支，修改其状态
    auto tt = dynamic_cast<sfriend *>(ui->tw->itemWidget(t, 0));
    tt->setState("不在线");
    ui->tw->setItemWidget(t, 0, tt);
    if(fnews.find(fid) != fnews.end())//说明存在该消息分支
    {
        QListWidgetItem *t = fnews[fid];
        auto n = dynamic_cast<sfnews *>(ui->lw->itemWidget(t));
        n->setState("不在线");
        ui->lw->setItemWidget(t, n);
    }
}

void Qtqq::dealFip(QString mip, QString fid, QString fip)
{
    //qDebug() << mip << "  " << id << "  " << ip;
    this->mip = mip;
    fsip.insert(fsip.end(), fid, fip);//将好友的ip信息存储起来
    //对应好友QQ显示在线：聊天框，消息框，好友列表
    emit stateChanged(fid, "在线");
    QTreeWidgetItem* t = fsTree[fid];//找到对应分支，修改其状态
    auto tt = dynamic_cast<sfriend *>(ui->tw->itemWidget(t, 0));
    tt->setState("在线");
    ui->tw->setItemWidget(t, 0, tt);
    if(fnews.find(fid) != fnews.end())//说明存在该消息分支
    {
        QListWidgetItem *t = fnews[fid];
        auto n = dynamic_cast<sfnews *>(ui->lw->itemWidget(t));
        n->setState("在线");
        ui->lw->setItemWidget(t, n);
    }
}

void Qtqq::dealDiscon()
{
    //断开连接之后要修改自己QQ的状态，还要修改所有好友状态，消息框与聊天框，并且要销毁UDP线程
    ui->l2->setStyleSheet(QString("border-image: url(:/%1);").arg(mhead + "_h"));
    for(auto iter = fsTree.begin(); iter != fsTree.end(); ++iter)
    {
        emit stateChanged(iter.key(), "不在线");
        QTreeWidgetItem* t = iter.value();//找到对应分支，修改其状态
        auto tt = dynamic_cast<sfriend *>(ui->tw->itemWidget(t, 0));
        tt->setState("不在线");
        ui->tw->setItemWidget(t, 0, tt);
        if(fnews.find(iter.key()) != fnews.end())//说明存在该消息分支
        {
            QListWidgetItem *tt = fnews[iter.key()];
            auto n = dynamic_cast<sfnews *>(ui->lw->itemWidget(tt));
            n->setState("在线");
            ui->lw->setItemWidget(tt, n);
        }
    }
    emit toCloseUDP();//停止线程内的循环询问
    uh->quit();//关闭该线程
}

void Qtqq::chatClose(QString id, QString user)
{
    if(user == "friend")
        qqs.erase(qqs.find(id));//删除该对话框已打开的记录
    else
        gs.erase(gs.find(id));//删除该对话框已打开的记录
}

void Qtqq::addNews(QString id, QString name, QString h, QString state, QString news)
{
    if(fnews.find(id) == fnews.end())//说明消息框还未有其显示
    {
        sfnews* n = new sfnews(id, name, h, state);
        n->setLastNews(news);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(n->size());
        ui->lw->addItem(item);
        ui->lw->setItemWidget(item, n);
        fnews.insert(id, item);
    }
    else
    {
        QListWidgetItem *t = fnews[id];
        auto n = dynamic_cast<sfnews *>(ui->lw->itemWidget(t));
        n->setLastNews(news);
        ui->lw->setItemWidget(t, n);
    }
}
