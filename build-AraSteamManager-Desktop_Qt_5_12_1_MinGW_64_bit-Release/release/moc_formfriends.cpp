/****************************************************************************
** Meta object code from reading C++ file 'formfriends.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/formfriends.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formfriends.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormFriends_t {
    QByteArrayData data[13];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormFriends_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormFriends_t qt_meta_stringdata_FormFriends = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FormFriends"
QT_MOC_LITERAL(1, 12, 17), // "return_to_profile"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "closeEvent"
QT_MOC_LITERAL(4, 42, 12), // "QCloseEvent*"
QT_MOC_LITERAL(5, 55, 5), // "event"
QT_MOC_LITERAL(6, 61, 29), // "on_FormFriendsBReturn_clicked"
QT_MOC_LITERAL(7, 91, 13), // "OnResultImage"
QT_MOC_LITERAL(8, 105, 1), // "i"
QT_MOC_LITERAL(9, 107, 4), // "Save"
QT_MOC_LITERAL(10, 112, 13), // "ImageRequest*"
QT_MOC_LITERAL(11, 126, 4), // "imgr"
QT_MOC_LITERAL(12, 131, 18) // "GoToProfileClicked"

    },
    "FormFriends\0return_to_profile\0\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_FormFriendsBReturn_clicked\0"
    "OnResultImage\0i\0Save\0ImageRequest*\0"
    "imgr\0GoToProfileClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormFriends[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    3,   44,    2, 0x08 /* Private */,
      12,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 10,    8,    9,   11,
    QMetaType::Void,

       0        // eod
};

void FormFriends::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormFriends *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_to_profile(); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->on_FormFriendsBReturn_clicked(); break;
        case 3: _t->OnResultImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ImageRequest*(*)>(_a[3]))); break;
        case 4: _t->GoToProfileClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageRequest* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormFriends::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFriends::return_to_profile)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormFriends::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FormFriends.data,
    qt_meta_data_FormFriends,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormFriends::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormFriends::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormFriends.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormFriends::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void FormFriends::return_to_profile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
