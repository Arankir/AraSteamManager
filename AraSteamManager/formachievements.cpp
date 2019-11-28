#include "formachievements.h"
#include "ui_formachievements.h"

FormAchievements::FormAchievements(QString keys, QString ids, SGame games, int num, QWidget* parent) :    QWidget(parent),    ui(new Ui::FormAchievements){
    ui->setupUi(this);
    Words=Setting.GetWords("achievements");
    key=keys;
    id=ids;
    game=games;
    unicnum=num;
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
    ui->LineEditNameAchievements->setFocus();
}

#define Init {
void FormAchievements::InitComponents(){
    ui->TableWidgetAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetCompareAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetCompareFriends->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetCompareFriends->setMinimumSize(0,180);
    //ui->ButtonReturn->setIcon(QIcon(":/"+theme+"/program/"+theme+"/back.png"));
    ui->ButtonCompare->setIcon(QIcon(":/"+theme+"/program/"+theme+"/compare.png"));
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {background-image:url(images/program/filter_white.png)}");
    //ui->GroupBoxFilter->setStyleSheet("QGroupBox::title {image:url(images/program/filter_white.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->GroupBoxFilter->setStyleSheet("QGroupBox[accessibleName=\"Filter\"]::title {image:url(:/"+theme+"/program/"+theme+"/filter.png) 0 0 0 0 stretch stretch; image-position:left; margin-top:15px;}");
    ui->ButtonAddCategory->setIcon(QIcon(":/program/program/create.png"));
    ui->ButtonChangeCategory->setIcon(QIcon(":/"+theme+"/program/"+theme+"/change.png"));
    ui->ButtonDeleteCategory->setIcon(QIcon(":/program/program/delete.png"));
    ui->ButtonFindAchievement->setIcon(QIcon(":/"+theme+"/program/"+theme+"/find.png"));
    ui->ButtonAcceptNewCategory->setIcon(QIcon(":/program/program/apply.png"));
    ui->ButtonCancelNewCategory->setIcon(QIcon(":/program/program/cancel.png"));
    ui->ButtonAddValueNewCategory->setIcon(QIcon(":/program/program/create.png"));
    ui->ButtonAcceptChangeCategory->setIcon(QIcon(":/program/program/apply.png"));
    ui->ButtonCancelChangeCategory->setIcon(QIcon(":/program/program/cancel.png"));
    ui->ButtonAddValueChangeCategory->setIcon(QIcon(":/program/program/create.png"));
    ui->RadioButtonAll->setIcon(QIcon(":/"+theme+"/program/"+theme+"/all.png"));
    ui->RadioButtonReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/reached.png"));
    ui->RadioButtonNotReached->setIcon(QIcon(":/"+theme+"/program/"+theme+"/notreached.png"));
    ui->ButtonUpdate->setIcon(QIcon(":/"+theme+"/program/"+theme+"/update.png"));
    //ui->ButtonReturn->setText(" "+Words[0]);
    ui->ButtonCompare->setText(" "+Words[1]);
    ui->LabelGameLogo->setText("");
    ui->RadioButtonAll->setText(Words[2]);
    ui->RadioButtonReached->setText(Words[3]);
    ui->RadioButtonNotReached->setText(Words[4]);
    ui->ButtonAddCategory->setText(Words[5]);
    ui->ButtonChangeCategory->setText(Words[6]);
    ui->CheckBoxFavorites->setText(Words[7]);
    ui->ButtonFindAchievement->setText(Words[8]);
    ui->GroupBoxFilter->setTitle("      "+Words[9]);
    ui->LineEditNameAchievements->setPlaceholderText(Words[10]);
    ui->GroupBoxAddCategory->setTitle(Words[5]);
    ui->ButtonAddValueNewCategory->setText(Words[11]);
    ui->ButtonCancelNewCategory->setText(" "+Words[12]);
    ui->ButtonAcceptNewCategory->setText(Words[13]);
    ui->LineEditTitleNewCategory->setPlaceholderText(Words[14]);
    //ui->LineEditTitleValueNewCategory->setPlaceholderText(Words[15]);
    ui->GroupBoxChangeCategory->setTitle(Words[16]);
    ui->ButtonAddValueChangeCategory->setText(Words[11]);
    ui->ButtonCancelChangeCategory->setText(" "+Words[12]);
    ui->ButtonAcceptChangeCategory->setText(Words[13]);
    ui->ButtonDeleteCategory->setText(Words[17]);
    ui->ComboBoxCategoriesChangeCategory->addItem(Words[18]);
    ui->LineEditTitleCategoryChangeCategory->setPlaceholderText(Words[14]);
    //ui->LineEditTitleValueChangeCategory->setPlaceholderText(Words[15]);
    ui->ButtonUpdate->setText(Words[36]);
    ui->CheckBoxNewCategoryOneValue->setText(Words[38]);
    ui->CheckBoxChangeCategoryOneValue->setText(Words[38]);
    ui->GroupBoxCompareShowedColumns->setTitle(Words[42]);
    ui->CheckBoxCompareIcon->setText(Words[43]);
    ui->CheckBoxCompareTitle->setText(Words[44]);
    ui->CheckBoxCompareDescription->setText(Words[45]);
    ui->CheckBoxCompareTotalPercent->setText(Words[46]);
    ui->CheckBoxCompareAllFriends->setText(Words[47]);
    ui->CheckBoxShowFilter->setText(Words[49]);
    ui->TableWidgetAchievements->setColumnCount(7);
    ui->TableWidgetCompareAchievements->setColumnCount(7);
    ui->TableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[19]));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[20]));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem(Words[21]));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem(Words[23]));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(6,new QTableWidgetItem(Words[22]));
    ui->LabelGameOnline->setText(Words[27]+": "+game.GetNumberPlayers(key,false));
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
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem(Profile.GetPersonaname()/*Words[15]*/));
    QNetworkReply &imagereply = *manager.get(QNetworkRequest(Profile.GetAvatar()));
    loop.exec();
    QPixmap pix;
    pix.loadFromData(imagereply.readAll());
    disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QLabel* myava = new QLabel;
    myava->setPixmap(pix);
    myava->setAlignment(Qt::AlignCenter);
    ui->TableWidgetCompareAchievements->setCellWidget(0,5,myava);
    ui->TableWidgetCompareAchievements->setRowHeight(0,33);
    ui->TableWidgetCompareFriends->setRowCount(4);
    ui->TableWidgetCompareFriends->setColumnCount(2);
    ui->TableWidgetCompareFriends->setRowHidden(3,true);
    QLabel* myava2 = new QLabel;
    myava2->setPixmap(pix);
    myava2->setAlignment(Qt::AlignCenter);
    myava2->setToolTip(Profile.GetPersonaname());
    ui->TableWidgetCompareFriends->setCellWidget(0,0,myava2);
    QLabel* All = new QLabel("All");
    All->setToolTip(Words[48]);
    All->setPixmap(QPixmap(":/"+theme+"/program/"+theme+"/friends.png"));
    All->setScaledContents(true);
    All->setFixedSize(32,32);
    ui->TableWidgetCompareFriends->setCellWidget(0,1,All);
    QRadioButton* rbMyAll = new QRadioButton(/*Words[]*/);
    QRadioButton* rbMyReached = new QRadioButton(/*Words[]*/);
    QRadioButton* rbMyNotReached = new QRadioButton(/*Words[]*/);
    rbMyAll->setObjectName("RBMyAll");
    rbMyReached->setObjectName("RBMyReached");
    rbMyNotReached->setObjectName("RBMyNotReached");
    connect(rbMyAll,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonAll_clicked);
    connect(rbMyReached,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonReached_clicked);
    connect(rbMyNotReached,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonNotReached_clicked);
    rbMyAll->setChecked(true);
    QWidget* wd1 = new QWidget;
    QVBoxLayout* lay1 = new QVBoxLayout;
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
    QWidget* wd2 = new QWidget;
    QVBoxLayout* lay2 = new QVBoxLayout;
    wd2->setObjectName("WDFriends");
    lay2->setObjectName("LayFriends");
    QPushButton* pbFriendsAll = new QPushButton(/*Words[]*/);
    QPushButton* pbFriendsReached = new QPushButton(/*Words[]*/);
    QPushButton* pbFriendsNotReached = new QPushButton(/*Words[]*/);
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

    ui->GroupBoxAddCategory->setVisible(false);
    ui->GroupBoxChangeCategory->setVisible(false);
    ui->GroupBoxCategories->setVisible(false);
    SwitchSimpleCompare(1);
    ui->ProgressBarFriendsLoad->setVisible(false);
    ui->TableWidgetCompareAchievements->setColumnCount(6);
    ui->TableWidgetCompareAchievements->setVerticalHeaderItem(0,new QTableWidgetItem(""));
    ui->TableWidgetCompareAchievements->setVerticalHeaderItem(1,new QTableWidgetItem("%"));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[19]));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[20]));
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem(Words[21]));

    QWidget* widget1 = new QWidget;
    newcategoryvalueslayout = new QFormLayout;
    widget1->setLayout(newcategoryvalueslayout);
    ui->ScrollAreaValues->setWidget(widget1);
    QWidget* widget2 = new QWidget;
    changecategoryvalueslayout = new QFormLayout;
    widget2->setLayout(changecategoryvalueslayout);
    ui->ScrollAreaValuesChangeCategory->setWidget(widget2);

    QWidget* widget3 = new QWidget;
    categoryvalueslayout = new QFormLayout;
    categoryvalueslayout->setSpacing(0);
    categoryvalueslayout->setContentsMargins(1,1,1,1);
    widget3->setLayout(categoryvalueslayout);
    ui->ScrollAreaValuesCategory->setWidget(widget3);

    ui->LineEditTitleCategoryChangeCategory->setEnabled(false);
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
    connect(&achievements,SIGNAL(finished()),this,SLOT(PullTableWidget()));
    achievements.Set(key,QString::number(game.GetAppid()),id,Words[26]);
    qDebug()<<"FinishStatus="<<achievements.GetStatusFinish();
    //PullTableWidget();
}
void FormAchievements::PullTableWidget(){
    ui->TableWidgetAchievements->setRowCount(achievements.GetAchievementsCount());
    for(int i=0;i<achievements.GetAchievementsCount();i++)
        ui->TableWidgetAchievements->setRowHeight(i,65);
    ui->TableWidgetCompareAchievements->setRowCount(achievements.GetAchievementsCount()+2);
    if(!(achievements.GetStatusFinish()=="success")){
        ui->TableWidgetAchievements->insertRow(0);
        QTableWidgetItem* item1 = new QTableWidgetItem("Error");
        ui->TableWidgetAchievements->setItem(0,1,item1);
        ui->TableWidgetAchievements->setColumnHidden(2,true);
        ui->TableWidgetAchievements->setColumnHidden(3,true);
        ui->TableWidgetAchievements->setColumnHidden(4,true);
        ui->TableWidgetAchievements->setColumnHidden(5,true);
        ui->TableWidgetAchievements->setColumnHidden(6,true);
        ui->GroupBoxFilter->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
    } else{
        Threading LoadTable(this);
        QLabel* lbl = new QLabel;
        ui->TableWidgetCompareAchievements->setCellWidget(1,5, lbl);
        LoadTable.AddThreadAchievements(achievements,Words,ui->LabelTotalPersent,ui->TableWidgetAchievements,lbl,ui->TableWidgetCompareAchievements);
    }
}
void FormAchievements::ProgressLoading(int p,int row){
    qDebug()<<"ProgressLoading..."<<p;
    QPushButton* button1 = new QPushButton;
    button1->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
    connect(button1,&QPushButton::pressed,this,&FormAchievements::FavoritesClicked);
    button1->setObjectName("ButtonFavorites&"+achievements.GetApiname(p));
    ui->TableWidgetAchievements->setCellWidget(row,6,button1);
}
void FormAchievements::OnFinish(){
    ui->TableWidgetAchievements->resizeColumnToContents(4);
    ui->TableWidgetAchievements->resizeRowsToContents();
    int j=0;
    filterAchievements = new bool*[ui->TableWidgetAchievements->rowCount()];
    filterCompare = new bool*[ui->TableWidgetCompareAchievements->rowCount()];
    ShowCategories();
    ui->TableWidgetCompareAchievements->resizeRowsToContents();
    for (int i=0;i<achievements.GetAchievementsCount();i++) {
        if(achievements.GetDisplayname(i)!=""){
            QString AchievementIcon=achievements.GetIcon(i).mid(66,achievements.GetIcon(i).length());
            QString path="images/achievements/"+QString::number(game.GetAppid())+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1);
            if(!QFile::exists(path)){
                ImageRequest* image = new ImageRequest(achievements.GetIcon(i),j,path,true);
                connect(image,&ImageRequest::onReady,this,&FormAchievements::OnResultImage);
            } else {
                QPixmap pixmap;
                pixmap.load(path);
                QLabel* label = new QLabel;
                label->setPixmap(pixmap);
                ui->TableWidgetAchievements->setCellWidget(j,1,label);
                ui->TableWidgetAchievements->resizeRowToContents(j);
                QLabel* label2 = new QLabel;
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
void FormAchievements::OnResultImage(ImageRequest* imgr){
    disconnect(imgr,&ImageRequest::onReady,this,&FormAchievements::OnResultImage);
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel* label = new QLabel;
    label->setPixmap(pixmap);
    QLabel* label2 = new QLabel;
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
        ui->ButtonChangeCategory->setEnabled(true);
        ui->TableWidgetCompareFriends->setVisible(false);
        ui->TableWidgetCompareAchievements->setVisible(false);
        ui->ButtonCompare->setText(Words[50]);
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
        ui->ButtonCompare->setText(Words[51]);
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
    ui->TableWidgetCompareAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem(Profile.GetPersonaname()/*Words[15]*/));

    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply &imagereply = *manager.get(QNetworkRequest(Profile.GetAvatar()));
    loop.exec();
    QPixmap pix;
    pix.loadFromData(imagereply.readAll());
    QLabel* myava1 = new QLabel;
    myava1->setPixmap(pix);
    myava1->setAlignment(Qt::AlignCenter);
    ui->TableWidgetCompareAchievements->setCellWidget(0,5,myava1);
    ui->TableWidgetCompareAchievements->resizeRowToContents(0);
    QLabel* myava2 = new QLabel;
    myava2->setPixmap(pix);
    myava2->setAlignment(Qt::AlignCenter);
    myava2->setToolTip(Profile.GetPersonaname());
    ui->TableWidgetCompareFriends->setCellWidget(0,0,myava2);


    SFriends frien(key,id,false);
    SProfile Profiless = frien.GetProfiles();
    friendsCount=Profiless.GetCount();
    ui->TableWidgetCompareFriends->setColumnCount(friendsCount+2);
    for (int i=0;i<friendsCount;i++) {
        ui->TableWidgetCompareFriends->setColumnWidth(i+2,33);
        Profiles.push_back(Profiless.GetProfile(i));
    }//Сортировка по именам
    for (int i=0; i < friendsCount-1; i++) {
        for (int j=0; j < Profiles.size()-i-1; j++) {
            if (Profiles[j].GetPersonaname() > Profiles[j+1].GetPersonaname()) {
                SProfile temp = Profiles[j];
                Profiles[j] = Profiles[j+1];
                Profiles[j+1] = temp;
            }
        }
    }
    ui->ProgressBarFriendsLoad->setMaximum(Profiles.size());
    ui->ProgressBarFriendsLoad->setValue(0);
    ui->ProgressBarFriendsLoad->setVisible(true);

    for (int i=0;i<friendsCount;i++) {
        SGames *Games = new SGames;
        Games->SetIndex(i);
        Games->Set(key,Profiles[i].GetSteamid(),true,true,true);
        connect(Games,SIGNAL(finished(SGames*)),this,SLOT(LoadFriend(SGames*)));
    }

}
void FormAchievements::LoadFriend(SGames* Games){
    disconnect(Games,SIGNAL(finished(SGames*)),this,SLOT(LoadFriend(SGames*)));
    bool apply=false;
    for (int i=0;i<Games->GetCount();i++) {//Проверка на наличие игры
        if(Games->GetAppid(i)==game.GetAppid()){
            apply=true;
            break;
        }
    }
    QPair<SProfile,int> deb;
    deb.first=Profiles[Games->GetIndex()];
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

    for (int i=0;i<friends.size();i++) {
        QNetworkReply &imagereply = *manager.get(QNetworkRequest(friends[i].first.GetAvatar()));
        loop.exec();
        QPixmap pix;
        pix.loadFromData(imagereply.readAll());
        QLabel* ava = new QLabel;
        ava->setPixmap(pix);
        ava->setToolTip(friends[i].first.GetPersonaname());
        ava->setAlignment(Qt::AlignCenter);
        ui->TableWidgetCompareFriends->setCellWidget(0,i+2,ava);
        QTableWidgetItem* pItem(new QTableWidgetItem(tr("")));
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->TableWidgetCompareFriends->setItem(1,i+2,pItem);
        ui->TableWidgetCompareFriends->setItem(3,i+2,new QTableWidgetItem(friends[i].first.GetSteamid()));
        ui->TableWidgetCompareFriends->setColumnHidden(i+2,friends[i].second==2?true:false);
    }
    disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    connect(ui->TableWidgetCompareFriends,&QTableWidget::cellChanged,this,&FormAchievements::on_TableWidgetCompareFriendsCellChanged);
    ui->TableWidgetCompareFriends->resizeColumnsToContents();
}
void FormAchievements::on_RadioButtonAll_clicked(){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        filterAchievements[i][1]=true;
        filterCompare[i+2][1]=true;
    }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonReached_clicked(){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        filterAchievements[i][1]=ui->TableWidgetAchievements->item(i,5)->text().indexOf(".")>-1?true:false;
        filterCompare[i+2][1]=ui->TableWidgetCompareAchievements->item(i+2,5)->text().indexOf(".")>-1?true:false;
        }
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonNotReached_clicked(){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        filterAchievements[i][1]=ui->TableWidgetAchievements->item(i,5)->text().indexOf(".")>-1?false:true;
        filterCompare[i+2][1]=ui->TableWidgetCompareAchievements->item(i+2,5)->text().indexOf(".")>-1?false:true;
        }
    UpdateHiddenRows();
}

void FormAchievements::on_RadioButtonCompareFriendsAll_clicked(){
    for (int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"All";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormAchievements::on_RadioButtonCompareFriendsReached_clicked(){
    for (int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"Reached";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormAchievements::on_RadioButtonCompareFriendsNotReached_clicked(){
    for (int i=2;i<ui->TableWidgetCompareFriends->columnCount();i++) {
        QString Name="RB"+QString::number(i)+"NotReached";
        if(findChild<QRadioButton*>(Name)){
            findChild<QRadioButton*>(Name)->setChecked(true);
            findChild<QRadioButton*>(Name)->clicked(true);
        }
    }
}
void FormAchievements::on_RadioButtonFriendAll_Click(){
    QRadioButton* rb = qobject_cast<QRadioButton*>(sender());
    int col=(rb->objectName().mid(2,rb->objectName().indexOf("All")-2)).toInt();
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,col))->toolTip();
    int coll=0;
    for (int i=6;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=colfilterCompare-(ui->TableWidgetCompareAchievements->columnCount()-coll);
    for (int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++){
        filterCompare[i][filtercol]=true;}
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonFriendReached_Click(){
    QRadioButton* rb = qobject_cast<QRadioButton*>(sender());
    int col=(rb->objectName().mid(2,rb->objectName().indexOf("Reached")-2)).toInt();
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,col))->toolTip();
    int coll=0;
    for (int i=6;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=colfilterCompare-(ui->TableWidgetCompareAchievements->columnCount()-coll);
    for (int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++)
        filterCompare[i][filtercol]=ui->TableWidgetCompareAchievements->item(i,coll)->text().indexOf(".")>-1?true:false;
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonFriendNotReached_Click(){
    QRadioButton* rb = qobject_cast<QRadioButton*>(sender());
    int col=(rb->objectName().mid(2,rb->objectName().indexOf("NotReached")-2)).toInt();
    QString Name=dynamic_cast<QLabel*>(ui->TableWidgetCompareFriends->cellWidget(0,col))->toolTip();
    int coll=0;
    for (int i=6;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
        if(ui->TableWidgetCompareAchievements->horizontalHeaderItem(i)->text()==Name){
            coll=i;
            break;
        }
    }
    int filtercol=colfilterCompare-(ui->TableWidgetCompareAchievements->columnCount()-coll);
    for (int i=2;i<ui->TableWidgetCompareAchievements->rowCount();i++)
        filterCompare[i][filtercol]=ui->TableWidgetCompareAchievements->item(i,coll)->text().indexOf(".")>-1?false:true;
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
            QLabel* ava = new QLabel;
            ava->setPixmap(pix);
            ava->setToolTip(friends[column-2].first.GetPersonaname());
            ava->setAlignment(Qt::AlignCenter);
            ui->TableWidgetCompareAchievements->setCellWidget(0,col,ava);
            SAchievementsPlayer Pla(key,QString::number(game.GetAppid()),sProfile.GetSteamid());
            connect(&Pla,SIGNAL(finished()), &loop, SLOT(quit()));
            loop.exec();
            disconnect(&Pla,SIGNAL(finished()), &loop, SLOT(quit()));
            SAchievements Ach=achievements;
            Ach.Set(Pla);
            if(ProfileIsPublic(Ach,col)){
                QRadioButton* rbAll = new QRadioButton(/*Words[]*/);
                QRadioButton* rbReached = new QRadioButton(/*Words[]*/);
                QRadioButton* rbNotReached = new QRadioButton(/*Words[]*/);
                rbAll->setObjectName("RB"+QString::number(column)+"All");
                rbReached->setObjectName("RB"+QString::number(column)+"Reached");
                rbNotReached->setObjectName("RB"+QString::number(column)+"NotReached");
                connect(rbAll,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendAll_Click);
                connect(rbReached,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendReached_Click);
                connect(rbNotReached,&QRadioButton::clicked,this,&FormAchievements::on_RadioButtonFriendNotReached_Click);
                rbAll->setChecked(true);
                QWidget* wd = new QWidget;
                QVBoxLayout* lay = new QVBoxLayout;
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
            bool** New = new bool*[ui->TableWidgetCompareAchievements->rowCount()];
            colfilterCompare++;
            for (int i=0;i<ui->TableWidgetCompareAchievements->rowCount();i++) {
                New[i]=new bool[colfilterCompare];
                for (int j=0;j<colfilterCompare;j++)
                    New[i][j]=j!=colfilterCompare-1?filterCompare[i][j]:true;
                }
            delete filterCompare;
            filterCompare = new bool*[ui->TableWidgetCompareAchievements->rowCount()];
            filterCompare = New;

            ui->TableWidgetCompareAchievements->setColumnWidth(col,80);
        } else {
            int coll=0;
            for (int i=6;i<ui->TableWidgetCompareAchievements->columnCount();i++) {
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
            int filtercol=colfilterCompare-(ui->TableWidgetCompareAchievements->columnCount()-coll+1);
            bool** New = new bool*[ui->TableWidgetCompareAchievements->rowCount()];
            colfilterCompare--;
            for (int i=0;i<ui->TableWidgetCompareAchievements->rowCount();i++) {
                New[i]=new bool[colfilterCompare];
                int jt=0;
                for (int j=0;j<colfilterCompare;j++,jt++) {
                    if(j==filtercol)
                        jt++;
                    New[i][j]=filterCompare[i][jt];
                }
            }
            delete filterCompare;
            filterCompare = new bool*[ui->TableWidgetCompareAchievements->rowCount()];
            filterCompare = New;
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
    /*            if(ui->TableWidgetFriends->item(1,2+i)->checkState()==Qt::Checked){
                    int coll=0;
                    ui->TableWidgetFriends->item(1,2+i)->setCheckState(Qt::Unchecked);
                    for (int j=6;j<ui->TableWidget->columnCount();j++) {
                        if(ui->TableWidget->horizontalHeaderItem(j)->text()==friends[i].first.GetPersonaname()&&friends[i].second==2){
                            coll=i;
                            ui->TableWidget->removeColumn(j);
                            break;
                        }
                    }
                    if(findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"All")){
                        disconnect(findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"All"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendAll_Click()));
                        disconnect(findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"Reached"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendReached_Click()));
                        disconnect(findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"NotReached"),SIGNAL(clicked()),this,SLOT(on_RadioButtonFriendNotReached_Click()));
                        delete findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"All");
                        delete findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"Reached");
                        delete findChild<QRadioButton*>("RB"+QString::number(type1+2+i)+"NotReached");
                        delete findChild<QVBoxLayout*>("Lay"+QString::number(type1+2+i));
                        ui->TableWidgetFriends->removeCellWidget(2,type1+2+i);
                        delete findChild<QWidget*>("WD"+QString::number(type1+2+i));
                        ui->TableWidgetFriends->resizeRowsToContents();
                        ui->TableWidgetFriends->resizeColumnsToContents();
                    }
                    int filtercol=colfilter-(ui->TableWidget->columnCount()-coll);
                    bool** New = new bool*[ui->TableWidget->rowCount()];
                    colfilter--;
                    for (int i=0;i<ui->TableWidget->rowCount();i++) {
                        New[i]=new bool[colfilter];
                        int jt=0;
                        for (int j=0;j<colfilter;j++,jt++) {
                            if(j==filtercol)
                                jt++;
                            New[i][j]=filter[i][jt];
                        }
                    }
                    delete filter;
                    filter = new bool*[ui->TableWidget->rowCount()];
                    filter = New;
                    UpdateHiddenRows();
                }
                ui->TableWidgetFriends->setColumnHidden(type1+2+i,true);*/
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
    delete filterAchievements;
    delete  filterCompare;
    //delete newcategoryvalueslayout;
    //delete changecategoryvalueslayout;
    delete ui;
}
void FormAchievements::closeEvent(QCloseEvent*){
    emit return_to_games(unicnum);
    //delete this;
}
void FormAchievements::ShowCategories(){
    QDir categories("Files/Categories/"+QString::number(game.GetAppid()));
    categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    categories.setSorting(QDir::Name);
    QFileInfoList list = categories.entryInfoList();
    if(categories.exists()){
        while(ui->ComboBoxCategoriesChangeCategory->count()>1){
            ui->ComboBoxCategoriesChangeCategory->removeItem(1);
        }
        QFormLayout* layout1 = new QFormLayout;
        QFormLayout* layout2 = new QFormLayout;
        QWidget* widget1 = new QWidget;
        QWidget* widget2 = new QWidget;
        for (int i = 0; i < list.size(); ++i){
            QFile category("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(i).fileName());
            category.open(QFile::ReadOnly);
            QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
            if(cat.object().value("values").toArray().size()==1){
                QCheckBox* chb = new QCheckBox;
                chb->setText(cat.object().value("name").toString());
                chb->setObjectName("Category"+QString::number(i));
                connect(chb,&QCheckBox::stateChanged,this,&FormAchievements::on_CheckBoxCategory_Change);
                layout2->addRow(chb);
            } else {
                QComboBox* cb = new QComboBox;
                cb->addItem(Words[37]);
                for (int j=0;j<cat.object().value("values").toArray().size();j++) {
                    cb->addItem(cat.object().value("values").toArray().at(j).toString());
                }
                cb->setObjectName("Category"+QString::number(i));
                connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(on_ComboBoxCategory_Change(int)));
                layout1->addRow(new QLabel(cat.object().value("name").toString()),cb);
            }
            ui->ComboBoxCategoriesChangeCategory->addItem(cat.object().value("name").toString());
            category.close();
            }
        widget1->setLayout(layout1);
        widget2->setLayout(layout2);
        ui->ScrollAreaCategories->setWidget(widget1);
        ui->ScrollAreaCheckCategories->setWidget(widget2);

        ui->ScrollAreaCategories->setHidden((layout1->rowCount()==0)?true:false);
        ui->ScrollAreaCheckCategories->setHidden((layout2->rowCount()==0)?true:false);
    }
    bool** NewA = new bool*[ui->TableWidgetAchievements->rowCount()];
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
        NewA[i]=new bool[list.size()+3];
        for (int j=0;j<list.size()+3;j++) {
            NewA[i][j]=true;
            }
        }
    bool** NewC = new bool*[ui->TableWidgetCompareAchievements->rowCount()];
    for (int i=0;i<ui->TableWidgetCompareAchievements->rowCount();i++) {
        NewC[i]=new bool[list.size()+3];
        for (int j=0;j<list.size()+3;j++) {
            NewC[i][j]=true;
            }
        }
    colfilterAchievements=list.size()+3;
    colfilterCompare=list.size()+3;
    delete filterAchievements;
    delete filterCompare;
    filterAchievements = new bool*[ui->TableWidgetAchievements->rowCount()];
    filterAchievements = NewA;
    filterCompare = new bool*[ui->TableWidgetCompareAchievements->rowCount()];
    filterCompare = NewC;
}
void FormAchievements::UpdateHiddenRows(){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
        bool acceptA=true;
        for (int j=0;j<colfilterAchievements;j++) {
            if(filterAchievements[i][j]==false){
                acceptA=false;
                break;
            }
        }
        ui->TableWidgetAchievements->setRowHidden(i,acceptA?false:true);
    }
    for (int i=0;i<ui->TableWidgetCompareAchievements->rowCount();i++) {
        bool acceptC=true;
        for (int j=0;j<colfilterCompare;j++) {
            if(filterCompare[i][j]==false){
                acceptC=false;
                break;
            }
        }
        ui->TableWidgetCompareAchievements->setRowHidden(i,acceptC?false:true);
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
            QTableWidgetItem* item5;
            if(achievement.GetAchieved(j)==1){
                item5 = new QTableWidgetItem(Words[23]+" "+achievement.GetUnlocktime(j).toString("yyyy.MM.dd hh:mm"));
                totalr++;
                } else {
                item5 = new QTableWidgetItem(Words[24]);
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
        ui->TableWidgetCompareAchievements->setCellWidget(1,col, new QLabel(" "+QString::number(totalr)+"/"+QString::number(totalr+totalnr)+"\n "+QString::number(100.0*totalr/(totalr+totalnr))+"%"));
        return true;
    }
}
#define SystemEnd }

#define Filter {
void FormAchievements::on_LineEditNameAchievements_textChanged(const QString&){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        filterAchievements[i][0]=((ui->TableWidgetAchievements->item(i,2)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1)||(ui->TableWidgetAchievements->item(i,3)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1))?true:false;
        filterCompare[i+2][0]=((ui->TableWidgetCompareAchievements->item(i+2,2)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1)||(ui->TableWidgetCompareAchievements->item(i+2,3)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1))?true:false;
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

        ui->ComboBoxCategoriesCategory->setVisible(false);
        ui->ButtonDeleteCategory_2->setVisible(false);

        ui->GroupBoxCategories->setTitle(Words[5]);
        ui->GroupBoxCategories->setVisible(true);
    }
    //ui->GroupBoxAddCategory->setVisible(true);
//    FormAddCategory* AddCategory = new FormAddCategory(QString::number(game.GetAppid()));
//    QGridLayout* lay = new QGridLayout;
//    lay->addWidget(AddCategory);
//    lay->setSpacing(0);
//    lay->setContentsMargins(1,1,1,1);
//    ui->GroupBoxCategories->setLayout(lay);
//    ui->GroupBoxCategories->setVisible(true);
//    connect(AddCategory,&FormAddCategory::addvalue,this,&FormAchievements::CategoryAddValue);
//    connect(AddCategory,&FormAddCategory::valuechange,this,&FormAchievements::CategoryValueChange);
//    connect(AddCategory,&FormAddCategory::visiblechange,this,&FormAchievements::CategoryVisibleChange);
//    connect(AddCategory,&FormAddCategory::positionchange,this,&FormAchievements::CategoryPositionChange);
//    connect(AddCategory,&FormAddCategory::selectchange,this,&FormAchievements::CategorySelectChange);
//    connect(AddCategory,&FormAddCategory::deleting,this,&FormAchievements::CategoryDeleteValue);
//    connect(AddCategory,&FormAddCategory::accept,this,&FormAchievements::CategoryAccept);
//    connect(AddCategory,&FormAddCategory::cancel,this,&FormAchievements::CategoryCancel);
//    connect(AddCategory,&FormAddCategory::novalue,this,&FormAchievements::CategoryNoValue);
}
void FormAchievements::on_ButtonChangeCategory_clicked(){
    ui->ButtonAddCategory->setEnabled(false);
    ui->ButtonChangeCategory->setEnabled(false);
    ui->ButtonCompare->setEnabled(false);
    ui->GroupBoxChangeCategory->setVisible(true);
}
void FormAchievements::on_ButtonUpdate_clicked(){
    achievements.Update();
    PullTableWidget();
    ui->LabelGameOnline->setText(Words[27]+": "+game.GetNumberPlayers(key,true));
}
void FormAchievements::FavoritesClicked(){

}
void FormAchievements::on_ButtonCompare_clicked(){
    SwitchSimpleCompare(simpleCompare);
}
void FormAchievements::on_CheckBoxShowFilter_stateChanged(int arg1){
    ui->GroupBoxFilter->setHidden(arg1==0?true:false);
}
void FormAchievements::on_ComboBoxCategory_Change(int index){
    QComboBox* cb = qobject_cast<QComboBox*>(sender());
    QDir categories("Files/Categories/"+QString::number(game.GetAppid()));
    if(categories.exists()){
        categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        categories.setSorting(QDir::Name);
        QFileInfoList list = categories.entryInfoList();
        QFile category("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(cb->objectName().mid(8,cb->objectName().length()).toInt()).fileName());
        category.open(QFile::ReadOnly);
        QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
        QJsonArray selecteditem = cat.object().value(cb->itemText(index)).toArray();
        if(index!=0)
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                filterAchievements[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                filterCompare[i+2][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,0)->text()==selecteditem[j].toString()){
                        filterAchievements[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        filterCompare[i+2][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        break;
                        }
                    }
            } else {
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                filterAchievements[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                filterCompare[i+2][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                }
            }
        category.close();
        UpdateHiddenRows();
    }
}
void FormAchievements::on_CheckBoxCategory_Change(int ind){
    QCheckBox* cb = qobject_cast<QCheckBox*>(sender());
    QDir categories("Files/Categories/"+QString::number(game.GetAppid()));
    if(categories.exists()){
        categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        categories.setSorting(QDir::Name);
        QFileInfoList list = categories.entryInfoList();
        QFile category("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(cb->objectName().mid(8,cb->objectName().length()).toInt()).fileName());
        category.open(QFile::ReadOnly);
        QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
        QJsonArray selecteditem = cat.object().value(cat.object().value("values").toArray().at(0).toString()).toArray();
        if(ind!=0)
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                filterAchievements[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                filterCompare[i+2][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,0)->text()==selecteditem[j].toString()){
                        filterAchievements[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        filterCompare[i+2][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        break;
                        }
                    }
            } else {
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                filterAchievements[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                filterCompare[i+2][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                }
            }
        category.close();
        UpdateHiddenRows();
    }
}
#define HideColumns {
void FormAchievements::on_CheckBoxCompareIcon_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(1,arg1==0?true:false);
    ui->TableWidgetCompareAchievements->setColumnHidden(1,arg1==0?true:false);
}
void FormAchievements::on_CheckBoxCompareTitle_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(2,arg1==0?true:false);
    ui->TableWidgetCompareAchievements->setColumnHidden(2,arg1==0?true:false);
}
void FormAchievements::on_CheckBoxCompareDescription_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(3,arg1==0?true:false);
    ui->TableWidgetCompareAchievements->setColumnHidden(3,arg1==0?true:false);
}
void FormAchievements::on_CheckBoxCompareTotalPercent_stateChanged(int arg1){
    ui->TableWidgetAchievements->setColumnHidden(4,arg1==0?true:false);
    ui->TableWidgetCompareAchievements->setColumnHidden(4,arg1==0?true:false);
}
#define HideColumnsEnd }
#define NewCategory {
void FormAchievements::on_ButtonAddValueNewCategory_clicked(){
        AddValueCategory("New",newcategoryvalueslayout);
}
void FormAchievements::on_ButtonCancelNewCategory_clicked(){
    ui->TableWidgetAchievements->setColumnCount(7);
    ui->GroupBoxAddCategory->setVisible(false);
    ui->ButtonAddCategory->setEnabled(true);
    ui->ButtonCompare->setEnabled(true);
    ui->ButtonChangeCategory->setEnabled(true);
    while (!newcategoryvalueslayout->isEmpty()) {
        newcategoryvalueslayout->removeRow(0);
    }
}
void FormAchievements::on_ButtonAcceptNewCategory_clicked(){
    if(!QDir("Files/Categories/"+QString::number(game.GetAppid())).exists()){
        QDir().mkdir("Files/Categories/"+QString::number(game.GetAppid()));
    }
    if(ui->LineEditTitleNewCategory->text()!=""){
        QFile Category("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->LineEditTitleNewCategory->text()+".json");
        if(!QFile::exists("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->LineEditTitleNewCategory->text()+".json")){
            if(Category.open(QIODevice::WriteOnly)){
                QJsonDocument category;
                //QJsonArray groups;
                QJsonObject group;
                group["name"]=ui->LineEditTitleNewCategory->text();
                QJsonArray values;
                if(ui->CheckBoxNewCategoryOneValue->isChecked()){
                    if(newcategoryvalueslayout->rowCount()>0){
                        QMessageBox::StandardButton btn=QMessageBox::question(this,Words[39],Words[40].mid(0,Words[40].indexOf("\\n")-1)+"\n"+Words[40].mid(Words[40].indexOf("\\n")+2,Words[40].length()-Words[40].indexOf("\n")-2),QMessageBox::Yes|QMessageBox::No);
                        if(btn==QMessageBox::No){
                            return;
                        }
                    }
                    values.append(ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->text());
                    QJsonArray valn;
                    for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++){
                        if(ui->TableWidgetAchievements->item(j,ui->TableWidgetAchievements->columnCount()-1)->checkState()){
                            valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                            }
                        group[ui->LineEditTitleNewCategory->text()]=valn;
                        }
                    } else {
                    for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                        if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==""){
                            Category.close();
                            Category.remove();
                            QMessageBox::warning(this,Words[28],Words[29]);
                            return;
                            }
                        for (int j=7;j<i;j++){
                            if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->TableWidgetAchievements->horizontalHeaderItem(j)->text()){
                                Category.close();
                                Category.remove();
                                QMessageBox::warning(this,Words[28],Words[29]);
                                return;
                                }
                            }
                        }
                    for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                        values.append(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text());
                        QJsonArray valn;
                        for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                            if(ui->TableWidgetAchievements->item(j,i)->checkState()){
                                valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                                }
                            group[ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()]=valn;
                            }
                        }
                    }
                group["values"]=values;
                category.setObject(group);
                Category.write(category.toJson());
                Category.close();
                delete ui->ScrollAreaCategories->layout();
                delete ui->ScrollAreaCheckCategories->layout();
                ShowCategories();
                QMessageBox::information(this,Words[30],Words[31]);
                on_ButtonCancelNewCategory_clicked();
            } else
                QMessageBox::warning(this,Words[28],Words[32]);
        }
    } else
        QMessageBox::warning(this,Words[28],Words[33]);
}
void FormAchievements::on_CheckBoxNewCategoryOneValue_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        ui->ButtonAddValueNewCategory->setEnabled(true);
        ui->ScrollAreaValues->setEnabled(true);
        for (int i=0;i<ui->TableWidgetAchievements->columnCount()-7;i++) {
            ui->TableWidgetAchievements->setColumnHidden(7+i,false);
        }
        ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()-1);
        disconnect(ui->LineEditTitleNewCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_NewCategory_OneValue);
        break;
        }
    case 2:{
        ui->ButtonAddValueNewCategory->setEnabled(false);
        ui->ScrollAreaValues->setEnabled(false);
        for (int i=0;i<ui->TableWidgetAchievements->columnCount()-7;i++) {
            ui->TableWidgetAchievements->setColumnHidden(7+i,true);
        }
        ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
        ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(ui->LineEditTitleNewCategory->text()));
        for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
            QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
        }
        connect(ui->LineEditTitleNewCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_NewCategory_OneValue);
        break;
        }
    }
}
void FormAchievements::on_Change_Title_NewCategory_OneValue(){
    ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->setText(ui->LineEditTitleNewCategory->text());
}
#define NewCategoryValues {
void FormAchievements::EditLineEditNewCategoryValue(){
    QLineEdit* lied =qobject_cast<QLineEdit*>(sender());
    int i=lied->objectName().mid(20,lied->objectName().length()-20).toInt();
    ui->TableWidgetAchievements->horizontalHeaderItem(7+i)->setText(lied->text());
}
void FormAchievements::on_buttonNewCategoryUpValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(21,btn->objectName().length()-21).toInt();
    UpValueCategory("New",i);
}
void FormAchievements::on_buttonNewCategoryDownValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(23,btn->objectName().length()-23).toInt();
    UpValueCategory("New",i+1);
}
void FormAchievements::on_buttonNewCategoryDeleteValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(25,btn->objectName().length()-25).toInt();
    delete btn;
    DeleteValuesCategory("New",i,newcategoryvalueslayout);
}
void FormAchievements::on_buttonNewCategorySelectValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(25,btn->objectName().length()-25).toInt();
    SelectValueCategory(j,Qt::Checked);
}
void FormAchievements::on_buttonNewCategoryUnSelectValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(27,btn->objectName().length()-27).toInt();
    SelectValueCategory(j,Qt::Unchecked);
}
#define NewCategoryValuesEnd }
#define NewCategoryEnd }
#define ChangeCategory {
void FormAchievements::on_ComboBoxCategoriesChangeCategory_activated(int index){
    QDir categories("Files/Categories/"+QString::number(game.GetAppid()));
    if(categories.exists()){
        ui->TableWidgetAchievements->setColumnCount(7);
        ui->LineEditTitleCategoryChangeCategory->setText(ui->ComboBoxCategoriesChangeCategory->itemText(index));
        while(!changecategoryvalueslayout->isEmpty()){
            changecategoryvalueslayout->removeRow(0);
        }
        categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        categories.setSorting(QDir::Name);
        QFileInfoList list = categories.entryInfoList();
        if(index!=0){
            QFile category("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(index-1).fileName());
            category.open(QFile::ReadOnly);
            QJsonDocument categor=QJsonDocument().fromJson(category.readAll());
            ui->LineEditTitleCategoryChangeCategory->setEnabled(true);
            for (int i=0;i<categor.object().value("values").toArray().size();i++) {
                QHBoxLayout* bl = new QHBoxLayout;
                QPushButton* btn = new QPushButton;
                QLineEdit* val = new QLineEdit(categor.object().value("values").toArray().at(i).toString());
                QPushButton* up = new QPushButton();
                QPushButton* down = new QPushButton();
                QPushButton* select = new QPushButton();
                QPushButton* unselect = new QPushButton();
                btn->setObjectName("btnChangeCategoryDeleteValue"+QString::number(changecategoryvalueslayout->rowCount()));
                val->setObjectName("liedChangeCategoryValue"+QString::number(changecategoryvalueslayout->rowCount()));
                up->setObjectName("btnChangeCategoryUpValue"+QString::number(changecategoryvalueslayout->rowCount()));
                down->setObjectName("btnChangeCategoryDownValue"+QString::number(changecategoryvalueslayout->rowCount()));
                select->setObjectName("btnChangeCategorySelectValue"+QString::number(changecategoryvalueslayout->rowCount()));
                unselect->setObjectName("btnChangeCategoryUnSelectValue"+QString::number(changecategoryvalueslayout->rowCount()));
                if(i==0) up->setEnabled(false);
                if(i==categor.object().value("values").toArray().size()-1) down->setEnabled(false);
                btn->setIcon(QIcon(":/program/program/delete.png"));
                //select->setIcon();
                //unselect->setIcon();
                up->setIcon(QIcon(":/"+theme+"/program/"+theme+"/up.png"));
                down->setIcon(QIcon(":/"+theme+"/program/"+theme+"/down.png"));
                connect(btn,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryDeleteValues_clicked);
                connect(val,&QLineEdit::editingFinished,this,&FormAchievements::EditLineEditChangeCategoryValue);
                connect(up,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryUpValues_clicked);
                connect(down,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryDownValues_clicked);
                connect(select,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategorySelectValues_clicked);
                connect(unselect,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryUnSelectValues_clicked);
                //changecategoryvalueslayout->addRow(categor.object().value("values").toArray().at(i).toString(),btn);
                bl->addWidget(val);
                bl->addWidget(up);
                bl->addWidget(down);
                bl->addWidget(select);
                bl->addWidget(unselect);
                bl->addWidget(btn);
                bl->setMargin(0);
                QWidget* Wbl = new QWidget;
                Wbl->setLayout(bl);
//                changecategoryvalueslayout->addWidget(val,i,0);
//                changecategoryvalueslayout->addWidget(up,i,1);
//                changecategoryvalueslayout->addWidget(down,i,2);
//                changecategoryvalueslayout->addWidget(btn,i,3);
                changecategoryvalueslayout->addRow(Wbl);
                ui->TableWidgetAchievements->insertColumn(ui->TableWidgetAchievements->columnCount());
                ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(categor.object().value("values").toArray().at(i).toString()));
                for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                    QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
                    pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
                    bool accept=true;
                    for (int k=0;k<categor.object().value(categor.object().value("values").toArray().at(i).toString()).toArray().size();k++) {
                        if(ui->TableWidgetAchievements->item(j,0)->text()==categor.object().value(categor.object().value("values").toArray().at(i).toString()).toArray().at(k).toString()){
                            accept=false;
                            break;
                        }
                    }
                    pItem->setCheckState(accept?Qt::Unchecked:Qt::Checked);
                    ui->TableWidgetAchievements->setItem(j,ui->TableWidgetAchievements->columnCount()-1, pItem);
                }
            }
            category.close();
        } else {
            ui->LineEditTitleCategoryChangeCategory->setEnabled(false);
        }
    }
}
void FormAchievements::on_ButtonAddValueChangeCategory_clicked(){
    AddValueCategory("Change",changecategoryvalueslayout);
}
void FormAchievements::on_ButtonCancelChangeCategory_clicked(){
    ui->TableWidgetAchievements->setColumnCount(7);
    ui->GroupBoxChangeCategory->setVisible(false);
    ui->ButtonAddCategory->setEnabled(true);
    ui->ButtonCompare->setEnabled(true);
    ui->ButtonChangeCategory->setEnabled(true);
    ui->ComboBoxCategoriesChangeCategory->setCurrentIndex(0);
    ui->LineEditTitleCategoryChangeCategory->setText("");
    ui->LineEditTitleCategoryChangeCategory->setEnabled(false);
    while(!changecategoryvalueslayout->isEmpty()){
        changecategoryvalueslayout->removeRow(0);
    }
}
void FormAchievements::on_ButtonDeleteCategory_clicked(){
    QMessageBox::StandardButton btn=QMessageBox::question(this,Words[39],Words[41],QMessageBox::Yes|QMessageBox::No);
    if(btn==QMessageBox::No){
        return;
    }
    QDir categories("Files/Categories/"+QString::number(game.GetAppid()));
    delete ui->ScrollAreaCategories->layout();
    delete ui->ScrollAreaCheckCategories->layout();
        if(categories.exists()){
            if(ui->ComboBoxCategoriesChangeCategory->currentIndex()!=0){
            if(QFile("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->ComboBoxCategoriesChangeCategory->currentText()+".json").exists()){
                QFile("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->ComboBoxCategoriesChangeCategory->currentText()+".json").remove();
                }
            ShowCategories();
            ui->LineEditNameAchievements->setText("");
            ui->RadioButtonAll->setChecked(true);
            ui->CheckBoxFavorites->setChecked(false);
            QMessageBox::information(this,Words[30],Words[35]);
            on_ButtonCancelChangeCategory_clicked();
            }
        }
}
void FormAchievements::on_ButtonAcceptChangeCategory_clicked(){
    if(!QDir("Files/Categories/"+QString::number(game.GetAppid())).exists()){
        QDir().mkdir("Files/Categories/"+QString::number(game.GetAppid()));
    }
    if(ui->LineEditTitleCategoryChangeCategory->text()!=""){
        if(ui->LineEditTitleCategoryChangeCategory->text()!=ui->ComboBoxCategoriesChangeCategory->currentText()){
            if(QFile::exists("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->ComboBoxCategoriesChangeCategory->currentText()+".json")){
                QFile("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->ComboBoxCategoriesChangeCategory->currentText()+".json").remove();
            }
        }
        QFile Category("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->LineEditTitleCategoryChangeCategory->text()+".json");
        if((!QFile::exists("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->LineEditTitleCategoryChangeCategory->text()+".json"))||(ui->LineEditTitleCategoryChangeCategory->text()==ui->ComboBoxCategoriesChangeCategory->currentText())){
            QJsonDocument category;
            QJsonArray groups;
            QJsonObject group;
            group["name"]=ui->LineEditTitleCategoryChangeCategory->text();
            QJsonArray values;
            if(ui->CheckBoxChangeCategoryOneValue->isChecked()){
                if(changecategoryvalueslayout->rowCount()>0){
                    QMessageBox::StandardButton btn=QMessageBox::question(this,Words[39],Words[40].mid(0,Words[40].indexOf("\\n")-1)+"\n"+Words[40].mid(Words[40].indexOf("\\n")+2,Words[40].length()-Words[40].indexOf("\n")-2),QMessageBox::Yes|QMessageBox::No);
                    if(btn==QMessageBox::No){
                        return;
                    }
                }
                Category.open(QIODevice::WriteOnly);
                values.append(ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->text());
                QJsonArray valn;
                for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++){
                    if(ui->TableWidgetAchievements->item(j,ui->TableWidgetAchievements->columnCount()-1)->checkState()){
                        valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                        }
                    group[ui->LineEditTitleCategoryChangeCategory->text()]=valn;
                    }
            } else {
                for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                    if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==""){
                        Category.close();
                        QMessageBox::warning(this,Words[28],Words[29]);
                        return;
                        }
                    for (int j=7;j<i;j++) {
                        if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->TableWidgetAchievements->horizontalHeaderItem(j)->text()){
                            Category.close();
                            QMessageBox::warning(this,Words[28],Words[29]);
                            return;
                            }
                        }
                    }
                Category.open(QIODevice::WriteOnly);
                for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                    values.append(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text());
                    QJsonArray valn;
                    for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                        if(ui->TableWidgetAchievements->item(j,i)->checkState()){
                            valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                            }
                        group[ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()]=valn;
                        }
                    }
                }
            group["values"]=values;
            category.setObject(group);
            Category.write(category.toJson());
            Category.close();
            ui->LineEditTitleCategoryChangeCategory->setText("");
            ui->LineEditTitleCategoryChangeCategory->setEnabled(false);
            delete ui->ScrollAreaCategories->layout();
            delete ui->ScrollAreaCheckCategories->layout();
            ShowCategories();
            ui->LineEditNameAchievements->setText("");
            ui->RadioButtonAll->setChecked(true);
            ui->CheckBoxFavorites->setChecked(false);
            QMessageBox::information(this,Words[30],Words[34]);
            on_ButtonCancelChangeCategory_clicked();
            } else
                QMessageBox::warning(this,Words[28],Words[32]);
        } else
            QMessageBox::warning(this,Words[28],Words[33]);
}
void FormAchievements::on_CheckBoxChangeCategoryOneValue_stateChanged(int arg1){
    switch (arg1) {
    case 0:{
        ui->ButtonAddValueChangeCategory->setEnabled(true);
        ui->ScrollAreaValuesChangeCategory->setEnabled(true);
        for (int i=0;i<ui->TableWidgetAchievements->columnCount()-7;i++) {
            ui->TableWidgetAchievements->setColumnHidden(7+i,false);
        }
        ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()-1);
        disconnect(ui->LineEditTitleCategoryChangeCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_ChangeCategory_OneValue);
        break;
        }
    case 2:{
        ui->ButtonAddValueChangeCategory->setEnabled(false);
        ui->ScrollAreaValuesChangeCategory->setEnabled(false);
        for (int i=0;i<ui->TableWidgetAchievements->columnCount()-7;i++) {
            ui->TableWidgetAchievements->setColumnHidden(7+i,true);
        }
        ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
        ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(ui->LineEditTitleCategoryChangeCategory->text()));
        for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
            QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
        }
        connect(ui->LineEditTitleCategoryChangeCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_ChangeCategory_OneValue);
        break;
        }
    }
}
void FormAchievements::on_Change_Title_ChangeCategory_OneValue(){
    ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->setText(ui->LineEditTitleCategoryChangeCategory->text());
}
#define ChangeCategoryValues {
void FormAchievements::EditLineEditChangeCategoryValue(){
    QLineEdit* lied =qobject_cast<QLineEdit*>(sender());
    int i=lied->objectName().mid(23,lied->objectName().length()-23).toInt();
    ui->TableWidgetAchievements->horizontalHeaderItem(7+i)->setText(lied->text());
}
void FormAchievements::on_buttonChangeCategoryUpValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(24,btn->objectName().length()-24).toInt();
    UpValueCategory("Change",i);
}
void FormAchievements::on_buttonChangeCategoryDownValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(26,btn->objectName().length()-26).toInt();
    UpValueCategory("Change",i+1);
}
void FormAchievements::on_buttonChangeCategoryDeleteValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(28,btn->objectName().length()-28).toInt();
    delete btn;
    DeleteValuesCategory("Change",i,changecategoryvalueslayout);
}
void FormAchievements::on_buttonChangeCategorySelectValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(28,btn->objectName().length()-28).toInt();
    SelectValueCategory(j,Qt::Checked);
}
void FormAchievements::on_buttonChangeCategoryUnSelectValues_clicked(){
    QPushButton* btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(30,btn->objectName().length()-30).toInt();
    SelectValueCategory(j,Qt::Unchecked);
}
#define ChangeCategoryValuesEnd }
#define ChangeCategoryEnd }
#define Categorys {
void FormAchievements::CategoryAddValue(int){
    ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
    ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem());
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
        ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
        }
}
void FormAchievements::CategoryValueChange(int pos, QString value){
    ui->TableWidgetAchievements->horizontalHeaderItem(7+pos)->setText(value);
}
void FormAchievements::CategoryVisibleChange(int pos, bool visible){
    ui->TableWidgetAchievements->setColumnHidden(7+pos,!visible);
}
void FormAchievements::CategoryPositionChange(int pos, int posnew){
    if(posnew<0||posnew>ui->TableWidgetAchievements->columnCount()-7){
        QMessageBox::warning(this,"","Невозможно переместить значение");
    } else {
        for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
            Qt::CheckState pItem1 = ui->TableWidgetAchievements->item(j,7+pos)->checkState();
            ui->TableWidgetAchievements->item(j,7+pos)->setCheckState(ui->TableWidgetAchievements->item(j,7+posnew)->checkState());
            ui->TableWidgetAchievements->item(j,7+posnew)->setCheckState(pItem1);
        }
        QString hh=ui->TableWidgetAchievements->horizontalHeaderItem(7+pos)->text();
        ui->TableWidgetAchievements->horizontalHeaderItem(7+pos)->setText(ui->TableWidgetAchievements->horizontalHeaderItem(7+posnew)->text());
        ui->TableWidgetAchievements->horizontalHeaderItem(7+posnew)->setText(hh);
    }
}
void FormAchievements::CategorySelectChange(int pos, bool select){
    ui->TableWidgetAchievements->selectColumn(2);
    QList<QTableWidgetItem*> rows = ui->TableWidgetAchievements->selectedItems();
    for (int i=0;i<rows.size();i++) {
        ui->TableWidgetAchievements->item(rows.at(i)->row(),7+pos)->setCheckState(select?Qt::Checked:Qt::Unchecked);
    }
    ui->TableWidgetAchievements->selectColumn(0);
}
void FormAchievements::CategoryDeleteValue(int pos){

}
void FormAchievements::CategoryAccept(){
    QString title="";
    QWidget* Form = ui->GroupBoxCategories->layout()->takeAt(0)->widget();
    if(QString(Form->metaObject()->className())=="FormAddCategory"){
        title=dynamic_cast<FormAddCategory*>(Form)->GetTitle();
    }
    QFile Category("Files/Categories/"+QString::number(game.GetAppid())+"/"+title+".json");
    if(Category.open(QIODevice::WriteOnly)){
        QJsonDocument category;
        QJsonArray groups;
        QJsonObject group;
        group["name"]=title;
        QJsonArray values;
        if(ui->CheckBoxNewCategoryOneValue->isChecked()){
            if(newcategoryvalueslayout->rowCount()>0){
                QMessageBox::StandardButton btn=QMessageBox::question(this,Words[39],Words[40].mid(0,Words[40].indexOf("\\n")-1)+"\n"+Words[40].mid(Words[40].indexOf("\\n")+2,Words[40].length()-Words[40].indexOf("\n")-2),QMessageBox::Yes|QMessageBox::No);
                if(btn==QMessageBox::No){
                    return;
                }
            }
            values.append(ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->text());
            QJsonArray valn;
            for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++){
                if(ui->TableWidgetAchievements->item(j,ui->TableWidgetAchievements->columnCount()-1)->checkState()){
                    valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                    }
                group[title]=valn;
                }
            } else {
            for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==""){
                    Category.close();
                    Category.remove();
                    QMessageBox::warning(this,Words[28],Words[29]);
                    return;
                    }
                for (int j=7;j<i;j++){
                    if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->TableWidgetAchievements->horizontalHeaderItem(j)->text()){
                        Category.close();
                        Category.remove();
                        QMessageBox::warning(this,Words[28],Words[29]);
                        return;
                        }
                    }
                }
            for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                values.append(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text());
                QJsonArray valn;
                for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                    if(ui->TableWidgetAchievements->item(j,i)->checkState()){
                        valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                        }
                    group[ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()]=valn;
                    }
                }
            }
        group["values"]=values;
        category.setObject(group);
        Category.write(category.toJson());
        Category.close();
        delete ui->ScrollAreaCategories->layout();
        delete ui->ScrollAreaCheckCategories->layout();
        ShowCategories();
        QMessageBox::information(this,Words[30],Words[31]);
        CategoryCancel();
    }
}
void FormAchievements::CategoryCancel(){
    ui->TableWidgetAchievements->setColumnCount(7);
    ui->GroupBoxCategories->setVisible(false);
    ui->ButtonAddCategory->setEnabled(true);
    ui->ButtonCompare->setEnabled(true);
    ui->ButtonChangeCategory->setEnabled(true);
    delete ui->GroupBoxCategories->layout()->takeAt(0);
}
void FormAchievements::CategoryNoValue(bool novalue){
    for (int i=8;i<ui->TableWidgetAchievements->columnCount();i++) {
        ui->TableWidgetAchievements->setColumnHidden(i,novalue);
    }
    if(novalue) {
        ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
        ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(ui->LineEditTitleNewCategory->text()));
        for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
            QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
        }
        connect(ui->LineEditTitleNewCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_NewCategory_OneValue);
    } else {
        ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()-1);
        disconnect(ui->LineEditTitleNewCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_NewCategory_OneValue);
    }
}
void FormAchievements::AddValueCategory(QString Type, QFormLayout* layout){
    ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
    ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem());
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
        ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
        }
    QHBoxLayout* bl = new QHBoxLayout;
    QPushButton* btn = new QPushButton;
    QLineEdit* val = new QLineEdit();
    QPushButton* up = new QPushButton();
    QPushButton* down = new QPushButton();
    QPushButton* select = new QPushButton();
    QPushButton* unselect = new QPushButton();
    int row = layout->rowCount();
    btn->setObjectName("btn"+Type+"CategoryDeleteValue"+QString::number(row));
    val->setObjectName("lied"+Type+"CategoryValue"+QString::number(row));
    up->setObjectName("btn"+Type+"CategoryUpValue"+QString::number(row));
    down->setObjectName("btn"+Type+"CategoryDownValue"+QString::number(row));
    select->setObjectName("btn"+Type+"CategorySelectValue"+QString::number(row));
    unselect->setObjectName("btn"+Type+"CategoryUnSelectValue"+QString::number(row));
    if(row==0){
        up->setEnabled(false);
    } else {
        findChild<QPushButton*>("btn"+Type+"CategoryDownValue"+QString::number(row-1))->setEnabled(true);
    }
    down->setEnabled(false);
    btn->setIcon(QIcon(":/program/program/delete.png"));
    //select->setIcon();
    //unselect->setIcon();
    up->setIcon(QIcon(":/"+theme+"/program/"+theme+"/up.png"));
    down->setIcon(QIcon(":/"+theme+"/program/"+theme+"/down.png"));
    if(Type=="New"){
        connect(btn,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategoryDeleteValues_clicked);
        connect(val,&QLineEdit::editingFinished,this,&FormAchievements::EditLineEditNewCategoryValue);
        connect(up,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategoryUpValues_clicked);
        connect(down,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategoryDownValues_clicked);
        connect(select,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategorySelectValues_clicked);
        connect(unselect,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategoryUnSelectValues_clicked);
    } else {
        if(Type=="Change"){
            connect(btn,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryDeleteValues_clicked);
            connect(val,&QLineEdit::editingFinished,this,&FormAchievements::EditLineEditChangeCategoryValue);
            connect(up,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryUpValues_clicked);
            connect(down,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryDownValues_clicked);
            connect(select,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategorySelectValues_clicked);
            connect(unselect,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryUnSelectValues_clicked);
        }
    }
    bl->addWidget(val);
    bl->addWidget(up);
    bl->addWidget(down);
    bl->addWidget(select);
    bl->addWidget(unselect);
    bl->addWidget(btn);
    bl->setMargin(0);
    QWidget* Wbl = new QWidget;
    Wbl->setLayout(bl);
    layout->addRow(Wbl);
//    } else
//        QMessageBox::warning(this,Words[28],Words[29]);
}
void FormAchievements::UpValueCategory(QString Type, int i){
    if(i==0){
        QMessageBox::warning(this,"","Невозможно переместить значение");
    } else {
        for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
            Qt::CheckState pItem1 = ui->TableWidgetAchievements->item(j,7+i)->checkState();
            ui->TableWidgetAchievements->item(j,7+i)->setCheckState(ui->TableWidgetAchievements->item(j,6+i)->checkState());
            ui->TableWidgetAchievements->item(j,6+i)->setCheckState(pItem1);
        }
        QString hh=ui->TableWidgetAchievements->horizontalHeaderItem(7+i)->text();
        ui->TableWidgetAchievements->horizontalHeaderItem(7+i)->setText(ui->TableWidgetAchievements->horizontalHeaderItem(6+i)->text());
        ui->TableWidgetAchievements->horizontalHeaderItem(6+i)->setText(hh);
        QString text=findChild<QLineEdit*>("lied"+Type+"CategoryValue"+QString::number(i))->text();
        findChild<QLineEdit*>("lied"+Type+"CategoryValue"+QString::number(i))->setText(findChild<QLineEdit*>("lied"+Type+"CategoryValue"+QString::number(i-1))->text());
        findChild<QLineEdit*>("lied"+Type+"CategoryValue"+QString::number(i-1))->setText(text);
    }
}
void FormAchievements::DownValueCategory(QString Type, int i, QFormLayout* layout){
    if(i==layout->rowCount()){
        QMessageBox::warning(this,"","Невозможно переместить значение");
    } else {
        for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
            Qt::CheckState pItem1 = ui->TableWidgetAchievements->item(j,7+i)->checkState();
            ui->TableWidgetAchievements->item(j,7+i)->setCheckState(ui->TableWidgetAchievements->item(j,8+i)->checkState());
            ui->TableWidgetAchievements->item(j,8+i)->setCheckState(pItem1);
        }
        QString hh=ui->TableWidgetAchievements->horizontalHeaderItem(7+i)->text();
        ui->TableWidgetAchievements->horizontalHeaderItem(7+i)->setText(ui->TableWidgetAchievements->horizontalHeaderItem(8+i)->text());
        ui->TableWidgetAchievements->horizontalHeaderItem(8+i)->setText(hh);
        QString text=findChild<QLineEdit*>("lied"+Type+"CategoryValue"+QString::number(i))->text();
        findChild<QLineEdit*>("lied"+Type+"CategoryValue"+QString::number(i))->setText(findChild<QLineEdit*>("lied"+Type+"CategoryValue"+QString::number(i+1))->text());
        findChild<QLineEdit*>("lied"+Type+"CategoryValue"+QString::number(i+1))->setText(text);
    }
}
void FormAchievements::DeleteValuesCategory(QString Type, int i, QFormLayout* layout){
    if(i==0)
        findChild<QPushButton*>("btn"+Type+"CategoryUpValue"+QString::number(1))->setEnabled(false);
    if(i==layout->rowCount()-1)
        findChild<QPushButton*>("btn"+Type+"CategoryDownValue"+QString::number(i-1))->setEnabled(false);
    ui->TableWidgetAchievements->removeColumn(7+i);
    //утечка данных (надо удалить еще 2 кнопки, лайнэдит, лейаут и виджет
    layout->removeRow(i++);
    while(i<layout->rowCount()+1){
        QPushButton* butn = findChild<QPushButton*>("btn"+Type+"CategoryDeleteValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btn"+Type+"CategoryDeleteValue"+QString::number(i-1));
        QLineEdit* lied = findChild<QLineEdit*>("lied"+Type+"CategoryValue"+QString::number(i));
        if(lied)
            lied->setObjectName("lied"+Type+"CategoryValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btn"+Type+"CategoryUpValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btn"+Type+"CategoryUpValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btn"+Type+"CategoryDownValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btn"+Type+"CategoryDownValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btn"+Type+"CategorySelectValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btn"+Type+"CategorySelectValue"+QString::number(i-1));
        butn = findChild<QPushButton*>("btn"+Type+"CategoryUnSelectValue"+QString::number(i));
        if(butn)
            butn->setObjectName("btn"+Type+"CategoryUnSelectValue"+QString::number(i-1));
        i++;
    }
}
void FormAchievements::SelectValueCategory(int j,Qt::CheckState CS){
    ui->TableWidgetAchievements->selectColumn(2);
    QList<QTableWidgetItem*> rows = ui->TableWidgetAchievements->selectedItems();
    for (int i=0;i<rows.size();i++) {
        ui->TableWidgetAchievements->item(rows.at(i)->row(),7+j)->setCheckState(CS);
    }
    ui->TableWidgetAchievements->selectColumn(0);
}
#define CategoryEnd }
#define FilterEnd }

void FormAchievements::returnfromcompare(){
    windowchildcount--;
    this->setVisible(true);
    //delete compareform;
}
void FormAchievements::on_ButtonReturn_clicked(){
    emit return_to_games(unicnum);
    //delete this;
}
void FormAchievements::on_ComboBoxCategoriesCategory_currentIndexChanged(int index){

}
void FormAchievements::on_LineEditTitleCategoryChangeCategory_editingFinished(){

}

void FormAchievements::on_ButtonAddValueCategory_clicked(){
    if((typecategory==1)||(typecategory==2)){
        ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
        ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem());
        for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
            QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
            ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
            }
        int row = categoryvalueslayout->rowCount();
        FormCategoryValue *Value = new FormCategoryValue(row);
        Values.append(Value);
        switch (row) {
        case 0:{
            Value->setFirstLast(-2);
            break;
        }
        case 1:{
            Values[row-1]->setFirstLast(-1);
            Value->setFirstLast(1);
            break;
        }
        default:{
            Values[row-1]->setFirstLast(0);
            Value->setFirstLast(1);
        }
        }
//            connect(btn,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategoryDeleteValues_clicked);
//            connect(val,&QLineEdit::editingFinished,this,&FormAchievements::EditLineEditNewCategoryValue);
//            connect(up,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategoryUpValues_clicked);
//            connect(down,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategoryDownValues_clicked);
//            connect(select,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategorySelectValues_clicked);
//            connect(unselect,&QPushButton::clicked,this,&FormAchievements::on_buttonNewCategoryUnSelectValues_clicked);

        categoryvalueslayout->addRow(Value);
    }
}

void FormAchievements::on_CheckBoxCategoryOneValue_stateChanged(int arg1){
    if(typecategory==1){
        switch (arg1) {
        case 0:{
            ui->ButtonAddValueNewCategory->setEnabled(true);
            ui->ScrollAreaValues->setEnabled(true);
            for (int i=0;i<ui->TableWidgetAchievements->columnCount()-7;i++) {
                ui->TableWidgetAchievements->setColumnHidden(7+i,false);
            }
            ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()-1);
            disconnect(ui->LineEditTitleNewCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_NewCategory_OneValue);
            break;
            }
        case 2:{
            ui->ButtonAddValueNewCategory->setEnabled(false);
            ui->ScrollAreaValues->setEnabled(false);
            for (int i=0;i<ui->TableWidgetAchievements->columnCount()-7;i++) {
                ui->TableWidgetAchievements->setColumnHidden(7+i,true);
            }
            ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
            ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(ui->LineEditTitleNewCategory->text()));
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
                pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
                pItem->setCheckState(Qt::Unchecked);
                ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
            }
            connect(ui->LineEditTitleNewCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_NewCategory_OneValue);
            break;
            }
        }
    } else if(typecategory==2){
        switch (arg1) {
        case 0:{
            ui->ButtonAddValueChangeCategory->setEnabled(true);
            ui->ScrollAreaValuesChangeCategory->setEnabled(true);
            for (int i=0;i<ui->TableWidgetAchievements->columnCount()-7;i++) {
                ui->TableWidgetAchievements->setColumnHidden(7+i,false);
            }
            ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()-1);
            disconnect(ui->LineEditTitleCategoryChangeCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_ChangeCategory_OneValue);
            break;
            }
        case 2:{
            ui->ButtonAddValueChangeCategory->setEnabled(false);
            ui->ScrollAreaValuesChangeCategory->setEnabled(false);
            for (int i=0;i<ui->TableWidgetAchievements->columnCount()-7;i++) {
                ui->TableWidgetAchievements->setColumnHidden(7+i,true);
            }
            ui->TableWidgetAchievements->setColumnCount(ui->TableWidgetAchievements->columnCount()+1);
            ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(ui->LineEditTitleCategoryChangeCategory->text()));
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
                QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
                pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
                pItem->setCheckState(Qt::Unchecked);
                ui->TableWidgetAchievements->setItem(i,ui->TableWidgetAchievements->columnCount()-1, pItem);
            }
            connect(ui->LineEditTitleCategoryChangeCategory,&QLineEdit::editingFinished,this,&FormAchievements::on_Change_Title_ChangeCategory_OneValue);
            break;
            }
        }
    }
}

void FormAchievements::on_ButtonCancelCategory_clicked(){
    if(typecategory==1){
        ui->TableWidgetAchievements->setColumnCount(7);
        ui->GroupBoxAddCategory->setVisible(false);
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonCompare->setEnabled(true);
        ui->ButtonChangeCategory->setEnabled(true);
        while (!newcategoryvalueslayout->isEmpty()) {
            newcategoryvalueslayout->removeRow(0);
        }
    } else if(typecategory==2){
        ui->TableWidgetAchievements->setColumnCount(7);
        ui->GroupBoxChangeCategory->setVisible(false);
        ui->ButtonAddCategory->setEnabled(true);
        ui->ButtonCompare->setEnabled(true);
        ui->ButtonChangeCategory->setEnabled(true);
        ui->ComboBoxCategoriesChangeCategory->setCurrentIndex(0);
        ui->LineEditTitleCategoryChangeCategory->setText("");
        ui->LineEditTitleCategoryChangeCategory->setEnabled(false);
        while(!changecategoryvalueslayout->isEmpty()){
            changecategoryvalueslayout->removeRow(0);
        }
    }
}

void FormAchievements::on_ButtonDeleteCategory_2_clicked(){
    if(typecategory==2){
        QPushButton* btn =qobject_cast<QPushButton*>(sender());
        int i=btn->objectName().mid(28,btn->objectName().length()-28).toInt();
        delete btn;
        DeleteValuesCategory("Change",i,changecategoryvalueslayout);
    }
}

void FormAchievements::on_ButtonAcceptCategory_clicked(){
    if(typecategory==1){
        if(!QDir("Files/Categories/"+QString::number(game.GetAppid())).exists()){
            QDir().mkdir("Files/Categories/"+QString::number(game.GetAppid()));
        }
        if(ui->LineEditTitleNewCategory->text()!=""){
            QFile Category("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->LineEditTitleNewCategory->text()+".json");
            if(!QFile::exists("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->LineEditTitleNewCategory->text()+".json")){
                if(Category.open(QIODevice::WriteOnly)){
                    QJsonDocument category;
                    //QJsonArray groups;
                    QJsonObject group;
                    group["name"]=ui->LineEditTitleNewCategory->text();
                    QJsonArray values;
                    if(ui->CheckBoxNewCategoryOneValue->isChecked()){
                        if(newcategoryvalueslayout->rowCount()>0){
                            QMessageBox::StandardButton btn=QMessageBox::question(this,Words[39],Words[40].mid(0,Words[40].indexOf("\\n")-1)+"\n"+Words[40].mid(Words[40].indexOf("\\n")+2,Words[40].length()-Words[40].indexOf("\n")-2),QMessageBox::Yes|QMessageBox::No);
                            if(btn==QMessageBox::No){
                                return;
                            }
                        }
                        values.append(ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->text());
                        QJsonArray valn;
                        for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++){
                            if(ui->TableWidgetAchievements->item(j,ui->TableWidgetAchievements->columnCount()-1)->checkState()){
                                valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                                }
                            group[ui->LineEditTitleNewCategory->text()]=valn;
                            }
                        } else {
                        for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                            if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==""){
                                Category.close();
                                Category.remove();
                                QMessageBox::warning(this,Words[28],Words[29]);
                                return;
                                }
                            for (int j=7;j<i;j++){
                                if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->TableWidgetAchievements->horizontalHeaderItem(j)->text()){
                                    Category.close();
                                    Category.remove();
                                    QMessageBox::warning(this,Words[28],Words[29]);
                                    return;
                                    }
                                }
                            }
                        for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                            values.append(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text());
                            QJsonArray valn;
                            for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                                if(ui->TableWidgetAchievements->item(j,i)->checkState()){
                                    valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                                    }
                                group[ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()]=valn;
                                }
                            }
                        }
                    group["values"]=values;
                    category.setObject(group);
                    Category.write(category.toJson());
                    Category.close();
                    delete ui->ScrollAreaCategories->layout();
                    delete ui->ScrollAreaCheckCategories->layout();
                    ShowCategories();
                    QMessageBox::information(this,Words[30],Words[31]);
                    on_ButtonCancelNewCategory_clicked();
                } else
                    QMessageBox::warning(this,Words[28],Words[32]);
            }
        } else
            QMessageBox::warning(this,Words[28],Words[33]);
    } else if(typecategory==2){
        if(!QDir("Files/Categories/"+QString::number(game.GetAppid())).exists()){
            QDir().mkdir("Files/Categories/"+QString::number(game.GetAppid()));
        }
        if(ui->LineEditTitleCategoryChangeCategory->text()!=""){
            if(ui->LineEditTitleCategoryChangeCategory->text()!=ui->ComboBoxCategoriesChangeCategory->currentText()){
                if(QFile::exists("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->ComboBoxCategoriesChangeCategory->currentText()+".json")){
                    QFile("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->ComboBoxCategoriesChangeCategory->currentText()+".json").remove();
                }
            }
            QFile Category("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->LineEditTitleCategoryChangeCategory->text()+".json");
            if((!QFile::exists("Files/Categories/"+QString::number(game.GetAppid())+"/"+ui->LineEditTitleCategoryChangeCategory->text()+".json"))||(ui->LineEditTitleCategoryChangeCategory->text()==ui->ComboBoxCategoriesChangeCategory->currentText())){
                QJsonDocument category;
                QJsonArray groups;
                QJsonObject group;
                group["name"]=ui->LineEditTitleCategoryChangeCategory->text();
                QJsonArray values;
                if(ui->CheckBoxChangeCategoryOneValue->isChecked()){
                    if(changecategoryvalueslayout->rowCount()>0){
                        QMessageBox::StandardButton btn=QMessageBox::question(this,Words[39],Words[40].mid(0,Words[40].indexOf("\\n")-1)+"\n"+Words[40].mid(Words[40].indexOf("\\n")+2,Words[40].length()-Words[40].indexOf("\n")-2),QMessageBox::Yes|QMessageBox::No);
                        if(btn==QMessageBox::No){
                            return;
                        }
                    }
                    Category.open(QIODevice::WriteOnly);
                    values.append(ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->text());
                    QJsonArray valn;
                    for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++){
                        if(ui->TableWidgetAchievements->item(j,ui->TableWidgetAchievements->columnCount()-1)->checkState()){
                            valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                            }
                        group[ui->LineEditTitleCategoryChangeCategory->text()]=valn;
                        }
                } else {
                    for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                        if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==""){
                            Category.close();
                            QMessageBox::warning(this,Words[28],Words[29]);
                            return;
                            }
                        for (int j=7;j<i;j++) {
                            if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->TableWidgetAchievements->horizontalHeaderItem(j)->text()){
                                Category.close();
                                QMessageBox::warning(this,Words[28],Words[29]);
                                return;
                                }
                            }
                        }
                    Category.open(QIODevice::WriteOnly);
                    for (int i=7;i<ui->TableWidgetAchievements->columnCount();i++){
                        values.append(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text());
                        QJsonArray valn;
                        for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                            if(ui->TableWidgetAchievements->item(j,i)->checkState()){
                                valn.append(ui->TableWidgetAchievements->item(j,0)->text());
                                }
                            group[ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()]=valn;
                            }
                        }
                    }
                group["values"]=values;
                category.setObject(group);
                Category.write(category.toJson());
                Category.close();
                ui->LineEditTitleCategoryChangeCategory->setText("");
                ui->LineEditTitleCategoryChangeCategory->setEnabled(false);
                delete ui->ScrollAreaCategories->layout();
                delete ui->ScrollAreaCheckCategories->layout();
                ShowCategories();
                ui->LineEditNameAchievements->setText("");
                ui->RadioButtonAll->setChecked(true);
                ui->CheckBoxFavorites->setChecked(false);
                QMessageBox::information(this,Words[30],Words[34]);
                on_ButtonCancelChangeCategory_clicked();
                } else
                    QMessageBox::warning(this,Words[28],Words[32]);
            } else
                QMessageBox::warning(this,Words[28],Words[33]);
    }
}

void FormAchievements::on_ComboBoxCategoriesCategory_activated(int index){
    if(typecategory==2){
        QDir categories("Files/Categories/"+QString::number(game.GetAppid()));
        if(categories.exists()){
            ui->TableWidgetAchievements->setColumnCount(7);
            ui->LineEditTitleCategoryChangeCategory->setText(ui->ComboBoxCategoriesChangeCategory->itemText(index));
            while(!changecategoryvalueslayout->isEmpty()){
                changecategoryvalueslayout->removeRow(0);
            }
            categories.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
            categories.setSorting(QDir::Name);
            QFileInfoList list = categories.entryInfoList();
            if(index!=0){
                QFile category("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(index-1).fileName());
                category.open(QFile::ReadOnly);
                QJsonDocument categor=QJsonDocument().fromJson(category.readAll());
                ui->LineEditTitleCategoryChangeCategory->setEnabled(true);
                for (int i=0;i<categor.object().value("values").toArray().size();i++) {
                    QHBoxLayout* bl = new QHBoxLayout;
                    QPushButton* btn = new QPushButton;
                    QLineEdit* val = new QLineEdit(categor.object().value("values").toArray().at(i).toString());
                    QPushButton* up = new QPushButton();
                    QPushButton* down = new QPushButton();
                    QPushButton* select = new QPushButton();
                    QPushButton* unselect = new QPushButton();
                    btn->setObjectName("btnChangeCategoryDeleteValue"+QString::number(changecategoryvalueslayout->rowCount()));
                    val->setObjectName("liedChangeCategoryValue"+QString::number(changecategoryvalueslayout->rowCount()));
                    up->setObjectName("btnChangeCategoryUpValue"+QString::number(changecategoryvalueslayout->rowCount()));
                    down->setObjectName("btnChangeCategoryDownValue"+QString::number(changecategoryvalueslayout->rowCount()));
                    select->setObjectName("btnChangeCategorySelectValue"+QString::number(changecategoryvalueslayout->rowCount()));
                    unselect->setObjectName("btnChangeCategoryUnSelectValue"+QString::number(changecategoryvalueslayout->rowCount()));
                    if(i==0) up->setEnabled(false);
                    if(i==categor.object().value("values").toArray().size()-1) down->setEnabled(false);
                    btn->setIcon(QIcon(":/program/program/delete.png"));
                    //select->setIcon();
                    //unselect->setIcon();
                    up->setIcon(QIcon(":/"+theme+"/program/"+theme+"/up.png"));
                    down->setIcon(QIcon(":/"+theme+"/program/"+theme+"/down.png"));
                    connect(btn,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryDeleteValues_clicked);
                    connect(val,&QLineEdit::editingFinished,this,&FormAchievements::EditLineEditChangeCategoryValue);
                    connect(up,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryUpValues_clicked);
                    connect(down,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryDownValues_clicked);
                    connect(select,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategorySelectValues_clicked);
                    connect(unselect,&QPushButton::clicked,this,&FormAchievements::on_buttonChangeCategoryUnSelectValues_clicked);
                    //changecategoryvalueslayout->addRow(categor.object().value("values").toArray().at(i).toString(),btn);
                    bl->addWidget(val);
                    bl->addWidget(up);
                    bl->addWidget(down);
                    bl->addWidget(select);
                    bl->addWidget(unselect);
                    bl->addWidget(btn);
                    bl->setMargin(0);
                    QWidget* Wbl = new QWidget;
                    Wbl->setLayout(bl);
    //                changecategoryvalueslayout->addWidget(val,i,0);
    //                changecategoryvalueslayout->addWidget(up,i,1);
    //                changecategoryvalueslayout->addWidget(down,i,2);
    //                changecategoryvalueslayout->addWidget(btn,i,3);
                    changecategoryvalueslayout->addRow(Wbl);
                    ui->TableWidgetAchievements->insertColumn(ui->TableWidgetAchievements->columnCount());
                    ui->TableWidgetAchievements->setHorizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1,new QTableWidgetItem(categor.object().value("values").toArray().at(i).toString()));
                    for (int j=0;j<ui->TableWidgetAchievements->rowCount();j++) {
                        QTableWidgetItem* pItem(new QTableWidgetItem(tr("Add")));
                        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
                        bool accept=true;
                        for (int k=0;k<categor.object().value(categor.object().value("values").toArray().at(i).toString()).toArray().size();k++) {
                            if(ui->TableWidgetAchievements->item(j,0)->text()==categor.object().value(categor.object().value("values").toArray().at(i).toString()).toArray().at(k).toString()){
                                accept=false;
                                break;
                            }
                        }
                        pItem->setCheckState(accept?Qt::Unchecked:Qt::Checked);
                        ui->TableWidgetAchievements->setItem(j,ui->TableWidgetAchievements->columnCount()-1, pItem);
                    }
                }
                category.close();
            } else {
                ui->LineEditTitleCategoryChangeCategory->setEnabled(false);
            }
        }
    }
}

void FormAchievements::on_ChangeTitleCategory_OneValue(){
    if(ui->CheckBoxCategoryOneValue->isChecked())
        ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->setText(ui->LineEditTitleCategoryChangeCategory->text());
}
