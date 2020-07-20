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

FormContainerAchievements::~FormContainerAchievements() {
    _setting.setAchievementContainerParams(this->geometry());
    _setting.syncronizeSettings();
    emit s_formClose();
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
    QString filePath = _setting._pathImagesIconGames + aGame._img_icon_url + ".jpg";
    QString urlPath = "http://media.steampowered.com/steamcommunity/public/images/apps/" + QString::number(aGame._appID) + "/" + aGame._img_icon_url + ".jpg";
    if(!QFile::exists(filePath)) {
        if(aGame._img_icon_url != "") {
            RequestImage *tabIcon = new RequestImage(urlPath, filePath, true, this);
            tabIcon->setIndex(tabIndex);
            connect(tabIcon, &RequestImage::s_loadComplete, this, &FormContainerAchievements::OnLoadImage);
        }
    } else {
        QPixmap tabIcon(filePath);
        ui->TabWidgetAchievements->setTabIcon(tabIndex, tabIcon);
    }
}

void FormContainerAchievements::closeEvent(QCloseEvent *) {

}

void FormContainerAchievements::on_TabWidgetAchievements_tabCloseRequested(int aIndex) {
    ui->TabWidgetAchievements->removeTab(aIndex);
    if(ui->TabWidgetAchievements->count() == 0) {
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
