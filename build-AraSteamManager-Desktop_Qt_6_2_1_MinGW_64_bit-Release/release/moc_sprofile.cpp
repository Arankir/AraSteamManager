/****************************************************************************
** Meta object code from reading C++ file 'sprofile.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/classes/steamApi/structures/sprofile.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sprofile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SProfile_t {
    const uint offsetsAndSize[20];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SProfile_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SProfile_t qt_meta_stringdata_SProfile = {
    {
QT_MOC_LITERAL(0, 8), // "SProfile"
QT_MOC_LITERAL(9, 8), // "fromJson"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 5), // "value"
QT_MOC_LITERAL(25, 10), // "loadVanity"
QT_MOC_LITERAL(36, 9), // "ProfileID"
QT_MOC_LITERAL(46, 3), // "aId"
QT_MOC_LITERAL(50, 29), // "std::function<void(SProfile)>"
QT_MOC_LITERAL(80, 9), // "aCallback"
QT_MOC_LITERAL(90, 6) // "loadId"

    },
    "SProfile\0fromJson\0\0value\0loadVanity\0"
    "ProfileID\0aId\0std::function<void(SProfile)>\0"
    "aCallback\0loadId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SProfile[] = {

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
       1,    1,   44,    2, 0x08,    1 /* Private */,
       4,    2,   47,    2, 0x08,    3 /* Private */,
       4,    1,   52,    2, 0x28,    6 /* Private | MethodCloned */,
       9,    2,   55,    2, 0x08,    8 /* Private */,
       9,    1,   60,    2, 0x28,   11 /* Private | MethodCloned */,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonValue,    3,
    0x80000000 | 0, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    0x80000000 | 0, 0x80000000 | 5,    6,
    0x80000000 | 0, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    0x80000000 | 0, 0x80000000 | 5,    6,

       0        // eod
};

void SProfile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SProfile *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fromJson((*reinterpret_cast< const QJsonValue(*)>(_a[1]))); break;
        case 1: { SProfile _r = _t->loadVanity((*reinterpret_cast< const ProfileID(*)>(_a[1])),(*reinterpret_cast< std::function<void(SProfile)>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< SProfile*>(_a[0]) = std::move(_r); }  break;
        case 2: { SProfile _r = _t->loadVanity((*reinterpret_cast< const ProfileID(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< SProfile*>(_a[0]) = std::move(_r); }  break;
        case 3: { SProfile _r = _t->loadId((*reinterpret_cast< const ProfileID(*)>(_a[1])),(*reinterpret_cast< std::function<void(SProfile)>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< SProfile*>(_a[0]) = std::move(_r); }  break;
        case 4: { SProfile _r = _t->loadId((*reinterpret_cast< const ProfileID(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< SProfile*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject SProfile::staticMetaObject = { {
    QMetaObject::SuperData::link<Sapi::staticMetaObject>(),
    qt_meta_stringdata_SProfile.offsetsAndSize,
    qt_meta_data_SProfile,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SProfile_t
, QtPrivate::TypeAndForceComplete<SProfile, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>, QtPrivate::TypeAndForceComplete<SProfile, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<std::function<void(SProfile)>, std::false_type>, QtPrivate::TypeAndForceComplete<SProfile, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<SProfile, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<std::function<void(SProfile)>, std::false_type>, QtPrivate::TypeAndForceComplete<SProfile, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>


>,
    nullptr
} };


const QMetaObject *SProfile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SProfile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SProfile.stringdata0))
        return static_cast<void*>(this);
    return Sapi::qt_metacast(_clname);
}

int SProfile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Sapi::qt_metacall(_c, _id, _a);
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
