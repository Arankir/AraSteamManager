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
#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sfriends.h"
#include "classes/common/settings.h"
#include "subWidgets/progressBars/progressbargood.h"
#include "form.h"

enum stackedFormsMain {
    FormMainNone        = 0,
    FormMainGames       = 1,
    FormMainFriends     = 2,
    FormMainStatistic   = 3,
    FormMainFavorites   = 4,
    FormMainSettings    = 5
};

namespace Ui {
    class FormMain;
}

class FormMain : public Form {
    Q_OBJECT

public:
    explicit FormMain(QWidget *parent = nullptr);
    ~FormMain() override;
    FormStatistics *_statisticsForm = nullptr;
    FormContainerAchievements *_containerAchievementsForm = nullptr;

public slots:
    void addAchievements(SGame games);
    void removeAchievements(int index);
    void containerAchievementsClose();

    void goToGames(SProfile &profileSteamid, SGames &games);
    void goToFriends(const QString &profileSteamid, QList<SFriend> &friends);
    void goToFavorites();
    void goToStatistics(const SProfile &profileSteamid, SGames &games);

    FormProfile *createFormProfile(SProfile &aProfile);
    FormStatistics *createFormStatistics(const SProfile &aProfile, SGames &aGames);
    FormContainerAchievements *createFormContainerAchievements();
signals:
    void s_updateSettings();

private slots:
    //events
    void keyPressEvent(QKeyEvent*) override;
//    void changeEvent(QEvent*) override;
    void closeEvent(QCloseEvent*) override;
    //Forms
    void showForm(int widgetIndex, int widthWindow = 300, int aWindowHeight = 400);
    void returnFromForms();
    //Systems
    void retranslate() override;
    void updateIcons() override;
    void updateSettings() override;
    void initComponents();
    void resizeScrollArea(int width = 300, int aHeight = 400);
    void updateEnabledButtonsBackNext();
    //Functions
    void buttonFindProfile_Clicked();
    void goToProfile(const QString &id, SProfileRequestType type);
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
