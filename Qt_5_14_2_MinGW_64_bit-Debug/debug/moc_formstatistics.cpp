/****************************************************************************
** Meta object code from reading C++ file 'formstatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/subForms/main/formstatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formstatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormStatistics_t {
    QByteArrayData data[33];
    char stringdata0[407];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormStatistics_t qt_meta_stringdata_FormStatistics = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FormStatistics"
QT_MOC_LITERAL(1, 15, 18), // "s_statisticsLoaded"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "progress"
QT_MOC_LITERAL(4, 44, 8), // "s_finish"
QT_MOC_LITERAL(5, 53, 19), // "s_return_to_profile"
QT_MOC_LITERAL(6, 73, 8), // "QWidget*"
QT_MOC_LITERAL(7, 82, 18), // "s_showAchievements"
QT_MOC_LITERAL(8, 101, 25), // "QList<SAchievementPlayer>"
QT_MOC_LITERAL(9, 127, 12), // "achievements"
QT_MOC_LITERAL(10, 140, 5), // "SGame"
QT_MOC_LITERAL(11, 146, 4), // "game"
QT_MOC_LITERAL(12, 151, 8), // "onFinish"
QT_MOC_LITERAL(13, 160, 12), // "createThread"
QT_MOC_LITERAL(14, 173, 14), // "updateSettings"
QT_MOC_LITERAL(15, 188, 8), // "setIcons"
QT_MOC_LITERAL(16, 197, 11), // "changeEvent"
QT_MOC_LITERAL(17, 209, 7), // "QEvent*"
QT_MOC_LITERAL(18, 217, 5), // "event"
QT_MOC_LITERAL(19, 223, 11), // "retranslate"
QT_MOC_LITERAL(20, 235, 17), // "showCompleteGames"
QT_MOC_LITERAL(21, 253, 16), // "showStartedGames"
QT_MOC_LITERAL(22, 270, 19), // "showNotStartedGames"
QT_MOC_LITERAL(23, 290, 23), // "showNoAchievementsGames"
QT_MOC_LITERAL(24, 314, 15), // "setModelToTable"
QT_MOC_LITERAL(25, 330, 19), // "QStandardItemModel*"
QT_MOC_LITERAL(26, 350, 6), // "aModel"
QT_MOC_LITERAL(27, 357, 11), // "currentGame"
QT_MOC_LITERAL(28, 369, 6), // "SGame*"
QT_MOC_LITERAL(29, 376, 10), // "createMenu"
QT_MOC_LITERAL(30, 387, 6), // "QMenu*"
QT_MOC_LITERAL(31, 394, 6), // "SGame&"
QT_MOC_LITERAL(32, 401, 5) // "aGame"

    },
    "FormStatistics\0s_statisticsLoaded\0\0"
    "progress\0s_finish\0s_return_to_profile\0"
    "QWidget*\0s_showAchievements\0"
    "QList<SAchievementPlayer>\0achievements\0"
    "SGame\0game\0onFinish\0createThread\0"
    "updateSettings\0setIcons\0changeEvent\0"
    "QEvent*\0event\0retranslate\0showCompleteGames\0"
    "showStartedGames\0showNotStartedGames\0"
    "showNoAchievementsGames\0setModelToTable\0"
    "QStandardItemModel*\0aModel\0currentGame\0"
    "SGame*\0createMenu\0QMenu*\0SGame&\0aGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormStatistics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    0,  102,    2, 0x06 /* Public */,
       5,    1,  103,    2, 0x06 /* Public */,
       7,    2,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  111,    2, 0x0a /* Public */,
      13,    0,  112,    2, 0x0a /* Public */,
      14,    0,  113,    2, 0x0a /* Public */,
      15,    0,  114,    2, 0x0a /* Public */,
      16,    1,  115,    2, 0x08 /* Private */,
      19,    0,  118,    2, 0x08 /* Private */,
      20,    0,  119,    2, 0x08 /* Private */,
      21,    0,  120,    2, 0x08 /* Private */,
      22,    0,  121,    2, 0x08 /* Private */,
      23,    0,  122,    2, 0x08 /* Private */,
      24,    1,  123,    2, 0x08 /* Private */,
      27,    0,  126,    2, 0x08 /* Private */,
      29,    1,  127,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    0x80000000 | 28,
    0x80000000 | 30, 0x80000000 | 31,   32,

       0        // eod
};

void FormStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_statisticsLoaded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->s_finish(); break;
        case 2: _t->s_return_to_profile((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 3: _t->s_showAchievements((*reinterpret_cast< QList<SAchievementPlayer>(*)>(_a[1])),(*reinterpret_cast< SGame(*)>(_a[2]))); break;
        case 4: _t->onFinish(); break;
        case 5: _t->createThread(); break;
        case 6: _t->updateSettings(); break;
        case 7: _t->setIcons(); break;
        case 8: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 9: _t->retranslate(); break;
        case 10: _t->showCompleteGames(); break;
        case 11: _t->showStartedGames(); break;
        case 12: _t->showNotStartedGames(); break;
        case 13: _t->showNoAchievementsGames(); break;
        case 14: _t->setModelToTable((*reinterpret_cast< QStandardItemModel*(*)>(_a[1]))); break;
        case 15: { SGame* _r = _t->currentGame();
            if (_a[0]) *reinterpret_cast< SGame**>(_a[0]) = std::move(_r); }  break;
        case 16: { QMenu* _r = _t->createMenu((*reinterpret_cast< SGame(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormStatistics::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormStatistics::s_statisticsLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormStatistics::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormStatistics::s_finish)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FormStatistics::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormStatistics::s_return_to_profile)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FormStatistics::*)(QList<SAchievementPlayer> , SGame );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormStatistics::s_showAchievements)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormStatistics::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormStatistics.data,
    qt_meta_data_FormStatistics,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormStatistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormStatistics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormStatistics.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void FormStatistics::s_statisticsLoaded(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormStatistics::s_finish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FormStatistics::s_return_to_profile(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FormStatistics::s_showAchievements(QList<SAchievementPlayer> _t1, SGame _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
