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
    QByteArrayData data[17];
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
QT_MOC_LITERAL(4, 43, 1), // "i"
QT_MOC_LITERAL(5, 45, 4), // "Save"
QT_MOC_LITERAL(6, 50, 13), // "ImageRequest*"
QT_MOC_LITERAL(7, 64, 4), // "imgr"
QT_MOC_LITERAL(8, 69, 10), // "closeEvent"
QT_MOC_LITERAL(9, 80, 12), // "QCloseEvent*"
QT_MOC_LITERAL(10, 93, 5), // "event"
QT_MOC_LITERAL(11, 99, 32), // "on_FormGamesButtonReturn_clicked"
QT_MOC_LITERAL(12, 132, 19), // "AchievementsClicked"
QT_MOC_LITERAL(13, 152, 16), // "FavoritesClicked"
QT_MOC_LITERAL(14, 169, 9), // "on_return"
QT_MOC_LITERAL(15, 179, 36), // "on_FormGamesLineEditGame_text..."
QT_MOC_LITERAL(16, 216, 30) // "on_FormGamesButtonFind_clicked"

    },
    "FormGames\0return_to_profile\0\0OnResultImage\0"
    "i\0Save\0ImageRequest*\0imgr\0closeEvent\0"
    "QCloseEvent*\0event\0on_FormGamesButtonReturn_clicked\0"
    "AchievementsClicked\0FavoritesClicked\0"
    "on_return\0on_FormGamesLineEditGame_textChanged\0"
    "on_FormGamesButtonFind_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormGames[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   60,    2, 0x08 /* Private */,
       8,    1,   67,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,
      13,    0,   72,    2, 0x08 /* Private */,
      14,    0,   73,    2, 0x08 /* Private */,
      15,    1,   74,    2, 0x08 /* Private */,
      16,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
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
        case 1: _t->OnResultImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ImageRequest*(*)>(_a[3]))); break;
        case 2: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: _t->on_FormGamesButtonReturn_clicked(); break;
        case 4: _t->AchievementsClicked(); break;
        case 5: _t->FavoritesClicked(); break;
        case 6: _t->on_return(); break;
        case 7: _t->on_FormGamesLineEditGame_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_FormGamesButtonFind_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
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
