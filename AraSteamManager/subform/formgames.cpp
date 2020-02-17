#include "formgames.h"
#include "ui_formgames.h"

#define Constants {
const int c_tableColumnAppid=0;
const int c_tableColumnIndex=1;
const int c_tableColumnIcon=2;
const int c_tableColumnName=3;
const int c_tableColumnProgress=4;
const int c_tableColumnCount=5;
#define ConstantsEnd }

#define Init {
FormGames::FormGames(QString a_id, SGames a_games, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormGames){
    ui->setupUi(this);
    _id=a_id;
    _games=a_games;
    this->setAttribute(Qt::WA_TranslucentBackground);
    switch(_setting.GetTheme()){
        case 1:
            _theme="white";
            break;
        case 2:
            _theme="black";
            break;
    }
    InitComponents();
}
void FormGames::InitComponents(){
    _games.Sort();
    _favorites.SetPath("Files/Favorites/Games.json","Games");
    ui->TableWidgetGames->setColumnCount(c_tableColumnCount);
    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnIcon,new QTableWidgetItem(""));
    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnName,new QTableWidgetItem(tr("Название игры")));
    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnProgress,new QTableWidgetItem(tr("Прогресс")));
    //ui->TableWidgetGames->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->TableWidgetGames->setSelectionMode(QAbstractItemView::NoSelection);
    //ui->TableWidgetGames->setAlternatingRowColors(true);

    ui->FrameGroup->stackUnder(ui->TableWidgetGames);
    _geometryGroup = QRect(0,0,0,ui->FrameGames->height());
    //ui->TableWidgetGames->installEventFilter(this);
    this->setMouseTracking(true);
    ui->FrameGames->setMouseTracking(true);
    ui->TableWidgetGames->setMouseTracking(true);
    ui->TableWidgetGames->viewport()->setMouseTracking(true);
    ui->FrameGroup->setVisible(false);

    ui->TableWidgetGames->setSortingEnabled(true);
    ui->ProgressBarLoading->setVisible(false);
//    ui->FrameGame->setVisible(false);
    ui->ButtonAchievements->setText(tr("Достижения"));
    ui->ButtonFavorite->setText("");
    ui->ButtonHide->setText("");
    ui->ButtonFind->setIcon(QIcon("://"+_theme+"/find.png"));
    ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
    ui->ButtonHide->setIcon(QIcon("://"+_theme+"/hide.png"));
    ui->ButtonCreateGroup->setIcon(QIcon(":/create.png"));
    ui->ButtonChangeGroup->setIcon(QIcon("://"+_theme+"/change.png"));
    ui->TableWidgetGames->setRowCount(_games.GetCount());
    for (int i=0;i<_games.GetCount();i++) {
        ui->TableWidgetGames->setRowHeight(i,33);
        ui->TableWidgetGames->setCellWidget(i,c_tableColumnProgress, new QProgressBar);
    }
    //загрузить группы
    ui->TableWidgetGames->setColumnWidth(c_tableColumnIcon,33);
    ui->TableWidgetGames->setColumnWidth(c_tableColumnName,300);
    Threading loadTable(this);
    loadTable.AddThreadGames(ui->TableWidgetGames,_games);
}
void FormGames::ProgressLoading(int a_progress,int a_row){
    ui->ProgressBarLoading->setValue(a_progress);
    if(ui->ProgressBarLoading->value()==ui->ProgressBarLoading->maximum()-1){
        //ui->ProgressBarLoading->setVisible(false);
        //ui->TableWidgetGames->setEnabled(true);
    }
}
void FormGames::OnFinish(){
    ui->TableWidgetGames->setColumnHidden(c_tableColumnAppid,true);
    ui->TableWidgetGames->setColumnHidden(c_tableColumnIndex,true);
    ui->TableWidgetGames->resizeColumnsToContents();
    QFile fileHide;
    fileHide.setFileName("Files/Hide/"+_id+".txt");
    if(fileHide.open(QIODevice::ReadOnly)){
        while(!fileHide.atEnd()){
            _hide << QString::fromLocal8Bit(fileHide.readLine()).remove("\r\n").remove("\n");
        }
        fileHide.close();
    }
    fileHide.setFileName("Files/Hide/All.txt");
    if(fileHide.open(QIODevice::ReadOnly)){
        while(!fileHide.atEnd()){
            _hide << QString::fromLocal8Bit(fileHide.readLine()).remove("\r\n").remove("\n").split("%%").at(0);
        }
        fileHide.close();
    }
    QStringList hideList=_hide;
    _achievements = new SAchievementsPlayer[_games.GetCount()];
    for(int i=0;i<_games.GetCount();i++){
        QString path = "images/icon_games/"+_games[i].GetImg_icon_url()+".jpg";
        if(!QFile::exists(path)){
            if(_numRequests<500){
                if(_games[i].GetImg_icon_url()!=""){
                    RequestData *image = new RequestData("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                                                           QString::number(_games[i].GetAppid())+"/"+_games[i].GetImg_icon_url()+".jpg",i,path,true);
                    connect(image,&RequestData::s_finished,this,&FormGames::OnImageLoad);
                    _request.append(image);
                    _numRequests++;
                    }
                _numNow++;
            }
            } else {
            QLabel *iconGame = new QLabel;
            iconGame->setPixmap(QPixmap(path));
            ui->TableWidgetGames->setCellWidget(i,c_tableColumnIcon,iconGame);
            }
        SAchievementsPlayer *achievementsGame = new SAchievementsPlayer(QString::number(_games[i].GetAppid()),_id);
        achievementsGame->SetIndex(i);
        connect(achievementsGame,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
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
    ui->LineEditGame->setFocus();
}
void FormGames::OnImageLoad(RequestData *a_image){
    QPixmap iconGame;
    iconGame.loadFromData(a_image->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(iconGame);
    ui->TableWidgetGames->setCellWidget(a_image->GetRow(),c_tableColumnIcon,label);
    if(_numRequests==500&&_numNow<_games.GetCount()){
        while (QFile::exists("images/icon_games/"+_games[_numNow].GetImg_icon_url()+".jpg")||_games[_numNow].GetImg_icon_url()=="") {
            _numNow++;
        }
        a_image->LoadImage("http://media.steampowered.com/steamcommunity/public/images/apps/"+
                        QString::number(_games[_numNow].GetAppid())+"/"+_games[_numNow].GetImg_icon_url()+".jpg",_numNow,
                        "images/icon_games/"+_games[_numNow].GetImg_icon_url()+".jpg",true);
        _numNow++;
    } else {
        disconnect(a_image,&RequestData::s_finished,this,&FormGames::OnImageLoad);
        a_image->deleteLater();
    }
}
void FormGames::OnResultAchievements(SAchievementsPlayer a_achievements){
    disconnect(&a_achievements,SIGNAL(s_finished(SAchievementsPlayer)),this,SLOT(OnResultAchievements(SAchievementsPlayer)));
    QProgressBar *progressBarAchievements = static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(a_achievements.GetIndex(),c_tableColumnProgress));
    progressBarAchievements->setMaximum(a_achievements.GetCount());
    progressBarAchievements->setMinimumSize(QSize(25,25));
    if(a_achievements.GetCount()>0){
        int val=0;
        for (int i=0;i<a_achievements.GetCount();i++) {
            if(a_achievements[i].GetAchieved()==1)
                val++;
        }
        progressBarAchievements->setValue(val);
    } else {
        progressBarAchievements->setValue(0);
        //static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(a_achievements.GetIndex(),c_tableColumnProgress))->setEnabled(false);
    }
    ui->TableWidgetGames->setItem(a_achievements.GetIndex(),c_tableColumnProgress,new QTableWidgetItem(progressBarAchievements->text().rightJustified(4,'0')));
    _achievements[a_achievements.GetIndex()]=a_achievements;
    emit s_achievementsLoaded(_load++,0);
    if(_load==_games.GetCount()){
        on_TableWidgetGames_cellClicked(0,1);
        emit s_finish();
    }
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
void FormGames::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        ui->retranslateUi(this);
    }
}
void FormGames::closeEvent(QCloseEvent*){
    emit s_return_to_profile(this);
    //delete this;
}
void FormGames::resizeEvent(QResizeEvent *event){
    ui->TableWidgetGames->setGeometry(0,0,ui->FrameGames->width(),ui->FrameGames->height());
    ui->FrameGroup->setGeometry(0,0,ui->FrameGroup->width(),ui->FrameGames->height());
    ui->FrameGroup->raise();
}
void FormGames::showHideSlideWidget(bool a_flag){
    qDebug()<<4<<a_flag;
    if (a_flag)
        ui->FrameGroup->setGeometry(_geometryGroup);
    _animate = new QPropertyAnimation(ui->FrameGroup, "geometry");
    _animate->setDuration(300);

    QRect startRect(0, 0, 0, height());
    QRect endRect(0, 0, 300, height());

    if (a_flag)
    {
        _animate->setStartValue(startRect);
        _animate->setEndValue(endRect);
        _geometryGroup=endRect;
    }
    else
    {
        _animate->setStartValue(endRect);
        _animate->setEndValue(startRect);
        _geometryGroup=startRect;
    }
    _animate->start();
    //connect(_animate,QPropertyAnimations::, ui->FrameGroup->setVisible(!a_flag));
}
void FormGames::mouseMoveEvent(QMouseEvent *ev){
    qDebug()<<ev->pos().x()<<ev->pos().y();
    if (ev->pos().x() < 50)
    {
        qDebug()<<1;
        if (!ui->FrameGroup->isVisible()){
            ui->FrameGroup->show();
            showHideSlideWidget(true);
        }
    }
    else
    {
        qDebug()<<2;
        if (ui->FrameGroup->isVisible())
            showHideSlideWidget(false);
    }
}
void FormGames::slotShowHideSlide(){
    if (ui->FrameGroup->isHidden())
        ui->FrameGroup->show();

    qDebug()<<3<<ui->FrameGroup->isVisible();
    showHideSlideWidget(!ui->FrameGroup->isVisible());
}
#define SystemEnd }

#define Filter {
void FormGames::on_LineEditGame_textChanged(const QString arg){
    if(_setting.GetVisibleHiddenGames()==1&&arg!=""){
        for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
            ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,c_tableColumnName)->text().toLower().indexOf(arg.toLower(),0)==-1);
        }
    } else {
        for (int i=0;i<ui->TableWidgetGames->rowCount();i++) {
            ui->TableWidgetGames->setRowHidden(i,ui->TableWidgetGames->item(i,c_tableColumnName)->text().toLower().indexOf(arg.toLower(),0)==-1);
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
void FormGames::on_TableWidgetGames_cellDoubleClicked(int a_row, int){
    on_ButtonAchievements_clicked();
    //this->findChild<QButtonWithData*>("ButtonAchievements"+ui->TableWidgetGames->item(row,0)->text())->click();
}
void FormGames::on_TableWidgetGames_cellClicked(int a_row, int){
    _selectedGame=ui->TableWidgetGames->item(a_row,c_tableColumnAppid)->text();
    _selectedIndex=ui->TableWidgetGames->item(a_row,c_tableColumnIndex)->text();
    ui->LabelIconGame->setPixmap(*static_cast<QLabel*>(ui->TableWidgetGames->cellWidget(a_row,c_tableColumnIcon))->pixmap());
    ui->LabelTitleGame->setText(ui->TableWidgetGames->item(a_row,c_tableColumnName)->text());
    ui->ProgressBarSelectedGame->setMaximum(static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(a_row,c_tableColumnProgress))->maximum());
    ui->ProgressBarSelectedGame->setValue(static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(a_row,c_tableColumnProgress))->value());
    QJsonArray favorites = _favorites.GetValues();
    bool isFavorite=false;
    for(int i=0;i<favorites.size();i++){
        if(favorites[i].toObject().value("id").toString()==_selectedGame){
            isFavorite=true;
            break;
        }
    }
    if(isFavorite)
        ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/in_favorites.png"));
    else
        ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
    if(ui->TableWidgetGames->item(a_row,c_tableColumnName)->textColor()==Qt::red)
        ui->ButtonHide->setIcon(QIcon("://"+_theme+"/unhide.png"));
    ui->FrameGame->setVisible(true);
}
void FormGames::on_ButtonAchievements_clicked(){
    SAchievementsPercentage Percentage(_selectedGame,false);
    if(Percentage.GetCount()==0){
        QMessageBox::warning(this,tr("Ошибка"),tr("В этой игре нет достижений"));
    } else {
        //ui->TableWidgetGames->setEnabled(false);
        ui->ProgressBarLoading->setMaximum(static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(_selectedIndex.toInt(),c_tableColumnProgress))->maximum());
        //ui->ProgressBarLoading->setVisible(true);
        emit s_showAchievements(_achievements[_selectedIndex.toInt()],_games[_selectedIndex.toInt()]);
    }
}
void FormGames::on_ButtonFavorite_clicked(){
    QJsonObject newValue;
    newValue["id"]=QString::number(_games[_selectedIndex.toInt()].GetAppid());
    newValue["name"]=_games[_selectedIndex.toInt()].GetName();
    newValue["icon"]=_games[_selectedIndex.toInt()].GetImg_icon_url();
    newValue["idUser"]=_id;
    ui->ButtonFavorite->setFixedSize(ui->ButtonFavorite->size());
    if(_favorites.AddValue(newValue,true)){
        //Категория добавилась
        ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/in_favorites.png"));
    } else {
        //Категория уже есть (удалилась)
        ui->ButtonFavorite->setIcon(QIcon("://"+_theme+"/favorites.png"));
    }
}
void FormGames::on_ButtonHide_clicked(){
    QString savePath="";
    QMessageBox question(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите скрыть эту игру?"));
    QAbstractButton *btnProfile = question.addButton(tr("Да, но только для этого аккаунта"),QMessageBox::YesRole);
    QAbstractButton *btnAll = question.addButton(tr("Да, для всех аккаунтов"),QMessageBox::YesRole);
    question.addButton(tr("Отмена"),QMessageBox::NoRole);
    question.exec();
    if(question.clickedButton()==btnProfile){
         savePath="Files/Hide/"+_id+".txt";
    } else if(question.clickedButton()==btnAll){
         savePath="Files/Hide/All.txt";
    } else return;

    _setting.CreateFile(savePath);
    QFile fileHide(savePath);
    fileHide.open(QIODevice::Append | QIODevice::Text);
    QTextStream writeStream(&fileHide);
    writeStream <<_games[_selectedIndex.toInt()].GetAppid()<<(savePath=="Files/Hide/All.txt"?"%%"
                                                            +_games[_selectedIndex.toInt()].GetImg_icon_url()+"%%"
                                                            +_games[_selectedIndex.toInt()].GetName():"")<<"\n";
    fileHide.close();
    for (int i=0;i<_games.GetCount();i++) {
        if(_games[_selectedIndex.toInt()].GetName()==ui->TableWidgetGames->item(i,c_tableColumnName)->text()){
            ui->TableWidgetGames->item(i,c_tableColumnName)->setTextColor(Qt::red);
            ui->TableWidgetGames->setRowHidden(i,true);
            break;
        }
    }
    ui->ButtonHide->setFixedSize(ui->ButtonHide->size());
    ui->ButtonHide->setIcon(QIcon("://"+_theme+"/unhide.png"));
}
#define FunctionsEnd }
