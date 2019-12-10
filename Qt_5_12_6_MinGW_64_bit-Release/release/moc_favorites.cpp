/****************************************************************************
** Meta object code from reading C++ file 'favorites.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/class/favorites.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'favorites.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Favorites_t {
    QByteArrayData data[16];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Favorites_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Favorites_t qt_meta_stringdata_Favorites = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Favorites"
QT_MOC_LITERAL(1, 10, 7), // "SetPath"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "path"
QT_MOC_LITERAL(4, 24, 4), // "type"
QT_MOC_LITERAL(5, 29, 7), // "SetType"
QT_MOC_LITERAL(6, 37, 8), // "AddValue"
QT_MOC_LITERAL(7, 46, 8), // "newValue"
QT_MOC_LITERAL(8, 55, 13), // "deleteIfExist"
QT_MOC_LITERAL(9, 69, 11), // "RemoveValue"
QT_MOC_LITERAL(10, 81, 4), // "game"
QT_MOC_LITERAL(11, 86, 10), // "RemoveGame"
QT_MOC_LITERAL(12, 97, 7), // "AddGame"
QT_MOC_LITERAL(13, 105, 7), // "GetType"
QT_MOC_LITERAL(14, 113, 9), // "GetValues"
QT_MOC_LITERAL(15, 123, 4) // "Save"

    },
    "Favorites\0SetPath\0\0path\0type\0SetType\0"
    "AddValue\0newValue\0deleteIfExist\0"
    "RemoveValue\0game\0RemoveGame\0AddGame\0"
    "GetType\0GetValues\0Save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Favorites[] = {

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
       1,    2,   79,    2, 0x0a /* Public */,
       5,    1,   84,    2, 0x0a /* Public */,
       6,    2,   87,    2, 0x0a /* Public */,
       9,    1,   92,    2, 0x0a /* Public */,
       6,    2,   95,    2, 0x0a /* Public */,
       9,    1,  100,    2, 0x0a /* Public */,
       6,    3,  103,    2, 0x0a /* Public */,
       9,    2,  110,    2, 0x0a /* Public */,
      11,    1,  115,    2, 0x0a /* Public */,
      12,    1,  118,    2, 0x0a /* Public */,
      13,    0,  121,    2, 0x0a /* Public */,
      14,    0,  122,    2, 0x0a /* Public */,
      15,    0,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Bool, QMetaType::QJsonObject, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Bool, QMetaType::QJsonArray, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::QJsonArray,    7,
    QMetaType::Bool, QMetaType::QString, QMetaType::QJsonObject, QMetaType::Bool,   10,    7,    8,
    QMetaType::Bool, QMetaType::QString, QMetaType::QJsonObject,   10,    7,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Int, QMetaType::QString,   10,
    QMetaType::QString,
    QMetaType::QJsonArray,
    QMetaType::Void,

       0        // eod
};

void Favorites::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Favorites *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetPath((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->SetType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: { bool _r = _t->AddValue((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->RemoveValue((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: { bool _r = _t->AddValue((*reinterpret_cast< QJsonArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->RemoveValue((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 6: { bool _r = _t->AddValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->RemoveValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->RemoveGame((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: { int _r = _t->AddGame((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->GetType();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QJsonArray _r = _t->GetValues();
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->Save(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Favorites::staticMetaObject = { {
    &QObject::staticMetaObject,
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
