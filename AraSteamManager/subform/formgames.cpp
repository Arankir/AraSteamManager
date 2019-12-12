#include "formgames.h"
#include "ui_formgames.h"

FormGames::FormGames(QString ids, QString keys, SGames gamess, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormGames){
    ui->setupUi(this);
    id=ids;
    key=keys;
    SGames game=gamess;
    for (int i=0;i<game.GetCount();i++) {
        games.push_back(game.GetGame(i));
    }
    switch(setting.GetTheme()){
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
    favorites.SetPath("Files/Favorites/Games.json","Games");
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
    ui->ButtonFind->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    //iAchievement = ;
    QIcon iFavorite = QIcon(":/"+theme+"/program/"+theme+"/favorites.png");
    QIcon iHide = QIcon(":/"+theme+"/program/"+theme+"/hide.png");
    ui->TableWidgetGames->setRowCount(games.count());
    for (int i=0;i<games.count();i++) {
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
    LoadTable.AddThreadGames(ui->TableWidgetGames,games);
}
void FormGames::ProgressLoading(int p,int row){

}
void FormGames::OnFinish(){
    ui->TableWidgetGames->resizeColumnsToContents();
    QFile fileHide1;
    fileHide1.setFileName("Files/Hide/"+id+".txt");
    if(fileHide1.open(QIODevice::ReadOnly)){
        while(!fileHide1.atEnd()){
            hide << QString::fromLocal8Bit(fileHide1.readLine()).remove("\r\n").remove("\n");
        }
        fileHide1.close();
    }
    QFile fileHide2;
    fileHide2.setFileName("Files/Hide/All.txt");
    if(fileHide2.open(QIODevice::ReadOnly)){
        while(!fileHide2.atEnd()){
            hide << QString::fromLocal8Bit(fileHide2.readLine()).remove("\r\n").remove("\n");
        }
        fileHide2.close();
    }
    QStringList hides=hide;
    achievements = new SAchievementsPlayer[games.size()];
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
        SAchievementsPlayer *pl = new SAchievementsPlayer(key,QString::number(games[i].GetAppid()),id);
        pl->SetIndex(i);
        connect(pl,SIGNAL(finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
        for (int j=0;j<hides.size();j++) {
            if(hides[j].toInt()==games[i].GetAppid()){
                ui->TableWidgetGames->setRowHidden(i,true);
                ui->TableWidgetGames->item(i,1)->setTextColor(Qt::red);
                static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(i,5))->setEnabled(false);
                hides.removeAt(j);
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
void FormGames::OnResultAchievements(SAchievementsPlayer ach){
    disconnect(&ach,SIGNAL(finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
    QProgressBar *pb = static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(ach.GetIndex(),2));
    pb->setMaximum(ach.GetAchievementsCount());
    pb->setMinimumSize(QSize(25,25));
    if(ach.GetAchievementsCount()>0){
        int val=0;
        for (int i=0;i<ach.GetAchievementsCount();i++) {
            if(ach.GetAchieved(i)==1)
                val++;
        }
        pb->setValue(val);
    } else {
        pb->setValue(0);
        static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(ach.GetIndex(),3))->setEnabled(false);
    }
    ui->TableWidgetGames->setItem(ach.GetIndex(),2,new QTableWidgetItem(pb->text().rightJustified(4,'0')));
    achievements[ach.GetIndex()]=ach;
    //ach->deleteLater();
}
#define InitEnd }

#define System {
FormGames::~FormGames(){
    qDebug()<<numrequests<<"запросов на картинки";
    delete [] achievements;
    //for (int i=0;i<=numrequests;i++) {
    //    delete request[numrequests];
    //}
    delete ui;
}
void FormGames::closeEvent(QCloseEvent*){
    emit return_to_profile();
    //delete this;
}
void FormGames::returnfromachievements(int num){
    disconnect(achievementsforms[num],&FormAchievements::return_to_games,this,&FormGames::returnfromachievements);
    //delete achievementsforms[num];
}
#define SystemEnd }

#define Filter {
void FormGames::on_LineEditGame_textChanged(const QString arg){
    if(setting.GetVisibleHiddenGames()==1&&arg!=""){
        for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
                ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,1)->text().toUpper().indexOf(arg.toUpper(),0)>-1?false:true);
        }
    } else {
        for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
                ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,1)->text().toUpper().indexOf(arg.toUpper(),0)>-1?false:true);
                QStringList hides=hide;
                for (int j=0;j<hides.size();j++) {
                    if(hides[j].toInt()==games[i].GetAppid()){
                        ui->TableWidgetGames->setRowHidden(i,true);
                        hides.removeAt(j);
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
    SAchievementsPercentage Percentage(key,QString::number(games[index].GetAppid()));
    connect(&Percentage, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    disconnect(&Percentage, SIGNAL(finished()), &loop, SLOT(quit()));
    if(Percentage.GetAchievementsCount()==0){
        QMessageBox::warning(this,tr("Ошибка"),tr("В этой игре нет достижений"));
    } else {
        FormAchievements *fa = new FormAchievements(key,achievements[index],id,games[index],windowchildcount++);
        achievementsforms.append(fa);
        connect(fa,&FormAchievements::return_to_games,this,&FormGames::returnfromachievements);
        fa->show();
    }
}
void FormGames::FavoritesClicked(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int index=btn->objectName().mid(15).toInt();
    QJsonObject newValue;
    newValue["id"]=QString::number(games[index].GetAppid());
    newValue["name"]=games[index].GetName();
    if(favorites.AddValue(newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
void FormGames::HideClicked(){
    QString Save="";
    QMessageBox messageBox(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите скрыть эту игру?"));
    QAbstractButton *btnProfile = messageBox.addButton(tr("Да, но только для этого аккаунта"),QMessageBox::YesRole);
    QAbstractButton *btnAll = messageBox.addButton(tr("Да, для всех аккаунтов"),QMessageBox::YesRole);
    messageBox.addButton(tr("Отмена"),QMessageBox::NoRole);
    messageBox.exec();
    if(messageBox.clickedButton()==btnProfile){
         Save="Files/Hide/"+id+".txt";
    } else if(messageBox.clickedButton()==btnAll){
         Save="Files/Hide/All.txt";
    } else return;

    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int gamei=btn->objectName().mid(10,6).toInt();
    setting.CreateFile(Save);
    QFile hide(Save);
    hide.open(QIODevice::Append | QIODevice::Text);
    QTextStream writeStream(&hide);
    writeStream <<games[gamei].GetAppid()<<"\n";
    hide.close();
    for (int i=0;i<games.size();i++) {
        if(games[gamei].GetName()==ui->TableWidgetGames->item(i,1)->text()){
            ui->TableWidgetGames->item(i,1)->setTextColor(Qt::red);
            ui->TableWidgetGames->setRowHidden(i,true);
            ui->TableWidgetGames->setCurrentCell(i+1,4);
            break;
        }
    }
    btn->setEnabled(false);
}
#define FunctionsEnd }
