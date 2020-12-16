#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QKeyEvent>
#include <QTranslator>
#include <QLibraryInfo>
#include <QPropertyAnimation>
#include <QFontDatabase>
#include <QScreen>
#include <QSizeGrip>
#include <QGraphicsDropShadowEffect>
#include "framelesswindow.h"
#include "formcontainerachievements.h"
#include "forms/subForms/main/formgames.h"
#include "forms/subForms/main/formfriends.h"
#include "forms/subForms/main/formfavorites.h"
#include "forms/subForms/main/formstatistics.h"
#include "forms/subForms/main/formsettings.h"
#include "forms/subForms/main/formprofile.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/steamApi/structures/sbans.h"
#include "classes/steamApi/structures/slevels.h"
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/common/settings.h"
#include "subWidgets/progressBars/progressbargood.h"

namespace Ui {
    class FormMain;
}

class FormMain : public QWidget {
    Q_OBJECT

public:
    explicit FormMain(QWidget *parent = nullptr);
    ~FormMain() override;
    FormFavorites *_favoritesForm = nullptr;
    FormStatistics *_statisticsForm = nullptr;
    FormSettings *_settingsForm = nullptr;
    FormContainerAchievements *_containerAchievementsForm = nullptr;

public slots:
    void progressLoading(int, int);
    void addAchievements(SAchievementsPlayer &achievements, SGame &games);
    void removeAchievements(int index);
    void containerAchievementsClose();

    void goToGames(SProfile &profileSteamid, SGames &games);
    void goToFriends(const QString &profileSteamid, SFriends &friends);
    void goToFavorites();
    void goToStatistics(const QString &profileSteamid, SGames &games, const QString &profileName);

    void updateSettings();

    FormProfile *createFormProfile(SProfile &aProfile);
    FormStatistics *createFormStatistics(const QString &aId, SGames &aGames, const QString &aName);
    FormContainerAchievements *createFormContainerAchievements();
signals:
    void s_updateSettings();

private slots:
    //events
    void keyPressEvent(QKeyEvent*) override;
    void changeEvent(QEvent*) override;
    void closeEvent(QCloseEvent*) override;
    //Forms
    void showForm(int widgetIndex, int widthWindow = 300);
    void returnFromForms();
    //Systems
    void initComponents();
    void setIcons();
    void resizeScrollArea(int width = 300);
    void updateEnabledButtonsBackNext();
    //Functions
    void buttonFindProfile_Clicked();
    void goToProfile(const QString &id, ProfileUrlType type);
    void buttonSettings_Clicked();
    //Profile
    void buttonGoToMyProfile_Clicked();
    void buttonBack_Clicked();
    void buttonNext_Clicked();
    void buttonUpdate_Clicked();

private:
    Ui::FormMain *ui;
    int _achievementsCount = 0;

    bool _blockedLoad = false;

};

#endif // FORMMAIN_H
