/****************************************************************************
** Meta object code from reading C++ file 'threadachievements.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/class/Threads/threadachievements.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadachievements.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadAchievements_t {
    QByteArrayData data[25];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadAchievements_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadAchievements_t qt_meta_stringdata_ThreadAchievements = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ThreadAchievements"
QT_MOC_LITERAL(1, 19, 10), // "s_finished"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "reached"
QT_MOC_LITERAL(4, 39, 10), // "notreached"
QT_MOC_LITERAL(5, 50, 10), // "s_progress"
QT_MOC_LITERAL(6, 61, 1), // "p"
QT_MOC_LITERAL(7, 63, 3), // "row"
QT_MOC_LITERAL(8, 67, 11), // "s_is_public"
QT_MOC_LITERAL(9, 79, 8), // "a_public"
QT_MOC_LITERAL(10, 88, 8), // "a_column"
QT_MOC_LITERAL(11, 97, 4), // "Fill"
QT_MOC_LITERAL(12, 102, 3), // "Set"
QT_MOC_LITERAL(13, 106, 13), // "SAchievements"
QT_MOC_LITERAL(14, 120, 12), // "achievements"
QT_MOC_LITERAL(15, 133, 7), // "QLabel*"
QT_MOC_LITERAL(16, 141, 17), // "LabelTotalPersent"
QT_MOC_LITERAL(17, 159, 13), // "QTableWidget*"
QT_MOC_LITERAL(18, 173, 23), // "TableWidgetAchievements"
QT_MOC_LITERAL(19, 197, 24), // "LabelTotalPersentCompare"
QT_MOC_LITERAL(20, 222, 9), // "AddFriend"
QT_MOC_LITERAL(21, 232, 9), // "SetFriend"
QT_MOC_LITERAL(22, 242, 11), // "achievement"
QT_MOC_LITERAL(23, 254, 3), // "col"
QT_MOC_LITERAL(24, 258, 12) // "AcolumnAppid"

    },
    "ThreadAchievements\0s_finished\0\0reached\0"
    "notreached\0s_progress\0p\0row\0s_is_public\0"
    "a_public\0a_column\0Fill\0Set\0SAchievements\0"
    "achievements\0QLabel*\0LabelTotalPersent\0"
    "QTableWidget*\0TableWidgetAchievements\0"
    "LabelTotalPersentCompare\0AddFriend\0"
    "SetFriend\0achievement\0col\0AcolumnAppid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadAchievements[] = {

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
       1,    2,   49,    2, 0x06 /* Public */,
       5,    2,   54,    2, 0x06 /* Public */,
       8,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   64,    2, 0x0a /* Public */,
      12,    4,   65,    2, 0x0a /* Public */,
      20,    0,   74,    2, 0x0a /* Public */,
      21,    4,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    9,   10,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15, 0x80000000 | 17, 0x80000000 | 15,   14,   16,   18,   19,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 13, QMetaType::Int, QMetaType::Int,   18,   22,   23,   24,

       0        // eod
};

void ThreadAchievements::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreadAchievements *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->s_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->s_is_public((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: { int _r = _t->Fill();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->Set((*reinterpret_cast< SAchievements(*)>(_a[1])),(*reinterpret_cast< QLabel*(*)>(_a[2])),(*reinterpret_cast< QTableWidget*(*)>(_a[3])),(*reinterpret_cast< QLabel*(*)>(_a[4]))); break;
        case 5: { bool _r = _t->AddFriend();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->SetFriend((*reinterpret_cast< QTableWidget*(*)>(_a[1])),(*reinterpret_cast< SAchievements(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadAchievements::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadAchievements::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThreadAchievements::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadAchievements::s_progress)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ThreadAchievements::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadAchievements::s_is_public)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThreadAchievements::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ThreadAchievements.data,
    qt_meta_data_ThreadAchievements,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThreadAchievements::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadAchievements::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadAchievements.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadAchievements::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ThreadAchievements::s_finished(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadAchievements::s_progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadAchievements::s_is_public(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
