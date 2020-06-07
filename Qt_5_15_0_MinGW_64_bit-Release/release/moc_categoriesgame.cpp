/****************************************************************************
** Meta object code from reading C++ file 'categoriesgame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/class/categoriesgame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'categoriesgame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CategoriesGame_t {
    QByteArrayData data[27];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CategoriesGame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CategoriesGame_t qt_meta_stringdata_CategoriesGame = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CategoriesGame"
QT_MOC_LITERAL(1, 15, 8), // "getTitle"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "a_index"
QT_MOC_LITERAL(4, 33, 13), // "getIsNoValues"
QT_MOC_LITERAL(5, 47, 9), // "getValues"
QT_MOC_LITERAL(6, 57, 7), // "a_value"
QT_MOC_LITERAL(7, 65, 7), // "getGame"
QT_MOC_LITERAL(8, 73, 8), // "getCount"
QT_MOC_LITERAL(9, 82, 9), // "getGameID"
QT_MOC_LITERAL(10, 92, 9), // "getTitles"
QT_MOC_LITERAL(11, 102, 14), // "QList<QString>"
QT_MOC_LITERAL(12, 117, 8), // "category"
QT_MOC_LITERAL(13, 126, 5), // "value"
QT_MOC_LITERAL(14, 132, 11), // "getNoValues"
QT_MOC_LITERAL(15, 144, 14), // "deleteCategory"
QT_MOC_LITERAL(16, 159, 5), // "index"
QT_MOC_LITERAL(17, 165, 9), // "deleteAll"
QT_MOC_LITERAL(18, 175, 14), // "changeCategory"
QT_MOC_LITERAL(19, 190, 11), // "newCategory"
QT_MOC_LITERAL(20, 202, 6), // "update"
QT_MOC_LITERAL(21, 209, 4), // "save"
QT_MOC_LITERAL(22, 214, 8), // "getFiles"
QT_MOC_LITERAL(23, 223, 13), // "QFileInfoList"
QT_MOC_LITERAL(24, 237, 4), // "path"
QT_MOC_LITERAL(25, 242, 20), // "convertOldCategories"
QT_MOC_LITERAL(26, 263, 14) // "loadCategories"

    },
    "CategoriesGame\0getTitle\0\0a_index\0"
    "getIsNoValues\0getValues\0a_value\0getGame\0"
    "getCount\0getGameID\0getTitles\0"
    "QList<QString>\0category\0value\0getNoValues\0"
    "deleteCategory\0index\0deleteAll\0"
    "changeCategory\0newCategory\0update\0"
    "save\0getFiles\0QFileInfoList\0path\0"
    "convertOldCategories\0loadCategories"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CategoriesGame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x0a /* Public */,
       4,    1,  102,    2, 0x0a /* Public */,
       5,    1,  105,    2, 0x0a /* Public */,
       7,    0,  108,    2, 0x0a /* Public */,
       8,    0,  109,    2, 0x0a /* Public */,
       9,    0,  110,    2, 0x0a /* Public */,
      10,    0,  111,    2, 0x0a /* Public */,
       5,    2,  112,    2, 0x0a /* Public */,
      14,    1,  117,    2, 0x0a /* Public */,
      15,    1,  120,    2, 0x0a /* Public */,
      17,    0,  123,    2, 0x0a /* Public */,
      18,    2,  124,    2, 0x0a /* Public */,
      20,    0,  129,    2, 0x0a /* Public */,
      21,    0,  130,    2, 0x0a /* Public */,
      22,    1,  131,    2, 0x08 /* Private */,
      25,    0,  134,    2, 0x08 /* Private */,
      26,    0,  135,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::QString, QMetaType::Int,    3,
    QMetaType::Int, QMetaType::Int,    3,
    QMetaType::QJsonArray, QMetaType::Int,    6,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Int,
    0x80000000 | 11,
    0x80000000 | 11, QMetaType::Int, QMetaType::Int,   12,   13,
    0x80000000 | 11, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonObject,   12,   19,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 23, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CategoriesGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CategoriesGame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->getTitle((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->getIsNoValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { QJsonArray _r = _t->getValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->getGame();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->getCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->getGameID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { QList<QString> _r = _t->getTitles();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 7: { QList<QString> _r = _t->getValues((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 8: { QList<QString> _r = _t->getNoValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->deleteCategory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->deleteAll(); break;
        case 11: _t->changeCategory((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 12: _t->update(); break;
        case 13: _t->save(); break;
        case 14: { QFileInfoList _r = _t->getFiles((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFileInfoList*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->convertOldCategories(); break;
        case 16: _t->loadCategories(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CategoriesGame::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
