/****************************************************************************
** Meta object code from reading C++ file 'multiselectcombobox.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/comboBoxes/multiselectcombobox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiselectcombobox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MultiSelectComboBox_t {
    const uint offsetsAndSize[12];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MultiSelectComboBox_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MultiSelectComboBox_t qt_meta_stringdata_MultiSelectComboBox = {
    {
QT_MOC_LITERAL(0, 19), // "MultiSelectComboBox"
QT_MOC_LITERAL(20, 16), // "selectionChanged"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 5), // "clear"
QT_MOC_LITERAL(44, 14), // "setCurrentText"
QT_MOC_LITERAL(59, 5) // "aText"

    },
    "MultiSelectComboBox\0selectionChanged\0"
    "\0clear\0setCurrentText\0aText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultiSelectComboBox[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   39,    2, 0x0a,    2 /* Public */,
       4,    1,   40,    2, 0x0a,    3 /* Public */,
       4,    1,   43,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QStringList,    5,

       0        // eod
};

void MultiSelectComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MultiSelectComboBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectionChanged(); break;
        case 1: _t->clear(); break;
        case 2: _t->setCurrentText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setCurrentText((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MultiSelectComboBox::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiSelectComboBox::selectionChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MultiSelectComboBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QComboBox::staticMetaObject>(),
    qt_meta_stringdata_MultiSelectComboBox.offsetsAndSize,
    qt_meta_data_MultiSelectComboBox,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MultiSelectComboBox_t
, QtPrivate::TypeAndForceComplete<MultiSelectComboBox, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>


>,
    nullptr
} };


const QMetaObject *MultiSelectComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultiSelectComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MultiSelectComboBox.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int MultiSelectComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MultiSelectComboBox::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
