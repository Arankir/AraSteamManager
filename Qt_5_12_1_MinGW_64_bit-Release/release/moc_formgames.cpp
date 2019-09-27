/****************************************************************************
** Meta object code from reading C++ file 'formgames.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/formgames.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formgames.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormGames_t {
    QByteArrayData data[16];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormGames_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormGames_t qt_meta_stringdata_FormGames = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FormGames"
QT_MOC_LITERAL(1, 10, 17), // "return_to_profile"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "OnResultImage"
QT_MOC_LITERAL(4, 43, 13), // "ImageRequest*"
QT_MOC_LITERAL(5, 57, 4), // "imgr"
QT_MOC_LITERAL(6, 62, 20), // "OnResultAchievements"
QT_MOC_LITERAL(7, 83, 10), // "closeEvent"
QT_MOC_LITERAL(8, 94, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 107, 5), // "event"
QT_MOC_LITERAL(10, 113, 23), // "on_ButtonReturn_clicked"
QT_MOC_LITERAL(11, 137, 19), // "AchievementsClicked"
QT_MOC_LITERAL(12, 157, 16), // "FavoritesClicked"
QT_MOC_LITERAL(13, 174, 22), // "returnfromachievements"
QT_MOC_LITERAL(14, 197, 27), // "on_LineEditGame_textChanged"
QT_MOC_LITERAL(15, 225, 21) // "on_ButtonFind_clicked"

    },
    "FormGames\0return_to_profile\0\0OnResultImage\0"
    "ImageRequest*\0imgr\0OnResultAchievements\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_ButtonReturn_clicked\0AchievementsClicked\0"
    "FavoritesClicked\0returnfromachievements\0"
    "on_LineEditGame_textChanged\0"
    "on_ButtonFind_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormGames[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   65,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,
      14,    1,   78,    2, 0x08 /* Private */,
      15,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void FormGames::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormGames *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_to_profile(); break;
        case 1: _t->OnResultImage((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        case 2: _t->OnResultAchievements((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 4: _t->on_ButtonReturn_clicked(); break;
        case 5: _t->AchievementsClicked(); break;
        case 6: _t->FavoritesClicked(); break;
        case 7: _t->returnfromachievements(); break;
        case 8: _t->on_LineEditGame_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_ButtonFind_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageRequest* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageRequest* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormGames::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormGames::return_to_profile)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormGames::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FormGames.data,
    qt_meta_data_FormGames,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormGames::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormGames::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormGames.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormGames::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FormGames::return_to_profile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
