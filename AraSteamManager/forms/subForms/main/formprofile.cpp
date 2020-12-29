#include "formprofile.h"
#include "ui_formprofile.h"

#define Constants {
QString c_green_css     = "#4BD44B";
QColor c_green_color    = QColor (87, 230, 124, 255 * 0.7);
QString c_yellow_css    = "#6c6e0e";
QColor c_yellow_color   = QColor (108, 110, 14, 255 * 0.7);
QString c_red_css       = "#ab1d1d"; //b33a3a
QColor c_red_color      = QColor (255, 48, 48, 255 * 1);
QString c_blue_css      = "#42a9c6";
QColor c_blue_color     = QColor (0, 0, 255, 255 * 0.7);
#define ConstantsEnd }

FormProfile::FormProfile(SProfile aProfile, QWidget *aParent) : QWidget(aParent), ui(new Ui::FormProfile), _profile(aProfile), _games(this) {
    ui->setupUi(this);
    ui->LabelProfileVisibility->setTextFormat(Qt::RichText);
    ui->LabelGamesVisibility  ->setTextFormat(Qt::RichText);
    ui->LabelFriendsVisibility->setTextFormat(Qt::RichText);
    ui->LabelProfileUrl       ->setTextFormat(Qt::RichText);
    ui->ButtonGames->setBaseSize(QSize(23, 23));
    ui->LabelPersonaState->setWordWrap(true);

    ui->FrameProfileButtons->setMinimumHeight(32 + 18);

    ui->LabelAvatar->setFixedSize(QSize(64, 64));
    ui->LabelAvatarMinimize->setFixedSize(QSize(32, 32));

    ui->LabellvlValue           ->setStyleSheet("color: #42a9c6;");
    ui->LabelTimeCreatedValue   ->setStyleSheet("color: #42a9c6;");
    ui->LabelRealNameValue      ->setStyleSheet("color: #42a9c6;");
    ui->LabelLocCountryCodeValue->setStyleSheet("color: #42a9c6;");

    ui->LabelName             ->setGraphicsEffect(createLightning());
    ui->LabelNameMinimize     ->setGraphicsEffect(createLightning());

    ui->LabelProfileVisibility->setGraphicsEffect(createLightning());
    ui->LabelGamesVisibility  ->setGraphicsEffect(createLightning());
    ui->LabelFriendsVisibility->setGraphicsEffect(createLightning());

    ui->LabelProfileState     ->setGraphicsEffect(createLightning());
    ui->LabelCommentPermission->setGraphicsEffect(createLightning());
    ui->LabelBansValue        ->setGraphicsEffect(createLightning());

#define Connects {
    connect(ui->ButtonSetProfile, &QPushButton::clicked, this, &FormProfile::buttonSetProfile_Clicked);
    connect(ui->ButtonGames,      &QPushButton::clicked, this, &FormProfile::buttonGames_Clicked);
    connect(ui->ButtonFriends,    &QPushButton::clicked, this, &FormProfile::buttonFriends_Clicked);
    connect(ui->ButtonStatistics, &QPushButton::clicked, this, &FormProfile::buttonStatistics_Clicked);
    connect(ui->ButtonFavorites,  &QPushButton::clicked, this, &FormProfile::buttonFavorites_Clicked);
#define ConnectsEnd }
    profileToUi(_profile);
    updateSettings();
}

FormProfile::~FormProfile() {
    qInfo() << "Форма профиля удалилась";
    delete ui;
}

void FormProfile::changeEvent(QEvent *aEvent) {
    if(aEvent->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormProfile::profileToUi(const SProfile &aProfile) {
    _profile = aProfile;
    //Аватарки
    ui->LabelAvatar->setPixmap(_profile.pixmapAvatarMedium());
    ui->LabelAvatarMinimize->setPixmap(_profile.pixmapAvatar());
    //Ник
    ui->LabelName        ->setText(_profile.personaName());
    ui->LabelNameMinimize->setText(_profile.personaName());
    //Реальное имя
    ui->LabelRealNameValue->setText(_profile.realName());
    if (_profile.realName() != "") {
        ui->LabelRealName     ->setVisible(true);
        ui->LabelRealNameValue->setVisible(true);
    } else {
        ui->LabelRealName     ->setVisible(false);
        ui->LabelRealNameValue->setVisible(false);
    }
    //Дата создания аккаунта
    ui->LabelTimeCreatedValue->setText(_profile.timeCreated().toString("yyyy.MM.dd"));
    if (_profile.timeCreated() > QDateTime::fromSecsSinceEpoch(0, Qt::LocalTime)) {
        ui->LabelTimeCreated     ->setVisible(true);
        ui->LabelTimeCreatedValue->setVisible(true);
    } else {
        ui->LabelTimeCreated     ->setVisible(false);
        ui->LabelTimeCreatedValue->setVisible(false);
    }
    //Код страны
    ui->LabelLocCountryCodeValue->setText(_profile.locCountryCode());
    if (_profile.locCountryCode() != "") {
        ui->LabelLocCountryCode     ->setVisible(true);
        ui->LabelLocCountryCodeValue->setVisible(true);
    } else {
        ui->LabelLocCountryCode     ->setVisible(false);
        ui->LabelLocCountryCodeValue->setVisible(false);
    }
    //Url
    ui->LabelProfileUrl->setText("<img height=13 style=\"vertical-align: top\" src=\"" + Images::link() + "\"> "
                                "<a href=\"" + _profile.profileUrl() + "\">"
                                "<span style=\" text-decoration: underline; color:#2d7fc8;\">" + _profile.profileUrl() + "</span></a>");

    setProfileStatus();
    setOnlineStatus();

    setCommunityProfile();
    setCommentPermission();

    setGames(_profile.steamID());
    setFriends(_profile.steamID());
    setLvl(_profile.steamID());
    setBans(_profile.steamID());
}

QGraphicsDropShadowEffect *FormProfile::createLightning() {
    QGraphicsDropShadowEffect *lightning = new QGraphicsDropShadowEffect;
    //shadowEffect3->setColor(QColor(255, 255, 0, 255 * 0.7));
    lightning->setOffset(0);
    lightning->setBlurRadius(10);
    return lightning;
}

void FormProfile::setColorStatus(int aRed, int aGreen, int aBlue, double aAlpha) {
    QString stylesheet = "color: rgb(" + QString::number(aRed) + ", " + QString::number(aGreen) + ", " + QString::number(aBlue) + ");";
    ui->LabelPersonaState   ->setStyleSheet(stylesheet);
    ui->LabelName           ->setStyleSheet(stylesheet);
    ui->LabelNameMinimize   ->setStyleSheet(stylesheet);

    QGraphicsDropShadowEffect *nameLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelName->graphicsEffect());
    if (nameLight) {
        nameLight->setColor(QColor(aRed, aGreen, aBlue, aAlpha));
    }

    QGraphicsDropShadowEffect *nameSmallLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelNameMinimize->graphicsEffect());
    if (nameSmallLight) {
        nameSmallLight->setColor(QColor(aRed, aGreen, aBlue, aAlpha));
    }
}

#define setData {
void FormProfile::setProfile(const SProfile &aProfile) {
    _profile = aProfile;
}

void FormProfile::setProfileStatus() {
    //ui->LabelProfileVisibility->setText(tr("Профиль"));
    QPixmap profileState;
    QGraphicsDropShadowEffect *profileLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelProfileVisibility->graphicsEffect());
    switch (_profile.communityVisibilityState()) {
        case 1:
            ui->LabelProfileVisibility->setToolTip(tr("Скрытый"));
            ui->LabelProfileVisibility->setStyleSheet("color: " + c_red_css);
            profileState.load(Images::stateRed());
            if (profileLight) {
                profileLight->setColor(c_red_color);
            }
            break;
        case 3:
            ui->LabelProfileVisibility->setToolTip(tr("Публичный"));
            ui->LabelProfileVisibility->setStyleSheet("color: " + c_green_css);
            profileState.load(Images::stateGreen());
            if (profileLight) {
                profileLight->setColor(c_green_color);
            }
            break;
        case 8:
            ui->LabelProfileVisibility->setToolTip(tr("Для друзей"));
            ui->LabelProfileVisibility->setStyleSheet("color: " + c_yellow_css);
            profileState.load(Images::stateYellow());
            if (profileLight) {
                profileLight->setColor(c_yellow_color);
            }
            break;
        default:
            ui->LabelProfileVisibility->setToolTip(tr("Неизвестно"));
            ui->LabelProfileVisibility->setStyleSheet("color: " + c_blue_css);
            profileState.load(Images::stateBlue());
            if (profileLight) {
                profileLight->setColor(c_blue_color);
            }
        }
    ui->LabelProfileStatus->setPixmap(profileState.scaled(14, 14));
}

void FormProfile::setOnlineStatus() {
    if(!_profile.gameExtraInfo().isEmpty()) {
        ui->LabelPersonaState->setText(tr("В игре %1").arg(_profile.gameExtraInfo()));
        setColorStatus(137, 183, 83, 255 * 0.7);
    } else {
        switch (_profile.personaState()) {
            case 0:
                if (_profile.lastLogoff() == QDateTime::fromSecsSinceEpoch(0, Qt::LocalTime)) {
                    ui->LabelPersonaState->setText(tr("Не в сети"));
                } else {
                    ui->LabelPersonaState->setText(tr("Был в сети %1").arg(_profile.lastLogoff().toString("yyyy.MM.dd hh:mm:ss")));
                }
                setColorStatus(125, 126, 128, 255 * 0.7);
                break;
            case 1:
                ui->LabelPersonaState->setText(tr("В сети"));
                setColorStatus(87, 203, 222, 255 * 0.7);
                break;
            case 2:
                ui->LabelPersonaState->setText(tr("Не беспокоить"));
                setColorStatus(129, 85, 96, 255 * 0.7);
                break;
            case 3:
                ui->LabelPersonaState->setText(tr("Нет на месте"));
                setColorStatus(70, 120, 142, 255 * 0.7);
                break;
            case 4:
                ui->LabelPersonaState->setText(tr("Спит"));
                setColorStatus(70, 120, 142, 255 * 0.7);
                break;
            case 5:
                ui->LabelPersonaState->setText(tr("Ожидает обмена"));
                setColorStatus(0, 0, 0, 255 * 0.7);
                break;
            case 6:
                ui->LabelPersonaState->setText(tr("Хочет поиграть"));
                setColorStatus(0, 0, 0, 255 * 0.7);
                break;
        }
    }
}

void FormProfile::setGames(const QString &aSteamId) {
    _games.load(aSteamId, true, true, false);
    //ui->LabelGamesVisibility->setText(tr("Игры"));
    QPixmap gamesState;
    QGraphicsDropShadowEffect *gamesLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelGamesVisibility->graphicsEffect());
    switch (_games.status()) {
    case StatusValue::success: {
        ui->ButtonGames->setEnabled(true);
        ui->ButtonStatistics->setEnabled(true);
        ui->LabelGamesVisibility->setToolTip(tr("Публичный"));
        ui->LabelGamesVisibility->setStyleSheet("color: " + c_green_css);
        gamesState.load(Images::stateGreen());
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Игры"));
        if (gamesLight) {
            gamesLight->setColor(c_green_color);
        }
        break;
    }
    case StatusValue::error: {
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        ui->LabelGamesVisibility->setToolTip(tr("Скрытый"));
        ui->LabelGamesVisibility->setStyleSheet("color: " + c_red_css);
        gamesState.load(Images::stateRed());
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Игры"));
        if (gamesLight) {
            gamesLight->setColor(c_red_color);
        }
        break;
    }
    case StatusValue::none: {
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        ui->LabelGamesVisibility->setToolTip(tr("Неизвестно"));
        ui->LabelGamesVisibility->setStyleSheet("color: " + c_blue_css);
        gamesState.load(Images::stateBlue());
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Игры"));
        if (gamesLight) {
            gamesLight->setColor(c_blue_color);
        }
        break;
    }
    }
    ui->LabelGamesStatus->setPixmap(gamesState.scaled(14, 14));
}

void FormProfile::setFriends(const QString &aSteamId) {
    _friends.load(aSteamId,false);
    //ui->LabelFriendsVisibility->setText(tr("Друзья"));
    QPixmap friendsState;
    QGraphicsDropShadowEffect *friendsLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelFriendsVisibility->graphicsEffect());
    switch (_friends.status()) {
    case StatusValue::success: {
        ui->ButtonFriends->setEnabled(true);
        ui->LabelFriendsVisibility->setToolTip(tr("Публичный"));
        ui->LabelFriendsVisibility->setStyleSheet("color: " + c_green_css);
        friendsState.load(Images::stateGreen());
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Друзья"));
        if (friendsLight) {
            friendsLight->setColor(c_green_color);
        }
        break;
    }
    case StatusValue::error: {
        ui->ButtonFriends->setEnabled(false);
        ui->LabelFriendsVisibility->setToolTip(tr("Скрытый"));
        ui->LabelFriendsVisibility->setStyleSheet("color: " + c_red_css);
        friendsState.load(Images::stateRed());
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Друзья"));
        if (friendsLight) {
            friendsLight->setColor(c_red_color);
        }
        break;
    }
    case StatusValue::none: {
        ui->ButtonFriends->setEnabled(false);
        ui->LabelFriendsVisibility->setToolTip(tr("Неизвестно"));
        ui->LabelFriendsVisibility->setStyleSheet("color: " + c_blue_css);
        friendsState.load(Images::stateBlue());
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Друзья"));
        if (friendsLight) {
            friendsLight->setColor(c_blue_color);
        }
        break;
    }
    }
    ui->LabelFriendsStatus->setPixmap(friendsState.scaled(14, 14));
}

void FormProfile::setBans(const QString &aSteamId) {
    SBans bans(aSteamId,false);
    QGraphicsDropShadowEffect *bansLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelBansValue->graphicsEffect());
    if(bans[0].vacBanned()) {
        ui->LabelBansValue->setText(tr("%1, последний %2 дней назад").arg(QString::number(bans[0].numberOfVacBan()), QString::number(bans[0].daysSinceLastBan())));
        ui->LabelBansValue->setStyleSheet("color: " + c_red_css);
        if (bansLight) {
            bansLight->setColor(c_red_color);
        }
    } else {
        ui->LabelBansValue->setText(tr("отсутствуют"));
        ui->LabelBansValue->setStyleSheet("color: " + c_green_css);
        if (bansLight) {
            bansLight->setColor(c_green_color);
        }
    }
}

void FormProfile::setLvl(const QString &aSteamId) {
    SLevels levels(aSteamId);
    ui->LabellvlValue->setText(levels.level() > 0 ? QString::number(levels.level()) : "?");
    int dozens = (levels.level() / 10) % 10;
    QString qss = QString("color: #42a9c6; "
                  "border-image: url(%1) %2 0 %3 0; ").arg(Images::levels(levels.level() / 100), QString::number(dozens * 32), QString::number((10 - dozens - 1) * 32));
    ui->LabellvlValue->setStyleSheet(qss);
}

void FormProfile::setCommunityProfile() {
    QGraphicsDropShadowEffect *stateLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelProfileState->graphicsEffect());
    if (_profile.profileState() == 1) {
        ui->LabelProfileState->setText(tr("Настроен профиль сообщества"));
        ui->LabelProfileState->setStyleSheet("color: " + c_green_css);
        if (stateLight) {
            stateLight->setColor(c_green_color);
        }
    } else {
        ui->LabelProfileState->setText(tr("Не настроен профиль сообщества"));
        ui->LabelGamesVisibility->setStyleSheet("color: " + c_red_css);
        if (stateLight) {
            stateLight->setColor(c_red_color);
        }
    }
}

void FormProfile::setCommentPermission() {
    QGraphicsDropShadowEffect *commentLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelCommentPermission->graphicsEffect());
    if (_profile.commentPermission() == 1) {
        ui->LabelCommentPermission->setText(tr("Публичные комментарии разрешены"));
        ui->LabelCommentPermission->setStyleSheet("color: " + c_green_css);
        if (commentLight) {
            commentLight->setColor(c_green_color);
        }
    } else {
        ui->LabelCommentPermission->setText(tr("Публичные комментарии запрещены"));
        ui->LabelCommentPermission->setStyleSheet("color: " + c_red_css);
        if (commentLight) {
            commentLight->setColor(c_red_color);
        }
    }
}
#define setDataEnd }

#define updateData {
void FormProfile::updateSettings() {
    Settings::syncronizeSettings();
    setIcons();
    updateVisibleInfo();
    updateMyProfile();
}

void FormProfile::updateVisibleInfo() {
    _visibleInfo = Settings::profileInfoSize();
    switch (_visibleInfo) {
    case 0: {
        ui->FrameProfileBaseInfo    ->setVisible(false);
        ui->FrameProfileMaximumInfo ->setVisible(false);

        ui->LabelNameMinimize       ->setVisible(true);
        ui->LabelAvatarMinimize->pixmap()->scaled(23, 23);
        ui->LabelAvatarMinimize     ->setVisible(true);
        break;
    }
    case 1: {
        ui->FrameProfileBaseInfo    ->setVisible(true);
        ui->FrameProfileMaximumInfo ->setVisible(false);

        ui->LabelNameMinimize       ->setVisible(false);
        ui->LabelAvatarMinimize     ->setVisible(false);
        break;
    }
    case 2: {
        ui->FrameProfileBaseInfo    ->setVisible(true);
        ui->FrameProfileMaximumInfo ->setVisible(true);

        ui->LabelNameMinimize       ->setVisible(false);
        ui->LabelAvatarMinimize     ->setVisible(false);
    }
    }
    retranslate();
    ui->ButtonSetProfile->setEnabled(Settings::myProfile() != _profile.steamID());
}

void FormProfile::updateInfo() {
    _profile.update(false);
    profileToUi(_profile);
}

void FormProfile::updateMyProfile() {
    ui->ButtonSetProfile->setEnabled(Settings::myProfile() != _profile.steamID());
}

void FormProfile::retranslate() {
    ui->retranslateUi(this);
    switch (_visibleInfo) {
    case 0:{
        ui->ButtonGames     ->setText("");
        ui->ButtonFriends   ->setText("");
        ui->ButtonStatistics->setText("");
        ui->ButtonFavorites ->setText("");
        ui->ButtonSetProfile->setText("");
        ui->ButtonGames     ->setToolTip(tr("Игры (%1)").arg(_games.status() == StatusValue::success ? QString::number(_games.count()) : tr("???")));
        ui->ButtonFriends   ->setToolTip(tr("Друзья (%1)").arg(_friends.status() == StatusValue::success ? QString::number(_friends.count()) : tr("???")));
        ui->ButtonStatistics->setToolTip(tr("Статистика"));
        ui->ButtonFavorites ->setToolTip(tr("Избранное"));
        ui->ButtonSetProfile->setToolTip(tr("Установить профиль как свой"));
        break;
    }
    case 1:{
        ui->ButtonGames     ->setText(tr("Игры (%1)").arg(_games.status() == StatusValue::success ? QString::number(_games.count()) : tr("???")));
        ui->ButtonFriends   ->setText(tr("Друзья (%1)").arg(_friends.status() == StatusValue::success ? QString::number(_friends.count()) : tr("???")));
        ui->ButtonStatistics->setText(tr("Статистика"));
        ui->ButtonFavorites ->setText(tr("Избранное"));
        ui->ButtonSetProfile->setText(tr("Это мой профиль"));
        ui->ButtonGames     ->setToolTip("");
        ui->ButtonFriends   ->setToolTip("");
        ui->ButtonStatistics->setToolTip("");
        ui->ButtonFavorites ->setToolTip("");
        ui->ButtonSetProfile->setToolTip("");
        break;
    }
    case 2:{
        ui->ButtonGames     ->setText(tr("Игры (%1)").arg(_games.status() == StatusValue::success ? QString::number(_games.count()) : tr("???")));
        ui->ButtonFriends   ->setText(tr("Друзья (%1)").arg(_friends.status() == StatusValue::success ? QString::number(_friends.count()) : tr("???")));
        ui->ButtonStatistics->setText(tr("Статистика"));
        ui->ButtonFavorites ->setText(tr("Избранное"));
        ui->ButtonSetProfile->setText(tr("Это мой профиль"));
        ui->ButtonGames     ->setToolTip("");
        ui->ButtonFriends   ->setToolTip("");
        ui->ButtonStatistics->setToolTip("");
        ui->ButtonFavorites ->setToolTip("");
        ui->ButtonSetProfile->setToolTip("");
    }
    }
    setBans(_profile.steamID());
    setCommunityProfile();
    setCommentPermission();
}

void FormProfile::setIcons() {
    ui->LabelProfileUrl->setText("<img height=13 style=\"vertical-align: top\" src=\"" + Images::link() + "\"> "
                                "<a href=\"" + _profile.profileUrl() + "\">"
                                "<span style=\" text-decoration: underline; color:#2d7fc8;\">" + _profile.profileUrl() + "</span></a>");
    ui->ButtonSetProfile->setIcon(QIcon(Images::setHome()));
    ui->ButtonFavorites ->setIcon(QIcon(Images::isNotFavorites()));
    ui->ButtonStatistics->setIcon(QIcon(Images::statistic()));
    ui->ButtonFriends   ->setIcon(QIcon(Images::friends()));
    ui->ButtonGames     ->setIcon(QIcon(Images::games()));
}
#define updateDataEnd }

#define uiFunctions {
void FormProfile::buttonSetProfile_Clicked() {
    Settings::setMyProfile(_profile.steamID());
    ui->ButtonSetProfile->setEnabled(false);
    emit s_myProfileChange();
}

void FormProfile::buttonGames_Clicked() {
    if(_games.status() == StatusValue::success) {
        emit s_goToGames(_profile, _games);
    }
}

void FormProfile::buttonFriends_Clicked() {
    if(_friends.status() == StatusValue::success) {
        emit s_goToFriends(_profile.steamID(), _friends);
    }
}

void FormProfile::buttonStatistics_Clicked() {
    if(_games.status() == StatusValue::success) {
        emit s_goToStatistic(_profile.steamID(), _games, _profile.personaName());
    }
}

void FormProfile::buttonFavorites_Clicked() {
    if(true) {
        emit s_goToFavorites();
    }
}
#define uiFunctionsEnd }
