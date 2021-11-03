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
    const uint offsetsAndSize[44];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormGroups_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormGroups_t qt_meta_stringdata_FormGroups = {
    {
QT_MOC_LITERAL(0, 10), // "FormGroups"
QT_MOC_LITERAL(11, 14), // "s_updateGroups"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 14), // "setProfileGame"
QT_MOC_LITERAL(42, 6), // "initUi"
QT_MOC_LITERAL(49, 5), // "clear"
QT_MOC_LITERAL(55, 8), // "updateUi"
QT_MOC_LITERAL(64, 3), // "add"
QT_MOC_LITERAL(68, 6), // "aTitle"
QT_MOC_LITERAL(75, 11), // "changeTitle"
QT_MOC_LITERAL(87, 6), // "aIndex"
QT_MOC_LITERAL(94, 6), // "cancel"
QT_MOC_LITERAL(101, 5), // "apply"
QT_MOC_LITERAL(107, 11), // "add_clicked"
QT_MOC_LITERAL(119, 19), // "changeTitle_clicked"
QT_MOC_LITERAL(139, 14), // "cancel_clicked"
QT_MOC_LITERAL(154, 13), // "apply_clicked"
QT_MOC_LITERAL(168, 11), // "retranslate"
QT_MOC_LITERAL(180, 11), // "updateIcons"
QT_MOC_LITERAL(192, 14), // "updateSettings"
QT_MOC_LITERAL(207, 23), // "QFlags<changedSettings>"
QT_MOC_LITERAL(231, 9) // "aSettings"

    },
    "FormGroups\0s_updateGroups\0\0setProfileGame\0"
    "initUi\0clear\0updateUi\0add\0aTitle\0"
    "changeTitle\0aIndex\0cancel\0apply\0"
    "add_clicked\0changeTitle_clicked\0"
    "cancel_clicked\0apply_clicked\0retranslate\0"
    "updateIcons\0updateSettings\0"
    "QFlags<changedSettings>\0aSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormGroups[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  111,    2, 0x08,    2 /* Private */,
       4,    0,  112,    2, 0x08,    3 /* Private */,
       5,    0,  113,    2, 0x08,    4 /* Private */,
       6,    0,  114,    2, 0x08,    5 /* Private */,
       7,    1,  115,    2, 0x08,    6 /* Private */,
       9,    2,  118,    2, 0x08,    8 /* Private */,
      11,    0,  123,    2, 0x08,   11 /* Private */,
      12,    0,  124,    2, 0x08,   12 /* Private */,
      13,    0,  125,    2, 0x08,   13 /* Private */,
      14,    0,  126,    2, 0x08,   14 /* Private */,
      15,    0,  127,    2, 0x08,   15 /* Private */,
      16,    0,  128,    2, 0x08,   16 /* Private */,
      17,    0,  129,    2, 0x08,   17 /* Private */,
      18,    0,  130,    2, 0x08,   18 /* Private */,
      19,    1,  131,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   10,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void FormGroups::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormGroups *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_updateGroups(); break;
        case 1: _t->setProfileGame(); break;
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
        case 13: _t->retranslate(); break;
        case 14: _t->updateIcons(); break;
        case 15: _t->updateSettings((*reinterpret_cast< QFlags<changedSettings>(*)>(_a[1]))); break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QFlags<changedSettings>, std::false_type>


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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
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
