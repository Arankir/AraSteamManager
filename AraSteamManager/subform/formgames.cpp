#include "formgames.h"
#include "ui_formgames.h"
#define Constants {
const int c_tableColumnAppid=0;
const int c_tableColumnIndex=1;
const int c_tableColumnIcon=2;
const int c_tableColumnName=3;
const int c_tableColumnProgress=4;
//const int c_tableColumnAchievement=5;
//const int c_tableColumnFavorite=6;
//const int c_tableColumnHide=7;
const int c_tableColumnCount=5;
#define ConstantsEnd }

FormGames::FormGames(QString Aid, SGames Agames, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormGames){
    ui->setupUi(this);
    _id=Aid;
    SGames game=Agames;
    std::list<SGame> list;
    for (int i=0;i<game.GetCount();list.push_back(game.GetGame(i++)));
    list.sort();
    _games=QVector<SGame>::fromList(QList<SGame>::fromStdList(list));
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    InitComponents();
    ui->LineEditGame->setFocus();
}

#define Init {
void FormGames::InitComponents(){
//    for (int i=0; i < _games.size()-1; i++) {
//        for (int j=0; j < _games.size()-i-1; j++) {
//            if (_games[j].GetName() > _games[j+1].GetName()) {
//                SGame temp = _games[j];
//                _games[j] = _games[j+1];
//                _games[j+1] = temp;
//            }
//        }
//    }
    _favorites.SetPath("Files/Favorites/Games.json","Games");
    ui->TableWidgetGames->setColumnCount(c_tableColumnCount);
    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnIcon,new QTableWidgetItem(""));
    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnName,new QTableWidgetItem(tr("Название игры")));
    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnProgress,new QTableWidgetItem(tr("Прогресс")));
//    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnAchievement,new QTableWidgetItem(tr("Достижения")));
//    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnFavorite,new QTableWidgetItem(tr("Избранное")));
//    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnHide,new QTableWidgetItem(tr("Скрыть")));
    ui->TableWidgetGames->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetGames->setAlternatingRowColors(true);
    ui->TableWidgetGames->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetGames->setSortingEnabled(true);
    ui->ProgressBarLoading->setVisible(false);
    ui->GroupBoxGame->setVisible(false);
    ui->ButtonFind->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/find.png"));
    ui->ButtonAchievements->setText(tr("Достижения"));
    ui->ButtonFavorite->setText("");
    ui->ButtonHide->setText("");
    ui->ButtonFavorite->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/favorites.png"));
    ui->ButtonHide->setIcon(QIcon(":/"+_theme+"/program/"+_theme+"/hide.png"));
    //iAchievement = ;
//    QIcon iFavorite = QIcon(":/"+_theme+"/program/"+_theme+"/favorites.png");
//    QIcon iHide = QIcon(":/"+_theme+"/program/"+_theme+"/hide.png");
    ui->TableWidgetGames->setRowCount(_games.count());
    for (int i=0;i<_games.count();i++) {
        ui->TableWidgetGames->setRowHeight(i,33);
//        QButtonWithData *button1 = new QButtonWithData(tr("Достижения"));
//        button1->setMinimumSize(QSize(25,25));
//        button1->setObjectName("ButtonAchievements"+QString::number(_games[i].GetAppid()));
//        button1->AddData("NumberGame",QString::number(i));
//        connect(button1,&QButtonWithData::pressed,this,&FormGames::AchievementsClicked);
//        ui->TableWidgetGames->setCellWidget(i,c_tableColumnAchievement,button1);

//        QButtonWithData *button2 = new QButtonWithData("");
//        //проверка всего на избранное
//        button2->setIcon(iFavorite);
//        button2->setMinimumSize(QSize(25,25));
//        connect(button2,&QButtonWithData::pressed,this,&FormGames::FavoritesClicked);
//        button2->setObjectName("ButtonFavorites"+QString::number(i));
//        button2->AddData("NumberGame",QString::number(i));
//        ui->TableWidgetGames->setCellWidget(i,c_tableColumnFavorite,button2);

//        QButtonWithData *button3 = new QButtonWithData("");
//        button3->setIcon(iHide);
//        button3->setMinimumSize(QSize(25,25));
//        connect(button3,&QButtonWithData::pressed,this,&FormGames::HideClicked);
//        button3->setObjectName("ButtonHide"+QString::number(i));
//        button3->AddData("NumberGame",QString::number(i));
//        ui->TableWidgetGames->setCellWidget(i,c_tableColumnHide,button3);

        QProgressBar *pb = new QProgressBar;
        ui->TableWidgetGames->setCellWidget(i,c_tableColumnProgress,pb);
//        emit s_achievementsLoaded(i,0);
    }
    ui->TableWidgetGames->setColumnWidth(c_tableColumnIcon,33);
    ui->TableWidgetGames->setColumnWidth(c_tableColumnName,300);
    Threading LoadTable(this);
    LoadTable.AddThreadGames(ui->TableWidgetGames,_games);
}
void FormGames::ProgressLoading(int Aprogress,int Arow){

}
void FormGames::OnFinish(){
    ui->TableWidgetGames->setColumnHidden(c_tableColumnAppid,true);
    ui->TableWidgetGames->setColumnHidden(c_tableColumnIndex,true);
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
            _hide << QString::fromLocal8Bit(fileHide2.readLine()).remove("\r\n").remove("\n").split("%%").at(0);
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
            ui->TableWidgetGames->setCellWidget(i,c_tableColumnIcon,label);
            }
        SAchievementsPlayer *pl = new SAchievementsPlayer(QString::number(_games[i].GetAppid()),_id);
        pl->SetIndex(i);
        connect(pl,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
        for (int j=0;j<hideList.size();j++) {
            if(hideList[j].toInt()==_games[i].GetAppid()){
                ui->TableWidgetGames->setRowHidden(i,true);
                ui->TableWidgetGames->item(i,c_tableColumnName)->setTextColor(Qt::red);
                //static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(i,c_tableColumnHide))->setEnabled(false);
                hideList.removeAt(j);
                break;
            }
            }
        }
}
void FormGames::OnResultImage(ImageRequest *Aimage){
    QPixmap pixmap;
    pixmap.loadFromData(Aimage->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetGames->setCellWidget(Aimage->GetRow(),c_tableColumnIcon,label);
    if(_numRequests==500&&_numNow<_games.size()){
        while (QFile::exists("images/icon_games/"+_games[_numNow].GetImg_icon_url()+".jpg")||_games[_numNow].GetImg_icon_url()=="") {
            _numNow++;
        }
        Aimage->LoadImage("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                        QString::number(_games[_numNow].GetAppid())+"/"+_games[_numNow].GetImg_icon_url()+".jpg",_numNow,
                        "images/icon_games/"+_games[_numNow].GetImg_icon_url()+".jpg",true);
        _numNow++;
    } else {
        disconnect(Aimage,&ImageRequest::s_finished,this,&FormGames::OnResultImage);
        Aimage->deleteLater();
    }
}
void FormGames::OnResultAchievements(SAchievementsPlayer Aachievements){
    disconnect(&Aachievements,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
    QProgressBar *pb = static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(Aachievements.GetIndex(),c_tableColumnProgress));
    pb->setMaximum(Aachievements.GetCount());
    pb->setMinimumSize(QSize(25,25));
    if(Aachievements.GetCount()>0){
        int val=0;
        for (int i=0;i<Aachievements.GetCount();i++) {
            if(Aachievements.GetAchieved(i)==1)
                val++;
        }
        pb->setValue(val);
    } else {
        pb->setValue(0);
        //static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(Aachievements.GetIndex(),c_tableColumnAchievement))->setEnabled(false);
    }
    ui->TableWidgetGames->setItem(Aachievements.GetIndex(),c_tableColumnProgress,new QTableWidgetItem(pb->text().rightJustified(4,'0')));
    _achievements[Aachievements.GetIndex()]=Aachievements;
    emit s_achievementsLoaded(_load++,0);
    if(_load==_games.size())
        emit s_finish();
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
    emit s_return_to_profile(this);
    //delete this;
}
void FormGames::ReturnFromAchievements(int Anum){
    disconnect(_achievementsForms[Anum],&FormAchievements::s_return_to_games,this,&FormGames::ReturnFromAchievements);
    //delete achievementsforms[num];
}
void FormGames::AddAchievements(int index){
    if(_achievementsCount==0){
        _containerAchievementsForm = new FormContainerAchievements();
        connect(_containerAchievementsForm,&FormContainerAchievements::s_removeAchievements,this,&FormGames::RemoveAchievements);
        connect(_containerAchievementsForm,&FormContainerAchievements::s_formClose,this,&FormGames::ContainerAchievementsClose);
        _windowChildCount++;
    }
    _containerAchievementsForm->AddFormAchievement(_achievements[index],_id,_games[index],_achievementsCount++);
    _containerAchievementsForm->show();
}
void FormGames::RemoveAchievements(int){
    _achievementsCount--;
}
void FormGames::ContainerAchievementsClose(){
    _achievementsCount=0;
    disconnect(_containerAchievementsForm,&FormContainerAchievements::s_removeAchievements,this,&FormGames::RemoveAchievements);
    disconnect(_containerAchievementsForm,&FormContainerAchievements::s_formClose,this,&FormGames::ContainerAchievementsClose);
}
#define SystemEnd }

#define Filter {
void FormGames::on_LineEditGame_textChanged(const QString arg){
    if(_setting.GetVisibleHiddenGames()==1&&arg!=""){
        for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
                ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,c_tableColumnName)->text().toUpper().indexOf(arg.toUpper(),0)==-1);
        }
    } else {
        for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
                ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,c_tableColumnName)->text().toUpper().indexOf(arg.toUpper(),0)==-1);
                QStringList hideList=_hide;
                for (int j=0;j<hideList.size();j++) {
                    if(hideList[j]==ui->TableWidgetGames->item(i,c_tableColumnAppid)->text()){
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
void FormGames::on_TableWidgetGames_cellDoubleClicked(int row, int){
    on_ButtonAchievements_clicked();
    //this->findChild<QButtonWithData*>("ButtonAchievements"+ui->TableWidgetGames->item(row,0)->text())->click();
}
/*void FormGames::AchievementsClicked(){
    QButtonWithData *btn = static_cast<QButtonWithData*>(sender());
    int index=btn->GetData(0).toInt();
    QEventLoop loop;
    SAchievementsPercentage Percentage(QString::number(_games[index].GetAppid()));
    connect(&Percentage, SIGNAL(s_finished()), &loop, SLOT(quit()));
    loop.exec();
    disconnect(&Percentage, SIGNAL(s_finished()), &loop, SLOT(quit()));
    if(Percentage.GetCount()==0){
        QMessageBox::warning(this,tr("Ошибка"),tr("В этой игре нет достижений"));
    } else {
        AddAchievements(index);
    }
}
void FormGames::FavoritesClicked(){
    QButtonWithData *btn = static_cast<QButtonWithData*>(sender());
    int index=btn->GetData(0).toInt();
    QJsonObject newValue;
    newValue["id"]=QString::number(_games[index].GetAppid());
    newValue["name"]=_games[index].GetName();
    newValue["icon"]=_games[index].GetImg_icon_url();
    newValue["idUser"]=_id;
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

    QButtonWithData *btn = static_cast<QButtonWithData*>(sender());
    int gamei=btn->GetData(0).toInt();
    _setting.CreateFile(save);
    QFile hide(save);
    hide.open(QIODevice::Append | QIODevice::Text);
    QTextStream writeStream(&hide);
    writeStream <<_games[gamei].GetAppid()<<(save=="Files/Hide/All.txt"?"%%"+_games[gamei].GetImg_icon_url()+"%%"+_games[gamei].GetName():"")<<"\n";
    hide.close();
    for (int i=0;i<_games.size();i++) {
        if(_games[gamei].GetName()==ui->TableWidgetGames->item(i,c_tableColumnName)->text()){
            ui->TableWidgetGames->item(i,c_tableColumnName)->setTextColor(Qt::red);
            ui->TableWidgetGames->setRowHidden(i,true);
            //ui->TableWidgetGames->setCurrentCell(i+1,c_tableColumnAchievement);
            break;
        }
    }
    btn->setEnabled(false);
}*/

void FormGames::on_TableWidgetGames_cellClicked(int row, int){
    _selectedGame=ui->TableWidgetGames->item(row,c_tableColumnAppid)->text();
    _selectedIndex=ui->TableWidgetGames->item(row,c_tableColumnIndex)->text();
    ui->LabelIconGame->setPixmap(*static_cast<QLabel*>(ui->TableWidgetGames->cellWidget(row,c_tableColumnIcon))->pixmap());
    ui->LabelTitleGame->setText(ui->TableWidgetGames->item(row,c_tableColumnName)->text());
    ui->ProgressBarSelectedGame->setMaximum(static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(row,c_tableColumnProgress))->maximum());
    ui->ProgressBarSelectedGame->setValue(static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(row,c_tableColumnProgress))->value());
    ui->GroupBoxGame->setVisible(true);
}
void FormGames::on_ButtonAchievements_clicked(){
    QEventLoop loop;
    SAchievementsPercentage Percentage(_selectedGame);
    connect(&Percentage, SIGNAL(s_finished()), &loop, SLOT(quit()));
    loop.exec();
    disconnect(&Percentage, SIGNAL(s_finished()), &loop, SLOT(quit()));
    if(Percentage.GetCount()==0){
        QMessageBox::warning(this,tr("Ошибка"),tr("В этой игре нет достижений"));
    } else {
        AddAchievements(_selectedIndex.toInt());
    }
}
void FormGames::on_ButtonFavorite_clicked(){
    QJsonObject newValue;
    newValue["id"]=QString::number(_games[_selectedIndex.toInt()].GetAppid());
    newValue["name"]=_games[_selectedIndex.toInt()].GetName();
    newValue["icon"]=_games[_selectedIndex.toInt()].GetImg_icon_url();
    newValue["idUser"]=_id;
    if(_favorites.AddValue(newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
void FormGames::on_ButtonHide_clicked(){
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

    _setting.CreateFile(save);
    QFile hide(save);
    hide.open(QIODevice::Append | QIODevice::Text);
    QTextStream writeStream(&hide);
    writeStream <<_games[_selectedIndex.toInt()].GetAppid()<<(save=="Files/Hide/All.txt"?"%%"
                                                            +_games[_selectedIndex.toInt()].GetImg_icon_url()+"%%"
                                                            +_games[_selectedIndex.toInt()].GetName():"")<<"\n";
    hide.close();
    for (int i=0;i<_games.size();i++) {
        if(_games[_selectedIndex.toInt()].GetName()==ui->TableWidgetGames->item(i,c_tableColumnName)->text()){
            ui->TableWidgetGames->item(i,c_tableColumnName)->setTextColor(Qt::red);
            ui->TableWidgetGames->setRowHidden(i,true);
            //ui->TableWidgetGames->setCurrentCell(i+1,c_tableColumnAchievement);
            break;
        }
    }
}
#define FunctionsEnd }

