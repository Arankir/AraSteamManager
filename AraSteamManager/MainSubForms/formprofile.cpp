#include "formprofile.h"
#include "ui_formprofile.h"

FormProfile::FormProfile(SProfile aProfile, QWidget *aParent) : QWidget(aParent), ui(new Ui::FormProfile), _profile(aProfile), _games(this) {
    ui->setupUi(this);
    ui->LabelProfileVisibility->setTextFormat(Qt::RichText);
    ui->LabelGamesVisibility->setTextFormat(Qt::RichText);
    ui->LabelFriendsVisibility->setTextFormat(Qt::RichText);
    ui->LabelProfileUrl->setTextFormat(Qt::RichText);
    ui->LabelNick->setStyleSheet("color: #42a9c6;");
    ui->LabelNameMinimize->setStyleSheet("color: #42a9c6;");
    ui->ButtonGames->setBaseSize(QSize(23, 23));
    ui->LabelPersonaState->setWordWrap(true);
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
    _profile = aProfile;
    SBans bans(aProfile._steamID,false);
    SLevels levels(aProfile._steamID);
    _games.set(aProfile._steamID,true,true,false);
    _friends.set(aProfile._steamID,false);
    if(!aProfile._gameExtraInfo.isEmpty()) {
        ui->LabelPersonaState->setText(tr("В игре %1").arg(aProfile._gameExtraInfo));
        ui->LabelPersonaState->setStyleSheet("color: rgb(137,183,83);");
    } else {
        switch (aProfile._personaState) {
            case 0:
                ui->LabelPersonaState->setText(tr("Был в сети %1").arg(aProfile._lastLogoff.toString("yyyy.MM.dd hh:mm:ss")));
                ui->LabelPersonaState->setStyleSheet("color: rgb(125,126,128);");
                break;
            case 1:
                ui->LabelPersonaState->setText(tr("В сети"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(87,203,222);");
                break;
            case 2:
                ui->LabelPersonaState->setText(tr("Не беспокоить"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(129,85,96);");
                break;
            case 3:
                ui->LabelPersonaState->setText(tr("Нет на месте"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                break;
            case 4:
                ui->LabelPersonaState->setText(tr("Спит"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(70,120,142);");
                break;
            case 5:
                ui->LabelPersonaState->setText(tr("Ожидает обмена"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                break;
            case 6:
                ui->LabelPersonaState->setText(tr("Хочет поиграть"));
                ui->LabelPersonaState->setStyleSheet("color: rgb(0,0,0);");
                break;
        }
    }
    QString iconsColor = _setting.getIconsColor();
    ui->LabelProfileUrl->setText("<img height=13 style=\"vertical-align: top\" src=\"" + _setting.getIconLink() + "\"> "
                                "<a href=\"" + aProfile._profileUrl + "\">"
                                "<span style=\" text-decoration: underline; color:#2d7fc8;\">" + aProfile._profileUrl + "</span></a>");
    ui->LabellvlValue->setText(QString::number(levels.GetLevel()));
    ui->LabelRealNameValue->setText(aProfile._realName);
    ui->LabelTimeCreatedValue->setText(aProfile._timeCreated.toString("yyyy.MM.dd"));
    ui->LabelLocCountryCodeValue->setText(aProfile._locCountryCode);
    QPixmap profileState;
    QPixmap gamesState;
    QPixmap friendsState;
    //Добавить описание при наведении
    switch (aProfile._communityVisibilityState) {
        case 1:
//            ui->LabelProfileVisibility->setText(tr("Скрытый"));
//            ui->LabelProfileVisibility->setStyleSheet("color: #6e0e0e");
            profileState.load(_setting.getIconStateRed());
            break;
        case 3:
//            ui->LabelProfileVisibility->setText(tr("Публичный"));
//            ui->LabelProfileVisibility->setStyleSheet("color: #0e6e11");
            profileState.load(_setting.getIconStateGreen());
            break;
        case 8:
//            ui->LabelProfileVisibility->setText(tr("Для друзей"));
//            ui->LabelProfileVisibility->setStyleSheet("color: #6c6e0e");
            profileState.load(_setting.getIconStateYellow());
            break;
        default:
//            ui->LabelProfileVisibility->setText(tr("Неизвестно"));
//            ui->LabelProfileVisibility->setStyleSheet("color:white");
            profileState.load(_setting.getIconStateBlue());
        }
    switch (_games.getStatus()) {
    case StatusValue::success: {
        ui->ButtonGames->setEnabled(true);
        ui->ButtonStatistics->setEnabled(true);
        gamesState.load(_setting.getIconStateGreen());
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Игры"));
        break;
    }
    case StatusValue::error: {
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        gamesState.load(_setting.getIconStateRed());
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Игры"));
        break;
    }
    case StatusValue::none: {
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        gamesState.load(_setting.getIconStateBlue());
        //ui->LabelGamesVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Игры"));
        break;
    }
    }
    switch (_friends.getStatus()) {
    case StatusValue::success: {
        ui->ButtonFriends->setEnabled(true);
        friendsState.load(_setting.getIconStateGreen());
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_green.png\"> "+tr("Друзья"));
        break;
    }
    case StatusValue::error: {
        ui->ButtonFriends->setEnabled(false);
        friendsState.load(_setting.getIconStateRed());
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_red.png\"> "+tr("Друзья"));
        break;
    }
    case StatusValue::none: {
        ui->ButtonFriends->setEnabled(false);
        friendsState.load(_setting.getIconStateBlue());
        //ui->LabelFriendsVisibility->setText("<img height=15 style=\"vertical-align: top\" src=\"://state_blue.png\"> "+tr("Друзья"));
        break;
    }
    }
    ui->LabelProfileStatus->setPixmap(profileState.scaled(14, 14));
    ui->LabelGamesStatus->setPixmap(gamesState.scaled(14, 14));
    ui->LabelFriendsStatus->setPixmap(friendsState.scaled(14, 14));
    if(bans.getVacBanned()) {
        ui->LabelBansNotNone->setText(QString::number(bans.getNumberOfVacBans()));
        ui->LabelBansDays->setText(QString::number(bans.getDaysSinceLastBan()));
        ui->LabelBansNotNone->setVisible(true);
        ui->LabelBansLast->setVisible(true);
        ui->LabelBansDays->setVisible(true);
        ui->LabelBansDaysAgo->setVisible(true);
        ui->LabelBansNone->setVisible(false);
//        ui->LabelBans->setText(tr("VAC баны: %1| Последний %2 дней назад").arg(QString::number(bans.GetNumberOfVACBans())).arg(QString::number(bans.GetDaysSinceLastBan())));
//        ui->LabelBans->setStyleSheet("color: #6e0e0e");
    } else {
        ui->LabelBansNotNone->setVisible(false);
        ui->LabelBansLast->setVisible(false);
        ui->LabelBansDays->setVisible(false);
        ui->LabelBansDaysAgo->setVisible(false);
        ui->LabelBansNone->setVisible(true);
//        ui->LabelBans->setText(tr("VAC баны: Отсутствуют"));
//        ui->LabelBans->setStyleSheet("color: #0e6e11");
    }

    ui->LabelAvatar->setPixmap(RequestData(aProfile._avatarMedium, false).getPixmap());
    ui->LabelAvatarMinimize->setPixmap(RequestData(aProfile._avatar, false).getPixmap());
    ui->LabelNick->setText(aProfile._personaName);
    ui->LabelNameMinimize->setText(aProfile._personaName);
}

void FormProfile::setProfile(SProfile aProfile) {
    _profile = aProfile;
}

SProfile FormProfile::getProfile() {
    return _profile;
}

SGames FormProfile::getGames() {
    return _games;
}

SFriends FormProfile::getFriends() {
    return _friends;
}

void FormProfile::updateSettings() {
    _setting.syncronizeSettings();
    setIcons();
    updateVisibleInfo();
    updateMyProfile();
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

void FormProfile::updateVisibleInfo() {
    _visibleInfo = _setting.getProfileInfoSize();
    switch (_visibleInfo) {
    case 0:{
        ui->FrameNormalInfo->setVisible(false);
        ui->LabelNameMinimize->setVisible(true);
        ui->LabelAvatarMinimize->setVisible(true);
        ui->LabelAvatarMinimize->pixmap()->scaled(23, 23);
        break;
    }
    case 1:{
        ui->FrameNormalInfo->setVisible(true);
        ui->LabelNameMinimize->setVisible(false);
        ui->FrameMaximumInfo->setVisible(false);
        ui->LabelAvatarMinimize->setVisible(false);
        break;
    }
    case 2:{
        ui->FrameNormalInfo->setVisible(true);
        ui->LabelNameMinimize->setVisible(false);
        ui->FrameMaximumInfo->setVisible(true);
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
}

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
