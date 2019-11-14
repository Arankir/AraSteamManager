#include "threadfriends.h"

ThreadFriends::ThreadFriends(QObject* parent) : QObject(parent){
    numrequests=0;
    numnow=0;
}

void ThreadFriends::Set(QTableWidget* TableWidgetFriends,QVector<SProfile> Profiles,SFriends Friends,QStringList Words){
    this->TableWidgetFriends=TableWidgetFriends;
    this->Profiles=Profiles;
    this->Friends=Friends;
    this->Words=Words;
}

int ThreadFriends::Fill(){
    for (int i=0;i<Friends.GetCount();i++) {
        int row = TableWidgetFriends->rowCount();
        TableWidgetFriends->insertRow(i);
        //qDebug()<<i;
        if(!QFile::exists("images/profiles/"+Profiles[i].GetAvatar().mid(72,20)+".jpg")){
            if(numrequests<500){
                qDebug()<<Profiles[i].GetAvatar()<<row<<"images/profiles/"+Profiles[i].GetAvatar().mid(72,20)+".jpg";
                ImageRequest* image = new ImageRequest(Profiles[i].GetAvatar(),row,"images/profiles/"+Profiles[i].GetAvatar().mid(72,20)+".jpg",true);
                connect(image,SIGNAL(onReady(ImageRequest*)),this,SLOT(OnResultImage(ImageRequest*)));
                request.append(image);
                numrequests++;
                numnow++;
                }
            } else {
            QPixmap pixmap;
            pixmap.load("images/profiles/"+Profiles[i].GetAvatar().mid(72,20)+".jpg");
            emit setimage(pixmap,row);
            }
        TableWidgetFriends->setItem(i,1,new QTableWidgetItem(Profiles[i].GetPersonaname()));
        int j;
        for (j=0;;j++) {
            if(Profiles[i].GetSteamid()==Friends.GetSteamid(j)){
                break;
            }
        }
        TableWidgetFriends->setItem(i,2,new QTableWidgetItem(Friends.GetFriend_since(j).toString("yyyy.MM.dd hh:mm:ss")));
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
        TableWidgetFriends->setItem(i,3,item4);
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
        TableWidgetFriends->setItem(i,4,item5);
        TableWidgetFriends->setItem(i,5,new QTableWidgetItem(Profiles[i].GetSteamid()));
        emit progress(i,row);
    }
    TableWidgetFriends->setColumnHidden(5,true);
    TableWidgetFriends->resizeColumnsToContents();
    TableWidgetFriends->setColumnWidth(0,33);
    emit finished();
    return 1;
}

void ThreadFriends::OnResultImage(ImageRequest* imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    emit setimage(pixmap,imgr->GetRow());
    qDebug()<<1<<imgr->GetRow();
    //ui->TableWidgetFriends->resizeRowToContents(imgr->GetRow());
    if(numrequests==500&&numnow<Friends.GetCount()){
        imgr->LoadImage(Profiles[numnow].GetAvatar(),numnow,"images/profiles/"+Profiles[numnow].GetAvatar().mid(72,20)+".jpg",true);
        numnow++;
    } else
        disconnect(imgr,SIGNAL(onReady(ImageRequest*)),this,SLOT(OnResultImage(ImageRequest*)));
    //imgr->deleteLater();
}
