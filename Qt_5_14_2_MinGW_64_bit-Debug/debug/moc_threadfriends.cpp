/****************************************************************************
** Meta object code from reading C++ file 'threadfriends.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/class/Threads/threadfriends.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadfriends.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadFriends_t {
    QByteArrayData data[13];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadFriends_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadFriends_t qt_meta_stringdata_ThreadFriends = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ThreadFriends"
QT_MOC_LITERAL(1, 14, 10), // "s_finished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "s_progress"
QT_MOC_LITERAL(4, 37, 1), // "p"
QT_MOC_LITERAL(5, 39, 3), // "row"
QT_MOC_LITERAL(6, 43, 4), // "fill"
QT_MOC_LITERAL(7, 48, 8), // "getState"
QT_MOC_LITERAL(8, 57, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(9, 75, 13), // "gameExtraInfo"
QT_MOC_LITERAL(10, 89, 12), // "personaState"
QT_MOC_LITERAL(11, 102, 10), // "getPrivacy"
QT_MOC_LITERAL(12, 113, 24) // "communityVisibilityState"

    },
    "ThreadFriends\0s_finished\0\0s_progress\0"
    "p\0row\0fill\0getState\0QTableWidgetItem*\0"
    "gameExtraInfo\0personaState\0getPrivacy\0"
    "communityVisibilityState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadFriends[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    2,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    2,   46,    2, 0x08 /* Private */,
      11,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Int,
    0x80000000 | 8, QMetaType::QString, QMetaType::Int,    9,   10,
    0x80000000 | 8, QMetaType::Int,   12,

       0        // eod
};

void ThreadFriends::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadFriends *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_finished(); break;
        case 1: _t->s_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: { int _r = _t->fill();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { QTableWidgetItem* _r = _t->getState((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QTableWidgetItem**>(_a[0]) = std::move(_r); }  break;
        case 4: { QTableWidgetItem* _r = _t->getPrivacy((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTableWidgetItem**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadFriends::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadFriends::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadFriends::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadFriends::s_progress)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThreadFriends::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ThreadFriends.data,
    qt_meta_data_ThreadFriends,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThreadFriends::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadFriends::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadFriends.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadFriends::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ThreadFriends::s_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ThreadFriends::s_progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
