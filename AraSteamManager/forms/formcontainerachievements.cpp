#include "formcontainerachievements.h"
#include "ui_formcontainerachievements.h"

#include <QCloseEvent>
#include <QMessageBox>

FormContainerAchievements::FormContainerAchievements(QWidget *parent): Form(parent), ui(new Ui::FormContainerAchievements) {
    ui->setupUi(this);
//    if (parentWidget()) {
//        parentWidget()->setGeometry(Settings::achievementContainerGeometry());
//        parentWidget()->move(Settings::achievementContainerPos());
//    }

}

FormContainerAchievements::~FormContainerAchievements() {
//    emit s_closed();
    delete ui;
}

void FormContainerAchievements::retranslate() {

}

void FormContainerAchievements::updateIcons() {

}

void FormContainerAchievements::updateSettings(QFlags<changedSettings> aSettings) {
    for (int i = 0; i < ui->TabWidgetAchievements->count(); ++i) {
        if (FormAchievements *achievements = dynamic_cast<FormAchievements*>(ui->TabWidgetAchievements->widget(i))) {
            achievements->updateSettings(aSettings);
        }
    }
    Form::updateSettings(aSettings);
}

void FormContainerAchievements::show() {
    window()->show();
    Form::show();
}

void FormContainerAchievements::closeEvent(QCloseEvent *aEvent) {
    if (FramelessWindow *framelessWindow = window()) {
//        Settings::setAchievementContainerParams(framelessWindow->geometry());
        Settings::setAchievementContainerState(framelessWindow->saveState());
        Settings::setAchievementContainerGeometry(framelessWindow->saveGeometry());
    }
    clear();
    hide();
    aEvent->ignore();
}

void FormContainerAchievements::clear() {
    ui->TabWidgetAchievements->clear();
}

int FormContainerAchievements::getTabIndex(const SProfile &aProfile, const SGame &aGame) {
    for (int i = 0; i < ui->TabWidgetAchievements->count(); ++i) {
        if (FormAchievements *achievements = dynamic_cast<FormAchievements*>(ui->TabWidgetAchievements->widget(i))) {
            if((achievements->getGameAppId() == aGame.appId()) && (achievements->getProfileId() == aProfile.steamId())) {
                return i;
            }
        }
    }
    return -1;
}

void FormContainerAchievements::addFormAchievement(const SProfile &aProfile, const SGame &aGame) {
    int index = getTabIndex(aProfile, aGame);
    if (index > 0) {
        FormAchievements *achievements = dynamic_cast<FormAchievements*>(ui->TabWidgetAchievements->widget(index));
        achievements->update();
        ui->TabWidgetAchievements->setCurrentIndex(index);
        return;
    }
    FormAchievements *achievements = new FormAchievements(this);
    int tabIndex = ui->TabWidgetAchievements->addTab(achievements, aGame.name());
//    connect(achievements, &FormAchievements::s_progress, this, &Form::setStatus);
    connect(achievements, &FormAchievements::s_finishedAchievements, this, [&]() {
        clearStatus();
        if (dynamic_cast<FormAchievements*>(sender())->getAchievementsCount() == 0) {
            QMessageBox::warning(this, tr("Ошибка!"), tr("Достижения не найдены!"));
            on_TabWidgetAchievements_tabCloseRequested(getTabIndex(aProfile, aGame));
        }
    });
    connect(achievements, &FormAchievements::s_settingsUpdated, this, [&](QFlags<changedSettings> lSetting) {
        emit s_settingsUpdated(lSetting);
    });
    ui->TabWidgetAchievements->setTabIcon(tabIndex, aGame.pixmapIcon());
    ui->TabWidgetAchievements->setCurrentIndex(tabIndex);
    achievements->setData(aProfile, aGame);
}

void FormContainerAchievements::on_TabWidgetAchievements_tabCloseRequested(int aIndex) {
    qDebug() << aIndex;
    int tabs = ui->TabWidgetAchievements->count();
    ui->TabWidgetAchievements->widget(aIndex)->deleteLater();
//    ui->TabWidgetAchievements->removeTab(aIndex);
    if(tabs - 1 == 0) {
        window()->hide();
//        deleteLater();
//        close();
    } else {
        emit s_removeAchievements(aIndex);
    }
}
