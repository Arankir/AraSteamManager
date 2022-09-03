/****************************************************************************
** Meta object code from reading C++ file 'formachievements.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/achievements/formachievements.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formachievements.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormAchievements_t {
    const uint offsetsAndSize[170];
    char stringdata0[1276];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormAchievements_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormAchievements_t qt_meta_stringdata_FormAchievements = {
    {
QT_MOC_LITERAL(0, 16), // "FormAchievements"
QT_MOC_LITERAL(17, 16), // "s_filtersUpdated"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 19), // "QAbstractItemModel*"
QT_MOC_LITERAL(55, 5), // "model"
QT_MOC_LITERAL(61, 21), // "s_filtersValueUpdated"
QT_MOC_LITERAL(83, 10), // "s_progress"
QT_MOC_LITERAL(94, 6), // "status"
QT_MOC_LITERAL(101, 8), // "progress"
QT_MOC_LITERAL(110, 3), // "max"
QT_MOC_LITERAL(114, 22), // "s_finishedAchievements"
QT_MOC_LITERAL(137, 17), // "s_finishedFriends"
QT_MOC_LITERAL(155, 6), // "update"
QT_MOC_LITERAL(162, 10), // "openManual"
QT_MOC_LITERAL(173, 12), // "isDataSetted"
QT_MOC_LITERAL(186, 18), // "setAllFriendsValue"
QT_MOC_LITERAL(205, 11), // "ReachedType"
QT_MOC_LITERAL(217, 5), // "aType"
QT_MOC_LITERAL(223, 15), // "addFriendToList"
QT_MOC_LITERAL(239, 8), // "SProfile"
QT_MOC_LITERAL(248, 12), // "aSteamFriend"
QT_MOC_LITERAL(261, 31), // "FriendListItemData::ProfileType"
QT_MOC_LITERAL(293, 4), // "type"
QT_MOC_LITERAL(298, 17), // "addProfileToTable"
QT_MOC_LITERAL(316, 11), // "QModelIndex"
QT_MOC_LITERAL(328, 5), // "index"
QT_MOC_LITERAL(334, 14), // "createCategory"
QT_MOC_LITERAL(349, 9), // "aCategory"
QT_MOC_LITERAL(359, 17), // "createSubCategory"
QT_MOC_LITERAL(377, 20), // "onAchievementsLoaded"
QT_MOC_LITERAL(398, 10), // "findFriend"
QT_MOC_LITERAL(409, 35), // "checkBoxFriendsOnlyWithGame_C..."
QT_MOC_LITERAL(445, 8), // "aChecked"
QT_MOC_LITERAL(454, 10), // "closeEvent"
QT_MOC_LITERAL(465, 12), // "QCloseEvent*"
QT_MOC_LITERAL(478, 11), // "retranslate"
QT_MOC_LITERAL(490, 11), // "updateIcons"
QT_MOC_LITERAL(502, 4), // "init"
QT_MOC_LITERAL(507, 16), // "updateCategories"
QT_MOC_LITERAL(524, 30), // "checkBoxFavorites_StateChanged"
QT_MOC_LITERAL(555, 4), // "arg1"
QT_MOC_LITERAL(560, 16), // "initEditCategory"
QT_MOC_LITERAL(577, 19), // "onLoadedFriendGames"
QT_MOC_LITERAL(597, 6), // "SGames"
QT_MOC_LITERAL(604, 5), // "games"
QT_MOC_LITERAL(610, 9), // "ProfileID"
QT_MOC_LITERAL(620, 9), // "profileId"
QT_MOC_LITERAL(630, 21), // "buttonComment_Clicked"
QT_MOC_LITERAL(652, 22), // "createMenuAchievements"
QT_MOC_LITERAL(675, 6), // "QMenu*"
QT_MOC_LITERAL(682, 12), // "SAchievement"
QT_MOC_LITERAL(695, 12), // "aAchievement"
QT_MOC_LITERAL(708, 18), // "createMenuCategory"
QT_MOC_LITERAL(727, 28), // "createMenuAchievementsHeader"
QT_MOC_LITERAL(756, 21), // "createMenuFrozenTable"
QT_MOC_LITERAL(778, 6), // "aIndex"
QT_MOC_LITERAL(785, 25), // "updateFilterWithMyProfile"
QT_MOC_LITERAL(811, 27), // "updateFilterTextAchievement"
QT_MOC_LITERAL(839, 8), // "aNewText"
QT_MOC_LITERAL(848, 20), // "updateFilterCategory"
QT_MOC_LITERAL(869, 9), // "Category*"
QT_MOC_LITERAL(879, 10), // "aIsChecked"
QT_MOC_LITERAL(890, 20), // "updateFilterFavorite"
QT_MOC_LITERAL(911, 26), // "QList<FavoriteAchievement>"
QT_MOC_LITERAL(938, 22), // "aFavoritesAchievements"
QT_MOC_LITERAL(961, 18), // "updateFilterFriend"
QT_MOC_LITERAL(980, 8), // "aSteamId"
QT_MOC_LITERAL(989, 7), // "loading"
QT_MOC_LITERAL(997, 10), // "aIsLoading"
QT_MOC_LITERAL(1008, 18), // "currentAchievement"
QT_MOC_LITERAL(1027, 15), // "onUpdateFilters"
QT_MOC_LITERAL(1043, 18), // "updateAchievements"
QT_MOC_LITERAL(1062, 11), // "loadFriends"
QT_MOC_LITERAL(1074, 15), // "addFriendColumn"
QT_MOC_LITERAL(1090, 18), // "removeFriendColumn"
QT_MOC_LITERAL(1109, 18), // "initTreeCategories"
QT_MOC_LITERAL(1128, 21), // "initAchievementsTable"
QT_MOC_LITERAL(1150, 11), // "initFriends"
QT_MOC_LITERAL(1162, 26), // "createCheckBoxHeaderAction"
QT_MOC_LITERAL(1189, 14), // "QWidgetAction*"
QT_MOC_LITERAL(1204, 5), // "aMenu"
QT_MOC_LITERAL(1210, 5), // "aText"
QT_MOC_LITERAL(1216, 26), // "achievementsModel::Columns"
QT_MOC_LITERAL(1243, 7), // "aColumn"
QT_MOC_LITERAL(1251, 24) // "buttonAddProfile_Clicked"

    },
    "FormAchievements\0s_filtersUpdated\0\0"
    "QAbstractItemModel*\0model\0"
    "s_filtersValueUpdated\0s_progress\0"
    "status\0progress\0max\0s_finishedAchievements\0"
    "s_finishedFriends\0update\0openManual\0"
    "isDataSetted\0setAllFriendsValue\0"
    "ReachedType\0aType\0addFriendToList\0"
    "SProfile\0aSteamFriend\0"
    "FriendListItemData::ProfileType\0type\0"
    "addProfileToTable\0QModelIndex\0index\0"
    "createCategory\0aCategory\0createSubCategory\0"
    "onAchievementsLoaded\0findFriend\0"
    "checkBoxFriendsOnlyWithGame_Clicked\0"
    "aChecked\0closeEvent\0QCloseEvent*\0"
    "retranslate\0updateIcons\0init\0"
    "updateCategories\0checkBoxFavorites_StateChanged\0"
    "arg1\0initEditCategory\0onLoadedFriendGames\0"
    "SGames\0games\0ProfileID\0profileId\0"
    "buttonComment_Clicked\0createMenuAchievements\0"
    "QMenu*\0SAchievement\0aAchievement\0"
    "createMenuCategory\0createMenuAchievementsHeader\0"
    "createMenuFrozenTable\0aIndex\0"
    "updateFilterWithMyProfile\0"
    "updateFilterTextAchievement\0aNewText\0"
    "updateFilterCategory\0Category*\0"
    "aIsChecked\0updateFilterFavorite\0"
    "QList<FavoriteAchievement>\0"
    "aFavoritesAchievements\0updateFilterFriend\0"
    "aSteamId\0loading\0aIsLoading\0"
    "currentAchievement\0onUpdateFilters\0"
    "updateAchievements\0loadFriends\0"
    "addFriendColumn\0removeFriendColumn\0"
    "initTreeCategories\0initAchievementsTable\0"
    "initFriends\0createCheckBoxHeaderAction\0"
    "QWidgetAction*\0aMenu\0aText\0"
    "achievementsModel::Columns\0aColumn\0"
    "buttonAddProfile_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormAchievements[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  308,    2, 0x06,    1 /* Public */,
       5,    0,  311,    2, 0x06,    3 /* Public */,
       6,    3,  312,    2, 0x06,    4 /* Public */,
       6,    2,  319,    2, 0x26,    8 /* Public | MethodCloned */,
       6,    1,  324,    2, 0x26,   11 /* Public | MethodCloned */,
       6,    0,  327,    2, 0x26,   13 /* Public | MethodCloned */,
      10,    0,  328,    2, 0x06,   14 /* Public */,
      11,    0,  329,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,  330,    2, 0x0a,   16 /* Public */,
      13,    0,  331,    2, 0x0a,   17 /* Public */,
      14,    0,  332,    2, 0x0a,   18 /* Public */,
      15,    1,  333,    2, 0x0a,   19 /* Public */,
      18,    2,  336,    2, 0x0a,   21 /* Public */,
      23,    1,  341,    2, 0x0a,   24 /* Public */,
      26,    1,  344,    2, 0x09,   26 /* Protected */,
      28,    1,  347,    2, 0x09,   28 /* Protected */,
      29,    0,  350,    2, 0x09,   30 /* Protected */,
      30,    0,  351,    2, 0x09,   31 /* Protected */,
      31,    1,  352,    2, 0x09,   32 /* Protected */,
      33,    1,  355,    2, 0x08,   34 /* Private */,
      35,    0,  358,    2, 0x08,   36 /* Private */,
      36,    0,  359,    2, 0x08,   37 /* Private */,
      37,    0,  360,    2, 0x08,   38 /* Private */,
      38,    0,  361,    2, 0x08,   39 /* Private */,
      39,    1,  362,    2, 0x08,   40 /* Private */,
      41,    0,  365,    2, 0x08,   42 /* Private */,
      42,    2,  366,    2, 0x08,   43 /* Private */,
      47,    0,  371,    2, 0x08,   46 /* Private */,
      48,    1,  372,    2, 0x08,   47 /* Private */,
      52,    1,  375,    2, 0x08,   49 /* Private */,
      53,    0,  378,    2, 0x08,   51 /* Private */,
      54,    1,  379,    2, 0x08,   52 /* Private */,
      56,    1,  382,    2, 0x08,   54 /* Private */,
      57,    1,  385,    2, 0x08,   56 /* Private */,
      59,    2,  388,    2, 0x08,   58 /* Private */,
      62,    1,  393,    2, 0x08,   61 /* Private */,
      65,    2,  396,    2, 0x08,   63 /* Private */,
      67,    1,  401,    2, 0x08,   66 /* Private */,
      69,    0,  404,    2, 0x08,   68 /* Private */,
      70,    0,  405,    2, 0x08,   69 /* Private */,
      71,    0,  406,    2, 0x08,   70 /* Private */,
      72,    0,  407,    2, 0x08,   71 /* Private */,
      73,    2,  408,    2, 0x08,   72 /* Private */,
      74,    1,  413,    2, 0x08,   75 /* Private */,
      75,    0,  416,    2, 0x08,   77 /* Private */,
      76,    0,  417,    2, 0x08,   78 /* Private */,
      77,    0,  418,    2, 0x08,   79 /* Private */,
      78,    3,  419,    2, 0x08,   80 /* Private */,
      84,    0,  426,    2, 0x08,   84 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 21,   20,   22,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 24,   27,
    QMetaType::Void, 0x80000000 | 24,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 43, 0x80000000 | 45,   44,   46,
    QMetaType::Void,
    0x80000000 | 49, 0x80000000 | 50,   51,
    0x80000000 | 49, 0x80000000 | 24,   27,
    0x80000000 | 49,
    0x80000000 | 49, 0x80000000 | 24,   55,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::QString,   58,
    QMetaType::Void, 0x80000000 | 60, QMetaType::Bool,   27,   61,
    QMetaType::Void, 0x80000000 | 63,   64,
    QMetaType::Void, 0x80000000 | 45, 0x80000000 | 16,   66,   17,
    QMetaType::Void, QMetaType::Bool,   68,
    0x80000000 | 50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 19, 0x80000000 | 21,   20,    2,
    QMetaType::Bool, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 79, 0x80000000 | 49, QMetaType::QString, 0x80000000 | 82,   80,   81,   83,
    QMetaType::Void,

       0        // eod
};

void FormAchievements::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormAchievements *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->s_filtersUpdated((*reinterpret_cast< QAbstractItemModel*(*)>(_a[1]))); break;
        case 1: _t->s_filtersValueUpdated(); break;
        case 2: _t->s_progress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 3: _t->s_progress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 4: _t->s_progress((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->s_progress(); break;
        case 6: _t->s_finishedAchievements(); break;
        case 7: _t->s_finishedFriends(); break;
        case 8: _t->update(); break;
        case 9: _t->openManual(); break;
        case 10: { bool _r = _t->isDataSetted();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setAllFriendsValue((*reinterpret_cast< const ReachedType(*)>(_a[1]))); break;
        case 12: _t->addFriendToList((*reinterpret_cast< const SProfile(*)>(_a[1])),(*reinterpret_cast< FriendListItemData::ProfileType(*)>(_a[2]))); break;
        case 13: _t->addProfileToTable((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->createCategory((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->createSubCategory((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 16: _t->onAchievementsLoaded(); break;
        case 17: _t->findFriend(); break;
        case 18: _t->checkBoxFriendsOnlyWithGame_Clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 20: _t->retranslate(); break;
        case 21: _t->updateIcons(); break;
        case 22: _t->init(); break;
        case 23: _t->updateCategories(); break;
        case 24: _t->checkBoxFavorites_StateChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 25: _t->initEditCategory(); break;
        case 26: _t->onLoadedFriendGames((*reinterpret_cast< const SGames(*)>(_a[1])),(*reinterpret_cast< const ProfileID(*)>(_a[2]))); break;
        case 27: _t->buttonComment_Clicked(); break;
        case 28: { QMenu* _r = _t->createMenuAchievements((*reinterpret_cast< const SAchievement(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 29: { QMenu* _r = _t->createMenuCategory((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 30: { QMenu* _r = _t->createMenuAchievementsHeader();
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 31: { QMenu* _r = _t->createMenuFrozenTable((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 32: _t->updateFilterWithMyProfile((*reinterpret_cast< const ReachedType(*)>(_a[1]))); break;
        case 33: _t->updateFilterTextAchievement((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->updateFilterCategory((*reinterpret_cast< Category*(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 35: _t->updateFilterFavorite((*reinterpret_cast< const QList<FavoriteAchievement>(*)>(_a[1]))); break;
        case 36: _t->updateFilterFriend((*reinterpret_cast< const ProfileID(*)>(_a[1])),(*reinterpret_cast< const ReachedType(*)>(_a[2]))); break;
        case 37: _t->loading((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 38: { SAchievement _r = _t->currentAchievement();
            if (_a[0]) *reinterpret_cast< SAchievement*>(_a[0]) = std::move(_r); }  break;
        case 39: _t->onUpdateFilters(); break;
        case 40: _t->updateAchievements(); break;
        case 41: _t->loadFriends(); break;
        case 42: { int _r = _t->addFriendColumn((*reinterpret_cast< const SProfile(*)>(_a[1])),(*reinterpret_cast< FriendListItemData::ProfileType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 43: { bool _r = _t->removeFriendColumn((*reinterpret_cast< const SProfile(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 44: _t->initTreeCategories(); break;
        case 45: _t->initAchievementsTable(); break;
        case 46: _t->initFriends(); break;
        case 47: { QWidgetAction* _r = _t->createCheckBoxHeaderAction((*reinterpret_cast< QMenu*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< achievementsModel::Columns(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QWidgetAction**>(_a[0]) = std::move(_r); }  break;
        case 48: _t->buttonAddProfile_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractItemModel* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< SAchievement >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormAchievements::*)(QAbstractItemModel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAchievements::s_filtersUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormAchievements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAchievements::s_filtersValueUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FormAchievements::*)(const QString & , const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAchievements::s_progress)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FormAchievements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAchievements::s_finishedAchievements)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (FormAchievements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAchievements::s_finishedFriends)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject FormAchievements::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormAchievements.offsetsAndSize,
    qt_meta_data_FormAchievements,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormAchievements_t
, QtPrivate::TypeAndForceComplete<FormAchievements, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractItemModel *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const ReachedType &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SProfile &, std::false_type>, QtPrivate::TypeAndForceComplete<FriendListItemData::ProfileType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const SGames &, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<const SAchievement &, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const ReachedType &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Category *, std::false_type>, QtPrivate::TypeAndForceComplete<const bool &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<FavoriteAchievement> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const ProfileID &, std::false_type>, QtPrivate::TypeAndForceComplete<const ReachedType &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool &, std::false_type>, QtPrivate::TypeAndForceComplete<SAchievement, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const SProfile &, std::false_type>, QtPrivate::TypeAndForceComplete<FriendListItemData::ProfileType, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const SProfile &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QWidgetAction *, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<achievementsModel::Columns, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FormAchievements::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormAchievements::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormAchievements.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormAchievements::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    }
    return _id;
}

// SIGNAL 0
void FormAchievements::s_filtersUpdated(QAbstractItemModel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormAchievements::s_filtersValueUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FormAchievements::s_progress(const QString & _t1, const int & _t2, const int & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 6
void FormAchievements::s_finishedAchievements()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void FormAchievements::s_finishedFriends()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
