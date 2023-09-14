/****************************************************************************
** Meta object code from reading C++ file 'threadstatistics.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/classes/threads/thread/threadstatistics.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadstatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadStatistics_t {
    const uint offsetsAndSize[32];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ThreadStatistics_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ThreadStatistics_t qt_meta_stringdata_ThreadStatistics = {
    {
QT_MOC_LITERAL(0, 16), // "ThreadStatistics"
QT_MOC_LITERAL(17, 10), // "s_progress"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 4), // "text"
QT_MOC_LITERAL(34, 8), // "progress"
QT_MOC_LITERAL(43, 3), // "max"
QT_MOC_LITERAL(47, 8), // "s_finish"
QT_MOC_LITERAL(56, 11), // "Statistics&"
QT_MOC_LITERAL(68, 4), // "fill"
QT_MOC_LITERAL(73, 20), // "onResultAchievements"
QT_MOC_LITERAL(94, 19), // "SAchievementsPlayer"
QT_MOC_LITERAL(114, 12), // "achievements"
QT_MOC_LITERAL(127, 5), // "SGame"
QT_MOC_LITERAL(133, 4), // "game"
QT_MOC_LITERAL(138, 11), // "updateTimes"
QT_MOC_LITERAL(150, 12) // "unlockedTime"

    },
    "ThreadStatistics\0s_progress\0\0text\0"
    "progress\0max\0s_finish\0Statistics&\0"
    "fill\0onResultAchievements\0SAchievementsPlayer\0"
    "achievements\0SGame\0game\0updateTimes\0"
    "unlockedTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadStatistics[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   44,    2, 0x06,    1 /* Public */,
       6,    1,   51,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   54,    2, 0x08,    7 /* Private */,
       9,    2,   55,    2, 0x08,    8 /* Private */,
      14,    1,   60,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::QDateTime,   15,

       0        // eod
};

void ThreadStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadStatistics *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_progress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->s_finish((*reinterpret_cast< Statistics(*)>(_a[1]))); break;
        case 2: { int _r = _t->fill();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->onResultAchievements((*reinterpret_cast< const SAchievementsPlayer(*)>(_a[1])),(*reinterpret_cast< const SGame(*)>(_a[2]))); break;
        case 4: _t->updateTimes((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
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
        {
            using _t = void (ThreadStatistics::*)(Statistics & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadStatistics::s_finish)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ThreadStatistics::staticMetaObject = { {
    QMetaObject::SuperData::link<ThreadLoading::staticMetaObject>(),
    qt_meta_stringdata_ThreadStatistics.offsetsAndSize,
    qt_meta_data_ThreadStatistics,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ThreadStatistics_t
, QtPrivate::TypeAndForceComplete<ThreadStatistics, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Statistics &, std::false_type>
, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SAchievementsPlayer &, std::false_type>, QtPrivate::TypeAndForceComplete<const SGame &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>


>,
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ThreadStatistics::s_progress(const QString & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadStatistics::s_finish(Statistics & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
