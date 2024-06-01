#-------------------------------------------------
#
# Project created by QtCreator 2021-06-13T14:49:37
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtQQ
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    signin.cpp \
    sfriend.cpp \
    chatbox.cpp \
    chatitem.cpp \
    qtqq.cpp \
    udpprocess.cpp \
    sfnews.cpp \
    tcpprocess.cpp \
    groupchatbox.cpp \
    sguser.cpp

HEADERS += \
    signin.h \
    sfriend.h \
    hshowfriend.h \
    chatbox.h \
    chatitem.h \
    qtqq.h \
    udpprocess.h \
    sfnews.h \
    tcpprocess.h \
    groupchatbox.h \
    sguser.h

FORMS += \
    signin.ui \
    sfriend.ui \
    chatbox.ui \
    qtqq.ui \
    sfnews.ui \
    groupchatbox.ui

RESOURCES += \
    picture.qrc
