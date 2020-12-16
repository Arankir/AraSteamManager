/****************************************************************************
** Meta object code from reading C++ file 'formgroups.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/formgroups.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formgroups.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormGroups_t {
    QByteArrayData data[18];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormGroups_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormGroups_t qt_meta_stringdata_FormGroups = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FormGroups"
QT_MOC_LITERAL(1, 11, 14), // "s_updateGroups"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "isUpdate"
QT_MOC_LITERAL(4, 36, 4), // "init"
QT_MOC_LITERAL(5, 41, 6), // "initUi"
QT_MOC_LITERAL(6, 48, 5), // "clear"
QT_MOC_LITERAL(7, 54, 8), // "updateUi"
QT_MOC_LITERAL(8, 63, 3), // "add"
QT_MOC_LITERAL(9, 67, 6), // "aTitle"
QT_MOC_LITERAL(10, 74, 11), // "changeTitle"
QT_MOC_LITERAL(11, 86, 6), // "aIndex"
QT_MOC_LITERAL(12, 93, 6), // "cancel"
QT_MOC_LITERAL(13, 100, 5), // "apply"
QT_MOC_LITERAL(14, 106, 11), // "add_clicked"
QT_MOC_LITERAL(15, 118, 19), // "changeTitle_clicked"
QT_MOC_LITERAL(16, 138, 14), // "cancel_clicked"
QT_MOC_LITERAL(17, 153, 13) // "apply_clicked"

    },
    "FormGroups\0s_updateGroups\0\0isUpdate\0"
    "init\0initUi\0clear\0updateUi\0add\0aTitle\0"
    "changeTitle\0aIndex\0cancel\0apply\0"
    "add_clicked\0changeTitle_clicked\0"
    "cancel_clicked\0apply_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormGroups[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
      10,    2,   89,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormGroups::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormGroups *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_updateGroups((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->init(); break;
        case 2: _t->initUi(); break;
        case 3: _t->clear(); break;
        case 4: _t->updateUi(); break;
        case 5: _t->add((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->changeTitle((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->cancel(); break;
        case 8: _t->apply(); break;
        case 9: _t->add_clicked(); break;
        case 10: _t->changeTitle_clicked(); break;
        case 11: _t->cancel_clicked(); break;
        case 12: _t->apply_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormGroups::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormGroups::s_updateGroups)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormGroups::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormGroups.data,
    qt_meta_data_FormGroups,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormGroups::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormGroups::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormGroups.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormGroups::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FormGroups::s_updateGroups(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
