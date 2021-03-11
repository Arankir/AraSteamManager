#include "formmain.h"
#include "ui_formmain.h"
//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
//qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter << 16777220;
//qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//https://ru.stackoverflow.com/questions/952577/qt-network-ssl-qsslsocketconnecttohostencrypted-tls-initialization-failed

#define Init {
FormMain::FormMain(QWidget *parent): QWidget(parent), ui(new Ui::FormMain) {
    ui->setupUi(this);
    initComponents();
    if (Settings::myProfile() != "none") {
        goToProfile(Settings::myProfile(), SProfileRequestType::id);
    }
}

void FormMain::initComponents() {
    createFormContainerAchievements();

    ui->StackedFormFriends  ->setWhatsThis("FormFriends");
    ui->StackedFormGames    ->setWhatsThis("FormGames");
    ui->StackedFormFavorites->setWhatsThis("FormFavorites");
    ui->StackedFormSettings ->setWhatsThis("FormSettings");

    ui->FormProgressBar->setVisible(false);
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
    qApp->setStyleSheet(Settings::qssTheme());
    setIcons();
#define Connects {
    connect(ui->ButtonFindProfile,      &QPushButton::clicked,              this,                       &FormMain::buttonFindProfile_Clicked);
    connect(ui->ButtonGoToMyProfile,    &QPushButton::clicked,              this,                       &FormMain::buttonGoToMyProfile_Clicked);
    connect(ui->ButtonBack,             &QPushButton::clicked,              this,                       &FormMain::buttonBack_Clicked);
    connect(ui->ButtonNext,             &QPushButton::clicked,              this,                       &FormMain::buttonNext_Clicked);
    connect(ui->ButtonSettings,         &QPushButton::clicked,              this,                       &FormMain::buttonSettings_Clicked);
    connect(ui->ButtonUpdate,           &QPushButton::clicked,              this,                       &FormMain::buttonUpdate_Clicked);
    connect(ui->StackedFormFriends,     &FormFriends::s_goToProfile,        this,                       &FormMain::goToProfile);
    connect(ui->StackedFormGames,       &FormGames::s_showAchievements,     this,                       &FormMain::addAchievements);

    connect(ui->StackedFormFriends,     &FormFriends::s_friendsLoaded,      ui->FormProgressBar,        &QProgressBar::setValue);
    connect(ui->StackedFormGames,       &FormGames::s_achievementsLoaded,   ui->FormProgressBar,        &QProgressBar::setValue);

    connect(ui->StackedFormFriends,     &FormFriends::s_finish,             this,                       [=]() {showForm(FormMainFriends);});
    connect(ui->StackedFormGames,       &FormGames::s_finish,               this,                       [=](int aWidth) {showForm(FormMainGames, aWidth);});

    connect(ui->StackedFormSettings,    &FormSettings::s_updateSettings,    this,                       &FormMain::updateSettings);
    connect(this,                       &FormMain::s_updateSettings,        ui->StackedFormFriends,     &FormFriends::updateSettings);
    connect(this,                       &FormMain::s_updateSettings,        ui->StackedFormGames,       &FormGames::updateSettings);
    connect(this,                       &FormMain::s_updateSettings,        ui->StackedFormFavorites,   &FormFavorites::updateSettings);
#define ConnectsEnd }
}
#define InitEnd }

#define System {
void FormMain::setIcons() {
    ui->ButtonUpdate        ->setIcon(QIcon(Images::update()));
    ui->ButtonGoToMyProfile ->setIcon(QIcon(Images::home()));
    ui->ButtonFindProfile   ->setIcon(QIcon(Images::findProfile()));
    ui->ButtonSettings      ->setIcon(QIcon(Images::settings()));
    ui->ButtonBack          ->setIcon(QIcon(Images::left()));
    ui->ButtonNext          ->setIcon(QIcon(Images::right()));
}

#define ContainerAchievementsStart {
void FormMain::addAchievements(QList<SAchievementPlayer> &aAchievements, SGame &aGames) {
    if (_containerAchievementsForm == nullptr) {
        createFormContainerAchievements();
    }
    FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
    if (currentProfile) {
        ++_achievementsCount;
        _containerAchievementsForm->addFormAchievement(aAchievements, currentProfile->getProfile(), aGames);
        _containerAchievementsForm->show();
    }
}

void FormMain::removeAchievements(int index) {
    Q_UNUSED(index);
    --_achievementsCount;
}

void FormMain::containerAchievementsClose() {
    _achievementsCount = 0;
    disconnect(_containerAchievementsForm);
    if (_containerAchievementsForm->parentWidget()->parentWidget()) {
        _containerAchievementsForm->parentWidget()->parentWidget()->close();
    }
    delete _containerAchievementsForm;
    _containerAchievementsForm = nullptr;
}
#define ContainerAchievementsEnd }

#define FormsStart {

#define FormsCreateStart {
FormProfile *FormMain::createFormProfile(SProfile &aProfile) {
    FormProfile *newFormProfile = new FormProfile(aProfile, this);
    newFormProfile->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum));
    connect(newFormProfile, &FormProfile::s_goToGames,      this,           &FormMain::goToGames);
    connect(newFormProfile, &FormProfile::s_goToFriends,    this,           &FormMain::goToFriends);
    connect(newFormProfile, &FormProfile::s_goToStatistic,  this,           &FormMain::goToStatistics);
    connect(newFormProfile, &FormProfile::s_goToFavorites,  this,           &FormMain::goToFavorites);
    connect(newFormProfile, &FormProfile::s_myProfileChange,this,           &FormMain::updateSettings);
    connect(this,           &FormMain::s_updateSettings,    newFormProfile, &FormProfile::updateSettings);
    return newFormProfile;
}

FormStatistics *FormMain::createFormStatistics(const SProfile &aProfile, QList<SGame> &aGames, const QString &aName) {
    _statisticsForm = new FormStatistics(aProfile, aGames, aName, this);
    connect(this,            &FormMain::s_updateSettings,         _statisticsForm,      &FormStatistics::updateSettings);
    connect(_statisticsForm, &FormStatistics::s_statisticsLoaded, ui->FormProgressBar,  &QProgressBar::setValue);
    connect(_statisticsForm, &FormStatistics::s_finish,           this,                 [=]() {
                                                                                            showForm(FormMainStatistic);
                                                                                        });
    return _statisticsForm;
}

FormContainerAchievements *FormMain::createFormContainerAchievements() {
    FramelessWindow *f = new FramelessWindow;
    _containerAchievementsForm = new FormContainerAchievements(f);
    f->setWidget(_containerAchievementsForm);
    connect(_containerAchievementsForm, &FormContainerAchievements::s_removeAchievements, this, &FormMain::removeAchievements);
    connect(_containerAchievementsForm, &FormContainerAchievements::s_formClose,          this, &FormMain::containerAchievementsClose);
    //++_windowChildCount;
    return _containerAchievementsForm;
}
#define FormsCreateEnd }

#define GoToFormStart {
void FormMain::goToProfile(const QString &aId, SProfileRequestType aType) {
    SProfile profile = SProfile::load(aId, aType);
    if(profile != SProfile()) {
        returnFromForms();
        if(ui->StackedWidgetProfiles->currentIndex() != ui->StackedWidgetProfiles->count() - 1) {
            while(ui->StackedWidgetProfiles->count() - 1 != ui->StackedWidgetProfiles->currentIndex()) {
                ui->StackedWidgetProfiles->removeWidget(ui->StackedWidgetProfiles->widget(ui->StackedWidgetProfiles->currentIndex() + 1));
            }
        }
        ui->StackedWidgetProfiles->addWidget(createFormProfile(profile));
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->count() - 1);
        updateSettings();
        updateEnabledButtonsBackNext();
        qInfo() << "Буфер профилей" << ui->StackedWidgetProfiles->currentIndex() + 1 << "/" << ui->StackedWidgetProfiles->count();
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удаётся найти профиль!"));
        qWarning() << "profileError";
    }
}

void FormMain::goToGames(SProfile &aProfile, QList<SGame> &aGames) {
    if(!_blockedLoad) {
        if (!ui->StackedFormGames->isInit()) {
            _blockedLoad = true;
            ui->StackedFormGames->setGames(aProfile, aGames);
            ui->FormProgressBar->setMaximum(aGames.count());
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(FormMainNone);
        } else {
            if (ui->StackedFormGames->isLoaded()) {
                ui->StackedWidgetForms->setCurrentIndex(FormMainGames);
            }
        }
    }
}

void FormMain::goToFriends(const QString &aSteamId, QList<SFriend> &aFriends) {
    if(!_blockedLoad) {
        if (!ui->StackedFormFriends->isInit()) {
            _blockedLoad = true;
            ui->StackedFormFriends->setFriends(aSteamId, aFriends);
            ui->FormProgressBar->setMaximum(aFriends.count());
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(FormMainNone);
        } else {
            if (ui->StackedFormFriends->isLoaded()) {
                ui->StackedWidgetForms->setCurrentIndex(FormMainFriends);
            }
        }
    }
}

void FormMain::goToFavorites() {
    if(!_blockedLoad) {
        //if (!ui->StackedFormFavorites->isInit()) {
            //_blockedLoad = true;
            //ui->FormProgressBar->setMaximum(aFriends.getCount());
            //ui->FormProgressBar->setVisible(true);
            //ui->StackedWidgetForms->setCurrentIndex(FormMainNone);
        //} else {
            if (ui->StackedFormFriends->isLoaded()) {
                ui->StackedWidgetForms->setCurrentIndex(FormMainFavorites);
            }
        //}
    }
}

void FormMain::goToStatistics(const SProfile &aId, QList<SGame> &aGames, const QString &aProfileName) {
    if(_statisticsForm == nullptr) {
        if(!_blockedLoad) {
            _blockedLoad = true;
            ui->FormProgressBar->setMaximum(aGames.count());
            ui->ScrollAreaStatistic->setWidget(createFormStatistics(aId, aGames, aProfileName));
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(FormMainNone);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(FormMainStatistic);
    }
}
#define GoToFormEnd }

void FormMain::showForm(int aWidgetIndex, int aWidthWindow, int aWindowHeight) {
    ui->FormProgressBar->setVisible(false);
    _blockedLoad = false;
    ui->StackedWidgetForms->setCurrentIndex(aWidgetIndex);
    resizeScrollArea(aWidthWindow, aWindowHeight);
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
#define FormsEnd }

#define EventsStart {
void FormMain::keyPressEvent(QKeyEvent *aEvent) {
    if(aEvent->key() == Qt::Key_Enter) {
        buttonFindProfile_Clicked();
    }
}

void FormMain::changeEvent(QEvent *aEvent) {
    if (aEvent->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}

void FormMain::closeEvent(QCloseEvent *aEvent) {
    if (parentWidget()->parentWidget()) {
        Settings::setMainWindowIsMaximize(parentWidget()->parentWidget()->isMaximized());
        Settings::setMainWindowParams(parentWidget()->parentWidget()->normalGeometry());
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

void FormMain::updateSettings() {
    Settings::syncronizeSettings();
//TODO исправить ресайз профилей на нормальный вариант
    switch (Settings::profileInfoSize()) {
    case 0: {
        ui->StackedWidgetProfiles->setFixedHeight(50);
        break;
    }
    case 1: {
        ui->StackedWidgetProfiles->setFixedHeight(140);
        break;
    }
    case 2: {
        ui->StackedWidgetProfiles->setFixedHeight(320);
        break;
    }
    }
    FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
    if (currentProfile) {
        ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile().steamID() != Settings::myProfile());
    }
    qApp->setStyleSheet(Settings::qssTheme());
    setIcons();
    emit s_updateSettings();
}

void FormMain::resizeScrollArea(int aWidth, int aHeight) {
    if((ui->StackedWidgetForms->height() < 400) || (ui->StackedWidgetForms->width() < aWidth)) {
        FramelessWindow *parent = dynamic_cast<FramelessWindow*>(parentWidget()->parent());
        if (parent) {
            parent->animateResize(parentWidget()->width() - ui->StackedWidgetForms->width() + std::max(ui->StackedWidgetForms->width(), aWidth),
                                  parentWidget()->height() - ui->StackedWidgetForms->height() + std::max(ui->StackedWidgetForms->height(), aHeight));
            //qDebug()<<this->width()+a_width-ui->StackedWidgetForms->width()<<this->width()<<a_width<<ui->StackedWidgetForms->width();
//            QPropertyAnimation *animation = new QPropertyAnimation(parentWidget(), "size");
//            connect(animation, &QPropertyAnimation::finished, animation, &QPropertyAnimation::deleteLater);
//            animation->setDuration(500);
//            animation->setStartValue(QSize(parentWidget()->width(), parentWidget()->height()));
//            animation->setEndValue(QSize(parentWidget()->width() + aWidth - ui->StackedWidgetForms->width(), parentWidget()->height() - ui->StackedWidgetForms->height() + 400));
            //animation->start();
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
    QRegExp regExpProfileUrl("^(https:\\/\\/)?(steamcommunity\\.com\\/)?((profiles|id)\\/)?(\\d{17}|\\w+)\\/?$");
    if (regExpProfileUrl.indexIn(ui->LineEditIdProfile->text()) < 0) {
        qWarning() << "Не распознан профиль" << ui->LineEditIdProfile->text();
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось распознать синтаксис профиля"));
        return;
    }

    if ((regExpProfileUrl.cap(4) == "profiles") || (QRegExp("\\d{17}").indexIn(regExpProfileUrl.cap(5)) >= 0)) {
        goToProfile(regExpProfileUrl.cap(5), SProfileRequestType::id);
    } else {
        goToProfile(regExpProfileUrl.cap(5), SProfileRequestType::vanity);
    }
    returnFromForms();
}

void FormMain::updateEnabledButtonsBackNext() {
    ui->ButtonBack->setEnabled(ui->StackedWidgetProfiles->currentIndex() > 0);
    ui->ButtonNext->setEnabled(ui->StackedWidgetProfiles->currentIndex() != ui->StackedWidgetProfiles->count() - 1);
}

void FormMain::buttonBack_Clicked() {
    if(ui->StackedWidgetProfiles->currentIndex() > 0) {
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->currentIndex() - 1);
        returnFromForms();
        FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
        if (currentProfile) {
            ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile().steamID() != Settings::myProfile());
        }
        updateEnabledButtonsBackNext();
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
        updateEnabledButtonsBackNext();
    }
}

void FormMain::buttonSettings_Clicked() {
    if(!_blockedLoad) {
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
        goToProfile(Settings::myProfile(), SProfileRequestType::id);
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удаётся найти профиль!"));
    }
}

void FormMain::buttonUpdate_Clicked() {
    FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
    if (currentProfile) {
        currentProfile->updateInfo();
    }
}
#define FunctionsEnd }
