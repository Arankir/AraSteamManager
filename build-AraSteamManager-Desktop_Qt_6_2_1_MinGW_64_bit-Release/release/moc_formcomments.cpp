/****************************************************************************
** Meta object code from reading C++ file 'formcomments.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/formcomments.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcomments.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormComments_t {
    const uint offsetsAndSize[22];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormComments_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormComments_t qt_meta_stringdata_FormComments = {
    {
QT_MOC_LITERAL(0, 12), // "FormComments"
QT_MOC_LITERAL(13, 16), // "s_updateComments"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 4), // "init"
QT_MOC_LITERAL(36, 23), // "on_ButtonCancel_clicked"
QT_MOC_LITERAL(60, 22), // "on_ButtonApply_clicked"
QT_MOC_LITERAL(83, 11), // "retranslate"
QT_MOC_LITERAL(95, 11), // "updateIcons"
QT_MOC_LITERAL(107, 14), // "updateSettings"
QT_MOC_LITERAL(122, 23), // "QFlags<changedSettings>"
QT_MOC_LITERAL(146, 9) // "aSettings"

    },
    "FormComments\0s_updateComments\0\0init\0"
    "on_ButtonCancel_clicked\0on_ButtonApply_clicked\0"
    "retranslate\0updateIcons\0updateSettings\0"
    "QFlags<changedSettings>\0aSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormComments[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    1,   62,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void FormComments::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormComments *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_updateComments(); break;
        case 1: _t->init(); break;
        case 2: _t->on_ButtonCancel_clicked(); break;
        case 3: _t->on_ButtonApply_clicked(); break;
        case 4: _t->retranslate(); break;
        case 5: _t->updateIcons(); break;
        case 6: _t->updateSettings((*reinterpret_cast< QFlags<changedSettings>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormComments::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormComments::s_updateComments)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FormComments::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormComments.offsetsAndSize,
    qt_meta_data_FormComments,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormComments_t
, QtPrivate::TypeAndForceComplete<FormComments, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QFlags<changedSettings>, std::false_type>


>,
    nullptr
} };


const QMetaObject *FormComments::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormComments::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormComments.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormComments::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void FormComments::s_updateComments()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
