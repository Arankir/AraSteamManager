/****************************************************************************
** Meta object code from reading C++ file 'formtablesheaders.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subform/formtablesheaders.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formtablesheaders.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormTablesHeaders_t {
    QByteArrayData data[16];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormTablesHeaders_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormTablesHeaders_t qt_meta_stringdata_FormTablesHeaders = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FormTablesHeaders"
QT_MOC_LITERAL(1, 18, 20), // "s_contentCellClicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 3), // "row"
QT_MOC_LITERAL(4, 44, 3), // "col"
QT_MOC_LITERAL(5, 48, 9), // "InsertRow"
QT_MOC_LITERAL(6, 58, 5), // "a_row"
QT_MOC_LITERAL(7, 64, 9), // "RemoveRow"
QT_MOC_LITERAL(8, 74, 15), // "AddFriendColumn"
QT_MOC_LITERAL(9, 90, 8), // "SProfile"
QT_MOC_LITERAL(10, 99, 13), // "friendProfile"
QT_MOC_LITERAL(11, 113, 16), // "AddNoValueColumn"
QT_MOC_LITERAL(12, 130, 17), // "AddCategoryColumn"
QT_MOC_LITERAL(13, 148, 18), // "RemoveFriendColumn"
QT_MOC_LITERAL(14, 167, 8), // "a_column"
QT_MOC_LITERAL(15, 176, 20) // "RemoveCategoryColumn"

    },
    "FormTablesHeaders\0s_contentCellClicked\0"
    "\0row\0col\0InsertRow\0a_row\0RemoveRow\0"
    "AddFriendColumn\0SProfile\0friendProfile\0"
    "AddNoValueColumn\0AddCategoryColumn\0"
    "RemoveFriendColumn\0a_column\0"
    "RemoveCategoryColumn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormTablesHeaders[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   59,    2, 0x0a /* Public */,
       7,    1,   62,    2, 0x0a /* Public */,
       8,    1,   65,    2, 0x0a /* Public */,
      11,    0,   68,    2, 0x0a /* Public */,
      12,    0,   69,    2, 0x0a /* Public */,
      13,    1,   70,    2, 0x0a /* Public */,
      15,    1,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Bool, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void FormTablesHeaders::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormTablesHeaders *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_contentCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->InsertRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->RemoveRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { bool _r = _t->AddFriendColumn((*reinterpret_cast< SProfile(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->AddNoValueColumn(); break;
        case 5: _t->AddCategoryColumn(); break;
        case 6: _t->RemoveFriendColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->RemoveCategoryColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormTablesHeaders::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormTablesHeaders::s_contentCellClicked)) {
                *result = 0;
                return;
            }
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FormTablesHeaders::s_contentCellClicked(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
