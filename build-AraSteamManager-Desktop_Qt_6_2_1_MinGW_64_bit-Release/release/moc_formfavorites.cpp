/****************************************************************************
** Meta object code from reading C++ file 'formfavorites.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/main/formfavorites.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formfavorites.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormFavorites_t {
    const uint offsetsAndSize[46];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormFavorites_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormFavorites_t qt_meta_stringdata_FormFavorites = {
    {
QT_MOC_LITERAL(0, 13), // "FormFavorites"
QT_MOC_LITERAL(14, 18), // "s_showAchievements"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 9), // "ProfileID"
QT_MOC_LITERAL(44, 5), // "SGame"
QT_MOC_LITERAL(50, 13), // "s_goToProfile"
QT_MOC_LITERAL(64, 4), // "init"
QT_MOC_LITERAL(69, 6), // "isInit"
QT_MOC_LITERAL(76, 8), // "isLoaded"
QT_MOC_LITERAL(85, 11), // "updateIcons"
QT_MOC_LITERAL(97, 11), // "retranslate"
QT_MOC_LITERAL(109, 15), // "createMenuGames"
QT_MOC_LITERAL(125, 6), // "QMenu*"
QT_MOC_LITERAL(132, 6), // "GameID"
QT_MOC_LITERAL(139, 7), // "aGameId"
QT_MOC_LITERAL(147, 10), // "aProfileId"
QT_MOC_LITERAL(158, 18), // "createMenuProfiles"
QT_MOC_LITERAL(177, 8), // "goToGame"
QT_MOC_LITERAL(186, 22), // "createMenuAchievements"
QT_MOC_LITERAL(209, 13), // "AchievementID"
QT_MOC_LITERAL(223, 14), // "aAchievementId"
QT_MOC_LITERAL(238, 31), // "getProfilesFavoriteAchievements"
QT_MOC_LITERAL(270, 9) // "SProfiles"

    },
    "FormFavorites\0s_showAchievements\0\0"
    "ProfileID\0SGame\0s_goToProfile\0init\0"
    "isInit\0isLoaded\0updateIcons\0retranslate\0"
    "createMenuGames\0QMenu*\0GameID\0aGameId\0"
    "aProfileId\0createMenuProfiles\0goToGame\0"
    "createMenuAchievements\0AchievementID\0"
    "aAchievementId\0getProfilesFavoriteAchievements\0"
    "SProfiles"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormFavorites[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   86,    2, 0x06,    1 /* Public */,
       5,    1,   91,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   94,    2, 0x0a,    6 /* Public */,
       7,    0,   95,    2, 0x0a,    7 /* Public */,
       8,    0,   96,    2, 0x0a,    8 /* Public */,
       9,    0,   97,    2, 0x0a,    9 /* Public */,
      10,    0,   98,    2, 0x0a,   10 /* Public */,
      11,    2,   99,    2, 0x09,   11 /* Protected */,
      16,    1,  104,    2, 0x09,   14 /* Protected */,
      17,    2,  107,    2, 0x09,   16 /* Protected */,
      18,    3,  112,    2, 0x09,   19 /* Protected */,
      21,    0,  119,    2, 0x08,   23 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 12, 0x80000000 | 13, 0x80000000 | 3,   14,   15,
    0x80000000 | 12, 0x80000000 | 3,   15,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 3,   14,   15,
    0x80000000 | 12, 0x80000000 | 13, 0x80000000 | 3, 0x80000000 | 19,   14,   15,   20,
    0x80000000 | 22,

       0        // eod
};

void FormFavorites::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormFavorites *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_showAchievements((*reinterpret_cast< const ProfileID(*)>(_a[1])),(*reinterpret_cast< const SGame(*)>(_a[2]))); break;
        case 1: _t->s_goToProfile((*reinterpret_cast< const ProfileID(*)>(_a[1]))); break;
        case 2: _t->init(); break;
        case 3: { bool _r = _t->isInit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->isLoaded();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->updateIcons(); break;
        case 6: _t->retranslate(); break;
        case 7: { QMenu* _r = _t->createMenuGames((*reinterpret_cast< const GameID(*)>(_a[1])),(*reinterpret_cast< const ProfileID(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 8: { QMenu* _r = _t->createMenuProfiles((*reinterpret_cast< const ProfileID(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 9: _t->goToGame((*reinterpret_cast< const GameID(*)>(_a[1])),(*reinterpret_cast< const ProfileID(*)>(_a[2]))); break;
        case 10: { QMenu* _r = _t->createMenuAchievements((*reinterpret_cast< const GameID(*)>(_a[1])),(*reinterpret_cast< const ProfileID(*)>(_a[2])),(*reinterpret_cast< const AchievementID(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 11: { SProfiles _r = _t->getProfilesFavoriteAchievements();
            if (_a[0]) *reinterpret_cast< SProfiles*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormFavorites::*)(const ProfileID & , const SGame & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFavorites::s_showAchievements)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormFavorites::*)(const ProfileID & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFavorites::s_goToProfile)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FormFavorites::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormFavorites.offsetsAndSize,
    qt_meta_data_FormFavorites,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormFavorites_t
, QtPrivate::TypeAndForceComplete<FormFavorites, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<const SGame &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<const GameID &, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const GameID &, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<const GameID &, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<const AchievementID &, std::false_type>, QtPrivate::TypeAndForceComplete<SProfiles, std::false_type>


>,
    nullptr
} };


const QMetaObject *FormFavorites::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormFavorites::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormFavorites.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormFavorites::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void FormFavorites::s_showAchievements(const ProfileID & _t1, const SGame & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormFavorites::s_goToProfile(const ProfileID & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
