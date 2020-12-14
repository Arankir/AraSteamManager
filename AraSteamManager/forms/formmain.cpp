#include "formmain.h"
#include "ui_formmain.h"
//    ui->textEdit->setText(document.toJson(QJsonDocument::Compact));
//qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter << 16777220;
//qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
//https://ru.stackoverflow.com/questions/952577/qt-network-ssl-qsslsocketconnecttohostencrypted-tls-initialization-failed

#define Constants {
constexpr int c_formsNone       = 0;
constexpr int c_formsGames      = 1;
constexpr int c_formsFriends    = 2;
constexpr int c_formsStatistic  = 3;
constexpr int c_formsFavorites  = 4;
constexpr int c_formsSettings   = 5;
#define ConstantsEnd }

#define Init {
FormMain::FormMain(QWidget *parent): QWidget(parent), ui(new Ui::FormMain), _games(this) {
    ui->setupUi(this);
    initComponents();
    if (Settings::getMyProfile() != "none") {
        goToProfile(Settings::getMyProfile(), ProfileUrlType::id);
    }
}

void FormMain::initComponents() {
    createFormContainerAchievements();


    ui->FormProgressBar->setVisible(false);
    ui->ButtonBack->setEnabled(false);
    ui->ButtonNext->setEnabled(false);
    ui->StackedWidgetForms->setCurrentIndex(0);

    if (parentWidget() != nullptr) {
        parentWidget()->setGeometry(Settings::getMainWindowGeometry());
        parentWidget()->move(Settings::getMainWindowPos());

        if(Settings::getMainWindowMaximize()) {
            parentWidget()->showMaximized();
        }
    }
    qApp->setStyleSheet(getTheme());
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setColor(QColor(93, 170, 224, 255 * 0.7));
    shadowEffect->setOffset(0);
    shadowEffect->setBlurRadius(50);
    ui->FormProgressBar->setGraphicsEffect(shadowEffect);
#define Connects {
    connect(ui->ButtonFindProfile,   &QPushButton::clicked, this, &FormMain::buttonFindProfile_Clicked);
    connect(ui->ButtonGoToMyProfile, &QPushButton::clicked, this, &FormMain::buttonGoToMyProfile_Clicked);
    connect(ui->ButtonBack,          &QPushButton::clicked, this, &FormMain::buttonBack_Clicked);
    connect(ui->ButtonNext,          &QPushButton::clicked, this, &FormMain::buttonNext_Clicked);
    connect(ui->ButtonSettings,      &QPushButton::clicked, this, &FormMain::buttonSettings_Clicked);
    connect(ui->ButtonUpdate,        &QPushButton::clicked, this, &FormMain::buttonUpdate_Clicked);
#define ConnectsEnd }
}
#define InitEnd }

#define System {
QString FormMain::getTheme() {
    QString qss;
    switch(Settings::getTheme()) {
    case 1:{
        QFile qssFile("://blackTheme.qss");
        qssFile.open(QFile::ReadOnly);
        qss = qssFile.readAll() + " "
        "QRadioButton::indicator::unchecked { "
            "image: url(" + Images::radioButtonUnchecked() + "); "
        "} "
        "QRadioButton::indicator::checked { "
            "image: url(" + Images::radioButtonChecked() + "); "
        "} "
        "QRadioButton::indicator::unchecked:hover { "
            "image: url(" + Images::radioButtonUncheckedHover() + "); "
        "} "
        "QRadioButton::indicator::checked:hover { "
            "image: url(" + Images::radioButtonCheckedHover() + "); "
        "} "
        "QRadioButton::indicator::unchecked:pressed { "
            "image: url(" + Images::radioButtonUncheckedPress() + "); "
        "} "
        "QRadioButton::indicator::checked:pressed { "
            "image: url(" + Images::radioButtonCheckedPress() + "); "
        "} "
        "QCheckBox::indicator:unchecked { "
            "image: url(" + Images::checkBoxUnchecked() + "); "
        "} "
        "QCheckBox::indicator:checked { "
            "image: url(" + Images::checkBoxChecked() + "); "
        "} "
        "QCheckBox::indicator:unchecked:hover { "
            "image: url(" + Images::checkBoxUncheckedHover() + "); "
        "} "
        "QCheckBox::indicator:checked:hover { "
            "image: url(" + Images::checkBoxCheckedHover() + "); "
        "} "
        "QCheckBox::indicator:unchecked:pressed { "
            "image: url(" + Images::checkBoxUncheckedPress() + "); "
        "} "
        "QCheckBox::indicator:checked:pressed { "
            "image: url(" + Images::checkBoxCheckedPress() + "); "
        "} "
        "QComboBox::down-arrow { "
            "image: url(" + Images::comboBoxDown() + "); "
        "} "
        "QTabBar::close-button { "
            "image: url(" + Images::closeWindow() + "); "
        "} "
        "QTableView::indicator:unchecked { "
            "image: url(" + Images::checkBoxUnchecked() + "); "
        "} "
        "QTableView::indicator:checked { "
            "image: url(" + Images::checkBoxChecked() + "); "
        "} "
        "QTableView::indicator:unchecked:hover { "
            "image: url(" + Images::checkBoxUncheckedHover() + "); "
        "} "
        "QTableView::indicator:checked:hover { "
            "image: url(" + Images::checkBoxCheckedHover() + "); "
        "} "
        "QTableView::indicator:unchecked:pressed { "
            "image: url(" + Images::checkBoxUncheckedPress() + "); "
        "} "
        "QTableView::indicator:checked:pressed { "
            "image: url(" + Images::checkBoxCheckedPress() + "); "
        "} "
        "QScrollBar::add-line:vertical { "
            "image: url(" + Images::scrollBarDown() + "); "
        "}"
        "QScrollBar::sub-line:vertical { "
            "image: url(" + Images::scrollBarUp() + "); "
        "}"
        "QScrollBar::add-line:horizontal { "
            "image: url(" + Images::scrollBarRight() + "); "
        "}"
        "QScrollBar::sub-line:horizontal { "
            "image: url(" + Images::scrollBarLeft() + "); "
        "}"
        "QGroupBox#GroupBoxFilter::title { "
            "image: url(" + Images::filter() + "); "
        "} ";
        break;
    }
    case 2:{
        break;
    }
    default: {
        // Настраиваем палитру для цветовых ролей элементов интерфейса
        //    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::WindowText, Qt::white);
        //    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        //    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        //    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        //    darkPalette.setColor(QPalette::Text, Qt::white);
        //    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        //    darkPalette.setColor(QPalette::ButtonText, Qt::white);
        //    darkPalette.setColor(QPalette::BrightText, Qt::red);
        //    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        //    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
        // Устанавливаем данную палитру
            // Для возврата к светлой палитре достаточно
            // будет установить стандартную палитру из темы оформления
            //qApp->setPalette(style()->standardPalette());
        break;
    }
    }
    setIcons();
    return qss;
}

void FormMain::setIcons() {
    ui->ButtonUpdate        ->setIcon(QIcon(Images::update()));
    ui->ButtonGoToMyProfile ->setIcon(QIcon(Images::home()));
    ui->ButtonFindProfile   ->setIcon(QIcon(Images::findProfile()));
    ui->ButtonSettings      ->setIcon(QIcon(Images::settings()));
    ui->ButtonBack          ->setIcon(QIcon(Images::left()));
    ui->ButtonNext          ->setIcon(QIcon(Images::right()));
}

void FormMain::progressLoading(int aProgress, int) {
    ui->FormProgressBar->setValue(aProgress);
}

#define ContainerAchievementsStart {
void FormMain::addAchievements(SAchievementsPlayer &aAchievements, SGame &aGames) {
    if (_containerAchievementsForm == nullptr) {
        createFormContainerAchievements();
    }
    FormProfile *currentProfile = dynamic_cast<FormProfile*>(ui->StackedWidgetProfiles->currentWidget());
    if (currentProfile) {
        _containerAchievementsForm->addFormAchievement(aAchievements, currentProfile->getProfile(), aGames, _achievementsCount++);
        _containerAchievementsForm->parentWidget()->parentWidget()->show();
    }
}

void FormMain::removeAchievements(int index) {
    Q_UNUSED(index);
    --_achievementsCount;
}

void FormMain::containerAchievementsClose() {
    _achievementsCount = 0;
    disconnect(_containerAchievementsForm, &FormContainerAchievements::s_removeAchievements, this, &FormMain::removeAchievements);
    disconnect(_containerAchievementsForm, &FormContainerAchievements::s_formClose,          this, &FormMain::containerAchievementsClose);
    delete _containerAchievementsForm;
    _containerAchievementsForm = nullptr;
}

void FormMain::returnFromAchievements(int aNum) {
    Q_UNUSED(aNum);
    //disconnect(_achievementsForms[aNum], &FormAchievements::s_returnToGames, this, &FormMain::returnFromAchievements);
    disconnect(_containerAchievementsForm);
    delete _containerAchievementsForm;
    //delete achievementsforms[num];
}
#define ContainerAchievementsEnd }

#define FormsStart {

#define FormsCreateStart {
FormProfile *FormMain::createFormProfile(SProfile &aProfile) {
    FormProfile *newFormProfile = new FormProfile(aProfile);
    newFormProfile->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum));
    connect(newFormProfile, &FormProfile::s_goToGames,       this,           &FormMain::goToGames);
    connect(newFormProfile, &FormProfile::s_goToFriends,     this,           &FormMain::goToFriends);
    connect(newFormProfile, &FormProfile::s_goToStatistic,   this,           &FormMain::goToStatistics);
    connect(newFormProfile, &FormProfile::s_goToFavorites,   this,           &FormMain::goToFavorites);
    connect(newFormProfile, &FormProfile::s_myProfileChange, this,           &FormMain::updateSettings);
    connect(this,           &FormMain::s_updateSettings,   newFormProfile, &FormProfile::updateSettings);
    return newFormProfile;
}

FormGames *FormMain::createFormGames(SProfile &aProfile, SGames &aGames) {
    _gamesForm = new FormGames(aProfile, aGames, this);
    connect(this,       &FormMain::s_updateSettings,    _gamesForm,   &FormGames::updateSettings);
    connect(_gamesForm, &FormGames::s_achievementsLoaded, this,         &FormMain::progressLoading);
    connect(_gamesForm, &FormGames::s_showAchievements,   this,         &FormMain::addAchievements);
    connect(_gamesForm, &FormGames::s_finish,             this,         [=](int aWidth) {
                                                                            showForm(c_formsGames, aWidth);
                                                                        });
    _gamesForm->setWhatsThis("FormGames");
    return _gamesForm;
}

FormFriends *FormMain::createFormFriends(const QString &aId, SFriends &aFriends) {
    _friendsForm = new FormFriends(aId, aFriends, this);
    connect(this,         &FormMain::s_updateSettings, _friendsForm,  &FormFriends::updateSettings);
    connect(_friendsForm, &FormFriends::s_friendsLoaded, this,          &FormMain::progressLoading);
    connect(_friendsForm, &FormFriends::s_go_to_profile, this,          &FormMain::goToProfile);
    connect(_friendsForm, &FormFriends::s_finish,        this,          [=]() {
                                                                            showForm(c_formsFriends);
                                                                        });
    _friendsForm->setWhatsThis("FormFriends");
    return _friendsForm;
}

FormFavorites *FormMain::createFormFavorites() {
    _favoritesForm = new FormFavorites(this);
    connect(this, &FormMain::s_updateSettings, _favoritesForm, &FormFavorites::updateSettings);
    _favoritesForm->setWhatsThis("FormFavorites");
    return _favoritesForm;
}

FormStatistics *FormMain::createFormStatistics(const QString &aId, SGames &aGames, const QString &aName) {
    _statisticsForm = new FormStatistics(aId, aGames, aName, this);
    connect(this,            &FormMain::s_updateSettings,       _statisticsForm,  &FormStatistics::updateSettings);
    connect(_statisticsForm, &FormStatistics::s_statisticsLoaded, this,             &FormMain::progressLoading);
    connect(_statisticsForm, &FormStatistics::s_finish,           this,             [=]() {
                                                                                        showForm(c_formsStatistic);
                                                                                    });
    return _statisticsForm;
}

FormSettings *FormMain::createFormSettings() {
    _settingsForm = new FormSettings(this);
    connect(_settingsForm, &FormSettings::s_updateSettings, this, &FormMain::updateSettings);
    return _settingsForm;
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
void FormMain::goToProfile(const QString &aId, ProfileUrlType aType) {
    SProfiles newProfile(aId, false, aType);
    if(newProfile.getStatus() == StatusValue::success) {
        returnFromForms();
        if(ui->StackedWidgetProfiles->currentIndex() != ui->StackedWidgetProfiles->count() - 1) {
            while(ui->StackedWidgetProfiles->count() - 1 != ui->StackedWidgetProfiles->currentIndex()) {
                ui->StackedWidgetProfiles->removeWidget(ui->StackedWidgetProfiles->widget(ui->StackedWidgetProfiles->currentIndex() + 1));
            }
        }
        ui->StackedWidgetProfiles->addWidget(createFormProfile(newProfile[0]));
        ui->StackedWidgetProfiles->setCurrentIndex(ui->StackedWidgetProfiles->count() - 1);
        updateSettings();
        updateEnabledButtonsBackNext();
        qInfo() << "Буфер профилей" << ui->StackedWidgetProfiles->currentIndex() + 1 << "/" << ui->StackedWidgetProfiles->count();
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удаётся найти профиль!"));
        qWarning() << newProfile.getError();
    }
}

void FormMain::goToGames(SProfile &aProfileSteamId, SGames &aGames) {
    if(_gamesForm == nullptr) {
        if(!_blockedLoad) {
            _blockedLoad = true;
            ui->FormProgressBar->setMaximum(aGames.getCount());
            ui->ScrollAreaGames->setWidget(createFormGames(aProfileSteamId, aGames));
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsGames);
    }
}

void FormMain::goToFriends(const QString &aSteamId, SFriends &aFriends) {
    if(_friendsForm == nullptr) {
        if(!_blockedLoad) {
            _blockedLoad = true;
            ui->FormProgressBar->setMaximum(aFriends.getCount());
            ui->ScrollAreaFriends->setWidget(createFormFriends(aSteamId, aFriends));
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
            //showForm(c_formsFriends);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsFriends);
    }
}

void FormMain::goToFavorites() {
    if(_favoritesForm == nullptr) {
        if(!_blockedLoad) {
            ui->ScrollAreaFavorites->setWidget(createFormFavorites());
            //
            ui->StackedWidgetForms->setCurrentIndex(c_formsFavorites);
            resizeScrollArea();
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsFavorites);
    }
}

void FormMain::goToStatistics(const QString &aId, SGames &aGames, const QString &aProfileName) {
    if(_statisticsForm == nullptr) {
        if(!_blockedLoad) {
            _blockedLoad = true;
            ui->FormProgressBar->setMaximum(aGames.getCount());
            ui->ScrollAreaStatistic->setWidget(createFormStatistics(aId, aGames, aProfileName));
            ui->FormProgressBar->setVisible(true);
            ui->StackedWidgetForms->setCurrentIndex(c_formsNone);
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsStatistic);
    }
}
#define GoToFormEnd }

void FormMain::showForm(int aWidgetIndex, int aWidthWindow) {
    ui->FormProgressBar->setVisible(false);
    _blockedLoad = false;
    ui->StackedWidgetForms->setCurrentIndex(aWidgetIndex);
    resizeScrollArea(aWidthWindow);
}

void FormMain::returnFromForms() {
    if(_gamesForm != nullptr) {
        disconnect(_gamesForm);
        delete _gamesForm;
        _gamesForm = nullptr;
    }
    if(_friendsForm != nullptr) {
        disconnect(_friendsForm);
        _friendsForm->deleteLater();
        _friendsForm = nullptr;
    }
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
        _setting.setMainWindowIsMaximize(parentWidget()->parentWidget()->isMaximized());
        _setting.setMainWindowParams(parentWidget()->parentWidget()->normalGeometry());
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
    _containerAchievementsForm->close();
    delete _containerAchievementsForm;
    delete ui;
}

void FormMain::updateSettings() {
    Settings::syncronizeSettings();
//TODO исправить ресайз профилей на нормальный вариант
    switch (Settings::getProfileInfoSize()) {
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
        ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile()._steamID != Settings::getMyProfile());
    }
    qApp->setStyleSheet(getTheme());
    emit s_updateSettings();
}

void FormMain::resizeScrollArea(int aWidth) {
    if((ui->StackedWidgetForms->height() < 400) || (ui->StackedWidgetForms->width() < aWidth)) {
        FramelessWindow *parent = dynamic_cast<FramelessWindow*>(parentWidget()->parent());
        if (parent) {
            parent->animateResize(parentWidget()->width() + aWidth - ui->StackedWidgetForms->width(), parentWidget()->height() - ui->StackedWidgetForms->height() + 400);
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
        goToProfile(regExpProfileUrl.cap(5), ProfileUrlType::id);
    } else {
        goToProfile(regExpProfileUrl.cap(5), ProfileUrlType::vanity);
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
            ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile()._steamID != Settings::getMyProfile());
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
            ui->ButtonGoToMyProfile->setEnabled(currentProfile->getProfile()._steamID != Settings::getMyProfile());
        }
        updateEnabledButtonsBackNext();
    }
}

void FormMain::buttonSettings_Clicked() {
    if(_settingsForm == nullptr) {
        if(!_blockedLoad) {
            createFormSettings();
            ui->ScrollAreaSettings->setWidget(_settingsForm);
            //
            ui->StackedWidgetForms->setCurrentIndex(c_formsSettings);
            resizeScrollArea();
        }
    } else {
        ui->StackedWidgetForms->setCurrentIndex(c_formsSettings);
    }
}

void FormMain::buttonGoToMyProfile_Clicked() {
    if(Settings::getMyProfile() != "none") {
        goToProfile(Settings::getMyProfile(), ProfileUrlType::id);
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
