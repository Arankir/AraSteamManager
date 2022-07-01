#include "formprofilesbrowser.h"
#include "ui_formprofilesbrowser.h"

FormProfilesBrowser::FormProfilesBrowser(QWidget *parent) :
    Form(parent),
    ui(new Ui::FormProfilesBrowser)
{
    ui->setupUi(this);
    updateIcons();
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);

//    ui->LineEditIdProfile->setStyleSheet("QLineEdit[text=\"\"]{ color:gray; }");
//    connect(ui->LineEditIdProfile, &QLineEdit::textChanged, [=]{ style()->polish(ui->LineEditIdProfile); });

    connect(ui->ButtonFindProfile,  &QPushButton::clicked, this, &FormProfilesBrowser::buttonFindProfile_Clicked);
    connect(ui->ButtonBack,         &QPushButton::clicked, this, &FormProfilesBrowser::buttonBack_Clicked);
    connect(ui->ButtonNext,         &QPushButton::clicked, this, &FormProfilesBrowser::buttonNext_Clicked);
    connect(ui->ButtonUpdate,       &QPushButton::clicked, this, &FormProfilesBrowser::buttonUpdate_Clicked);
    connect(ui->ButtonGoToMyProfile,&QPushButton::clicked, this, &FormProfilesBrowser::buttonGoToMyProfile_Clicked);
    connect(ui->ButtonFavorites,    &QPushButton::clicked, this, &FormProfilesBrowser::buttonFavorites_Clicked);
    connect(ui->ButtonSettings,     &QPushButton::clicked, this, &FormProfilesBrowser::buttonSettings_Clicked);
    connect(this, &Form::s_settingsUpdated, ui->LineEditIdProfile, &MyLineEdit::updateSettings);
}

FormProfilesBrowser::~FormProfilesBrowser() {
    while(ui->StackedWidgetProfiles->count() > 0) {
        auto widget = ui->StackedWidgetProfiles->widget(0);
        ui->StackedWidgetProfiles->removeWidget(widget);
        delete widget;
    }
    delete ui;
}

SProfile FormProfilesBrowser::currentProfile() {
    if (FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())) {
        return currentProfile->getProfile();
    }
    return SProfile();
}

void FormProfilesBrowser::keyPressEvent(QKeyEvent *aEvent) {
    if(aEvent->key() == Qt::Key_Enter || aEvent->key() == Qt::Key_Return) {
        buttonFindProfile_Clicked();
    }
}

FormProfile *FormProfilesBrowser::createFormProfile(const SProfile &aProfile) {
    FormProfile *newFormProfile = new FormProfile(aProfile, this);
    newFormProfile->setObjectName(QString("FormProfile_%1").arg(aProfile.personaName()));
    newFormProfile->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum));
    connect(newFormProfile, &FormProfile::s_goToGames,      this,   &FormProfilesBrowser::goToGames);
    connect(newFormProfile, &FormProfile::s_goToFriends,    this,   &FormProfilesBrowser::goToFriends);
    connect(newFormProfile, &FormProfile::s_goToStatistic,  this,   &FormProfilesBrowser::goToStatistics);
    connect(newFormProfile, &FormProfile::s_goToFavorites,  this,   &FormProfilesBrowser::buttonFavorites_Clicked);
    connect(newFormProfile, &Form::s_settingsUpdated,       this,   &Form::updateSettings);
    connect(this,           &FormProfilesBrowser::s_settingsUpdated,   newFormProfile, &FormProfile::updateSettings);
    return newFormProfile;
}

void FormProfilesBrowser::goToProfile(const ProfileID &aId) {
    ProfileID id = aId;
    SProfile::LoadType type = identifyProfileType(id);
    if (type == SProfile::LoadType::unknown) {
        qWarning() << "Не распознан профиль" << ui->LineEditIdProfile->text();
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось распознать синтаксис профиля"));
        return;
    }

    SProfile profile = SProfile::load(aId, type);
    if(!profile.isNull()) {
        emit s_profileChanged(profile.steamID());
        while(ui->StackedWidgetProfiles->count() - 1 != ui->StackedWidgetProfiles->currentIndex()) {
            auto widget = ui->StackedWidgetProfiles->widget(ui->StackedWidgetProfiles->currentIndex() + 1);
            ui->StackedWidgetProfiles->removeWidget(widget);
            delete widget;
        }
        ui->StackedWidgetProfiles->addWidget(createFormProfile(profile));
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->count() - 1);
        updateSettings(changedSettings::myProfile);
        updateProfileNavigation();

//        qInfo() << "Буфер профилей" << ui->StackedWidgetProfiles->currentIndex() + 1 << "/" << ui->StackedWidgetProfiles->count();
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Нет данных о профиле!"));
        qWarning() << "profileError";
    }
}

void FormProfilesBrowser::retranslate() {
    ui->retranslateUi(this);
}

void FormProfilesBrowser::goToGames(const ProfileID &aProfileId) {
    if (!aProfileId.isEmpty() && !aProfileId.isNull()) {
        emit s_gamesClicked(aProfileId);
    }
}

void FormProfilesBrowser::goToFriends(const ProfileID &aProfileId) {
    if (!aProfileId.isEmpty() && !aProfileId.isNull()) {
        emit s_friendsClicked(aProfileId);
    }
}

void FormProfilesBrowser::goToStatistics(const SProfile &aProfile) {
    if (!aProfile.steamID().isEmpty() && !aProfile.steamID().isNull()) {
        emit s_statisticsClicked(aProfile);
    }
}

void FormProfilesBrowser::updateSettings(QFlags<changedSettings> aSettings) {
    Settings::syncronizeSettings();
    if (aSettings.testFlag(changedSettings::myProfile)) {
        for (int i = 0; i < ui->StackedWidgetProfiles->count(); ++i) {
            FormProfile *profile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->widget(i));
            if (profile) {
                profile->updateSettings(changedSettings::myProfile);
            }
        }
        FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
        ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile().steamID() != Settings::myProfile());
    }
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
    emit s_settingsUpdated(aSettings);
}

void FormProfilesBrowser::updateIcons() {
    ui->ButtonUpdate        ->setIcon(QIcon(Images::update()));
    ui->ButtonGoToMyProfile ->setIcon(QIcon(Images::home()));
    ui->ButtonFindProfile   ->setIcon(QIcon(Images::findProfile()));
    ui->ButtonBack          ->setIcon(QIcon(Images::left()));
    ui->ButtonNext          ->setIcon(QIcon(Images::right()));
    ui->ButtonSettings      ->setIcon(QIcon(Images::settings()));
    ui->ButtonFavorites     ->setIcon(QIcon(Images::isNotFavorites()));
}

void FormProfilesBrowser::updateProfileNavigation() {
    ui->ButtonBack->setEnabled(ui->StackedWidgetProfiles->currentIndex() > 0);
    ui->ButtonNext->setEnabled(ui->StackedWidgetProfiles->currentIndex() != ui->StackedWidgetProfiles->count() - 1);
}

SProfile::LoadType FormProfilesBrowser::identifyProfileType(ProfileID &aId) {
    //https://steamcommunity.com/profiles/76561198017985018/
    //https://steamcommunity.com/id/xFrenzy47x
    //steamcommunity.com/profiles/76561198017985018/
    //steamcommunity.com/id/xFrenzy47x
    //76561198017985018
    //xFrenzy47x
    QRegularExpression ProfileUrl("^(https:\\/\\/)?(steamcommunity\\.com\\/)?((profiles|id)\\/)?(\\d{17}|\\w+)\\/?$");
    auto match = ProfileUrl.match(aId);
    if (!match.hasMatch()) {
        return SProfile::LoadType::unknown;
    }

    if ((match.captured(4) == "profiles") || (QRegularExpression("\\d{17}").match(match.captured(5)).hasMatch())) {
        aId = match.captured(5);
        return SProfile::LoadType::id;
    } else {
        aId = match.captured(5);
        return SProfile::LoadType::vanity;
    }
}

void FormProfilesBrowser::buttonFindProfile_Clicked() {
    goToProfile(ui->LineEditIdProfile->text());
}

void FormProfilesBrowser::buttonBack_Clicked() {
    if(ui->StackedWidgetProfiles->currentIndex() > 0) {
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex() - 1);
        FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
        if (currentProfile) {
            emit s_profileChanged(currentProfile->getProfile().steamID());
            ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile().steamID() != Settings::myProfile());
        }
        updateProfileNavigation();
    }
}

void FormProfilesBrowser::buttonNext_Clicked() {
    if(ui->StackedWidgetProfiles->currentIndex() < ui->StackedWidgetProfiles->count()) {
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex() + 1);
        FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
        if (currentProfile) {
            emit s_profileChanged(currentProfile->getProfile().steamID());
            ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile().steamID() != Settings::myProfile());
        }
        updateProfileNavigation();
    }
}

void FormProfilesBrowser::buttonSettings_Clicked() {
    emit s_settingsClicked();
}

void FormProfilesBrowser::buttonFavorites_Clicked() {
    emit s_favoritesClicked();
}

void FormProfilesBrowser::buttonGoToMyProfile_Clicked() {
    if(!Settings::myProfile().isEmpty()) {
        goToProfile(Settings::myProfile());
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удаётся найти профиль!"));
    }
}

void FormProfilesBrowser::buttonUpdate_Clicked() {
    if (FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())) {
        currentProfile->updateInfo();
    }
}
