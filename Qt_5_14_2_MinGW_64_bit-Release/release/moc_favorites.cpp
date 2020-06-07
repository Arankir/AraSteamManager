/****************************************************************************
** Meta object code from reading C++ file 'favorites.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/class/favorites.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'favorites.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Favorites_t {
    QByteArrayData data[17];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Favorites_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Favorites_t qt_meta_stringdata_Favorites = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Favorites"
QT_MOC_LITERAL(1, 10, 7), // "setType"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "type"
QT_MOC_LITERAL(4, 24, 8), // "addValue"
QT_MOC_LITERAL(5, 33, 8), // "newValue"
QT_MOC_LITERAL(6, 42, 13), // "deleteIfExist"
QT_MOC_LITERAL(7, 56, 4), // "game"
QT_MOC_LITERAL(8, 61, 11), // "removeValue"
QT_MOC_LITERAL(9, 73, 10), // "removeGame"
QT_MOC_LITERAL(10, 84, 7), // "addGame"
QT_MOC_LITERAL(11, 92, 7), // "getType"
QT_MOC_LITERAL(12, 100, 9), // "getValues"
QT_MOC_LITERAL(13, 110, 4), // "save"
QT_MOC_LITERAL(14, 115, 4), // "init"
QT_MOC_LITERAL(15, 120, 8), // "jsonType"
QT_MOC_LITERAL(16, 129, 4) // "load"

    },
    "Favorites\0setType\0\0type\0addValue\0"
    "newValue\0deleteIfExist\0game\0removeValue\0"
    "removeGame\0addGame\0getType\0getValues\0"
    "save\0init\0jsonType\0load"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Favorites[] = {

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
       4,    2,  102,    2, 0x0a /* Public */,
       4,    2,  107,    2, 0x0a /* Public */,
       4,    3,  112,    2, 0x0a /* Public */,
       8,    1,  119,    2, 0x0a /* Public */,
       8,    1,  122,    2, 0x0a /* Public */,
       8,    2,  125,    2, 0x0a /* Public */,
       9,    1,  130,    2, 0x0a /* Public */,
      10,    1,  133,    2, 0x0a /* Public */,
      11,    0,  136,    2, 0x0a /* Public */,
      12,    0,  137,    2, 0x0a /* Public */,
      12,    1,  138,    2, 0x0a /* Public */,
      13,    0,  141,    2, 0x08 /* Private */,
      14,    1,  142,    2, 0x08 /* Private */,
       4,    3,  145,    2, 0x08 /* Private */,
       8,    1,  152,    2, 0x08 /* Private */,
      16,    0,  155,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QJsonObject, QMetaType::Bool,    5,    6,
    QMetaType::Bool, QMetaType::QJsonArray, QMetaType::Bool,    5,    6,
    QMetaType::Bool, QMetaType::QJsonObject, QMetaType::QJsonObject, QMetaType::Bool,    7,    5,    6,
    QMetaType::Void, QMetaType::QJsonObject,    5,
    QMetaType::Void, QMetaType::QJsonArray,    5,
    QMetaType::Bool, QMetaType::QJsonObject, QMetaType::QJsonObject,    7,    5,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Int, QMetaType::QJsonObject,    7,
    QMetaType::QString,
    QMetaType::QJsonArray,
    QMetaType::QJsonArray, QMetaType::QJsonObject,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QJsonValue, QMetaType::Bool, 0x80000000 | 15,    5,    6,    3,
    QMetaType::Void, QMetaType::QJsonValue,    5,
    QMetaType::Void,

       0        // eod
};

void Favorites::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Favorites *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: { bool _r = _t->addValue((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->addValue((*reinterpret_cast< QJsonArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->addValue((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->removeValue((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 5: _t->removeValue((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 6: { bool _r = _t->removeValue((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->removeGame((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 8: { int _r = _t->addGame((*reinterpret_cast< QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getType();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QJsonArray _r = _t->getValues();
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        case 11: { QJsonArray _r = _t->getValues((*reinterpret_cast< QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->save(); break;
        case 13: _t->init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: { bool _r = _t->addValue((*reinterpret_cast< QJsonValue(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< jsonType(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->removeValue((*reinterpret_cast< QJsonValue(*)>(_a[1]))); break;
        case 16: _t->load(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Favorites::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Favorites.data,
    qt_meta_data_Favorites,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Favorites::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Favorites::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Favorites.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Favorites::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
