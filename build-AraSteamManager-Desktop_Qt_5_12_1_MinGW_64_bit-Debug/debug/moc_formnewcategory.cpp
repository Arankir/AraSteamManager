/****************************************************************************
** Meta object code from reading C++ file 'formnewcategory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/formnewcategory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formnewcategory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormNewCategory_t {
    QByteArrayData data[8];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormNewCategory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormNewCategory_t qt_meta_stringdata_FormNewCategory = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FormNewCategory"
QT_MOC_LITERAL(1, 16, 22), // "return_to_achievements"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 10), // "closeEvent"
QT_MOC_LITERAL(4, 51, 12), // "QCloseEvent*"
QT_MOC_LITERAL(5, 64, 49), // "on_FormAddCategoryButtonAddPa..."
QT_MOC_LITERAL(6, 114, 38), // "on_FormAddCategoryButtonCance..."
QT_MOC_LITERAL(7, 153, 43) // "on_FormAddCategoryButtonAddCa..."

    },
    "FormNewCategory\0return_to_achievements\0"
    "\0closeEvent\0QCloseEvent*\0"
    "on_FormAddCategoryButtonAddParameterValue_clicked\0"
    "on_FormAddCategoryButtonCancel_clicked\0"
    "on_FormAddCategoryButtonAddCategory_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormNewCategory[] = {

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
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormNewCategory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormNewCategory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_to_achievements(); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->on_FormAddCategoryButtonAddParameterValue_clicked(); break;
        case 3: _t->on_FormAddCategoryButtonCancel_clicked(); break;
        case 4: _t->on_FormAddCategoryButtonAddCategory_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormNewCategory::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormNewCategory::return_to_achievements)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormNewCategory::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FormNewCategory.data,
    qt_meta_data_FormNewCategory,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormNewCategory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormNewCategory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormNewCategory.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormNewCategory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FormNewCategory::return_to_achievements()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
