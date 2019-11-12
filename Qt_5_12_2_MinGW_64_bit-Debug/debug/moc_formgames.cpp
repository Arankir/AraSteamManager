/****************************************************************************
** Meta object code from reading C++ file 'formgames.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/formgames.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formgames.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormGames_t {
    QByteArrayData data[21];
    char stringdata0[295];
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
QT_MOC_LITERAL(3, 29, 15), // "ProgressLoading"
QT_MOC_LITERAL(4, 45, 8), // "ImageSet"
QT_MOC_LITERAL(5, 54, 3), // "pix"
QT_MOC_LITERAL(6, 58, 3), // "row"
QT_MOC_LITERAL(7, 62, 13), // "OnResultImage"
QT_MOC_LITERAL(8, 76, 13), // "ImageRequest*"
QT_MOC_LITERAL(9, 90, 4), // "imgr"
QT_MOC_LITERAL(10, 95, 20), // "OnResultAchievements"
QT_MOC_LITERAL(11, 116, 10), // "closeEvent"
QT_MOC_LITERAL(12, 127, 12), // "QCloseEvent*"
QT_MOC_LITERAL(13, 140, 5), // "event"
QT_MOC_LITERAL(14, 146, 14), // "InitComponents"
QT_MOC_LITERAL(15, 161, 23), // "on_ButtonReturn_clicked"
QT_MOC_LITERAL(16, 185, 19), // "AchievementsClicked"
QT_MOC_LITERAL(17, 205, 16), // "FavoritesClicked"
QT_MOC_LITERAL(18, 222, 22), // "returnfromachievements"
QT_MOC_LITERAL(19, 245, 27), // "on_LineEditGame_textChanged"
QT_MOC_LITERAL(20, 273, 21) // "on_ButtonFind_clicked"

    },
    "FormGames\0return_to_profile\0\0"
    "ProgressLoading\0ImageSet\0pix\0row\0"
    "OnResultImage\0ImageRequest*\0imgr\0"
    "OnResultAchievements\0closeEvent\0"
    "QCloseEvent*\0event\0InitComponents\0"
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
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   80,    2, 0x0a /* Public */,
       4,    2,   85,    2, 0x0a /* Public */,
       7,    1,   90,    2, 0x08 /* Private */,
      10,    1,   93,    2, 0x08 /* Private */,
      11,    1,   96,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,
      19,    1,  104,    2, 0x08 /* Private */,
      20,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QPixmap, QMetaType::Int,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
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
        case 1: _t->ProgressLoading((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ImageSet((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->OnResultImage((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        case 4: _t->OnResultAchievements((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        case 5: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 6: _t->InitComponents(); break;
        case 7: _t->on_ButtonReturn_clicked(); break;
        case 8: _t->AchievementsClicked(); break;
        case 9: _t->FavoritesClicked(); break;
        case 10: _t->returnfromachievements(); break;
        case 11: _t->on_LineEditGame_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_ButtonFind_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageRequest* >(); break;
            }
            break;
        case 4:
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
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
