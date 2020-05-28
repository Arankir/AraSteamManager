/****************************************************************************
** Meta object code from reading C++ file 'threadstatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/class/Threads/threadstatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadstatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadStatistics_t {
    QByteArrayData data[23];
    char stringdata0[266];
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
QT_MOC_LITERAL(3, 29, 12), // "QVector<int>"
QT_MOC_LITERAL(4, 42, 5), // "numof"
QT_MOC_LITERAL(5, 48, 32), // "QVector<QPair<QString,QString> >"
QT_MOC_LITERAL(6, 81, 8), // "complete"
QT_MOC_LITERAL(7, 90, 7), // "started"
QT_MOC_LITERAL(8, 98, 10), // "notStarted"
QT_MOC_LITERAL(9, 109, 15), // "QVector<double>"
QT_MOC_LITERAL(10, 125, 14), // "averagePercent"
QT_MOC_LITERAL(11, 140, 10), // "summcolumn"
QT_MOC_LITERAL(12, 151, 5), // "times"
QT_MOC_LITERAL(13, 157, 6), // "months"
QT_MOC_LITERAL(14, 164, 28), // "QVector<QPair<QString,int> >"
QT_MOC_LITERAL(15, 193, 5), // "years"
QT_MOC_LITERAL(16, 199, 10), // "s_progress"
QT_MOC_LITERAL(17, 210, 1), // "p"
QT_MOC_LITERAL(18, 212, 3), // "row"
QT_MOC_LITERAL(19, 216, 4), // "Fill"
QT_MOC_LITERAL(20, 221, 20), // "OnResultAchievements"
QT_MOC_LITERAL(21, 242, 19), // "SAchievementsPlayer"
QT_MOC_LITERAL(22, 262, 3) // "ach"

    },
    "ThreadStatistics\0s_finished\0\0QVector<int>\0"
    "numof\0QVector<QPair<QString,QString> >\0"
    "complete\0started\0notStarted\0QVector<double>\0"
    "averagePercent\0summcolumn\0times\0months\0"
    "QVector<QPair<QString,int> >\0years\0"
    "s_progress\0p\0row\0Fill\0OnResultAchievements\0"
    "SAchievementsPlayer\0ach"
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
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    9,   34,    2, 0x06 /* Public */,
      16,    2,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,   58,    2, 0x0a /* Public */,
      20,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 9, QMetaType::Int, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 14,    4,    6,    7,    8,   10,   11,   12,   13,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void ThreadStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_finished((*reinterpret_cast< QVector<int>(*)>(_a[1])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[2])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[3])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[4])),(*reinterpret_cast< QVector<double>(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QVector<int>(*)>(_a[7])),(*reinterpret_cast< QVector<int>(*)>(_a[8])),(*reinterpret_cast< QVector<QPair<QString,int> >(*)>(_a[9]))); break;
        case 1: _t->s_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: { int _r = _t->Fill();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->OnResultAchievements((*reinterpret_cast< SAchievementsPlayer(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            case 7:
            case 6:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadStatistics::*)(QVector<int> , QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> , QVector<QPair<QString,QString>> , QVector<double> , int , QVector<int> , QVector<int> , QVector<QPair<QString,int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadStatistics::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadStatistics::*)(int , int );
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
void ThreadStatistics::s_finished(QVector<int> _t1, QVector<QPair<QString,QString>> _t2, QVector<QPair<QString,QString>> _t3, QVector<QPair<QString,QString>> _t4, QVector<double> _t5, int _t6, QVector<int> _t7, QVector<int> _t8, QVector<QPair<QString,int>> _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadStatistics::s_progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
