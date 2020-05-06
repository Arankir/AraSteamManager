#include "threadfriends.h"

ThreadFriends::ThreadFriends(QObject *parent) : QObject(parent){

}

void ThreadFriends::Set(QTableWidget *a_tableWidgetFriends,SProfiles a_profiles,SFriends a_friends){
    _TableWidgetFriends=a_tableWidgetFriends;
    _profiles=a_profiles;
    _friends=a_friends;
}

int ThreadFriends::Fill(){
    for (int i=0;i<_friends.GetCount();i++) {
        int j;
        for (j=0;;j++) {
            if(_profiles[i].GetSteamid()==_friends[j].GetSteamid()){
                break;
            }
        }
        QTableWidgetItem *item4 = new QTableWidgetItem;
        if(!_profiles[i].GetGameextrainfo().isEmpty()){
            item4->setText(tr("В игре"));
            item4->setForeground(QColor(137,183,83));
        } else
            switch (_profiles[i].GetPersonastate()){
            case 0:{
                    item4->setText(tr("Не в сети"));
                    item4->setForeground(QColor(76,77,79));
                    break;
            }
            case 1:{
                    item4->setText(tr("В сети"));
                    item4->setForeground(QColor(87,203,222));
                    break;
            }
            case 2:{
                    item4->setText(tr("Не беспокоить"));
                    item4->setForeground(QColor(129,85,96));
                    break;
            }
            case 3:{
                    item4->setText(tr("Нет на месте"));
                    item4->setForeground(QColor(70,120,142));
                    break;
            }
            case 4:{
                    item4->setText(tr("Спит"));
                    item4->setForeground(QColor(70,120,142));
                    break;
            }
            case 5:{
                    item4->setText(tr("Ожидает обмена"));
                    item4->setForeground(Qt::darkMagenta);
                    break;
            }
            case 6:{
                    item4->setText(tr("Хочет поиграть"));
                    item4->setForeground(Qt::darkMagenta);
                    break;
            }
            }
        QTableWidgetItem *item5 = new QTableWidgetItem;
        switch(_profiles[i].GetCommunityvisibilitystate()){
        case 1:{
            item5->setText(tr("Скрытый"));
            item5->setForeground(QColor(110,14,14));
            break;
        }
        case 2:{
            item5->setText(tr("Скрытый"));
            item5->setForeground(QColor(110,14,14));
            break;
        }
        case 3:{
            item5->setText(tr("Публичный"));
            item5->setForeground(QColor(14,110,17));
            break;
        }
        case 8:{
            item5->setText(tr("Скрытый"));
            item5->setForeground(QColor(110,14,14));
            break;
        }
        }

        _TableWidgetFriends->setItem(i,0,new QTableWidgetItem(_profiles[i].GetSteamid()));
        _TableWidgetFriends->setItem(i,2,new QTableWidgetItem(_profiles[i].GetPersonaname()));
        _TableWidgetFriends->setItem(i,3,new QTableWidgetItem(_friends[j].GetFriend_since().toString("yyyy.MM.dd hh:mm:ss")));
        _TableWidgetFriends->setItem(i,4,item4);
        _TableWidgetFriends->setItem(i,5,item5);
        emit s_progress(i,i);
    }
    emit s_finished();
    return 1;
}

