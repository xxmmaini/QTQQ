/****************************************************************************
** Meta object code from reading C++ file 'udpprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtQQ/udpprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_udpProcess_t {
    QByteArrayData data[8];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_udpProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_udpProcess_t qt_meta_stringdata_udpProcess = {
    {
QT_MOC_LITERAL(0, 0, 10), // "udpProcess"
QT_MOC_LITERAL(1, 11, 7), // "getData"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 16), // "QVector<QString>"
QT_MOC_LITERAL(4, 37, 4), // "data"
QT_MOC_LITERAL(5, 42, 4), // "read"
QT_MOC_LITERAL(6, 47, 7), // "toClose"
QT_MOC_LITERAL(7, 55, 13) // "readGroupData"

    },
    "udpProcess\0getData\0\0QVector<QString>\0"
    "data\0read\0toClose\0readGroupData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_udpProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void udpProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        udpProcess *_t = static_cast<udpProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getData((*reinterpret_cast< const QVector<QString>(*)>(_a[1]))); break;
        case 1: _t->read(); break;
        case 2: _t->toClose(); break;
        case 3: _t->readGroupData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (udpProcess::*_t)(const QVector<QString> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&udpProcess::getData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject udpProcess::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_udpProcess.data,
      qt_meta_data_udpProcess,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *udpProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *udpProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_udpProcess.stringdata0))
        return static_cast<void*>(const_cast< udpProcess*>(this));
    return QObject::qt_metacast(_clname);
}

int udpProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void udpProcess::getData(const QVector<QString> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
