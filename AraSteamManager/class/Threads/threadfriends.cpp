#include "threadfriends.h"

int ThreadFriends::Fill(){
    int row=0;
    for(auto &profile: _profiles){
        for(auto &friendP: _friends){
            if(profile.GetSteamid()==friendP._steamID){
                _TableWidgetFriends->setItem(row,c_tableColumnID,new QTableWidgetItem(profile.GetSteamid()));
                _TableWidgetFriends->setItem(row,c_tableColumnName,new QTableWidgetItem(profile.GetPersonaname()));
                _TableWidgetFriends->setItem(row,c_tableColumnAdded,new QTableWidgetItem(friendP._friend_since.toString("yyyy.MM.dd hh:mm:ss")));
                _TableWidgetFriends->setItem(row,c_tableColumnStatus,GetState(profile.GetGameextrainfo(),profile.GetPersonastate()));
                _TableWidgetFriends->setItem(row,c_tableColumnisPublic,GetPrivacy(profile.GetCommunityvisibilitystate()));
                emit s_progress(row,row);
                break;
            }
        }
        row++;
    }
    emit s_finished();
    return 1;
}

QTableWidgetItem *ThreadFriends::GetState(QString a_gameExtraInfo, int a_personaState){
    QTableWidgetItem *item = new QTableWidgetItem;
    if(!a_gameExtraInfo.isEmpty()){
        item->setText(tr("В игре"));
        item->setForeground(QColor(137,183,83));
    } else
        switch (a_personaState){
        case 0:{
                item->setText(tr("Не в сети"));
                item->setForeground(QColor(76,77,79));
                break;
        }
        case 1:{
                item->setText(tr("В сети"));
                item->setForeground(QColor(87,203,222));
                break;
        }
        case 2:{
                item->setText(tr("Не беспокоить"));
                item->setForeground(QColor(129,85,96));
                break;
        }
        case 3:{
                item->setText(tr("Нет на месте"));
                item->setForeground(QColor(70,120,142));
                break;
        }
        case 4:{
                item->setText(tr("Спит"));
                item->setForeground(QColor(70,120,142));
                break;
        }
        case 5:{
                item->setText(tr("Ожидает обмена"));
                item->setForeground(Qt::darkMagenta);
                break;
        }
        case 6:{
                item->setText(tr("Хочет поиграть"));
                item->setForeground(Qt::darkMagenta);
                break;
        }
        }
    return item;
}

QTableWidgetItem *ThreadFriends::GetPrivacy(int a_communityVisibilityState){
    QTableWidgetItem *item = new QTableWidgetItem;
    switch(a_communityVisibilityState){
    case 1:{
        item->setText(tr("Скрытый"));
        item->setForeground(QColor(110,14,14));
        break;
    }
    case 2:{
        item->setText(tr("Скрытый"));
        item->setForeground(QColor(110,14,14));
        break;
    }
    case 3:{
        item->setText(tr("Публичный"));
        item->setForeground(QColor(14,110,17));
        break;
    }
    case 8:{
        item->setText(tr("Скрытый"));
        item->setForeground(QColor(110,14,14));
        break;
    }
    }
    return item;
}

