/****************************************************************************
** Meta object code from reading C++ file 'formsettings.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/main/formsettings.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormSettings_t {
    const uint offsetsAndSize[12];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormSettings_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormSettings_t qt_meta_stringdata_FormSettings = {
    {
QT_MOC_LITERAL(0, 12), // "FormSettings"
QT_MOC_LITERAL(13, 11), // "retranslate"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 14), // "updateSettings"
QT_MOC_LITERAL(41, 23), // "QFlags<changedSettings>"
QT_MOC_LITERAL(65, 11) // "updateIcons"

    },
    "FormSettings\0retranslate\0\0updateSettings\0"
    "QFlags<changedSettings>\0updateIcons"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormSettings[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    1,   33,    2, 0x08,    2 /* Private */,
       5,    0,   36,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

       0        // eod
};

void FormSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormSettings *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->retranslate(); break;
        case 1: _t->updateSettings((*reinterpret_cast< QFlags<changedSettings>(*)>(_a[1]))); break;
        case 2: _t->updateIcons(); break;
        default: ;
        }
    }
}

const QMetaObject FormSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormSettings.offsetsAndSize,
    qt_meta_data_FormSettings,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormSettings_t
, QtPrivate::TypeAndForceComplete<FormSettings, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QFlags<changedSettings>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FormSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormSettings.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
