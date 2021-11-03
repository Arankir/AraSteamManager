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
    QByteArrayData data[14];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadStatistics_t qt_meta_stringdata_ThreadStatistics = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ThreadStatistics"
QT_MOC_LITERAL(1, 17, 10), // "s_progress"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "text"
QT_MOC_LITERAL(4, 34, 8), // "progress"
QT_MOC_LITERAL(5, 43, 3), // "max"
QT_MOC_LITERAL(6, 47, 4), // "fill"
QT_MOC_LITERAL(7, 52, 20), // "onResultAchievements"
QT_MOC_LITERAL(8, 73, 25), // "QList<SAchievementPlayer>"
QT_MOC_LITERAL(9, 99, 3), // "ach"
QT_MOC_LITERAL(10, 103, 5), // "SGame"
QT_MOC_LITERAL(11, 109, 5), // "aGame"
QT_MOC_LITERAL(12, 115, 11), // "updateTimes"
QT_MOC_LITERAL(13, 127, 12) // "unlockedTime"

    },
    "ThreadStatistics\0s_progress\0\0text\0"
    "progress\0max\0fill\0onResultAchievements\0"
    "QList<SAchievementPlayer>\0ach\0SGame\0"
    "aGame\0updateTimes\0unlockedTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadStatistics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   41,    2, 0x08 /* Private */,
       7,    2,   42,    2, 0x08 /* Private */,
      12,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,
    QMetaType::Void, QMetaType::QDateTime,   13,

       0        // eod
};

void ThreadStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_progress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: { int _r = _t->fill();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->onResultAchievements((*reinterpret_cast< const QList<SAchievementPlayer>(*)>(_a[1])),(*reinterpret_cast< const SGame(*)>(_a[2]))); break;
        case 3: _t->updateTimes((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadStatistics::*)(const QString & , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadStatistics::s_progress)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThreadStatistics::staticMetaObject = { {
    QMetaObject::SuperData::link<ThreadLoading::staticMetaObject>(),
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
    return ThreadLoading::qt_metacast(_clname);
}

int ThreadStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ThreadLoading::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ThreadStatistics::s_progress(const QString & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
