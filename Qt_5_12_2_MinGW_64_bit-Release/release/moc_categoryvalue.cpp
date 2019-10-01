/****************************************************************************
** Meta object code from reading C++ file 'categoryvalue.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/class/categoryvalue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'categoryvalue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CategoryValue_t {
    QByteArrayData data[16];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CategoryValue_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CategoryValue_t qt_meta_stringdata_CategoryValue = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CategoryValue"
QT_MOC_LITERAL(1, 14, 11), // "valuechange"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "value"
QT_MOC_LITERAL(4, 33, 13), // "visiblechange"
QT_MOC_LITERAL(5, 47, 7), // "visible"
QT_MOC_LITERAL(6, 55, 14), // "positionchange"
QT_MOC_LITERAL(7, 70, 3), // "pos"
QT_MOC_LITERAL(8, 74, 12), // "selectchange"
QT_MOC_LITERAL(9, 87, 6), // "select"
QT_MOC_LITERAL(10, 94, 8), // "deleting"
QT_MOC_LITERAL(11, 103, 13), // "OnChangeValue"
QT_MOC_LITERAL(12, 117, 18), // "OnChangeVisibility"
QT_MOC_LITERAL(13, 136, 16), // "OnChangePosition"
QT_MOC_LITERAL(14, 153, 14), // "OnChangeSelect"
QT_MOC_LITERAL(15, 168, 10) // "OnDeleting"

    },
    "CategoryValue\0valuechange\0\0value\0"
    "visiblechange\0visible\0positionchange\0"
    "pos\0selectchange\0select\0deleting\0"
    "OnChangeValue\0OnChangeVisibility\0"
    "OnChangePosition\0OnChangeSelect\0"
    "OnDeleting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CategoryValue[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       8,    1,   73,    2, 0x06 /* Public */,
      10,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   77,    2, 0x08 /* Private */,
      12,    0,   78,    2, 0x08 /* Private */,
      13,    0,   79,    2, 0x08 /* Private */,
      14,    0,   80,    2, 0x08 /* Private */,
      15,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CategoryValue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CategoryValue *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valuechange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->visiblechange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->positionchange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->selectchange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->deleting(); break;
        case 5: _t->OnChangeValue(); break;
        case 6: _t->OnChangeVisibility(); break;
        case 7: _t->OnChangePosition(); break;
        case 8: _t->OnChangeSelect(); break;
        case 9: _t->OnDeleting(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CategoryValue::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CategoryValue::valuechange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CategoryValue::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CategoryValue::visiblechange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CategoryValue::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CategoryValue::positionchange)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CategoryValue::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CategoryValue::selectchange)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CategoryValue::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CategoryValue::deleting)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CategoryValue::staticMetaObject = { {
    &QGridLayout::staticMetaObject,
    qt_meta_stringdata_CategoryValue.data,
    qt_meta_data_CategoryValue,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CategoryValue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CategoryValue::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CategoryValue.stringdata0))
        return static_cast<void*>(this);
    return QGridLayout::qt_metacast(_clname);
}

int CategoryValue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGridLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CategoryValue::valuechange(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CategoryValue::visiblechange(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CategoryValue::positionchange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CategoryValue::selectchange(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CategoryValue::deleting()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
