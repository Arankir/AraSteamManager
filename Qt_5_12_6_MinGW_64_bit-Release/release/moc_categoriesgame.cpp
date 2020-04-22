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
    QByteArrayData data[22];
    char stringdata0[206];
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
QT_MOC_LITERAL(12, 115, 8), // "GetCount"
QT_MOC_LITERAL(13, 124, 9), // "GetGameID"
QT_MOC_LITERAL(14, 134, 14), // "DeleteCategory"
QT_MOC_LITERAL(15, 149, 9), // "DeleteAll"
QT_MOC_LITERAL(16, 159, 14), // "ChangeCategory"
QT_MOC_LITERAL(17, 174, 11), // "newCategory"
QT_MOC_LITERAL(18, 186, 3), // "Set"
QT_MOC_LITERAL(19, 190, 5), // "SGame"
QT_MOC_LITERAL(20, 196, 4), // "game"
QT_MOC_LITERAL(21, 201, 4) // "Save"

    },
    "CategoriesGame\0GetTitles\0QList<QString>\0"
    "\0GetTitle\0index\0GetIsNoValues\0GetValues\0"
    "category\0value\0GetNoValues\0GetGame\0"
    "GetCount\0GetGameID\0DeleteCategory\0"
    "DeleteAll\0ChangeCategory\0newCategory\0"
    "Set\0SGame\0game\0Save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CategoriesGame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    3, 0x0a /* Public */,
       4,    1,   85,    3, 0x0a /* Public */,
       6,    1,   88,    3, 0x0a /* Public */,
       7,    2,   91,    3, 0x0a /* Public */,
       7,    1,   96,    3, 0x0a /* Public */,
      10,    1,   99,    3, 0x0a /* Public */,
      11,    0,  102,    3, 0x0a /* Public */,
      12,    0,  103,    3, 0x0a /* Public */,
      13,    0,  104,    3, 0x0a /* Public */,
      14,    1,  105,    3, 0x0a /* Public */,
      15,    0,  108,    3, 0x0a /* Public */,
      16,    2,  109,    3, 0x0a /* Public */,
      18,    1,  114,    3, 0x0a /* Public */,
      21,    0,  117,    3, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonObject,    8,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
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
        case 7: { int _r = _t->GetCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->GetGameID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->DeleteCategory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->DeleteAll(); break;
        case 11: _t->ChangeCategory((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 12: _t->Set((*reinterpret_cast< SGame(*)>(_a[1]))); break;
        case 13: _t->Save(); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
