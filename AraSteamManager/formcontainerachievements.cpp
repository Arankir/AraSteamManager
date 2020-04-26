#include "formcontainerachievements.h"
#include "ui_formcontainerachievements.h"

FormContainerAchievements::FormContainerAchievements(QWidget *parent) : QWidget(parent),ui(new Ui::FormContainerAchievements){
    ui->setupUi(this);
    _setting.CustomGeometry(QGuiApplication::primaryScreen()->geometry());
    this->setGeometry(_setting.GetAchievementContainerGeometry());
    if((_setting.GetAchievementContainerPos().x()>QGuiApplication::primaryScreen()->geometry().width())||(_setting.GetAchievementContainerPos().y()>QGuiApplication::primaryScreen()->geometry().height()))
        this->move(_setting.GetAchievementContainerPercentPos().x(),_setting.GetAchievementContainerPercentPos().y()-31);
    else
        this->move(_setting.GetAchievementContainerPos().x(),_setting.GetAchievementContainerPos().y()-31);
}

FormContainerAchievements::~FormContainerAchievements(){
    _setting.SetAchievementContainerParams(this->geometry());
    _setting.SyncronizeSettings();
    emit s_formClose();
    delete ui;
}

void FormContainerAchievements::AddFormAchievement(SAchievementsPlayer a_pl, QString a_ids, SGame a_game, int a_num){
    for (int i=0;i<ui->TabWidgetAchievements->count();i++) {
        if((static_cast<FormAchievements*>(ui->TabWidgetAchievements[i].widget(0))->GetGame().GetAppid()==a_game.GetAppid())&&(static_cast<FormAchievements*>(ui->TabWidgetAchievements[i].widget(0))->GetProfile()==a_ids)){
            static_cast<FormAchievements*>(ui->TabWidgetAchievements[i].widget(0))->on_ButtonUpdate_clicked();
            ui->TabWidgetAchievements->setCurrentIndex(i);
            return;
        }
    }
    FormAchievements *newFormAchievements = new FormAchievements(a_pl,a_ids,a_game,a_num,this);
    int tabIndex = ui->TabWidgetAchievements->addTab(newFormAchievements,"  "+a_game.GetName()+"  ");
    ui->TabWidgetAchievements->setCurrentIndex(tabIndex);
    QString filePath = _setting._pathImagesIconGames+a_game.GetImg_icon_url()+".jpg";
    QString urlPath = "http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(a_game.GetAppid())+"/"+a_game.GetImg_icon_url()+".jpg";
    if(!QFile::exists(filePath)){
        if(a_game.GetImg_icon_url()!=""){
            RequestImage *tabIcon = new RequestImage(urlPath,filePath,true,this);
            tabIcon->SetIndex(tabIndex);
            connect(tabIcon,&RequestImage::s_loadComplete,this,&FormContainerAchievements::OnLoadImage);
            }
    } else {
        QPixmap tabIcon(filePath);
        ui->TabWidgetAchievements->setTabIcon(tabIndex,tabIcon);
    }
}

void FormContainerAchievements::closeEvent(QCloseEvent *){
}

void FormContainerAchievements::on_TabWidgetAchievements_tabCloseRequested(int a_index){
    ui->TabWidgetAchievements->removeTab(a_index);
    if(ui->TabWidgetAchievements->count()==0)
        delete this;
    else
        emit s_removeAchievements(a_index);
}

void FormContainerAchievements::OnLoadImage(RequestImage *a_image){
    QPixmap tabIcon(a_image->GetPixmap());
    ui->TabWidgetAchievements->setTabIcon(a_image->GetIndex(),tabIcon);
    disconnect(a_image,&RequestImage::s_loadComplete,this,&FormContainerAchievements::OnLoadImage);
    a_image->deleteLater();
}
