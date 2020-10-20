/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[73];
    char stringdata0[1043];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "s_updateSettings"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "progressLoading"
QT_MOC_LITERAL(4, 45, 15), // "addAchievements"
QT_MOC_LITERAL(5, 61, 20), // "SAchievementsPlayer&"
QT_MOC_LITERAL(6, 82, 12), // "achievements"
QT_MOC_LITERAL(7, 95, 6), // "SGame&"
QT_MOC_LITERAL(8, 102, 5), // "games"
QT_MOC_LITERAL(9, 108, 18), // "removeAchievements"
QT_MOC_LITERAL(10, 127, 5), // "index"
QT_MOC_LITERAL(11, 133, 26), // "containerAchievementsClose"
QT_MOC_LITERAL(12, 160, 22), // "returnFromAchievements"
QT_MOC_LITERAL(13, 183, 3), // "num"
QT_MOC_LITERAL(14, 187, 9), // "goToGames"
QT_MOC_LITERAL(15, 197, 9), // "SProfile&"
QT_MOC_LITERAL(16, 207, 14), // "profileSteamid"
QT_MOC_LITERAL(17, 222, 7), // "SGames&"
QT_MOC_LITERAL(18, 230, 11), // "goToFriends"
QT_MOC_LITERAL(19, 242, 9), // "SFriends&"
QT_MOC_LITERAL(20, 252, 7), // "friends"
QT_MOC_LITERAL(21, 260, 13), // "goToFavorites"
QT_MOC_LITERAL(22, 274, 14), // "goToStatistics"
QT_MOC_LITERAL(23, 289, 11), // "profileName"
QT_MOC_LITERAL(24, 301, 14), // "updateSettings"
QT_MOC_LITERAL(25, 316, 17), // "createFormProfile"
QT_MOC_LITERAL(26, 334, 12), // "FormProfile*"
QT_MOC_LITERAL(27, 347, 8), // "aProfile"
QT_MOC_LITERAL(28, 356, 15), // "createFormGames"
QT_MOC_LITERAL(29, 372, 10), // "FormGames*"
QT_MOC_LITERAL(30, 383, 6), // "aGames"
QT_MOC_LITERAL(31, 390, 17), // "createFormFriends"
QT_MOC_LITERAL(32, 408, 12), // "FormFriends*"
QT_MOC_LITERAL(33, 421, 3), // "aId"
QT_MOC_LITERAL(34, 425, 8), // "aFriends"
QT_MOC_LITERAL(35, 434, 19), // "createFormFavorites"
QT_MOC_LITERAL(36, 454, 14), // "FormFavorites*"
QT_MOC_LITERAL(37, 469, 20), // "createFormStatistics"
QT_MOC_LITERAL(38, 490, 15), // "FormStatistics*"
QT_MOC_LITERAL(39, 506, 5), // "aName"
QT_MOC_LITERAL(40, 512, 18), // "createFormSettings"
QT_MOC_LITERAL(41, 531, 13), // "FormSettings*"
QT_MOC_LITERAL(42, 545, 31), // "createFormContainerAchievements"
QT_MOC_LITERAL(43, 577, 26), // "FormContainerAchievements*"
QT_MOC_LITERAL(44, 604, 13), // "keyPressEvent"
QT_MOC_LITERAL(45, 618, 10), // "QKeyEvent*"
QT_MOC_LITERAL(46, 629, 11), // "changeEvent"
QT_MOC_LITERAL(47, 641, 7), // "QEvent*"
QT_MOC_LITERAL(48, 649, 10), // "closeEvent"
QT_MOC_LITERAL(49, 660, 12), // "QCloseEvent*"
QT_MOC_LITERAL(50, 673, 8), // "showForm"
QT_MOC_LITERAL(51, 682, 11), // "widgetIndex"
QT_MOC_LITERAL(52, 694, 11), // "widthWindow"
QT_MOC_LITERAL(53, 706, 15), // "returnFromForms"
QT_MOC_LITERAL(54, 722, 14), // "initComponents"
QT_MOC_LITERAL(55, 737, 8), // "getTheme"
QT_MOC_LITERAL(56, 746, 8), // "setIcons"
QT_MOC_LITERAL(57, 755, 16), // "resizeScrollArea"
QT_MOC_LITERAL(58, 772, 5), // "width"
QT_MOC_LITERAL(59, 778, 28), // "updateEnabledButtonsBackNext"
QT_MOC_LITERAL(60, 807, 22), // "buttonMaximize_Clicked"
QT_MOC_LITERAL(61, 830, 22), // "buttonMinimize_Clicked"
QT_MOC_LITERAL(62, 853, 25), // "buttonFindProfile_Clicked"
QT_MOC_LITERAL(63, 879, 11), // "goToProfile"
QT_MOC_LITERAL(64, 891, 2), // "id"
QT_MOC_LITERAL(65, 894, 14), // "ProfileUrlType"
QT_MOC_LITERAL(66, 909, 4), // "type"
QT_MOC_LITERAL(67, 914, 22), // "buttonSettings_Clicked"
QT_MOC_LITERAL(68, 937, 18), // "buttonExit_Clicked"
QT_MOC_LITERAL(69, 956, 27), // "buttonGoToMyProfile_Clicked"
QT_MOC_LITERAL(70, 984, 18), // "buttonBack_Clicked"
QT_MOC_LITERAL(71, 1003, 18), // "buttonNext_Clicked"
QT_MOC_LITERAL(72, 1022, 20) // "buttonUpdate_Clicked"

    },
    "MainWindow\0s_updateSettings\0\0"
    "progressLoading\0addAchievements\0"
    "SAchievementsPlayer&\0achievements\0"
    "SGame&\0games\0removeAchievements\0index\0"
    "containerAchievementsClose\0"
    "returnFromAchievements\0num\0goToGames\0"
    "SProfile&\0profileSteamid\0SGames&\0"
    "goToFriends\0SFriends&\0friends\0"
    "goToFavorites\0goToStatistics\0profileName\0"
    "updateSettings\0createFormProfile\0"
    "FormProfile*\0aProfile\0createFormGames\0"
    "FormGames*\0aGames\0createFormFriends\0"
    "FormFriends*\0aId\0aFriends\0createFormFavorites\0"
    "FormFavorites*\0createFormStatistics\0"
    "FormStatistics*\0aName\0createFormSettings\0"
    "FormSettings*\0createFormContainerAchievements\0"
    "FormContainerAchievements*\0keyPressEvent\0"
    "QKeyEvent*\0changeEvent\0QEvent*\0"
    "closeEvent\0QCloseEvent*\0showForm\0"
    "widgetIndex\0widthWindow\0returnFromForms\0"
    "initComponents\0getTheme\0setIcons\0"
    "resizeScrollArea\0width\0"
    "updateEnabledButtonsBackNext\0"
    "buttonMaximize_Clicked\0buttonMinimize_Clicked\0"
    "buttonFindProfile_Clicked\0goToProfile\0"
    "id\0ProfileUrlType\0type\0buttonSettings_Clicked\0"
    "buttonExit_Clicked\0buttonGoToMyProfile_Clicked\0"
    "buttonBack_Clicked\0buttonNext_Clicked\0"
    "buttonUpdate_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  214,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,  215,    2, 0x0a /* Public */,
       4,    2,  220,    2, 0x0a /* Public */,
       9,    1,  225,    2, 0x0a /* Public */,
      11,    0,  228,    2, 0x0a /* Public */,
      12,    1,  229,    2, 0x0a /* Public */,
      14,    2,  232,    2, 0x0a /* Public */,
      18,    2,  237,    2, 0x0a /* Public */,
      21,    0,  242,    2, 0x0a /* Public */,
      22,    3,  243,    2, 0x0a /* Public */,
      24,    0,  250,    2, 0x0a /* Public */,
      25,    1,  251,    2, 0x0a /* Public */,
      28,    2,  254,    2, 0x0a /* Public */,
      31,    2,  259,    2, 0x0a /* Public */,
      35,    0,  264,    2, 0x0a /* Public */,
      37,    3,  265,    2, 0x0a /* Public */,
      40,    0,  272,    2, 0x0a /* Public */,
      42,    0,  273,    2, 0x0a /* Public */,
      44,    1,  274,    2, 0x08 /* Private */,
      46,    1,  277,    2, 0x08 /* Private */,
      48,    1,  280,    2, 0x08 /* Private */,
      50,    2,  283,    2, 0x08 /* Private */,
      50,    1,  288,    2, 0x28 /* Private | MethodCloned */,
      53,    0,  291,    2, 0x08 /* Private */,
      54,    0,  292,    2, 0x08 /* Private */,
      55,    0,  293,    2, 0x08 /* Private */,
      56,    0,  294,    2, 0x08 /* Private */,
      57,    1,  295,    2, 0x08 /* Private */,
      57,    0,  298,    2, 0x28 /* Private | MethodCloned */,
      59,    0,  299,    2, 0x08 /* Private */,
      60,    0,  300,    2, 0x08 /* Private */,
      61,    0,  301,    2, 0x08 /* Private */,
      62,    0,  302,    2, 0x08 /* Private */,
      63,    2,  303,    2, 0x08 /* Private */,
      67,    0,  308,    2, 0x08 /* Private */,
      68,    0,  309,    2, 0x08 /* Private */,
      69,    0,  310,    2, 0x08 /* Private */,
      70,    0,  311,    2, 0x08 /* Private */,
      71,    0,  312,    2, 0x08 /* Private */,
      72,    0,  313,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,    8,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 19,   16,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 17, QMetaType::QString,   16,    8,   23,
    QMetaType::Void,
    0x80000000 | 26, 0x80000000 | 15,   27,
    0x80000000 | 29, 0x80000000 | 15, 0x80000000 | 17,   27,   30,
    0x80000000 | 32, QMetaType::QString, 0x80000000 | 19,   33,   34,
    0x80000000 | 36,
    0x80000000 | 38, QMetaType::QString, 0x80000000 | 17, QMetaType::QString,   33,   30,   39,
    0x80000000 | 41,
    0x80000000 | 43,
    QMetaType::Void, 0x80000000 | 45,    2,
    QMetaType::Void, 0x80000000 | 47,    2,
    QMetaType::Void, 0x80000000 | 49,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   51,   52,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   58,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 65,   64,   66,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_updateSettings(); break;
        case 1: _t->progressLoading((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->addAchievements((*reinterpret_cast< SAchievementsPlayer(*)>(_a[1])),(*reinterpret_cast< SGame(*)>(_a[2]))); break;
        case 3: _t->removeAchievements((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->containerAchievementsClose(); break;
        case 5: _t->returnFromAchievements((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->goToGames((*reinterpret_cast< SProfile(*)>(_a[1])),(*reinterpret_cast< SGames(*)>(_a[2]))); break;
        case 7: _t->goToFriends((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< SFriends(*)>(_a[2]))); break;
        case 8: _t->goToFavorites(); break;
        case 9: _t->goToStatistics((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< SGames(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 10: _t->updateSettings(); break;
        case 11: { FormProfile* _r = _t->createFormProfile((*reinterpret_cast< SProfile(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< FormProfile**>(_a[0]) = std::move(_r); }  break;
        case 12: { FormGames* _r = _t->createFormGames((*reinterpret_cast< SProfile(*)>(_a[1])),(*reinterpret_cast< SGames(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< FormGames**>(_a[0]) = std::move(_r); }  break;
        case 13: { FormFriends* _r = _t->createFormFriends((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< SFriends(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< FormFriends**>(_a[0]) = std::move(_r); }  break;
        case 14: { FormFavorites* _r = _t->createFormFavorites();
            if (_a[0]) *reinterpret_cast< FormFavorites**>(_a[0]) = std::move(_r); }  break;
        case 15: { FormStatistics* _r = _t->createFormStatistics((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< SGames(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< FormStatistics**>(_a[0]) = std::move(_r); }  break;
        case 16: { FormSettings* _r = _t->createFormSettings();
            if (_a[0]) *reinterpret_cast< FormSettings**>(_a[0]) = std::move(_r); }  break;
        case 17: { FormContainerAchievements* _r = _t->createFormContainerAchievements();
            if (_a[0]) *reinterpret_cast< FormContainerAchievements**>(_a[0]) = std::move(_r); }  break;
        case 18: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 19: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 20: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 21: _t->showForm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 22: _t->showForm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->returnFromForms(); break;
        case 24: _t->initComponents(); break;
        case 25: { QString _r = _t->getTheme();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->setIcons(); break;
        case 27: _t->resizeScrollArea((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->resizeScrollArea(); break;
        case 29: _t->updateEnabledButtonsBackNext(); break;
        case 30: _t->buttonMaximize_Clicked(); break;
        case 31: _t->buttonMinimize_Clicked(); break;
        case 32: _t->buttonFindProfile_Clicked(); break;
        case 33: _t->goToProfile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ProfileUrlType(*)>(_a[2]))); break;
        case 34: _t->buttonSettings_Clicked(); break;
        case 35: _t->buttonExit_Clicked(); break;
        case 36: _t->buttonGoToMyProfile_Clicked(); break;
        case 37: _t->buttonBack_Clicked(); break;
        case 38: _t->buttonNext_Clicked(); break;
        case 39: _t->buttonUpdate_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::s_updateSettings)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 40;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::s_updateSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
