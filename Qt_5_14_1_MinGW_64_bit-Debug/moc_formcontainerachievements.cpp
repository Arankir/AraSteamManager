/****************************************************************************
** Meta object code from reading C++ file 'formcontainerachievements.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AraSteamManager/formcontainerachievements.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formcontainerachievements.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormContainerAchievements_t {
    QByteArrayData data[17];
    char stringdata0[219];
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
QT_MOC_LITERAL(4, 54, 11), // "s_formClose"
QT_MOC_LITERAL(5, 66, 18), // "AddFormAchievement"
QT_MOC_LITERAL(6, 85, 19), // "SAchievementsPlayer"
QT_MOC_LITERAL(7, 105, 2), // "pl"
QT_MOC_LITERAL(8, 108, 3), // "ids"
QT_MOC_LITERAL(9, 112, 5), // "SGame"
QT_MOC_LITERAL(10, 118, 4), // "game"
QT_MOC_LITERAL(11, 123, 3), // "num"
QT_MOC_LITERAL(12, 127, 10), // "closeEvent"
QT_MOC_LITERAL(13, 138, 12), // "QCloseEvent*"
QT_MOC_LITERAL(14, 151, 42), // "on_TabWidgetAchievements_tabC..."
QT_MOC_LITERAL(15, 194, 11), // "OnLoadImage"
QT_MOC_LITERAL(16, 206, 12) // "RequestData*"

    },
    "FormContainerAchievements\0"
    "s_removeAchievements\0\0index\0s_formClose\0"
    "AddFormAchievement\0SAchievementsPlayer\0"
    "pl\0ids\0SGame\0game\0num\0closeEvent\0"
    "QCloseEvent*\0on_TabWidgetAchievements_tabCloseRequested\0"
    "OnLoadImage\0RequestData*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormContainerAchievements[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    4,   48,    2, 0x0a /* Public */,
      12,    1,   57,    2, 0x08 /* Private */,
      14,    1,   60,    2, 0x08 /* Private */,
      15,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString, 0x80000000 | 9, QMetaType::Int,    7,    8,   10,   11,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 16,    2,

       0        // eod
};

void FormContainerAchievements::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormContainerAchievements *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_removeAchievements((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->s_formClose(); break;
        case 2: _t->AddFormAchievement((*reinterpret_cast< SAchievementsPlayer(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< SGame(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 4: _t->on_TabWidgetAchievements_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->OnLoadImage((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RequestData* >(); break;
            }
            break;
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
        {
            using _t = void (FormContainerAchievements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormContainerAchievements::s_formClose)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormContainerAchievements::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
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
    return QWidget::qt_metacast(_clname);
}

int FormContainerAchievements::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FormContainerAchievements::s_removeAchievements(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormContainerAchievements::s_formClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
