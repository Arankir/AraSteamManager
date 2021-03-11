/****************************************************************************
** Meta object code from reading C++ file 'threading.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/classes/threads/threading.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threading.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Threading_t {
    QByteArrayData data[71];
    char stringdata0[1015];
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
QT_MOC_LITERAL(5, 41, 22), // "s_games_finished_model"
QT_MOC_LITERAL(6, 64, 19), // "QStandardItemModel*"
QT_MOC_LITERAL(7, 84, 18), // "s_friends_progress"
QT_MOC_LITERAL(8, 103, 24), // "s_friends_finished_model"
QT_MOC_LITERAL(9, 128, 21), // "s_statistics_progress"
QT_MOC_LITERAL(10, 150, 21), // "s_statistics_finished"
QT_MOC_LITERAL(11, 172, 32), // "s_achievements_friends_is_public"
QT_MOC_LITERAL(12, 205, 9), // "isVisible"
QT_MOC_LITERAL(13, 215, 6), // "column"
QT_MOC_LITERAL(14, 222, 23), // "s_achievements_progress"
QT_MOC_LITERAL(15, 246, 29), // "s_achievements_finished_model"
QT_MOC_LITERAL(16, 276, 5), // "model"
QT_MOC_LITERAL(17, 282, 7), // "reached"
QT_MOC_LITERAL(18, 290, 10), // "notReached"
QT_MOC_LITERAL(19, 301, 23), // "s_achievements_finished"
QT_MOC_LITERAL(20, 325, 14), // "AddThreadGames"
QT_MOC_LITERAL(21, 340, 8), // "columnID"
QT_MOC_LITERAL(22, 349, 11), // "columnIndex"
QT_MOC_LITERAL(23, 361, 10), // "columnIcon"
QT_MOC_LITERAL(24, 372, 10), // "columnName"
QT_MOC_LITERAL(25, 383, 13), // "columnComment"
QT_MOC_LITERAL(26, 397, 14), // "columnProgress"
QT_MOC_LITERAL(27, 412, 11), // "columnCount"
QT_MOC_LITERAL(28, 424, 12), // "QList<SGame>"
QT_MOC_LITERAL(29, 437, 5), // "games"
QT_MOC_LITERAL(30, 443, 21), // "AddThreadAchievements"
QT_MOC_LITERAL(31, 465, 11), // "columnAppid"
QT_MOC_LITERAL(32, 477, 11), // "columnTitle"
QT_MOC_LITERAL(33, 489, 17), // "columnDescription"
QT_MOC_LITERAL(34, 507, 11), // "columnWorld"
QT_MOC_LITERAL(35, 519, 8), // "columnMy"
QT_MOC_LITERAL(36, 528, 13), // "achievedColor"
QT_MOC_LITERAL(37, 542, 16), // "notAchievedColor"
QT_MOC_LITERAL(38, 559, 13), // "SAchievements"
QT_MOC_LITERAL(39, 573, 12), // "achievements"
QT_MOC_LITERAL(40, 586, 9), // "gameAppId"
QT_MOC_LITERAL(41, 596, 16), // "AddThreadFriends"
QT_MOC_LITERAL(42, 613, 11), // "columnAdded"
QT_MOC_LITERAL(43, 625, 12), // "columnStatus"
QT_MOC_LITERAL(44, 638, 14), // "columnisPublic"
QT_MOC_LITERAL(45, 653, 31), // "QList<QPair<SFriend,SProfile> >"
QT_MOC_LITERAL(46, 685, 7), // "friends"
QT_MOC_LITERAL(47, 693, 19), // "AddThreadStatistics"
QT_MOC_LITERAL(48, 713, 13), // "QList<SGame>&"
QT_MOC_LITERAL(49, 727, 8), // "QString&"
QT_MOC_LITERAL(50, 736, 2), // "id"
QT_MOC_LITERAL(51, 739, 13), // "QVector<int>&"
QT_MOC_LITERAL(52, 753, 5), // "numOf"
QT_MOC_LITERAL(53, 759, 33), // "QVector<QPair<QString,QString..."
QT_MOC_LITERAL(54, 793, 8), // "complete"
QT_MOC_LITERAL(55, 802, 7), // "started"
QT_MOC_LITERAL(56, 810, 10), // "notStarted"
QT_MOC_LITERAL(57, 821, 16), // "QVector<double>&"
QT_MOC_LITERAL(58, 838, 14), // "averagePercent"
QT_MOC_LITERAL(59, 853, 4), // "int&"
QT_MOC_LITERAL(60, 858, 10), // "summColumn"
QT_MOC_LITERAL(61, 869, 5), // "times"
QT_MOC_LITERAL(62, 875, 6), // "months"
QT_MOC_LITERAL(63, 882, 29), // "QVector<QPair<QString,int> >&"
QT_MOC_LITERAL(64, 912, 5), // "years"
QT_MOC_LITERAL(65, 918, 27), // "AddThreadFriendAchievements"
QT_MOC_LITERAL(66, 946, 13), // "QTableWidget*"
QT_MOC_LITERAL(67, 960, 23), // "tableWidgetAchievements"
QT_MOC_LITERAL(68, 984, 14), // "SAchievements&"
QT_MOC_LITERAL(69, 999, 11), // "achievement"
QT_MOC_LITERAL(70, 1011, 3) // "col"

    },
    "Threading\0s_games_progress\0\0progress\0"
    "row\0s_games_finished_model\0"
    "QStandardItemModel*\0s_friends_progress\0"
    "s_friends_finished_model\0s_statistics_progress\0"
    "s_statistics_finished\0"
    "s_achievements_friends_is_public\0"
    "isVisible\0column\0s_achievements_progress\0"
    "s_achievements_finished_model\0model\0"
    "reached\0notReached\0s_achievements_finished\0"
    "AddThreadGames\0columnID\0columnIndex\0"
    "columnIcon\0columnName\0columnComment\0"
    "columnProgress\0columnCount\0QList<SGame>\0"
    "games\0AddThreadAchievements\0columnAppid\0"
    "columnTitle\0columnDescription\0columnWorld\0"
    "columnMy\0achievedColor\0notAchievedColor\0"
    "SAchievements\0achievements\0gameAppId\0"
    "AddThreadFriends\0columnAdded\0columnStatus\0"
    "columnisPublic\0QList<QPair<SFriend,SProfile> >\0"
    "friends\0AddThreadStatistics\0QList<SGame>&\0"
    "QString&\0id\0QVector<int>&\0numOf\0"
    "QVector<QPair<QString,QString> >&\0"
    "complete\0started\0notStarted\0"
    "QVector<double>&\0averagePercent\0int&\0"
    "summColumn\0times\0months\0"
    "QVector<QPair<QString,int> >&\0years\0"
    "AddThreadFriendAchievements\0QTableWidget*\0"
    "tableWidgetAchievements\0SAchievements&\0"
    "achievement\0col"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Threading[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       5,    1,   94,    2, 0x06 /* Public */,
       7,    2,   97,    2, 0x06 /* Public */,
       8,    1,  102,    2, 0x06 /* Public */,
       9,    2,  105,    2, 0x06 /* Public */,
      10,    0,  110,    2, 0x06 /* Public */,
      11,    2,  111,    2, 0x06 /* Public */,
      14,    2,  116,    2, 0x06 /* Public */,
      15,    3,  121,    2, 0x06 /* Public */,
      19,    2,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    8,  133,    2, 0x0a /* Public */,
      30,   13,  150,    2, 0x0a /* Public */,
      41,    8,  177,    2, 0x0a /* Public */,
      47,   11,  194,    2, 0x0a /* Public */,
      65,    4,  217,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, QMetaType::Int,   16,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 28,   21,   22,   23,   24,   25,   26,   27,   29,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QColor, QMetaType::QColor, 0x80000000 | 38, QMetaType::Int,   31,   22,   23,   32,   33,   25,   34,   35,   27,   36,   37,   39,   40,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 45,   21,   22,   23,   24,   42,   43,   44,   46,
    QMetaType::Int, 0x80000000 | 48, 0x80000000 | 49, 0x80000000 | 51, 0x80000000 | 53, 0x80000000 | 53, 0x80000000 | 53, 0x80000000 | 57, 0x80000000 | 59, 0x80000000 | 51, 0x80000000 | 51, 0x80000000 | 63,   29,   50,   52,   54,   55,   56,   58,   60,   61,   62,   64,
    QMetaType::Int, 0x80000000 | 66, 0x80000000 | 68, QMetaType::Int, QMetaType::Int,   67,   69,   70,   31,

       0        // eod
};

void Threading::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Threading *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_games_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->s_games_finished_model((*reinterpret_cast< QStandardItemModel*(*)>(_a[1]))); break;
        case 2: _t->s_friends_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->s_friends_finished_model((*reinterpret_cast< QStandardItemModel*(*)>(_a[1]))); break;
        case 4: _t->s_statistics_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->s_statistics_finished(); break;
        case 6: _t->s_achievements_friends_is_public((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->s_achievements_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->s_achievements_finished_model((*reinterpret_cast< QStandardItemModel*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->s_achievements_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: { int _r = _t->AddThreadGames((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5])),(*reinterpret_cast< const int(*)>(_a[6])),(*reinterpret_cast< const int(*)>(_a[7])),(*reinterpret_cast< QList<SGame>(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->AddThreadAchievements((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5])),(*reinterpret_cast< const int(*)>(_a[6])),(*reinterpret_cast< const int(*)>(_a[7])),(*reinterpret_cast< const int(*)>(_a[8])),(*reinterpret_cast< const int(*)>(_a[9])),(*reinterpret_cast< const QColor(*)>(_a[10])),(*reinterpret_cast< const QColor(*)>(_a[11])),(*reinterpret_cast< const SAchievements(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->AddThreadFriends((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5])),(*reinterpret_cast< const int(*)>(_a[6])),(*reinterpret_cast< const int(*)>(_a[7])),(*reinterpret_cast< QList<QPair<SFriend,SProfile> >(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->AddThreadStatistics((*reinterpret_cast< QList<SGame>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[4])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[5])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[6])),(*reinterpret_cast< QVector<double>(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< QVector<int>(*)>(_a[9])),(*reinterpret_cast< QVector<int>(*)>(_a[10])),(*reinterpret_cast< QVector<QPair<QString,int> >(*)>(_a[11])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->AddThreadFriendAchievements((*reinterpret_cast< QTableWidget*(*)>(_a[1])),(*reinterpret_cast< SAchievements(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        case 14:
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
            using _t = void (Threading::*)(QStandardItemModel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_games_finished_model)) {
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
            using _t = void (Threading::*)(QStandardItemModel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_friends_finished_model)) {
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
            using _t = void (Threading::*)(QStandardItemModel * , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_achievements_finished_model)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Threading::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threading::s_achievements_finished)) {
                *result = 9;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
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
void Threading::s_games_finished_model(QStandardItemModel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Threading::s_friends_progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Threading::s_friends_finished_model(QStandardItemModel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
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
void Threading::s_achievements_finished_model(QStandardItemModel * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Threading::s_achievements_finished(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
