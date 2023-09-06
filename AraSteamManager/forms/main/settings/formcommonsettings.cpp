#include "formcommonsettings.h"
#include "ui_formcommonsettings.h"
#include "classes/common/settings.h"
#include "classes/common/images.h"
#include "classes/common/theme.h"
#include "./colorpicker.h"
#include <QTranslator>

FormCommonSettings::FormCommonSettings(QWidget *aParent) :
    Form(aParent),
    ui(new Ui::FormCommonSettings) {
    ui->setupUi(this);
    init();
}

void FormCommonSettings::update() {
    switch (Settings::language()) {
    case 1: {
        ui->ComboBoxLanguage->setCurrentIndex(0);
        break;
    }
    case 5: {
        ui->ComboBoxLanguage->setCurrentIndex(1);
        break;
    }
    default: {
        break;
    }
    }
    switch (Settings::theme()) {
    case 0: {
        ui->ComboBoxTheme->setCurrentIndex(8);
        break;
    }
    case 1: {
        ui->ComboBoxTheme->setCurrentIndex(2);
        break;
    }
    case 2: {
        ui->ComboBoxTheme->setCurrentIndex(1);
        break;
    }
    case 3: {
        ui->ComboBoxTheme->setCurrentIndex(0);
        break;
    }
    case 4: {
        ui->ComboBoxTheme->setCurrentIndex(3);
        break;
    }
    case 5: {
        ui->ComboBoxTheme->setCurrentIndex(4);
        break;
    }
    case 6: {
        ui->ComboBoxTheme->setCurrentIndex(5);
        break;
    }
    case 7: {
        ui->ComboBoxTheme->setCurrentIndex(6);
        break;
    }
    case 8: {
        ui->ComboBoxTheme->setCurrentIndex(7);
        break;
    }
    default: {
        break;
    }
    }
    ui->comboBoxProfileInfo->setCurrentIndex(Settings::profileInfoSize());
}

FormCommonSettings::~FormCommonSettings() {
    delete ui;
}

void FormCommonSettings::init() {
    ui->comboBoxProfileInfo->addItems(QStringList {tr("Минимум"), tr("Обычные"), tr("Максимум")});
    ui->ComboBoxLanguage->addItem(QIcon(Images::english()), tr("English"));
    ui->ComboBoxLanguage->addItem(QIcon(Images::russian()), tr("Русский"));
    ui->ComboBoxTheme->addItems(QStringList {tr("Тёмная"), tr("Светлая"), tr("Синяя"), tr("Оранжевая"), tr("Малиновая"), tr("Лаймовая"), tr("Фиолетовая"), tr("Зеленая"), tr("Пользовательская")});
    ui->ComboBoxTheme->setItemData(0, blackTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(1, whiteTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(2, blueTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(3, orangeTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(4, crimsonTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(5, limeTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(6, purpleTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(7, greenTheme().mainBackground.color, Qt::DecorationRole);
    ui->ComboBoxTheme->setItemData(8, QColor(255, 255, 255, 20), Qt::DecorationRole);
    update();
    connect(ui->ComboBoxTheme,              SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxThemeIndexChanged(int)));
    connect(ui->ComboBoxLanguage,           SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxLanguageIndexChanged(int)));
    connect(ui->comboBoxProfileInfo,        SIGNAL(currentIndexChanged(int)), this, SLOT(slideProfileSize_ValueChanged(int)));
//    QPalette darkPalette;
//    darkPalette.setColorGroup(QPalette::Active,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, Qt::gray,QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Normal,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Inactive,Qt::white,QColor(53, 53, 53),Qt::white,Qt::black,Qt::gray,Qt::white,Qt::red, QColor(25, 25, 25),QColor(53, 53, 53));
//    darkPalette.setColorGroup(QPalette::Disabled,Qt::white,QColor(73, 73, 73),Qt::white,Qt::black,Qt::gray,QColor(130,130,130),Qt::red, QColor(53,53,53),QColor(53, 53, 53));
    //                        тип               ,???      ,Кнопка            ,Разделители,???      ,???     ,цвет текста на кнопке,???  ,поле сзади     ,???
    //ui->GroupBoxDarkTheme->setPalette(darkPalette);
    //ui->GroupBoxWhiteTheme->setPalette(style()->standardPalette());
}

void FormCommonSettings::comboBoxThemeIndexChanged(int aIndex) {
    switch (aIndex) {
    case 0: {
        Settings::setTheme(3);
        emit s_settingsUpdated(changedSettings::theme);
        break;
    }
    case 1: {
        Settings::setTheme(2);
        emit s_settingsUpdated(changedSettings::theme);
        break;
    }
    case 2: {
        Settings::setTheme(1);
        emit s_settingsUpdated(changedSettings::theme);
        break;
    }
    case 3: {
        Settings::setTheme(4);
        emit s_settingsUpdated(changedSettings::theme);
        break;
    }
    case 4: {
        Settings::setTheme(5);
        emit s_settingsUpdated(changedSettings::theme);
        break;
    }
    case 5: {
        Settings::setTheme(6);
        emit s_settingsUpdated(changedSettings::theme);
        break;
    }
    case 6: {
        Settings::setTheme(7);
        emit s_settingsUpdated(changedSettings::theme);
        break;
    }
    case 7: {
        Settings::setTheme(8);
        emit s_settingsUpdated(changedSettings::theme);
        break;
    }
    case 8: {
        ColorPicker *picker = new ColorPicker(this);
        picker->show();
        connect(picker, &ColorPicker::s_pickerClose, this, [=](bool lIsAccept, QColor lColor) {
            if (lIsAccept) {
                customTheme(lColor).save(Paths::documents() + "theme\\custom.json");
                Settings::setTheme(0);
                emit s_settingsUpdated(changedSettings::theme);
            }
        });
//        QColor themeColor = QColorDialog::getColor(Qt::white, this, tr("Выберите цвет"));
//        customTheme(themeColor).save(Paths::documents() + "theme\\custom.json");
//        Settings::setTheme(0);
        break;
    }
    default: {
        break;
    }
    }
}

void FormCommonSettings::comboBoxLanguageIndexChanged(int aIndex) {
    int language = 0;
    QString languageFile = "";
    switch (aIndex) {
    case 0: {
        language = 1;
        languageFile = ":/AraSteamManager_en.qm";
        break;
    }
    case 1: {
        language = 5;
        languageFile = ":/AraSteamManager_ru.qm";
        break;
    }
    default: {
        qWarning() << "unknown language";
        return;
    }
    }
    Settings::setLanguage(language);
    emit s_settingsUpdated(changedSettings::language);
    QTranslator *translator = new QTranslator;
    if (translator->load(languageFile)) {
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
    } else {
        qWarning() << "error change language";
    }
}

void FormCommonSettings::retranslate() {
    ui->retranslateUi(this);
    ui->ComboBoxTheme->setItemText(0, tr("Тёмная"));
    ui->ComboBoxTheme->setItemText(1, tr("Светлая"));
    ui->ComboBoxTheme->setItemText(2, tr("Синяя"));
    ui->ComboBoxTheme->setItemText(3, tr("Оранжевая"));
    ui->ComboBoxTheme->setItemText(4, tr("Малиновая"));
    ui->ComboBoxTheme->setItemText(5, tr("Лаймовая"));
    ui->ComboBoxTheme->setItemText(6, tr("Фиолетовая"));
    ui->ComboBoxTheme->setItemText(7, tr("Зеленая"));
    ui->ComboBoxTheme->setItemText(8, tr("Пользовательская"));
}

void FormCommonSettings::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

void FormCommonSettings::updateIcons() {

}

void FormCommonSettings::slideProfileSize_ValueChanged(int aValue) {
    Settings::setVisibleProfileInfo(aValue);
    emit s_settingsUpdated(changedSettings::profileInfo);
}
