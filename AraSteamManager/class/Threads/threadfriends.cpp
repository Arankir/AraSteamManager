#include "threadfriends.h"

ThreadFriends::ThreadFriends(QObject *parent) : QObject(parent){

}

void ThreadFriends::Set(QTableWidget *TableWidgetFriends,QVector<SProfile> Profiles,SFriends Friends){
    this->TableWidgetFriends=TableWidgetFriends;
    this->Profiles=Profiles;
    this->Friends=Friends;
}

int ThreadFriends::Fill(){
    for (int i=0;i<Friends.GetCount();i++) {
        int j;
        for (j=0;;j++) {
            if(Profiles[i].GetSteamid()==Friends.GetSteamid(j)){
                break;
            }
        }
        QTableWidgetItem *item4 = new QTableWidgetItem;
        if(!Profiles[i].GetGameextrainfo().isEmpty()){
            item4->setText(tr("В игре"));
            item4->setTextColor(QColor("#89b753"));
        } else
            switch (Profiles[i].GetPersonastate()){
            case 0:{
                    item4->setText(tr("Не в сети"));
                    item4->setTextColor(QColor("#4c4d4f"));
                    break;
            }
            case 1:{
                    item4->setText(tr("В сети"));
                    item4->setTextColor(QColor("#57cbde"));
                    break;
            }
            case 2:{
                    item4->setText(tr("Не беспокоить"));
                    item4->setTextColor(QColor("#815560"));
                    break;
            }
            case 3:{
                    item4->setText(tr("Нет на месте"));
                    item4->setTextColor(QColor("#46788e"));
                    break;
            }
            case 4:{
                    item4->setText(tr("Спит"));
                    item4->setTextColor(QColor("#46788e"));
                    break;
            }
            case 5:{
                    item4->setText(tr("Ожидает обмена"));
                    item4->setTextColor(Qt::darkMagenta);
                    break;
            }
            case 6:{
                    item4->setText(tr("Хочет поиграть"));
                    item4->setTextColor(Qt::darkMagenta);
                    break;
            }
            }
        QTableWidgetItem *item5 = new QTableWidgetItem;
        switch(Profiles[i].GetCommunityvisibilitystate()){
        case 1:{
            item5->setText(tr("Скрытый"));
            item5->setTextColor(Qt::red);
            break;
        }
        case 2:{
            item5->setText(tr("Скрытый"));
            item5->setTextColor(Qt::red);
            break;
        }
        case 3:{
            item5->setText(tr("Публичный"));
            item5->setTextColor(Qt::green);
            break;
        }
        case 8:{
            item5->setText(tr("Скрытый"));
            item5->setTextColor(Qt::red);
            break;
        }
        }
        TableWidgetFriends->setItem(i,1,new QTableWidgetItem(Profiles[i].GetPersonaname()));
        TableWidgetFriends->setItem(i,2,new QTableWidgetItem(Friends.GetFriend_since(j).toString("yyyy.MM.dd hh:mm:ss")));
        TableWidgetFriends->setItem(i,3,item4);
        TableWidgetFriends->setItem(i,4,item5);
        TableWidgetFriends->setItem(i,5,new QTableWidgetItem(Profiles[i].GetSteamid()));
        emit progress(i,i);
    }
    emit finished();
    return 1;
}

