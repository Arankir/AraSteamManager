/****************************************************************************
** Meta object code from reading C++ file 'steamapiachievementspercentage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/class/steamapiachievementspercentage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'steamapiachievementspercentage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SteamAPIAchievementsPercentage_t {
    QByteArrayData data[7];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SteamAPIAchievementsPercentage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SteamAPIAchievementsPercentage_t qt_meta_stringdata_SteamAPIAchievementsPercentage = {
    {
QT_MOC_LITERAL(0, 0, 30), // "SteamAPIAchievementsPercentage"
QT_MOC_LITERAL(1, 31, 8), // "finished"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 31), // "SteamAPIAchievementsPercentage*"
QT_MOC_LITERAL(4, 73, 4), // "Load"
QT_MOC_LITERAL(5, 78, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 93, 5) // "Reply"

    },
    "SteamAPIAchievementsPercentage\0finished\0"
    "\0SteamAPIAchievementsPercentage*\0Load\0"
    "QNetworkReply*\0Reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SteamAPIAchievementsPercentage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       1,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void SteamAPIAchievementsPercentage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SteamAPIAchievementsPercentage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< SteamAPIAchievementsPercentage*(*)>(_a[1]))); break;
        case 1: _t->finished(); break;
        case 2: _t->Load((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SteamAPIAchievementsPercentage* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SteamAPIAchievementsPercentage::*)(SteamAPIAchievementsPercentage * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SteamAPIAchievementsPercentage::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SteamAPIAchievementsPercentage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SteamAPIAchievementsPercentage::finished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SteamAPIAchievementsPercentage::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SteamAPIAchievementsPercentage.data,
    qt_meta_data_SteamAPIAchievementsPercentage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SteamAPIAchievementsPercentage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SteamAPIAchievementsPercentage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SteamAPIAchievementsPercentage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SteamAPIAchievementsPercentage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SteamAPIAchievementsPercentage::finished(SteamAPIAchievementsPercentage * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SteamAPIAchievementsPercentage::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
