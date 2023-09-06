/****************************************************************************
** Meta object code from reading C++ file 'gamesmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/models/gamesmodel.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSet>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamesmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GamesModel_t {
    const uint offsetsAndSize[34];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GamesModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GamesModel_t qt_meta_stringdata_GamesModel = {
    {
QT_MOC_LITERAL(0, 10), // "GamesModel"
QT_MOC_LITERAL(11, 10), // "s_finished"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 10), // "s_progress"
QT_MOC_LITERAL(34, 6), // "status"
QT_MOC_LITERAL(41, 8), // "progress"
QT_MOC_LITERAL(50, 3), // "max"
QT_MOC_LITERAL(54, 14), // "updateComments"
QT_MOC_LITERAL(69, 4), // "sort"
QT_MOC_LITERAL(74, 6), // "column"
QT_MOC_LITERAL(81, 13), // "Qt::SortOrder"
QT_MOC_LITERAL(95, 5), // "order"
QT_MOC_LITERAL(101, 20), // "onResultAchievements"
QT_MOC_LITERAL(122, 19), // "SAchievementsPlayer"
QT_MOC_LITERAL(142, 12), // "achievements"
QT_MOC_LITERAL(155, 6), // "GameID"
QT_MOC_LITERAL(162, 6) // "gameId"

    },
    "GamesModel\0s_finished\0\0s_progress\0"
    "status\0progress\0max\0updateComments\0"
    "sort\0column\0Qt::SortOrder\0order\0"
    "onResultAchievements\0SAchievementsPlayer\0"
    "achievements\0GameID\0gameId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GamesModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    3,   51,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   58,    2, 0x0a,    6 /* Public */,
       8,    2,   59,    2, 0x0a,    7 /* Public */,
       8,    1,   64,    2, 0x2a,   10 /* Public | MethodCloned */,
      12,    2,   67,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10,    9,   11,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,

       0        // eod
};

void GamesModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GamesModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_finished(); break;
        case 1: _t->s_progress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->updateComments(); break;
        case 3: _t->sort((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::SortOrder(*)>(_a[2]))); break;
        case 4: _t->sort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onResultAchievements((*reinterpret_cast< const SAchievementsPlayer(*)>(_a[1])),(*reinterpret_cast< const GameID(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GamesModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GamesModel::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GamesModel::*)(const QString & , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GamesModel::s_progress)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject GamesModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_GamesModel.offsetsAndSize,
    qt_meta_data_GamesModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GamesModel_t
, QtPrivate::TypeAndForceComplete<GamesModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::SortOrder, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SAchievementsPlayer &, std::false_type>, QtPrivate::TypeAndForceComplete<const GameID &, std::false_type>


>,
    nullptr
} };


const QMetaObject *GamesModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GamesModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GamesModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int GamesModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GamesModel::s_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GamesModel::s_progress(const QString & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_FilterModelGames_t {
    const uint offsetsAndSize[34];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FilterModelGames_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FilterModelGames_t qt_meta_stringdata_FilterModelGames = {
    {
QT_MOC_LITERAL(0, 16), // "FilterModelGames"
QT_MOC_LITERAL(17, 15), // "s_modelFinished"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 7), // "setName"
QT_MOC_LITERAL(42, 7), // "newName"
QT_MOC_LITERAL(50, 7), // "setHide"
QT_MOC_LITERAL(58, 12), // "QSet<GameID>"
QT_MOC_LITERAL(71, 7), // "newHide"
QT_MOC_LITERAL(79, 8), // "setGroup"
QT_MOC_LITERAL(88, 8), // "newGroup"
QT_MOC_LITERAL(97, 12), // "setFavorites"
QT_MOC_LITERAL(110, 12), // "newFavorites"
QT_MOC_LITERAL(123, 9), // "clearName"
QT_MOC_LITERAL(133, 9), // "clearHide"
QT_MOC_LITERAL(143, 10), // "clearGroup"
QT_MOC_LITERAL(154, 14), // "clearFavorites"
QT_MOC_LITERAL(169, 5) // "clear"

    },
    "FilterModelGames\0s_modelFinished\0\0"
    "setName\0newName\0setHide\0QSet<GameID>\0"
    "newHide\0setGroup\0newGroup\0setFavorites\0"
    "newFavorites\0clearName\0clearHide\0"
    "clearGroup\0clearFavorites\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterModelGames[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   75,    2, 0x0a,    2 /* Public */,
       5,    1,   78,    2, 0x0a,    4 /* Public */,
       8,    1,   81,    2, 0x0a,    6 /* Public */,
      10,    1,   84,    2, 0x0a,    8 /* Public */,
      12,    0,   87,    2, 0x0a,   10 /* Public */,
      13,    0,   88,    2, 0x0a,   11 /* Public */,
      14,    0,   89,    2, 0x0a,   12 /* Public */,
      15,    0,   90,    2, 0x0a,   13 /* Public */,
      16,    0,   91,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void, 0x80000000 | 6,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FilterModelGames::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterModelGames *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_modelFinished(); break;
        case 1: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setHide((*reinterpret_cast< const QSet<GameID>(*)>(_a[1]))); break;
        case 3: _t->setGroup((*reinterpret_cast< const QSet<GameID>(*)>(_a[1]))); break;
        case 4: _t->setFavorites((*reinterpret_cast< const QSet<GameID>(*)>(_a[1]))); break;
        case 5: _t->clearName(); break;
        case 6: _t->clearHide(); break;
        case 7: _t->clearGroup(); break;
        case 8: _t->clearFavorites(); break;
        case 9: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FilterModelGames::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterModelGames::s_modelFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FilterModelGames::staticMetaObject = { {
    QMetaObject::SuperData::link<FilterModel::staticMetaObject>(),
    qt_meta_stringdata_FilterModelGames.offsetsAndSize,
    qt_meta_data_FilterModelGames,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FilterModelGames_t
, QtPrivate::TypeAndForceComplete<FilterModelGames, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QSet<GameID> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QSet<GameID> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QSet<GameID> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FilterModelGames::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterModelGames::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterModelGames.stringdata0))
        return static_cast<void*>(this);
    return FilterModel::qt_metacast(_clname);
}

int FilterModelGames::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FilterModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FilterModelGames::s_modelFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
