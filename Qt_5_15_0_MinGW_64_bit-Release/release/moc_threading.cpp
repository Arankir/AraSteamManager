/****************************************************************************
** Meta object code from reading C++ file 'threading.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/class/Threads/threading.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threading.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Threading_t {
    QByteArrayData data[63];
    char stringdata0[921];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Threading_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Threading_t qt_meta_stringdata_Threading = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Threading"
QT_MOC_LITERAL(1, 10, 16), // "s_games_progress"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "progress"
QT_MOC_LITERAL(4, 37, 3), // "row"
QT_MOC_LITERAL(5, 41, 16), // "s_games_finished"
QT_MOC_LITERAL(6, 58, 18), // "s_friends_progress"
QT_MOC_LITERAL(7, 77, 18), // "s_friends_finished"
QT_MOC_LITERAL(8, 96, 21), // "s_statistics_progress"
QT_MOC_LITERAL(9, 118, 21), // "s_statistics_finished"
QT_MOC_LITERAL(10, 140, 32), // "s_achievements_friends_is_public"
QT_MOC_LITERAL(11, 173, 9), // "isVisible"
QT_MOC_LITERAL(12, 183, 6), // "column"
QT_MOC_LITERAL(13, 190, 23), // "s_achievements_progress"
QT_MOC_LITERAL(14, 214, 23), // "s_achievements_finished"
QT_MOC_LITERAL(15, 238, 14), // "AddThreadGames"
QT_MOC_LITERAL(16, 253, 8), // "columnID"
QT_MOC_LITERAL(17, 262, 11), // "columnIndex"
QT_MOC_LITERAL(18, 274, 10), // "columnName"
QT_MOC_LITERAL(19, 285, 13), // "QTableWidget*"
QT_MOC_LITERAL(20, 299, 16), // "tableWidgetGames"
QT_MOC_LITERAL(21, 316, 6), // "SGames"
QT_MOC_LITERAL(22, 323, 5), // "games"
QT_MOC_LITERAL(23, 329, 21), // "AddThreadAchievements"
QT_MOC_LITERAL(24, 351, 16), // "tableColumnAppid"
QT_MOC_LITERAL(25, 368, 16), // "tableColumnTitle"
QT_MOC_LITERAL(26, 385, 22), // "tableColumnDescription"
QT_MOC_LITERAL(27, 408, 16), // "tableColumnWorld"
QT_MOC_LITERAL(28, 425, 13), // "tableColumnMy"
QT_MOC_LITERAL(29, 439, 14), // "SAchievements*"
QT_MOC_LITERAL(30, 454, 12), // "achievements"
QT_MOC_LITERAL(31, 467, 23), // "TableWidgetAchievements"
QT_MOC_LITERAL(32, 491, 16), // "AddThreadFriends"
QT_MOC_LITERAL(33, 508, 11), // "columnAdded"
QT_MOC_LITERAL(34, 520, 12), // "columnStatus"
QT_MOC_LITERAL(35, 533, 14), // "columnisPublic"
QT_MOC_LITERAL(36, 548, 18), // "tableWidgetFriends"
QT_MOC_LITERAL(37, 567, 31), // "QList<QPair<SFriend,SProfile> >"
QT_MOC_LITERAL(38, 599, 7), // "friends"
QT_MOC_LITERAL(39, 607, 19), // "AddThreadStatistics"
QT_MOC_LITERAL(40, 627, 7), // "SGames&"
QT_MOC_LITERAL(41, 635, 8), // "QString&"
QT_MOC_LITERAL(42, 644, 2), // "id"
QT_MOC_LITERAL(43, 647, 13), // "QVector<int>&"
QT_MOC_LITERAL(44, 661, 5), // "numOf"
QT_MOC_LITERAL(45, 667, 33), // "QVector<QPair<QString,QString..."
QT_MOC_LITERAL(46, 701, 8), // "complete"
QT_MOC_LITERAL(47, 710, 7), // "started"
QT_MOC_LITERAL(48, 718, 10), // "notStarted"
QT_MOC_LITERAL(49, 729, 16), // "QVector<double>&"
QT_MOC_LITERAL(50, 746, 14), // "averagePercent"
QT_MOC_LITERAL(51, 761, 4), // "int&"
QT_MOC_LITERAL(52, 766, 10), // "summColumn"
QT_MOC_LITERAL(53, 777, 5), // "times"
QT_MOC_LITERAL(54, 783, 6), // "months"
QT_MOC_LITERAL(55, 790, 29), // "QVector<QPair<QString,int> >&"
QT_MOC_LITERAL(56, 820, 5), // "years"
QT_MOC_LITERAL(57, 826, 27), // "AddThreadFriendAchievements"
QT_MOC_LITERAL(58, 854, 23), // "tableWidgetAchievements"
QT_MOC_LITERAL(59, 878, 14), // "SAchievements&"
QT_MOC_LITERAL(60, 893, 11), // "achievement"
QT_MOC_LITERAL(61, 905, 3), // "col"
QT_MOC_LITERAL(62, 909, 11) // "columnAppid"

    },
    "Threading\0s_games_progress\0\0progress\0"
    "row\0s_games_finished\0s_friends_progress\0"
    "s_friends_finished\0s_statistics_progress\0"
    "s_statistics_finished\0"
    "s_achievements_friends_is_public\0"
    "isVisible\0column\0s_achievements_progress\0"
    "s_achievements_finished\0AddThreadGames\0"
    "columnID\0columnIndex\0columnName\0"
    "QTableWidget*\0tableWidgetGames\0SGames\0"
    "games\0AddThreadAchievements\0"
    "tableColumnAppid\0tableColumnTitle\0"
    "tableColumnDescription\0tableColumnWorld\0"
    "tableColumnMy\0SAchievements*\0achievements\0"
    "TableWidgetAchievements\0AddThreadFriends\0"
    "columnAdded\0columnStatus\0columnisPublic\0"
    "tableWidgetFriends\0QList<QPair<SFriend,SProfile> >\0"
    "friends\0AddThreadStatistics\0SGames&\0"
    "QString&\0id\0QVector<int>&\0numOf\0"
    "QVector<QPair<QString,QString> >&\0"
    "complete\0started\0notStarted\0"
    "QVector<double>&\0averagePercent\0int&\0"
    "summColumn\0times\0months\0"
    "QVector<QPair<QString,int> >&\0years\0"
    "AddThreadFriendAchievements\0"
    "tableWidgetAchievements\0SAchievements&\0"
    "achievement\0col\0columnAppid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Threading[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    0,   89,    2, 0x06 /* Public */,
       6,    2,   90,    2, 0x06 /* Public */,
       7,    0,   95,    2, 0x06 /* Public */,
       8,    2,   96,    2, 0x06 /* Public */,
       9,    0,  101,    2, 0x06 /* Public */,
      10,    2,  102,    2, 0x06 /* Public */,
      13,    2,  107,    2, 0x06 /* Public */,
      14,    2,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    5,  117,    2, 0x0a /* Public */,
      23,    7,  128,    2, 0x0a /* Public */,
      32,    7,  143,    2, 0x0a /* Public */,
      39,   11,  158,    2, 0x0a /* Public */,
      57,    4,  181,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 19, 0x80000000 | 21,   16,   17,   18,   20,   22,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 29, 0x80000000 | 19,   24,   25,   26,   27,   28,   30,   31,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 19, 0x80000000 | 37,   16,   18,   33,   34,   35,   36,   38,
    QMetaType::Int, 0x80000000 | 40, 0x80000000 | 41, 0x80000000 | 43, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 45, 0x80000000 | 49, 0x80000000 | 51, 0x80000000 | 43, 0x80000000 | 43, 0x80000000 | 55,   22,   42,   44,   46,   47,   48,   50,   52,   53,   54,   56,
    QMetaType::Int, 0x80000000 | 19, 0x80000000 | 59, QMetaType::Int, QMetaType::Int,   58,   60,   61,   62,

       0        // eod
};

void Threading::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Threading *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_games_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->s_games_finished(); break;
        case 2: _t->s_friends_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->s_friends_finished(); break;
        case 4: _t->s_statistics_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->s_statistics_finished(); break;
        case 6: _t->s_achievements_friends_is_public((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->s_achievements_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->s_achievements_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: { int _r = _t->AddThreadGames((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< QTableWidget*(*)>(_a[4])),(*reinterpret_cast< SGames(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->AddThreadAchievements((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5])),(*reinterpret_cast< SAchievements*(*)>(_a[6])),(*reinterpret_cast< QTableWidget*(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->AddThreadFriends((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5])),(*reinterpret_cast< QTableWidget*(*)>(_a[6])),(*reinterpret_cast< QList<QPair<SFriend,SProfile> >(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->AddThreadStatistics((*reinterpret_cast< SGames(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[4])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[5])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[6])),(*reinterpret_cast< QVector<double>(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< QVector<int>(*)>(_a[9])),(*reinterpret_cast< QVector<int>(*)>(_a[10])),(*reinterpret_cast< QVector<QPair<QString,int> >(*)>(_a[11])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->AddThreadFriendAchievements((*reinterpret_cast< QTableWidget*(*)>(_a[1])),(*reinterpret_cast< SAchievements(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 6:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SAchievements* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        case 13:
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
            using _t = void (Threading::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_games_progress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Threading::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_games_finished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Threading::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_friends_progress)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Threading::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_friends_finished)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Threading::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_statistics_progress)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Threading::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_statistics_finished)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Threading::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_achievements_friends_is_public)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Threading::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_achievements_progress)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Threading::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_achievements_finished)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Threading::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Threading.data,
    qt_meta_data_Threading,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Threading::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Threading::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Threading.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Threading::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Threading::s_games_progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Threading::s_games_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Threading::s_friends_progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Threading::s_friends_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Threading::s_statistics_progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Threading::s_statistics_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Threading::s_achievements_friends_is_public(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Threading::s_achievements_progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Threading::s_achievements_finished(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
