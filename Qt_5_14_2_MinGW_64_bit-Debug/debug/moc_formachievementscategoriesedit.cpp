/****************************************************************************
** Meta object code from reading C++ file 'formachievementscategoriesedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/AchievementsSubForms/formachievementscategoriesedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formachievementscategoriesedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormAchievementsCategoriesEdit_t {
    QByteArrayData data[18];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormAchievementsCategoriesEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormAchievementsCategoriesEdit_t qt_meta_stringdata_FormAchievementsCategoriesEdit = {
    {
QT_MOC_LITERAL(0, 0, 30), // "FormAchievementsCategoriesEdit"
QT_MOC_LITERAL(1, 31, 21), // "s_categoriesIsUpdated"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 9), // "isUpdated"
QT_MOC_LITERAL(4, 64, 16), // "s_updateSettings"
QT_MOC_LITERAL(5, 81, 18), // "changeCategoryType"
QT_MOC_LITERAL(6, 100, 12), // "CategoryType"
QT_MOC_LITERAL(7, 113, 4), // "type"
QT_MOC_LITERAL(8, 118, 25), // "buttonAddCategory_Clicked"
QT_MOC_LITERAL(9, 144, 33), // "buttonDeleteAllCategories_Cli..."
QT_MOC_LITERAL(10, 178, 28), // "buttonCancelCategory_Clicked"
QT_MOC_LITERAL(11, 207, 28), // "buttonAcceptCategory_Clicked"
QT_MOC_LITERAL(12, 236, 28), // "buttonDeleteCategory_Clicked"
QT_MOC_LITERAL(13, 265, 33), // "lineEditTitleCategory_TextCha..."
QT_MOC_LITERAL(14, 299, 4), // "arg1"
QT_MOC_LITERAL(15, 304, 8), // "setIcons"
QT_MOC_LITERAL(16, 313, 24), // "updateUniqueAchievements"
QT_MOC_LITERAL(17, 338, 4) // "init"

    },
    "FormAchievementsCategoriesEdit\0"
    "s_categoriesIsUpdated\0\0isUpdated\0"
    "s_updateSettings\0changeCategoryType\0"
    "CategoryType\0type\0buttonAddCategory_Clicked\0"
    "buttonDeleteAllCategories_Clicked\0"
    "buttonCancelCategory_Clicked\0"
    "buttonAcceptCategory_Clicked\0"
    "buttonDeleteCategory_Clicked\0"
    "lineEditTitleCategory_TextChanged\0"
    "arg1\0setIcons\0updateUniqueAchievements\0"
    "init"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormAchievementsCategoriesEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   78,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    1,   86,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormAchievementsCategoriesEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormAchievementsCategoriesEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_categoriesIsUpdated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->s_updateSettings(); break;
        case 2: _t->changeCategoryType((*reinterpret_cast< CategoryType(*)>(_a[1]))); break;
        case 3: _t->buttonAddCategory_Clicked(); break;
        case 4: _t->buttonDeleteAllCategories_Clicked(); break;
        case 5: _t->buttonCancelCategory_Clicked(); break;
        case 6: _t->buttonAcceptCategory_Clicked(); break;
        case 7: _t->buttonDeleteCategory_Clicked(); break;
        case 8: _t->lineEditTitleCategory_TextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setIcons(); break;
        case 10: _t->updateUniqueAchievements(); break;
        case 11: _t->init(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormAchievementsCategoriesEdit::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAchievementsCategoriesEdit::s_categoriesIsUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormAchievementsCategoriesEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAchievementsCategoriesEdit::s_updateSettings)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormAchievementsCategoriesEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormAchievementsCategoriesEdit.data,
    qt_meta_data_FormAchievementsCategoriesEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormAchievementsCategoriesEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormAchievementsCategoriesEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormAchievementsCategoriesEdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormAchievementsCategoriesEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FormAchievementsCategoriesEdit::s_categoriesIsUpdated(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormAchievementsCategoriesEdit::s_updateSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
