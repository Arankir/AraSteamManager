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
    QByteArrayData data[10];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CategoriesGame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CategoriesGame_t qt_meta_stringdata_CategoriesGame = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CategoriesGame"
QT_MOC_LITERAL(1, 15, 8), // "fromJson"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "_categories"
QT_MOC_LITERAL(4, 37, 8), // "getFiles"
QT_MOC_LITERAL(5, 46, 13), // "QFileInfoList"
QT_MOC_LITERAL(6, 60, 4), // "path"
QT_MOC_LITERAL(7, 65, 20), // "convertOldCategories"
QT_MOC_LITERAL(8, 86, 4), // "load"
QT_MOC_LITERAL(9, 91, 6) // "toJson"

    },
    "CategoriesGame\0fromJson\0\0_categories\0"
    "getFiles\0QFileInfoList\0path\0"
    "convertOldCategories\0load\0toJson"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CategoriesGame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,
       8,    0,   46,    2, 0x08 /* Private */,
       9,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    0x80000000 | 5, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QJsonObject,

       0        // eod
};

void CategoriesGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CategoriesGame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fromJson((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 1: { QFileInfoList _r = _t->getFiles((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFileInfoList*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->convertOldCategories(); break;
        case 3: _t->load(); break;
        case 4: { QJsonObject _r = _t->toJson();
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
