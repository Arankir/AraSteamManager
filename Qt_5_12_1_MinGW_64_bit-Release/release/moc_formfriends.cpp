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
    QByteArrayData data[23];
    char stringdata0[331];
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
QT_MOC_LITERAL(3, 31, 13), // "go_to_profile"
QT_MOC_LITERAL(4, 45, 2), // "id"
QT_MOC_LITERAL(5, 48, 4), // "type"
QT_MOC_LITERAL(6, 53, 12), // "UpdateBuffer"
QT_MOC_LITERAL(7, 66, 10), // "closeEvent"
QT_MOC_LITERAL(8, 77, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 90, 5), // "event"
QT_MOC_LITERAL(10, 96, 23), // "on_ButtonReturn_clicked"
QT_MOC_LITERAL(11, 120, 13), // "OnResultImage"
QT_MOC_LITERAL(12, 134, 13), // "ImageRequest*"
QT_MOC_LITERAL(13, 148, 4), // "imgr"
QT_MOC_LITERAL(14, 153, 18), // "GoToProfileClicked"
QT_MOC_LITERAL(15, 172, 16), // "FavoritesClicked"
QT_MOC_LITERAL(16, 189, 16), // "UpdateHiddenRows"
QT_MOC_LITERAL(17, 206, 35), // "on_CheckBoxOpenProfile_stateC..."
QT_MOC_LITERAL(18, 242, 4), // "arg1"
QT_MOC_LITERAL(19, 247, 27), // "on_LineEditName_textChanged"
QT_MOC_LITERAL(20, 275, 21), // "on_ButtonFind_clicked"
QT_MOC_LITERAL(21, 297, 27), // "on_ComboBoxStatus_activated"
QT_MOC_LITERAL(22, 325, 5) // "index"

    },
    "FormFriends\0return_to_profile\0\0"
    "go_to_profile\0id\0type\0UpdateBuffer\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_ButtonReturn_clicked\0OnResultImage\0"
    "ImageRequest*\0imgr\0GoToProfileClicked\0"
    "FavoritesClicked\0UpdateHiddenRows\0"
    "on_CheckBoxOpenProfile_stateChanged\0"
    "arg1\0on_LineEditName_textChanged\0"
    "on_ButtonFind_clicked\0on_ComboBoxStatus_activated\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormFriends[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    3,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   82,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,
      17,    1,   92,    2, 0x08 /* Private */,
      19,    1,   95,    2, 0x08 /* Private */,
      20,    0,   98,    2, 0x08 /* Private */,
      21,    1,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void FormFriends::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormFriends *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_to_profile(); break;
        case 1: _t->go_to_profile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: _t->on_ButtonReturn_clicked(); break;
        case 4: _t->OnResultImage((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        case 5: _t->GoToProfileClicked(); break;
        case 6: _t->FavoritesClicked(); break;
        case 7: _t->UpdateHiddenRows(); break;
        case 8: _t->on_CheckBoxOpenProfile_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_LineEditName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_ButtonFind_clicked(); break;
        case 11: _t->on_ComboBoxStatus_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
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
        {
            using _t = void (FormFriends::*)(QString , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFriends::go_to_profile)) {
                *result = 1;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void FormFriends::return_to_profile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormFriends::go_to_profile(QString _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
