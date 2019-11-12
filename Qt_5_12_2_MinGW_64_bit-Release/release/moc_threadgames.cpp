/****************************************************************************
** Meta object code from reading C++ file 'threadgames.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/class/Threads/threadgames.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadgames.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadGames_t {
    QByteArrayData data[17];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadGames_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadGames_t qt_meta_stringdata_ThreadGames = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ThreadGames"
QT_MOC_LITERAL(1, 12, 8), // "finished"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "progress"
QT_MOC_LITERAL(4, 31, 1), // "p"
QT_MOC_LITERAL(5, 33, 4), // "Fill"
QT_MOC_LITERAL(6, 38, 3), // "Set"
QT_MOC_LITERAL(7, 42, 13), // "QTableWidget*"
QT_MOC_LITERAL(8, 56, 16), // "TableWidgetGames"
QT_MOC_LITERAL(9, 73, 14), // "QVector<SGame>"
QT_MOC_LITERAL(10, 88, 5), // "games"
QT_MOC_LITERAL(11, 94, 3), // "key"
QT_MOC_LITERAL(12, 98, 8), // "Favorite"
QT_MOC_LITERAL(13, 107, 24), // "AchievementsLocalisation"
QT_MOC_LITERAL(14, 132, 13), // "OnResultImage"
QT_MOC_LITERAL(15, 146, 13), // "ImageRequest*"
QT_MOC_LITERAL(16, 160, 4) // "imgr"

    },
    "ThreadGames\0finished\0\0progress\0p\0Fill\0"
    "Set\0QTableWidget*\0TableWidgetGames\0"
    "QVector<SGame>\0games\0key\0Favorite\0"
    "AchievementsLocalisation\0OnResultImage\0"
    "ImageRequest*\0imgr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadGames[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,
       6,    5,   44,    2, 0x0a /* Public */,
      14,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9, QMetaType::QString, QMetaType::QIcon, QMetaType::QString,    8,   10,   11,   12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void ThreadGames::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadGames *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->Fill();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->Set((*reinterpret_cast< QTableWidget*(*)>(_a[1])),(*reinterpret_cast< QVector<SGame>(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QIcon(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 4: _t->OnResultImage((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
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
            using _t = void (ThreadGames::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadGames::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadGames::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadGames::progress)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThreadGames::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ThreadGames.data,
    qt_meta_data_ThreadGames,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThreadGames::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadGames::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadGames.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadGames::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ThreadGames::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ThreadGames::progress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
