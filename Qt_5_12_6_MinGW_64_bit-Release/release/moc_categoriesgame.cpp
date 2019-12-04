/****************************************************************************
** Meta object code from reading C++ file 'categoriesgame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/class/categoriesgame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'categoriesgame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CategoriesGame_t {
    QByteArrayData data[21];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CategoriesGame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CategoriesGame_t qt_meta_stringdata_CategoriesGame = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CategoriesGame"
QT_MOC_LITERAL(1, 15, 9), // "GetTitles"
QT_MOC_LITERAL(2, 25, 14), // "QList<QString>"
QT_MOC_LITERAL(3, 40, 0), // ""
QT_MOC_LITERAL(4, 41, 14), // "GetCountValues"
QT_MOC_LITERAL(5, 56, 16), // "GetCountNoValues"
QT_MOC_LITERAL(6, 73, 8), // "GetTitle"
QT_MOC_LITERAL(7, 82, 5), // "index"
QT_MOC_LITERAL(8, 88, 13), // "GetIsNoValues"
QT_MOC_LITERAL(9, 102, 9), // "GetValues"
QT_MOC_LITERAL(10, 112, 11), // "GetNoValues"
QT_MOC_LITERAL(11, 124, 19), // "GetAchievementsName"
QT_MOC_LITERAL(12, 144, 8), // "category"
QT_MOC_LITERAL(13, 153, 5), // "value"
QT_MOC_LITERAL(14, 159, 7), // "GetGame"
QT_MOC_LITERAL(15, 167, 9), // "GetGameID"
QT_MOC_LITERAL(16, 177, 14), // "DeleteCategory"
QT_MOC_LITERAL(17, 192, 3), // "Set"
QT_MOC_LITERAL(18, 196, 5), // "SGame"
QT_MOC_LITERAL(19, 202, 4), // "game"
QT_MOC_LITERAL(20, 207, 4) // "Save"

    },
    "CategoriesGame\0GetTitles\0QList<QString>\0"
    "\0GetCountValues\0GetCountNoValues\0"
    "GetTitle\0index\0GetIsNoValues\0GetValues\0"
    "GetNoValues\0GetAchievementsName\0"
    "category\0value\0GetGame\0GetGameID\0"
    "DeleteCategory\0Set\0SGame\0game\0Save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CategoriesGame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    3, 0x0a /* Public */,
       4,    0,   80,    3, 0x0a /* Public */,
       5,    0,   81,    3, 0x0a /* Public */,
       6,    1,   82,    3, 0x0a /* Public */,
       8,    1,   85,    3, 0x0a /* Public */,
       9,    1,   88,    3, 0x0a /* Public */,
      10,    1,   91,    3, 0x0a /* Public */,
      11,    2,   94,    3, 0x0a /* Public */,
      14,    0,   99,    3, 0x0a /* Public */,
      15,    0,  100,    3, 0x0a /* Public */,
      16,    1,  101,    3, 0x0a /* Public */,
      17,    1,  104,    3, 0x0a /* Public */,
      20,    0,  107,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    7,
    QMetaType::Int, QMetaType::Int,    7,
    QMetaType::QJsonArray, QMetaType::Int,    7,
    QMetaType::QJsonArray, QMetaType::Int,    7,
    0x80000000 | 2, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,

       0        // eod
};

void CategoriesGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CategoriesGame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QList<QString> _r = _t->GetTitles();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->GetCountValues();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->GetCountNoValues();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->GetTitle((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->GetIsNoValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { QJsonArray _r = _t->GetValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        case 6: { QJsonArray _r = _t->GetNoValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        case 7: { QList<QString> _r = _t->GetAchievementsName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->GetGame();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->GetGameID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->DeleteCategory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->Set((*reinterpret_cast< SGame(*)>(_a[1]))); break;
        case 12: _t->Save(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CategoriesGame::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CategoriesGame.data,
    qt_meta_data_CategoriesGame,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CategoriesGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CategoriesGame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CategoriesGame.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CategoriesGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
