#include "formcontainerachievements.h"
#include "ui_formcontainerachievements.h"

FormContainerAchievements::FormContainerAchievements(QWidget *parent): QWidget(parent), ui(new Ui::FormContainerAchievements) {
    ui->setupUi(this);
    if (parentWidget()) {
        parentWidget()->setGeometry(Settings::achievementContainerGeometry());
        parentWidget()->move(Settings::achievementContainerPos());
    }
}

FormContainerAchievements::~FormContainerAchievements() {
    qInfo() << "Форма вкладок достижений удалилась";
    delete ui;
}

void FormContainerAchievements::show() {
    parentWidget()->parentWidget()->show();
}

void FormContainerAchievements::closeEvent(QCloseEvent *aEvent) {
    Q_UNUSED(aEvent);
    if (parentWidget()->parentWidget()) {
        Settings::setAchievementContainerParams(parentWidget()->parentWidget()->geometry());
    }
    Settings::syncronizeSettings();
    emit s_formClose();
}

void FormContainerAchievements::addFormAchievement(SAchievementsPlayer &aPl, SProfile aProfile, SGame &aGame) {
    for (int i = 0; i < ui->TabWidgetAchievements->count(); ++i) {
        FormAchievements *achievements = dynamic_cast<FormAchievements*>(ui->TabWidgetAchievements->widget(i));
        if (achievements) {
            if((achievements->getGameAppId() == aGame.appId()) && (achievements->getProfileId() == aProfile.steamID())) {
                achievements->buttonUpdate_Clicked();
                ui->TabWidgetAchievements->setCurrentIndex(i);
                return;
            }
        }
    }
    int tabIndex = ui->TabWidgetAchievements->addTab(new FormAchievements(aPl, aProfile, aGame, this), aGame.name());
    ui->TabWidgetAchievements->setTabIcon(tabIndex, aGame.pixmapIcon());
    ui->TabWidgetAchievements->setCurrentIndex(tabIndex);
}

void FormContainerAchievements::on_TabWidgetAchievements_tabCloseRequested(int aIndex) {
    ui->TabWidgetAchievements->removeTab(aIndex);
    if(ui->TabWidgetAchievements->count() == 0) {
        close();
    } else {
        emit s_removeAchievements(aIndex);
    }
}
