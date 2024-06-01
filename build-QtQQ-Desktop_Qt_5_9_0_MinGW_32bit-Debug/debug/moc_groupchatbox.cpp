/****************************************************************************
** Meta object code from reading C++ file 'groupchatbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtQQ/groupchatbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupchatbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_groupChatBox_t {
    QByteArrayData data[14];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_groupChatBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_groupChatBox_t qt_meta_stringdata_groupChatBox = {
    {
QT_MOC_LITERAL(0, 0, 12), // "groupChatBox"
QT_MOC_LITERAL(1, 13, 8), // "isClosed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 2), // "id"
QT_MOC_LITERAL(4, 26, 4), // "type"
QT_MOC_LITERAL(5, 31, 8), // "sendData"
QT_MOC_LITERAL(6, 40, 4), // "data"
QT_MOC_LITERAL(7, 45, 10), // "sendClosed"
QT_MOC_LITERAL(8, 56, 10), // "tosendData"
QT_MOC_LITERAL(9, 67, 8), // "showData"
QT_MOC_LITERAL(10, 76, 3), // "gid"
QT_MOC_LITERAL(11, 80, 3), // "fid"
QT_MOC_LITERAL(12, 84, 11), // "stateChange"
QT_MOC_LITERAL(13, 96, 5) // "state"

    },
    "groupChatBox\0isClosed\0\0id\0type\0sendData\0"
    "data\0sendClosed\0tosendData\0showData\0"
    "gid\0fid\0stateChange\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_groupChatBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   52,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,
       9,    3,   54,    2, 0x0a /* Public */,
      12,    2,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,   13,

       0        // eod
};

void groupChatBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        groupChatBox *_t = static_cast<groupChatBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isClosed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendClosed(); break;
        case 3: _t->tosendData(); break;
        case 4: _t->showData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->stateChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (groupChatBox::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&groupChatBox::isClosed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (groupChatBox::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&groupChatBox::sendData)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject groupChatBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_groupChatBox.data,
      qt_meta_data_groupChatBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *groupChatBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *groupChatBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_groupChatBox.stringdata0))
        return static_cast<void*>(const_cast< groupChatBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int groupChatBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void groupChatBox::isClosed(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void groupChatBox::sendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
