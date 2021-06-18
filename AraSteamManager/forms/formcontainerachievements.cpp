#include "formcontainerachievements.h"
#include "ui_formcontainerachievements.h"

FormContainerAchievements::FormContainerAchievements(QWidget *parent): Form(parent), ui(new Ui::FormContainerAchievements) {
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

void FormContainerAchievements::updateSettings() {
    for (int i = 0; i < ui->TabWidgetAchievements->count(); ++i) {
        if (FormAchievements *achievements = dynamic_cast<FormAchievements*>(ui->TabWidgetAchievements->widget(i))) {
            achievements->updateSettings();
        }
    }
}

void FormContainerAchievements::show() {
    window()->show();
}

void FormContainerAchievements::closeEvent(QCloseEvent *aEvent) {
    Q_UNUSED(aEvent);
    if (FramelessWindow *framelessWindow = window()) {
        Settings::setAchievementContainerParams(framelessWindow->geometry());
    }
    emit s_closed();
//    Settings::syncronizeSettings();
//    emit s_formClose();
}

void FormContainerAchievements::addFormAchievement(/*QList<SAchievementPlayer> &aPl, */SProfile aProfile, SGame &aGame) {
    for (int i = 0; i < ui->TabWidgetAchievements->count(); ++i) {
        if (FormAchievements *achievements = dynamic_cast<FormAchievements*>(ui->TabWidgetAchievements->widget(i))) {
            if((achievements->getGameAppId() == aGame.appId()) && (achievements->getProfileId() == aProfile.steamID())) {
                achievements->update();
                ui->TabWidgetAchievements->setCurrentIndex(i);
                return;
            }
        }
    }
    auto achievements = new FormAchievements(this);
    int tabIndex = ui->TabWidgetAchievements->addTab(achievements, aGame.name());
    ui->TabWidgetAchievements->setTabIcon(tabIndex, aGame.pixmapIcon());
    ui->TabWidgetAchievements->setCurrentIndex(tabIndex);
    achievements->setData(/*aPl, */aProfile, aGame);
}

void FormContainerAchievements::on_TabWidgetAchievements_tabCloseRequested(int aIndex) {
    delete ui->TabWidgetAchievements->widget(aIndex);
    ui->TabWidgetAchievements->removeTab(aIndex);
    if(ui->TabWidgetAchievements->count() == 0) {
        close();
    } else {
        emit s_removeAchievements(aIndex);
    }
}
