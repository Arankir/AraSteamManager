/****************************************************************************
** Meta object code from reading C++ file 'formstatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/subform/formstatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formstatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormStatistics_t {
    QByteArrayData data[16];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormStatistics_t qt_meta_stringdata_FormStatistics = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FormStatistics"
QT_MOC_LITERAL(1, 15, 8), // "OnFinish"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "QVector<int>"
QT_MOC_LITERAL(4, 38, 5), // "numof"
QT_MOC_LITERAL(5, 44, 32), // "QVector<QPair<QString,QString> >"
QT_MOC_LITERAL(6, 77, 8), // "complete"
QT_MOC_LITERAL(7, 86, 7), // "started"
QT_MOC_LITERAL(8, 94, 10), // "notStarted"
QT_MOC_LITERAL(9, 105, 15), // "QVector<double>"
QT_MOC_LITERAL(10, 121, 14), // "averagePercent"
QT_MOC_LITERAL(11, 136, 10), // "summcolumn"
QT_MOC_LITERAL(12, 147, 5), // "times"
QT_MOC_LITERAL(13, 153, 6), // "months"
QT_MOC_LITERAL(14, 160, 28), // "QVector<QPair<QString,int> >"
QT_MOC_LITERAL(15, 189, 5) // "years"

    },
    "FormStatistics\0OnFinish\0\0QVector<int>\0"
    "numof\0QVector<QPair<QString,QString> >\0"
    "complete\0started\0notStarted\0QVector<double>\0"
    "averagePercent\0summcolumn\0times\0months\0"
    "QVector<QPair<QString,int> >\0years"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormStatistics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    9,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 9, QMetaType::Int, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 14,    4,    6,    7,    8,   10,   11,   12,   13,   15,

       0        // eod
};

void FormStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnFinish((*reinterpret_cast< QVector<int>(*)>(_a[1])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[2])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[3])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[4])),(*reinterpret_cast< QVector<double>(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QVector<int>(*)>(_a[7])),(*reinterpret_cast< QVector<int>(*)>(_a[8])),(*reinterpret_cast< QVector<QPair<QString,int> >(*)>(_a[9]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            case 7:
            case 6:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormStatistics::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FormStatistics.data,
    qt_meta_data_FormStatistics,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormStatistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormStatistics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormStatistics.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
