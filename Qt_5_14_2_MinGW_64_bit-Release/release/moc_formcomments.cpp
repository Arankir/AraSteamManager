/****************************************************************************
** Meta object code from reading C++ file 'formcomments.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/formcomments.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcomments.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormComments_t {
    QByteArrayData data[11];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormComments_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormComments_t qt_meta_stringdata_FormComments = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FormComments"
QT_MOC_LITERAL(1, 13, 16), // "s_updateComments"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "s_closed"
QT_MOC_LITERAL(4, 40, 4), // "init"
QT_MOC_LITERAL(5, 45, 23), // "on_ButtonCancel_clicked"
QT_MOC_LITERAL(6, 69, 22), // "on_ButtonApply_clicked"
QT_MOC_LITERAL(7, 92, 5), // "close"
QT_MOC_LITERAL(8, 98, 11), // "retranslate"
QT_MOC_LITERAL(9, 110, 11), // "updateIcons"
QT_MOC_LITERAL(10, 122, 14) // "updateSettings"

    },
    "FormComments\0s_updateComments\0\0s_closed\0"
    "init\0on_ButtonCancel_clicked\0"
    "on_ButtonApply_clicked\0close\0retranslate\0"
    "updateIcons\0updateSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormComments[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormComments::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormComments *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_updateComments(); break;
        case 1: _t->s_closed(); break;
        case 2: _t->init(); break;
        case 3: _t->on_ButtonCancel_clicked(); break;
        case 4: _t->on_ButtonApply_clicked(); break;
        case 5: _t->close(); break;
        case 6: _t->retranslate(); break;
        case 7: _t->updateIcons(); break;
        case 8: _t->updateSettings(); break;
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
        {
            using _t = void (FormComments::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormComments::s_closed)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FormComments::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormComments.data,
    qt_meta_data_FormComments,
    qt_static_metacall,
    nullptr,
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void FormComments::s_updateComments()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormComments::s_closed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
