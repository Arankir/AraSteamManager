/****************************************************************************
** Meta object code from reading C++ file 'formtablesheaders.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AraSteamManager/subform/formtablesheaders.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formtablesheaders.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormTablesHeaders_t {
<<<<<<< HEAD
    QByteArrayData data[1];
    char stringdata0[18];
=======
    QByteArrayData data[8];
    char stringdata0[81];
>>>>>>> работает
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormTablesHeaders_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormTablesHeaders_t qt_meta_stringdata_FormTablesHeaders = {
    {
<<<<<<< HEAD
QT_MOC_LITERAL(0, 0, 17) // "FormTablesHeaders"

    },
    "FormTablesHeaders"
=======
QT_MOC_LITERAL(0, 0, 17), // "FormTablesHeaders"
QT_MOC_LITERAL(1, 18, 12), // "InsertColumn"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "a_columns"
QT_MOC_LITERAL(4, 42, 12), // "RemoveColumn"
QT_MOC_LITERAL(5, 55, 9), // "InsertRow"
QT_MOC_LITERAL(6, 65, 5), // "a_row"
QT_MOC_LITERAL(7, 71, 9) // "RemoveRow"

    },
    "FormTablesHeaders\0InsertColumn\0\0"
    "a_columns\0RemoveColumn\0InsertRow\0a_row\0"
    "RemoveRow"
>>>>>>> работает
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormTablesHeaders[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
       0,    0, // methods
=======
       4,   14, // methods
>>>>>>> работает
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

<<<<<<< HEAD
=======
 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       7,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

>>>>>>> работает
       0        // eod
};

void FormTablesHeaders::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
<<<<<<< HEAD
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
=======
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormTablesHeaders *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InsertColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->RemoveColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->InsertRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->RemoveRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
>>>>>>> работает
}

QT_INIT_METAOBJECT const QMetaObject FormTablesHeaders::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormTablesHeaders.data,
    qt_meta_data_FormTablesHeaders,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormTablesHeaders::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormTablesHeaders::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormTablesHeaders.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormTablesHeaders::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
<<<<<<< HEAD
=======
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
>>>>>>> работает
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE