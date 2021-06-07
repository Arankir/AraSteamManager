/****************************************************************************
** Meta object code from reading C++ file 'gamesmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/models/gamesmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamesmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GamesModel_t {
    QByteArrayData data[15];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GamesModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GamesModel_t qt_meta_stringdata_GamesModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GamesModel"
QT_MOC_LITERAL(1, 11, 10), // "s_finished"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "s_progress"
QT_MOC_LITERAL(4, 34, 5), // "stage"
QT_MOC_LITERAL(5, 40, 8), // "progress"
QT_MOC_LITERAL(6, 49, 14), // "updateComments"
QT_MOC_LITERAL(7, 64, 4), // "sort"
QT_MOC_LITERAL(8, 69, 6), // "column"
QT_MOC_LITERAL(9, 76, 13), // "Qt::SortOrder"
QT_MOC_LITERAL(10, 90, 5), // "order"
QT_MOC_LITERAL(11, 96, 20), // "onResultAchievements"
QT_MOC_LITERAL(12, 117, 25), // "QList<SAchievementPlayer>"
QT_MOC_LITERAL(13, 143, 12), // "achievements"
QT_MOC_LITERAL(14, 156, 5) // "appId"

    },
    "GamesModel\0s_finished\0\0s_progress\0"
    "stage\0progress\0updateComments\0sort\0"
    "column\0Qt::SortOrder\0order\0"
    "onResultAchievements\0QList<SAchievementPlayer>\0"
    "achievements\0appId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GamesModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    2,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   50,    2, 0x0a /* Public */,
       7,    2,   51,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x2a /* Public | MethodCloned */,
      11,    2,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString,   13,   14,

       0        // eod
};

void GamesModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GamesModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_finished(); break;
        case 1: _t->s_progress((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 2: _t->updateComments(); break;
        case 3: _t->sort((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::SortOrder(*)>(_a[2]))); break;
        case 4: _t->sort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onResultAchievements((*reinterpret_cast< QList<SAchievementPlayer>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
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
            using _t = void (GamesModel::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GamesModel::s_progress)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GamesModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_GamesModel.data,
    qt_meta_data_GamesModel,
    qt_static_metacall,
    nullptr,
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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
void GamesModel::s_progress(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ProxyModelGames_t {
    QByteArrayData data[11];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProxyModelGames_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProxyModelGames_t qt_meta_stringdata_ProxyModelGames = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ProxyModelGames"
QT_MOC_LITERAL(1, 16, 7), // "setName"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "newName"
QT_MOC_LITERAL(4, 33, 7), // "setHide"
QT_MOC_LITERAL(5, 41, 7), // "newHide"
QT_MOC_LITERAL(6, 49, 8), // "setGroup"
QT_MOC_LITERAL(7, 58, 8), // "newGroup"
QT_MOC_LITERAL(8, 67, 12), // "setFavorites"
QT_MOC_LITERAL(9, 80, 12), // "newFavorites"
QT_MOC_LITERAL(10, 93, 5) // "clear"

    },
    "ProxyModelGames\0setName\0\0newName\0"
    "setHide\0newHide\0setGroup\0newGroup\0"
    "setFavorites\0newFavorites\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProxyModelGames[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       8,    1,   48,    2, 0x0a /* Public */,
      10,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::QStringList,    7,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void,

       0        // eod
};

void ProxyModelGames::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProxyModelGames *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setHide((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->setGroup((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 3: _t->setFavorites((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: _t->clear(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProxyModelGames::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_ProxyModelGames.data,
    qt_meta_data_ProxyModelGames,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProxyModelGames::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyModelGames::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProxyModelGames.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int ProxyModelGames::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
