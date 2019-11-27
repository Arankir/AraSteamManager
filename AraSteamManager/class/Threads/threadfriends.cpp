#include "threadfriends.h"

ThreadFriends::ThreadFriends(QObject* parent) : QObject(parent){

}

void ThreadFriends::Set(QTableWidget* TableWidgetFriends,QVector<SProfile> Profiles,SFriends Friends,QStringList Words){
    this->TableWidgetFriends=TableWidgetFriends;
    this->Profiles=Profiles;
    this->Friends=Friends;
    this->Words=Words;
}

int ThreadFriends::Fill(){
    for (int i=0;i<Friends.GetCount();i++) {
        int j;
        for (j=0;;j++) {
            if(Profiles[i].GetSteamid()==Friends.GetSteamid(j)){
                break;
            }
        }
        QTableWidgetItem* item4 = new QTableWidgetItem;
        if(!Profiles[i].GetGameextrainfo().isEmpty()){
            item4->setText(Words[8]);
            item4->setTextColor(QColor("#89b753"));
        } else
            switch (Profiles[i].GetPersonastate()){
            case 0:{
                    item4->setText(Words[9]);
                    item4->setTextColor(QColor("#4c4d4f"));
                    break;
            }
            case 1:{
                    item4->setText(Words[10]);
                    item4->setTextColor(QColor("#57cbde"));
                    break;
            }
            case 2:{
                    item4->setText(Words[11]);
                    item4->setTextColor(QColor("#815560"));
                    break;
            }
            case 3:{
                    item4->setText(Words[12]);
                    item4->setTextColor(QColor("#46788e"));
                    break;
            }
            case 4:{
                    item4->setText(Words[13]);
                    item4->setTextColor(QColor("#46788e"));
                    break;
            }
            case 5:{
                    item4->setText(Words[14]);
                    item4->setTextColor(Qt::darkMagenta);
                    break;
            }
            case 6:{
                    item4->setText(Words[15]);
                    item4->setTextColor(Qt::darkMagenta);
                    break;
            }
            }
        QTableWidgetItem* item5 = new QTableWidgetItem;
        switch(Profiles[i].GetCommunityvisibilitystate()){
        case 1:{
            item5->setText(Words[17]);
            item5->setTextColor(Qt::red);
            break;
        }
        case 2:{
            item5->setText(Words[17]);
            item5->setTextColor(Qt::red);
            break;
        }
        case 3:{
            item5->setText(Words[16]);
            item5->setTextColor(Qt::green);
            break;
        }
        case 8:{
            item5->setText(Words[17]);
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

