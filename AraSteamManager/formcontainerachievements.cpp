#include "formcontainerachievements.h"
#include "ui_formcontainerachievements.h"

FormContainerAchievements::FormContainerAchievements(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormContainerAchievements){
    ui->setupUi(this);
}

FormContainerAchievements::~FormContainerAchievements(){
    emit s_formClose();
    delete ui;
}

void FormContainerAchievements::AddFormAchievement(SAchievementsPlayer a_pl, QString a_ids, SGame a_game, int a_num){
    FormAchievements *newFormAchievements = new FormAchievements(a_pl,a_ids,a_game,a_num,this);
    int tabIndex = ui->TabWidgetAchievements->addTab(newFormAchievements,a_game.GetName());
    ui->TabWidgetAchievements->setCurrentIndex(tabIndex);
    QString filePath = "images/icon_games/"+a_game.GetImg_icon_url()+".jpg";
    QString urlPath = "http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(a_game.GetAppid())+"/"+a_game.GetImg_icon_url()+".jpg";
    if(!QFile::exists(filePath)){
        if(a_game.GetImg_icon_url()!=""){
            RequestData *image = new RequestData(urlPath,tabIndex,filePath,true);
            connect(image,&RequestData::s_finished,this,&FormContainerAchievements::OnLoadImage);
            }
        } else {
        QPixmap tabIcon(filePath);
        ui->TabWidgetAchievements->setTabIcon(tabIndex,tabIcon);
        }
}

void FormContainerAchievements::on_TabWidgetAchievements_tabCloseRequested(int a_index){
    ui->TabWidgetAchievements->removeTab(a_index);
    if(ui->TabWidgetAchievements->count()==0)
        delete this;
    else
        emit s_removeAchievements(a_index);
}

void FormContainerAchievements::OnLoadImage(RequestData *a_image){
    QPixmap tabIcon(a_image->GetAnswer());
    ui->TabWidgetAchievements->setTabIcon(a_image->GetRow(),tabIcon);
    disconnect(a_image,&RequestData::s_finished,this,&FormContainerAchievements::OnLoadImage);
    a_image->deleteLater();
}
