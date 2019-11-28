/****************************************************************************
** Meta object code from reading C++ file 'formcategoryvalue.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/subform/formcategoryvalue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcategoryvalue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormCategoryValue_t {
    QByteArrayData data[20];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormCategoryValue_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormCategoryValue_t qt_meta_stringdata_FormCategoryValue = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FormCategoryValue"
QT_MOC_LITERAL(1, 18, 11), // "valuechange"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "pos"
QT_MOC_LITERAL(4, 35, 5), // "value"
QT_MOC_LITERAL(5, 41, 13), // "visiblechange"
QT_MOC_LITERAL(6, 55, 7), // "visible"
QT_MOC_LITERAL(7, 63, 14), // "positionchange"
QT_MOC_LITERAL(8, 78, 6), // "posnew"
QT_MOC_LITERAL(9, 85, 12), // "selectchange"
QT_MOC_LITERAL(10, 98, 6), // "select"
QT_MOC_LITERAL(11, 105, 8), // "deleting"
QT_MOC_LITERAL(12, 114, 31), // "on_CheckBoxVisible_stateChanged"
QT_MOC_LITERAL(13, 146, 4), // "arg1"
QT_MOC_LITERAL(14, 151, 19), // "on_ButtonUp_clicked"
QT_MOC_LITERAL(15, 171, 21), // "on_ButtonDown_clicked"
QT_MOC_LITERAL(16, 193, 23), // "on_ButtonSelect_clicked"
QT_MOC_LITERAL(17, 217, 25), // "on_ButtonUnSelect_clicked"
QT_MOC_LITERAL(18, 243, 23), // "on_ButtonDelete_clicked"
QT_MOC_LITERAL(19, 267, 28) // "on_LineEditTitle_textChanged"

    },
    "FormCategoryValue\0valuechange\0\0pos\0"
    "value\0visiblechange\0visible\0positionchange\0"
    "posnew\0selectchange\0select\0deleting\0"
    "on_CheckBoxVisible_stateChanged\0arg1\0"
    "on_ButtonUp_clicked\0on_ButtonDown_clicked\0"
    "on_ButtonSelect_clicked\0"
    "on_ButtonUnSelect_clicked\0"
    "on_ButtonDelete_clicked\0"
    "on_LineEditTitle_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormCategoryValue[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       5,    2,   79,    2, 0x06 /* Public */,
       7,    2,   84,    2, 0x06 /* Public */,
       9,    2,   89,    2, 0x06 /* Public */,
      11,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   97,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    0,  104,    2, 0x08 /* Private */,
      19,    1,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   10,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void FormCategoryValue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormCategoryValue *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valuechange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->visiblechange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->positionchange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->selectchange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->deleting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_CheckBoxVisible_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_ButtonUp_clicked(); break;
        case 7: _t->on_ButtonDown_clicked(); break;
        case 8: _t->on_ButtonSelect_clicked(); break;
        case 9: _t->on_ButtonUnSelect_clicked(); break;
        case 10: _t->on_ButtonDelete_clicked(); break;
        case 11: _t->on_LineEditTitle_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormCategoryValue::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoryValue::valuechange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormCategoryValue::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoryValue::visiblechange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FormCategoryValue::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoryValue::positionchange)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FormCategoryValue::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoryValue::selectchange)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FormCategoryValue::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoryValue::deleting)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormCategoryValue::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FormCategoryValue.data,
    qt_meta_data_FormCategoryValue,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormCategoryValue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormCategoryValue::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormCategoryValue.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormCategoryValue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void FormCategoryValue::valuechange(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormCategoryValue::visiblechange(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FormCategoryValue::positionchange(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FormCategoryValue::selectchange(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FormCategoryValue::deleting(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
