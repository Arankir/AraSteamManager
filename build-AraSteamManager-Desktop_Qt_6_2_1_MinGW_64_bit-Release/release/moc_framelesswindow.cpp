/****************************************************************************
** Meta object code from reading C++ file 'framelesswindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/framelesswindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'framelesswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FramelessWindow_t {
    const uint offsetsAndSize[26];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FramelessWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FramelessWindow_t qt_meta_stringdata_FramelessWindow = {
    {
QT_MOC_LITERAL(0, 15), // "FramelessWindow"
QT_MOC_LITERAL(16, 14), // "updateSettings"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 4), // "Edge"
QT_MOC_LITERAL(37, 4), // "None"
QT_MOC_LITERAL(42, 4), // "Left"
QT_MOC_LITERAL(47, 3), // "Top"
QT_MOC_LITERAL(51, 5), // "Right"
QT_MOC_LITERAL(57, 6), // "Bottom"
QT_MOC_LITERAL(64, 7), // "TopLeft"
QT_MOC_LITERAL(72, 8), // "TopRight"
QT_MOC_LITERAL(81, 10), // "BottomLeft"
QT_MOC_LITERAL(92, 11) // "BottomRight"

    },
    "FramelessWindow\0updateSettings\0\0Edge\0"
    "None\0Left\0Top\0Right\0Bottom\0TopLeft\0"
    "TopRight\0BottomLeft\0BottomRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FramelessWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       1,   21, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    9,   26,

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
        (void)_t;
        switch (_id) {
        case 0: _t->updateSettings(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject FramelessWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FramelessWindow.offsetsAndSize,
    qt_meta_data_FramelessWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FramelessWindow_t
, QtPrivate::TypeAndForceComplete<FramelessWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
