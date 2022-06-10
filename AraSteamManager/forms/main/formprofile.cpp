#include "formprofile.h"
#include "ui_formprofile.h"
#include <QPainter>

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
    //ui->LabelPersonaState->setWordWrap(true);

    ui->LabelWindowsPlayTime->setToolTip(textToToolTip(tr("Стим начал собирать статистику по платформам в сентябре 2019 года")));
    ui->LabelLinuxPlayTime->setToolTip(textToToolTip(tr("Стим начал собирать статистику по платформам в сентябре 2019 года")));
    ui->LabelMacOsPlayTime->setToolTip(textToToolTip(tr("Стим начал собирать статистику по платформам в сентябре 2019 года")));

    ui->FrameProfileButtons->setMinimumHeight(32 + 18);

    ui->LabelAvatar->setFixedSize(QSize(64, 64) * c_frameLargerBy);
    ui->LabelAvatarMinimize->setFixedSize(QSize(32, 32) * c_frameLargerBy);

#define Connects {
    connect(ui->ButtonSetProfile, &QPushButton::clicked, this, &FormProfile::buttonSetProfile_Clicked);
    connect(ui->ButtonGames,      &QPushButton::clicked, this, &FormProfile::buttonGames_Clicked);
    connect(ui->ButtonFriends,    &QPushButton::clicked, this, &FormProfile::buttonFriends_Clicked);
    connect(ui->ButtonStatistics, &QPushButton::clicked, this, &FormProfile::buttonStatistics_Clicked);
#define ConnectsEnd }
    profileToUi(_profile);
    updateSettings(QFlags<changedSettings>(changedSettings::profileInfo | changedSettings::myProfile | changedSettings::theme));
}

FormProfile::~FormProfile() {
    delete ui;
}

void FormProfile::profileToUi(const SProfile &aProfile) {
    _profile = aProfile;
    //Аватарки
    ui->LabelAvatar->setPixmap(aProfile.getAvatarWithFrame(QSize(64, 64) * c_frameLargerBy));
    ui->LabelAvatarMinimize->setPixmap(aProfile.getAvatarWithFrame(QSize(32, 32) * c_frameLargerBy));

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
    setId(_profile.steamID());
    setProfileStatus();
    setOnlineStatus();

    setCommunityProfile();
    setCommentPermission();

    setGames(_profile.steamID());
    setFriends(_profile.steamID());
    setLvl(_profile.steamID());
    setBadges(_profile.steamID());
    setBans(_profile.steamID());
    setCustomizations(_profile.steamID());
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

void FormProfile::setGames(const ProfileID &aSteamId) {
    _games = SGame::load(aSteamId, true, true);
    if (_games.count() > 0) {
        ui->ButtonGames->setEnabled(true);
        ui->ButtonStatistics->setEnabled(true);
        setlightningColor(ui->LabelGamesVisibility, c_green_color)->setToolTip(tr("Публичный"));
        ui->LabelGamesStatus->setPixmap(QPixmap(Images::stateGreen()).scaled(14, 14));
        setTimePlayed(_games);
    } else {
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        setlightningColor(ui->LabelGamesVisibility, c_red_color)->setToolTip(tr("Скрытый"));
        ui->LabelGamesStatus->setPixmap(QPixmap(Images::stateRed()).scaled(14, 14));
    }
}

void FormProfile::setFriends(const ProfileID &aSteamId) {
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

void FormProfile::setId(const ProfileID &aSteamId) {
    if (_profile.profileUrl().indexOf("/id/") > -1) {
        ui->LabelVanityUrlValue->setText(_profile.profileUrl().mid(_profile.profileUrl().indexOf("/id/") + 4).remove("/"));
        ui->LabelVanityUrlValue->setVisible(true);
        ui->LabelVanityUrl->setVisible(true);
    } else {
        ui->LabelVanityUrlValue->setText("");
        ui->LabelVanityUrlValue->setVisible(false);
        ui->LabelVanityUrl->setVisible(false);
    }
    ui->LabelProfileIDValue->setText(aSteamId);
    //Url
    ui->LabelProfileUrl->setText("<img height=13 style=\"vertical-align: top\" src=\"" + Images::link() + "\"> "
                                "<a href=\"" + _profile.profileUrl() + "\">"
                                "<span style=\" text-decoration: underline; color:#2d7fc8;\">" + _profile.profileUrl() + "</span></a>");

}

void FormProfile::setBans(const ProfileID &aSteamId) {
    QList<SBan> bans = SBan::load(aSteamId);
    if (bans.count() == 0) {
        return;
    }
    if(bans[0].vacBanned()) {
        QString dayAgo = "";
        switch (bans[0].daysSinceLastBan() % 10) {
        case 1: {
            dayAgo = tr("день назад");
            break;
        }
        case 2:
        case 3:
        case 4: {
            dayAgo = tr("дня назад");
            break;
        }
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0: {
            dayAgo = tr("дней назад");
            break;
        }
        }

        setlightningColor(ui->LabelVacBansValue, c_red_color)->setText(tr("%1, последний %2 %3").arg(
                                                                    QString::number(bans[0].numberOfVacBan()),
                                                                    QString::number(bans[0].daysSinceLastBan()),
                                                                    dayAgo));
    } else {
        setlightningColor(ui->LabelVacBansValue, c_green_color)->setText(tr("Отсутствуют"));
    }
    if(bans[0].numberOfGameBans() > 0) {
        setlightningColor(ui->LabelGameBansValue, c_red_color)->setText(tr("%1").arg(QString::number(bans[0].numberOfGameBans())));
    } else {
        setlightningColor(ui->LabelGameBansValue, c_green_color)->setText(tr("Отсутствуют"));
    }
    if(bans[0].communityBanned()) {
        setlightningColor(ui->LabelCommunityBanValue, c_red_color)->setText(tr("Забанен"));
    } else {
        setlightningColor(ui->LabelCommunityBanValue, c_green_color)->setText(tr("Отсутствует"));
    }
    if(bans[0].numberOfGameBans() > 0) {
        setlightningColor(ui->LabelTradeBanValue, c_red_color)->setText(tr("%1").arg(bans[0].economyBan()));
    } else {
        setlightningColor(ui->LabelTradeBanValue, c_green_color)->setText(tr("Отсутствует"));
    }
}

void FormProfile::setBadges(const ProfileID &aSteamId) {
    int specialBadges = 0;
    int normalBadges = 0;
    int foilBadges = 0;
    int lvl1Badges = 0;
    int lvl2Badges = 0;
    int lvl3Badges = 0;
    int lvl4Badges = 0;
    int lvl5Badges = 0;
    int lvlMore5Badges = 0;
    auto badges = SBadge::load(aSteamId);
    for (const auto &badge: badges) {
        if (badge.appid() == 0) {
            ++specialBadges;
        } else {
            if (badge.border_color() == 1) {
                ++foilBadges;
            } else {
                ++normalBadges;
            }
            switch (badge.level()) {
            case 1: {
                ++lvl1Badges;
                break;
            }
            case 2: {
                ++lvl2Badges;
                break;
            }
            case 3: {
                ++lvl3Badges;
                break;
            }
            case 4: {
                ++lvl4Badges;
                break;
            }
            case 5: {
                ++lvl5Badges;
                break;
            }
            default: {
                ++lvlMore5Badges;
                break;
            }
            }
        }
    }

    ui->LabelSpecialBadgesValue->setText(QString::number(specialBadges));
    ui->LabelNormalBadgesValue->setText(QString::number(normalBadges));
    ui->LabelFoilBadgesValue->setText(QString::number(foilBadges));
    ui->LabelBadges1LvlValue->setText(QString::number(lvl1Badges));
    ui->LabelBadges2LvlValue->setText(QString::number(lvl2Badges));
    ui->LabelBadges3LvlValue->setText(QString::number(lvl3Badges));
    ui->LabelBadges4LvlValue->setText(QString::number(lvl4Badges));
    ui->LabelBadges5LvlValue->setText(QString::number(lvl5Badges));
    ui->LabelBadgesMore5LvlValue->setText(QString::number(lvlMore5Badges));
}

void FormProfile::setTimePlayed(const SGames &aGames) {
    int never = 0;
    int zero_one = 0;
    int one_ten = 0;
    int ten_day = 0;
    int day_tenday = 0;
    int tenday_fivehundreed = 0;
    int fivehundreed_onethouthand = 0;
    int more_than_onethouthand = 0;
    int total = 0;
    int win = 0;
    int mac = 0;
    int linux = 0;
    for (const auto &game: aGames) {
        int playtime = game.playtimeForever();
        total += playtime;
        win += game.playtimeWindowsForever();
        mac += game.playtimeMacForever();
        linux += game.playtimeLinuxForever();
        if (playtime == 0) {
            ++never;
        } else if (playtime < 60) {
            ++zero_one;
        } else if (playtime < 600) {
            ++one_ten;
        } else if (playtime < 60 * 24) {
            ++ten_day;
        } else if (playtime < 60 * 240) {
            ++day_tenday;
        } else if (playtime < 60 * 500) {
            ++tenday_fivehundreed;
        } else if (playtime < 60 * 1000) {
            ++fivehundreed_onethouthand;
        } else {
            ++more_than_onethouthand;
        }
    }
    ui->LabelGamesPlayed0hValue->setText(QString::number(never));
    ui->LabelGamesPlayed0_1hValue->setText(QString::number(zero_one));
    ui->LabelGamesPlayed1_10hValue->setText(QString::number(one_ten));
    ui->LabelGamesPlayed10_24hValue->setText(QString::number(ten_day));
    ui->LabelGamesPlayed24_240hValue->setText(QString::number(day_tenday));
    ui->LabelGamesPlayed240_500hValue->setText(QString::number(tenday_fivehundreed));
    ui->LabelGamesPlayed500_1000hValue->setText(QString::number(fivehundreed_onethouthand));
    ui->LabelGamesPlayedMore1000hValue->setText(QString::number(more_than_onethouthand));

    ui->LabelTotalPlayTimeValue->setText(tr("%1h").arg(QString::number(1.0 * total / 60, 'f', 1)));
    ui->LabelWindowsPlayTimeValue->setText(tr("%1h").arg(QString::number(1.0 * win / 60, 'f', 1)));
    ui->LabelMacOsPlayTimeValue->setText(tr("%1h").arg(QString::number(1.0 * mac / 60, 'f', 1)));
    ui->LabelLinuxPlayTimeValue->setText(tr("%1h").arg(QString::number(1.0 * linux / 60, 'f', 1)));
}

void FormProfile::setCustomizations(const ProfileID &aSteamId) {
    auto items = SProfile::getEquippedItems(aSteamId);
    ui->LabelBackgroundValue->setText(items.value("profile_background").item_title);
    ui->LabelMiniProfileValue->setText(items.value("mini_profile_background").item_title);
    ui->LabelAvatarFrameValue->setText(items.value("avatar_frame").item_title);
    ui->LabelAnimatedAvatarValue->setText(items.value("animated_avatar").item_title);

    auto customizations = SProfileCustomization::load(aSteamId);
    int purchased = 0;
    int upgraded = 0;
    int lvl1 = 0;
    int lvl2 = 0;
    int lvl3 = 0;
    for (const auto &customization: customizations) {
        if (customization.isUpgradable()) {
            switch (customization.level()) {
            case 1: {
                ++lvl1;
                ++upgraded;
                break;
            }
            case 2: {
                ++lvl2;
                ++upgraded;
                break;
            }
            case 3: {
                ++lvl3;
                ++upgraded;
                break;
            }
            }
        }
        if (customization.isPurchase()) {
            if (customization.count() > 0) {
                ++purchased;
            }
        }
    }
    ui->LabelProfileCustomizationsPurchasedValue->setText(QString::number(purchased));
    ui->LabelProfileCustomizationsUpgradedValue->setText(QString::number(upgraded));
    ui->LabelProfileCustomization1LvlValue->setText(QString::number(lvl1));
    ui->LabelProfileCustomization2LvlValue->setText(QString::number(lvl2));
    ui->LabelProfileCustomization3LvlValue->setText(QString::number(lvl3));
}

void FormProfile::setLvl(const ProfileID &aSteamId) {
    int playerXp = 0;
    int playerLevel = 0;
    int playerXpNeededToLevelUp = 0;
    int playerXpNeededCurrentLevel = 0;

    SBadge::getXpInfo(aSteamId, playerXp, playerLevel, playerXpNeededToLevelUp, playerXpNeededCurrentLevel);

    ui->LabellvlValue->setText(playerLevel > 0 ? QString::number(playerLevel) : "?");
    int dozens = (playerLevel / 10) % 10;
    QString qss = QString("border-image: url(%1) %2 0 %3 0; ").arg
                         (Images::levels(playerLevel / 100),
                          QString::number(dozens * 32),
                          QString::number((10 - dozens - 1) * 32));
    ui->LabellvlValue->setStyleSheet(qss);

    ui->progressBarXp->setMaximum(playerXp - playerXpNeededCurrentLevel + playerXpNeededToLevelUp);
    ui->progressBarXp->setValue(playerXp - playerXpNeededCurrentLevel);
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
        ui->ButtonSetProfile->setText("");
        ui->ButtonGames     ->setToolTip(tr("Игры (%1)").arg(_games.count() > 0 ? QString::number(_games.count()) : tr("???")));
        ui->ButtonFriends   ->setToolTip(tr("Друзья (%1)").arg(_friends != QList<SFriend>() ? QString::number(_friends.count()) : tr("???")));
        ui->ButtonStatistics->setToolTip(tr("Статистика"));
        ui->ButtonSetProfile->setToolTip(tr("Установить профиль как свой"));
        break;
    }
    case 1:{
        ui->ButtonGames     ->setText(tr("Игры (%1)").arg(_games.count() > 0 ? QString::number(_games.count()) : tr("???")));
        ui->ButtonFriends   ->setText(tr("Друзья (%1)").arg(_friends != QList<SFriend>() ? QString::number(_friends.count()) : tr("???")));
        ui->ButtonStatistics->setText(tr("Статистика"));
        ui->ButtonSetProfile->setText(tr("Это мой профиль"));
        ui->ButtonGames     ->setToolTip("");
        ui->ButtonFriends   ->setToolTip("");
        ui->ButtonStatistics->setToolTip("");
        ui->ButtonSetProfile->setToolTip("");
        break;
    }
    case 2:{
        ui->ButtonGames     ->setText(tr("Игры (%1)").arg(_games.count() > 0 ? QString::number(_games.count()) : tr("???")));
        ui->ButtonFriends   ->setText(tr("Друзья (%1)").arg(_friends != QList<SFriend>() ? QString::number(_friends.count()) : tr("???")));
        ui->ButtonStatistics->setText(tr("Статистика"));
        ui->ButtonSetProfile->setText(tr("Это мой профиль"));
        ui->ButtonGames     ->setToolTip("");
        ui->ButtonFriends   ->setToolTip("");
        ui->ButtonStatistics->setToolTip("");
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
        emit s_goToGames(_profile.steamID());
    }
}

void FormProfile::buttonFriends_Clicked() {
    if(_friends != QList<SFriend>()) {
        emit s_goToFriends(_profile.steamID());
    }
}

void FormProfile::buttonStatistics_Clicked() {
    if(_games.count() > 0) {
        emit s_goToStatistic(_profile);
    }
}
#define uiFunctionsEnd }
