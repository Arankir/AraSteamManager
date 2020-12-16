/****************************************************************************
** Meta object code from reading C++ file 'framelesswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/framelesswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'framelesswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FramelessWindow_t {
    QByteArrayData data[11];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FramelessWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FramelessWindow_t qt_meta_stringdata_FramelessWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FramelessWindow"
QT_MOC_LITERAL(1, 16, 4), // "Edge"
QT_MOC_LITERAL(2, 21, 4), // "None"
QT_MOC_LITERAL(3, 26, 4), // "Left"
QT_MOC_LITERAL(4, 31, 3), // "Top"
QT_MOC_LITERAL(5, 35, 5), // "Right"
QT_MOC_LITERAL(6, 41, 6), // "Bottom"
QT_MOC_LITERAL(7, 48, 7), // "TopLeft"
QT_MOC_LITERAL(8, 56, 8), // "TopRight"
QT_MOC_LITERAL(9, 65, 10), // "BottomLeft"
QT_MOC_LITERAL(10, 76, 11) // "BottomRight"

    },
    "FramelessWindow\0Edge\0None\0Left\0Top\0"
    "Right\0Bottom\0TopLeft\0TopRight\0BottomLeft\0"
    "BottomRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FramelessWindow[] = {

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
       2, uint(FramelessWindow::None),
       3, uint(FramelessWindow::Left),
       4, uint(FramelessWindow::Top),
       5, uint(FramelessWindow::Right),
       6, uint(FramelessWindow::Bottom),
       7, uint(FramelessWindow::TopLeft),
       8, uint(FramelessWindow::TopRight),
       9, uint(FramelessWindow::BottomLeft),
      10, uint(FramelessWindow::BottomRight),

       0        // eod
};

void FramelessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FramelessWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FramelessWindow.data,
    qt_meta_data_FramelessWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FramelessWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FramelessWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FramelessWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FramelessWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
