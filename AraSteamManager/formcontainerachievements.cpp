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

void FormContainerAchievements::AddFormAchievement(SAchievementsPlayer Apl, QString Aids, SGame Agame, int Anum, QWidget *parent){
    FormAchievements *fa = new FormAchievements(Apl,Aids,Agame,Anum,this);
    int index = ui->TabWidgetAchievements->addTab(fa,Agame.GetName());
    ui->TabWidgetAchievements->setCurrentIndex(index);

    QString path = "images/icon_games/"+Agame.GetImg_icon_url()+".jpg";
    if(!QFile::exists(path)){
            if(Agame.GetImg_icon_url()!=""){
                ImageRequest *image = new ImageRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                       QString::number(Agame.GetAppid())+"/"+Agame.GetImg_icon_url()+".jpg",index,path,true);
                connect(image,&ImageRequest::s_finished,this,&FormContainerAchievements::OnResultImage);
                }
        } else {
        QPixmap pixmap;
        pixmap.load(path);
        QLabel *label = new QLabel;
        label->setPixmap(pixmap);
        ui->TabWidgetAchievements->setTabIcon(index,pixmap);
        }
}

void FormContainerAchievements::on_TabWidgetAchievements_tabCloseRequested(int index){
    ui->TabWidgetAchievements->removeTab(index);
    if(ui->TabWidgetAchievements->count()==0)
        delete this;
    else
        emit s_removeAchievements(index);
}

void FormContainerAchievements::OnResultImage(ImageRequest *Aimage){
    QPixmap pixmap;
    pixmap.loadFromData(Aimage->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TabWidgetAchievements->setTabIcon(Aimage->GetRow(),pixmap);
    disconnect(Aimage,&ImageRequest::s_finished,this,&FormContainerAchievements::OnResultImage);
    Aimage->deleteLater();
}
