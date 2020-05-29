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
    QByteArrayData data[22];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CategoriesGame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CategoriesGame_t qt_meta_stringdata_CategoriesGame = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CategoriesGame"
QT_MOC_LITERAL(1, 15, 8), // "GetTitle"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "a_index"
QT_MOC_LITERAL(4, 33, 13), // "GetIsNoValues"
QT_MOC_LITERAL(5, 47, 9), // "GetValues"
QT_MOC_LITERAL(6, 57, 7), // "a_value"
QT_MOC_LITERAL(7, 65, 7), // "GetGame"
QT_MOC_LITERAL(8, 73, 8), // "GetCount"
QT_MOC_LITERAL(9, 82, 9), // "GetGameID"
QT_MOC_LITERAL(10, 92, 9), // "GetTitles"
QT_MOC_LITERAL(11, 102, 14), // "QList<QString>"
QT_MOC_LITERAL(12, 117, 8), // "category"
QT_MOC_LITERAL(13, 126, 5), // "value"
QT_MOC_LITERAL(14, 132, 11), // "GetNoValues"
QT_MOC_LITERAL(15, 144, 14), // "DeleteCategory"
QT_MOC_LITERAL(16, 159, 5), // "index"
QT_MOC_LITERAL(17, 165, 9), // "DeleteAll"
QT_MOC_LITERAL(18, 175, 14), // "ChangeCategory"
QT_MOC_LITERAL(19, 190, 11), // "newCategory"
QT_MOC_LITERAL(20, 202, 6), // "Update"
QT_MOC_LITERAL(21, 209, 4) // "Save"

    },
    "CategoriesGame\0GetTitle\0\0a_index\0"
    "GetIsNoValues\0GetValues\0a_value\0GetGame\0"
    "GetCount\0GetGameID\0GetTitles\0"
    "QList<QString>\0category\0value\0GetNoValues\0"
    "DeleteCategory\0index\0DeleteAll\0"
    "ChangeCategory\0newCategory\0Update\0"
    "Save"
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
       1,    1,   84,    2, 0x0a /* Public */,
       4,    1,   87,    2, 0x0a /* Public */,
       5,    1,   90,    2, 0x0a /* Public */,
       7,    0,   93,    2, 0x0a /* Public */,
       8,    0,   94,    2, 0x0a /* Public */,
       9,    0,   95,    2, 0x0a /* Public */,
      10,    0,   96,    2, 0x0a /* Public */,
       5,    2,   97,    2, 0x0a /* Public */,
      14,    1,  102,    2, 0x0a /* Public */,
      15,    1,  105,    2, 0x0a /* Public */,
      17,    0,  108,    2, 0x0a /* Public */,
      18,    2,  109,    2, 0x0a /* Public */,
      20,    0,  114,    2, 0x0a /* Public */,
      21,    0,  115,    2, 0x0a /* Public */,

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

       0        // eod
};

void CategoriesGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CategoriesGame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->GetTitle((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->GetIsNoValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { QJsonArray _r = _t->GetValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->GetGame();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->GetCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->GetGameID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { QList<QString> _r = _t->GetTitles();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 7: { QList<QString> _r = _t->GetValues((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 8: { QList<QString> _r = _t->GetNoValues((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->DeleteCategory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->DeleteAll(); break;
        case 11: _t->ChangeCategory((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 12: _t->Update(); break;
        case 13: _t->Save(); break;
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
