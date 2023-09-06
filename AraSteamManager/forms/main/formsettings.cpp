#include "formsettings.h"
#include "ui_formsettings.h"
#include "version.h"

FormSettings::FormSettings(QWidget *aParent): Form(aParent), ui(new Ui::FormSettings) {
    ui->setupUi(this);
    init();
}

void FormSettings::update() {
    ui->importExport->update();
    ui->commonSettings->update();
}

FormSettings::~FormSettings() {
    delete ui;
}

void FormSettings::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
}

bool FormSettings::isInit() {
    return isInit_;
}

bool FormSettings::isLoaded() {
    return isInit_;
}

void FormSettings::init() {
    ui->tabWidget->setAttribute(Qt::WA_TranslucentBackground);

    ui->tabWidget->setCurrentIndex(0);
    ui->labelVersion->setText(VER_PRODUCTVERSION_STR);

    connect(ui->commonSettings, &FormCommonSettings::s_settingsUpdated, this, [this](QFlags<changedSettings> lSettings) {
        emit s_settingsUpdated(lSettings);
    });

    retranslate();
    isInit_ = true;
}

void FormSettings::retranslate() {
    ui->retranslateUi(this);
}

void FormSettings::updateIcons() {

}
