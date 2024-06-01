/****************************************************************************
** Meta object code from reading C++ file 'mysocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/mysocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mysocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mySocket_t {
    QByteArrayData data[16];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mySocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mySocket_t qt_meta_stringdata_mySocket = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mySocket"
QT_MOC_LITERAL(1, 9, 9), // "isGetData"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "data"
QT_MOC_LITERAL(4, 25, 7), // "isClose"
QT_MOC_LITERAL(5, 33, 6), // "closed"
QT_MOC_LITERAL(6, 40, 7), // "getData"
QT_MOC_LITERAL(7, 48, 6), // "dError"
QT_MOC_LITERAL(8, 55, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 84, 6), // "sError"
QT_MOC_LITERAL(10, 91, 11), // "getFirendIP"
QT_MOC_LITERAL(11, 103, 3), // "mid"
QT_MOC_LITERAL(12, 107, 3), // "fid"
QT_MOC_LITERAL(13, 111, 2), // "ip"
QT_MOC_LITERAL(14, 114, 7), // "quitCon"
QT_MOC_LITERAL(15, 122, 6) // "reTime"

    },
    "mySocket\0isGetData\0\0data\0isClose\0"
    "closed\0getData\0dError\0"
    "QAbstractSocket::SocketError\0sError\0"
    "getFirendIP\0mid\0fid\0ip\0quitCon\0reTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mySocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       5,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   66,    2, 0x08 /* Private */,
       7,    1,   67,    2, 0x08 /* Private */,
       9,    0,   70,    2, 0x08 /* Private */,
      10,    3,   71,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x08 /* Private */,
      15,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mySocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mySocket *_t = static_cast<mySocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isGetData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->isClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->closed(); break;
        case 3: _t->getData(); break;
        case 4: _t->dError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->sError(); break;
        case 6: _t->getFirendIP((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->quitCon(); break;
        case 8: _t->reTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mySocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mySocket::isGetData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (mySocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mySocket::isClose)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (mySocket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mySocket::closed)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject mySocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_mySocket.data,
      qt_meta_data_mySocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mySocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mySocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mySocket.stringdata0))
        return static_cast<void*>(const_cast< mySocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int mySocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void mySocket::isGetData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mySocket::isClose(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mySocket::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
