/****************************************************************************
** Meta object code from reading C++ file 'formsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AraSteamManager/subform/formsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormSettings_t {
    QByteArrayData data[22];
    char stringdata0[434];
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
QT_MOC_LITERAL(3, 34, 8), // "QWidget*"
QT_MOC_LITERAL(4, 43, 16), // "s_updateSettings"
QT_MOC_LITERAL(5, 60, 14), // "InitComponents"
QT_MOC_LITERAL(6, 75, 11), // "changeEvent"
QT_MOC_LITERAL(7, 87, 7), // "QEvent*"
QT_MOC_LITERAL(8, 95, 5), // "event"
QT_MOC_LITERAL(9, 101, 37), // "on_RadioButtonLanguageEnglish..."
QT_MOC_LITERAL(10, 139, 37), // "on_RadioButtonLanguageRussian..."
QT_MOC_LITERAL(11, 177, 42), // "on_CheckBoxVisibleHiddenGames..."
QT_MOC_LITERAL(12, 220, 4), // "arg1"
QT_MOC_LITERAL(13, 225, 31), // "on_RadioButtonDarkTheme_clicked"
QT_MOC_LITERAL(14, 257, 32), // "on_RadioButtonLightTheme_clicked"
QT_MOC_LITERAL(15, 290, 29), // "RadiobuttonHiddenGamesClicked"
QT_MOC_LITERAL(16, 320, 13), // "OnResultImage"
QT_MOC_LITERAL(17, 334, 12), // "RequestData*"
QT_MOC_LITERAL(18, 347, 19), // "AchievementsClicked"
QT_MOC_LITERAL(19, 367, 11), // "HideClicked"
QT_MOC_LITERAL(20, 379, 11), // "Retranslate"
QT_MOC_LITERAL(21, 391, 42) // "on_CheckBoxVisibleProfileInfo..."

    },
    "FormSettings\0s_return_to_profile\0\0"
    "QWidget*\0s_updateSettings\0InitComponents\0"
    "changeEvent\0QEvent*\0event\0"
    "on_RadioButtonLanguageEnglish_clicked\0"
    "on_RadioButtonLanguageRussian_clicked\0"
    "on_CheckBoxVisibleHiddenGames_stateChanged\0"
    "arg1\0on_RadioButtonDarkTheme_clicked\0"
    "on_RadioButtonLightTheme_clicked\0"
    "RadiobuttonHiddenGamesClicked\0"
    "OnResultImage\0RequestData*\0"
    "AchievementsClicked\0HideClicked\0"
    "Retranslate\0on_CheckBoxVisibleProfileInfo_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormSettings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   93,    2, 0x08 /* Private */,
       6,    1,   94,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    1,   99,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    1,  105,    2, 0x08 /* Private */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,
      20,    0,  110,    2, 0x08 /* Private */,
      21,    1,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void FormSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_return_to_profile((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->s_updateSettings(); break;
        case 2: _t->InitComponents(); break;
        case 3: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 4: _t->on_RadioButtonLanguageEnglish_clicked(); break;
        case 5: _t->on_RadioButtonLanguageRussian_clicked(); break;
        case 6: _t->on_CheckBoxVisibleHiddenGames_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_RadioButtonDarkTheme_clicked(); break;
        case 8: _t->on_RadioButtonLightTheme_clicked(); break;
        case 9: _t->RadiobuttonHiddenGamesClicked(); break;
        case 10: _t->OnResultImage((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        case 11: _t->AchievementsClicked(); break;
        case 12: _t->HideClicked(); break;
        case 13: _t->Retranslate(); break;
        case 14: _t->on_CheckBoxVisibleProfileInfo_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RequestData* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormSettings::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSettings::s_return_to_profile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormSettings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormSettings::s_updateSettings)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void FormSettings::s_return_to_profile(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormSettings::s_updateSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
