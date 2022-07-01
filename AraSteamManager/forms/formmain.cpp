#include "formmain.h"
#include "ui_formmain.h"
#include "classes/common/theme.h"
//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
//qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter << 16777220;
//qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//https://ru.stackoverflow.com/questions/952577/qt-network-ssl-qsslsocketconnecttohostencrypted-tls-initialization-failed

enum stackedForms {
    FormNone        = 0,
    FormGames       = 1,
    FormFriends     = 2,
    FormStatistic   = 3,
    FormFavorites   = 4,
    FormSettings    = 5
};

FormMain::FormMain(QWidget *parent): Form(parent), ui(new Ui::FormMain) {
    ui->setupUi(this);
    init();
    if (Settings::myProfile() != "") {
        goToProfile(Settings::myProfile());
    }
}

void FormMain::init() {
    ui->stackedFormFriends      ->setObjectName("FormFriends");
    ui->stackedFormGames        ->setObjectName("FormGames");
    ui->stackedFormFavorites    ->setObjectName("FormFavorites");
    ui->stackedFormSettings     ->setObjectName("FormSettings");
    ui->stackedFormStatistics   ->setObjectName("StatisticForm");
    ui->stackedFormFriends      ->setAttribute(Qt::WA_TranslucentBackground);
    ui->stackedFormGames        ->setAttribute(Qt::WA_TranslucentBackground);
    ui->stackedFormFavorites    ->setAttribute(Qt::WA_TranslucentBackground);
    ui->stackedFormSettings     ->setAttribute(Qt::WA_TranslucentBackground);
    ui->stackedFormStatistics   ->setAttribute(Qt::WA_TranslucentBackground);

//    if (window() != nullptr) {
//        window()->restoreGeometry(Settings::mainWindowGeometry());
//        window()->restoreState(Settings::mainWindowState());

////        parentWidget()->setGeometry(Settings::mainWindowParams());
////        parentWidget()->move(Settings::mainWindowPos());

////        if(Settings::isMainWindowMaximize()) {
////            parentWidget()->showMaximized();
////        }
//    }
    ui->stackedWidgetForms->setCurrentIndex(0);
    qApp->setStyleSheet(Theme::qssTheme());
    updateIcons();

    connect(ui->profilesBrowser,        &FormProfilesBrowser::s_profileChanged,this,                       [&](const ProfileID &) {
        returnFromForms();
    });
    connect(ui->profilesBrowser,        &FormProfilesBrowser::s_favoritesClicked,this,                  &FormMain::goToFavorites);
    connect(ui->profilesBrowser,        &FormProfilesBrowser::s_settingsClicked,this,                   &FormMain::goToSettings);
    connect(ui->profilesBrowser,        &FormProfilesBrowser::s_friendsClicked,this,                    &FormMain::goToFriends);
    connect(ui->profilesBrowser,        &FormProfilesBrowser::s_gamesClicked,this,                      &FormMain::goToGames);
    connect(ui->profilesBrowser,        &FormProfilesBrowser::s_statisticsClicked,this,                 &FormMain::goToStatistics);
    connect(ui->stackedFormFriends,     &FormFriends::s_goToProfile,        this,                       &FormMain::goToProfile);
    connect(ui->stackedFormGames,       &FormGames::s_showAchievements,     this,                       &FormMain::showAchievements);
    connect(ui->stackedFormStatistics,  &FormStatistics::s_showAchievements,this,                       &FormMain::showAchievements);

    connect(ui->stackedFormGames,       &FormGames::s_achievementsLoaded,   this,                       &Form::setStatus);

    connect(ui->stackedFormFriends,     &FormFriends::s_finish,             this,                       [&](int aWidth) {
        clearStatus();
        showForm(FormFriends, aWidth);
    });
    connect(ui->stackedFormGames,       &FormGames::s_finish,               this,                       [&](int aWidth) {
        clearStatus();
        showForm(FormGames, aWidth);
    });
    connect(ui->stackedFormStatistics, &FormStatistics::s_finish,           this,                       [&]() {
        clearStatus();
        showForm(FormStatistic);
    });

    connect(ui->stackedFormSettings,    &FormSettings::s_settingsUpdated,   this,                       &FormMain::updateSettings);
    connect(this,                       &FormMain::s_settingsUpdated,       ui->stackedFormFriends,     &FormFriends::updateSettings);
    connect(this,                       &FormMain::s_settingsUpdated,       ui->stackedFormGames,       &FormGames::updateSettings);
    connect(this,                       &FormMain::s_settingsUpdated,       ui->stackedFormFavorites,   &FormFavorites::updateSettings);
    connect(this,                       &FormMain::s_settingsUpdated,       ui->profilesBrowser,        &FormProfilesBrowser::updateSettings);
    connect(this,                       &FormMain::s_settingsUpdated,       ui->stackedFormStatistics,  &FormStatistics::updateSettings);


//    QtDownload dl;
//    dl.setTarget("http://www.java2s.com/Code/Cpp/Qt/DownloadfromURL.htm");
//    auto movie = new QMovie(this);
//    movie->setFileName("C:\\Users\\Pavel\\Desktop\\GenerousColossalCurlew-size_restricted.gif");
//    connect(movie, &QMovie::frameChanged, [=]{
//        ui->pushButton->setIcon(movie->currentPixmap());
//    });
//    movie->start();
//    ui->pushButton->setIconSize(QSize(movie->currentPixmap().size()));
//    ui->pushButton->setFixedSize(QSize(movie->currentPixmap().size()).operator+=(QSize(10, 10)));
}

#define System {
FormMain::~FormMain() {
    if (window()) {
//        Settings::setMainWindowIsMaximize(window()->isMaximized());
//        Settings::setMainWindowParams(window()->normalGeometry());
        Settings::setMainWindowState(window()->saveState());
        Settings::setMainWindowGeometry(window()->saveGeometry());
    }
    if (_containerAchievementsForm) {
        _containerAchievementsForm->close();
    }
    returnFromForms();
    delete ui;
}

void FormMain::retranslate() {
    ui->retranslateUi(this);
}

#define ContainerAchievementsStart {
FormContainerAchievements *FormMain::createFormContainerAchievements() {
    _containerAchievementsForm = createFramelessForm<FormContainerAchievements>();
    _containerAchievementsForm->setObjectName("ContainerAchievements");
    _containerAchievementsForm->window()->setAttribute(Qt::WA_DeleteOnClose);
    _containerAchievementsForm->setAttribute(Qt::WA_DeleteOnClose);
    connect(this, &Form::s_settingsUpdated, _containerAchievementsForm->window(), &FramelessWindow::updateSettings);
    connect(this, &Form::s_settingsUpdated, _containerAchievementsForm, &Form::updateSettings);
    connect(_containerAchievementsForm, &FormContainerAchievements::s_closed,               this, &FormMain::containerAchievementsClose);
    connect(_containerAchievementsForm, &FormContainerAchievements::s_destructed, this, [=]() {
        _containerAchievementsForm = nullptr;
    });
    if (_containerAchievementsForm->window() != nullptr) {
        _containerAchievementsForm->window()->restoreGeometry(Settings::achievementContainerGeometry());
        _containerAchievementsForm->window()->restoreState(Settings::achievementContainerState());
    }
    return _containerAchievementsForm;
}

void FormMain::showAchievements(const SGame &aGame) {
    if (_containerAchievementsForm == nullptr) {
        createFormContainerAchievements();
    }
    _containerAchievementsForm->show();
    _containerAchievementsForm->addFormAchievement(ui->profilesBrowser->currentProfile(), aGame);
}

void FormMain::containerAchievementsClose() {
//    disconnect(_containerAchievementsForm);
    delete _containerAchievementsForm;
}
#define ContainerAchievementsEnd }

#define FormsStart {
#define GoToFormStart {
void FormMain::goToProfile(const ProfileID &aProfileId) {
    ui->profilesBrowser->goToProfile(aProfileId);
}

void FormMain::goToGames(const ProfileID &aProfileId) {
    if (!isLoading_) {
        if (!ui->stackedFormGames->isInit()) {
            isLoading_ = true;
            ui->stackedWidgetForms->setCurrentIndex(FormNone);
            ui->stackedFormGames->setGames(aProfileId);
        } else {
            ui->stackedWidgetForms->setCurrentIndex(FormGames);
        }
    }
}

void FormMain::goToFriends(const ProfileID &aProfileId) {
    if(!isLoading_) {
        if (!ui->stackedFormFriends->isInit()) {
            isLoading_ = true;
            ui->stackedWidgetForms->setCurrentIndex(FormNone);
            ui->stackedFormFriends->setFriends(aProfileId);
        } else {
            ui->stackedWidgetForms->setCurrentIndex(FormFriends);
        }
    }
}

void FormMain::goToStatistics(const SProfile &aProfileId) {
    if(!isLoading_) {
        if (!ui->stackedFormStatistics->isInit()) {
            isLoading_ = true;
            ui->stackedWidgetForms->setCurrentIndex(FormNone);
            ui->stackedFormStatistics->setProfile(aProfileId);
        } else {
            ui->stackedWidgetForms->setCurrentIndex(FormStatistic);
        }
    }

}

void FormMain::goToFavorites() {
    if(!isLoading_) {
        if (!ui->stackedFormFavorites->isInit()) {
            isLoading_ = true;
            ui->stackedWidgetForms->setCurrentIndex(FormNone);
            ui->stackedFormFavorites->init();
            isLoading_ = false;
            ui->stackedWidgetForms->setCurrentIndex(FormFavorites);
        } else {
            ui->stackedWidgetForms->setCurrentIndex(FormFavorites);
        }
    }
}

void FormMain::goToSettings() {
    if(!isLoading_) {
        if (!ui->stackedFormSettings->isInit()) {
            isLoading_ = true;
            ui->stackedWidgetForms->setCurrentIndex(FormNone);
            ui->stackedFormSettings->init();
            isLoading_ = false;
            ui->stackedWidgetForms->setCurrentIndex(FormSettings);
        } else {
            ui->stackedWidgetForms->setCurrentIndex(FormSettings);
        }
    }
}
#define GoToFormEnd }

void FormMain::showForm(int aWidgetIndex, int aWindowWidth, int aWindowHeight) {
    isLoading_ = false;
    ui->stackedWidgetForms->setCurrentIndex(aWidgetIndex);
    resizeScrollArea(aWindowWidth, aWindowHeight);
}

void FormMain::returnFromForms() {
    ui->stackedFormGames->clear();
    ui->stackedFormFriends->clear();
    ui->stackedFormStatistics->clear();
    ui->stackedWidgetForms->setCurrentIndex(FormNone);
}
#define FormsEnd }

void FormMain::closeEvent(QCloseEvent *aEvent) {
    aEvent->accept();
    this->deleteLater();
}

void FormMain::updateSettings(QFlags<changedSettings> aSettings) {
    Settings::syncronizeSettings();
    if (aSettings.testFlag(changedSettings::theme)) {
        qApp->setStyleSheet(Theme::qssTheme());
        updateIcons();
    }
    emit s_settingsUpdated(aSettings);
}

void FormMain::updateIcons() {

}

void FormMain::resizeScrollArea(int aWidth, int aHeight) {
    int formWidth = ui->stackedWidgetForms->width();
    int formHeight = ui->stackedWidgetForms->height();
    int newWidth = std::max(formWidth, aWidth);
    int newHeight = std::max(formHeight, aHeight);
    if((formHeight < newHeight) || (formWidth < newWidth)) {
        if (FramelessWindow *parent = window()) {
            parent->animateResize(window()->width() - formWidth + newWidth,
                                  window()->height() - formHeight + newHeight);
        }
    }
}
#define SystemEnd }
