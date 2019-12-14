#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString AID, QString AKey, SGames AGames, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormGames){
    ui->setupUi(this);
    _id=AID;
    _key=AKey;
    SGames game=AGames;
    for (int i=0;i<game.GetCount();_games.push_back(game.GetGame(i++)));
    switch(_setting.GetTheme()){
    case 1:{
        _theme="white";
        break;
        }
    case 2:{
        _theme="black";
        break;
        }
    }
    InitComponents();
    ui->LineEditGame->setFocus();
}

#define Init {
void FormGames::InitComponents(){
    for (int i=0; i < _games.size()-1; i++) {
        for (int j=0; j < _games.size()-i-1; j++) {
            if (_games[j].GetName() > _games[j+1].GetName()) {
                SGame temp = _games[j];
                _games[j] = _games[j+1];
                _games[j+1] = temp;
            }
        }
    }
    _favorites.SetPath("Files/Favorites/Games.json","Games");
    ui->TableWidgetGames->setColumnCount(4);
    ui->TableWidgetGames->setColumnCount(6);
    ui->TableWidgetGames->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetGames->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("Название игры")));
    ui->TableWidgetGames->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Прогресс")));
    ui->TableWidgetGames->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("Достижения")));
    ui->TableWidgetGames->setHorizontalHeaderItem(4,new QTableWidgetItem(tr("Избранное")));
    ui->TableWidgetGames->setHorizontalHeaderItem(5,new QTableWidgetItem(tr("Скрыть")));
    ui->TableWidgetGames->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetGames->setAlternatingRowColors(true);
    ui->TableWidgetGames->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetGames->setSortingEnabled(true);
    ui->ButtonFind->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/find.png"));
    //iAchievement = ;
    QIcon iFavorite = QIcon(":/"+_theme+"/program/"+_theme+"/favorites.png");
    QIcon iHide = QIcon(":/"+_theme+"/program/"+_theme+"/hide.png");
    ui->TableWidgetGames->setRowCount(_games.count());
    for (int i=0;i<_games.count();i++) {
        ui->TableWidgetGames->setRowHeight(i,33);
        QPushButton *button1 = new QPushButton(tr("Достижения"));
        button1->setMinimumSize(QSize(25,25));
        connect(button1,&QPushButton::pressed,this,&FormGames::AchievementsClicked);
        button1->setObjectName("ButtonAchievements"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(i,3,button1);

        QPushButton *button2 = new QPushButton;
        //проверка всего на избранное
        button2->setIcon(iFavorite);
        button2->setMinimumSize(QSize(25,25));
        connect(button2,&QPushButton::pressed,this,&FormGames::FavoritesClicked);
        button2->setObjectName("ButtonFavorites"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(i,4,button2);

        QPushButton *button3 = new QPushButton;
        button3->setIcon(iHide);
        button3->setMinimumSize(QSize(25,25));
        connect(button3,&QPushButton::pressed,this,&FormGames::HideClicked);
        button3->setObjectName("ButtonHide"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(i,5,button3);

        QProgressBar *pb = new QProgressBar;
        ui->TableWidgetGames->setCellWidget(i,2,pb);
    }
    ui->TableWidgetGames->setColumnWidth(0,33);
    ui->TableWidgetGames->setColumnWidth(1,300);
    Threading LoadTable(this);
    LoadTable.AddThreadGames(ui->TableWidgetGames,_games);
}
void FormGames::ProgressLoading(int p,int row){

}
void FormGames::OnFinish(){
    ui->TableWidgetGames->resizeColumnsToContents();
    QFile fileHide1;
    fileHide1.setFileName("Files/Hide/"+_id+".txt");
    if(fileHide1.open(QIODevice::ReadOnly)){
        while(!fileHide1.atEnd()){
            _hide << QString::fromLocal8Bit(fileHide1.readLine()).remove("\r\n").remove("\n");
        }
        fileHide1.close();
    }
    QFile fileHide2;
    fileHide2.setFileName("Files/Hide/All.txt");
    if(fileHide2.open(QIODevice::ReadOnly)){
        while(!fileHide2.atEnd()){
            _hide << QString::fromLocal8Bit(fileHide2.readLine()).remove("\r\n").remove("\n");
        }
        fileHide2.close();
    }
    QStringList hideList=_hide;
    _achievements = new SAchievementsPlayer[_games.size()];
    for(int i=0;i<_games.size();i++){
        QString path = "images/icon_games/"+_games[i].GetImg_icon_url()+".jpg";
        if(!QFile::exists(path)){
            if(_numRequests<500){
                if(_games[i].GetImg_icon_url()!=""){
                    ImageRequest *image = new ImageRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                           QString::number(_games[i].GetAppid())+"/"+_games[i].GetImg_icon_url()+".jpg",i,path,true);
                    connect(image,&ImageRequest::s_finished,this,&FormGames::OnResultImage);
                    _request.append(image);
                    _numRequests++;
                    }
                _numNow++;
            }
            } else {
            QPixmap pixmap;
            pixmap.load(path);
            QLabel *label = new QLabel;
            label->setPixmap(pixmap);
            ui->TableWidgetGames->setCellWidget(i,0,label);
            }
        SAchievementsPlayer *pl = new SAchievementsPlayer(_key,QString::number(_games[i].GetAppid()),_id);
        pl->SetIndex(i);
        connect(pl,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
        for (int j=0;j<hideList.size();j++) {
            if(hideList[j].toInt()==_games[i].GetAppid()){
                ui->TableWidgetGames->setRowHidden(i,true);
                ui->TableWidgetGames->item(i,1)->setTextColor(Qt::red);
                static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(i,5))->setEnabled(false);
                hideList.removeAt(j);
                break;
            }
            }
        }
}
void FormGames::OnResultImage(ImageRequest *AImage){
    QPixmap pixmap;
    pixmap.loadFromData(AImage->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetGames->setCellWidget(AImage->GetRow(),0,label);
    if(_numRequests==500&&_numNow<_games.size()){
        while (QFile::exists("images/icon_games/"+_games[_numNow].GetImg_icon_url()+".jpg")||_games[_numNow].GetImg_icon_url()=="") {
            _numNow++;
        }
        AImage->LoadImage("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                        QString::number(_games[_numNow].GetAppid())+"/"+_games[_numNow].GetImg_icon_url()+".jpg",_numNow,
                        "images/icon_games/"+_games[_numNow].GetImg_icon_url()+".jpg",true);
        _numNow++;
    } else {
        disconnect(AImage,&ImageRequest::s_finished,this,&FormGames::OnResultImage);
        AImage->deleteLater();
    }
}
void FormGames::OnResultAchievements(SAchievementsPlayer AAchievements){
    disconnect(&AAchievements,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
    QProgressBar *pb = static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(AAchievements.GetIndex(),2));
    pb->setMaximum(AAchievements.GetCount());
    pb->setMinimumSize(QSize(25,25));
    if(AAchievements.GetCount()>0){
        int val=0;
        for (int i=0;i<AAchievements.GetCount();i++) {
            if(AAchievements.GetAchieved(i)==1)
                val++;
        }
        pb->setValue(val);
    } else {
        pb->setValue(0);
        static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(AAchievements.GetIndex(),3))->setEnabled(false);
    }
    ui->TableWidgetGames->setItem(AAchievements.GetIndex(),2,new QTableWidgetItem(pb->text().rightJustified(4,'0')));
    _achievements[AAchievements.GetIndex()]=AAchievements;
    //ach->deleteLater();
}
#define InitEnd }

#define System {
FormGames::~FormGames(){
    qDebug()<<_numRequests<<"запросов на картинки";
    delete [] _achievements;
    //for (int i=0;i<=numrequests;i++) {
    //    delete request[numrequests];
    //}
    delete ui;
}
void FormGames::closeEvent(QCloseEvent*){
    emit s_return_to_profile();
    //delete this;
}
void FormGames::ReturnFromAchievements(int ANum){
    disconnect(achievementsforms[ANum],&FormAchievements::s_return_to_games,this,&FormGames::ReturnFromAchievements);
    //delete achievementsforms[num];
}
#define SystemEnd }

#define Filter {
void FormGames::on_LineEditGame_textChanged(const QString arg){
    if(_setting.GetVisibleHiddenGames()==1&&arg!=""){
        for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
                ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,1)->text().toUpper().indexOf(arg.toUpper(),0)==-1);
        }
    } else {
        for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
                ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,1)->text().toUpper().indexOf(arg.toUpper(),0)==-1);
                QStringList hideList=_hide;
                for (int j=0;j<hideList.size();j++) {
                    if(hideList[j].toInt()==_games[i].GetAppid()){
                        ui->TableWidgetGames->setRowHidden(i,true);
                        hideList.removeAt(j);
                        break;
                    }
                    }
        }
    }
}
void FormGames::on_ButtonFind_clicked(){
    on_LineEditGame_textChanged(ui->LineEditGame->text());
}
#define FilterEnd }

#define Functions {
void FormGames::AchievementsClicked(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int index=btn->objectName().mid(18,6).toInt();
    QEventLoop loop;
    SAchievementsPercentage Percentage(_key,QString::number(_games[index].GetAppid()));
    connect(&Percentage, SIGNAL(s_finished()), &loop, SLOT(quit()));
    loop.exec();
    disconnect(&Percentage, SIGNAL(s_finished()), &loop, SLOT(quit()));
    if(Percentage.GetCount()==0){
        QMessageBox::warning(this,tr("Ошибка"),tr("В этой игре нет достижений"));
    } else {
        FormAchievements *fa = new FormAchievements(_key,_achievements[index],_id,_games[index],_windowChildCount++);
        achievementsforms.append(fa);
        connect(fa,&FormAchievements::s_return_to_games,this,&FormGames::ReturnFromAchievements);
        fa->show();
    }
}
void FormGames::FavoritesClicked(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int index=btn->objectName().mid(15).toInt();
    QJsonObject newValue;
    newValue["id"]=QString::number(_games[index].GetAppid());
    newValue["name"]=_games[index].GetName();
    if(_favorites.AddValue(newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
void FormGames::HideClicked(){
    QString save="";
    QMessageBox messageBox(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите скрыть эту игру?"));
    QAbstractButton *btnProfile = messageBox.addButton(tr("Да, но только для этого аккаунта"),QMessageBox::YesRole);
    QAbstractButton *btnAll = messageBox.addButton(tr("Да, для всех аккаунтов"),QMessageBox::YesRole);
    messageBox.addButton(tr("Отмена"),QMessageBox::NoRole);
    messageBox.exec();
    if(messageBox.clickedButton()==btnProfile){
         save="Files/Hide/"+_id+".txt";
    } else if(messageBox.clickedButton()==btnAll){
         save="Files/Hide/All.txt";
    } else return;

    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int gamei=btn->objectName().mid(10,6).toInt();
    _setting.CreateFile(save);
    QFile hide(save);
    hide.open(QIODevice::Append | QIODevice::Text);
    QTextStream writeStream(&hide);
    writeStream <<_games[gamei].GetAppid()<<"\n";
    hide.close();
    for (int i=0;i<_games.size();i++) {
        if(_games[gamei].GetName()==ui->TableWidgetGames->item(i,1)->text()){
            ui->TableWidgetGames->item(i,1)->setTextColor(Qt::red);
            ui->TableWidgetGames->setRowHidden(i,true);
            ui->TableWidgetGames->setCurrentCell(i+1,4);
            break;
        }
    }
    btn->setEnabled(false);
}
#define FunctionsEnd }
