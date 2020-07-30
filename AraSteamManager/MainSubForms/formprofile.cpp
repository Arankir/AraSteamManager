#include "formprofile.h"
#include "ui_formprofile.h"

#define Constants {
QString c_green = "#57FF7C";
QString c_yellow = "#6c6e0e";
QString c_red = "#E44B4B"; //b33a3a
QString c_blue = "blue";
#define ConstantsEnd }

FormProfile::FormProfile(SProfile aProfile, QWidget *aParent) : QWidget(aParent), ui(new Ui::FormProfile), _profile(aProfile), _games(this) {
    ui->setupUi(this);
    ui->LabelProfileVisibility->setTextFormat(Qt::RichText);
    ui->LabelGamesVisibility->setTextFormat(Qt::RichText);
    ui->LabelFriendsVisibility->setTextFormat(Qt::RichText);
    ui->LabelProfileUrl->setTextFormat(Qt::RichText);
    ui->ButtonGames->setBaseSize(QSize(23, 23));
    ui->LabelPersonaState->setWordWrap(true);

    ui->LabelName->setGraphicsEffect(createLightning());
    ui->LabelNameMinimize->setGraphicsEffect(createLightning());

    ui->LabellvlValue->setStyleSheet("color: #42a9c6; ");
    ui->LabelTimeCreatedValue->setStyleSheet("color: #42a9c6;");
    ui->LabelRealNameValue->setStyleSheet("color: #42a9c6;");
    ui->LabelLocCountryCodeValue->setStyleSheet("color: #42a9c6;");

    ui->LabelProfileVisibility->setGraphicsEffect(createLightning());
    ui->LabelGamesVisibility->setGraphicsEffect(createLightning());
    ui->LabelFriendsVisibility->setGraphicsEffect(createLightning());

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

FormProfile::~FormProfile(){
    delete ui;
}

void FormProfile::changeEvent(QEvent *aEvent) {
    if(aEvent->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormProfile::profileToUi(SProfile aProfile) {
    _profile = std::move(aProfile);

    ui->LabelAvatar->setFixedSize(QSize(64, 64));
    new RequestImage(ui->LabelAvatar,         _profile._avatarMedium, 0, false);
    new RequestImage(ui->LabelAvatarMinimize, _profile._avatar,       0, false);

    ui->LabelRealNameValue->setText(_profile._realName);
    if (_profile._realName != "") {
        ui->LabelRealName     ->setVisible(true);
        ui->LabelRealNameValue->setVisible(true);
    } else {
        ui->LabelRealName     ->setVisible(false);
        ui->LabelRealNameValue->setVisible(false);
    }

    ui->LabelTimeCreatedValue->setText(_profile._timeCreated.toString("yyyy.MM.dd"));
    if (_profile._timeCreated > QDateTime::fromSecsSinceEpoch(0, Qt::LocalTime)) {
        ui->LabelTimeCreated     ->setVisible(true);
        ui->LabelTimeCreatedValue->setVisible(true);
    } else {
        ui->LabelTimeCreated     ->setVisible(false);
        ui->LabelTimeCreatedValue->setVisible(false);
    }

    ui->LabelLocCountryCodeValue->setText(_profile._locCountryCode);
    if (_profile._locCountryCode != "") {
        ui->LabelLocCountryCode     ->setVisible(true);
        ui->LabelLocCountryCodeValue->setVisible(true);
    } else {
        ui->LabelLocCountryCode     ->setVisible(false);
        ui->LabelLocCountryCodeValue->setVisible(false);
    }

    ui->LabelProfileState->setText(tr("%1 профиль сообщества").arg(_profile._profileState == 1 ? tr("Настроен") : tr("Не настроен")));
    ui->LabelCommentPermission->setText(tr("Публичные комментарии %1").arg(_profile._commentPermission == 1 ? tr("разрешены") : tr("запрещены")));
    ui->LabelProfileUrl->setText("<img height=13 style=\"vertical-align: top\" src=\"" + _setting.getIconLink() + "\"> "
                                "<a href=\"" + _profile._profileUrl + "\">"
                                "<span style=\" text-decoration: underline; color:#2d7fc8;\">" + _profile._profileUrl + "</span></a>");

    setName();
    setStatus();

    setGames(_profile._steamID);
    setFriends(_profile._steamID);
    setLvl(_profile._steamID);
    setBans(_profile._steamID);

}

QGraphicsDropShadowEffect *FormProfile::createLightning() {
    QGraphicsDropShadowEffect *lightning = new QGraphicsDropShadowEffect;
    //shadowEffect3->setColor(QColor(255, 255, 0, 255 * 0.7));
    lightning->setOffset(0);
    lightning->setBlurRadius(10);
    return lightning;
}

#define setData {
void FormProfile::setProfile(SProfile aProfile) {
    _profile = aProfile;
}

void FormProfile::setName() {
    ui->LabelName->setText(_profile._personaName);
    ui->LabelNameMinimize->setText(_profile._personaName);
    QPixmap profileState;
    QGraphicsDropShadowEffect *profileLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelProfileVisibility->graphicsEffect());
    switch (_profile._communityVisibilityState) {
        case 1:
            ui->LabelProfileVisibility->setText(tr("Скрытый"));
            ui->LabelProfileVisibility->setStyleSheet("color: " + c_red);
            profileState.load(_setting.getIconStateRed());
            if (profileLight) {
                profileLight->setColor(QColor (255, 48, 48, 255 * 1));
            }
            break;
        case 3:
            ui->LabelProfileVisibility->setText(tr("Публичный"));
            ui->LabelProfileVisibility->setStyleSheet("color: " + c_green);
            profileState.load(_setting.getIconStateGreen());
            if (profileLight) {
                profileLight->setColor(QColor (87, 255, 124, 255 * 0.7));
            }
            break;
        case 8:
            ui->LabelProfileVisibility->setText(tr("Для друзей"));
            ui->LabelProfileVisibility->setStyleSheet("color: " + c_yellow);
            profileState.load(_setting.getIconStateYellow());
            if (profileLight) {
                profileLight->setColor(QColor (108, 110, 14, 255 * 0.7));
            }
            break;
        default:
            ui->LabelProfileVisibility->setText(tr("Неизвестно"));
            ui->LabelProfileVisibility->setStyleSheet("color: " + c_blue);
            profileState.load(_setting.getIconStateBlue());
            if (profileLight) {
                profileLight->setColor(QColor (0, 0, 255, 255 * 0.7));
            }
        }
    ui->LabelProfileStatus->setPixmap(profileState.scaled(14, 14));
}

void FormProfile::setStatus() {
    if(!_profile._gameExtraInfo.isEmpty()) {
        ui->LabelPersonaState->setText(tr("В игре %1").arg(_profile._gameExtraInfo));
        setColorStatus(137, 183, 83, 255 * 0.7);
    } else {
        switch (_profile._personaState) {
            case 0:
                ui->LabelPersonaState->setText(tr("Был в сети %1").arg(_profile._lastLogoff.toString("yyyy.MM.dd hh:mm:ss")));
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

void FormProfile::setColorStatus(int aRed, int aGreen, int aBlue, double aAlpha) {
    QGraphicsDropShadowEffect *nameLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelName->graphicsEffect());
    QGraphicsDropShadowEffect *nameSmallLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelNameMinimize->graphicsEffect());
    ui->LabelPersonaState->setStyleSheet("color: rgb(" + QString::number(aRed) + ", " + QString::number(aGreen) + ", " + QString::number(aBlue) + ");");
    ui->LabelName->setStyleSheet("color: rgb(" + QString::number(aRed) + ", " + QString::number(aGreen) + ", " + QString::number(aBlue) + ");");
    ui->LabelNameMinimize->setStyleSheet("color: rgb(" + QString::number(aRed) + ", " + QString::number(aGreen) + ", " + QString::number(aBlue) + ");");
    if (nameLight) {
        nameLight->setColor(QColor(aRed, aGreen, aBlue, aAlpha));
    }
    if (nameSmallLight) {
        nameSmallLight->setColor(QColor(aRed, aGreen, aBlue, aAlpha));
    }
}

void FormProfile::setGames(QString aSteamId) {
    _games.set(aSteamId,true,true,false);
    QPixmap gamesState;
    QGraphicsDropShadowEffect *gamesLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelGamesVisibility->graphicsEffect());
    switch (_games.getStatus()) {
    case StatusValue::success: {
        ui->ButtonGames->setEnabled(true);
        ui->ButtonStatistics->setEnabled(true);
        ui->LabelGamesVisibility->setText(tr("Публичный"));
        ui->LabelGamesVisibility->setStyleSheet("color: " + c_green);
        gamesState.load(_setting.getIconStateGreen());
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Игры"));
        if (gamesLight) {
            gamesLight->setColor(QColor (87, 255, 124, 255 * 0.7));
        }
        break;
    }
    case StatusValue::error: {
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        ui->LabelGamesVisibility->setText(tr("Скрытый"));
        ui->LabelGamesVisibility->setStyleSheet("color: " + c_red);
        gamesState.load(_setting.getIconStateRed());
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Игры"));
        if (gamesLight) {
            gamesLight->setColor(QColor (255, 48, 48, 255 * 1));
        }
        break;
    }
    case StatusValue::none: {
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        ui->LabelGamesVisibility->setText(tr("Неизвестно"));
        ui->LabelGamesVisibility->setStyleSheet("color: " + c_blue);
        gamesState.load(_setting.getIconStateBlue());
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Игры"));
        if (gamesLight) {
            gamesLight->setColor(QColor (0, 0, 255, 255 * 0.7));
        }
        break;
    }
    }
    ui->LabelGamesStatus->setPixmap(gamesState.scaled(14, 14));
}

void FormProfile::setFriends(QString aSteamId) {
    _friends.set(aSteamId,false);
    QPixmap friendsState;
    QGraphicsDropShadowEffect *friendsLight = dynamic_cast<QGraphicsDropShadowEffect*>(ui->LabelFriendsVisibility->graphicsEffect());
    switch (_friends.getStatus()) {
    case StatusValue::success: {
        ui->ButtonFriends->setEnabled(true);
        ui->LabelFriendsVisibility->setText(tr("Публичный"));
        ui->LabelFriendsVisibility->setStyleSheet("color: " + c_green);
        friendsState.load(_setting.getIconStateGreen());
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Друзья"));
        if (friendsLight) {
            friendsLight->setColor(QColor (87, 255, 124, 255 * 0.7));
        }
        break;
    }
    case StatusValue::error: {
        ui->ButtonFriends->setEnabled(false);
        ui->LabelFriendsVisibility->setText(tr("Скрытый"));
        ui->LabelFriendsVisibility->setStyleSheet("color: " + c_red);
        friendsState.load(_setting.getIconStateRed());
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Друзья"));
        if (friendsLight) {
            friendsLight->setColor(QColor (255, 48, 48, 255 * 1));
        }
        break;
    }
    case StatusValue::none: {
        ui->ButtonFriends->setEnabled(false);
        ui->LabelFriendsVisibility->setText(tr("Неизвестно"));
        ui->LabelFriendsVisibility->setStyleSheet("color: " + c_blue);
        friendsState.load(_setting.getIconStateBlue());
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Друзья"));
        if (friendsLight) {
            friendsLight->setColor(QColor (0, 0, 255, 255 * 0.7));
        }
        break;
    }
    }
    ui->LabelFriendsStatus->setPixmap(friendsState.scaled(14, 14));
}

void FormProfile::setBans(QString aSteamId) {
    SBans bans(aSteamId,false);
    if(bans.getVacBanned()) {
        ui->LabelBansNotNone->setText(QString::number(bans.getNumberOfVacBans()));
        ui->LabelBansDays->setText(QString::number(bans.getDaysSinceLastBan()));
        ui->LabelBansNotNone->setVisible(true);
        ui->LabelBansLast->setVisible(true);
        ui->LabelBansDays->setVisible(true);
        ui->LabelBansDaysAgo->setVisible(true);
        ui->LabelBansNone->setVisible(false);
        //ui->LabelBans->setStyleSheet("color: " + c_red);
        ui->LabelBansNotNone->setStyleSheet("color: " + c_red);
        ui->LabelBansLast->setStyleSheet("color: " + c_red);
        ui->LabelBansDays->setStyleSheet("color: " + c_red);
        ui->LabelBansDaysAgo->setStyleSheet("color: " + c_red);
    } else {
        ui->LabelBansNotNone->setVisible(false);
        ui->LabelBansLast->setVisible(false);
        ui->LabelBansDays->setVisible(false);
        ui->LabelBansDaysAgo->setVisible(false);
        ui->LabelBansNone->setVisible(true);
        //ui->LabelBans->setStyleSheet("color: " + c_green);
        ui->LabelBansNone->setStyleSheet("color: " + c_green);
    }
}

void FormProfile::setLvl(QString aSteamId) {
//TODO исправить картинки
    SLevels levels(aSteamId);
    ui->LabellvlValue->setText(levels.GetLevel() > 0 ? QString::number(levels.GetLevel()) : "?");
    QString qss = "color: #42a9c6; "
                  "border-image: url(://lvls/" + QString::number(levels.GetLevel() / 100) + ".png) 0 0 0 0 stretch stretch; ";
    ui->LabellvlValue->setStyleSheet(qss);
}
#define setDataEnd }

#define getData {
SProfile FormProfile::getProfile() {
    return _profile;
}

SGames FormProfile::getGames() {
    return _games;
}

SFriends FormProfile::getFriends() {
    return _friends;
}
#define getDataEnd }

#define updateData {
void FormProfile::updateSettings() {
    _setting.syncronizeSettings();
    setIcons();
    updateVisibleInfo();
    updateMyProfile();
}

void FormProfile::updateVisibleInfo() {
    _visibleInfo = _setting.getProfileInfoSize();
    switch (_visibleInfo) {
    case 0: {
        ui->FrameProfileBaseInfo->setVisible(false);
        ui->FrameProfileMaximumInfo->setVisible(false);

        ui->LabelNameMinimize->setVisible(true);
        ui->LabelAvatarMinimize->pixmap()->scaled(23, 23);
        ui->LabelAvatarMinimize->setVisible(true);
        break;
    }
    case 1: {
        ui->FrameProfileBaseInfo->setVisible(true);
        ui->FrameProfileMaximumInfo->setVisible(false);

        ui->LabelNameMinimize->setVisible(false);
        ui->LabelAvatarMinimize->setVisible(false);
        break;
    }
    case 2: {
        ui->FrameProfileBaseInfo->setVisible(true);
        ui->FrameProfileMaximumInfo->setVisible(true);

        ui->LabelNameMinimize->setVisible(false);
        ui->LabelAvatarMinimize->setVisible(false);
    }
    }
    retranslate();
    ui->ButtonSetProfile->setEnabled(_setting.getMyProfile() != _profile._steamID);
}

void FormProfile::updateInfo() {
    _profile.update(false);
    profileToUi(_profile);
}

void FormProfile::updateMyProfile() {
    QString currentMyProfile = _setting.getMyProfile();
    ui->ButtonSetProfile->setEnabled(!(currentMyProfile == _profile._steamID));
}

void FormProfile::retranslate() {
    ui->retranslateUi(this);
    switch (_visibleInfo) {
    case 0:{
        ui->ButtonGames->setText("");
        ui->ButtonFriends->setText("");
        ui->ButtonGames->setToolTip(tr("Игры (%1)").arg(_games.getStatus() == StatusValue::success ? QString::number(_games.getCount()) : tr("???")));
        ui->ButtonFriends->setToolTip(tr("Друзья (%1)").arg(_friends.getStatus() == StatusValue::success ? QString::number(_friends.getCount()) : tr("???")));
        ui->ButtonStatistics->setText("");
        ui->ButtonFavorites->setText("");
        ui->ButtonStatistics->setToolTip(tr("Статистика"));
        ui->ButtonFavorites->setToolTip(tr("Избранное"));
        ui->ButtonSetProfile->setText("");
        ui->ButtonSetProfile->setToolTip(tr("Установить профиль как свой"));
        break;
    }
    case 1:{
        ui->ButtonGames->setText(tr(" Игры (%1)").arg(_games.getStatus() == StatusValue::success ? QString::number(_games.getCount()) : tr("???")));
        ui->ButtonFriends->setText(tr(" Друзья (%1)").arg(_friends.getStatus() == StatusValue::success ? QString::number(_friends.getCount()) : tr("???")));
        ui->ButtonGames->setToolTip("");
        ui->ButtonFriends->setToolTip("");
        ui->ButtonStatistics->setText(tr("Статистика"));
        ui->ButtonFavorites->setText(tr("Избранное"));
        ui->ButtonStatistics->setToolTip("");
        ui->ButtonFavorites->setToolTip("");
        ui->ButtonSetProfile->setText(tr("Это мой профиль"));
        ui->ButtonSetProfile->setToolTip("");
        break;
    }
    case 2:{
        ui->ButtonGames->setText(tr(" Игры (%1)").arg(_games.getStatus() == StatusValue::success ? QString::number(_games.getCount()) : tr("???")));
        ui->ButtonFriends->setText(tr(" Друзья (%1)").arg(_friends.getStatus() == StatusValue::success ? QString::number(_friends.getCount()) : tr("???")));
        ui->ButtonGames->setToolTip("");
        ui->ButtonFriends->setToolTip("");
        ui->ButtonStatistics->setText(tr("Статистика"));
        ui->ButtonFavorites->setText(tr("Избранное"));
        ui->ButtonStatistics->setToolTip("");
        ui->ButtonFavorites->setToolTip("");
        ui->ButtonSetProfile->setText(tr("Это мой профиль"));
        ui->ButtonSetProfile->setToolTip("");
    }
    }
    ui->LabelProfileState->setText(tr("%1 профиль сообщества").arg(_profile._profileState == 1 ? tr("Настроен") : tr("Не настроен")));
    ui->LabelCommentPermission->setText(tr("Публичные комментарии %1").arg(_profile._commentPermission == 1 ? tr("разрешены") : tr("запрещены")));
}

void FormProfile::setIcons() {
    QString iconsColor = _setting.getIconsColor();
    ui->LabelProfileUrl->setText("<img height=13 style=\"vertical-align: top\" src=\"" + _setting.getIconLink() + "\"> "
                                "<a href=\"" + _profile._profileUrl + "\">"
                                "<span style=\" text-decoration: underline; color:#2d7fc8;\">" + _profile._profileUrl + "</span></a>");
    ui->ButtonSetProfile->setIcon(QIcon(_setting.getIconSetHome()));
    ui->ButtonFavorites->setIcon(QIcon(_setting.getIconIsNotFavorites()));
    ui->ButtonStatistics->setIcon(QIcon(_setting.getIconStatistic()));
    ui->ButtonFriends->setIcon(QIcon(_setting.getIconFriends()));
    ui->ButtonGames->setIcon(QIcon(_setting.getIconGames()));
}
#define updateDataEnd }

#define uiFunctions {
void FormProfile::buttonSetProfile_Clicked() {
    _setting.setMyProfile(_profile._steamID);
    ui->ButtonSetProfile->setEnabled(false);
    emit s_myProfileChange();
}

void FormProfile::buttonGames_Clicked() {
    if(_games.getStatus() == StatusValue::success) {
        emit s_goToGames(_profile, _games);
    }
}

void FormProfile::buttonFriends_Clicked() {
    if(_friends.getStatus() == StatusValue::success) {
        emit s_goToFriends(_profile._steamID, _friends);
    }
}

void FormProfile::buttonStatistics_Clicked() {
    if(_games.getStatus() == StatusValue::success) {
        emit s_goToStatistic(_profile._steamID, _games, _profile._personaName);
    }
}

void FormProfile::buttonFavorites_Clicked() {
    if(true) {
        emit s_goToFavorites();
    }
}
#define uiFunctionsEnd }
