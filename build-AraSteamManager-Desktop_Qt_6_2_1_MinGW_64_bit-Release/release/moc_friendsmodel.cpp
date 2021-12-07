/****************************************************************************
** Meta object code from reading C++ file 'friendsmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/models/friendsmodel.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'friendsmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FriendsModel_t {
    const uint offsetsAndSize[22];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FriendsModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FriendsModel_t qt_meta_stringdata_FriendsModel = {
    {
QT_MOC_LITERAL(0, 12), // "FriendsModel"
QT_MOC_LITERAL(13, 10), // "s_finished"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 10), // "s_progress"
QT_MOC_LITERAL(36, 6), // "status"
QT_MOC_LITERAL(43, 8), // "progress"
QT_MOC_LITERAL(52, 3), // "max"
QT_MOC_LITERAL(56, 4), // "sort"
QT_MOC_LITERAL(61, 6), // "column"
QT_MOC_LITERAL(68, 13), // "Qt::SortOrder"
QT_MOC_LITERAL(82, 5) // "order"

    },
    "FriendsModel\0s_finished\0\0s_progress\0"
    "status\0progress\0max\0sort\0column\0"
    "Qt::SortOrder\0order"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendsModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    3,   39,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    2,   46,    2, 0x0a,    6 /* Public */,
       7,    1,   51,    2, 0x2a,    9 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void FriendsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FriendsModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_finished(); break;
        case 1: _t->s_progress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 2: _t->sort((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::SortOrder(*)>(_a[2]))); break;
        case 3: _t->sort((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FriendsModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FriendsModel::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FriendsModel::*)(const QString & , const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FriendsModel::s_progress)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FriendsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_FriendsModel.offsetsAndSize,
    qt_meta_data_FriendsModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FriendsModel_t
, QtPrivate::TypeAndForceComplete<FriendsModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::SortOrder, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *FriendsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FriendsModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int FriendsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FriendsModel::s_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FriendsModel::s_progress(const QString & _t1, const int & _t2, const int & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ProxyModelFriends_t {
    const uint offsetsAndSize[22];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProxyModelFriends_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProxyModelFriends_t qt_meta_stringdata_ProxyModelFriends = {
    {
QT_MOC_LITERAL(0, 17), // "ProxyModelFriends"
QT_MOC_LITERAL(18, 7), // "setName"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 7), // "newName"
QT_MOC_LITERAL(35, 9), // "setStatus"
QT_MOC_LITERAL(45, 9), // "newStatus"
QT_MOC_LITERAL(55, 11), // "setIsPublic"
QT_MOC_LITERAL(67, 8), // "isPublic"
QT_MOC_LITERAL(76, 12), // "setFavorites"
QT_MOC_LITERAL(89, 12), // "newFavorites"
QT_MOC_LITERAL(102, 5) // "clear"

    },
    "ProxyModelFriends\0setName\0\0newName\0"
    "setStatus\0newStatus\0setIsPublic\0"
    "isPublic\0setFavorites\0newFavorites\0"
    "clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProxyModelFriends[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    1,   47,    2, 0x0a,    3 /* Public */,
       6,    1,   50,    2, 0x0a,    5 /* Public */,
       8,    1,   53,    2, 0x0a,    7 /* Public */,
      10,    0,   56,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void,

       0        // eod
};

void ProxyModelFriends::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProxyModelFriends *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setIsPublic((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->setFavorites((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: _t->clear(); break;
        default: ;
        }
    }
}

const QMetaObject ProxyModelFriends::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_ProxyModelFriends.offsetsAndSize,
    qt_meta_data_ProxyModelFriends,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProxyModelFriends_t
, QtPrivate::TypeAndForceComplete<ProxyModelFriends, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProxyModelFriends::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyModelFriends::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProxyModelFriends.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int ProxyModelFriends::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
