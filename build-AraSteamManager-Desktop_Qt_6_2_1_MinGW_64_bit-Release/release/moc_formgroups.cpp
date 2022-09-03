/****************************************************************************
** Meta object code from reading C++ file 'formgroups.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/formgroups.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formgroups.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormGroups_t {
    const uint offsetsAndSize[36];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormGroups_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormGroups_t qt_meta_stringdata_FormGroups = {
    {
QT_MOC_LITERAL(0, 10), // "FormGroups"
QT_MOC_LITERAL(11, 14), // "s_updateGroups"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 4), // "init"
QT_MOC_LITERAL(32, 10), // "createMenu"
QT_MOC_LITERAL(43, 6), // "QMenu*"
QT_MOC_LITERAL(50, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(67, 5), // "aItem"
QT_MOC_LITERAL(73, 11), // "removeGroup"
QT_MOC_LITERAL(85, 6), // "initUi"
QT_MOC_LITERAL(92, 5), // "clear"
QT_MOC_LITERAL(98, 8), // "updateUi"
QT_MOC_LITERAL(107, 6), // "cancel"
QT_MOC_LITERAL(114, 5), // "apply"
QT_MOC_LITERAL(120, 13), // "cancelClicked"
QT_MOC_LITERAL(134, 12), // "applyClicked"
QT_MOC_LITERAL(147, 11), // "retranslate"
QT_MOC_LITERAL(159, 11) // "updateIcons"

    },
    "FormGroups\0s_updateGroups\0\0init\0"
    "createMenu\0QMenu*\0QListWidgetItem*\0"
    "aItem\0removeGroup\0initUi\0clear\0updateUi\0"
    "cancel\0apply\0cancelClicked\0applyClicked\0"
    "retranslate\0updateIcons"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormGroups[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   93,    2, 0x09,    2 /* Protected */,
       4,    1,   94,    2, 0x09,    3 /* Protected */,
       8,    1,   97,    2, 0x09,    5 /* Protected */,
       9,    0,  100,    2, 0x09,    7 /* Protected */,
      10,    0,  101,    2, 0x09,    8 /* Protected */,
      11,    0,  102,    2, 0x09,    9 /* Protected */,
      12,    0,  103,    2, 0x09,   10 /* Protected */,
      13,    0,  104,    2, 0x09,   11 /* Protected */,
      14,    0,  105,    2, 0x09,   12 /* Protected */,
      15,    0,  106,    2, 0x09,   13 /* Protected */,
      16,    0,  107,    2, 0x09,   14 /* Protected */,
      17,    0,  108,    2, 0x09,   15 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 5, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        (void)_t;
        switch (_id) {
        case 0: _t->s_updateGroups(); break;
        case 1: _t->init(); break;
        case 2: { QMenu* _r = _t->createMenu((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 3: _t->removeGroup((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->initUi(); break;
        case 5: _t->clear(); break;
        case 6: _t->updateUi(); break;
        case 7: _t->cancel(); break;
        case 8: _t->apply(); break;
        case 9: _t->cancelClicked(); break;
        case 10: _t->applyClicked(); break;
        case 11: _t->retranslate(); break;
        case 12: _t->updateIcons(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormGroups::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormGroups::s_updateGroups)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FormGroups::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormGroups.offsetsAndSize,
    qt_meta_data_FormGroups,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormGroups_t
, QtPrivate::TypeAndForceComplete<FormGroups, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
    return Form::qt_metacast(_clname);
}

int FormGroups::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FormGroups::s_updateGroups()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
