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
    QByteArrayData data[20];
    char stringdata0[199];
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
QT_MOC_LITERAL(5, 33, 3), // "row"
QT_MOC_LITERAL(6, 37, 8), // "setimage"
QT_MOC_LITERAL(7, 46, 4), // "Fill"
QT_MOC_LITERAL(8, 51, 3), // "Set"
QT_MOC_LITERAL(9, 55, 13), // "QTableWidget*"
QT_MOC_LITERAL(10, 69, 16), // "TableWidgetGames"
QT_MOC_LITERAL(11, 86, 14), // "QVector<SGame>"
QT_MOC_LITERAL(12, 101, 5), // "games"
QT_MOC_LITERAL(13, 107, 3), // "key"
QT_MOC_LITERAL(14, 111, 8), // "Favorite"
QT_MOC_LITERAL(15, 120, 24), // "AchievementsLocalisation"
QT_MOC_LITERAL(16, 145, 13), // "OnResultImage"
QT_MOC_LITERAL(17, 159, 13), // "ImageRequest*"
QT_MOC_LITERAL(18, 173, 4), // "imgr"
QT_MOC_LITERAL(19, 178, 20) // "OnResultAchievements"

    },
    "ThreadGames\0finished\0\0progress\0p\0row\0"
    "setimage\0Fill\0Set\0QTableWidget*\0"
    "TableWidgetGames\0QVector<SGame>\0games\0"
    "key\0Favorite\0AchievementsLocalisation\0"
    "OnResultImage\0ImageRequest*\0imgr\0"
    "OnResultAchievements"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadGames[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    2,   50,    2, 0x06 /* Public */,
       6,    2,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   60,    2, 0x0a /* Public */,
       8,    5,   61,    2, 0x0a /* Public */,
      16,    1,   72,    2, 0x0a /* Public */,
      19,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QPixmap, QMetaType::Int,    2,    5,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11, QMetaType::QString, QMetaType::QIcon, QMetaType::QString,   10,   12,   13,   14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void ThreadGames::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadGames *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setimage((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: { int _r = _t->Fill();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->Set((*reinterpret_cast< QTableWidget*(*)>(_a[1])),(*reinterpret_cast< QVector<SGame>(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QIcon(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 5: _t->OnResultImage((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        case 6: _t->OnResultAchievements((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageRequest* >(); break;
            }
            break;
        case 6:
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
            using _t = void (ThreadGames::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadGames::progress)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ThreadGames::*)(QPixmap , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadGames::setimage)) {
                *result = 2;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ThreadGames::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ThreadGames::progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadGames::setimage(QPixmap _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
