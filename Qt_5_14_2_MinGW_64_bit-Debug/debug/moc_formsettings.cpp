/****************************************************************************
** Meta object code from reading C++ file 'formsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AraSteamManager/subform/formsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormSettings_t {
    QByteArrayData data[22];
    char stringdata0[417];
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
QT_MOC_LITERAL(5, 60, 11), // "changeEvent"
QT_MOC_LITERAL(6, 72, 7), // "QEvent*"
QT_MOC_LITERAL(7, 80, 5), // "event"
QT_MOC_LITERAL(8, 86, 14), // "InitComponents"
QT_MOC_LITERAL(9, 101, 34), // "RadioButtonLanguageEnglish_Cl..."
QT_MOC_LITERAL(10, 136, 34), // "RadioButtonLanguageRussian_Cl..."
QT_MOC_LITERAL(11, 171, 28), // "RadioButtonDarkTheme_Clicked"
QT_MOC_LITERAL(12, 200, 29), // "RadioButtonLightTheme_Clicked"
QT_MOC_LITERAL(13, 230, 30), // "RadioButtonHiddenGames_Clicked"
QT_MOC_LITERAL(14, 261, 19), // "AchievementsClicked"
QT_MOC_LITERAL(15, 281, 11), // "HideClicked"
QT_MOC_LITERAL(16, 293, 11), // "Retranslate"
QT_MOC_LITERAL(17, 305, 39), // "CheckBoxVisibleHiddenGames_St..."
QT_MOC_LITERAL(18, 345, 4), // "arg1"
QT_MOC_LITERAL(19, 350, 30), // "CheckBoxSaveImage_StateChanged"
QT_MOC_LITERAL(20, 381, 29), // "SlideProfileSize_ValueChanged"
QT_MOC_LITERAL(21, 411, 5) // "value"

    },
    "FormSettings\0s_return_to_profile\0\0"
    "QWidget*\0s_updateSettings\0changeEvent\0"
    "QEvent*\0event\0InitComponents\0"
    "RadioButtonLanguageEnglish_Clicked\0"
    "RadioButtonLanguageRussian_Clicked\0"
    "RadioButtonDarkTheme_Clicked\0"
    "RadioButtonLightTheme_Clicked\0"
    "RadioButtonHiddenGames_Clicked\0"
    "AchievementsClicked\0HideClicked\0"
    "Retranslate\0CheckBoxVisibleHiddenGames_StateChanged\0"
    "arg1\0CheckBoxSaveImage_StateChanged\0"
    "SlideProfileSize_ValueChanged\0value"
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
       5,    1,   93,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    1,  105,    2, 0x08 /* Private */,
      19,    1,  108,    2, 0x08 /* Private */,
      20,    1,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   21,

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
        case 2: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 3: _t->InitComponents(); break;
        case 4: _t->RadioButtonLanguageEnglish_Clicked(); break;
        case 5: _t->RadioButtonLanguageRussian_Clicked(); break;
        case 6: _t->RadioButtonDarkTheme_Clicked(); break;
        case 7: _t->RadioButtonLightTheme_Clicked(); break;
        case 8: _t->RadioButtonHiddenGames_Clicked(); break;
        case 9: _t->AchievementsClicked(); break;
        case 10: _t->HideClicked(); break;
        case 11: _t->Retranslate(); break;
        case 12: _t->CheckBoxVisibleHiddenGames_StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->CheckBoxSaveImage_StateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->SlideProfileSize_ValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
