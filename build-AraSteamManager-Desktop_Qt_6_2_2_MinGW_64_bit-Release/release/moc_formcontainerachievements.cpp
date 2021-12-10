/****************************************************************************
** Meta object code from reading C++ file 'formcontainerachievements.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/formcontainerachievements.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcontainerachievements.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormContainerAchievements_t {
    const uint offsetsAndSize[26];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormContainerAchievements_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormContainerAchievements_t qt_meta_stringdata_FormContainerAchievements = {
    {
QT_MOC_LITERAL(0, 25), // "FormContainerAchievements"
QT_MOC_LITERAL(26, 20), // "s_removeAchievements"
QT_MOC_LITERAL(47, 0), // ""
QT_MOC_LITERAL(48, 5), // "index"
QT_MOC_LITERAL(54, 18), // "addFormAchievement"
QT_MOC_LITERAL(73, 8), // "SProfile"
QT_MOC_LITERAL(82, 3), // "ids"
QT_MOC_LITERAL(86, 5), // "SGame"
QT_MOC_LITERAL(92, 4), // "game"
QT_MOC_LITERAL(97, 4), // "show"
QT_MOC_LITERAL(102, 10), // "closeEvent"
QT_MOC_LITERAL(113, 12), // "QCloseEvent*"
QT_MOC_LITERAL(126, 42) // "on_TabWidgetAchievements_tabC..."

    },
    "FormContainerAchievements\0"
    "s_removeAchievements\0\0index\0"
    "addFormAchievement\0SProfile\0ids\0SGame\0"
    "game\0show\0closeEvent\0QCloseEvent*\0"
    "on_TabWidgetAchievements_tabCloseRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormContainerAchievements[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   47,    2, 0x0a,    3 /* Public */,
       9,    0,   52,    2, 0x0a,    6 /* Public */,
      10,    1,   53,    2, 0x08,    7 /* Private */,
      12,    1,   56,    2, 0x08,    9 /* Private */,

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
        (void)_t;
        switch (_id) {
        case 0: _t->s_removeAchievements((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addFormAchievement((*reinterpret_cast< const SProfile(*)>(_a[1])),(*reinterpret_cast< const SGame(*)>(_a[2]))); break;
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

const QMetaObject FormContainerAchievements::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormContainerAchievements.offsetsAndSize,
    qt_meta_data_FormContainerAchievements,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormContainerAchievements_t
, QtPrivate::TypeAndForceComplete<FormContainerAchievements, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SProfile &, std::false_type>, QtPrivate::TypeAndForceComplete<const SGame &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
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
