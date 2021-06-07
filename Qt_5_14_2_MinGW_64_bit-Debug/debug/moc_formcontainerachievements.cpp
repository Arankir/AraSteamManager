/****************************************************************************
** Meta object code from reading C++ file 'formcontainerachievements.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/formcontainerachievements.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcontainerachievements.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormContainerAchievements_t {
    QByteArrayData data[13];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormContainerAchievements_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormContainerAchievements_t qt_meta_stringdata_FormContainerAchievements = {
    {
QT_MOC_LITERAL(0, 0, 25), // "FormContainerAchievements"
QT_MOC_LITERAL(1, 26, 20), // "s_removeAchievements"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 5), // "index"
QT_MOC_LITERAL(4, 54, 18), // "addFormAchievement"
QT_MOC_LITERAL(5, 73, 8), // "SProfile"
QT_MOC_LITERAL(6, 82, 3), // "ids"
QT_MOC_LITERAL(7, 86, 6), // "SGame&"
QT_MOC_LITERAL(8, 93, 4), // "game"
QT_MOC_LITERAL(9, 98, 4), // "show"
QT_MOC_LITERAL(10, 103, 10), // "closeEvent"
QT_MOC_LITERAL(11, 114, 12), // "QCloseEvent*"
QT_MOC_LITERAL(12, 127, 42) // "on_TabWidgetAchievements_tabC..."

    },
    "FormContainerAchievements\0"
    "s_removeAchievements\0\0index\0"
    "addFormAchievement\0SProfile\0ids\0SGame&\0"
    "game\0show\0closeEvent\0QCloseEvent*\0"
    "on_TabWidgetAchievements_tabCloseRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormContainerAchievements[] = {

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
       4,    2,   42,    2, 0x0a /* Public */,
       9,    0,   47,    2, 0x0a /* Public */,
      10,    1,   48,    2, 0x08 /* Private */,
      12,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void FormContainerAchievements::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormContainerAchievements *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_removeAchievements((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addFormAchievement((*reinterpret_cast< SProfile(*)>(_a[1])),(*reinterpret_cast< SGame(*)>(_a[2]))); break;
        case 2: _t->show(); break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 4: _t->on_TabWidgetAchievements_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormContainerAchievements::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormContainerAchievements::s_removeAchievements)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormContainerAchievements::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormContainerAchievements.data,
    qt_meta_data_FormContainerAchievements,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormContainerAchievements::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormContainerAchievements::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormContainerAchievements.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormContainerAchievements::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FormContainerAchievements::s_removeAchievements(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
