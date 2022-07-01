/****************************************************************************
** Meta object code from reading C++ file 'gameswithpercentmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/models/gameswithpercentmodel.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameswithpercentmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GamesWithPercentModel_t {
    const uint offsetsAndSize[32];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GamesWithPercentModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GamesWithPercentModel_t qt_meta_stringdata_GamesWithPercentModel = {
    {
QT_MOC_LITERAL(0, 21), // "GamesWithPercentModel"
QT_MOC_LITERAL(22, 10), // "s_finished"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 10), // "s_progress"
QT_MOC_LITERAL(45, 6), // "status"
QT_MOC_LITERAL(52, 8), // "progress"
QT_MOC_LITERAL(61, 3), // "max"
QT_MOC_LITERAL(65, 4), // "sort"
QT_MOC_LITERAL(70, 6), // "column"
QT_MOC_LITERAL(77, 13), // "Qt::SortOrder"
QT_MOC_LITERAL(91, 5), // "order"
QT_MOC_LITERAL(97, 20), // "onResultAchievements"
QT_MOC_LITERAL(118, 19), // "SAchievementsPlayer"
QT_MOC_LITERAL(138, 12), // "achievements"
QT_MOC_LITERAL(151, 6), // "GameID"
QT_MOC_LITERAL(158, 6) // "gameId"

    },
    "GamesWithPercentModel\0s_finished\0\0"
    "s_progress\0status\0progress\0max\0sort\0"
    "column\0Qt::SortOrder\0order\0"
    "onResultAchievements\0SAchievementsPlayer\0"
    "achievements\0GameID\0gameId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GamesWithPercentModel[] = {

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
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    3,   45,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    2,   52,    2, 0x0a,    6 /* Public */,
       7,    1,   57,    2, 0x2a,    9 /* Public | MethodCloned */,
      11,    2,   60,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,

       0        // eod
};

void GamesWithPercentModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GamesWithPercentModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_finished(); break;
        case 1: _t->s_progress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 2: _t->sort((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::SortOrder(*)>(_a[2]))); break;
        case 3: _t->sort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onResultAchievements((*reinterpret_cast< const SAchievementsPlayer(*)>(_a[1])),(*reinterpret_cast< const GameID(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GamesWithPercentModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GamesWithPercentModel::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GamesWithPercentModel::*)(const QString & , const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GamesWithPercentModel::s_progress)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject GamesWithPercentModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_GamesWithPercentModel.offsetsAndSize,
    qt_meta_data_GamesWithPercentModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GamesWithPercentModel_t
, QtPrivate::TypeAndForceComplete<GamesWithPercentModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::SortOrder, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SAchievementsPlayer &, std::false_type>, QtPrivate::TypeAndForceComplete<const GameID &, std::false_type>


>,
    nullptr
} };


const QMetaObject *GamesWithPercentModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GamesWithPercentModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GamesWithPercentModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int GamesWithPercentModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
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
void GamesWithPercentModel::s_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GamesWithPercentModel::s_progress(const QString & _t1, const int & _t2, const int & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
