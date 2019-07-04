/****************************************************************************
** Meta object code from reading C++ file 'formfriends.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/formfriends.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formfriends.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormFriends_t {
    QByteArrayData data[23];
    char stringdata0[354];
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
QT_MOC_LITERAL(5, 48, 10), // "closeEvent"
QT_MOC_LITERAL(6, 59, 12), // "QCloseEvent*"
QT_MOC_LITERAL(7, 72, 5), // "event"
QT_MOC_LITERAL(8, 78, 29), // "on_FormFriendsBReturn_clicked"
QT_MOC_LITERAL(9, 108, 13), // "OnResultImage"
QT_MOC_LITERAL(10, 122, 1), // "i"
QT_MOC_LITERAL(11, 124, 4), // "Save"
QT_MOC_LITERAL(12, 129, 13), // "ImageRequest*"
QT_MOC_LITERAL(13, 143, 4), // "imgr"
QT_MOC_LITERAL(14, 148, 18), // "GoToProfileClicked"
QT_MOC_LITERAL(15, 167, 16), // "FavoritesClicked"
QT_MOC_LITERAL(16, 184, 16), // "UpdateHiddenRows"
QT_MOC_LITERAL(17, 201, 41), // "on_FormFriendsChBOpenProfile_..."
QT_MOC_LITERAL(18, 243, 4), // "arg1"
QT_MOC_LITERAL(19, 248, 38), // "on_FormFriendsLineEditName_te..."
QT_MOC_LITERAL(20, 287, 27), // "on_FormFriendsBFind_clicked"
QT_MOC_LITERAL(21, 315, 32), // "on_FormFriendsCBStatus_activated"
QT_MOC_LITERAL(22, 348, 5) // "index"

    },
    "FormFriends\0return_to_profile\0\0"
    "go_to_profile\0id\0closeEvent\0QCloseEvent*\0"
    "event\0on_FormFriendsBReturn_clicked\0"
    "OnResultImage\0i\0Save\0ImageRequest*\0"
    "imgr\0GoToProfileClicked\0FavoritesClicked\0"
    "UpdateHiddenRows\0"
    "on_FormFriendsChBOpenProfile_stateChanged\0"
    "arg1\0on_FormFriendsLineEditName_textChanged\0"
    "on_FormFriendsBFind_clicked\0"
    "on_FormFriendsCBStatus_activated\0index"
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
       3,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   78,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    3,   82,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,
      17,    1,   92,    2, 0x08 /* Private */,
      19,    1,   95,    2, 0x08 /* Private */,
      20,    0,   98,    2, 0x08 /* Private */,
      21,    1,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 12,   10,   11,   13,
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
        case 1: _t->go_to_profile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: _t->on_FormFriendsBReturn_clicked(); break;
        case 4: _t->OnResultImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ImageRequest*(*)>(_a[3]))); break;
        case 5: _t->GoToProfileClicked(); break;
        case 6: _t->FavoritesClicked(); break;
        case 7: _t->UpdateHiddenRows(); break;
        case 8: _t->on_FormFriendsChBOpenProfile_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_FormFriendsLineEditName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_FormFriendsBFind_clicked(); break;
        case 11: _t->on_FormFriendsCBStatus_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
        {
            using _t = void (FormFriends::*)(QString );
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
void FormFriends::go_to_profile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
