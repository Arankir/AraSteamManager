#include "formprofile.h"
#include "ui_formprofile.h"
#include "subWidgets/labels/labellight.h"
#include "classes/steamApi/structures/sbans.h"
#include "classes/steamApi/structures/sprofilecustomization.h"
#include "classes/steamApi/structures/sbadge.h"
#include "classes/common/images.h"
#include "classes/common/generalfunctions.h"

#include <QPainter>
#include <QSpacerItem>
#include <QFormLayout>

#define Constants {
const QColor c_green_color  = QColor (19, 147, 24, 255 * 0.7);//#139318
const QColor c_yellow_color = QColor (183, 197, 19, 255 * 0.7);//#B7C513
const QColor c_red_color    = QColor (166, 23, 23, 255 * 1);//#A61717
const QColor c_blue_color   = QColor (21, 50, 138, 255 * 0.7);//#15328A
#define ConstantsEnd }

FormProfile::FormProfile(const SProfile &aProfile, QWidget *aParent) : Form(aParent), ui(new Ui::FormProfile), profile_(aProfile) {
    ui->setupUi(this);
    ui->labelLinkValue->setTextFormat(Qt::RichText);
    ui->LabelPersonaState->setWordWrap(true);

    ui->LabelAvatar->setFixedSize(QSize(64, 64) * c_frameLargerBy);
    ui->LabelAvatarMinimize->setFixedSize(QSize(32, 32) * c_frameLargerBy);

#define Connects {
    connect(ui->ButtonSetProfile, &QPushButton::clicked, this, &FormProfile::buttonSetProfile_Clicked);
    connect(ui->ButtonGames,      &QPushButton::clicked, this, &FormProfile::buttonGames_Clicked);
    connect(ui->ButtonFriends,    &QPushButton::clicked, this, &FormProfile::buttonFriends_Clicked);
    connect(ui->ButtonStatistics, &QPushButton::clicked, this, &FormProfile::buttonStatistics_Clicked);
#define ConnectsEnd }
    profileToUi(profile_);
    updateSettings(QFlags<changedSettings>(changedSettings::profileInfo | changedSettings::myProfile | changedSettings::theme));
    retranslate();

    ui->collapsableWidgetCommon->setContentLayout(*(ui->layoutCommon));
    ui->collapsableWidgetBans->setContentLayout(*(ui->layoutBans));
    ui->collapsableWidgetBadges->setContentLayout(*(ui->layoutBadges));
    ui->collapsableWidgetPlayTime->setContentLayout(*(ui->layoutPlayTime));
    ui->collapsableWidgetGamesPlayTime->setContentLayout(*(ui->layoutGamesPlayTime));
    ui->collapsableWidgetCustomizations->setContentLayout(*(ui->layoutCustomizations));
}

FormProfile::~FormProfile() {
    delete ui;
}

SProfile FormProfile::getProfile() const {
    return profile_;
}

SGames FormProfile::getGames() const {
    return games_;
}

SFriends FormProfile::getFriends() const {
    return friends_;
}

void FormProfile::profileToUi(const SProfile &aProfile) {
    profile_ = aProfile;
    setProfileStatus();
    setOnlineStatus();

    setGames(profile_.steamId());
    setFriends(profile_.steamId());
    updateVisibleInfo();
}

void FormProfile::setColorStatus(const QColor &aColor) {
    ui->LabelPersonaState->setStyleSheet("color: " + aColor.name());
    ui->LabelName->setlightningColor(aColor);
    ui->LabelNameMinimize->setlightningColor(aColor);
}

#define setData {
void FormProfile::setProfile(const SProfile &aProfile) {
    profile_ = aProfile;
    isMinimizeInit_ = false;
    isBaseInit_ = false;
    isMaximizeInit_ = false;
}

void FormProfile::setProfileStatus() {
    switch (profile_.communityVisibilityState()) {
        case 1:
            ui->LabelProfileStatus->setPixmap(QPixmap("://dataLoaded/profile_red.png").scaled(20, 20));
            ui->LabelProfileStatus->setToolTip(textToToolTip(tr("Данные профиля скрыты")));
            break;
        case 3:
            ui->LabelProfileStatus->setPixmap(QPixmap("://dataLoaded/profile_green.png").scaled(20, 20));
            ui->LabelProfileStatus->setToolTip(textToToolTip(tr("Данные профиля загружены")));
            break;
        case 8:
            ui->LabelProfileStatus->setPixmap(QPixmap("://dataLoaded/profile_yellow.png").scaled(20, 20));
            ui->LabelProfileStatus->setToolTip(textToToolTip(tr("Данные профиля доступны только для друзей")));
            break;
        default:
            ui->LabelProfileStatus->setPixmap(QPixmap("://dataLoaded/profile_red.png").scaled(20, 20));
            ui->LabelProfileStatus->setToolTip(textToToolTip(tr("Не удалось загрузить данные профиля")));
    }
}

void FormProfile::setOnlineStatus() {
    ui->LabelPersonaState->setText(profile_.stateFullText());
    setColorStatus(profile_.stateColor());
}

void FormProfile::setGames(const ProfileID &aSteamId) {
    games_ = SGame::load(aSteamId, true, true);
    if (games_.count() > 0) {
        ui->ButtonGames->setEnabled(true);
        ui->ButtonStatistics->setEnabled(true);
        ui->LabelGamesStatus->setPixmap(QPixmap("://dataLoaded/games_green.png").scaled(20, 20));
        ui->LabelGamesStatus->setToolTip(textToToolTip("Игры загружены"));
        setTimePlayed(games_);
    } else {
        ui->ButtonGames->setEnabled(false);
        ui->ButtonStatistics->setEnabled(false);
        ui->LabelGamesStatus->setPixmap(QPixmap("://dataLoaded/games_red.png").scaled(20, 20));
        ui->LabelGamesStatus->setToolTip(textToToolTip("Не удалось загрузить информацию о играх"));
    }
}

void FormProfile::setFriends(const ProfileID &aSteamId) {
    friends_ = SFriend::load(aSteamId);
    if (friends_.count() > 0) {
        ui->ButtonFriends->setEnabled(true);
        ui->LabelFriendsStatus->setPixmap(QPixmap("://dataLoaded/friends_green.png").scaled(20, 20));
        ui->LabelFriendsStatus->setToolTip(textToToolTip("Друзья загружены"));
    } else {
        ui->ButtonFriends->setEnabled(false);
        ui->LabelFriendsStatus->setPixmap(QPixmap("://dataLoaded/friends_red.png").scaled(20, 20));
        ui->LabelFriendsStatus->setToolTip(textToToolTip("Не удалось загрузить информацию о друзьях"));
    }
}

void FormProfile::setMinimizeInfo(const SProfile &aProfile) {
    ui->LabelAvatarMinimize->setPixmap(aProfile.pixmapFramedAvatar(QSize(32, 32) * c_frameLargerBy));
    ui->LabelNameMinimize->setText(aProfile.personaName());

    isMinimizeInit_ = true;
}

void FormProfile::setBaseInfo(const SProfile &aProfile) {
    //Аватарки
    ui->LabelAvatar->setPixmap(aProfile.pixmapFramedAvatar(QSize(64, 64) * c_frameLargerBy));

    //Ник
    ui->LabelName        ->setText(aProfile.personaName());
    //Реальное имя
    if (profile_.realName() != "") {
        ui->LabelRealName     ->setVisible(true);
        ui->LabelRealNameValue->setVisible(true);
        ui->LabelRealNameValue->setText(aProfile.realName());
    } else {
        ui->LabelRealName     ->setVisible(false);
        ui->LabelRealNameValue->setVisible(false);
    }
    isBaseInit_ = true;
}

void FormProfile::setMaximizeInfo(const SProfile &aProfile) {
    setCommonInfo(aProfile);
    setLvl(aProfile.steamId());
    setBadges(aProfile.steamId());
    setBans(aProfile.steamId());
    setCustomizations(aProfile.steamId());
    isMaximizeInit_ = true;
}

void FormProfile::setCommonInfo(const SProfile &aProfile) {
    if (aProfile.profileUrl().indexOf("/id/") > -1) {
        ui->labelVanityUrlValue->setText(aProfile.profileUrl().mid(aProfile.profileUrl().indexOf("/id/") + 4).remove("/"));
        ui->labelVanityUrlValue->setVisible(true);
        ui->labelVanityUrl->setVisible(true);
    } else {
        ui->labelVanityUrlValue->setText("");
        ui->labelVanityUrlValue->setVisible(false);
        ui->labelVanityUrl->setVisible(false);
    }
    ui->labelAccountIdValue->setText(aProfile.steamId());
    //Url
    ui->labelLinkValue->setText("<img height=13 style=\"vertical-align: top\" src=\"" + Images::link() + "\"> "
                                "<a href=\"" + aProfile.profileUrl() + "\">"
                                "<span style=\" text-decoration: underline; color:#2d7fc8;\">" + aProfile.profileUrl() + "</span></a>");
    //Дата создания аккаунта
    ui->labelAccountCreatedValue->setText(aProfile.timeCreated().toString(Settings::dateFormat()));
    if (aProfile.timeCreated() > QDateTime::fromSecsSinceEpoch(0, Qt::LocalTime)) {
        ui->labelAccountCreated     ->setVisible(true);
        ui->labelAccountCreatedValue->setVisible(true);
    } else {
        ui->labelAccountCreated     ->setVisible(false);
        ui->labelAccountCreatedValue->setVisible(false);
    }
    //Код страны
    ui->labelLanguageValue->setText(aProfile.locCountryCode());
    if (aProfile.locCountryCode() != "") {
        ui->labelLanguage     ->setVisible(true);
        ui->labelLanguageValue->setVisible(true);
    } else {
        ui->labelLanguage     ->setVisible(false);
        ui->labelLanguageValue->setVisible(false);
    }

    if (aProfile.profileState() == 1) {
        ui->LabelProfileState->setlightningColor(c_green_color)->setText(tr("Настроен профиль сообщества"));
    } else {
        ui->LabelProfileState->setlightningColor(c_red_color)->setText(tr("Не настроен профиль сообщества"));
    }

    if (aProfile.commentPermission() == 1) {
        ui->LabelCommentPermission->setlightningColor(c_green_color)->setText(tr("Публичные комментарии разрешены"));
    } else {
        ui->LabelCommentPermission->setlightningColor(c_red_color)->setText(tr("Публичные комментарии запрещены"));
    }
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

        ui->labelVacBansValue->setlightningColor(c_red_color)->setText(tr("%1, последний %2 %3").arg(
                                                                    QString::number(bans[0].numberOfVacBan()),
                                                                    QString::number(bans[0].daysSinceLastBan()),
                                                                    dayAgo));
    } else {
        ui->labelVacBansValue->setlightningColor(c_green_color)->setText(tr("Отсутствуют"));
    }
    if(bans[0].numberOfGameBans() > 0) {
        ui->labelGameBansValue->setlightningColor(c_red_color)->setText(tr("%1").arg(QString::number(bans[0].numberOfGameBans())));
    } else {
        ui->labelGameBansValue->setlightningColor(c_green_color)->setText(tr("Отсутствуют"));
    }
    if(bans[0].communityBanned()) {
        ui->labelCommunityBanValue->setlightningColor(c_red_color)->setText(tr("Забанен"));
    } else {
        ui->labelCommunityBanValue->setlightningColor(c_green_color)->setText(tr("Отсутствует"));
    }
    if(bans[0].numberOfGameBans() > 0) {
        ui->labelTradeBanValue->setlightningColor(c_red_color)->setText(tr("%1").arg(bans[0].economyBan()));
    } else {
        ui->labelTradeBanValue->setlightningColor(c_green_color)->setText(tr("Отсутствует"));
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
    SBadges badges = SBadge::load(aSteamId);
    for (const SBadge &badge: badges) {
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

    ui->labelSpecialBadgesValue->setText(QString::number(specialBadges));
    ui->labelNormalBadgesValue->setText(QString::number(normalBadges));
    ui->labelFoilBadgesValue->setText(QString::number(foilBadges));
    ui->labelNormalLvl1Value ->setText(QString::number(lvl1Badges));
    ui->labelNormalLvl2Value->setText(QString::number(lvl2Badges));
    ui->labelNormalLvl3Value->setText(QString::number(lvl3Badges));
    ui->labelNormalLvl4Value->setText(QString::number(lvl4Badges));
    ui->labelNormalLvl5Value->setText(QString::number(lvl5Badges));
    ui->labelNormalLvl5plusValue->setText(QString::number(lvlMore5Badges));
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
    for (const SGame &game: aGames) {
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
    ui->labelPlayTime0Value->setText(QString::number(never));
    ui->labelPlayTime0_1Value->setText(QString::number(zero_one));
    ui->labelPlayTime1_10Value->setText(QString::number(one_ten));
    ui->labelPlayTime10_24Value->setText(QString::number(ten_day));
    ui->labelPlayTime24_240Value->setText(QString::number(day_tenday));
    ui->labelPlayTime240_500Value->setText(QString::number(tenday_fivehundreed));
    ui->labelPlayTime500_1000Value->setText(QString::number(fivehundreed_onethouthand));
    ui->labelPlayTime1000plusValue->setText(QString::number(more_than_onethouthand));

    ui->labelWindowsPlayTimeValue->setText(tr("%1h").arg(QString::number(1.0 * win / 60, 'f', 1)));
    ui->labelLinuxPlayTimeValue->setText(tr("%1h").arg(QString::number(1.0 * linux / 60, 'f', 1)));
    ui->labelMacOsPlayTimeValue->setText(tr("%1h").arg(QString::number(1.0 * mac / 60, 'f', 1)));
    ui->labelTotalPlayTimeValue->setText(tr("%1h").arg(QString::number(1.0 * total / 60, 'f', 1)));
}

void FormProfile::setCustomizations(const ProfileID &aSteamId) {
    auto items = SProfile::getEquippedItems(aSteamId);
    ui->labelCustomizationBackgroundValue->setText(items.value("profile_background").item_title);
    ui->labelCustomizationMiniProfileValue->setText(items.value("mini_profile_background").item_title);
    ui->labelCustomizationAvatarFrameValue->setText(items.value("avatar_frame").item_title);
    ui->labelCustomizationAnimatedAvatarValue->setText(items.value("animated_avatar").item_title);

    QList<SProfileCustomization> customizations = SProfileCustomization::load(aSteamId);
    int purchased = 0;
    int upgraded = 0;
//    int lvl1 = 0;
//    int lvl2 = 0;
//    int lvl3 = 0;
    for (const SProfileCustomization &customization: customizations) {
        if (customization.isUpgradable()) {
//            switch (customization.level()) {
//            case 1: {
//                ++lvl1;
//                break;
//            }
//            case 2: {
//                ++lvl2;
//                break;
//            }
//            case 3: {
//                ++lvl3;
//                break;
//            }
//            }
            ++upgraded;
        }
        if (customization.isPurchase()) {
            if (customization.count() > 0) {
                ++purchased;
            }
        }
    }
    ui->labelCustomizationPointsPurchasesValue->setText(QString::number(purchased));
    ui->labelCustomizationPointsUpgradesValue->setText(QString::number(upgraded));
//    ui->LabelProfileCustomization1LvlValue->setText(QString::number(lvl1));
//    ui->LabelProfileCustomization2LvlValue->setText(QString::number(lvl2));
//    ui->LabelProfileCustomization3LvlValue->setText(QString::number(lvl3));
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
#define setDataEnd }

#define updateData {
void FormProfile::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::profileInfo)) {
        updateVisibleInfo();
    }
    if (aSettings.testFlag(changedSettings::myProfile)) {
        updateMyProfile();
    }
    Form::updateSettings(aSettings);
}

void FormProfile::updateVisibleInfo() {
    visibleInfo_ = Settings::profileInfoSize();
    switch(visibleInfo_) {
    case 0: {
        if (!isMinimizeInit_) {
            setMinimizeInfo(profile_);
        }
        break;
    }
    case 1: {
        if (!isBaseInit_) {
            setBaseInfo(profile_);
        }
        break;
    }
    case 2: {
        if (!isBaseInit_) {
            setBaseInfo(profile_);
        }
        if (!isMaximizeInit_) {
            setMaximizeInfo(profile_);
        }
        break;
    }
    default: {
        qWarning() << "Unknown state \"visible info\" at FormProfile";
    }
    }

    ui->LabelNameMinimize       ->setVisible(visibleInfo_ == 0);
    ui->LabelAvatarMinimize     ->setVisible(visibleInfo_ == 0);
    ui->FrameProfileBaseInfo    ->setVisible(visibleInfo_ >= 1);
    ui->FrameProfileMaximumInfo ->setVisible(visibleInfo_ >= 2);

    updateMyProfile();
    retranslate();
}

void FormProfile::updateInfo() {
    profile_.update();
    profileToUi(profile_);
}

void FormProfile::updateMyProfile() {
    ui->ButtonSetProfile->setEnabled(Settings::myProfile() != profile_.steamId());
}

void FormProfile::retranslate() {
    ui->retranslateUi(this);
    switch (visibleInfo_) {
    case 0:{
        ui->ButtonGames     ->setText("");
        ui->ButtonFriends   ->setText("");
        ui->ButtonStatistics->setText("");
        ui->ButtonSetProfile->setText("");
        ui->ButtonGames     ->setToolTip(tr("Игры (%1)").arg(games_.count() > 0 ? QString::number(games_.count()) : tr("???")));
        ui->ButtonFriends   ->setToolTip(tr("Друзья (%1)").arg(friends_ != QList<SFriend>() ? QString::number(friends_.count()) : tr("???")));
        ui->ButtonStatistics->setToolTip(tr("Статистика"));
        ui->ButtonSetProfile->setToolTip(tr("Установить профиль как свой"));
        break;
    }
    case 1:{
        ui->ButtonGames     ->setText(tr("Игры (%1)").arg(games_.count() > 0 ? QString::number(games_.count()) : tr("???")));
        ui->ButtonFriends   ->setText(tr("Друзья (%1)").arg(friends_ != QList<SFriend>() ? QString::number(friends_.count()) : tr("???")));
        ui->ButtonStatistics->setText(tr("Статистика"));
        ui->ButtonSetProfile->setText(tr("Это мой профиль"));
        ui->ButtonGames     ->setToolTip("");
        ui->ButtonFriends   ->setToolTip("");
        ui->ButtonStatistics->setToolTip("");
        ui->ButtonSetProfile->setToolTip("");
        break;
    }
    case 2:{
        ui->ButtonGames     ->setText(tr("Игры (%1)").arg(games_.count() > 0 ? QString::number(games_.count()) : tr("???")));
        ui->ButtonFriends   ->setText(tr("Друзья (%1)").arg(friends_ != QList<SFriend>() ? QString::number(friends_.count()) : tr("???")));
        ui->ButtonStatistics->setText(tr("Статистика"));
        ui->ButtonSetProfile->setText(tr("Это мой профиль"));
        ui->ButtonGames     ->setToolTip("");
        ui->ButtonFriends   ->setToolTip("");
        ui->ButtonStatistics->setToolTip("");
        ui->ButtonSetProfile->setToolTip("");
    }
    }

    ui->collapsableWidgetCommon->setTitle(tr("Common info"));
    ui->collapsableWidgetBans->setTitle(tr("Bans"));
    ui->collapsableWidgetBadges->setTitle(tr("Badges"));
    ui->collapsableWidgetPlayTime->setTitle(tr("Playtime for platform"));
    ui->collapsableWidgetGamesPlayTime->setTitle(tr("Games for playtime"));
    ui->collapsableWidgetCustomizations->setTitle(tr("Profile customizations"));

    ui->labelWindowsPlayTime->setToolTip(tr("Playtime on windows"));
    ui->labelLinuxPlayTime->setToolTip(tr("Playtime on linux"));
    ui->labelMacOsPlayTime->setToolTip(tr("Playtime on macOS"));

    setCommonInfo(profile_);
    setBans(profile_.steamId());
    setTimePlayed(games_);
    setOnlineStatus();
}

void FormProfile::updateIcons() {
    ui->labelLinkValue->setText("<img height=13 style=\"vertical-align: top\" src=\"" + Images::link() + "\"> "
                                "<a href=\"" + profile_.profileUrl() + "\">"
                                "<span style=\" text-decoration: underline; color:#2d7fc8;\">" + profile_.profileUrl() + "</span></a>");
    ui->ButtonSetProfile->setIcon(QIcon(Images::setHome()));
    ui->ButtonStatistics->setIcon(QIcon(Images::statistic()));
    ui->ButtonFriends   ->setIcon(QIcon(Images::friends()));
    ui->ButtonGames     ->setIcon(QIcon(Images::games()));

    ui->labelSpecialBadges->setPixmap(QPixmap(Images::special()).scaled(25, 25));
    ui->labelNormalBadges->setPixmap(QPixmap(Images::normal()).scaled(25, 25));
    ui->labelFoilBadges->setPixmap(QPixmap(Images::foil()).scaled(25, 25));
    ui->labelNormalLvl1->setPixmap(QPixmap(Images::badges1()).scaled(25, 25));
    ui->labelNormalLvl2->setPixmap(QPixmap(Images::badges2()).scaled(25, 25));
    ui->labelNormalLvl3->setPixmap(QPixmap(Images::badges3()).scaled(25, 25));
    ui->labelNormalLvl4->setPixmap(QPixmap(Images::badges4()).scaled(25, 25));
    ui->labelNormalLvl5->setPixmap(QPixmap(Images::badges5()).scaled(25, 25));
    ui->labelNormalLvl5plus->setPixmap(QPixmap(Images::badges5plus()).scaled(25, 25));

    ui->labelWindowsPlayTime->setPixmap(QPixmap(Images::windows()).scaled(25, 25));
    ui->labelLinuxPlayTime->setPixmap(QPixmap(Images::linux()).scaled(25, 25));
    ui->labelMacOsPlayTime->setPixmap(QPixmap(Images::mac()).scaled(25, 25));
}
#define updateDataEnd }

#define uiFunctions {
void FormProfile::buttonSetProfile_Clicked() {
    Settings::setMyProfile(profile_.steamId());
    emit s_settingsUpdated(changedSettings::myProfile);
}

void FormProfile::buttonGames_Clicked() {
    if(games_.count() > 0) {
        emit s_goToGames(profile_.steamId());
    }
}

void FormProfile::buttonFriends_Clicked() {
    if(friends_ != QList<SFriend>()) {
        emit s_goToFriends(profile_.steamId());
    }
}

void FormProfile::buttonStatistics_Clicked() {
    if(games_.count() > 0) {
        emit s_goToStatistic(profile_);
    }
}
#define uiFunctionsEnd }
