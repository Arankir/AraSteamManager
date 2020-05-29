/****************************************************************************
** Meta object code from reading C++ file 'frameless.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/frameless.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frameless.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrameLess_t {
    QByteArrayData data[11];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrameLess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrameLess_t qt_meta_stringdata_FrameLess = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FrameLess"
QT_MOC_LITERAL(1, 10, 4), // "Edge"
QT_MOC_LITERAL(2, 15, 4), // "None"
QT_MOC_LITERAL(3, 20, 4), // "Left"
QT_MOC_LITERAL(4, 25, 3), // "Top"
QT_MOC_LITERAL(5, 29, 5), // "Right"
QT_MOC_LITERAL(6, 35, 6), // "Bottom"
QT_MOC_LITERAL(7, 42, 7), // "TopLeft"
QT_MOC_LITERAL(8, 50, 8), // "TopRight"
QT_MOC_LITERAL(9, 59, 10), // "BottomLeft"
QT_MOC_LITERAL(10, 70, 11) // "BottomRight"

    },
    "FrameLess\0Edge\0None\0Left\0Top\0Right\0"
    "Bottom\0TopLeft\0TopRight\0BottomLeft\0"
    "BottomRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrameLess[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    9,   19,

 // enum data: key, value
       2, uint(FrameLess::None),
       3, uint(FrameLess::Left),
       4, uint(FrameLess::Top),
       5, uint(FrameLess::Right),
       6, uint(FrameLess::Bottom),
       7, uint(FrameLess::TopLeft),
       8, uint(FrameLess::TopRight),
       9, uint(FrameLess::BottomLeft),
      10, uint(FrameLess::BottomRight),

       0        // eod
};

void FrameLess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FrameLess::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FrameLess.data,
    qt_meta_data_FrameLess,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrameLess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrameLess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrameLess.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FrameLess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
