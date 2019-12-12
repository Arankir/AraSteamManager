#include "formachievements.h"
#include "ui_formachievements.h"

FormAchievements::FormAchievements(QString keys, SAchievementsPlayer pl, QString ids, SGame games, int num, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormAchievements){
    ui->setupUi(this);
    key=keys;
    id=ids;
    game=games;
    unicnum=num;
    achievements.Set(pl);
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
    ui->LineEditNameAchievements->setFocus();
}

#define Init {
void FormAchievements::InitComponents(){
    favorites.SetPath("Files/Favorites/Achievements.json","Achievements");
    ui->TableWidgetAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetCompareAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetCompareFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetAchievements->setAlternatingRowColors(true);
    ui->TableWidgetAchievements->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetCompareAchievements->setAlternatingRowColors(true);
    ui->TableWidgetCompareAchievements->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetCompareFriends->setAlternatingRowColors(true);
    ui->TableWidgetCompareFriends->setSelectionMode(QAbstractItemView::NoSelection);
    ui->TableWidgetCompareFriends->setMinimumSize(0,180);
    categoriesGame.Set(game);
    ui->ButtonCompare->setIcon(QIcon(":/"+theme+"/program/"+theme+"/compare.png"));
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {background-image:url(images/program/filter_white.png)}");
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(images/program/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(:/"+theme+"/program/"+theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->ButtonAddCategory->setIcon(QIcon(":/program/program/create.png"));
    ui->ButtonChangeCategory->setIcon(QIcon(":/"+theme+"/program/"+theme+"/change.png"));
    ui->ButtonDeleteCategory->setIcon(QIcon(":/program/program/delete.png"));
    ui->ButtonFindAchievement->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->ButtonAddValueCategory->setIcon(QIcon(":/program/program/create.png"));
    ui->ButtonAcceptCategory->setIcon(QIcon(":/program/program/apply.png"));
    ui->ButtonCancelCategory->setIcon(QIcon(":/program/program/cancel.png"));
    ui->RadioButtonAll->setIcon(QIcon(":/"+theme+"/program/"+theme+"/all.png"));
    ui->RadioButtonReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/reached.png"));
    ui->RadioButtonNotReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/notreached.png"));
    ui->ButtonUpdate->setIcon(QIcon(":/"+theme+"/program/"+theme+"/update.png"));
    ui->TableWidgetAchievements->setColumnCount(7);
    ui->TableWidgetCompareAchievements->setColumnCount(7);
    ui->TableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Название")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("Описание")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem(tr("По миру")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem(tr("Получено")));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(6,new QTableWidgetItem(tr("Избранное")));
    ui->LabelGameOnline->setText(tr("Сейчас в игре :%1").arg(game.GetNumberPlayers(key,false)));
    ui->LabelGameTitle->setText(game.GetName());
    if(!QDir("images/achievements/"+QString::number(game.GetAppid())).exists())
        QDir().mkdir("images/achievements/"+QString::number(game.GetAppid()));

    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &logoreply = *manager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(game.GetAppid())+"/"+game.GetImg_logo_url()+".jpg"));
    loop.exec();
    QPixmap pixmap;
    pixmap.loadFromData(logoreply.readAll());
    ui->LabelGameLogo->setPixmap(pixmap);
    SProfile Profile(key,id,false,"url");
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem(Profile.GetPersonaname()));
    QNetworkReply &imagereply = *manager.get(QNetworkRequest(Profile.GetAvatar()));
    loop.exec();
    QPixmap pix;
    pix.loadFromData(imagereply.readAll());
    disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QLabel *myava = new QLabel;
    myava->setPixmap(pix);
    myava->setAlignment(Qt::AlignCenter);
    ui->TableWidgetCompareAchievements->setCellWidget(0,5,myava);
    ui->TableWidgetCompareAchievements->setRowHeight(0,33);
    ui->TableWidgetCompareFriends->setRowCount(4);
    ui->TableWidgetCompareFriends->setColumnCount(2);
    ui->TableWidgetCompareFriends->setRowHidden(3,true);
    QLabel *myava2 = new QLabel;
    myava2->setPixmap(pix);
    myava2->setAlignment(Qt::AlignCenter);
    myava2->setToolTip(Profile.GetPersonaname());
    ui->TableWidgetCompareFriends->setCellWidget(0,0,myava2);
    QLabel *All = new QLabel("All");
    All->setToolTip(tr("Достижения друзей"));
    All->setPixmap(QPixmap(":/"+theme+"/program/"+theme+"/friends.png"));
    All->setScaledContents(true);
    All->setFixedSize(32,32);
    ui->TableWidgetCompareFriends->setCellWidget(0,1,All);
    QRadioButton *rbMyAll = new QRadioButton();
    QRadioButton *rbMyReached = new QRadioButton();
    QRadioButton *rbMyNotReached = new QRadioButton();
    rbMyAll->setObjectName("RBMyAll");
    rbMyReached->setObjectName("RBMyReached");
    rbMyNotReached->setObjectName("RBMyNotReached");
    connect(rbMyAll,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonAll_clicked);
    connect(rbMyReached,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonReached_clicked);
    connect(rbMyNotReached,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonNotReached_clicked);
    rbMyAll->setChecked(true);
    QWidget *wd1 = new QWidget;
    QVBoxLayout *lay1 = new QVBoxLayout;
    wd1->setObjectName("WDMy");
    lay1->setObjectName("LayMy");
    lay1->addWidget(rbMyAll);
    lay1->addWidget(rbMyReached);
    lay1->addWidget(rbMyNotReached);
    lay1->setMargin(1);
    lay1->setAlignment(Qt::AlignCenter);
    wd1->setLayout(lay1);
    rbMyAll->setIcon(QIcon(":/"+theme+"/program/"+theme+"/all.png"));
    rbMyReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/reached.png"));
    rbMyNotReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/notreached.png"));
    QWidget *wd2 = new QWidget;
    QVBoxLayout *lay2 = new QVBoxLayout;
    wd2->setObjectName("WDFriends");
    lay2->setObjectName("LayFriends");
    QPushButton *pbFriendsAll = new QPushButton();
    QPushButton *pbFriendsReached = new QPushButton();
    QPushButton *pbFriendsNotReached = new QPushButton();
    pbFriendsAll->setObjectName("PBFriendsAll");
    pbFriendsReached->setObjectName("PBFriendsReached");
    pbFriendsNotReached->setObjectName("PBFriendsNotReached");
    connect(pbFriendsAll,&QPushButton::clicked,this,&FormAchievements::on_RadioButtonCompareFriendsAll_clicked);
    connect(pbFriendsReached,&QPushButton::clicked,this,&FormAchievements::on_RadioButtonCompareFriendsReached_clicked);
    connect(pbFriendsNotReached,&QPushButton::clicked,this,&FormAchievements::on_RadioButtonCompareFriendsNotReached_clicked);
    pbFriendsAll->setChecked(true);
    lay2->addWidget(pbFriendsAll);
    lay2->addWidget(pbFriendsReached);
    lay2->addWidget(pbFriendsNotReached);
    lay2->setMargin(1);
    wd2->setLayout(lay2);
    pbFriendsAll->setIcon(QIcon(":/"+theme+"/program/"+theme+"/all.png"));
    pbFriendsReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/reached.png"));
    pbFriendsNotReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/notreached.png"));
    ui->TableWidgetCompareFriends->setCellWidget(2,0,wd1);
    ui->TableWidgetCompareFriends->setCellWidget(2,1,wd2);
    ui->TableWidgetCompareFriends->resizeRowsToContents();
    ui->TableWidgetCompareFriends->resizeColumnsToContents();

    ui->GroupBoxCategories->setVisible(false);
    SwitchSimpleCompare(1);
    ui->ProgressBarFriendsLoad->setVisible(false);
    ui->TableWidgetCompareAchievements->setColumnCount(6);
    ui->TableWidgetCompareAchievements->setVerticalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetCompareAchievements->setVerticalHeaderItem(1,new QTableWidgetItem("%"));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Название")));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("Описание")));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem(tr("По миру")));

    QWidget *widget3 = new QWidget;
    categoryvalueslayout = new QFormLayout;
    categoryvalueslayout->setSpacing(0);
    categoryvalueslayout->setContentsMargins(1,1,1,1);
    widget3->setLayout(categoryvalueslayout);
    ui->ScrollAreaValuesCategory->setWidget(widget3);

    ui->TableWidgetAchievements->setColumnHidden(0,true);
    ui->TableWidgetAchievements->setColumnWidth(1,65);
    ui->TableWidgetAchievements->setColumnWidth(2,100);
    ui->TableWidgetAchievements->setColumnWidth(3,315);
    ui->TableWidgetAchievements->setColumnWidth(5,80);
    ui->TableWidgetAchievements->setColumnWidth(6,50);
    ui->TableWidgetCompareAchievements->setColumnHidden(0,true);
    ui->TableWidgetCompareAchievements->setColumnWidth(1,65);
    ui->TableWidgetCompareAchievements->setColumnWidth(2,100);
    ui->TableWidgetCompareAchievements->setColumnWidth(3,315);
    ui->TableWidgetCompareAchievements->resizeColumnToContents(4);
    ui->TableWidgetCompareAchievements->setColumnWidth(5,80);
    fAchievements.SetRow(ui->TableWidgetAchievements->rowCount());
    fCompare.SetRow(ui->TableWidgetCompareAchievements->rowCount());
    ShowCategories();
    ui->GroupBoxFilter->setEnabled(false);
    connect(&achievements,SIGNAL(finished()),this,SLOT(PullTableWidget()));
    achievements.DoSet(key,QString::number(game.GetAppid()),id);
    qDebug()<<"FinishStatus="<<achievements.GetStatusFinish();
}
void FormAchievements::PullTableWidget(){
    ui->TableWidgetAchievements->setRowCount(achievements.GetAchievementsCount());
    for(int i=0;i<achievements.GetAchievementsCount();i++)
        ui->TableWidgetAchievements->setRowHeight(i,65);
    ui->TableWidgetCompareAchievements->setRowCount(achievements.GetAchievementsCount()+2);
    if(!(achievements.GetStatusFinish()=="success")){
        ui->TableWidgetAchievements->insertRow(0);
        ui->TableWidgetAchievements->setItem(0,1,new QTableWidgetItem("Error"));
        ui->TableWidgetAchievements->setColumnHidden(2,true);
        ui->TableWidgetAchievements->setColumnHidden(3,true);
        ui->TableWidgetAchievements->setColumnHidden(4,true);
        ui->TableWidgetAchievements->setColumnHidden(5,true);
        ui->TableWidgetAchievements->setColumnHidden(6,true);
        ui->GroupBoxFilter->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
    } else{
        Threading LoadTable(this);
        QLabel *lbl = new QLabel;
        ui->TableWidgetCompareAchievements->setCellWidget(1,5, lbl);
        LoadTable.AddThreadAchievements(achievements,ui->LabelTotalPersent,ui->TableWidgetAchievements,lbl,ui->TableWidgetCompareAchievements);
    }
}
void FormAchievements::ProgressLoading(int p,int row){
    qDebug()<<"Loading..."<<p;
    QPushButton *button1 = new QPushButton;
    button1->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
    connect(button1,&QPushButton::pressed,this,&FormAchievements::FavoritesClicked);
    button1->setObjectName("ButtonFavorites&"+QString::number(row));
    ui->TableWidgetAchievements->setCellWidget(row,6,button1);
}
void FormAchievements::OnFinish(){
    ui->GroupBoxFilter->setEnabled(true);
    ui->TableWidgetAchievements->resizeColumnToContents(4);
    ui->TableWidgetAchievements->resizeRowsToContents();
    int j=0;
    ui->TableWidgetCompareAchievements->resizeRowsToContents();
    for (int i=0;i<achievements.GetAchievementsCount();i++) {
        if(achievements.GetDisplayname(i)!=""){
            QString achievementIcon=achievements.GetIcon(i).mid(66,achievements.GetIcon(i).length());
            QString path="images/achievements/"+QString::number(game.GetAppid())+"/"+achievementIcon.mid(achievementIcon.indexOf("/",1)+1,achievementIcon.length()-1);
            if(!QFile::exists(path)){
                ImageRequest *image = new ImageRequest(achievements.GetIcon(i),j,path,true);
                connect(image,&ImageRequest::onReady,this,&FormAchievements::OnResultImage);
            } else {
                QPixmap pixmap;
                pixmap.load(path);
                QLabel *label = new QLabel;
                label->setPixmap(pixmap);
                ui->TableWidgetAchievements->setCellWidget(j,1,label);
                ui->TableWidgetAchievements->resizeRowToContents(j);
                QLabel *label2 = new QLabel;
                label2->setPixmap(pixmap);
                ui->TableWidgetCompareAchievements->setCellWidget(j+2,1,label2);
                ui->TableWidgetCompareAchievements->resizeRowToContents(j);
            }
            j++;
        } else {
            ui->TableWidgetAchievements->removeRow(ui->TableWidgetAchievements->rowCount()-1);
            ui->TableWidgetCompareAchievements->removeRow(ui->TableWidgetCompareAchievements->rowCount()-1);
        }

        }
}
void FormAchievements::OnResultImage(ImageRequest *imgr){
    disconnect(imgr,&ImageRequest::onReady,this,&FormAchievements::OnResultImage);
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    QLabel *label2 = new QLabel;
    label2->setPixmap(pixmap);
    ui->TableWidgetAchievements->setCellWidget(imgr->GetRow(),1,label);
    ui->TableWidgetCompareAchievements->setCellWidget(imgr->GetRow()+2,1,label2);
    ui->TableWidgetAchievements->resizeRowToContents(imgr->GetRow());
    ui->TableWidgetCompareAchievements->resizeRowToContents(imgr->GetRow()+2);
    imgr->deleteLater();
}
#define InitEnd }

#define SimpleCompare {
void FormAchievements::SwitchSimpleCompare(int sc){
    switch (sc) {
    case 1:{
        ui->CheckBoxCompareAllFriends->setVisible(false);
        ui->TableWidgetCompareFriends->setVisible(false);
        ui->ButtonAddCategory->setEnabled(true);
        categoriesGame.Set(game);
        QList<QString> list = categoriesGame.GetTitles();
        ui->ButtonChangeCategory->setEnabled(list.size()!=0);
        ui->TableWidgetCompareFriends->setVisible(false);
        ui->TableWidgetCompareAchievements->setVisible(false);
        ui->ButtonCompare->setText(tr("Сравнить с друзьями"));
        ui->RadioButtonAll->setVisible(true);
        ui->RadioButtonReached->setVisible(true);
        ui->RadioButtonNotReached->setVisible(true);
        ui->TableWidgetAchievements->setVisible(true);
        simpleCompare=2;
        break;
    }
    case 2:{
        ui->RadioButtonAll->setVisible(false);
        ui->RadioButtonReached->setVisible(false);
        ui->RadioButtonNotReached->setVisible(false);
        ui->TableWidgetAchievements->setVisible(false);
        ui->ButtonCompare->setText(tr("Обратно"));
        ui->CheckBoxCompareAllFriends->setVisible(true);
        ui->TableWidgetCompareFriends->setVisible(true);
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->TableWidgetCompareFriends->setVisible(true);
        ui->TableWidgetCompareAchievements->setVisible(true);
        if(!loadCompare){
            qDebug()<<"LoadCompare";
            LoadingCompare();
        }
        simpleCompare=1;
        break;
    }
    }
}
void FormAchievements::LoadingCompare(){
    loadCompare++;
    SProfile Profile(key,id,false,"url");
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem(Profile.GetPersonaname()));

    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &imagereply = *manager.get(QNetworkRequest(Profile.GetAvatar()));
    loop.exec();
    QPixmap pix;
    pix.loadFromData(imagereply.readAll());
    QLabel *myava1 = new QLabel;
    myava1->setPixmap(pix);
    myava1->setAlignment(Qt::AlignCenter);
    ui->TableWidgetCompareAchievements->setCellWidget(0,5,myava1);
    ui->TableWidgetCompareAchievements->resizeRowToContents(0);
    QLabel *myava2 = new QLabel;
    myava2->setPixmap(pix);
    myava2->setAlignment(Qt::AlignCenter);
    myava2->setToolTip(Profile.GetPersonaname());
    ui->TableWidgetCompareFriends->setCellWidget(0,0,myava2);


    SFriends frien(key,id,false);
    SProfile profiless = frien.GetProfiles();
    friendsCount=profiless.GetCount();
    ui->TableWidgetCompareFriends->setColumnCount(friendsCount+2);
    for (int i=0;i<friendsCount;i++) {
        ui->TableWidgetCompareFriends->setColumnWidth(i+2,33);
        profiles.push_back(profiless.GetProfile(i));
    }//Сортировка по именам
    for (int i=0; i < friendsCount-1; i++) {
        for (int j=0; j < profiles.size()-i-1; j++) {
            if (profiles[j].GetPersonaname() > profiles[j+1].GetPersonaname()) {
                SProfile temp = profiles[j];
                profiles[j] = profiles[j+1];
                profiles[j+1] = temp;
            }
        }
    }
    ui->ProgressBarFriendsLoad->setMaximum(profiles.size());
    ui->ProgressBarFriendsLoad->setValue(0);
    ui->ProgressBarFriendsLoad->setVisible(true);

    for (int i=0;i<friendsCount;i++) {
        SGames *Games = new SGames;
        Games->SetIndex(i);
        Games->Set(key,profiles[i].GetSteamid(),true,true,true);
        connect(Games,SIGNAL(finished(SGames*)),this,SLOT(LoadFriend(SGames*)));
    }

}
void FormAchievements::LoadFriend(SGames *Games){
    disconnect(Games,SIGNAL(finished(SGames*)),this,SLOT(LoadFriend(SGames*)));
    bool apply=false;
    for (int i=0;i<Games->GetCount();i++) {//Проверка на наличие игры
        if(Games->GetAppid(i)==game.GetAppid()){
            apply=true;
            break;
        }
    }
    QPair<SProfile,int> deb;
    deb.first=profiles[Games->GetIndex()];
    if(apply){
        deb.second=1;
        type1++;
    } else {
        deb.second=2;
        type2++;
    }
    friends.push_back(deb);
    ui->ProgressBarFriendsLoad->setValue(ui->ProgressBarFriendsLoad->value()+1);
    if(ui->ProgressBarFriendsLoad->value()==friendsCount)
        FinishLoadFriends();

}
void FormAchievements::FinishLoadFriends(){
    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    ui->ProgressBarFriendsLoad->setVisible(false);

    for(int i=0;i<friends.size();i++) {
        QNetworkReply &imagereply = *manager.get(QNetworkRequest(friends[i].first.GetAvatar()));
        loop.exec();
        QPixmap pix;
        pix.loadFromData(imagereply.readAll());
        QLabel *ava = new QLabel;
        ava->setPixmap(pix);
        ava->setToolTip(friends[i].first.GetPersonaname());
        ava->setAlignment(Qt::AlignCenter);
        ui->TableWidgetCompareFriends->setCellWidget(0,i+2,ava);
        QTableWidgetItem *pItem(new QTableWidgetItem(tr("")));
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetCompareFriends->setItem(1,i+2,pItem);
        ui->TableWidgetCompareFriends->setItem(3,i+2,new QTableWidgetItem(friends[i].first.GetSteamid()));
        ui->TableWidgetCompareFriends->setColumnHidden(i+2,friends[i].second==2);
    }
    disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    connect(ui->TableWidgetCompareFriends,&QTableWidget::cellChanged,this,&FormAchievements::on_TableWidgetCompareFriendsCellChanged);
    ui->TableWidgetCompareFriends->resizeColumnsToContents();
}
void FormAchievements::on_RadioButtonAll_clicked(){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        fAchievements.SetData(i,1,true);
        fCompare.SetData(i+2,1,true);
    }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonReached_clicked(){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        fAchievements.SetData(i,1,ui->TableWidgetAchievements->item(i,5)->text().indexOf(".")>-1);
        fCompare.SetData(i+2,1,ui->TableWidgetCompareAchievements->item(i+2,5)->text().indexOf(".")>-1);
        }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonNotReached_clicked(){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        fAchievements.SetData(i,1,ui->TableWidgetAchievements->item(i,5)->text().indexOf(".")==-1);
        fCompare.SetData(i+2,1,ui->TableWidgetCompareAchievements->item(i+2,5)->text().indexOf(".")==-1);
        }
    UpdateHiddenRows();
}

void FormAchievements::on_RadioButtonCompareFriendsAll_clicked(){
    for(int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"All";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormAchievements::on_RadioButtonCompareFriendsReached_clicked(){
    for(int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"Reached";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormAchievements::on_RadioButtonCompareFriendsNotReached_clicked(){
    for(int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"NotReached";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormAchievements::on_RadioButtonFriendAll_Click(){
    QRadioButton *rb = qobject_cast<QRadioButton*>(sender());
    int col=(rb->objectName().mid(2,rb->objectName().indexOf("All")-2)).toInt();
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,col))->toolTip();
    int coll=0;
    for(int i=6;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-coll);
    for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        fCompare.SetData(i,filtercol,true);
    }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonFriendReached_Click(){
    QRadioButton *rb = qobject_cast<QRadioButton*>(sender());
    int col=(rb->objectName().mid(2,rb->objectName().indexOf("Reached")-2)).toInt();
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,col))->toolTip();
    int coll=0;
    for(int i=6;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-coll);
    for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        fCompare.SetData(i,filtercol,ui->TableWidgetCompareAchievements->item(i,coll)->text().indexOf(".")>-1);
    }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonFriendNotReached_Click(){
    QRadioButton *rb = qobject_cast<QRadioButton*>(sender());
    int col=(rb->objectName().mid(2,rb->objectName().indexOf("NotReached")-2)).toInt();
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,col))->toolTip();
    int coll=0;
    for(int i=6;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-coll);
    for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        fCompare.SetData(i,filtercol,ui->TableWidgetCompareAchievements->item(i,coll)->text().indexOf(".")==-1);
    }
    UpdateHiddenRows();
}
void FormAchievements::on_TableWidgetCompareFriendsCellChanged(int row, int column){
    if((row==1)&&(column>1)){
        int col=ui->TableWidgetCompareAchievements->columnCount();
        SProfile sProfile=friends[column-2].first;
        if(ui->TableWidgetCompareFriends->item(row,column)->checkState()==Qt::Checked){
            ui->TableWidgetCompareAchievements->insertColumn(col);
            ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(col,new QTableWidgetItem(sProfile.GetPersonaname()));
            QNetworkAccessManager manager;
            QEventLoop loop;
            connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QNetworkReply &imagereply = *manager.get(QNetworkRequest(friends[column-2].first.GetAvatar()));
            loop.exec();
            disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
            QPixmap pix;
            pix.loadFromData(imagereply.readAll());
            QLabel *ava = new QLabel;
            ava->setPixmap(pix);
            ava->setToolTip(friends[column-2].first.GetPersonaname());
            ava->setAlignment(Qt::AlignCenter);
            ui->TableWidgetCompareAchievements->setCellWidget(0,col,ava);
            SAchievementsPlayer pla(key,QString::number(game.GetAppid()),sProfile.GetSteamid());
            connect(&pla,SIGNAL(finished()), &loop, SLOT(quit()));
            loop.exec();
            disconnect(&pla,SIGNAL(finished()), &loop, SLOT(quit()));
            SAchievements ach=achievements;
            ach.Set(pla);
            if(ProfileIsPublic(ach,col)){
                QRadioButton *rbAll = new QRadioButton();
                QRadioButton *rbReached = new QRadioButton();
                QRadioButton *rbNotReached = new QRadioButton();
                rbAll->setObjectName("RB"+QString::number(column)+"All");
                rbReached->setObjectName("RB"+QString::number(column)+"Reached");
                rbNotReached->setObjectName("RB"+QString::number(column)+"NotReached");
                connect(rbAll,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendAll_Click);
                connect(rbReached,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendReached_Click);
                connect(rbNotReached,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendNotReached_Click);
                rbAll->setChecked(true);
                QWidget *wd = new QWidget;
                QVBoxLayout *lay = new QVBoxLayout;
                wd->setObjectName("WD"+QString::number(column));
                lay->setObjectName("Lay"+QString::number(column));
                lay->addWidget(rbAll);
                lay->addWidget(rbReached);
                lay->addWidget(rbNotReached);
                lay->setMargin(1);
                wd->setLayout(lay);
                rbAll->setIcon(QIcon(":/"+theme+"/program/"+theme+"/all.png"));
                rbReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/reached.png"));
                rbNotReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/notreached.png"));
                ui->TableWidgetCompareFriends->setCellWidget(2,column,wd);
                ui->TableWidgetCompareFriends->resizeRowsToContents();
                ui->TableWidgetCompareFriends->resizeColumnsToContents();
            }
            fCompare.SetCol(fCompare.GetCol()+1);

            ui->TableWidgetCompareAchievements->setColumnWidth(col,80);
        } else {
            int coll=0;
            for(int i=6;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
                if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==sProfile.GetPersonaname()){
                    coll=i;
                    ui->TableWidgetCompareAchievements->removeColumn(i);
                    break;
                }
            }
            if(findChild<QRadioButton*>("RB"+QString::number(column)+"All")){
                disconnect(findChild<QRadioButton*>("RB"+QString::number(column)+"All"),&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendAll_Click);
                disconnect(findChild<QRadioButton*>("RB"+QString::number(column)+"Reached"),&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendReached_Click);
                disconnect(findChild<QRadioButton*>("RB"+QString::number(column)+"NotReached"),&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendNotReached_Click);
                delete findChild<QRadioButton*>("RB"+QString::number(column)+"All");
                delete findChild<QRadioButton*>("RB"+QString::number(column)+"Reached");
                delete findChild<QRadioButton*>("RB"+QString::number(column)+"NotReached");
                delete findChild<QVBoxLayout*>("Lay"+QString::number(column));
                ui->TableWidgetCompareFriends->removeCellWidget(2,column);
                delete findChild<QWidget*>("WD"+QString::number(column));
                ui->TableWidgetCompareFriends->resizeRowsToContents();
                ui->TableWidgetCompareFriends->resizeColumnsToContents();
            }
            fCompare.DeleteCol(fCompare.GetCol()-(ui->TableWidgetCompareAchievements->columnCount()-coll+1));
            UpdateHiddenRows();
        }
    }
}
void FormAchievements::on_CheckBoxCompareAllFriends_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        for (int i=0;i<friends.size();i++) {
            if(friends[i].second==2){
                ui->TableWidgetCompareFriends->setColumnHidden(i+2,true);
            }
        }
        break;
    }
    case 2:{
        for (int i=0;i<friends.size();i++) {
            if(friends[i].second==2){
                ui->TableWidgetCompareFriends->setColumnHidden(i+2,false);
            }
        }
        ui->TableWidgetCompareFriends->resizeColumnsToContents();
        break;
    }
    }
}
#define SimpleCompareEnd }

#define System {
FormAchievements::~FormAchievements(){
    delete categoryvalueslayout;
    delete ui;
}
void FormAchievements::closeEvent(QCloseEvent*){
    emit return_to_games(unicnum);
    this->deleteLater();
}
void FormAchievements::ShowCategories(){
    categoriesGame.Set(game);
    QList<QString> list = categoriesGame.GetTitles();
    while(ui->ComboBoxCategoriesCategory->count()>1){
        ui->ComboBoxCategoriesCategory->removeItem(1);
    }
    QFormLayout *layout1 = new QFormLayout;
    QFormLayout *layout2 = new QFormLayout;
    QWidget *widget1 = new QWidget;
    QWidget *widget2 = new QWidget;
    for(int i = 0; i < list.size(); i++){
        if(categoriesGame.GetIsNoValues(i)==1){
            QCheckBox *chb = new QCheckBox;
            chb->setText(categoriesGame.GetTitle(i));
            chb->setObjectName("Category"+QString::number(i));
            connect(chb,&QCheckBox::stateChanged,this,&FormAchievements::on_CheckBoxCategory_Change);
            layout2->addRow(chb);
        } else {
            QComboBox *cb = new QComboBox;
            cb->addItem(tr("Не выбрано"));
            QJsonArray values=categoriesGame.GetValues(i);
            for(int j=0;j<values.size();j++) {
                cb->addItem(values.at(j).toObject().value("Title").toString());
            }
            cb->setObjectName("Category"+QString::number(i));
            connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
            layout1->addRow(new QLabel(categoriesGame.GetTitle(i)),cb);
        }
        ui->ComboBoxCategoriesCategory->addItem(categoriesGame.GetTitle(i));
        }
    widget1->setLayout(layout1);
    widget2->setLayout(layout2);
    ui->ScrollAreaCategories->setWidget(widget1);
    ui->ScrollAreaCheckCategories->setWidget(widget2);

    ui->ScrollAreaCategories->setHidden((layout1->rowCount()==0));
    ui->ScrollAreaCheckCategories->setHidden((layout2->rowCount()==0));
    ui->ButtonChangeCategory->setEnabled(list.size()!=0);

    fAchievements.SetCol(list.size()+3);
    fCompare.SetCol(list.size()+3+ui->TableWidgetCompareAchievements->columnCount()-7);
}
void FormAchievements::UpdateHiddenRows(){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++)
        ui->TableWidgetAchievements->setRowHidden(i,!fAchievements.GetData(i));
    for(int i=0;i<ui->TableWidgetCompareAchievements->rowCount();i++) {
        ui->TableWidgetCompareAchievements->setRowHidden(i,!fCompare.GetData(i));
    }
}
bool FormAchievements::ProfileIsPublic(SAchievements achievement, int col){
    int totalr=0;
    int totalnr=0;
    for(int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        int j=0;
        bool accept=false;
        for(;j<achievement.GetAchievementsCount();j++){
            if(achievement.GetApiname(j)==ui->TableWidgetCompareAchievements->item(i,0)->text()){
                accept=true;
                break;
                }
        }
        if(accept){
            QTableWidgetItem *item5;
            if(achievement.GetAchieved(j)==1){
                item5 = new QTableWidgetItem(tr("Получено %1").arg(achievement.GetUnlocktime(j).toString("yyyy.MM.dd hh:mm")));
                totalr++;
                } else {
                item5 = new QTableWidgetItem(tr("Не получено"));
                totalnr++;
                }
            item5->setTextAlignment(Qt::AlignCenter);
            ui->TableWidgetCompareAchievements->setItem(i,col,item5);
        }
        }
    if((totalr==0)&&(totalnr==0)){
        ui->TableWidgetCompareAchievements->setCellWidget(1,col, new QLabel("profile is \nnot public"));
        return false;
        } else {
        ui->TableWidgetCompareAchievements->setCellWidget(1,col, new QLabel(QString(" %1/%2\n%3%").arg(QString::number(totalr)).arg(QString::number(totalr+totalnr)).arg(QString::number(100.0*totalr/(totalr+totalnr)))));
        return true;
    }
}
#define SystemEnd }

#define Filter {
void FormAchievements::on_LineEditNameAchievements_textChanged(const QString&){
    for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        fAchievements.SetData(i,0,((ui->TableWidgetAchievements->item(i,2)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1)||(ui->TableWidgetAchievements->item(i,3)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1)));
        fCompare.SetData(i+2,0,((ui->TableWidgetCompareAchievements->item(i+2,2)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1)||(ui->TableWidgetCompareAchievements->item(i+2,3)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1)));
    }
    UpdateHiddenRows();
}
void FormAchievements::on_ButtonFindAchievement_clicked(){
    on_LineEditNameAchievements_textChanged(ui->LineEditNameAchievements->text());
}
void FormAchievements::on_ButtonAddCategory_clicked(){
    if(typecategory==0){
        typecategory=1;
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
        ui->CheckBoxCategoryOneValue->setChecked(false);

        ui->ComboBoxCategoriesCategory->setVisible(false);
        ui->ButtonDeleteCategory->setVisible(false);
        ui->LineEditTitleCategory->setEnabled(true);
        ui->ButtonAddValueCategory->setEnabled(true);

        ui->GroupBoxCategories->setTitle(tr("Добавить категорию"));
        ui->GroupBoxCategories->setVisible(true);
        ui->TableWidgetAchievements->setColumnCount(8);
        ui->TableWidgetAchievements->setHorizontalHeaderItem(7,new QTableWidgetItem());
        for(int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
            QTableWidgetItem *pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(j,7, pItem);
        }
        ui->TableWidgetAchievements->setColumnHidden(7,true);
    }
}
void FormAchievements::on_ButtonChangeCategory_clicked(){
    if(typecategory==0){
        typecategory=2;
        ui->ButtonAddCategory->setEnabled(false);
        ui->ButtonChangeCategory->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
        ui->CheckBoxCategoryOneValue->setChecked(false);

        ui->ComboBoxCategoriesCategory->setVisible(true);
        ui->ButtonDeleteCategory->setVisible(true);
        ui->LineEditTitleCategory->setEnabled(false);
        ui->ButtonAddValueCategory->setEnabled(false);

        ui->GroupBoxCategories->setTitle(tr("Изменить категорию"));
        ui->GroupBoxCategories->setVisible(true);
    }
}
void FormAchievements::on_ButtonUpdate_clicked(){
    achievements.Update();
    PullTableWidget();
    ui->LabelGameOnline->setText(tr("Сейчас в игре :%1").arg(game.GetNumberPlayers(key,true)));
}
void FormAchievements::FavoritesClicked(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int index=btn->objectName().mid(16).toInt();
    QJsonObject gameO;
    QJsonObject newValue;
    gameO["id"]=game.GetAppid();
    gameO["name"]=game.GetName();
    newValue["id"]=achievements.GetApiname(index);
    newValue["title"]=achievements.GetDisplayname(index);
    newValue["description"]=achievements.GetDescription(index);

    if(favorites.AddValue(gameO,newValue,true)){
        //Категория добавилась
    } else {
        //Категория уже есть (удалилась)
    }
    //Поменять картинку
}
void FormAchievements::on_ButtonCompare_clicked(){
    SwitchSimpleCompare(simpleCompare);
}
void FormAchievements::on_CheckBoxShowFilter_stateChanged(int arg1){
    ui->GroupBoxFilter->setHidden(arg1==0);
}
void FormAchievements::on_ComboBoxCategory_Change(int index){
    QComboBox *cb = qobject_cast<QComboBox*>(sender());
    if(categoriesGame.GetCounts()>0){
        int categorynum = cb->objectName().mid(8,cb->objectName().length()).toInt();
        if(index!=0){
            QList<QString> achievementsName = categoriesGame.GetValues(categorynum,index-1);
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                fAchievements.SetData(i,3+categorynum,false);
                fCompare.SetData(i+2,3+categorynum,false);
                for(int j=0;j<achievementsName.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,0)->text()==achievementsName[j]){
                        fAchievements.SetData(i,3+categorynum,true);
                        fCompare.SetData(i+2,3+categorynum,true);
                        break;
                        }
                    }
            }
        } else {
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                fAchievements.SetData(i,3+categorynum,true);
                fCompare.SetData(i+2,3+categorynum,true);
                }
        }
        UpdateHiddenRows();
    }
}
void FormAchievements::on_CheckBoxCategory_Change(int index){
    QCheckBox *cb = qobject_cast<QCheckBox*>(sender());
    if(categoriesGame.GetCounts()>0){
        int categorynum = cb->objectName().mid(8,cb->objectName().length()).toInt();
        if(index!=0){
            QList<QString> achievementsName = categoriesGame.GetNoValues(categorynum);
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                fAchievements.SetData(i,3+categorynum,false);
                fCompare.SetData(i+2,3+categorynum,false);
                for(int j=0;j<achievementsName.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,0)->text()==achievementsName[j]){
                        fAchievements.SetData(i,3+categorynum,true);
                        fCompare.SetData(i+2,3+categorynum,true);
                        break;
                        }
                    }
            }
        } else {
            for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                fAchievements.SetData(i,3+categorynum,true);
                fCompare.SetData(i+2,3+categorynum,true);
                }
        }
        UpdateHiddenRows();
    }
}
void FormAchievements::on_ButtonDeleteAllCategories_clicked(){
    QMessageBox messageBox(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите удалить все категории?"));
    QAbstractButton *btnYes = messageBox.addButton(tr("Да"),QMessageBox::YesRole);
    messageBox.addButton(tr("Отмена"),QMessageBox::NoRole);
    messageBox.exec();
    if(messageBox.clickedButton()==btnYes){
        QMessageBox messageBox(QMessageBox::Question,
                               tr("Внимание!"),
                               tr("Данные о категориях будут утеряны навсегда, вы точно хотите удалить все категории?"));
        QAbstractButton *btnYess = messageBox.addButton(tr("Да"),QMessageBox::YesRole);
        messageBox.addButton(tr("Отмена"),QMessageBox::NoRole);
        messageBox.exec();
        if(messageBox.clickedButton()==btnYess){
            categoriesGame.DeleteAll();
            ShowCategories();
        }
    }
}
#define HideColumns {
void FormAchievements::on_CheckBoxCompareIcon_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(1,arg1==0);
    ui->TableWidgetCompareAchievements->setColumnHidden(1,arg1==0);
}
void FormAchievements::on_CheckBoxCompareTitle_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(2,arg1==0);
    ui->TableWidgetCompareAchievements->setColumnHidden(2,arg1==0);
}
void FormAchievements::on_CheckBoxCompareDescription_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(3,arg1==0);
    ui->TableWidgetCompareAchievements->setColumnHidden(3,arg1==0);
}
void FormAchievements::on_CheckBoxCompareTotalPercent_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(4,arg1==0);
    ui->TableWidgetCompareAchievements->setColumnHidden(4,arg1==0);
}
#define HideColumnsEnd }
#define Categorys {
void FormAchievements::on_ButtonAddValueCategory_clicked(){
    if((typecategory==1)||(typecategory==2)){
        ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
        ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem());
        for(int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
            QTableWidgetItem *pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
            }
        int row = categoryvalueslayout->rowCount();
        FormCategoryValue *value = new FormCategoryValue(row);
        values.append(value);
        switch (row) {
        case 0:{
            value->setFirstLast(-2);
            break;
        }
        case 1:{
            values[row-1]->setFirstLast(-1);
            value->setFirstLast(1);
            break;
        }
        default:{
            values[row-1]->setFirstLast(0);
            value->setFirstLast(1);
        }
        }
        connect(value,&FormCategoryValue::valuechange,this,&FormAchievements::on_FormCategoryValueChange);
        connect(value,&FormCategoryValue::visiblechange,this,&FormAchievements::on_FormCategoryVisibleChange);
        connect(value,&FormCategoryValue::positionchange,this,&FormAchievements::on_FormCategoryPositionChange);
        connect(value,&FormCategoryValue::selectchange,this,&FormAchievements::on_FormCategorySelectChange);
        connect(value,&FormCategoryValue::deleting,this,&FormAchievements::on_FormCategoryDeleting);
        categoryvalueslayout->addRow(value);
    }
}
void FormAchievements::on_ButtonCancelCategory_clicked(){
    if(typecategory==1||typecategory==2){
        ui->GroupBoxCategories->setVisible(false);
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonChangeCategory->setEnabled(true);
        ui->ButtonCompare->setEnabled(true);
        while (!categoryvalueslayout->isEmpty()) {
            categoryvalueslayout->removeRow(0);
        }
        ui->LineEditTitleCategory->setText("");
        ui->ComboBoxCategoriesCategory->setCurrentIndex(0);
        typecategory=0;
        while(!values.isEmpty())
            values.remove(0);
        ui->TableWidgetAchievements->setColumnCount(7);
        //values.clear();
    }
}
void FormAchievements::on_ButtonAcceptCategory_clicked(){
    if(typecategory==1||typecategory==2){
        if(ui->LineEditTitleCategory->text()!=""){
            int targetCategory=-1;
            if(typecategory==2){
                targetCategory=ui->ComboBoxCategoriesCategory->currentIndex()-1;
            } else {
                targetCategory=categoriesGame.GetCounts();
            }

            QList<QString> titles = categoriesGame.GetTitles();
            bool accept=true;
            for(int i=0;i<titles.size();i++) {
                if((titles[i]==ui->LineEditTitleCategory->text())&&(i!=ui->ComboBoxCategoriesCategory->currentIndex()-1)){
                    accept=false;
                    break;
                }
            }
            if(accept){
                QJsonObject categoryNew;
                categoryNew["Title"]=ui->LineEditTitleCategory->text();
                QJsonArray valuesNew;
                QJsonArray noValuesNew;
                if(ui->CheckBoxCategoryOneValue->isChecked()){
                    categoryNew["IsNoValues"]=1;
                } else {
                    categoryNew["IsNoValues"]=0;
                    for(int i=8;i<ui->TableWidgetAchievements->columnCount();i++){
                        if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==""){
                            QMessageBox::warning(this,tr("Ошибка"),tr("Название значения пустое или повторяется!"));
                            return;
                            }
                        for(int j=8;j<i;j++){
                            if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->TableWidgetAchievements->horizontalHeaderItem(j)->text()){
                                QMessageBox::warning(this,tr("Ошибка"),tr("Название значения пустое или повторяется!"));
                                return;
                                }
                            }
                        }
                    }
                for(int j=0;j<ui->TableWidgetAchievements->rowCount();j++){
                    if(ui->TableWidgetAchievements->item(j,7)->checkState()){
                        noValuesNew.append(ui->TableWidgetAchievements->item(j,0)->text());
                        }
                    }
                for(int i=8;i<ui->TableWidgetAchievements->columnCount();i++){
                    QJsonObject valueNew;
                    valueNew["Title"]=ui->TableWidgetAchievements->horizontalHeaderItem(i)->text();
                    QJsonArray achievementsNew;
                    for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                        if(ui->TableWidgetAchievements->item(j,i)->checkState()){
                            achievementsNew.append(ui->TableWidgetAchievements->item(j,0)->text());
                            }
                    }
                    valueNew["Achievements"]=achievementsNew;
                    valuesNew.append(valueNew);
                    }
                categoryNew["Values"]=valuesNew;
                categoryNew["NoValues"]=noValuesNew;
                categoriesGame.ChangeCategory(targetCategory,categoryNew);
                ui->LineEditTitleCategory->setText("");
                ui->LineEditTitleCategory->setEnabled(false);
                delete ui->ScrollAreaCategories->layout();
                delete ui->ScrollAreaCheckCategories->layout();
                ShowCategories();
                ui->LineEditNameAchievements->setText("");
                ui->RadioButtonAll->setChecked(true);
                ui->CheckBoxFavorites->setChecked(false);
                QMessageBox::information(this,tr("Успешно"),tr("Категория была %1!").arg(typecategory==1?tr("добавлена"):tr("изменена")));
                on_ButtonCancelCategory_clicked();
            } else
                QMessageBox::warning(this,tr("Ошибка"),tr("Такая категория уже есть!"));
        } else
            QMessageBox::warning(this,tr("Ошибка"),tr("Название категории пустое!"));
    }
}
void FormAchievements::on_ButtonDeleteCategory_clicked(){
    if(typecategory==2){
        QMessageBox::StandardButton btn=QMessageBox::question(this,tr("Внимание"),tr("Вы уверены, что хотите удалить категорию?"),QMessageBox::Yes|QMessageBox::No);
        if(btn==QMessageBox::No){
            return;
        }
        if(ui->ComboBoxCategoriesCategory->currentIndex()!=0){
            delete ui->ScrollAreaCategories->layout();
            delete ui->ScrollAreaCheckCategories->layout();
            categoriesGame.DeleteCategory(ui->ComboBoxCategoriesCategory->currentIndex()-1);
            ShowCategories();
            ui->LineEditNameAchievements->setText("");
            ui->RadioButtonAll->setChecked(true);
            ui->CheckBoxFavorites->setChecked(false);
            QMessageBox::information(this,tr("Успешно"),tr("Категория была удалена!"));
            on_ButtonCancelCategory_clicked();
        }
    }
}
void FormAchievements::on_CheckBoxCategoryOneValue_stateChanged(int arg1){
    if(typecategory==1||typecategory==2){
        switch (arg1) {
        case 0:{
            ui->ButtonAddValueCategory->setEnabled(true);
            ui->ScrollAreaValuesCategory->setEnabled(true);
            ui->TableWidgetAchievements->setColumnHidden(7,true);
            for(int i=0;i<ui->TableWidgetAchievements->columnCount()-8;i++) {
                ui->TableWidgetAchievements->setColumnHidden(8+i,false);
            }
            break;
            }
        case 2:{
            ui->ButtonAddValueCategory->setEnabled(false);
            ui->ScrollAreaValuesCategory->setEnabled(false);
            ui->TableWidgetAchievements->setColumnHidden(7,false);
            for(int i=0;i<ui->TableWidgetAchievements->columnCount()-8;i++) {
                ui->TableWidgetAchievements->setColumnHidden(8+i,true);
            }
            break;
            }
        }
    }
}
void FormAchievements::on_LineEditTitleCategory_textChanged(const QString &arg1){
    if(ui->TableWidgetAchievements->columnCount()>7)
        ui->TableWidgetAchievements->horizontalHeaderItem(7)->setText(arg1);
}
void FormAchievements::on_ComboBoxCategoriesCategory_activated(int index){
    if(typecategory==2){
        if(categoriesGame.GetCounts()>0){
            ui->LineEditTitleCategory->setText(ui->ComboBoxCategoriesCategory->itemText(index));
            while(!categoryvalueslayout->isEmpty()){
                categoryvalueslayout->removeRow(0);
            }
            ui->TableWidgetAchievements->setColumnCount(7);
            if(index!=0){
                ui->ButtonAddValueCategory->setEnabled(true);
                ui->TableWidgetAchievements->setColumnCount(8);
                ui->LineEditTitleCategory->setEnabled(true);
                QList<QString> noValues = categoriesGame.GetNoValues(index-1);
                ui->TableWidgetAchievements->setHorizontalHeaderItem(7,new QTableWidgetItem(categoriesGame.GetTitle(index-1)));
                for(int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                    QTableWidgetItem *pItem(new QTableWidgetItem(tr("Add")));
                    pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
                    bool accept=true;
                    for(int k=0;k<noValues.size();k++) {
                        if(ui->TableWidgetAchievements->item(j,0)->text()==noValues[k]){
                            accept=false;
                            break;
                        }
                    }
                    pItem->setCheckState(accept?Qt::Unchecked:Qt::Checked);
                    ui->TableWidgetAchievements->setItem(j,7, pItem);
                }
                QJsonArray valuess = categoriesGame.GetValues(index-1);
                values.clear();
                for(int i=0;i<valuess.size();i++) {
                    int row = categoryvalueslayout->rowCount();
                    FormCategoryValue *value = new FormCategoryValue(row);
                    values.append(value);
                    switch (row) {
                    case 0:{
                        value->setFirstLast(-2);
                        break;
                    }
                    case 1:{
                        values[row-1]->setFirstLast(-1);
                        value->setFirstLast(1);
                        break;
                    }
                    default:{
                        values[row-1]->setFirstLast(0);
                        value->setFirstLast(1);
                    }
                    }
                    connect(value,&FormCategoryValue::valuechange,this,&FormAchievements::on_FormCategoryValueChange);
                    connect(value,&FormCategoryValue::visiblechange,this,&FormAchievements::on_FormCategoryVisibleChange);
                    connect(value,&FormCategoryValue::positionchange,this,&FormAchievements::on_FormCategoryPositionChange);
                    connect(value,&FormCategoryValue::selectchange,this,&FormAchievements::on_FormCategorySelectChange);
                    connect(value,&FormCategoryValue::deleting,this,&FormAchievements::on_FormCategoryDeleting);

                    ui->TableWidgetAchievements->insertColumn(ui->TableWidgetAchievements->columnCount());
                    ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(valuess[i].toObject().value("Title").toString()));
                    categoryvalueslayout->addRow(value);
                    value->setTitle(valuess[i].toObject().value("Title").toString());
                    for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                        QTableWidgetItem *pItem(new QTableWidgetItem(tr("Add")));
                        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
                        bool accept=true;
                        for (int k=0;k<valuess[i].toObject().value("Achievements").toArray().size();k++) {
                            if(ui->TableWidgetAchievements->item(j,0)->text()==valuess[i].toObject().value("Achievements").toArray().at(k).toString()){
                                accept=false;
                                break;
                            }
                        }
                        pItem->setCheckState(accept?Qt::Unchecked:Qt::Checked);
                        ui->TableWidgetAchievements->setItem(j,ui->TableWidgetAchievements->columnCount()-1, pItem);
                    }
                }
                if(categoriesGame.GetIsNoValues(index-1)==1){
                    ui->CheckBoxCategoryOneValue->setChecked(true);
                    ui->TableWidgetAchievements->setColumnHidden(7,false);
                    for(int i=0;i<ui->TableWidgetAchievements->columnCount()-8;i++)
                        ui->TableWidgetAchievements->setColumnHidden(8+i,true);
                } else {
                    ui->CheckBoxCategoryOneValue->setChecked(false);
                    ui->TableWidgetAchievements->setColumnHidden(7,true);
                    for(int i=0;i<ui->TableWidgetAchievements->columnCount()-8;i++)
                        ui->TableWidgetAchievements->setColumnHidden(8+i,false);
                }
            } else
                ui->ButtonAddValueCategory->setEnabled(false);
        }
    }
}
void FormAchievements::on_CheckBoxCategoryVisibleAll_clicked(){
    bool ch = ui->CheckBoxCategoryVisibleAll->isChecked();
    for (int i=0;i<values.size();i++) {
        values[i]->setVisibl(ch);
    }
}
#define CategorysValues {
void FormAchievements::on_FormCategoryValueChange(int pos, QString value){
    ui->TableWidgetAchievements->horizontalHeaderItem(8+pos)->setText(value);
}
void FormAchievements::on_FormCategoryVisibleChange(int pos, bool visible){
    bool accept=true;
    for (int i=0;i<values.size();i++) {
        if(!values[i]->getVisible())
            accept=false;
    }
    if(accept)
        ui->CheckBoxCategoryVisibleAll->setCheckState(Qt::Checked);
    else
        ui->CheckBoxCategoryVisibleAll->setCheckState(Qt::Unchecked);
    ui->TableWidgetAchievements->setColumnHidden(8+pos,!visible);
}
void FormAchievements::on_FormCategoryPositionChange(int pos, int posnew){
    if(posnew<0||posnew>ui->TableWidgetAchievements->columnCount()-8){
        QMessageBox::warning(this,"","Невозможно переместить значение");
    } else {
        for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
            Qt::CheckState pItem1 = ui->TableWidgetAchievements->item(j,8+pos)->checkState();
            ui->TableWidgetAchievements->item(j,8+pos)->setCheckState(ui->TableWidgetAchievements->item(j,8+posnew)->checkState());
            ui->TableWidgetAchievements->item(j,8+posnew)->setCheckState(pItem1);
        }
        QString hh=ui->TableWidgetAchievements->horizontalHeaderItem(8+pos)->text();
        ui->TableWidgetAchievements->horizontalHeaderItem(8+pos)->setText(ui->TableWidgetAchievements->horizontalHeaderItem(8+posnew)->text());
        ui->TableWidgetAchievements->horizontalHeaderItem(8+posnew)->setText(hh);

        std::swap(values[pos],values[posnew]);
        for (int i=0;i<values.size();i++) {
            categoryvalueslayout->addRow(values[i]);
            values[i]->setPosition(i);
            if(values.size()==1){
                values[i]->setFirstLast(-2);
            } else if(values.size()-1==i) {
                values[i]->setFirstLast(1);
            } else if(i==0) {
                values[i]->setFirstLast(-1);
            } else {
                values[i]->setFirstLast(0);
            }
        }
    }
}
void FormAchievements::on_FormCategorySelectChange(int pos, bool select){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
        if(!ui->TableWidgetAchievements->isRowHidden(i))
            ui->TableWidgetAchievements->item(i,8+pos)->setCheckState(select?Qt::Checked:Qt::Unchecked);
    }
}
void FormAchievements::on_FormCategoryDeleting(int pos){
    qDebug()<<pos;
    ui->TableWidgetAchievements->removeColumn(8+pos);
    categoryvalueslayout->removeRow(pos);
    values.remove(pos);
    for (int i=0;i<values.size();i++) {
        values[i]->setPosition(i);
        if(values.size()==1){
            values[i]->setFirstLast(-2);
        } else if(values.size()-1==i) {
            values[i]->setFirstLast(1);
        } else if(i==0) {
            values[i]->setFirstLast(-1);
        } else {
            values[i]->setFirstLast(0);
        }
    }
}
#define CategoryValuesEnd }
#define CategoryEnd }
#define FilterEnd }

void FormAchievements::on_ButtonReturn_clicked(){
    emit return_to_games(unicnum);
    //delete this;
}

void FormAchievements::on_CheckBoxFavorites_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
            fAchievements.SetData(i,2,true);
            fCompare.SetData(i+2,2,true);
        }
        break;
    }
    case 2:{
        QJsonObject gameO;
        gameO["id"]=game.GetAppid();
        gameO["name"]=game.GetName();
        QJsonArray val=favorites.GetValues(gameO);
        for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
            bool accept=false;
            for (int j=0;j<val.size();j++) {
                if(val[j].toObject().value("id").toString()==achievements.GetApiname(i)){
                    accept=true;
                    break;
                }
            }
            fAchievements.SetData(i,2,accept);
            fCompare.SetData(i+2,2,accept);
        }
        break;
    }
    }
    UpdateHiddenRows();
}
