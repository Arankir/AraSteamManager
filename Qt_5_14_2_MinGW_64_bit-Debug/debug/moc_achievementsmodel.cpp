/****************************************************************************
** Meta object code from reading C++ file 'achievementsmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subWidgets/models/achievementsmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'achievementsmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AchievementsModel_t {
    QByteArrayData data[11];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AchievementsModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AchievementsModel_t qt_meta_stringdata_AchievementsModel = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AchievementsModel"
QT_MOC_LITERAL(1, 18, 10), // "s_finished"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "s_progress"
QT_MOC_LITERAL(4, 41, 5), // "stage"
QT_MOC_LITERAL(5, 47, 8), // "progress"
QT_MOC_LITERAL(6, 56, 14), // "updateComments"
QT_MOC_LITERAL(7, 71, 4), // "sort"
QT_MOC_LITERAL(8, 76, 6), // "column"
QT_MOC_LITERAL(9, 83, 13), // "Qt::SortOrder"
QT_MOC_LITERAL(10, 97, 5) // "order"

    },
    "AchievementsModel\0s_finished\0\0s_progress\0"
    "stage\0progress\0updateComments\0sort\0"
    "column\0Qt::SortOrder\0order"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AchievementsModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    2,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    2,   46,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void AchievementsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AchievementsModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_finished(); break;
        case 1: _t->s_progress((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 2: _t->updateComments(); break;
        case 3: _t->sort((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::SortOrder(*)>(_a[2]))); break;
        case 4: _t->sort((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AchievementsModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AchievementsModel::s_finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AchievementsModel::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AchievementsModel::s_progress)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AchievementsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_AchievementsModel.data,
    qt_meta_data_AchievementsModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AchievementsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AchievementsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AchievementsModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int AchievementsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void AchievementsModel::s_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AchievementsModel::s_progress(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
