/****************************************************************************
** Meta object code from reading C++ file 'Sachievements.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/class/steamapi/Sachievements.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Sachievements.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SAchievements_t {
    QByteArrayData data[11];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SAchievements_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SAchievements_t qt_meta_stringdata_SAchievements = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SAchievements"
QT_MOC_LITERAL(1, 14, 8), // "finished"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "SAchievements*"
QT_MOC_LITERAL(4, 39, 3), // "Set"
QT_MOC_LITERAL(5, 43, 19), // "SAchievementsPlayer"
QT_MOC_LITERAL(6, 63, 6), // "Player"
QT_MOC_LITERAL(7, 70, 19), // "SAchievementsGlobal"
QT_MOC_LITERAL(8, 90, 6), // "Global"
QT_MOC_LITERAL(9, 97, 23), // "SAchievementsPercentage"
QT_MOC_LITERAL(10, 121, 7) // "Percent"

    },
    "SAchievements\0finished\0\0SAchievements*\0"
    "Set\0SAchievementsPlayer\0Player\0"
    "SAchievementsGlobal\0Global\0"
    "SAchievementsPercentage\0Percent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SAchievements[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       1,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   43,    2, 0x0a /* Public */,
       4,    1,   46,    2, 0x0a /* Public */,
       4,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void SAchievements::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SAchievements *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< SAchievements*(*)>(_a[1]))); break;
        case 1: _t->finished(); break;
        case 2: _t->Set((*reinterpret_cast< SAchievementsPlayer(*)>(_a[1]))); break;
        case 3: _t->Set((*reinterpret_cast< SAchievementsGlobal(*)>(_a[1]))); break;
        case 4: _t->Set((*reinterpret_cast< SAchievementsPercentage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SAchievements* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SAchievements::*)(SAchievements * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SAchievements::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SAchievements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SAchievements::finished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SAchievements::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SAchievements.data,
    qt_meta_data_SAchievements,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SAchievements::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SAchievements::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SAchievements.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SAchievements::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SAchievements::finished(SAchievements * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SAchievements::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
