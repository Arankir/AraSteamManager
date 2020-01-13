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
    QByteArrayData data[15];
    char stringdata0[328];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormSettings_t qt_meta_stringdata_FormSettings = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FormSettings"
QT_MOC_LITERAL(1, 13, 19), // "s_return_to_profile"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "InitComponents"
QT_MOC_LITERAL(4, 49, 37), // "on_RadioButtonLanguageEnglish..."
QT_MOC_LITERAL(5, 87, 37), // "on_RadioButtonLanguageRussian..."
QT_MOC_LITERAL(6, 125, 42), // "on_CheckBoxVisibleHiddenGames..."
QT_MOC_LITERAL(7, 168, 4), // "arg1"
QT_MOC_LITERAL(8, 173, 31), // "on_RadioButtonDarkTheme_clicked"
QT_MOC_LITERAL(9, 205, 32), // "on_RadioButtonLightTheme_clicked"
QT_MOC_LITERAL(10, 238, 29), // "RadiobuttonHiddenGamesClicked"
QT_MOC_LITERAL(11, 268, 13), // "OnResultImage"
QT_MOC_LITERAL(12, 282, 13), // "ImageRequest*"
QT_MOC_LITERAL(13, 296, 19), // "AchievementsClicked"
QT_MOC_LITERAL(14, 316, 11) // "HideClicked"

    },
    "FormSettings\0s_return_to_profile\0\0"
    "InitComponents\0on_RadioButtonLanguageEnglish_clicked\0"
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
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    1,   79,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,
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
        case 0: _t->s_return_to_profile(); break;
        case 1: _t->InitComponents(); break;
        case 2: _t->on_RadioButtonLanguageEnglish_clicked(); break;
        case 3: _t->on_RadioButtonLanguageRussian_clicked(); break;
        case 4: _t->on_CheckBoxVisibleHiddenGames_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_RadioButtonDarkTheme_clicked(); break;
        case 6: _t->on_RadioButtonLightTheme_clicked(); break;
        case 7: _t->RadiobuttonHiddenGamesClicked(); break;
        case 8: _t->OnResultImage((*reinterpret_cast< ImageRequest*(*)>(_a[1]))); break;
        case 9: _t->AchievementsClicked(); break;
        case 10: _t->HideClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageRequest* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormSettings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSettings::s_return_to_profile)) {
                *result = 0;
                return;
            }
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void FormSettings::s_return_to_profile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
