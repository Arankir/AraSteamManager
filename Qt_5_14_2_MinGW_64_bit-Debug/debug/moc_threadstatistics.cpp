/****************************************************************************
** Meta object code from reading C++ file 'threadstatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/classes/threads/thread/threadstatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadstatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadStatistics_t {
    QByteArrayData data[13];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadStatistics_t qt_meta_stringdata_ThreadStatistics = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ThreadStatistics"
QT_MOC_LITERAL(1, 17, 10), // "s_finished"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "s_progress"
QT_MOC_LITERAL(4, 40, 1), // "p"
QT_MOC_LITERAL(5, 42, 4), // "fill"
QT_MOC_LITERAL(6, 47, 20), // "onResultAchievements"
QT_MOC_LITERAL(7, 68, 25), // "QList<SAchievementPlayer>"
QT_MOC_LITERAL(8, 94, 3), // "ach"
QT_MOC_LITERAL(9, 98, 5), // "SGame"
QT_MOC_LITERAL(10, 104, 5), // "aGame"
QT_MOC_LITERAL(11, 110, 11), // "updateTimes"
QT_MOC_LITERAL(12, 122, 15) // "achievementTime"

    },
    "ThreadStatistics\0s_finished\0\0s_progress\0"
    "p\0fill\0onResultAchievements\0"
    "QList<SAchievementPlayer>\0ach\0SGame\0"
    "aGame\0updateTimes\0achievementTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadStatistics[] = {

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
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,
       6,    2,   44,    2, 0x08 /* Private */,
      11,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::QDateTime,   12,

       0        // eod
};

void ThreadStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_finished(); break;
        case 1: _t->s_progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->fill();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->onResultAchievements((*reinterpret_cast< QList<SAchievementPlayer>(*)>(_a[1])),(*reinterpret_cast< SGame(*)>(_a[2]))); break;
        case 4: _t->updateTimes((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadStatistics::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadStatistics::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadStatistics::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadStatistics::s_progress)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThreadStatistics::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ThreadStatistics.data,
    qt_meta_data_ThreadStatistics,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThreadStatistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadStatistics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadStatistics.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ThreadStatistics::s_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ThreadStatistics::s_progress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
