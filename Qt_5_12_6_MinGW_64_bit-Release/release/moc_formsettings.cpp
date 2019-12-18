/****************************************************************************
** Meta object code from reading C++ file 'formsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AraSteamManager/subform/formsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormSettings_t {
    QByteArrayData data[14];
    char stringdata0[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormSettings_t qt_meta_stringdata_FormSettings = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FormSettings"
QT_MOC_LITERAL(1, 13, 14), // "InitComponents"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 37), // "on_RadioButtonLanguageEnglish..."
QT_MOC_LITERAL(4, 67, 37), // "on_RadioButtonLanguageRussian..."
QT_MOC_LITERAL(5, 105, 42), // "on_CheckBoxVisibleHiddenGames..."
QT_MOC_LITERAL(6, 148, 4), // "arg1"
QT_MOC_LITERAL(7, 153, 31), // "on_RadioButtonDarkTheme_clicked"
QT_MOC_LITERAL(8, 185, 32), // "on_RadioButtonLightTheme_clicked"
QT_MOC_LITERAL(9, 218, 29), // "RadiobuttonHiddenGamesClicked"
QT_MOC_LITERAL(10, 248, 13), // "OnResultImage"
QT_MOC_LITERAL(11, 262, 13), // "ImageRequest*"
QT_MOC_LITERAL(12, 276, 19), // "AchievementsClicked"
QT_MOC_LITERAL(13, 296, 11) // "HideClicked"

    },
    "FormSettings\0InitComponents\0\0"
    "on_RadioButtonLanguageEnglish_clicked\0"
    "on_RadioButtonLanguageRussian_clicked\0"
    "on_CheckBoxVisibleHiddenGames_stateChanged\0"
    "arg1\0on_RadioButtonDarkTheme_clicked\0"
    "on_RadioButtonLightTheme_clicked\0"
    "RadiobuttonHiddenGamesClicked\0"
    "OnResultImage\0ImageRequest*\0"
    "AchievementsClicked\0HideClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormSettings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InitComponents(); break;
        case 1: _t->on_RadioButtonLanguageEnglish_clicked(); break;
        case 2: _t->on_RadioButtonLanguageRussian_clicked(); break;
        case 3: _t->on_CheckBoxVisibleHiddenGames_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_RadioButtonDarkTheme_clicked(); break;
        case 5: _t->on_RadioButtonLightTheme_clicked(); break;
        case 6: _t->RadiobuttonHiddenGamesClicked(); break;
        case 7: _t->OnResultImage((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        case 8: _t->AchievementsClicked(); break;
        case 9: _t->HideClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageRequest* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormSettings::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FormSettings.data,
    qt_meta_data_FormSettings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormSettings.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
