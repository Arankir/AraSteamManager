/****************************************************************************
** Meta object code from reading C++ file 'formcompareprofilefilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/AchievementsSubForms/formcompareprofilefilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcompareprofilefilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormCompareProfileFilter_t {
    QByteArrayData data[12];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormCompareProfileFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormCompareProfileFilter_t qt_meta_stringdata_FormCompareProfileFilter = {
    {
QT_MOC_LITERAL(0, 0, 24), // "FormCompareProfileFilter"
QT_MOC_LITERAL(1, 25, 19), // "s_radioButtonChange"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 4), // "name"
QT_MOC_LITERAL(4, 51, 11), // "ReachedType"
QT_MOC_LITERAL(5, 63, 4), // "type"
QT_MOC_LITERAL(6, 68, 14), // "updateSettings"
QT_MOC_LITERAL(7, 83, 8), // "setIcons"
QT_MOC_LITERAL(8, 92, 11), // "changeEvent"
QT_MOC_LITERAL(9, 104, 7), // "QEvent*"
QT_MOC_LITERAL(10, 112, 5), // "event"
QT_MOC_LITERAL(11, 118, 17) // "slideValueChanged"

    },
    "FormCompareProfileFilter\0s_radioButtonChange\0"
    "\0name\0ReachedType\0type\0updateSettings\0"
    "setIcons\0changeEvent\0QEvent*\0event\0"
    "slideValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormCompareProfileFilter[] = {

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
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,
       8,    1,   46,    2, 0x08 /* Private */,
      11,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void FormCompareProfileFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormCompareProfileFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_radioButtonChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ReachedType(*)>(_a[2]))); break;
        case 1: _t->updateSettings(); break;
        case 2: _t->setIcons(); break;
        case 3: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 4: _t->slideValueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormCompareProfileFilter::*)(const QString & , ReachedType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormCompareProfileFilter::s_radioButtonChange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormCompareProfileFilter::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormCompareProfileFilter.data,
    qt_meta_data_FormCompareProfileFilter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormCompareProfileFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormCompareProfileFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormCompareProfileFilter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormCompareProfileFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void FormCompareProfileFilter::s_radioButtonChange(const QString & _t1, ReachedType _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
