#include "formmain.h"
#include "ui_formmain.h"
//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
//qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter << 16777220;
//qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//https://ru.stackoverflow.com/questions/952577/qt-network-ssl-qsslsocketconnecttohostencrypted-tls-initialization-failed

#define Init {
FormMain::FormMain(QWidget *parent): Form(parent), ui(new Ui::FormMain) {
    ui->setupUi(this);
    initComponents();
    if (Settings::myProfile() != "none") {
        goToProfile(Settings::myProfile(), SProfile::LoadType::id);
    }
}

void FormMain::initComponents() {
    createFormContainerAchievements();

    ui->StackedFormFriends  ->setWhatsThis("FormFriends");
    ui->StackedFormGames    ->setWhatsThis("FormGames");
    ui->StackedFormFavorites->setWhatsThis("FormFavorites");
    ui->StackedFormSettings ->setWhatsThis("FormSettings");

    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
    ui->StackedWidgetForms->setCurrentIndex(0);

    if (parentWidget() != nullptr) {
        parentWidget()->setGeometry(Settings::mainWindowGeometry());
        parentWidget()->move(Settings::mainWindowPos());

        if(Settings::isMainWindowMaximize()) {
            parentWidget()->showMaximized();
        }
    }
    qApp->setStyleSheet(Theme::qssTheme());
    updateIcons();
#define Connects {
    connect(ui->ButtonFindProfile,      &QPushButton::clicked,              this,                       &FormMain::buttonFindProfile_Clicked);
    connect(ui->ButtonGoToMyProfile,    &QPushButton::clicked,              this,                       &FormMain::buttonGoToMyProfile_Clicked);
    connect(ui->ButtonBack,             &QPushButton::clicked,              this,                       &FormMain::buttonBack_Clicked);
    connect(ui->ButtonNext,             &QPushButton::clicked,              this,                       &FormMain::buttonNext_Clicked);
    connect(ui->ButtonSettings,         &QPushButton::clicked,              this,                       &FormMain::buttonSettings_Clicked);
    connect(ui->ButtonUpdate,           &QPushButton::clicked,              this,                       &FormMain::buttonUpdate_Clicked);
    connect(ui->StackedFormFriends,     &FormFriends::s_goToProfile,        this,                       &FormMain::goToProfile);
    connect(ui->StackedFormGames,       &FormGames::s_showAchievements,     this,                       &FormMain::showAchievements);

    connect(ui->StackedFormFriends,     &FormFriends::s_friendsLoaded,      this,                       &Form::setStatus);
    connect(ui->StackedFormGames,       &FormGames::s_achievementsLoaded,   this,                       &Form::setStatus);

    connect(ui->StackedFormFriends,     &FormFriends::s_finish,             this,                       [=](int aWidth) {
        clearStatus();
        showForm(FormMainFriends, aWidth);
    });
    connect(ui->StackedFormGames,       &FormGames::s_finish,               this,                       [=](int aWidth) {
        clearStatus();
        showForm(FormMainGames, aWidth);
    });

    connect(ui->StackedFormSettings,    &FormSettings::s_settingsUpdated,   this,                       &FormMain::updateSettings);
    connect(this,                       &FormMain::s_settingsUpdated,       ui->StackedFormFriends,     &FormFriends::updateSettings);
    connect(this,                       &FormMain::s_settingsUpdated,       ui->StackedFormGames,       &FormGames::updateSettings);
    connect(this,                       &FormMain::s_settingsUpdated,       ui->StackedFormFavorites,   &FormFavorites::updateSettings);
#define ConnectsEnd }
}
#define InitEnd }

#define System {
#define ContainerAchievementsStart {
void FormMain::showAchievements(const SGame aGames) {
    if (_containerAchievementsForm == nullptr) {
        createFormContainerAchievements();
    }
    if (FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())) {
        _containerAchievementsForm->show();
        _containerAchievementsForm->addFormAchievement(currentProfile->getProfile(), aGames);
    }
}

void FormMain::removeAchievements(int index) {
    Q_UNUSED(index);
}

void FormMain::containerAchievementsClose() {
    disconnect(_containerAchievementsForm);
    delete _containerAchievementsForm;
    _containerAchievementsForm = nullptr;
}
#define ContainerAchievementsEnd }

#define FormsStart {

#define FormsCreateStart {
FormProfile *FormMain::createFormProfile(const SProfile &aProfile) {
    FormProfile *newFormProfile = new FormProfile(aProfile, this);
    newFormProfile->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum));
    connect(newFormProfile, &FormProfile::s_goToGames,      this,           &FormMain::goToGames);
    connect(newFormProfile, &FormProfile::s_goToFriends,    this,           &FormMain::goToFriends);
    connect(newFormProfile, &FormProfile::s_goToStatistic,  this,           &FormMain::goToStatistics);
    connect(newFormProfile, &FormProfile::s_goToFavorites,  this,           &FormMain::goToFavorites);
    connect(this,           &FormMain::s_settingsUpdated,   newFormProfile, &FormProfile::updateSettings);
    connect(newFormProfile, &Form::s_settingsUpdated,       this,           &Form::updateSettings);
    return newFormProfile;
}

FormStatistics *FormMain::createFormStatistics(const SProfile &aProfile, const SGames &aGames) {
    _statisticsForm = new FormStatistics(aProfile, aGames, this);
    connect(this,            &FormMain::s_settingsUpdated,         _statisticsForm,     &FormStatistics::updateSettings);
    connect(_statisticsForm, &FormStatistics::s_showAchievements, this,                 &FormMain::showAchievements);
//    connect(_statisticsForm, &FormStatistics::s_statisticsLoaded, this,                 &Form::setStatus);
    connect(_statisticsForm, &FormStatistics::s_finish,           this,                 [=]() {
        clearStatus();
        showForm(FormMainStatistic);
    });
    return _statisticsForm;
}

FormContainerAchievements *FormMain::createFormContainerAchievements() {
    _containerAchievementsForm = createFramelessForm<FormContainerAchievements>();
    connect(this, &Form::s_settingsUpdated, _containerAchievementsForm->window(), &FramelessWindow::updateSettings);
    connect(this, &Form::s_settingsUpdated, _containerAchievementsForm, &Form::updateSettings);
    connect(_containerAchievementsForm, &FormContainerAchievements::s_removeAchievements,   this, &FormMain::removeAchievements);
    connect(_containerAchievementsForm, &FormContainerAchievements::s_closed,               this, &FormMain::containerAchievementsClose);
    return _containerAchievementsForm;
}
#define FormsCreateEnd }

#define GoToFormStart {
void FormMain::goToProfile(const ProfileID &aId, SProfile::LoadType aType) {
    SProfile profile = SProfile::load(aId, aType);
    if(!profile.isNull()) {
        returnFromForms();
        while(ui->StackedWidgetProfiles->count() - 1 != ui->StackedWidgetProfiles->currentIndex()) {
            ui->StackedWidgetProfiles->removeWidget(ui->StackedWidgetProfiles->widget(ui->StackedWidgetProfiles->currentIndex() + 1));
        }
        ui->StackedWidgetProfiles->addWidget(createFormProfile(profile));
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->count() - 1);
        updateSettings(changedSettings::myProfile);
        updateProfileNavigation();

        qInfo() << "Буфер профилей" << ui->StackedWidgetProfiles->currentIndex() + 1 << "/" << ui->StackedWidgetProfiles->count();
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удаётся найти профиль!"));
        qWarning() << "profileError";
    }
}

void FormMain::goToGames(const SProfile &aProfile, const SGames &aGames) {
    if (!_isLoading) {
        if (!ui->StackedFormGames->isInit()) {
            _isLoading = true;
            ui->StackedWidgetForms->setCurrentIndex(FormMainNone);
            ui->StackedFormGames->setGames(aProfile, aGames);
        } else {
            ui->StackedWidgetForms->setCurrentIndex(FormMainGames);
        }
    }
}

void FormMain::goToFriends(const ProfileID &aSteamId, const SFriends &aFriends) {
    if(!_isLoading) {
        if (!ui->StackedFormFriends->isInit()) {
            _isLoading = true;
            ui->StackedWidgetForms->setCurrentIndex(FormMainNone);
            ui->StackedFormFriends->setFriends(aSteamId, aFriends);
        } else {
            ui->StackedWidgetForms->setCurrentIndex(FormMainFriends);
        }
    }
}

void FormMain::goToFavorites() {
    if(!_isLoading) {
        //if (!ui->StackedFormFavorites->isInit()) {
            //_blockedLoad = true;
            //ui->FormProgressBar->setMaximum(aFriends.getCount());
            //ui->FormProgressBar->setVisible(true);
            //ui->StackedWidgetForms->setCurrentIndex(FormMainNone);
        //} else {
            if (ui->StackedFormFavorites->isLoaded()) {
                ui->StackedWidgetForms->setCurrentIndex(FormMainFavorites);
            }
        //}
    }
}

void FormMain::goToStatistics(const SProfile &aId, SGames &aGames) {
    if(_statisticsForm == nullptr) {
        if(!_isLoading) {
            _isLoading = true;
            ui->StackedWidgetForms->setCurrentIndex(FormMainNone);
            ui->ScrollAreaStatistic->setWidget(createFormStatistics(aId, aGames));
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(FormMainStatistic);
    }
}
#define GoToFormEnd }

void FormMain::showForm(int aWidgetIndex, int aWindowWidth, int aWindowHeight) {
    _isLoading = false;
    ui->StackedWidgetForms->setCurrentIndex(aWidgetIndex);
    resizeScrollArea(aWindowWidth, aWindowHeight);
}

void FormMain::returnFromForms() {
    ui->StackedFormGames->clear();
    ui->StackedFormFriends->clear();
    if(_statisticsForm != nullptr) {
        disconnect(_statisticsForm);
        delete _statisticsForm;
        _statisticsForm = nullptr;
    }
//    if(_favoritesForm != nullptr) {
//        disconnect(_favoritesForm);
//        delete _favoritesForm;
//        _favoritesForm = nullptr;
//    }
//    if(_settingsForm != nullptr) {
//        disconnect(_settingsForm);
//        delete _settingsForm;
//        _settingsForm = nullptr;
//    }
    ui->StackedWidgetForms->setCurrentIndex(0);
}

void FormMain::retranslate() {
    ui->retranslateUi(this);
}
#define FormsEnd }

#define EventsStart {
void FormMain::keyPressEvent(QKeyEvent *aEvent) {
    if(aEvent->key() == Qt::Key_Enter) {
        buttonFindProfile_Clicked();
    }
}

void FormMain::closeEvent(QCloseEvent *aEvent) {
    if (window()) {
        Settings::setMainWindowIsMaximize(window()->isMaximized());
        Settings::setMainWindowParams(window()->normalGeometry());
    }
    Settings::syncronizeSettings();
    if (_containerAchievementsForm) {
        _containerAchievementsForm->close();
    }
    qInfo() << "Programm closed";
    qApp->closeAllWindows();
    aEvent->accept();
}
#define EventsEnd }

FormMain::~FormMain() {
    //может быть ошибка
    returnFromForms();
    if (_containerAchievementsForm != nullptr) {
        delete _containerAchievementsForm;
    }
    qInfo() << "Главная форма удалилась";
    delete ui;
}

void FormMain::updateSettings(QFlags<changedSettings> aSettings) {
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
        qApp->setStyleSheet(Theme::qssTheme());
        updateIcons();
    }
    emit s_settingsUpdated(aSettings);
}

void FormMain::updateIcons() {
    ui->ButtonUpdate        ->setIcon(QIcon(Images::update()));
    ui->ButtonGoToMyProfile ->setIcon(QIcon(Images::home()));
    ui->ButtonFindProfile   ->setIcon(QIcon(Images::findProfile()));
    ui->ButtonSettings      ->setIcon(QIcon(Images::settings()));
    ui->ButtonBack          ->setIcon(QIcon(Images::left()));
    ui->ButtonNext          ->setIcon(QIcon(Images::right()));
}

void FormMain::resizeScrollArea(int aWidth, int aHeight) {
    int newWidth = std::max(ui->StackedWidgetForms->width(), aWidth);
    int newHeight = std::max(ui->StackedWidgetForms->height(), aHeight);
    if((ui->StackedWidgetForms->height() < newHeight) || (ui->StackedWidgetForms->width() < newWidth)) {
        if (FramelessWindow *parent = window()) {
            parent->animateResize(window()->width() - ui->StackedWidgetForms->width() + newWidth,
                                  window()->height() - ui->StackedWidgetForms->height() + newHeight);
        }
    }
}
#define SystemEnd }

#define Functions {
void FormMain::buttonFindProfile_Clicked() {
    //https://steamcommunity.com/profiles/76561198017985018/
    //https://steamcommunity.com/id/xFrenzy47x
    //steamcommunity.com/profiles/76561198017985018/
    //steamcommunity.com/id/xFrenzy47x
    //76561198017985018
    //xFrenzy47x
    QRegularExpression ProfileUrl("^(https:\\/\\/)?(steamcommunity\\.com\\/)?((profiles|id)\\/)?(\\d{17}|\\w+)\\/?$");
    auto match = ProfileUrl.match(ui->LineEditIdProfile->text());
    if (!match.hasMatch()) {
        qWarning() << "Не распознан профиль" << ui->LineEditIdProfile->text();
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось распознать синтаксис профиля"));
        return;
    }

    if ((match.captured(4) == "profiles") || (QRegularExpression("\\d{17}").match(match.captured(5)).hasMatch())) {
        goToProfile(match.captured(5), SProfile::LoadType::id);
    } else {
        goToProfile(match.captured(5), SProfile::LoadType::vanity);
    }
    returnFromForms();
}

void FormMain::buttonBack_Clicked() {
    if(ui->StackedWidgetProfiles->currentIndex() > 0) {
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex() - 1);
        returnFromForms();
        FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
        if (currentProfile) {
            ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile().steamID() != Settings::myProfile());
        }
        updateProfileNavigation();
    }
}

void FormMain::buttonNext_Clicked() {
    if(ui->StackedWidgetProfiles->currentIndex() < ui->StackedWidgetProfiles->count()) {
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex() + 1);
        returnFromForms();
        FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
        if (currentProfile) {
            ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile().steamID() != Settings::myProfile());
        }
        updateProfileNavigation();
    }
}

void FormMain::updateProfileNavigation() {
    ui->ButtonBack->setEnabled(ui->StackedWidgetProfiles->currentIndex() > 0);
    ui->ButtonNext->setEnabled(ui->StackedWidgetProfiles->currentIndex() != ui->StackedWidgetProfiles->count() - 1);
}

void FormMain::buttonSettings_Clicked() {
    if(!_isLoading) {
        //if (!ui->StackedFormSettings->isInit()) {
            //_blockedLoad = true;
            //ui->FormProgressBar->setMaximum(aFriends.getCount());
            //ui->FormProgressBar->setVisible(true);
            //ui->StackedWidgetForms->setCurrentIndex(FormMainNone);
        //} else {
            if (ui->StackedFormSettings->isLoaded()) {
                ui->StackedWidgetForms->setCurrentIndex(FormMainSettings);
            }
        //}
    }
}

void FormMain::buttonGoToMyProfile_Clicked() {
    if(Settings::myProfile() != "none") {
        goToProfile(Settings::myProfile(), SProfile::LoadType::id);
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удаётся найти профиль!"));
    }
}

void FormMain::buttonUpdate_Clicked() {
    if (FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget())) {
        currentProfile->updateInfo();
    }
    updateSettings(changedSettings::theme);
}
#define FunctionsEnd }
