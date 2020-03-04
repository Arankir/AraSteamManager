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
    QByteArrayData data[13];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormTablesHeaders_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormTablesHeaders_t qt_meta_stringdata_FormTablesHeaders = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FormTablesHeaders"
QT_MOC_LITERAL(1, 18, 12), // "InsertColumn"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "a_columns"
QT_MOC_LITERAL(4, 42, 19), // "InsertColumnHeaders"
QT_MOC_LITERAL(5, 62, 12), // "RemoveColumn"
QT_MOC_LITERAL(6, 75, 19), // "RemoveColumnHeaders"
QT_MOC_LITERAL(7, 95, 23), // "SetHorizontalHeaderText"
QT_MOC_LITERAL(8, 119, 7), // "a_index"
QT_MOC_LITERAL(9, 127, 6), // "a_text"
QT_MOC_LITERAL(10, 134, 9), // "InsertRow"
QT_MOC_LITERAL(11, 144, 5), // "a_row"
QT_MOC_LITERAL(12, 150, 9) // "RemoveRow"

    },
    "FormTablesHeaders\0InsertColumn\0\0"
    "a_columns\0InsertColumnHeaders\0"
    "RemoveColumn\0RemoveColumnHeaders\0"
    "SetHorizontalHeaderText\0a_index\0a_text\0"
    "InsertRow\0a_row\0RemoveRow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormTablesHeaders[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    1,   52,    2, 0x0a /* Public */,
       5,    1,   55,    2, 0x0a /* Public */,
       6,    1,   58,    2, 0x0a /* Public */,
       7,    2,   61,    2, 0x0a /* Public */,
      10,    1,   66,    2, 0x0a /* Public */,
      12,    1,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void FormTablesHeaders::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormTablesHeaders *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InsertColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->InsertColumnHeaders((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->RemoveColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->RemoveColumnHeaders((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SetHorizontalHeaderText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->InsertRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->RemoveRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
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
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
