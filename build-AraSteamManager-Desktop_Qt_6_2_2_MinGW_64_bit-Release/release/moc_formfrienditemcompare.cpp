/****************************************************************************
** Meta object code from reading C++ file 'formfrienditemcompare.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/widgets/formfrienditemcompare.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formfrienditemcompare.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormFriendItemCompare_t {
    const uint offsetsAndSize[16];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormFriendItemCompare_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormFriendItemCompare_t qt_meta_stringdata_FormFriendItemCompare = {
    {
QT_MOC_LITERAL(0, 21), // "FormFriendItemCompare"
QT_MOC_LITERAL(22, 8), // "s_delete"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 15), // "s_filterChanged"
QT_MOC_LITERAL(48, 9), // "SProfile*"
QT_MOC_LITERAL(58, 7), // "profile"
QT_MOC_LITERAL(66, 11), // "ReachedType"
QT_MOC_LITERAL(78, 4) // "type"

    },
    "FormFriendItemCompare\0s_delete\0\0"
    "s_filterChanged\0SProfile*\0profile\0"
    "ReachedType\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormFriendItemCompare[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,
       3,    2,   27,    2, 0x06,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,

       0        // eod
};

void FormFriendItemCompare::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormFriendItemCompare *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_delete(); break;
        case 1: _t->s_filterChanged((*reinterpret_cast< SProfile*(*)>(_a[1])),(*reinterpret_cast< const ReachedType(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< SProfile* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormFriendItemCompare::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFriendItemCompare::s_delete)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormFriendItemCompare::*)(SProfile * , const ReachedType & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFriendItemCompare::s_filterChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FormFriendItemCompare::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormFriendItemCompare.offsetsAndSize,
    qt_meta_data_FormFriendItemCompare,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormFriendItemCompare_t
, QtPrivate::TypeAndForceComplete<FormFriendItemCompare, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SProfile *, std::false_type>, QtPrivate::TypeAndForceComplete<const ReachedType &, std::false_type>



>,
    nullptr
} };


const QMetaObject *FormFriendItemCompare::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormFriendItemCompare::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormFriendItemCompare.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormFriendItemCompare::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void FormFriendItemCompare::s_delete()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormFriendItemCompare::s_filterChanged(SProfile * _t1, const ReachedType & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
