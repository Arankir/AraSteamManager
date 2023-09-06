/****************************************************************************
** Meta object code from reading C++ file 'achievementcompletedpiechart.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/charts/achievementcompletedpiechart.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'achievementcompletedpiechart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AchievementCompletedPieChart_t {
    const uint offsetsAndSize[18];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AchievementCompletedPieChart_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AchievementCompletedPieChart_t qt_meta_stringdata_AchievementCompletedPieChart = {
    {
QT_MOC_LITERAL(0, 28), // "AchievementCompletedPieChart"
QT_MOC_LITERAL(29, 23), // "s_noAchievementsClicked"
QT_MOC_LITERAL(53, 0), // ""
QT_MOC_LITERAL(54, 19), // "s_notStartedClicked"
QT_MOC_LITERAL(74, 16), // "s_startedClicked"
QT_MOC_LITERAL(91, 18), // "s_completedClicked"
QT_MOC_LITERAL(110, 14), // "updateSettings"
QT_MOC_LITERAL(125, 23), // "QFlags<changedSettings>"
QT_MOC_LITERAL(149, 8) // "settings"

    },
    "AchievementCompletedPieChart\0"
    "s_noAchievementsClicked\0\0s_notStartedClicked\0"
    "s_startedClicked\0s_completedClicked\0"
    "updateSettings\0QFlags<changedSettings>\0"
    "settings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AchievementCompletedPieChart[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,
       4,    0,   46,    2, 0x06,    3 /* Public */,
       5,    0,   47,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   48,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void AchievementCompletedPieChart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AchievementCompletedPieChart *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_noAchievementsClicked(); break;
        case 1: _t->s_notStartedClicked(); break;
        case 2: _t->s_startedClicked(); break;
        case 3: _t->s_completedClicked(); break;
        case 4: _t->updateSettings((*reinterpret_cast< QFlags<changedSettings>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AchievementCompletedPieChart::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AchievementCompletedPieChart::s_noAchievementsClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AchievementCompletedPieChart::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AchievementCompletedPieChart::s_notStartedClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AchievementCompletedPieChart::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AchievementCompletedPieChart::s_startedClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AchievementCompletedPieChart::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AchievementCompletedPieChart::s_completedClicked)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject AchievementCompletedPieChart::staticMetaObject = { {
    QMetaObject::SuperData::link<PieChart::staticMetaObject>(),
    qt_meta_stringdata_AchievementCompletedPieChart.offsetsAndSize,
    qt_meta_data_AchievementCompletedPieChart,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AchievementCompletedPieChart_t
, QtPrivate::TypeAndForceComplete<AchievementCompletedPieChart, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QFlags<changedSettings>, std::false_type>


>,
    nullptr
} };


const QMetaObject *AchievementCompletedPieChart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AchievementCompletedPieChart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AchievementCompletedPieChart.stringdata0))
        return static_cast<void*>(this);
    return PieChart::qt_metacast(_clname);
}

int AchievementCompletedPieChart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PieChart::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AchievementCompletedPieChart::s_noAchievementsClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AchievementCompletedPieChart::s_notStartedClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AchievementCompletedPieChart::s_startedClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AchievementCompletedPieChart::s_completedClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
