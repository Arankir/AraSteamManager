/****************************************************************************
** Meta object code from reading C++ file 'categoriesmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/models/categoriesmodel.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'categoriesmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CategoriesModel_t {
    const uint offsetsAndSize[36];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CategoriesModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CategoriesModel_t qt_meta_stringdata_CategoriesModel = {
    {
QT_MOC_LITERAL(0, 15), // "CategoriesModel"
QT_MOC_LITERAL(16, 19), // "s_checkStateChanged"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 9), // "Category*"
QT_MOC_LITERAL(47, 8), // "category"
QT_MOC_LITERAL(56, 9), // "isChecked"
QT_MOC_LITERAL(66, 7), // "s_error"
QT_MOC_LITERAL(74, 19), // "removeAllCategories"
QT_MOC_LITERAL(94, 14), // "saveCategories"
QT_MOC_LITERAL(109, 7), // "setGame"
QT_MOC_LITERAL(117, 5), // "SGame"
QT_MOC_LITERAL(123, 5), // "aGame"
QT_MOC_LITERAL(129, 11), // "QModelIndex"
QT_MOC_LITERAL(141, 7), // "aParent"
QT_MOC_LITERAL(149, 10), // "insertRows"
QT_MOC_LITERAL(160, 8), // "position"
QT_MOC_LITERAL(169, 5), // "count"
QT_MOC_LITERAL(175, 6) // "parent"

    },
    "CategoriesModel\0s_checkStateChanged\0"
    "\0Category*\0category\0isChecked\0s_error\0"
    "removeAllCategories\0saveCategories\0"
    "setGame\0SGame\0aGame\0QModelIndex\0aParent\0"
    "insertRows\0position\0count\0parent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CategoriesModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,
       6,    1,   67,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   70,    2, 0x0a,    6 /* Public */,
       8,    0,   71,    2, 0x0a,    7 /* Public */,
       9,    1,   72,    2, 0x0a,    8 /* Public */,
       7,    1,   75,    2, 0x09,   10 /* Protected */,
      14,    3,   78,    2, 0x08,   12 /* Private */,
      14,    2,   85,    2, 0x28,   16 /* Private | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Bool, 0x80000000 | 12,   13,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int, 0x80000000 | 12,   15,   16,   17,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,   15,   16,

       0        // eod
};

void CategoriesModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CategoriesModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_checkStateChanged((*reinterpret_cast< Category*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->s_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { bool _r = _t->removeAllCategories();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->saveCategories();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setGame((*reinterpret_cast< const SGame(*)>(_a[1]))); break;
        case 5: { bool _r = _t->removeAllCategories((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->insertRows((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QModelIndex(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->insertRows((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CategoriesModel::*)(Category * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CategoriesModel::s_checkStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CategoriesModel::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CategoriesModel::s_error)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CategoriesModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_meta_stringdata_CategoriesModel.offsetsAndSize,
    qt_meta_data_CategoriesModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CategoriesModel_t
, QtPrivate::TypeAndForceComplete<CategoriesModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Category *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SGame &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *CategoriesModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CategoriesModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CategoriesModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int CategoriesModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CategoriesModel::s_checkStateChanged(Category * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CategoriesModel::s_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
