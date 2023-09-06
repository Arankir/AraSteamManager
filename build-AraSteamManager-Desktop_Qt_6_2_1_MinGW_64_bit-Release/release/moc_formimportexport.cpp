/****************************************************************************
** Meta object code from reading C++ file 'formimportexport.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/forms/main/settings/formimportexport.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formimportexport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormImportExport_t {
    const uint offsetsAndSize[20];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormImportExport_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormImportExport_t qt_meta_stringdata_FormImportExport = {
    {
QT_MOC_LITERAL(0, 16), // "FormImportExport"
QT_MOC_LITERAL(17, 10), // "itemToData"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(46, 5), // "aItem"
QT_MOC_LITERAL(52, 11), // "retranslate"
QT_MOC_LITERAL(64, 14), // "updateSettings"
QT_MOC_LITERAL(79, 23), // "QFlags<changedSettings>"
QT_MOC_LITERAL(103, 11), // "updateIcons"
QT_MOC_LITERAL(115, 14) // "checkAllChilds"

    },
    "FormImportExport\0itemToData\0\0"
    "QTreeWidgetItem*\0aItem\0retranslate\0"
    "updateSettings\0QFlags<changedSettings>\0"
    "updateIcons\0checkAllChilds"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormImportExport[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x09,    1 /* Protected */,
       5,    0,   47,    2, 0x08,    3 /* Private */,
       6,    1,   48,    2, 0x08,    4 /* Private */,
       8,    0,   51,    2, 0x08,    6 /* Private */,
       9,    1,   52,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::QJsonValue, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::QJsonArray, 0x80000000 | 3,    4,

       0        // eod
};

void FormImportExport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormImportExport *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QJsonValue _r = _t->itemToData((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonValue*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->retranslate(); break;
        case 2: _t->updateSettings((*reinterpret_cast< QFlags<changedSettings>(*)>(_a[1]))); break;
        case 3: _t->updateIcons(); break;
        case 4: { QJsonArray _r = _t->checkAllChilds((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject FormImportExport::staticMetaObject = { {
    QMetaObject::SuperData::link<Form::staticMetaObject>(),
    qt_meta_stringdata_FormImportExport.offsetsAndSize,
    qt_meta_data_FormImportExport,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormImportExport_t
, QtPrivate::TypeAndForceComplete<FormImportExport, std::true_type>
, QtPrivate::TypeAndForceComplete<QJsonValue, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QFlags<changedSettings>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonArray, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>


>,
    nullptr
} };


const QMetaObject *FormImportExport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormImportExport::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormImportExport.stringdata0))
        return static_cast<void*>(this);
    return Form::qt_metacast(_clname);
}

int FormImportExport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Form::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
