/****************************************************************************
** Meta object code from reading C++ file 'qcomboboxfriends.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/comboBoxes/qcomboboxfriends.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcomboboxfriends.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ComboBoxFriends_t {
    const uint offsetsAndSize[12];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ComboBoxFriends_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ComboBoxFriends_t qt_meta_stringdata_ComboBoxFriends = {
    {
QT_MOC_LITERAL(0, 15), // "ComboBoxFriends"
QT_MOC_LITERAL(16, 18), // "s_selectionChanged"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 15), // "s_friendClicked"
QT_MOC_LITERAL(52, 8), // "SProfile"
QT_MOC_LITERAL(61, 5) // "clear"

    },
    "ComboBoxFriends\0s_selectionChanged\0\0"
    "s_friendClicked\0SProfile\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComboBoxFriends[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    1 /* Public */,
       3,    1,   33,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   36,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ComboBoxFriends::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ComboBoxFriends *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_selectionChanged(); break;
        case 1: _t->s_friendClicked((*reinterpret_cast< const SProfile(*)>(_a[1]))); break;
        case 2: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ComboBoxFriends::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComboBoxFriends::s_selectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ComboBoxFriends::*)(const SProfile & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComboBoxFriends::s_friendClicked)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ComboBoxFriends::staticMetaObject = { {
    QMetaObject::SuperData::link<QComboBox::staticMetaObject>(),
    qt_meta_stringdata_ComboBoxFriends.offsetsAndSize,
    qt_meta_data_ComboBoxFriends,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ComboBoxFriends_t
, QtPrivate::TypeAndForceComplete<ComboBoxFriends, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SProfile &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ComboBoxFriends::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComboBoxFriends::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ComboBoxFriends.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int ComboBoxFriends::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ComboBoxFriends::s_selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ComboBoxFriends::s_friendClicked(const SProfile & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
