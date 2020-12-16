/****************************************************************************
** Meta object code from reading C++ file 'formgames.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/subForms/main/formgames.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formgames.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormGames_t {
    QByteArrayData data[66];
    char stringdata0[832];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormGames_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormGames_t qt_meta_stringdata_FormGames = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FormGames"
QT_MOC_LITERAL(1, 10, 19), // "s_return_to_profile"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "QWidget*"
QT_MOC_LITERAL(4, 40, 20), // "s_achievementsLoaded"
QT_MOC_LITERAL(5, 61, 8), // "s_finish"
QT_MOC_LITERAL(6, 70, 5), // "width"
QT_MOC_LITERAL(7, 76, 18), // "s_showAchievements"
QT_MOC_LITERAL(8, 95, 20), // "SAchievementsPlayer&"
QT_MOC_LITERAL(9, 116, 12), // "achievements"
QT_MOC_LITERAL(10, 129, 6), // "SGame&"
QT_MOC_LITERAL(11, 136, 5), // "games"
QT_MOC_LITERAL(12, 142, 14), // "updateSettings"
QT_MOC_LITERAL(13, 157, 8), // "setGames"
QT_MOC_LITERAL(14, 166, 9), // "SProfile&"
QT_MOC_LITERAL(15, 176, 8), // "aProfile"
QT_MOC_LITERAL(16, 185, 7), // "SGames&"
QT_MOC_LITERAL(17, 193, 6), // "aGames"
QT_MOC_LITERAL(18, 200, 6), // "isInit"
QT_MOC_LITERAL(19, 207, 8), // "isLoaded"
QT_MOC_LITERAL(20, 216, 5), // "clear"
QT_MOC_LITERAL(21, 222, 4), // "init"
QT_MOC_LITERAL(22, 227, 11), // "changeEvent"
QT_MOC_LITERAL(23, 239, 7), // "QEvent*"
QT_MOC_LITERAL(24, 247, 5), // "event"
QT_MOC_LITERAL(25, 253, 14), // "initComponents"
QT_MOC_LITERAL(26, 268, 8), // "setIcons"
QT_MOC_LITERAL(27, 277, 11), // "retranslate"
QT_MOC_LITERAL(28, 289, 20), // "onResultAchievements"
QT_MOC_LITERAL(29, 310, 20), // "SAchievementsPlayer*"
QT_MOC_LITERAL(30, 331, 3), // "ach"
QT_MOC_LITERAL(31, 335, 10), // "closeEvent"
QT_MOC_LITERAL(32, 346, 12), // "QCloseEvent*"
QT_MOC_LITERAL(33, 359, 24), // "lineEditGame_TextChanged"
QT_MOC_LITERAL(34, 384, 9), // "aFindText"
QT_MOC_LITERAL(35, 394, 18), // "buttonFind_Clicked"
QT_MOC_LITERAL(36, 413, 26), // "buttonAchievements_Clicked"
QT_MOC_LITERAL(37, 440, 22), // "buttonFavorite_Clicked"
QT_MOC_LITERAL(38, 463, 18), // "buttonHide_Clicked"
QT_MOC_LITERAL(39, 482, 12), // "createThread"
QT_MOC_LITERAL(40, 495, 10), // "createMenu"
QT_MOC_LITERAL(41, 506, 6), // "QMenu*"
QT_MOC_LITERAL(42, 513, 4), // "game"
QT_MOC_LITERAL(43, 518, 17), // "updateHiddenGames"
QT_MOC_LITERAL(44, 536, 17), // "updateCurrentGame"
QT_MOC_LITERAL(45, 554, 9), // "initTable"
QT_MOC_LITERAL(46, 564, 10), // "initGroups"
QT_MOC_LITERAL(47, 575, 12), // "initComments"
QT_MOC_LITERAL(48, 588, 13), // "setTableModel"
QT_MOC_LITERAL(49, 602, 19), // "QStandardItemModel*"
QT_MOC_LITERAL(50, 622, 6), // "aModel"
QT_MOC_LITERAL(51, 629, 12), // "indexFromRow"
QT_MOC_LITERAL(52, 642, 4), // "aRow"
QT_MOC_LITERAL(53, 647, 12), // "rowFromIndex"
QT_MOC_LITERAL(54, 660, 6), // "aIndex"
QT_MOC_LITERAL(55, 667, 11), // "indexFromId"
QT_MOC_LITERAL(56, 679, 3), // "aId"
QT_MOC_LITERAL(57, 683, 9), // "rowFromId"
QT_MOC_LITERAL(58, 693, 16), // "updateHiddenRows"
QT_MOC_LITERAL(59, 710, 18), // "updateGroupsFilter"
QT_MOC_LITERAL(60, 729, 21), // "showGroupsInteractive"
QT_MOC_LITERAL(61, 751, 23), // "showCommentsInteractive"
QT_MOC_LITERAL(62, 775, 30), // "checkBoxFavorites_StateChanged"
QT_MOC_LITERAL(63, 806, 4), // "arg1"
QT_MOC_LITERAL(64, 811, 13), // "isInFavorites"
QT_MOC_LITERAL(65, 825, 6) // "aAppId"

    },
    "FormGames\0s_return_to_profile\0\0QWidget*\0"
    "s_achievementsLoaded\0s_finish\0width\0"
    "s_showAchievements\0SAchievementsPlayer&\0"
    "achievements\0SGame&\0games\0updateSettings\0"
    "setGames\0SProfile&\0aProfile\0SGames&\0"
    "aGames\0isInit\0isLoaded\0clear\0init\0"
    "changeEvent\0QEvent*\0event\0initComponents\0"
    "setIcons\0retranslate\0onResultAchievements\0"
    "SAchievementsPlayer*\0ach\0closeEvent\0"
    "QCloseEvent*\0lineEditGame_TextChanged\0"
    "aFindText\0buttonFind_Clicked\0"
    "buttonAchievements_Clicked\0"
    "buttonFavorite_Clicked\0buttonHide_Clicked\0"
    "createThread\0createMenu\0QMenu*\0game\0"
    "updateHiddenGames\0updateCurrentGame\0"
    "initTable\0initGroups\0initComments\0"
    "setTableModel\0QStandardItemModel*\0"
    "aModel\0indexFromRow\0aRow\0rowFromIndex\0"
    "aIndex\0indexFromId\0aId\0rowFromId\0"
    "updateHiddenRows\0updateGroupsFilter\0"
    "showGroupsInteractive\0showCommentsInteractive\0"
    "checkBoxFavorites_StateChanged\0arg1\0"
    "isInFavorites\0aAppId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormGames[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  209,    2, 0x06 /* Public */,
       4,    2,  212,    2, 0x06 /* Public */,
       5,    1,  217,    2, 0x06 /* Public */,
       7,    2,  220,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  225,    2, 0x0a /* Public */,
      13,    2,  226,    2, 0x0a /* Public */,
      18,    0,  231,    2, 0x0a /* Public */,
      19,    0,  232,    2, 0x0a /* Public */,
      20,    0,  233,    2, 0x0a /* Public */,
      21,    0,  234,    2, 0x08 /* Private */,
      22,    1,  235,    2, 0x08 /* Private */,
      25,    0,  238,    2, 0x08 /* Private */,
      26,    0,  239,    2, 0x08 /* Private */,
      27,    0,  240,    2, 0x08 /* Private */,
      28,    1,  241,    2, 0x08 /* Private */,
      31,    1,  244,    2, 0x08 /* Private */,
      33,    1,  247,    2, 0x08 /* Private */,
      35,    0,  250,    2, 0x08 /* Private */,
      36,    0,  251,    2, 0x08 /* Private */,
      37,    0,  252,    2, 0x08 /* Private */,
      38,    0,  253,    2, 0x08 /* Private */,
      39,    0,  254,    2, 0x08 /* Private */,
      40,    1,  255,    2, 0x08 /* Private */,
      43,    0,  258,    2, 0x08 /* Private */,
      44,    0,  259,    2, 0x08 /* Private */,
      45,    0,  260,    2, 0x08 /* Private */,
      46,    0,  261,    2, 0x08 /* Private */,
      47,    0,  262,    2, 0x08 /* Private */,
      48,    1,  263,    2, 0x08 /* Private */,
      51,    1,  266,    2, 0x08 /* Private */,
      53,    1,  269,    2, 0x08 /* Private */,
      55,    1,  272,    2, 0x08 /* Private */,
      57,    1,  275,    2, 0x08 /* Private */,
      58,    0,  278,    2, 0x08 /* Private */,
      59,    0,  279,    2, 0x08 /* Private */,
      60,    0,  280,    2, 0x08 /* Private */,
      61,    0,  281,    2, 0x08 /* Private */,
      62,    1,  282,    2, 0x08 /* Private */,
      64,    1,  285,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 16,   15,   17,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 32,   24,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 41, 0x80000000 | 10,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 49,   50,
    QMetaType::Int, QMetaType::Int,   52,
    QMetaType::Int, QMetaType::Int,   54,
    QMetaType::Int, QMetaType::QString,   56,
    QMetaType::Int, QMetaType::QString,   56,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   63,
    QMetaType::Bool, QMetaType::Int,   65,

       0        // eod
};

void FormGames::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormGames *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_return_to_profile((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->s_achievementsLoaded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->s_finish((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->s_showAchievements((*reinterpret_cast< SAchievementsPlayer(*)>(_a[1])),(*reinterpret_cast< SGame(*)>(_a[2]))); break;
        case 4: _t->updateSettings(); break;
        case 5: _t->setGames((*reinterpret_cast< SProfile(*)>(_a[1])),(*reinterpret_cast< SGames(*)>(_a[2]))); break;
        case 6: { bool _r = _t->isInit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->isLoaded();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->clear(); break;
        case 9: _t->init(); break;
        case 10: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 11: _t->initComponents(); break;
        case 12: _t->setIcons(); break;
        case 13: _t->retranslate(); break;
        case 14: _t->onResultAchievements((*reinterpret_cast< SAchievementsPlayer*(*)>(_a[1]))); break;
        case 15: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 16: _t->lineEditGame_TextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->buttonFind_Clicked(); break;
        case 18: _t->buttonAchievements_Clicked(); break;
        case 19: _t->buttonFavorite_Clicked(); break;
        case 20: _t->buttonHide_Clicked(); break;
        case 21: _t->createThread(); break;
        case 22: { QMenu* _r = _t->createMenu((*reinterpret_cast< SGame(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 23: _t->updateHiddenGames(); break;
        case 24: _t->updateCurrentGame(); break;
        case 25: _t->initTable(); break;
        case 26: _t->initGroups(); break;
        case 27: _t->initComments(); break;
        case 28: _t->setTableModel((*reinterpret_cast< QStandardItemModel*(*)>(_a[1]))); break;
        case 29: { int _r = _t->indexFromRow((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 30: { int _r = _t->rowFromIndex((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 31: { int _r = _t->indexFromId((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 32: { int _r = _t->rowFromId((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->updateHiddenRows(); break;
        case 34: _t->updateGroupsFilter(); break;
        case 35: _t->showGroupsInteractive(); break;
        case 36: _t->showCommentsInteractive(); break;
        case 37: _t->checkBoxFavorites_StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: { bool _r = _t->isInFavorites((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SAchievementsPlayer* >(); break;
            }
            break;
        case 28:
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
            using _t = void (FormGames::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormGames::s_return_to_profile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormGames::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormGames::s_achievementsLoaded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FormGames::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormGames::s_finish)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FormGames::*)(SAchievementsPlayer & , SGame & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormGames::s_showAchievements)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormGames::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
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
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void FormGames::s_return_to_profile(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormGames::s_achievementsLoaded(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FormGames::s_finish(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FormGames::s_showAchievements(SAchievementsPlayer & _t1, SGame & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
