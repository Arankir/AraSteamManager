#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDebug>
#include <QScreen>

class Settings : public QObject {
    const QString c_language="Settings/Language";
    const QString c_theme="Settings/Theme";
    const QString c_saveImage="Settings/SaveImages";
    const QString c_myProfile="Settings/MyProfile";
    const QString c_visibleHiddenGames="Settings/VisibleHiddenGames";
    const QString c_ProfileInfoSize="Settings/VisibleProfileInfo";
    const QString c_MaxTableRows="Settings/MaxTableRows";

    const QString c_mainWindowHeight="MainWindow/Height";
    const QString c_mainWindowWidth="MainWindow/Width";
    const QString c_mainWindowX="MainWindow/X";
    const QString c_mainWindowY="MainWindow/Y";
    const QString c_mainWindowMaximize="MainWindow/Maximize";
    const QString c_mainWindowPercentX="MainWindow/PercentX";
    const QString c_mainWindowPercentY="MainWindow/PercentY";

    const QString c_achievementContainerHeight="AchievementContainer/Height";
    const QString c_achievementContainerWidth="AchievementContainer/Width";
    const QString c_achievementContainerX="AchievementContainer/X";
    const QString c_achievementContainerY="AchievementContainer/Y";
    const QString c_achievementContainerMaximize="achievementContainer/Maximize";
    const QString c_achievementContainerPercentX="AchievementContainer/PercentX";
    const QString c_achievementContainerPercentY="AchievementContainer/PercentY";

    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);
    explicit Settings(QRect geometry, QObject *parent = nullptr);
    void customGeometry(QRect geometry);
    void setMyProfile(QString a_myProfiles);
    void setLanguage(int a_language);
    void setTheme(int a_theme);
    void setSaveimage(int a_saveImage);
    void setVisibleHiddenGames(int a_visibleHiddenGames);
    void setVisibleProfileInfo(int a_visibleProfileInfo);
    void setMaximumTableRows(int rows);

    void setMainWindowParams(QRect geometry);
    void setMainWindowPos(QPoint pos);
    void setMainWindowGeometry(QSize size);
    void setMainWindowMaximize(bool maximize);

    void setAchievementContainerParams(QRect geometry);

    QString getMyProfile();
    int getLanguage();
    int getTheme();
    QString getIconsColor();
    int getSaveImages();
    int getVisibleHiddenGames();
    int getProfileInfoSize();
    int getMaximumTableRows();

    QString getIconLoadingColor();
    QString getIconLogoColor();
    QString getIconStateBlue();
    QString getIconStateGreen();
    QString getIconStateRed();
    QString getIconStateYellow();
    QString getIconAll();
    QString getIconBack();
    QString getIconCancel();
    QString getIconChange();
    QString getIconCheckAll();
    QString getIconCheckVisible();
    QString getIconCloseWindow();
    QString getIconCompare();
    QString getIconDeleteAll();
    QString getIconDown();
    QString getIconExit();
    QString getIconIsFavorites();
    QString getIconIsNotFavorites();
    QString getIconFilter();
    QString getIconFind();
    QString getIconFindProfile();
    QString getIconFriends();
    QString getIconGames();
    QString getIconGoTo();
    QString getIconHide();
    QString getIconHome();
    QString getIconLeft();
    QString getIconLink();
    QString getIconMaximizeWindow();
    QString getIconMinimizeWindow();
    QString getIconNotReached();
    QString getIconProfile();
    QString getIconReached();
    QString getIconNormalizeWindow();
    QString getIconReverse();
    QString getIconRight();
    QString getIconSetHome();
    QString getIconSettings();
    QString getIconStatistic();
    QString getIconUncheckVisible();
    QString getIconUnhide();
    QString getIconUp();
    QString getIconUpdate();
    QString getIconCreate();
    QString getIconDelete();
    QString getIconEdit();
    QString getIconApply();
    QString getIconTop();
    QString getIconBottom();

    QString getIconCheckBoxChecked();
    QString getIconCheckBoxCheckedHover();
    QString getIconCheckBoxCheckedPress();
    QString getIconCheckBoxUnchecked();
    QString getIconCheckBoxUncheckedHover();
    QString getIconCheckBoxUncheckedPress();
    QString getIconRadioButtonChecked();
    QString getIconRadioButtonCheckedHover();
    QString getIconRadioButtonCheckedPress();
    QString getIconRadioButtonUnchecked();
    QString getIconRadioButtonUncheckedHover();
    QString getIconRadioButtonUncheckedPress();
    QString getIconComboboxDown();
    QString getIconScrollbarUp();
    QString getIconScrollbarDown();
    QString getIconScrollbarLeft();
    QString getIconScrollbarRight();

    QRect getMainWindowGeometry();
    QPoint getMainWindowPos();
    QPoint getMainWindowPercentPos();
    bool getMainWindowMaximize();

    QRect getAchievementContainerGeometry();
    QPoint getAchievementContainerPos();
    QPoint getAchievementContainerPercentPos();

    static QString getKey();
    static bool createDir(QString path);
    static QString getUrlIconGame(QString appId, QString img_icon_url);
    void syncronizeSettings();

    const QString _pathImagesAchievements="images/achievements/";// /номер игры/url.jpg
    const QString _pathImagesIconGames="images/icon_games/";// /url.jpg
    const QString _pathImagesProfiles="images/profiles/";// /url.jpg
    const QString _pathCategories="files/categories/";// /номер игры.json
    const QString _pathFavorites="files/favorites/";// /тип.json
    const QString _pathHide="files/hide/";// /номер игры.json

    const QString c_defaultFont="C:/JosefinSans-Italic-VariableFont_wght.ttf"; // Шрифт

signals:

private:
    QSettings *_settings;
    QRect _screen;
};

#endif // SETTINGS_H
