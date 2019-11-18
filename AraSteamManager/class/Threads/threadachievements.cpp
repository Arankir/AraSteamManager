#include "threadachievements.h"

ThreadAchievements::ThreadAchievements(QObject* parent) : QObject(parent){
    numrequests=0;
    numnow=0;
}

void ThreadAchievements::Set(QString GameAppID, SAchievements achievements, QStringList Words, QLabel* LabelTotalPersent, QTableWidget* TableWidgetAchievements){
    this->GameAppID=GameAppID;
    this->achievements=achievements;
    this->Words=Words;
    this->LabelTotalPersent=LabelTotalPersent;
    this->TableWidgetAchievements=TableWidgetAchievements;
}

int ThreadAchievements::Fill(){
    int totalr=0;
    int totalnr=0;
    for(int i=0;i<achievements.GetAchievementsCount();i++){
        if(achievements.GetDisplayname(i)!=""){
            int row = TableWidgetAchievements->rowCount();
            TableWidgetAchievements->insertRow(row);
            TableWidgetAchievements->setItem(row,0,new QTableWidgetItem(achievements.GetApiname(i)));
            QString AchievementIcon=achievements.GetIcon(i).mid(66,achievements.GetIcon(i).length());
            if(!QFile::exists("images/achievements/"+GameAppID+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1))){
                ImageRequest* image = new ImageRequest(achievements.GetIcon(i),row,"images/achievements/"+GameAppID+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1),true);
                connect(image,&ImageRequest::onReady,this,&ThreadAchievements::OnResultImage);
                } else {
                QPixmap pixmap;
                pixmap.load("images/achievements/"+GameAppID+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1));
                emit setimage(pixmap,row);
                }
            TableWidgetAchievements->setItem(row,2,new QTableWidgetItem(achievements.GetDisplayname(i)));
            TableWidgetAchievements->setItem(row,3,new QTableWidgetItem(achievements.GetDescription(i)));
            TableWidgetAchievements->setItem(row,4,new QTableWidgetItem(achievements.GetPercent(i)<10?"0"+QString::number(achievements.GetPercent(i))+"%":QString::number(achievements.GetPercent(i))+"%"));
            if(achievements.GetAchieved(i)==1){
                TableWidgetAchievements->setItem(row,5,new QTableWidgetItem(Words[23]+" "+achievements.GetUnlocktime(i).toString("yyyy.MM.dd hh:mm")));
                totalr++;
                } else {
                TableWidgetAchievements->setItem(row,5,new QTableWidgetItem(Words[24]));
                totalnr++;
                }
            emit progress(i,row);
            TableWidgetAchievements->item(row,2)->setTextAlignment(Qt::AlignCenter);
            TableWidgetAchievements->item(row,3)->setTextAlignment(Qt::AlignCenter);
            TableWidgetAchievements->item(row,4)->setTextAlignment(Qt::AlignCenter);
            TableWidgetAchievements->item(row,5)->setTextAlignment(Qt::AlignCenter);
        }
    }
    LabelTotalPersent->setText(QString::number(totalr)+"/"+QString::number(totalr+totalnr)+" = "+QString::number(100.0*totalr/(totalr+totalnr))+"%");
    TableWidgetAchievements->setColumnHidden(0,true);
    TableWidgetAchievements->setColumnWidth(1,65);
    TableWidgetAchievements->setColumnWidth(2,100);
    TableWidgetAchievements->setColumnWidth(3,315);
    TableWidgetAchievements->resizeColumnToContents(4);
    TableWidgetAchievements->setColumnWidth(5,80);
    TableWidgetAchievements->setColumnWidth(6,50);
    TableWidgetAchievements->resizeRowsToContents();
    emit finished();
    return 1;
}

void ThreadAchievements::OnResultImage(ImageRequest* imgr){
    qDebug()<<2<<imgr->GetRow();
    disconnect(imgr,&ImageRequest::onReady,this,&ThreadAchievements::OnResultImage);
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    emit setimage(pixmap,imgr->GetRow());
    imgr->deleteLater();
}
