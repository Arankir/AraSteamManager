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
    QByteArrayData data[13];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FramelessWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FramelessWindow_t qt_meta_stringdata_FramelessWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FramelessWindow"
QT_MOC_LITERAL(1, 16, 14), // "updateSettings"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "Edge"
QT_MOC_LITERAL(4, 37, 4), // "None"
QT_MOC_LITERAL(5, 42, 4), // "Left"
QT_MOC_LITERAL(6, 47, 3), // "Top"
QT_MOC_LITERAL(7, 51, 5), // "Right"
QT_MOC_LITERAL(8, 57, 6), // "Bottom"
QT_MOC_LITERAL(9, 64, 7), // "TopLeft"
QT_MOC_LITERAL(10, 72, 8), // "TopRight"
QT_MOC_LITERAL(11, 81, 10), // "BottomLeft"
QT_MOC_LITERAL(12, 92, 11) // "BottomRight"

    },
    "FramelessWindow\0updateSettings\0\0Edge\0"
    "None\0Left\0Top\0Right\0Bottom\0TopLeft\0"
    "TopRight\0BottomLeft\0BottomRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FramelessWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       1,   20, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    9,   25,

 // enum data: key, value
       4, uint(FramelessWindow::None),
       5, uint(FramelessWindow::Left),
       6, uint(FramelessWindow::Top),
       7, uint(FramelessWindow::Right),
       8, uint(FramelessWindow::Bottom),
       9, uint(FramelessWindow::TopLeft),
      10, uint(FramelessWindow::TopRight),
      11, uint(FramelessWindow::BottomLeft),
      12, uint(FramelessWindow::BottomRight),

       0        // eod
};

void FramelessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FramelessWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateSettings(); break;
        default: ;
        }
    }
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
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
