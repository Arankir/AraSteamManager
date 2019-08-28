/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[375];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "on_return"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "FormGames*"
QT_MOC_LITERAL(4, 33, 12), // "FormFriends*"
QT_MOC_LITERAL(5, 46, 14), // "FormStatistic*"
QT_MOC_LITERAL(6, 61, 16), // "on_go_to_profile"
QT_MOC_LITERAL(7, 78, 2), // "id"
QT_MOC_LITERAL(8, 81, 13), // "keyPressEvent"
QT_MOC_LITERAL(9, 95, 10), // "QKeyEvent*"
QT_MOC_LITERAL(10, 106, 5), // "event"
QT_MOC_LITERAL(11, 112, 39), // "on_FormProfileButtonFindProfi..."
QT_MOC_LITERAL(12, 152, 33), // "on_FormProfileButtonGames_cli..."
QT_MOC_LITERAL(13, 186, 35), // "on_FormProfileButtonFriends_c..."
QT_MOC_LITERAL(14, 222, 38), // "on_FormProfileButtonSetProfil..."
QT_MOC_LITERAL(15, 261, 32), // "on_FormProfileButtonExit_clicked"
QT_MOC_LITERAL(16, 294, 41), // "on_FormProfileButtonGoToMyPro..."
QT_MOC_LITERAL(17, 336, 38) // "on_FormProfileButtonStatistic..."

    },
    "MainWindow\0on_return\0\0FormGames*\0"
    "FormFriends*\0FormStatistic*\0"
    "on_go_to_profile\0id\0keyPressEvent\0"
    "QKeyEvent*\0event\0"
    "on_FormProfileButtonFindProfile_clicked\0"
    "on_FormProfileButtonGames_clicked\0"
    "on_FormProfileButtonFriends_clicked\0"
    "on_FormProfileButtonSetProfile_clicked\0"
    "on_FormProfileButtonExit_clicked\0"
    "on_FormProfileButtonGoToMyProfile_clicked\0"
    "on_FormProfileButtonStatistics_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       1,    1,   77,    2, 0x08 /* Private */,
       1,    1,   80,    2, 0x08 /* Private */,
       6,    1,   83,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_return((*reinterpret_cast< FormGames*(*)>(_a[1]))); break;
        case 1: _t->on_return((*reinterpret_cast< FormFriends*(*)>(_a[1]))); break;
        case 2: _t->on_return((*reinterpret_cast< FormStatistic*(*)>(_a[1]))); break;
        case 3: _t->on_go_to_profile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 5: _t->on_FormProfileButtonFindProfile_clicked(); break;
        case 6: _t->on_FormProfileButtonGames_clicked(); break;
        case 7: _t->on_FormProfileButtonFriends_clicked(); break;
        case 8: _t->on_FormProfileButtonSetProfile_clicked(); break;
        case 9: _t->on_FormProfileButtonExit_clicked(); break;
        case 10: _t->on_FormProfileButtonGoToMyProfile_clicked(); break;
        case 11: _t->on_FormProfileButtonStatistics_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FormGames* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FormFriends* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FormStatistic* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
