/****************************************************************************
** Meta object code from reading C++ file 'formmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/formmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormMain_t {
    QByteArrayData data[56];
    char stringdata0[814];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormMain_t qt_meta_stringdata_FormMain = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FormMain"
QT_MOC_LITERAL(1, 9, 16), // "s_updateSettings"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "addAchievements"
QT_MOC_LITERAL(4, 43, 25), // "QList<SAchievementPlayer>"
QT_MOC_LITERAL(5, 69, 12), // "achievements"
QT_MOC_LITERAL(6, 82, 5), // "SGame"
QT_MOC_LITERAL(7, 88, 5), // "games"
QT_MOC_LITERAL(8, 94, 18), // "removeAchievements"
QT_MOC_LITERAL(9, 113, 5), // "index"
QT_MOC_LITERAL(10, 119, 26), // "containerAchievementsClose"
QT_MOC_LITERAL(11, 146, 9), // "goToGames"
QT_MOC_LITERAL(12, 156, 9), // "SProfile&"
QT_MOC_LITERAL(13, 166, 14), // "profileSteamid"
QT_MOC_LITERAL(14, 181, 13), // "QList<SGame>&"
QT_MOC_LITERAL(15, 195, 11), // "goToFriends"
QT_MOC_LITERAL(16, 207, 15), // "QList<SFriend>&"
QT_MOC_LITERAL(17, 223, 7), // "friends"
QT_MOC_LITERAL(18, 231, 13), // "goToFavorites"
QT_MOC_LITERAL(19, 245, 14), // "goToStatistics"
QT_MOC_LITERAL(20, 260, 8), // "SProfile"
QT_MOC_LITERAL(21, 269, 17), // "createFormProfile"
QT_MOC_LITERAL(22, 287, 12), // "FormProfile*"
QT_MOC_LITERAL(23, 300, 8), // "aProfile"
QT_MOC_LITERAL(24, 309, 20), // "createFormStatistics"
QT_MOC_LITERAL(25, 330, 15), // "FormStatistics*"
QT_MOC_LITERAL(26, 346, 6), // "aGames"
QT_MOC_LITERAL(27, 353, 31), // "createFormContainerAchievements"
QT_MOC_LITERAL(28, 385, 26), // "FormContainerAchievements*"
QT_MOC_LITERAL(29, 412, 13), // "keyPressEvent"
QT_MOC_LITERAL(30, 426, 10), // "QKeyEvent*"
QT_MOC_LITERAL(31, 437, 10), // "closeEvent"
QT_MOC_LITERAL(32, 448, 12), // "QCloseEvent*"
QT_MOC_LITERAL(33, 461, 8), // "showForm"
QT_MOC_LITERAL(34, 470, 11), // "widgetIndex"
QT_MOC_LITERAL(35, 482, 11), // "widthWindow"
QT_MOC_LITERAL(36, 494, 13), // "aWindowHeight"
QT_MOC_LITERAL(37, 508, 15), // "returnFromForms"
QT_MOC_LITERAL(38, 524, 11), // "retranslate"
QT_MOC_LITERAL(39, 536, 11), // "updateIcons"
QT_MOC_LITERAL(40, 548, 14), // "updateSettings"
QT_MOC_LITERAL(41, 563, 14), // "initComponents"
QT_MOC_LITERAL(42, 578, 16), // "resizeScrollArea"
QT_MOC_LITERAL(43, 595, 5), // "width"
QT_MOC_LITERAL(44, 601, 7), // "aHeight"
QT_MOC_LITERAL(45, 609, 28), // "updateEnabledButtonsBackNext"
QT_MOC_LITERAL(46, 638, 25), // "buttonFindProfile_Clicked"
QT_MOC_LITERAL(47, 664, 11), // "goToProfile"
QT_MOC_LITERAL(48, 676, 2), // "id"
QT_MOC_LITERAL(49, 679, 19), // "SProfileRequestType"
QT_MOC_LITERAL(50, 699, 4), // "type"
QT_MOC_LITERAL(51, 704, 22), // "buttonSettings_Clicked"
QT_MOC_LITERAL(52, 727, 27), // "buttonGoToMyProfile_Clicked"
QT_MOC_LITERAL(53, 755, 18), // "buttonBack_Clicked"
QT_MOC_LITERAL(54, 774, 18), // "buttonNext_Clicked"
QT_MOC_LITERAL(55, 793, 20) // "buttonUpdate_Clicked"

    },
    "FormMain\0s_updateSettings\0\0addAchievements\0"
    "QList<SAchievementPlayer>\0achievements\0"
    "SGame\0games\0removeAchievements\0index\0"
    "containerAchievementsClose\0goToGames\0"
    "SProfile&\0profileSteamid\0QList<SGame>&\0"
    "goToFriends\0QList<SFriend>&\0friends\0"
    "goToFavorites\0goToStatistics\0SProfile\0"
    "createFormProfile\0FormProfile*\0aProfile\0"
    "createFormStatistics\0FormStatistics*\0"
    "aGames\0createFormContainerAchievements\0"
    "FormContainerAchievements*\0keyPressEvent\0"
    "QKeyEvent*\0closeEvent\0QCloseEvent*\0"
    "showForm\0widgetIndex\0widthWindow\0"
    "aWindowHeight\0returnFromForms\0retranslate\0"
    "updateIcons\0updateSettings\0initComponents\0"
    "resizeScrollArea\0width\0aHeight\0"
    "updateEnabledButtonsBackNext\0"
    "buttonFindProfile_Clicked\0goToProfile\0"
    "id\0SProfileRequestType\0type\0"
    "buttonSettings_Clicked\0"
    "buttonGoToMyProfile_Clicked\0"
    "buttonBack_Clicked\0buttonNext_Clicked\0"
    "buttonUpdate_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormMain[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  174,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,  175,    2, 0x0a /* Public */,
       8,    1,  180,    2, 0x0a /* Public */,
      10,    0,  183,    2, 0x0a /* Public */,
      11,    2,  184,    2, 0x0a /* Public */,
      15,    2,  189,    2, 0x0a /* Public */,
      18,    0,  194,    2, 0x0a /* Public */,
      19,    2,  195,    2, 0x0a /* Public */,
      21,    1,  200,    2, 0x0a /* Public */,
      24,    2,  203,    2, 0x0a /* Public */,
      27,    0,  208,    2, 0x0a /* Public */,
      29,    1,  209,    2, 0x08 /* Private */,
      31,    1,  212,    2, 0x08 /* Private */,
      33,    3,  215,    2, 0x08 /* Private */,
      33,    2,  222,    2, 0x28 /* Private | MethodCloned */,
      33,    1,  227,    2, 0x28 /* Private | MethodCloned */,
      37,    0,  230,    2, 0x08 /* Private */,
      38,    0,  231,    2, 0x08 /* Private */,
      39,    0,  232,    2, 0x08 /* Private */,
      40,    0,  233,    2, 0x08 /* Private */,
      41,    0,  234,    2, 0x08 /* Private */,
      42,    2,  235,    2, 0x08 /* Private */,
      42,    1,  240,    2, 0x28 /* Private | MethodCloned */,
      42,    0,  243,    2, 0x28 /* Private | MethodCloned */,
      45,    0,  244,    2, 0x08 /* Private */,
      46,    0,  245,    2, 0x08 /* Private */,
      47,    2,  246,    2, 0x08 /* Private */,
      51,    0,  251,    2, 0x08 /* Private */,
      52,    0,  252,    2, 0x08 /* Private */,
      53,    0,  253,    2, 0x08 /* Private */,
      54,    0,  254,    2, 0x08 /* Private */,
      55,    0,  255,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 16,   13,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 14,   13,    7,
    0x80000000 | 22, 0x80000000 | 12,   23,
    0x80000000 | 25, 0x80000000 | 20, 0x80000000 | 14,   23,   26,
    0x80000000 | 28,
    QMetaType::Void, 0x80000000 | 30,    2,
    QMetaType::Void, 0x80000000 | 32,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   34,   35,   36,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   34,   35,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   43,   44,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 49,   48,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_updateSettings(); break;
        case 1: _t->addAchievements((*reinterpret_cast< QList<SAchievementPlayer>(*)>(_a[1])),(*reinterpret_cast< SGame(*)>(_a[2]))); break;
        case 2: _t->removeAchievements((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->containerAchievementsClose(); break;
        case 4: _t->goToGames((*reinterpret_cast< SProfile(*)>(_a[1])),(*reinterpret_cast< QList<SGame>(*)>(_a[2]))); break;
        case 5: _t->goToFriends((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QList<SFriend>(*)>(_a[2]))); break;
        case 6: _t->goToFavorites(); break;
        case 7: _t->goToStatistics((*reinterpret_cast< const SProfile(*)>(_a[1])),(*reinterpret_cast< QList<SGame>(*)>(_a[2]))); break;
        case 8: { FormProfile* _r = _t->createFormProfile((*reinterpret_cast< SProfile(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< FormProfile**>(_a[0]) = std::move(_r); }  break;
        case 9: { FormStatistics* _r = _t->createFormStatistics((*reinterpret_cast< const SProfile(*)>(_a[1])),(*reinterpret_cast< QList<SGame>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< FormStatistics**>(_a[0]) = std::move(_r); }  break;
        case 10: { FormContainerAchievements* _r = _t->createFormContainerAchievements();
            if (_a[0]) *reinterpret_cast< FormContainerAchievements**>(_a[0]) = std::move(_r); }  break;
        case 11: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 12: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 13: _t->showForm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->showForm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->showForm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->returnFromForms(); break;
        case 17: _t->retranslate(); break;
        case 18: _t->updateIcons(); break;
        case 19: _t->updateSettings(); break;
        case 20: _t->initComponents(); break;
        case 21: _t->resizeScrollArea((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 22: _t->resizeScrollArea((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->resizeScrollArea(); break;
        case 24: _t->updateEnabledButtonsBackNext(); break;
        case 25: _t->buttonFindProfile_Clicked(); break;
        case 26: _t->goToProfile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< SProfileRequestType(*)>(_a[2]))); break;
        case 27: _t->buttonSettings_Clicked(); break;
        case 28: _t->buttonGoToMyProfile_Clicked(); break;
        case 29: _t->buttonBack_Clicked(); break;
        case 30: _t->buttonNext_Clicked(); break;
        case 31: _t->buttonUpdate_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormMain::s_updateSettings)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormMain::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormMain.data,
    qt_meta_data_FormMain,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormMain.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void FormMain::s_updateSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
