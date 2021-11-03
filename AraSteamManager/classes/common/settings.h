#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QFile>
#include <QRect>
#include <QLoggingCategory>
#include <QFontDatabase>
#include <QApplication>
#include <QStandardPaths>
#include <QGradient>
#include <QLinearGradient>
#include <QRadialGradient>

//Q_DECLARE_LOGGING_CATEGORY(logDebug)
//Q_DECLARE_LOGGING_CATEGORY(logInfo)
//Q_DECLARE_LOGGING_CATEGORY(logFunc)
//Q_DECLARE_LOGGING_CATEGORY(logWarning)
//Q_DECLARE_LOGGING_CATEGORY(logCritical)

enum changedSettings {
    myProfile = 0x01,
    language = 0x02,
    theme = 0x04,
    saveImages = 0x08,
    visibleHiddenGame = 0x10,
    profileInfo = 0x20
};

struct Theme {
    Theme();

    QColor textColor;
    QGradient *textGradient = nullptr;
    Theme &setText(const QColor&, QGradient *gradient = nullptr);
    QColor getText();
    QString getTextString();

    QColor disabledBackgroundColor;
    QGradient *disabledBackgroundGradient = nullptr;
    Theme &setDisabledBackground(const QColor&, QGradient *gradient = nullptr);
    QColor getDisabledBackground();
    QString getDisabledBackgroundString();

    QColor disabledColor;
    QGradient *disabledGradient = nullptr;
    Theme &setDisabled(const QColor&, QGradient *gradient = nullptr);
    QColor getDisabled();
    QString getDisabledString();

    QColor hoverColor;
    QGradient *hoverGradient = nullptr;
    Theme &setHover(const QColor&, QGradient *gradient = nullptr);
    QColor getHover();
    QString getHoverString();

    QColor borderColor;
    QGradient *borderGradient = nullptr;
    Theme &setBorder(const QColor&, QGradient *gradient = nullptr);
    QColor getBorder();
    QString getBorderString();

    QColor alternateColor;
    QGradient *alternateGradient = nullptr;
    Theme &setAlternate(const QColor&, QGradient *gradient = nullptr);
    QColor getAlternate();
    QString getAlternateString();

    QColor backgroundColor;
    QGradient *backgroundGradient = nullptr;
    Theme &setBackground(const QColor&, QGradient *gradient = nullptr);
    QColor getBackground();
    QString getBackgroundString();

    QColor backgroundSelectedItemColor;
    QGradient *backgroundSelectedItemGradient = nullptr;
    Theme &setBackgroundSelectedItem(const QColor&, QGradient *gradient = nullptr);
    QColor getBackgroundSelectedItem();
    QString getBackgroundSelectedItemString();

    QColor backgroundSecondColor;
    QGradient *backgroundSecondGradient = nullptr;
    Theme &setBackgroundSecondGradient(const QColor&, QGradient *gradient = nullptr);
    QColor getBackgroundSecondGradient();
    QString getBackgroundSecondGradientString();

    QColor backgroundProgressbarColor;
    QGradient *backgroundProgressbarGradient = nullptr;
    Theme &setBackgroundProgressbar(const QColor&, QGradient *gradient = nullptr);
    QColor getBackgroundProgressbar();
    QString getBackgroundProgressbarString();

    QColor backgroundBadProgressbarColor;
    QGradient *backgroundBadProgressbarGradient = nullptr;
    Theme &setBackgroundBadProgressbar(const QColor&, QGradient *gradient = nullptr);
    QColor getBackgroundBadProgressbar();
    QString getBackgroundBadProgressbarString();

    QColor backgroundProgressbarProgressColor;
    QGradient *backgroundProgressbarProgressGradient = nullptr;
    Theme &setBackgroundProgressbarProgress(const QColor&, QGradient *gradient = nullptr);
    QColor getBackgroundProgressbarProgress();
    QString getBackgroundProgressbarProgressString();

    QColor selectedColor;
    QGradient *selectedGradient = nullptr;
    Theme &setSelected(const QColor&, QGradient *gradient = nullptr);
    QColor getSelected();
    QString getSelectedString();

    QColor headerFormColor;
    QGradient *headerFormGradient = nullptr;
    Theme &setHeaderForm(const QColor&, QGradient *gradient = nullptr);
    QColor getHeaderForm();
    QString getHeaderFormString();

    QColor backgroundItemColor;
    QGradient *backgroundItemGradient = nullptr;
    Theme &setBackgroundItem(const QColor&, QGradient *gradient = nullptr);
    QColor getBackgroundItem();
    QString getBackgroundItemString();

    QColor backgroundAlternateItemColor;
    QGradient *backgroundAlternateItemGradient = nullptr;
    Theme &setBackgroundAlternateItem(const QColor&, QGradient *gradient = nullptr);
    QColor getBackgroundAlternateItem();
    QString getBackgroundAlternateItemString();

    QColor forItemHoverColor;
    QGradient *forItemHoverGradient = nullptr;
    Theme &setForItemHover(const QColor&, QGradient *gradient = nullptr);
    QColor getForItemHover();
    QString getForItemHoverString();

    QColor mainProfileBackgroundColor;
    QGradient *mainProfileBackgroundGradient = nullptr;
    Theme &setMainProfileBackground(const QColor&, QGradient *gradient = nullptr);
    QColor getMainProfileBackground();
    QString getMainProfileBackgroundString();

    QColor mainBackgroundColor;
    QGradient *mainBackgroundGradient = nullptr;
    Theme &setMainBackground(const QColor&, QGradient *gradient = nullptr);
    QColor getMainBackground();
    QString getMainBackgroundString();

    QString   pathIcons;
    Theme &setPathIcons(const QString&);
    QString getPathIcons();

private:
    QString getText(const QColor&, QGradient*);
};

Theme blueTheme();

class Settings {
public:
    static const QString c_organizationName;
    static const QString c_organizationDomain;
    static const QString c_applicationName;

    static void setMyProfile(const QString &myProfiles);
    static QString myProfile();
    static void setLanguage(const int &language);
    static int language();
    static void setTheme(const int &theme);
    static int theme();
    static void setSaveimage(const int &saveImage);
    static int saveImages();
    static void setVisibleHiddenGames(const int &visibleHiddenGames);
    static int visibleHiddenGames();
    static void setVisibleProfileInfo(const int &visibleProfileInfo);
    static int profileInfoSize();

    static void setMainWindowParams(QRect geometry);
    static QRect mainWindowGeometry();
    static void setMainWindowPos(const QPoint &pos);
    static QPoint mainWindowPos();
    static void setMainWindowIsMaximize(bool maximize);
    static bool isMainWindowMaximize();

    static void setGamesTableIconWidth(const int &width);
    static int gamesTableIconWidth();
    static void setGamesTableTitleWidth(const int &width);
    static int gamesTableTitleWidth();
    static void setGamesTableCommentWidth(const int &width);
    static int gamesTableCommentWidth();
    static void setGamesTableProgressWidth(const int &width);
    static int gamesTableProgressWidth();

    static void setFriendsTableIconWidth(const int &width);
    static int friendsTableIconWidth();
    static void setFriendsTableNameWidth(const int &width);
    static int friendsTableNameWidth();
    static void setFriendsTableAddedWidth(const int &width);
    static int friendsTableAddedWidth();
    static void setFriendsTableStatusWidth(const int &width);
    static int friendsTableStatusWidth();
    static void setFriendsTableIsOpenWidth(const int &width);
    static int friendsTableIsOpenWidth();

    static void setAchievementContainerParams(QRect geometry);
    static QRect achievementContainerGeometry();
    static QPoint achievementContainerPos();

    static void setAchievementsTableIconWidth(const int &width);
    static int achievementsTableIconWidth();
    static void setAchievementsTableTitleWidth(const int &width);
    static int achievementsTableTitleWidth();
    static void setAchievementsTableDescriptionWidth(const int &width);
    static int achievementsTableDescriptionWidth();
    static void setAchievementsTableCommentWidth(const int &width);
    static int achievementsTableCommentWidth();
    static void setAchievementsTablePercentWidth(const int &width);
    static int achievementsTablePercentWidth();
    static void setAchievementsTableAchievedWidth(const int &width);
    static int achievementsTableAchievedWidth();

    static void setAchievementsCompareIconVisible(const int &width);
    static int achievementsCompareIconVisible();
    static void setAchievementsCompareTitleVisible(const int &width);
    static int achievementsCompareTitleVisible();
    static void setAchievementsCompareDescriptionVisible(const int &width);
    static int achievementsCompareDescriptionVisible();
    static void setAchievementsComparePercentVisible(const int &width);
    static int achievementsComparePercentVisible();

    static QString iconsColor();
    static QString defaultFont();
    static QString qssTheme();

    static void syncronizeSettings();

    static const QString dateTimeFormat();
    static const QString dateFormat();
    static const QString dateTimeFormatShort();
private:
    static QSettings *_settings;

};

class Paths {
public:
    static QString documents();
    static QString temp();
    static QString defaultFont();
    static QString categories(QString gameId = "");
    static QString favorites(QString type = "");
    static QString hiddenGames(QString steamId = "");
    static QString groupGames(QString profileId = "");
    static QString imagesProfiles(const QString &url);
    static QString imagesAchievements(const QString &gameId, const QString &url = "");
    static QString imagesGames(const QString &url);
    static QString commentsGames(const QString &profileId);
    static QString commentsAchievements(const QString &aProfileId = "");
};

class Images {
public:
    static QString loading();
    static QString logo();

    //States
    static QString stateBlue();
    static QString stateGreen();
    static QString stateRed();
    static QString stateYellow();

    static QString levels(const int &hundreds);

    //Achievements Checkbox
    static QString allAchievements();
    static QString reached();
    static QString notReached();

    //Achievements Categories
    static QString checkVisible();
    static QString uncheckVisible();
    static QString reverse();
    static QString deleteCategory();
    static QString deleteAllCategories();

    //Achievements
    static QString category();
    static QString checkAll();
    static QString guides();
    static QString guide();

    //Comments
    static QString isComment();
    static QString isNotComment();

    //Dirrection arrows
    static QString first();
    static QString back();
    static QString next();
    static QString last();
    static QString top();
    static QString bottom();
    static QString up();
    static QString down();

    //Favorites
    static QString isFavorites();
    static QString isNotFavorites();

    //Hide
    static QString hide();
    static QString visible();

    //Main
    static QString findProfile();
    static QString home();
    static QString left();
    static QString right();
    static QString settings();

    //Management
    static QString apply();
    static QString cancel();
    static QString change();
    static QString compare();
    static QString create();
    static QString deleteIcon();
    static QString deleteAll();
    static QString moveItem();
    static QString moveInTree();
    static QString download();
    static QString edit();
    static QString find();
    static QString update();

    //Profile icon
    static QString friends();
    static QString games();
    static QString setHome();
    static QString statistic();

    //Window buttons
    static QString closeWindow();
    static QString maximizeWindow();
    static QString minimizeWindow();
    static QString normalizeWindow();

    //Other
    static QString achievement();
    static QString backRounded();
    static QString exit();
    static QString filter();
    static QString goTo();
    static QString group1();
    static QString group2();
    static QString link();
    static QString profile();

    //Widgets
    static QString checkBoxChecked();
    static QString checkBoxCheckedHover();
    static QString checkBoxCheckedPress();

    static QString checkBoxUnchecked();
    static QString checkBoxUncheckedHover();
    static QString checkBoxUncheckedPress();

    static QString radioButtonChecked();
    static QString radioButtonCheckedHover();
    static QString radioButtonCheckedPress();

    static QString radioButtonUnchecked();
    static QString radioButtonUncheckedHover();
    static QString radioButtonUncheckedPress();

    static QString comboBoxDown();

    static QString scrollBarUp();
    static QString scrollBarDown();
    static QString scrollBarLeft();
    static QString scrollBarRight();

    static QString missingImage();
};

#endif // SETTINGS_H
