/****************************************************************************
** Meta object code from reading C++ file 'formfriends.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/subForms/main/formfriends.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formfriends.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormFriends_t {
    QByteArrayData data[62];
    char stringdata0[825];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormFriends_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormFriends_t qt_meta_stringdata_FormFriends = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FormFriends"
QT_MOC_LITERAL(1, 12, 15), // "s_friendsLoaded"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "progress"
QT_MOC_LITERAL(4, 38, 8), // "s_finish"
QT_MOC_LITERAL(5, 47, 17), // "s_returnToProfile"
QT_MOC_LITERAL(6, 65, 8), // "QWidget*"
QT_MOC_LITERAL(7, 74, 13), // "s_goToProfile"
QT_MOC_LITERAL(8, 88, 2), // "id"
QT_MOC_LITERAL(9, 91, 19), // "SProfileRequestType"
QT_MOC_LITERAL(10, 111, 4), // "type"
QT_MOC_LITERAL(11, 116, 14), // "updateSettings"
QT_MOC_LITERAL(12, 131, 10), // "setFriends"
QT_MOC_LITERAL(13, 142, 3), // "aId"
QT_MOC_LITERAL(14, 146, 15), // "QList<SFriend>&"
QT_MOC_LITERAL(15, 162, 8), // "aFriends"
QT_MOC_LITERAL(16, 171, 5), // "clear"
QT_MOC_LITERAL(17, 177, 6), // "isInit"
QT_MOC_LITERAL(18, 184, 8), // "isLoaded"
QT_MOC_LITERAL(19, 193, 4), // "init"
QT_MOC_LITERAL(20, 198, 11), // "initFriends"
QT_MOC_LITERAL(21, 210, 9), // "initTable"
QT_MOC_LITERAL(22, 220, 18), // "initComboBoxStatus"
QT_MOC_LITERAL(23, 239, 12), // "createThread"
QT_MOC_LITERAL(24, 252, 13), // "setTableModel"
QT_MOC_LITERAL(25, 266, 19), // "QStandardItemModel*"
QT_MOC_LITERAL(26, 286, 6), // "aModel"
QT_MOC_LITERAL(27, 293, 11), // "changeEvent"
QT_MOC_LITERAL(28, 305, 7), // "QEvent*"
QT_MOC_LITERAL(29, 313, 5), // "event"
QT_MOC_LITERAL(30, 319, 10), // "closeEvent"
QT_MOC_LITERAL(31, 330, 12), // "QCloseEvent*"
QT_MOC_LITERAL(32, 343, 11), // "retranslate"
QT_MOC_LITERAL(33, 355, 8), // "setIcons"
QT_MOC_LITERAL(34, 364, 16), // "updateHiddenRows"
QT_MOC_LITERAL(35, 381, 19), // "updateCurrentFriend"
QT_MOC_LITERAL(36, 401, 16), // "getFriendFromRow"
QT_MOC_LITERAL(37, 418, 24), // "QPair<SFriend,SProfile>*"
QT_MOC_LITERAL(38, 443, 4), // "aRow"
QT_MOC_LITERAL(39, 448, 21), // "getCurrentFriendIndex"
QT_MOC_LITERAL(40, 470, 21), // "getIndexFriendFromRow"
QT_MOC_LITERAL(41, 492, 21), // "getRowFromIndexFriend"
QT_MOC_LITERAL(42, 514, 6), // "aIndex"
QT_MOC_LITERAL(43, 521, 17), // "isProfileFavorite"
QT_MOC_LITERAL(44, 539, 23), // "QPair<SFriend,SProfile>"
QT_MOC_LITERAL(45, 563, 8), // "aProfile"
QT_MOC_LITERAL(46, 572, 10), // "createMenu"
QT_MOC_LITERAL(47, 583, 6), // "QMenu*"
QT_MOC_LITERAL(48, 590, 7), // "profile"
QT_MOC_LITERAL(49, 598, 24), // "updateActionFavoriteData"
QT_MOC_LITERAL(50, 623, 8), // "QAction*"
QT_MOC_LITERAL(51, 632, 7), // "aAction"
QT_MOC_LITERAL(52, 640, 11), // "aIsFavorite"
QT_MOC_LITERAL(53, 652, 11), // "goToProfile"
QT_MOC_LITERAL(54, 664, 16), // "friendToFavorite"
QT_MOC_LITERAL(55, 681, 32), // "checkBoxOpenProfile_StateChanged"
QT_MOC_LITERAL(56, 714, 4), // "arg1"
QT_MOC_LITERAL(57, 719, 24), // "lineEditName_TextChanged"
QT_MOC_LITERAL(58, 744, 18), // "buttonFind_Clicked"
QT_MOC_LITERAL(59, 763, 24), // "comboBoxStatus_Activated"
QT_MOC_LITERAL(60, 788, 5), // "index"
QT_MOC_LITERAL(61, 794, 30) // "checkBoxFavorites_StateChanged"

    },
    "FormFriends\0s_friendsLoaded\0\0progress\0"
    "s_finish\0s_returnToProfile\0QWidget*\0"
    "s_goToProfile\0id\0SProfileRequestType\0"
    "type\0updateSettings\0setFriends\0aId\0"
    "QList<SFriend>&\0aFriends\0clear\0isInit\0"
    "isLoaded\0init\0initFriends\0initTable\0"
    "initComboBoxStatus\0createThread\0"
    "setTableModel\0QStandardItemModel*\0"
    "aModel\0changeEvent\0QEvent*\0event\0"
    "closeEvent\0QCloseEvent*\0retranslate\0"
    "setIcons\0updateHiddenRows\0updateCurrentFriend\0"
    "getFriendFromRow\0QPair<SFriend,SProfile>*\0"
    "aRow\0getCurrentFriendIndex\0"
    "getIndexFriendFromRow\0getRowFromIndexFriend\0"
    "aIndex\0isProfileFavorite\0"
    "QPair<SFriend,SProfile>\0aProfile\0"
    "createMenu\0QMenu*\0profile\0"
    "updateActionFavoriteData\0QAction*\0"
    "aAction\0aIsFavorite\0goToProfile\0"
    "friendToFavorite\0checkBoxOpenProfile_StateChanged\0"
    "arg1\0lineEditName_TextChanged\0"
    "buttonFind_Clicked\0comboBoxStatus_Activated\0"
    "index\0checkBoxFavorites_StateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormFriends[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  189,    2, 0x06 /* Public */,
       4,    0,  192,    2, 0x06 /* Public */,
       5,    1,  193,    2, 0x06 /* Public */,
       7,    2,  196,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  201,    2, 0x0a /* Public */,
      12,    2,  202,    2, 0x0a /* Public */,
      16,    0,  207,    2, 0x0a /* Public */,
      17,    0,  208,    2, 0x0a /* Public */,
      18,    0,  209,    2, 0x0a /* Public */,
      19,    0,  210,    2, 0x08 /* Private */,
      20,    1,  211,    2, 0x08 /* Private */,
      21,    0,  214,    2, 0x08 /* Private */,
      22,    0,  215,    2, 0x08 /* Private */,
      23,    0,  216,    2, 0x08 /* Private */,
      24,    1,  217,    2, 0x08 /* Private */,
      27,    1,  220,    2, 0x08 /* Private */,
      30,    1,  223,    2, 0x08 /* Private */,
      32,    0,  226,    2, 0x08 /* Private */,
      33,    0,  227,    2, 0x08 /* Private */,
      34,    0,  228,    2, 0x08 /* Private */,
      35,    0,  229,    2, 0x08 /* Private */,
      36,    1,  230,    2, 0x08 /* Private */,
      39,    0,  233,    2, 0x08 /* Private */,
      40,    1,  234,    2, 0x08 /* Private */,
      41,    1,  237,    2, 0x08 /* Private */,
      43,    1,  240,    2, 0x08 /* Private */,
      46,    1,  243,    2, 0x08 /* Private */,
      49,    2,  246,    2, 0x08 /* Private */,
      53,    0,  251,    2, 0x08 /* Private */,
      54,    0,  252,    2, 0x08 /* Private */,
      55,    1,  253,    2, 0x08 /* Private */,
      57,    1,  256,    2, 0x08 /* Private */,
      58,    0,  259,    2, 0x08 /* Private */,
      59,    1,  260,    2, 0x08 /* Private */,
      61,    1,  263,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    8,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 14,   13,   15,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 31,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 37, QMetaType::Int,   38,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Int,   38,
    QMetaType::Int, QMetaType::Int,   42,
    QMetaType::Bool, 0x80000000 | 44,   45,
    0x80000000 | 47, 0x80000000 | 44,   48,
    QMetaType::Void, 0x80000000 | 50, QMetaType::Bool,   51,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   56,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void, QMetaType::Int,   56,

       0        // eod
};

void FormFriends::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormFriends *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_friendsLoaded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->s_finish(); break;
        case 2: _t->s_returnToProfile((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 3: _t->s_goToProfile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< SProfileRequestType(*)>(_a[2]))); break;
        case 4: _t->updateSettings(); break;
        case 5: _t->setFriends((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QList<SFriend>(*)>(_a[2]))); break;
        case 6: _t->clear(); break;
        case 7: { bool _r = _t->isInit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->isLoaded();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->init(); break;
        case 10: _t->initFriends((*reinterpret_cast< QList<SFriend>(*)>(_a[1]))); break;
        case 11: _t->initTable(); break;
        case 12: _t->initComboBoxStatus(); break;
        case 13: _t->createThread(); break;
        case 14: _t->setTableModel((*reinterpret_cast< QStandardItemModel*(*)>(_a[1]))); break;
        case 15: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 16: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 17: _t->retranslate(); break;
        case 18: _t->setIcons(); break;
        case 19: _t->updateHiddenRows(); break;
        case 20: _t->updateCurrentFriend(); break;
        case 21: { QPair<SFriend,SProfile>* _r = _t->getFriendFromRow((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPair<SFriend,SProfile>**>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->getCurrentFriendIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: { int _r = _t->getIndexFriendFromRow((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 24: { int _r = _t->getRowFromIndexFriend((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->isProfileFavorite((*reinterpret_cast< const QPair<SFriend,SProfile>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 26: { QMenu* _r = _t->createMenu((*reinterpret_cast< const QPair<SFriend,SProfile>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 27: _t->updateActionFavoriteData((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 28: _t->goToProfile(); break;
        case 29: _t->friendToFavorite(); break;
        case 30: _t->checkBoxOpenProfile_StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->lineEditName_TextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->buttonFind_Clicked(); break;
        case 33: _t->comboBoxStatus_Activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->checkBoxFavorites_StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormFriends::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFriends::s_friendsLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormFriends::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFriends::s_finish)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FormFriends::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFriends::s_returnToProfile)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FormFriends::*)(const QString & , SProfileRequestType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormFriends::s_goToProfile)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormFriends::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormFriends.data,
    qt_meta_data_FormFriends,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormFriends::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormFriends::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormFriends.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormFriends::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void FormFriends::s_friendsLoaded(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormFriends::s_finish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FormFriends::s_returnToProfile(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FormFriends::s_goToProfile(const QString & _t1, SProfileRequestType _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
