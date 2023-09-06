#include "settings.h"
#include <QDir>
#include <QApplication>
#include <QStandardPaths>

//Q_LOGGING_CATEGORY(logFunc,     "Function")

namespace reestrPaths {
    namespace settings {
        QString language()              {return "Settings/Language";}
        QString theme()                 {return "Settings/Theme";}
        QString saveImage()             {return "Settings/SaveImages";}
        QString myProfile()             {return "Settings/MyProfile";}
        QString profileInfoSize()       {return "Settings/VisibleProfileInfo";}

        QString dateFormat()            {return "Settings/DateFormat";}
        QString timeFormat()            {return "Settings/DateTimeFormat";}
        QString timeShortFormat()       {return "Settings/DateTimeShortFormat";}
    }
    namespace mainWindow {
        QString state()                 {return "MainWindow/State";}
        QString geometry()              {return "MainWindow/Geometry";}
    }
    namespace achievementContainer {
        QString state()                 {return "AchievementContainer/State";}
        QString geometry()              {return "AchievementContainer/Geometry";}
    }
}

const QString Settings::c_organizationName   = "Arankir";
const QString Settings::c_organizationDomain = "Arankir";
const QString Settings::c_applicationName    = "SteamAchievementsStatistic";

QSettings *Settings::settings_ = new QSettings(c_organizationName, c_applicationName);

#define SettingsStart {
void Settings::setMyProfile(const QString &aMyProfiles) {
    return settings_->setValue(reestrPaths::settings::myProfile(), aMyProfiles);
}

void Settings::setLanguage(int aLanguage) {
    return settings_->setValue(reestrPaths::settings::language(), aLanguage);
}

void Settings::setTheme(int aTheme) {
    return settings_->setValue(reestrPaths::settings::theme(), aTheme);
}

void Settings::setSaveimage(int aSaveImage) {
    return settings_->setValue(reestrPaths::settings::saveImage(), aSaveImage);
}

void Settings::setVisibleProfileInfo(int aVisibleProfileInfo) {
    return settings_->setValue(reestrPaths::settings::profileInfoSize(), aVisibleProfileInfo);
}

QString Settings::myProfile() {
    return settings_->value(reestrPaths::settings::myProfile(), "").toString();
}

int Settings::language() {
    return settings_->value(reestrPaths::settings::language(), 1).toInt();
}

int Settings::theme() {
    return settings_->value(reestrPaths::settings::theme(), 1).toInt();
}

int Settings::saveImages() {
    return settings_->value(reestrPaths::settings::saveImage(), 1).toInt();
}

int Settings::profileInfoSize() {
    return settings_->value(reestrPaths::settings::profileInfoSize(), 2).toInt();
}

const QString Settings::dateFormat() {
    return settings_->value(reestrPaths::settings::dateFormat(), "yyyy.MM.dd").toString();
}

const QString Settings::timeFormat() {
    return settings_->value(reestrPaths::settings::timeFormat(), "hh:mm:ss").toString();
}

const QString Settings::timeShortFormat() {
    return settings_->value(reestrPaths::settings::timeShortFormat(), "hh:mm").toString();
}

void Settings::setDateFormat(const QString &aFormat) {
    return settings_->setValue(reestrPaths::settings::dateFormat(), aFormat);
}

void Settings::setTimeFormat(const QString &aFormat) {
    return settings_->setValue(reestrPaths::settings::timeFormat(), aFormat);
}

void Settings::setTimeShortFormat(const QString &aFormat) {
    return settings_->setValue(reestrPaths::settings::timeShortFormat(), aFormat);
}

const QString Settings::dateTimeFormat() {
    return tr("%1 %2").arg(dateFormat(), timeFormat());
}

const QString Settings::dateTimeFormatShort() {
    return tr("%1 %2").arg(dateFormat(), timeShortFormat());
}

void Settings::setMainWindowState(const QByteArray &aState) {
    settings_->setValue(reestrPaths::mainWindow::state(), aState);
}

QByteArray Settings::mainWindowState() {
    return settings_->value(reestrPaths::mainWindow::state(), QByteArray()).toByteArray();
}

void Settings::setMainWindowGeometry(const QByteArray &aGeometry) {
    settings_->setValue(reestrPaths::mainWindow::geometry(), aGeometry);
}

QByteArray Settings::mainWindowGeometry() {
    return settings_->value(reestrPaths::mainWindow::geometry(), QByteArray()).toByteArray();
}

void Settings::setAchievementContainerState(const QByteArray &aState) {
    settings_->setValue(reestrPaths::achievementContainer::state(), aState);
}

QByteArray Settings::achievementContainerState() {
    return settings_->value(reestrPaths::achievementContainer::state(), QByteArray()).toByteArray();
}

void Settings::setAchievementContainerGeometry(const QByteArray &aGeometry) {
    settings_->setValue(reestrPaths::achievementContainer::geometry(), aGeometry);
}

QByteArray Settings::achievementContainerGeometry() {
    return settings_->value(reestrPaths::achievementContainer::geometry(), QByteArray()).toByteArray();
}

void Settings::syncronizeSettings() {
    settings_->sync();
}

#define SettingsEnd }

#define PathsStart {
QString Paths::documents() {
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + Settings::c_organizationName + "/" + Settings::c_applicationName + "/";
}

QString Paths::temp() {
    return QDir::tempPath() + "/" + Settings::c_organizationName + "/" + Settings::c_applicationName + "/";
}

QString Paths::categories(QString aGameId) {
    return QString(documents() + "categories/%1%2").arg(aGameId , aGameId != "" ? ".json" : "");
}

QString Paths::favorites(QString aType) {
    return QString(documents() + "favorites/%1%2").arg(aType , aType != "" ? ".json" : "");
}

QString Paths::groupGames(QString aProfileId) {
    return QString(documents() + "groups/%1%2").arg(aProfileId, aProfileId != "" ? ".txt" : "");
}

QString Paths::imagesProfiles(const QString &aUrl, const QString &aFormat) {
    return QString(temp() + "images/profiles/%1.%2")
            .arg(aUrl.mid(aUrl.lastIndexOf("/") + 1, aUrl.lastIndexOf(QString(".%2").arg(aFormat)) - aUrl.lastIndexOf("/") - 1),
                 aFormat);
}

QString Paths::imagesAchievements(const QString &aGameId, const QString &aUrl) {
    return QString(temp() + "images/achievements/%1/%2.jpg")
            .arg(aGameId,
                 aUrl.mid(aUrl.lastIndexOf("/") + 1, aUrl.lastIndexOf(".jpg") - aUrl.lastIndexOf("/") - 1));
}

QString Paths::imagesGames(const QString &aUrl) {
    return QString(temp() + "images/games/%1.jpg").arg(aUrl);
}

QString Paths::commentsGames(const QString &aProfileId) {
    return QString(documents() + "comments/games/%1%2").arg(aProfileId , aProfileId != "" ? ".json" : "");
}

QString Paths::commentsAchievements(const QString &aProfileId) {
    return QString(documents() + "comments/achievements/%1%2").arg(aProfileId, aProfileId != "" ? ".json" : "");
}
#define PathsEnd }
