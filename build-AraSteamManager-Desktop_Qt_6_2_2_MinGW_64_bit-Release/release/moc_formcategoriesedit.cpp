/****************************************************************************
** Meta object code from reading C++ file 'formcategoriesedit.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/achievements/formcategoriesedit.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcategoriesedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormCategoriesEdit_t {
    const uint offsetsAndSize[28];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormCategoriesEdit_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormCategoriesEdit_t qt_meta_stringdata_FormCategoriesEdit = {
    {
QT_MOC_LITERAL(0, 18), // "FormCategoriesEdit"
QT_MOC_LITERAL(19, 21), // "s_categoriesIsUpdated"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 9), // "isUpdated"
QT_MOC_LITERAL(52, 4), // "init"
QT_MOC_LITERAL(57, 11), // "updateIcons"
QT_MOC_LITERAL(69, 11), // "retranslate"
QT_MOC_LITERAL(81, 16), // "achievementsToUi"
QT_MOC_LITERAL(98, 12), // "indexFromRow"
QT_MOC_LITERAL(111, 12), // "QListWidget*"
QT_MOC_LITERAL(124, 10), // "listWidget"
QT_MOC_LITERAL(135, 3), // "row"
QT_MOC_LITERAL(139, 20), // "buttonCancel_Clicked"
QT_MOC_LITERAL(160, 20) // "buttonAccept_Clicked"

    },
    "FormCategoriesEdit\0s_categoriesIsUpdated\0"
    "\0isUpdated\0init\0updateIcons\0retranslate\0"
    "achievementsToUi\0indexFromRow\0"
    "QListWidget*\0listWidget\0row\0"
    "buttonCancel_Clicked\0buttonAccept_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormCategoriesEdit[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   65,    2, 0x08,    3 /* Private */,
       5,    0,   66,    2, 0x08,    4 /* Private */,
       6,    0,   67,    2, 0x08,    5 /* Private */,
       7,    0,   68,    2, 0x08,    6 /* Private */,
       8,    2,   69,    2, 0x08,    7 /* Private */,
      12,    0,   74,    2, 0x08,   10 /* Private */,
      13,    0,   75,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 9, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormCategoriesEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormCategoriesEdit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_categoriesIsUpdated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->init(); break;
        case 2: _t->updateIcons(); break;
        case 3: _t->retranslate(); break;
        case 4: _t->achievementsToUi(); break;
        case 5: { int _r = _t->indexFromRow((*reinterpret_cast< QListWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->buttonCancel_Clicked(); break;
        case 7: _t->buttonAccept_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QListWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormCategoriesEdit::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCategoriesEdit::s_categoriesIsUpdated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FormCategoriesEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormCategoriesEdit.offsetsAndSize,
    qt_meta_data_FormCategoriesEdit,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormCategoriesEdit_t
, QtPrivate::TypeAndForceComplete<FormCategoriesEdit, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FormCategoriesEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormCategoriesEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormCategoriesEdit.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormCategoriesEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FormCategoriesEdit::s_categoriesIsUpdated(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
