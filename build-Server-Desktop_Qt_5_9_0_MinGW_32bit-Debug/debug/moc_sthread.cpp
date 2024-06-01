/****************************************************************************
** Meta object code from reading C++ file 'sthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/sthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sThread_t {
    QByteArrayData data[14];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sThread_t qt_meta_stringdata_sThread = {
    {
QT_MOC_LITERAL(0, 0, 7), // "sThread"
QT_MOC_LITERAL(1, 8, 9), // "isGetData"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "data"
QT_MOC_LITERAL(4, 24, 7), // "isClose"
QT_MOC_LITERAL(5, 32, 10), // "sendSignal"
QT_MOC_LITERAL(6, 43, 3), // "mid"
QT_MOC_LITERAL(7, 47, 3), // "fid"
QT_MOC_LITERAL(8, 51, 2), // "ip"
QT_MOC_LITERAL(9, 54, 9), // "quitConSg"
QT_MOC_LITERAL(10, 64, 7), // "getData"
QT_MOC_LITERAL(11, 72, 5), // "close"
QT_MOC_LITERAL(12, 78, 11), // "getFirendIP"
QT_MOC_LITERAL(13, 90, 7) // "quitCon"

    },
    "sThread\0isGetData\0\0data\0isClose\0"
    "sendSignal\0mid\0fid\0ip\0quitConSg\0getData\0"
    "close\0getFirendIP\0quitCon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    3,   60,    2, 0x06 /* Public */,
       9,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   68,    2, 0x08 /* Private */,
      11,    1,   71,    2, 0x08 /* Private */,
      12,    3,   74,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Void,

       0        // eod
};

void sThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sThread *_t = static_cast<sThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isGetData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->isClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->quitConSg(); break;
        case 4: _t->getData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->close((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->getFirendIP((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->quitCon(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (sThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sThread::isGetData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (sThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sThread::isClose)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (sThread::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sThread::sendSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (sThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sThread::quitConSg)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject sThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_sThread.data,
      qt_meta_data_sThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *sThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sThread.stringdata0))
        return static_cast<void*>(const_cast< sThread*>(this));
    return QThread::qt_metacast(_clname);
}

int sThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void sThread::isGetData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void sThread::isClose(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void sThread::sendSignal(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void sThread::quitConSg()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
