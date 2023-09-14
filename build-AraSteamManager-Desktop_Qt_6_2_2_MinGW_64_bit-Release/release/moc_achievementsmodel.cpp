/****************************************************************************
** Meta object code from reading C++ file 'achievementsmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/models/achievementsmodel.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'achievementsmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AchievementsModel_t {
    const uint offsetsAndSize[24];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AchievementsModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AchievementsModel_t qt_meta_stringdata_AchievementsModel = {
    {
QT_MOC_LITERAL(0, 17), // "AchievementsModel"
QT_MOC_LITERAL(18, 10), // "s_finished"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 10), // "s_progress"
QT_MOC_LITERAL(41, 6), // "status"
QT_MOC_LITERAL(48, 8), // "progress"
QT_MOC_LITERAL(57, 3), // "max"
QT_MOC_LITERAL(61, 14), // "updateComments"
QT_MOC_LITERAL(76, 4), // "sort"
QT_MOC_LITERAL(81, 6), // "column"
QT_MOC_LITERAL(88, 13), // "Qt::SortOrder"
QT_MOC_LITERAL(102, 5) // "order"

    },
    "AchievementsModel\0s_finished\0\0s_progress\0"
    "status\0progress\0max\0updateComments\0"
    "sort\0column\0Qt::SortOrder\0order"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AchievementsModel[] = {

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
       7,    0,   52,    2, 0x0a,    6 /* Public */,
       8,    2,   53,    2, 0x0a,    7 /* Public */,
       8,    1,   58,    2, 0x2a,   10 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10,    9,   11,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void AchievementsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AchievementsModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_finished(); break;
        case 1: _t->s_progress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->updateComments(); break;
        case 3: _t->sort((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::SortOrder(*)>(_a[2]))); break;
        case 4: _t->sort((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AchievementsModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AchievementsModel::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AchievementsModel::*)(const QString & , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AchievementsModel::s_progress)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AchievementsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_AchievementsModel.offsetsAndSize,
    qt_meta_data_AchievementsModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AchievementsModel_t
, QtPrivate::TypeAndForceComplete<AchievementsModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::SortOrder, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *AchievementsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AchievementsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AchievementsModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int AchievementsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AchievementsModel::s_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AchievementsModel::s_progress(const QString & _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_FilterModelAchievements_t {
    const uint offsetsAndSize[54];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FilterModelAchievements_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FilterModelAchievements_t qt_meta_stringdata_FilterModelAchievements = {
    {
QT_MOC_LITERAL(0, 23), // "FilterModelAchievements"
QT_MOC_LITERAL(24, 10), // "addProfile"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 8), // "SProfile"
QT_MOC_LITERAL(45, 7), // "profile"
QT_MOC_LITERAL(53, 10), // "getProfile"
QT_MOC_LITERAL(64, 5), // "index"
QT_MOC_LITERAL(70, 13), // "removeProfile"
QT_MOC_LITERAL(84, 7), // "setName"
QT_MOC_LITERAL(92, 7), // "newName"
QT_MOC_LITERAL(100, 10), // "setReached"
QT_MOC_LITERAL(111, 10), // "newReached"
QT_MOC_LITERAL(122, 16), // "setReachedFriend"
QT_MOC_LITERAL(139, 9), // "ProfileID"
QT_MOC_LITERAL(149, 9), // "profileId"
QT_MOC_LITERAL(159, 13), // "setCategories"
QT_MOC_LITERAL(173, 16), // "CategoriesFilter"
QT_MOC_LITERAL(190, 13), // "newCategories"
QT_MOC_LITERAL(204, 13), // "getCategories"
QT_MOC_LITERAL(218, 12), // "setFavorites"
QT_MOC_LITERAL(231, 12), // "newFavorites"
QT_MOC_LITERAL(244, 5), // "clear"
QT_MOC_LITERAL(250, 11), // "addCategory"
QT_MOC_LITERAL(262, 9), // "Category*"
QT_MOC_LITERAL(272, 9), // "aCategory"
QT_MOC_LITERAL(282, 14), // "removeCategory"
QT_MOC_LITERAL(297, 22) // "updateCategoriesFilter"

    },
    "FilterModelAchievements\0addProfile\0\0"
    "SProfile\0profile\0getProfile\0index\0"
    "removeProfile\0setName\0newName\0setReached\0"
    "newReached\0setReachedFriend\0ProfileID\0"
    "profileId\0setCategories\0CategoriesFilter\0"
    "newCategories\0getCategories\0setFavorites\0"
    "newFavorites\0clear\0addCategory\0Category*\0"
    "aCategory\0removeCategory\0"
    "updateCategoriesFilter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterModelAchievements[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x0a,    1 /* Public */,
       5,    1,   95,    2, 0x0a,    3 /* Public */,
       7,    1,   98,    2, 0x0a,    5 /* Public */,
       8,    1,  101,    2, 0x0a,    7 /* Public */,
      10,    1,  104,    2, 0x0a,    9 /* Public */,
      12,    2,  107,    2, 0x0a,   11 /* Public */,
      15,    1,  112,    2, 0x0a,   14 /* Public */,
      18,    0,  115,    2, 0x10a,   16 /* Public | MethodIsConst  */,
      19,    1,  116,    2, 0x0a,   17 /* Public */,
      21,    0,  119,    2, 0x0a,   19 /* Public */,
      22,    1,  120,    2, 0x0a,   20 /* Public */,
      25,    1,  123,    2, 0x0a,   22 /* Public */,
      26,    0,  126,    2, 0x08,   24 /* Private */,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 3,    4,
    0x80000000 | 3, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   11,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    0x80000000 | 16,
    QMetaType::Void, QMetaType::QStringList,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,

       0        // eod
};

void FilterModelAchievements::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterModelAchievements *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->addProfile((*reinterpret_cast< const SProfile(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { SProfile _r = _t->getProfile((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< SProfile*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->removeProfile((*reinterpret_cast< const SProfile(*)>(_a[1]))); break;
        case 3: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setReached((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setReachedFriend((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const ProfileID(*)>(_a[2]))); break;
        case 6: _t->setCategories((*reinterpret_cast< const CategoriesFilter(*)>(_a[1]))); break;
        case 7: { CategoriesFilter _r = _t->getCategories();
            if (_a[0]) *reinterpret_cast< CategoriesFilter*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setFavorites((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 9: _t->clear(); break;
        case 10: _t->addCategory((*reinterpret_cast< Category*(*)>(_a[1]))); break;
        case 11: _t->removeCategory((*reinterpret_cast< Category*(*)>(_a[1]))); break;
        case 12: _t->updateCategoriesFilter(); break;
        default: ;
        }
    }
}

const QMetaObject FilterModelAchievements::staticMetaObject = { {
    QMetaObject::SuperData::link<FilterModel::staticMetaObject>(),
    qt_meta_stringdata_FilterModelAchievements.offsetsAndSize,
    qt_meta_data_FilterModelAchievements,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FilterModelAchievements_t
, QtPrivate::TypeAndForceComplete<FilterModelAchievements, std::true_type>
, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const SProfile &, std::false_type>, QtPrivate::TypeAndForceComplete<SProfile, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SProfile &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const CategoriesFilter &, std::false_type>, QtPrivate::TypeAndForceComplete<CategoriesFilter, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Category *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Category *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FilterModelAchievements::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterModelAchievements::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterModelAchievements.stringdata0))
        return static_cast<void*>(this);
    return FilterModel::qt_metacast(_clname);
}

int FilterModelAchievements::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FilterModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
