/****************************************************************************
** Meta object code from reading C++ file 'Sprofile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/class/steamapi/Sprofile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Sprofile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SProfile_t {
    QByteArrayData data[7];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SProfile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SProfile_t qt_meta_stringdata_SProfile = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SProfile"
QT_MOC_LITERAL(1, 9, 10), // "s_finished"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "SProfile*"
QT_MOC_LITERAL(4, 31, 7), // "LoadURL"
QT_MOC_LITERAL(5, 39, 12), // "RequestData*"
QT_MOC_LITERAL(6, 52, 7) // "request"

    },
    "SProfile\0s_finished\0\0SProfile*\0LoadURL\0"
    "RequestData*\0request"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SProfile[] = {

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

void SProfile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SProfile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_finished((*reinterpret_cast< SProfile*(*)>(_a[1]))); break;
        case 1: _t->s_finished(); break;
        case 2: _t->LoadURL((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SProfile* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RequestData* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SProfile::*)(SProfile * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SProfile::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SProfile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SProfile::s_finished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SProfile::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SProfile.data,
    qt_meta_data_SProfile,
    qt_static_metacall,
    nullptr,
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
    return QObject::qt_metacast(_clname);
}

int SProfile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SProfile::s_finished(SProfile * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SProfile::s_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_SProfiles_t {
    QByteArrayData data[8];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SProfiles_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SProfiles_t qt_meta_stringdata_SProfiles = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SProfiles"
QT_MOC_LITERAL(1, 10, 10), // "s_finished"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "SProfiles*"
QT_MOC_LITERAL(4, 33, 7), // "LoadURL"
QT_MOC_LITERAL(5, 41, 12), // "RequestData*"
QT_MOC_LITERAL(6, 54, 9), // "a_request"
QT_MOC_LITERAL(7, 64, 10) // "LoadVanity"

    },
    "SProfiles\0s_finished\0\0SProfiles*\0"
    "LoadURL\0RequestData*\0a_request\0"
    "LoadVanity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SProfiles[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,
       1,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   38,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void SProfiles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SProfiles *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_finished((*reinterpret_cast< SProfiles*(*)>(_a[1]))); break;
        case 1: _t->s_finished(); break;
        case 2: _t->LoadURL((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        case 3: _t->LoadVanity((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SProfiles* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RequestData* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RequestData* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SProfiles::*)(SProfiles * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SProfiles::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SProfiles::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SProfiles::s_finished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SProfiles::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SProfiles.data,
    qt_meta_data_SProfiles,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SProfiles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SProfiles::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SProfiles.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SProfiles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SProfiles::s_finished(SProfiles * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SProfiles::s_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
