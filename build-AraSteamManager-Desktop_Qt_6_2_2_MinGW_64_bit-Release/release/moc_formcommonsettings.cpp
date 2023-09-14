/****************************************************************************
** Meta object code from reading C++ file 'formcommonsettings.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/main/settings/formcommonsettings.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcommonsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormCommonSettings_t {
    const uint offsetsAndSize[24];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormCommonSettings_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormCommonSettings_t qt_meta_stringdata_FormCommonSettings = {
    {
QT_MOC_LITERAL(0, 18), // "FormCommonSettings"
QT_MOC_LITERAL(19, 4), // "init"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 11), // "retranslate"
QT_MOC_LITERAL(37, 14), // "updateSettings"
QT_MOC_LITERAL(52, 23), // "QFlags<changedSettings>"
QT_MOC_LITERAL(76, 11), // "updateIcons"
QT_MOC_LITERAL(88, 29), // "slideProfileSize_ValueChanged"
QT_MOC_LITERAL(118, 5), // "value"
QT_MOC_LITERAL(124, 25), // "comboBoxThemeIndexChanged"
QT_MOC_LITERAL(150, 5), // "index"
QT_MOC_LITERAL(156, 28) // "comboBoxLanguageIndexChanged"

    },
    "FormCommonSettings\0init\0\0retranslate\0"
    "updateSettings\0QFlags<changedSettings>\0"
    "updateIcons\0slideProfileSize_ValueChanged\0"
    "value\0comboBoxThemeIndexChanged\0index\0"
    "comboBoxLanguageIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormCommonSettings[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    1,   58,    2, 0x08,    3 /* Private */,
       6,    0,   61,    2, 0x08,    5 /* Private */,
       7,    1,   62,    2, 0x08,    6 /* Private */,
       9,    1,   65,    2, 0x08,    8 /* Private */,
      11,    1,   68,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void FormCommonSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormCommonSettings *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->init(); break;
        case 1: _t->retranslate(); break;
        case 2: _t->updateSettings((*reinterpret_cast< QFlags<changedSettings>(*)>(_a[1]))); break;
        case 3: _t->updateIcons(); break;
        case 4: _t->slideProfileSize_ValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->comboBoxThemeIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->comboBoxLanguageIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FormCommonSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormCommonSettings.offsetsAndSize,
    qt_meta_data_FormCommonSettings,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormCommonSettings_t
, QtPrivate::TypeAndForceComplete<FormCommonSettings, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QFlags<changedSettings>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *FormCommonSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormCommonSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormCommonSettings.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormCommonSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
