/****************************************************************************
** Meta object code from reading C++ file 'formcategoriestree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/subForms/achievements/formcategoriestree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcategoriestree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormCategoriesTree_t {
    QByteArrayData data[10];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormCategoriesTree_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormCategoriesTree_t qt_meta_stringdata_FormCategoriesTree = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FormCategoriesTree"
QT_MOC_LITERAL(1, 19, 14), // "s_stateChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 9), // "Category*"
QT_MOC_LITERAL(4, 45, 8), // "category"
QT_MOC_LITERAL(5, 54, 5), // "state"
QT_MOC_LITERAL(6, 60, 16), // "s_categoryChange"
QT_MOC_LITERAL(7, 77, 13), // "s_categoryAdd"
QT_MOC_LITERAL(8, 91, 16), // "s_categoryDelete"
QT_MOC_LITERAL(9, 108, 8) // "updateUi"

    },
    "FormCategoriesTree\0s_stateChanged\0\0"
    "Category*\0category\0state\0s_categoryChange\0"
    "s_categoryAdd\0s_categoryDelete\0updateUi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormCategoriesTree[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       6,    1,   44,    2, 0x06 /* Public */,
       7,    1,   47,    2, 0x06 /* Public */,
       8,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void FormCategoriesTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormCategoriesTree *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_stateChanged((*reinterpret_cast< Category*(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 1: _t->s_categoryChange((*reinterpret_cast< Category*(*)>(_a[1]))); break;
        case 2: _t->s_categoryAdd((*reinterpret_cast< Category*(*)>(_a[1]))); break;
        case 3: _t->s_categoryDelete((*reinterpret_cast< Category*(*)>(_a[1]))); break;
        case 4: _t->updateUi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormCategoriesTree::*)(Category * , const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoriesTree::s_stateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormCategoriesTree::*)(Category * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoriesTree::s_categoryChange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FormCategoriesTree::*)(Category * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoriesTree::s_categoryAdd)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FormCategoriesTree::*)(Category * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoriesTree::s_categoryDelete)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormCategoriesTree::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeWidget::staticMetaObject>(),
    qt_meta_stringdata_FormCategoriesTree.data,
    qt_meta_data_FormCategoriesTree,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormCategoriesTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormCategoriesTree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormCategoriesTree.stringdata0))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int FormCategoriesTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FormCategoriesTree::s_stateChanged(Category * _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormCategoriesTree::s_categoryChange(Category * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FormCategoriesTree::s_categoryAdd(Category * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FormCategoriesTree::s_categoryDelete(Category * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
