/****************************************************************************
** Meta object code from reading C++ file 'formreachedfilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/subForms/achievements/widgets/formreachedfilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formreachedfilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormReachedFilter_t {
    QByteArrayData data[9];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormReachedFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormReachedFilter_t qt_meta_stringdata_FormReachedFilter = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FormReachedFilter"
QT_MOC_LITERAL(1, 18, 19), // "s_radioButtonChange"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 11), // "ReachedType"
QT_MOC_LITERAL(4, 51, 4), // "type"
QT_MOC_LITERAL(5, 56, 14), // "updateSettings"
QT_MOC_LITERAL(6, 71, 11), // "updateIcons"
QT_MOC_LITERAL(7, 83, 11), // "retranslate"
QT_MOC_LITERAL(8, 95, 17) // "slideValueChanged"

    },
    "FormReachedFilter\0s_radioButtonChange\0"
    "\0ReachedType\0type\0updateSettings\0"
    "updateIcons\0retranslate\0slideValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormReachedFilter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormReachedFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormReachedFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_radioButtonChange((*reinterpret_cast< const ReachedType(*)>(_a[1]))); break;
        case 1: _t->updateSettings(); break;
        case 2: _t->updateIcons(); break;
        case 3: _t->retranslate(); break;
        case 4: _t->slideValueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormReachedFilter::*)(const ReachedType & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormReachedFilter::s_radioButtonChange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormReachedFilter::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormReachedFilter.data,
    qt_meta_data_FormReachedFilter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormReachedFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormReachedFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormReachedFilter.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormReachedFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FormReachedFilter::s_radioButtonChange(const ReachedType & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
