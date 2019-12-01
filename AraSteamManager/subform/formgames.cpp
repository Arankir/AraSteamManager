#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString ids, QString keys, SGames Gamess, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormGames){
    ui->setupUi(this);
    Words=Setting.GetWords("games");
    id=ids;
    key=keys;
    SGames Games=Gamess;
    for (int i=0;i<Games.GetCount();i++) {
        games.push_back(Games.GetGame(i));
    }
    switch(Setting.GetTheme()){
    case 1:{
        theme="white";
        break;
        }
    case 2:{
        theme="black";
        break;
        }
    }
    InitComponents();
    ui->LineEditGame->setFocus();
}

#define Init {
void FormGames::InitComponents(){
    for (int i=0; i < games.size()-1; i++) {
        for (int j=0; j < games.size()-i-1; j++) {
            if (games[j].GetName() > games[j+1].GetName()) {
                SGame temp = games[j];
                games[j] = games[j+1];
                games[j+1] = temp;
            }
        }
    }
    ui->TableWidgetGames->setColumnCount(4);
    ui->LineEditGame->setPlaceholderText(Words[0]);
    ui->ButtonFind->setText(" "+Words[1]);
    //ui->ButtonReturn->setText(" "+Words[2]);
    ui->TableWidgetGames->setColumnCount(5);
    ui->TableWidgetGames->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetGames->setHorizontalHeaderItem(1,new QTableWidgetItem(Words[3]));
    ui->TableWidgetGames->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[4]));
    ui->TableWidgetGames->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[5]));
    ui->TableWidgetGames->setHorizontalHeaderItem(4,new QTableWidgetItem("Скрыть"));
    ui->TableWidgetGames->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ButtonFind->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    //ui->ButtonReturn->setIcon(QIcon(":/"+theme+"/program/"+theme+"/back.png"));
    //Achievement = ;
    QIcon Favorite = QIcon(":/"+theme+"/program/"+theme+"/favorites.png");
    QIcon Hide = QIcon(":/"+theme+"/program/"+theme+"/hide.png");
    ui->TableWidgetGames->setRowCount(games.count());
    for (int i=0;i<games.count();i++) {
        ui->TableWidgetGames->setRowHeight(i,33);
        QPushButton *button1 = new QPushButton(Words[4]);
        button1->setMinimumSize(QSize(25,25));
        connect(button1,&QPushButton::pressed,this,&FormGames::AchievementsClicked);
        button1->setObjectName("ButtonAchievements"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(i,2,button1);

        QPushButton *button2 = new QPushButton;
        button2->setIcon(Favorite);
        button2->setMinimumSize(QSize(25,25));
        connect(button2,&QPushButton::pressed,this,&FormGames::FavoritesClicked);
        button2->setObjectName("ButtonFavorites"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(i,3,button2);

        QPushButton *button3 = new QPushButton;
        button3->setIcon(Hide);
        button3->setMinimumSize(QSize(25,25));
        connect(button3,&QPushButton::pressed,this,&FormGames::HideClicked);
        button3->setObjectName("ButtonHide"+QString::number(i));
        ui->TableWidgetGames->setCellWidget(i,4,button3);
    }
    ui->TableWidgetGames->setColumnWidth(0,33);
    ui->TableWidgetGames->setColumnWidth(1,300);
    Threading LoadTable(this);
    LoadTable.AddThreadGames(ui->TableWidgetGames,games);
}
void FormGames::ProgressLoading(int p,int row){

}
void FormGames::OnFinish(){
    ui->TableWidgetGames->resizeColumnsToContents();
    QFile FileHide1;
    FileHide1.setFileName("Files/Hide/"+id+".txt");
    if(FileHide1.open(QIODevice::ReadOnly)){
        while(!FileHide1.atEnd()){
            Hide << QString::fromLocal8Bit(FileHide1.readLine()).remove("\r\n").remove("\n");
        }
        FileHide1.close();
    }
    QFile FileHide2;
    FileHide2.setFileName("Files/Hide/All.txt");
    if(FileHide2.open(QIODevice::ReadOnly)){
        while(!FileHide2.atEnd()){
            Hide << QString::fromLocal8Bit(FileHide2.readLine()).remove("\r\n").remove("\n");
        }
        FileHide2.close();
    }
    QStringList hide=Hide;

    for(int i=0;i<games.size();i++){
        QString path = "images/icon_games/"+games[i].GetImg_icon_url()+".jpg";
        if(!QFile::exists(path)){
            if(numrequests<500){
                if(games[i].GetImg_icon_url()!=""){
                    ImageRequest *image = new ImageRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                           QString::number(games[i].GetAppid())+"/"+games[i].GetImg_icon_url()+".jpg",i,path,true);
                    connect(image,&ImageRequest::onReady,this,&FormGames::OnResultImage);
                    request.append(image);
                    numrequests++;
                    }
                numnow++;
            }
            } else {
            QPixmap pixmap;
            pixmap.load(path);
            QLabel *label = new QLabel;
            label->setPixmap(pixmap);
            ui->TableWidgetGames->setCellWidget(i,0,label);
            }
        ImageRequest *Achievements = new ImageRequest();
        connect(Achievements,&ImageRequest::onReady,this,&FormGames::OnResultAchievements);
        Achievements->LoadImage("https://api.steampowered.com/ISteamUserStats/GetGlobalAchievementPercentagesForApp/v1/?key="+key+
                                "&gameid="+QString::number(games[i].GetAppid()),i,
                                "ButtonAchievements"+QString::number(games[i].GetAppid())+"&"+games[i].GetImg_logo_url());
        for (int j=0;j<hide.size();j++) {
            if(hide[j].toInt()==games[i].GetAppid()){
                ui->TableWidgetGames->setRowHidden(i,true);
                hide.removeAt(j);
                break;
            }
            }
        }
}
void FormGames::OnResultImage(ImageRequest *imgr){
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetGames->setCellWidget(imgr->GetRow(),0,label);
    if(numrequests==500&&numnow<games.size()){
        while (QFile::exists("images/icon_games/"+games[numnow].GetImg_icon_url()+".jpg")||games[numnow].GetImg_icon_url()=="") {
            numnow++;
        }
        imgr->LoadImage("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                        QString::number(games[numnow].GetAppid())+"/"+games[numnow].GetImg_icon_url()+".jpg",numnow,
                        "images/icon_games/"+games[numnow].GetImg_icon_url()+".jpg",true);
        numnow++;
    } else {
        disconnect(imgr,&ImageRequest::onReady,this,&FormGames::OnResultImage);
        imgr->deleteLater();
    }
}
void FormGames::OnResultAchievements(ImageRequest *imgr){
    disconnect(imgr,&ImageRequest::onReady,this,&FormGames::OnResultAchievements);
    QJsonDocument doc = QJsonDocument::fromJson(imgr->GetAnswer());
    if(doc.object().value("achievementpercentages").toObject().value("achievements").toObject().value("achievement").toArray().at(0).isNull()){
        static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(imgr->GetRow(),2))->setEnabled(false);
    }
    imgr->deleteLater();
}
#define InitEnd }

#define System {
FormGames::~FormGames(){
    qDebug()<<numrequests<<"запросов на картинки";
    //if(numrequests)
    //    for (int i=0;i<=numrequests;i++) {
    //        delete request[numrequests];
    //    }
    //if(achievementsform)
    //    delete achievementsform;
    //delete all ukazateli
    delete ui;
}
void FormGames::closeEvent(QCloseEvent*){
    emit return_to_profile();
    //delete this;
}
void FormGames::returnfromachievements(int num){
    //windowchildcount--;
    disconnect(achievementsforms[num],&FormAchievements::return_to_games,this,&FormGames::returnfromachievements);
    //delete achievementsforms[num];
}
#define SystemEnd }

#define Filter {
void FormGames::on_LineEditGame_textChanged(const QString){
    for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
            ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,1)->text().toUpper().indexOf(ui->LineEditGame->text().toUpper(),0)>-1?false:true);
            QStringList hide=Hide;
            for (int j=0;j<hide.size();j++) {
                if(hide[j].toInt()==games[i].GetAppid()){
                    ui->TableWidgetGames->setRowHidden(i,true);
                    hide.removeAt(j);
                    break;
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
    SAchievementsPercentage Percentage(key,QString::number(games[index].GetAppid()));
    connect(&Percentage, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    disconnect(&Percentage, SIGNAL(finished()), &loop, SLOT(quit()));
    if(Percentage.GetAchievementsCount()==0){
        QMessageBox::warning(this,Words[6],Words[7]);
    } else {
        FormAchievements *fa = new FormAchievements(key,id,games[index],windowchildcount++);
        achievementsforms.append(fa);
        connect(fa,&FormAchievements::return_to_games,this,&FormGames::returnfromachievements);
        fa->show();
    }
}
void FormGames::FavoritesClicked(){

}
void FormGames::HideClicked(){
    QMessageBox messageBox(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите скрыть эту игру?"));
    QAbstractButton *btnProfile = messageBox.addButton(tr("Да, но только для этого аккаунта"),QMessageBox::YesRole);
    QAbstractButton *btnAll = messageBox.addButton(tr("Да, для всех аккаунтов"),QMessageBox::YesRole);
    messageBox.addButton(tr("Отмена"),QMessageBox::NoRole);
    messageBox.exec();
    QString Save="";
    if(messageBox.clickedButton()==btnProfile){
         qDebug()<<"Нажали профиль";
         Save="Files/Hide/"+id+".txt";
    } else if(messageBox.clickedButton()==btnAll){
         qDebug()<<"Нажали все";
         Save="Files/Hide/All.txt";
    } else return;

    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int index=btn->objectName().mid(10,6).toInt();
    QString savenow=Save;
    QString path="";
    while(savenow.length()>0){
        if(savenow.indexOf("/",0)>-1){
            QString dir=savenow.mid(0,savenow.indexOf("/",0));
            savenow=savenow.mid(savenow.indexOf("/",0)+1, savenow.length());
            if(!QDir(path+dir).exists()){
                QDir().mkdir(path+dir);
            }
            path+=dir+"/";
        } else {
            savenow="";
        }
    }
    QFile hide(Save);
    hide.open(QIODevice::Append | QIODevice::Text);
    QTextStream writeStream(&hide);
    writeStream <<games[index].GetAppid()<<"\n";
    hide.close();
    ui->TableWidgetGames->setRowHidden(index,true);
    ui->TableWidgetGames->setCurrentCell(index+1,4);
}
#define FunctionsEnd }
