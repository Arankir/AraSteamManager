#include "formprofile.h"
#include "ui_formprofile.h"

#define Constants {
const QColor c_green_color  = QColor (87,   230,    124,    255 * 0.7);
const QColor c_yellow_color = QColor (108,  110,    14,     255 * 0.7);
const QColor c_red_color    = QColor (255,  48,     48,     255 * 1);
const QColor c_blue_color   = QColor (0,    0,      255,    255 * 0.7);
#define ConstantsEnd }

FormProfile::FormProfile(const SProfile &aProfile, QWidget *aParent) : Form(aParent), ui(new Ui::FormProfile), _profile(aProfile) {
    ui->setupUi(this);
    ui->LabelProfileVisibility->setTextFormat(Qt::RichText);
    ui->LabelGamesVisibility  ->setTextFormat(Qt::RichText);
    ui->LabelFriendsVisibility->setTextFormat(Qt::RichText);
    ui->LabelProfileUrl       ->setTextFormat(Qt::RichText);
    ui->ButtonGames->setBaseSize(QSize(23, 23));
    //ui->LabelPersonaState->setWordWrap(true);

    ui->FrameProfileButtons->setMinimumHeight(32 + 18);

    ui->LabelAvatar->setFixedSize(QSize(64, 64));
    ui->LabelAvatarMinimize->setFixedSize(QSize(32, 32));

#define Connects {
    connect(ui->ButtonSetProfile, &QPushButton::clicked, this, &FormProfile::buttonSetProfile_Clicked);
    connect(ui->ButtonGames,      &QPushButton::clicked, this, &FormProfile::buttonGames_Clicked);
    connect(ui->ButtonFriends,    &QPushButton::clicked, this, &FormProfile::buttonFriends_Clicked);
    connect(ui->ButtonStatistics, &QPushButton::clicked, this, &FormProfile::buttonStatistics_Clicked);
    connect(ui->ButtonFavorites,  &QPushButton::clicked, this, &FormProfile::buttonFavorites_Clicked);
#define ConnectsEnd }
    profileToUi(_profile);
    updateSettings(QFlags<changedSettings>(changedSettings::profileInfo | changedSettings::myProfile | changedSettings::theme));
}

FormProfile::~FormProfile() {
    qInfo() << "Форма профиля " + _profile.personaName() + " удалилась";
    delete ui;
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
    ui->LabelTimeCreatedValue->setText(_profile.timeCreated().toString(Settings::dateFormat()));
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

QGraphicsDropShadowEffect *createLightning() {
    QGraphicsDropShadowEffect *lightning = new QGraphicsDropShadowEffect;
    //shadowEffect3->setColor(QColor(255, 255, 0, 255 * 0.7));
    lightning->setOffset(0);
    lightning->setBlurRadius(10);
    return lightning;
}

LabelLight *setlightningColor(LabelLight *aLabel, const QColor &aColor) {
    aLabel->setStyleSheet("color: " + aColor.name());
    aLabel->setLightColor(aColor);
    return aLabel;
}

void FormProfile::setColorStatus(const QColor &aColor) {
    QString stylesheet = "color: " + aColor.name() + ";";
    ui->LabelPersonaState   ->setStyleSheet("color: " + aColor.name());
    setlightningColor(ui->LabelName, aColor);
    setlightningColor(ui->LabelNameMinimize, aColor);
}

#define setData {
void FormProfile::setProfile(const SProfile &aProfile) {
    _profile = aProfile;
}

void FormProfile::setProfileStatus() {
    switch (_profile.communityVisibilityState()) {
        case 1:
            setlightningColor(ui->LabelProfileVisibility, c_red_color)->setToolTip(tr("Скрытый"));
            ui->LabelProfileStatus->setPixmap(QPixmap(Images::stateRed()).scaled(14, 14));
            break;
        case 3:
            setlightningColor(ui->LabelProfileVisibility, c_green_color)->setToolTip(tr("Публичный"));
            ui->LabelProfileStatus->setPixmap(QPixmap(Images::stateGreen()).scaled(14, 14));
            break;
        case 8:
            setlightningColor(ui->LabelProfileVisibility, c_yellow_color)->setToolTip(tr("Для друзей"));
            ui->LabelProfileStatus->setPixmap(QPixmap(Images::stateYellow()).scaled(14, 14));
            break;
        default:
            setlightningColor(ui->LabelProfileVisibility, c_blue_color)->setToolTip(tr("Неизвестно"));
            ui->LabelProfileStatus->setPixmap(QPixmap(Images::stateBlue()).scaled(14, 14));
    }
}

void FormProfile::setOnlineStatus() {
    ui->LabelPersonaState->setText(_profile.stateFullText());
    setColorStatus(_profile.stateColor());
}

void FormProfile::setGames(const QString &aSteamId) {
    _games = SGame::load(aSteamId, true, true);
    if (_games.count() > 0) {
        ui->ButtonGames->setEnabled(true);
        ui->ButtonStatistics->setEnabled(true);
        setlightningColor(ui->LabelGamesVisibility, c_green_color)->setToolTip(tr("Публичный"));
        ui->LabelGamesStatus->setPixmap(QPixmap(Images::stateGreen()).scaled(14, 14));
    } else {
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        setlightningColor(ui->LabelGamesVisibility, c_red_color)->setToolTip(tr("Скрытый"));
        ui->LabelGamesStatus->setPixmap(QPixmap(Images::stateRed()).scaled(14, 14));
    }
}

void FormProfile::setFriends(const QString &aSteamId) {
    _friends = SFriend::load(aSteamId);
    if (_friends.count() > 0) {
        ui->ButtonFriends->setEnabled(true);
        setlightningColor(ui->LabelFriendsVisibility, c_green_color)->setToolTip(tr("Публичный"));
        ui->LabelFriendsStatus->setPixmap(QPixmap(Images::stateGreen()).scaled(14, 14));
    } else {
        ui->ButtonFriends->setEnabled(false);
        setlightningColor(ui->LabelFriendsVisibility, c_red_color)->setToolTip(tr("Скрытый"));
        ui->LabelFriendsStatus->setPixmap(QPixmap(Images::stateRed()).scaled(14, 14));
    }
}

void FormProfile::setBans(const QString &aSteamId) {
    QList<SBan> bans = SBan::load(aSteamId);
    if (bans.count() == 0) {
        return;
    }
    if(bans[0].vacBanned()) {
        setlightningColor(ui->LabelBansValue, c_red_color)->setText(tr("%1, последний %2 дней назад").arg(
                                                                    QString::number(bans[0].numberOfVacBan()),
                                                                    QString::number(bans[0].daysSinceLastBan())));
    } else {
        setlightningColor(ui->LabelBansValue, c_green_color)->setText(tr("отсутствуют"));
    }
}

void FormProfile::setLvl(const QString &aSteamId) {
    int level = SProfile::getLevel(aSteamId);
    ui->LabellvlValue->setText(level > 0 ? QString::number(level) : "?");
    int dozens = (level / 10) % 10;
    QString qss = QString("border-image: url(%1) %2 0 %3 0; ").arg
                         (Images::levels(level / 100),
                          QString::number(dozens * 32),
                          QString::number((10 - dozens - 1) * 32));
    ui->LabellvlValue->setStyleSheet(qss);
}

void FormProfile::setCommunityProfile() {
    if (_profile.profileState() == 1) {
        setlightningColor(ui->LabelProfileState, c_green_color)->setText(tr("Настроен профиль сообщества"));
    } else {
        setlightningColor(ui->LabelProfileState, c_red_color)->setText(tr("Не настроен профиль сообщества"));
    }
}

void FormProfile::setCommentPermission() {
    if (_profile.commentPermission() == 1) {
        setlightningColor(ui->LabelCommentPermission, c_green_color)->setText(tr("Публичные комментарии разрешены"));
    } else {
        setlightningColor(ui->LabelCommentPermission, c_red_color)->setText(tr("Публичные комментарии запрещены"));
    }
}
#define setDataEnd }

#define updateData {
void FormProfile::updateSettings(QFlags<changedSettings> aSettings) {
    Settings::syncronizeSettings();
    if (aSettings.testFlag(changedSettings::theme)) {
        updateIcons();
    }
    if (aSettings.testFlag(changedSettings::profileInfo)) {
        updateVisibleInfo();
    }
    if (aSettings.testFlag(changedSettings::myProfile)) {
        updateMyProfile();
    }
}

void FormProfile::updateVisibleInfo() {
    _visibleInfo = Settings::profileInfoSize();
    switch (_visibleInfo) {
    case 0: {
        ui->FrameProfileBaseInfo    ->setVisible(false);
        ui->FrameProfileMaximumInfo ->setVisible(false);

        ui->LabelNameMinimize       ->setVisible(true);
        ui->LabelAvatarMinimize->pixmap().scaled(23, 23);
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
    _profile.update();
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
        ui->ButtonGames     ->setToolTip(tr("Игры (%1)").arg(_games.count() > 0 ? QString::number(_games.count()) : tr("???")));
        ui->ButtonFriends   ->setToolTip(tr("Друзья (%1)").arg(_friends != QList<SFriend>() ? QString::number(_friends.count()) : tr("???")));
        ui->ButtonStatistics->setToolTip(tr("Статистика"));
        ui->ButtonFavorites ->setToolTip(tr("Избранное"));
        ui->ButtonSetProfile->setToolTip(tr("Установить профиль как свой"));
        break;
    }
    case 1:{
        ui->ButtonGames     ->setText(tr("Игры (%1)").arg(_games.count() > 0 ? QString::number(_games.count()) : tr("???")));
        ui->ButtonFriends   ->setText(tr("Друзья (%1)").arg(_friends != QList<SFriend>() ? QString::number(_friends.count()) : tr("???")));
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
        ui->ButtonGames     ->setText(tr("Игры (%1)").arg(_games.count() > 0 ? QString::number(_games.count()) : tr("???")));
        ui->ButtonFriends   ->setText(tr("Друзья (%1)").arg(_friends != QList<SFriend>() ? QString::number(_friends.count()) : tr("???")));
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
    setOnlineStatus();
}

void FormProfile::updateIcons() {
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
    emit s_settingsUpdated(changedSettings::myProfile);
}

void FormProfile::buttonGames_Clicked() {
    if(_games.count() > 0) {
        emit s_goToGames(_profile, _games);
    }
}

void FormProfile::buttonFriends_Clicked() {
    if(_friends != QList<SFriend>()) {
        emit s_goToFriends(_profile.steamID(), _friends);
    }
}

void FormProfile::buttonStatistics_Clicked() {
    if(_games.count() > 0) {
        emit s_goToStatistic(_profile, _games);
    }
}

void FormProfile::buttonFavorites_Clicked() {
    if(true) {
        emit s_goToFavorites();
    }
}
#define uiFunctionsEnd }
