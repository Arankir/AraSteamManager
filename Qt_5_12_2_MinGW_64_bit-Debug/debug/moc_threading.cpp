/****************************************************************************
** Meta object code from reading C++ file 'threading.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/class/Threads/threading.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threading.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Threading_t {
    QByteArrayData data[22];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Threading_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Threading_t qt_meta_stringdata_Threading = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Threading"
QT_MOC_LITERAL(1, 10, 14), // "AddThreadGames"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "QTableWidget*"
QT_MOC_LITERAL(4, 40, 16), // "TableWidgetGames"
QT_MOC_LITERAL(5, 57, 14), // "QVector<SGame>"
QT_MOC_LITERAL(6, 72, 5), // "games"
QT_MOC_LITERAL(7, 78, 21), // "AddThreadAchievements"
QT_MOC_LITERAL(8, 100, 9), // "GameAppID"
QT_MOC_LITERAL(9, 110, 13), // "SAchievements"
QT_MOC_LITERAL(10, 124, 12), // "achievements"
QT_MOC_LITERAL(11, 137, 5), // "Words"
QT_MOC_LITERAL(12, 143, 7), // "QLabel*"
QT_MOC_LITERAL(13, 151, 17), // "LabelTotalPersent"
QT_MOC_LITERAL(14, 169, 23), // "TableWidgetAchievements"
QT_MOC_LITERAL(15, 193, 16), // "AddThreadCompare"
QT_MOC_LITERAL(16, 210, 16), // "AddThreadFriends"
QT_MOC_LITERAL(17, 227, 18), // "TableWidgetFriends"
QT_MOC_LITERAL(18, 246, 17), // "QVector<SProfile>"
QT_MOC_LITERAL(19, 264, 8), // "Profiles"
QT_MOC_LITERAL(20, 273, 8), // "SFriends"
QT_MOC_LITERAL(21, 282, 8) // "Friendss"

    },
    "Threading\0AddThreadGames\0\0QTableWidget*\0"
    "TableWidgetGames\0QVector<SGame>\0games\0"
    "AddThreadAchievements\0GameAppID\0"
    "SAchievements\0achievements\0Words\0"
    "QLabel*\0LabelTotalPersent\0"
    "TableWidgetAchievements\0AddThreadCompare\0"
    "AddThreadFriends\0TableWidgetFriends\0"
    "QVector<SProfile>\0Profiles\0SFriends\0"
    "Friendss"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Threading[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x0a /* Public */,
       7,    5,   39,    2, 0x0a /* Public */,
      15,    0,   50,    2, 0x0a /* Public */,
      16,    4,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 9, QMetaType::QStringList, 0x80000000 | 12, 0x80000000 | 3,    8,   10,   11,   13,   14,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 3, 0x80000000 | 18, 0x80000000 | 20, QMetaType::QStringList,   17,   19,   21,   11,

       0        // eod
};

void Threading::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Threading *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->AddThreadGames((*reinterpret_cast< QTableWidget*(*)>(_a[1])),(*reinterpret_cast< QVector<SGame>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->AddThreadAchievements((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SAchievements(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QLabel*(*)>(_a[4])),(*reinterpret_cast< QTableWidget*(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->AddThreadCompare();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->AddThreadFriends((*reinterpret_cast< QTableWidget*(*)>(_a[1])),(*reinterpret_cast< QVector<SProfile>(*)>(_a[2])),(*reinterpret_cast< SFriends(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Threading::staticMetaObject = { {
    &QObject::staticMetaObject,
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
