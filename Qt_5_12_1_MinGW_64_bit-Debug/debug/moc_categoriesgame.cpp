/****************************************************************************
** Meta object code from reading C++ file 'categoriesgame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/class/categoriesgame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'categoriesgame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CategoriesGame_t {
    QByteArrayData data[21];
    char stringdata0[197];
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
QT_MOC_LITERAL(4, 41, 8), // "GetTitle"
QT_MOC_LITERAL(5, 50, 5), // "index"
QT_MOC_LITERAL(6, 56, 13), // "GetIsNoValues"
QT_MOC_LITERAL(7, 70, 9), // "GetValues"
QT_MOC_LITERAL(8, 80, 8), // "category"
QT_MOC_LITERAL(9, 89, 5), // "value"
QT_MOC_LITERAL(10, 95, 11), // "GetNoValues"
QT_MOC_LITERAL(11, 107, 7), // "GetGame"
QT_MOC_LITERAL(12, 115, 9), // "GetCounts"
QT_MOC_LITERAL(13, 125, 9), // "GetGameID"
QT_MOC_LITERAL(14, 135, 14), // "DeleteCategory"
QT_MOC_LITERAL(15, 150, 14), // "ChangeCategory"
QT_MOC_LITERAL(16, 165, 11), // "newCategory"
QT_MOC_LITERAL(17, 177, 3), // "Set"
QT_MOC_LITERAL(18, 181, 5), // "SGame"
QT_MOC_LITERAL(19, 187, 4), // "game"
QT_MOC_LITERAL(20, 192, 4) // "Save"

    },
    "CategoriesGame\0GetTitles\0QList<QString>\0"
    "\0GetTitle\0index\0GetIsNoValues\0GetValues\0"
    "category\0value\0GetNoValues\0GetGame\0"
    "GetCounts\0GetGameID\0DeleteCategory\0"
    "ChangeCategory\0newCategory\0Set\0SGame\0"
    "game\0Save"
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
       4,    1,   80,    3, 0x0a /* Public */,
       6,    1,   83,    3, 0x0a /* Public */,
       7,    2,   86,    3, 0x0a /* Public */,
       7,    1,   91,    3, 0x0a /* Public */,
      10,    1,   94,    3, 0x0a /* Public */,
      11,    0,   97,    3, 0x0a /* Public */,
      12,    0,   98,    3, 0x0a /* Public */,
      13,    0,   99,    3, 0x0a /* Public */,
      14,    1,  100,    3, 0x0a /* Public */,
      15,    2,  103,    3, 0x0a /* Public */,
      17,    1,  108,    3, 0x0a /* Public */,
      20,    0,  111,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::Int, QMetaType::Int,    5,
    0x80000000 | 2, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::QJsonArray, QMetaType::Int,    9,
    0x80000000 | 2, QMetaType::Int,    8,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonObject,    8,   16,
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
        case 1: { QString _r = _t->GetTitle((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->GetIsNoValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { QList<QString> _r = _t->GetValues((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QJsonArray _r = _t->GetValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        case 5: { QList<QString> _r = _t->GetNoValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->GetGame();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->GetCounts();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->GetGameID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->DeleteCategory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->ChangeCategory((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
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
