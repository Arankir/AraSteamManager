/****************************************************************************
** Meta object code from reading C++ file 'formstatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AraSteamManager/subform/formstatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formstatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormStatistics_t {
    QByteArrayData data[21];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormStatistics_t qt_meta_stringdata_FormStatistics = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FormStatistics"
QT_MOC_LITERAL(1, 15, 19), // "s_return_to_profile"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "QWidget*"
QT_MOC_LITERAL(4, 45, 8), // "OnFinish"
QT_MOC_LITERAL(5, 54, 12), // "QVector<int>"
QT_MOC_LITERAL(6, 67, 5), // "numof"
QT_MOC_LITERAL(7, 73, 32), // "QVector<QPair<QString,QString> >"
QT_MOC_LITERAL(8, 106, 8), // "complete"
QT_MOC_LITERAL(9, 115, 7), // "started"
QT_MOC_LITERAL(10, 123, 10), // "notStarted"
QT_MOC_LITERAL(11, 134, 15), // "QVector<double>"
QT_MOC_LITERAL(12, 150, 14), // "averagePercent"
QT_MOC_LITERAL(13, 165, 10), // "summcolumn"
QT_MOC_LITERAL(14, 176, 5), // "times"
QT_MOC_LITERAL(15, 182, 6), // "months"
QT_MOC_LITERAL(16, 189, 28), // "QVector<QPair<QString,int> >"
QT_MOC_LITERAL(17, 218, 5), // "years"
QT_MOC_LITERAL(18, 224, 11), // "changeEvent"
QT_MOC_LITERAL(19, 236, 7), // "QEvent*"
QT_MOC_LITERAL(20, 244, 5) // "event"

    },
    "FormStatistics\0s_return_to_profile\0\0"
    "QWidget*\0OnFinish\0QVector<int>\0numof\0"
    "QVector<QPair<QString,QString> >\0"
    "complete\0started\0notStarted\0QVector<double>\0"
    "averagePercent\0summcolumn\0times\0months\0"
    "QVector<QPair<QString,int> >\0years\0"
    "changeEvent\0QEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormStatistics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    9,   32,    2, 0x0a /* Public */,
      18,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 11, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 16,    6,    8,    9,   10,   12,   13,   14,   15,   17,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void FormStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_return_to_profile((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->OnFinish((*reinterpret_cast< QVector<int>(*)>(_a[1])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[2])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[3])),(*reinterpret_cast< QVector<QPair<QString,QString> >(*)>(_a[4])),(*reinterpret_cast< QVector<double>(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QVector<int>(*)>(_a[7])),(*reinterpret_cast< QVector<int>(*)>(_a[8])),(*reinterpret_cast< QVector<QPair<QString,int> >(*)>(_a[9]))); break;
        case 2: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 1:
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormStatistics::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormStatistics::s_return_to_profile)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormStatistics::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FormStatistics::s_return_to_profile(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
