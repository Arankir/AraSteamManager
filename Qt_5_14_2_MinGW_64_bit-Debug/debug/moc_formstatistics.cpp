/****************************************************************************
** Meta object code from reading C++ file 'formstatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/MainSubForms/formstatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formstatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormStatistics_t {
    QByteArrayData data[16];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormStatistics_t qt_meta_stringdata_FormStatistics = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FormStatistics"
QT_MOC_LITERAL(1, 15, 18), // "s_statisticsLoaded"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "progress"
QT_MOC_LITERAL(4, 44, 3), // "row"
QT_MOC_LITERAL(5, 48, 8), // "s_finish"
QT_MOC_LITERAL(6, 57, 19), // "s_return_to_profile"
QT_MOC_LITERAL(7, 77, 8), // "QWidget*"
QT_MOC_LITERAL(8, 86, 8), // "onFinish"
QT_MOC_LITERAL(9, 95, 12), // "createThread"
QT_MOC_LITERAL(10, 108, 14), // "updateSettings"
QT_MOC_LITERAL(11, 123, 8), // "setIcons"
QT_MOC_LITERAL(12, 132, 11), // "changeEvent"
QT_MOC_LITERAL(13, 144, 7), // "QEvent*"
QT_MOC_LITERAL(14, 152, 5), // "event"
QT_MOC_LITERAL(15, 158, 11) // "retranslate"

    },
    "FormStatistics\0s_statisticsLoaded\0\0"
    "progress\0row\0s_finish\0s_return_to_profile\0"
    "QWidget*\0onFinish\0createThread\0"
    "updateSettings\0setIcons\0changeEvent\0"
    "QEvent*\0event\0retranslate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormStatistics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       5,    0,   64,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   68,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x0a /* Public */,
      12,    1,   72,    2, 0x08 /* Private */,
      15,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,

       0        // eod
};

void FormStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_statisticsLoaded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->s_finish(); break;
        case 2: _t->s_return_to_profile((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 3: _t->onFinish(); break;
        case 4: _t->createThread(); break;
        case 5: _t->updateSettings(); break;
        case 6: _t->setIcons(); break;
        case 7: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 8: _t->retranslate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormStatistics::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormStatistics::s_statisticsLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormStatistics::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormStatistics::s_finish)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FormStatistics::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormStatistics::s_return_to_profile)) {
                *result = 2;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void FormStatistics::s_statisticsLoaded(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormStatistics::s_finish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FormStatistics::s_return_to_profile(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
