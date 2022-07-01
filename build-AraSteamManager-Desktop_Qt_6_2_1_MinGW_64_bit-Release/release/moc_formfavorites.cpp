/****************************************************************************
** Meta object code from reading C++ file 'formfavorites.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/main/formfavorites.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formfavorites.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormFavorites_t {
    const uint offsetsAndSize[30];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormFavorites_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormFavorites_t qt_meta_stringdata_FormFavorites = {
    {
QT_MOC_LITERAL(0, 13), // "FormFavorites"
QT_MOC_LITERAL(14, 19), // "s_return_to_profile"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 8), // "QWidget*"
QT_MOC_LITERAL(44, 4), // "init"
QT_MOC_LITERAL(49, 6), // "isInit"
QT_MOC_LITERAL(56, 8), // "isLoaded"
QT_MOC_LITERAL(65, 10), // "friendLoad"
QT_MOC_LITERAL(76, 8), // "SProfile"
QT_MOC_LITERAL(85, 14), // "updateSettings"
QT_MOC_LITERAL(100, 23), // "QFlags<changedSettings>"
QT_MOC_LITERAL(124, 9), // "aSettings"
QT_MOC_LITERAL(134, 11), // "updateIcons"
QT_MOC_LITERAL(146, 11), // "retranslate"
QT_MOC_LITERAL(158, 21) // "on_pushButton_clicked"

    },
    "FormFavorites\0s_return_to_profile\0\0"
    "QWidget*\0init\0isInit\0isLoaded\0friendLoad\0"
    "SProfile\0updateSettings\0QFlags<changedSettings>\0"
    "aSettings\0updateIcons\0retranslate\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormFavorites[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   71,    2, 0x0a,    3 /* Public */,
       5,    0,   72,    2, 0x0a,    4 /* Public */,
       6,    0,   73,    2, 0x0a,    5 /* Public */,
       7,    1,   74,    2, 0x0a,    6 /* Public */,
       9,    1,   77,    2, 0x0a,    8 /* Public */,
      12,    0,   80,    2, 0x0a,   10 /* Public */,
      13,    0,   81,    2, 0x0a,   11 /* Public */,
      14,    0,   82,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormFavorites::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormFavorites *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_return_to_profile((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->init(); break;
        case 2: { bool _r = _t->isInit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->isLoaded();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->friendLoad((*reinterpret_cast< const SProfile(*)>(_a[1]))); break;
        case 5: _t->updateSettings((*reinterpret_cast< QFlags<changedSettings>(*)>(_a[1]))); break;
        case 6: _t->updateIcons(); break;
        case 7: _t->retranslate(); break;
        case 8: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormFavorites::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFavorites::s_return_to_profile)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FormFavorites::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormFavorites.offsetsAndSize,
    qt_meta_data_FormFavorites,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormFavorites_t
, QtPrivate::TypeAndForceComplete<FormFavorites, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SProfile &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QFlags<changedSettings>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FormFavorites::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormFavorites::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormFavorites.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormFavorites::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void FormFavorites::s_return_to_profile(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
