/****************************************************************************
** Meta object code from reading C++ file 'tcpprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtQQ/tcpprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tcpProcess_t {
    QByteArrayData data[15];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tcpProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tcpProcess_t qt_meta_stringdata_tcpProcess = {
    {
QT_MOC_LITERAL(0, 0, 10), // "tcpProcess"
QT_MOC_LITERAL(1, 11, 9), // "sendClose"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 2), // "id"
QT_MOC_LITERAL(4, 25, 9), // "sendError"
QT_MOC_LITERAL(5, 35, 10), // "successCon"
QT_MOC_LITERAL(6, 46, 12), // "sendFriendIp"
QT_MOC_LITERAL(7, 59, 10), // "sendDiscon"
QT_MOC_LITERAL(8, 70, 7), // "getData"
QT_MOC_LITERAL(9, 78, 10), // "dealDiscon"
QT_MOC_LITERAL(10, 89, 7), // "toClose"
QT_MOC_LITERAL(11, 97, 9), // "dealError"
QT_MOC_LITERAL(12, 107, 9), // "sendHeart"
QT_MOC_LITERAL(13, 117, 6), // "tryCon"
QT_MOC_LITERAL(14, 124, 9) // "startTime"

    },
    "tcpProcess\0sendClose\0\0id\0sendError\0"
    "successCon\0sendFriendIp\0sendDiscon\0"
    "getData\0dealDiscon\0toClose\0dealError\0"
    "sendHeart\0tryCon\0startTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tcpProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    0,   77,    2, 0x06 /* Public */,
       5,    0,   78,    2, 0x06 /* Public */,
       6,    3,   79,    2, 0x06 /* Public */,
       7,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   87,    2, 0x0a /* Public */,
       9,    0,   88,    2, 0x0a /* Public */,
      10,    0,   89,    2, 0x0a /* Public */,
      11,    0,   90,    2, 0x0a /* Public */,
      12,    0,   91,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void tcpProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tcpProcess *_t = static_cast<tcpProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendError(); break;
        case 2: _t->successCon(); break;
        case 3: _t->sendFriendIp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->sendDiscon(); break;
        case 5: _t->getData(); break;
        case 6: _t->dealDiscon(); break;
        case 7: _t->toClose(); break;
        case 8: _t->dealError(); break;
        case 9: _t->sendHeart(); break;
        case 10: _t->tryCon(); break;
        case 11: _t->startTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (tcpProcess::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tcpProcess::sendClose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (tcpProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tcpProcess::sendError)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (tcpProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tcpProcess::successCon)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (tcpProcess::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tcpProcess::sendFriendIp)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (tcpProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tcpProcess::sendDiscon)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject tcpProcess::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_tcpProcess.data,
      qt_meta_data_tcpProcess,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *tcpProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tcpProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tcpProcess.stringdata0))
        return static_cast<void*>(const_cast< tcpProcess*>(this));
    return QObject::qt_metacast(_clname);
}

int tcpProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void tcpProcess::sendClose(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tcpProcess::sendError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void tcpProcess::successCon()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void tcpProcess::sendFriendIp(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void tcpProcess::sendDiscon()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
