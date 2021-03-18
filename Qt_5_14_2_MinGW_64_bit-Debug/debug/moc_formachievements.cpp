/****************************************************************************
** Meta object code from reading C++ file 'formachievements.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/subForms/achievements/formachievements.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formachievements.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormAchievements_t {
    QByteArrayData data[79];
    char stringdata0[1121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormAchievements_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormAchievements_t qt_meta_stringdata_FormAchievements = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FormAchievements"
QT_MOC_LITERAL(1, 17, 16), // "s_updateSettings"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "s_updatedHiddenRows"
QT_MOC_LITERAL(4, 55, 15), // "progressLoading"
QT_MOC_LITERAL(5, 71, 5), // "value"
QT_MOC_LITERAL(6, 77, 3), // "max"
QT_MOC_LITERAL(7, 81, 13), // "onModelPulled"
QT_MOC_LITERAL(8, 95, 19), // "QStandardItemModel*"
QT_MOC_LITERAL(9, 115, 6), // "aModel"
QT_MOC_LITERAL(10, 122, 7), // "reached"
QT_MOC_LITERAL(11, 130, 10), // "notReached"
QT_MOC_LITERAL(12, 141, 12), // "getProfileId"
QT_MOC_LITERAL(13, 154, 12), // "getGameAppId"
QT_MOC_LITERAL(14, 167, 20), // "buttonUpdate_Clicked"
QT_MOC_LITERAL(15, 188, 14), // "updateSettings"
QT_MOC_LITERAL(16, 203, 20), // "buttonManual_Clicked"
QT_MOC_LITERAL(17, 224, 11), // "changeEvent"
QT_MOC_LITERAL(18, 236, 7), // "QEvent*"
QT_MOC_LITERAL(19, 244, 5), // "event"
QT_MOC_LITERAL(20, 250, 10), // "closeEvent"
QT_MOC_LITERAL(21, 261, 12), // "QCloseEvent*"
QT_MOC_LITERAL(22, 274, 14), // "initComponents"
QT_MOC_LITERAL(23, 289, 11), // "retranslate"
QT_MOC_LITERAL(24, 301, 8), // "setIcons"
QT_MOC_LITERAL(25, 310, 14), // "showCategories"
QT_MOC_LITERAL(26, 325, 29), // "checkBoxCategory_StateChanged"
QT_MOC_LITERAL(27, 355, 3), // "ind"
QT_MOC_LITERAL(28, 359, 30), // "checkBoxFavorites_StateChanged"
QT_MOC_LITERAL(29, 390, 4), // "arg1"
QT_MOC_LITERAL(30, 395, 22), // "buttonFavorite_Clicked"
QT_MOC_LITERAL(31, 418, 16), // "loadEditCategory"
QT_MOC_LITERAL(32, 435, 11), // "loadCompare"
QT_MOC_LITERAL(33, 447, 24), // "tabWidget_CurrentChanged"
QT_MOC_LITERAL(34, 472, 5), // "index"
QT_MOC_LITERAL(35, 478, 12), // "createThread"
QT_MOC_LITERAL(36, 491, 17), // "initTableStandart"
QT_MOC_LITERAL(37, 509, 18), // "initCategoriesTree"
QT_MOC_LITERAL(38, 528, 12), // "initComments"
QT_MOC_LITERAL(39, 541, 24), // "updateCurrentAchievement"
QT_MOC_LITERAL(40, 566, 16), // "updateHiddenRows"
QT_MOC_LITERAL(41, 583, 21), // "buttonComment_Clicked"
QT_MOC_LITERAL(42, 605, 10), // "createMenu"
QT_MOC_LITERAL(43, 616, 6), // "QMenu*"
QT_MOC_LITERAL(44, 623, 12), // "SAchievement"
QT_MOC_LITERAL(45, 636, 12), // "aAchievement"
QT_MOC_LITERAL(46, 649, 25), // "updateFilterWithMyProfile"
QT_MOC_LITERAL(47, 675, 11), // "ReachedType"
QT_MOC_LITERAL(48, 687, 5), // "aType"
QT_MOC_LITERAL(49, 693, 27), // "updateFilterTextAchievement"
QT_MOC_LITERAL(50, 721, 8), // "aNewText"
QT_MOC_LITERAL(51, 730, 27), // "updateHiddenColumnsStandart"
QT_MOC_LITERAL(52, 758, 20), // "updateFilterCategory"
QT_MOC_LITERAL(53, 779, 13), // "categoryIndex"
QT_MOC_LITERAL(54, 793, 5), // "clear"
QT_MOC_LITERAL(55, 799, 14), // "QList<QString>"
QT_MOC_LITERAL(56, 814, 16), // "achievementNames"
QT_MOC_LITERAL(57, 831, 20), // "updateFilterFavorite"
QT_MOC_LITERAL(58, 852, 26), // "QList<FavoriteAchievement>"
QT_MOC_LITERAL(59, 879, 22), // "aFavoritesAchievements"
QT_MOC_LITERAL(60, 902, 9), // "rowFromId"
QT_MOC_LITERAL(61, 912, 3), // "aId"
QT_MOC_LITERAL(62, 916, 23), // "recursAddCategoryToTree"
QT_MOC_LITERAL(63, 940, 9), // "Category*"
QT_MOC_LITERAL(64, 950, 8), // "category"
QT_MOC_LITERAL(65, 959, 5), // "count"
QT_MOC_LITERAL(66, 965, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(67, 982, 4), // "root"
QT_MOC_LITERAL(68, 987, 21), // "updateCurrentCategory"
QT_MOC_LITERAL(69, 1009, 18), // "createMenuCategory"
QT_MOC_LITERAL(70, 1028, 8), // "Category"
QT_MOC_LITERAL(71, 1037, 9), // "aCategory"
QT_MOC_LITERAL(72, 1047, 14), // "categoryChange"
QT_MOC_LITERAL(73, 1062, 11), // "categoryAdd"
QT_MOC_LITERAL(74, 1074, 14), // "categoryDelete"
QT_MOC_LITERAL(75, 1089, 7), // "loading"
QT_MOC_LITERAL(76, 1097, 10), // "aIsLoading"
QT_MOC_LITERAL(77, 1108, 7), // "getText"
QT_MOC_LITERAL(78, 1116, 4) // "item"

    },
    "FormAchievements\0s_updateSettings\0\0"
    "s_updatedHiddenRows\0progressLoading\0"
    "value\0max\0onModelPulled\0QStandardItemModel*\0"
    "aModel\0reached\0notReached\0getProfileId\0"
    "getGameAppId\0buttonUpdate_Clicked\0"
    "updateSettings\0buttonManual_Clicked\0"
    "changeEvent\0QEvent*\0event\0closeEvent\0"
    "QCloseEvent*\0initComponents\0retranslate\0"
    "setIcons\0showCategories\0"
    "checkBoxCategory_StateChanged\0ind\0"
    "checkBoxFavorites_StateChanged\0arg1\0"
    "buttonFavorite_Clicked\0loadEditCategory\0"
    "loadCompare\0tabWidget_CurrentChanged\0"
    "index\0createThread\0initTableStandart\0"
    "initCategoriesTree\0initComments\0"
    "updateCurrentAchievement\0updateHiddenRows\0"
    "buttonComment_Clicked\0createMenu\0"
    "QMenu*\0SAchievement\0aAchievement\0"
    "updateFilterWithMyProfile\0ReachedType\0"
    "aType\0updateFilterTextAchievement\0"
    "aNewText\0updateHiddenColumnsStandart\0"
    "updateFilterCategory\0categoryIndex\0"
    "clear\0QList<QString>\0achievementNames\0"
    "updateFilterFavorite\0QList<FavoriteAchievement>\0"
    "aFavoritesAchievements\0rowFromId\0aId\0"
    "recursAddCategoryToTree\0Category*\0"
    "category\0count\0QTreeWidgetItem*\0root\0"
    "updateCurrentCategory\0createMenuCategory\0"
    "Category\0aCategory\0categoryChange\0"
    "categoryAdd\0categoryDelete\0loading\0"
    "aIsLoading\0getText\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormAchievements[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  239,    2, 0x06 /* Public */,
       3,    0,  240,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,  241,    2, 0x0a /* Public */,
       7,    3,  246,    2, 0x0a /* Public */,
      12,    0,  253,    2, 0x0a /* Public */,
      13,    0,  254,    2, 0x0a /* Public */,
      14,    0,  255,    2, 0x0a /* Public */,
      15,    0,  256,    2, 0x0a /* Public */,
      16,    0,  257,    2, 0x0a /* Public */,
      17,    1,  258,    2, 0x08 /* Private */,
      20,    1,  261,    2, 0x08 /* Private */,
      22,    0,  264,    2, 0x08 /* Private */,
      23,    0,  265,    2, 0x08 /* Private */,
      24,    0,  266,    2, 0x08 /* Private */,
      25,    0,  267,    2, 0x08 /* Private */,
      26,    1,  268,    2, 0x08 /* Private */,
      28,    1,  271,    2, 0x08 /* Private */,
      30,    0,  274,    2, 0x08 /* Private */,
      31,    0,  275,    2, 0x08 /* Private */,
      32,    0,  276,    2, 0x08 /* Private */,
      33,    1,  277,    2, 0x08 /* Private */,
      35,    0,  280,    2, 0x08 /* Private */,
      36,    0,  281,    2, 0x08 /* Private */,
      37,    0,  282,    2, 0x08 /* Private */,
      38,    0,  283,    2, 0x08 /* Private */,
      39,    0,  284,    2, 0x08 /* Private */,
      40,    0,  285,    2, 0x08 /* Private */,
      41,    0,  286,    2, 0x08 /* Private */,
      42,    1,  287,    2, 0x08 /* Private */,
      46,    1,  290,    2, 0x08 /* Private */,
      49,    1,  293,    2, 0x08 /* Private */,
      51,    0,  296,    2, 0x08 /* Private */,
      52,    3,  297,    2, 0x08 /* Private */,
      52,    2,  304,    2, 0x28 /* Private | MethodCloned */,
      57,    1,  309,    2, 0x08 /* Private */,
      60,    1,  312,    2, 0x08 /* Private */,
      62,    3,  315,    2, 0x08 /* Private */,
      62,    2,  322,    2, 0x28 /* Private | MethodCloned */,
      68,    0,  327,    2, 0x08 /* Private */,
      69,    1,  328,    2, 0x08 /* Private */,
      72,    0,  331,    2, 0x08 /* Private */,
      73,    0,  332,    2, 0x08 /* Private */,
      74,    0,  333,    2, 0x08 /* Private */,
      75,    1,  334,    2, 0x08 /* Private */,
      77,    1,  337,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, QMetaType::Int,    9,   10,   11,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 43, 0x80000000 | 44,   45,
    QMetaType::Void, 0x80000000 | 47,   48,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, 0x80000000 | 55,   53,   54,   56,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   53,   54,
    QMetaType::Void, 0x80000000 | 58,   59,
    QMetaType::Int, QMetaType::QString,   61,
    QMetaType::Int, 0x80000000 | 63, QMetaType::Int, 0x80000000 | 66,   64,   65,   67,
    QMetaType::Int, 0x80000000 | 63, QMetaType::Int,   64,   65,
    QMetaType::Void,
    0x80000000 | 43, 0x80000000 | 70,   71,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   76,
    QMetaType::QString, 0x80000000 | 66,   78,

       0        // eod
};

void FormAchievements::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormAchievements *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_updateSettings(); break;
        case 1: _t->s_updatedHiddenRows(); break;
        case 2: _t->progressLoading((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->onModelPulled((*reinterpret_cast< QStandardItemModel*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: { QString _r = _t->getProfileId();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->getGameAppId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->buttonUpdate_Clicked(); break;
        case 7: _t->updateSettings(); break;
        case 8: _t->buttonManual_Clicked(); break;
        case 9: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 10: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 11: _t->initComponents(); break;
        case 12: _t->retranslate(); break;
        case 13: _t->setIcons(); break;
        case 14: _t->showCategories(); break;
        case 15: _t->checkBoxCategory_StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->checkBoxFavorites_StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->buttonFavorite_Clicked(); break;
        case 18: _t->loadEditCategory(); break;
        case 19: _t->loadCompare(); break;
        case 20: _t->tabWidget_CurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->createThread(); break;
        case 22: _t->initTableStandart(); break;
        case 23: _t->initCategoriesTree(); break;
        case 24: _t->initComments(); break;
        case 25: _t->updateCurrentAchievement(); break;
        case 26: _t->updateHiddenRows(); break;
        case 27: _t->buttonComment_Clicked(); break;
        case 28: { QMenu* _r = _t->createMenu((*reinterpret_cast< const SAchievement(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 29: _t->updateFilterWithMyProfile((*reinterpret_cast< ReachedType(*)>(_a[1]))); break;
        case 30: _t->updateFilterTextAchievement((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->updateHiddenColumnsStandart(); break;
        case 32: _t->updateFilterCategory((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QList<QString>(*)>(_a[3]))); break;
        case 33: _t->updateFilterCategory((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 34: _t->updateFilterFavorite((*reinterpret_cast< const QList<FavoriteAchievement>(*)>(_a[1]))); break;
        case 35: { int _r = _t->rowFromId((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 36: { int _r = _t->recursAddCategoryToTree((*reinterpret_cast< Category*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 37: { int _r = _t->recursAddCategoryToTree((*reinterpret_cast< Category*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 38: _t->updateCurrentCategory(); break;
        case 39: { QMenu* _r = _t->createMenuCategory((*reinterpret_cast< const Category(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 40: _t->categoryChange(); break;
        case 41: _t->categoryAdd(); break;
        case 42: _t->categoryDelete(); break;
        case 43: _t->loading((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: { QString _r = _t->getText((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormAchievements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAchievements::s_updateSettings)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormAchievements::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAchievements::s_updatedHiddenRows)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormAchievements::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormAchievements.data,
    qt_meta_data_FormAchievements,
    qt_static_metacall,
    nullptr,
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
    return QWidget::qt_metacast(_clname);
}

int FormAchievements::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    }
    return _id;
}

// SIGNAL 0
void FormAchievements::s_updateSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormAchievements::s_updatedHiddenRows()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
