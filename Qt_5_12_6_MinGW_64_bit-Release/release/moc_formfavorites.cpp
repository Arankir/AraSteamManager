/****************************************************************************
** Meta object code from reading C++ file 'formfavorites.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/subform/formfavorites.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formfavorites.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormFavorites_t {
    QByteArrayData data[9];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormFavorites_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormFavorites_t qt_meta_stringdata_FormFavorites = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FormFavorites"
QT_MOC_LITERAL(1, 14, 17), // "return_to_profile"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "InitComponents"
QT_MOC_LITERAL(4, 48, 10), // "FriendLoad"
QT_MOC_LITERAL(5, 59, 9), // "SProfile*"
QT_MOC_LITERAL(6, 69, 13), // "OnResultImage"
QT_MOC_LITERAL(7, 83, 13), // "ImageRequest*"
QT_MOC_LITERAL(8, 97, 21) // "on_pushButton_clicked"

    },
    "FormFavorites\0return_to_profile\0\0"
    "InitComponents\0FriendLoad\0SProfile*\0"
    "OnResultImage\0ImageRequest*\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormFavorites[] = {

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
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       6,    1,   44,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,

       0        // eod
};

void FormFavorites::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormFavorites *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_to_profile(); break;
        case 1: _t->InitComponents(); break;
        case 2: _t->FriendLoad((*reinterpret_cast< SProfile*(*)>(_a[1]))); break;
        case 3: _t->OnResultImage((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SProfile* >(); break;
            }
            break;
        case 3:
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
            using _t = void (FormFavorites::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFavorites::return_to_profile)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormFavorites::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FormFavorites.data,
    qt_meta_data_FormFavorites,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormFavorites::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormFavorites::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormFavorites.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormFavorites::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FormFavorites::return_to_profile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
