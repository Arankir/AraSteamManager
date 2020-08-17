#include "formcontainerachievements.h"
#include "ui_formcontainerachievements.h"

FormContainerAchievements::FormContainerAchievements(QWidget *parent): QWidget(parent), ui(new Ui::FormContainerAchievements) {
    ui->setupUi(this);
    _setting.customGeometry(QGuiApplication::primaryScreen()->geometry());
    this->setGeometry(_setting.getAchievementContainerGeometry());
    if((_setting.getAchievementContainerPos().x() > QGuiApplication::primaryScreen()->geometry().width()) ||
       (_setting.getAchievementContainerPos().y() > QGuiApplication::primaryScreen()->geometry().height())) {
        this->move(_setting.getAchievementContainerPercentPos().x(), _setting.getAchievementContainerPercentPos().y() - 31);
    } else {
        this->move(_setting.getAchievementContainerPos().x(), _setting.getAchievementContainerPos().y() - 31);
    }
}

void FormContainerAchievements::closeEvent(QCloseEvent *aEvent) {
    _setting.setAchievementContainerParams(this->geometry());
    _setting.syncronizeSettings();
    emit s_formClose();
}

FormContainerAchievements::~FormContainerAchievements() {
    delete ui;
}

void FormContainerAchievements::AddFormAchievement(SAchievementsPlayer aPl, SProfile aProfile, SGame aGame, int aNum) {
    for (int i = 0; i < ui->TabWidgetAchievements->count(); i++) {
        FormAchievements *tab = dynamic_cast<FormAchievements*>(ui->TabWidgetAchievements[0].widget(i));
        if (tab) {
            if((tab->getGameAppId() == aGame._appID) && (tab->getProfileId() == aProfile._steamID)) {
                tab->buttonUpdate_Clicked();
                ui->TabWidgetAchievements->setCurrentIndex(i);
                return;
            }
        }
    }
    FormAchievements *newFormAchievements = new FormAchievements(aPl, aProfile, aGame, aNum, this);
    int tabIndex = ui->TabWidgetAchievements->addTab(newFormAchievements, "  " + aGame._name + "  ");
    ui->TabWidgetAchievements->setCurrentIndex(tabIndex);
    ui->TabWidgetAchievements->setTabIcon(tabIndex, aGame.getPixmapIcon());
}

void FormContainerAchievements::on_TabWidgetAchievements_tabCloseRequested(int aIndex) {
    ui->TabWidgetAchievements->removeTab(aIndex);
    if(ui->TabWidgetAchievements->count() == 0) {
        close();
        delete this;
    } else {
        emit s_removeAchievements(aIndex);
    }
}

void FormContainerAchievements::OnLoadImage(RequestImage *aImage) {
    QPixmap tabIcon(aImage->getPixmap());
    ui->TabWidgetAchievements->setTabIcon(aImage->getIndex(), tabIcon);
    disconnect(aImage, &RequestImage::s_loadComplete, this, &FormContainerAchievements::OnLoadImage);
    aImage->deleteLater();
}
