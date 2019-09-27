#include "formachievements.h"
#include "ui_formachievements.h"

FormAchievements::FormAchievements(QString keys, QString ids, SGame games, QWidget *parent) :    QWidget(parent),    ui(new Ui::FormAchievements){
    ui->setupUi(this);
    Words=Setting.GetWords("achievements");
    key=keys;
    id=ids;
    game=games;
    achievements.Set(key,QString::number(game.GetAppid()),id,Words[26]);
    ui->TableWidgetAchievements->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
    ui->ButtonReturn->setIcon(QIcon(":/"+theme+"/program/"+theme+"/back.png"));
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
    ui->TableWidgetAchievements->setColumnCount(7);
    ui->ButtonReturn->setText(" "+Words[0]);
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
    ui->TableWidgetAchievements->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(2,new QTableWidgetItem(Words[19]));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(3,new QTableWidgetItem(Words[20]));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(4,new QTableWidgetItem(Words[21]));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(5,new QTableWidgetItem(Words[23]));
    ui->TableWidgetAchievements->setHorizontalHeaderItem(6,new QTableWidgetItem(Words[22]));
    ui->LabelGameOnline->setText(Words[27]+": "+game.GetNumberPlayers(key,false));
        QNetworkAccessManager manager;
        QEventLoop loop;
        connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        QNetworkReply &logoreply = *manager.get(QNetworkRequest("http://media.steampowered.com/steamcommunity/public/images/apps/"+QString::number(game.GetAppid())+"/"+game.GetImg_logo_url()+".jpg"));
        loop.exec();
        disconnect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QPixmap pixmap;
        pixmap.loadFromData(logoreply.readAll());
    ui->LabelGameLogo->setPixmap(pixmap);
    if(!QDir("images/achievements/"+QString::number(game.GetAppid())).exists())
        QDir().mkdir("images/achievements/"+QString::number(game.GetAppid()));
    qDebug()<<achievements.GetStatusGlobal()<<achievements.GetStatusPlayer()<<achievements.GetStatusPercent();
    PullTableWidget();
    filter = new bool*[ui->TableWidgetAchievements->rowCount()];
    ShowCategories();
    ui->GroupBoxAddCategory->setVisible(false);
    ui->GroupBoxChangeCategory->setVisible(false);
    QWidget *widget1 = new QWidget;
    newcategoryvalueslayout = new QFormLayout;
    widget1->setLayout(newcategoryvalueslayout);
    ui->ScrollAreaValues->setWidget(widget1);
    QWidget *widget2 = new QWidget;
    changecategoryvalueslayout = new QFormLayout;
    widget2->setLayout(changecategoryvalueslayout);
    ui->ScrollAreaValuesChangeCategory->setWidget(widget2);
    ui->LineEditTitleCategoryChangeCategory->setEnabled(false);
    ui->LineEditNameAchievements->setFocus();
}

FormAchievements::~FormAchievements(){
    delete ui;
}
void FormAchievements::closeEvent(QCloseEvent *){
    emit return_to_games();
    //delete this;
}
void FormAchievements::returnfromcompare(){
    windowchildcount--;
    this->setVisible(true);
    delete compareform;
}
void FormAchievements::on_ButtonReturn_clicked(){
    emit return_to_games();
    //delete this;
}

void FormAchievements::PullTableWidget(){
    int totalr=0;
    int totalnr=0;
    ui->TableWidgetAchievements->setRowCount(0);
    if(!(achievements.GetStatusGlobal()=="success"&&achievements.GetStatusPlayer()=="success"&&achievements.GetStatusPercent()=="success")){
        ui->TableWidgetAchievements->insertRow(0);
        QTableWidgetItem *item1 = new QTableWidgetItem("Error");
        ui->TableWidgetAchievements->setItem(0,1,item1);
        ui->TableWidgetAchievements->setColumnHidden(2,true);
        ui->TableWidgetAchievements->setColumnHidden(3,true);
        ui->TableWidgetAchievements->setColumnHidden(4,true);
        ui->TableWidgetAchievements->setColumnHidden(5,true);
        ui->TableWidgetAchievements->setColumnHidden(6,true);
        ui->GroupBoxFilter->setEnabled(false);
        ui->ButtonCompare->setEnabled(false);
    } else
    for(int i=0;i<achievements.GetAchievementsCount();i++){
        qDebug()<<i;
        if(achievements.GetDisplayname(i)!=""){
            int row = ui->TableWidgetAchievements->rowCount();
            ui->TableWidgetAchievements->insertRow(row);
            ui->TableWidgetAchievements->setItem(row,0,new QTableWidgetItem(achievements.GetApiname(i)));
            QString AchievementIcon=achievements.GetIcon(i).mid(66,achievements.GetIcon(i).length());
            if(!QFile::exists("images/achievements/"+QString::number(game.GetAppid())+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1))){
                ImageRequest *image = new ImageRequest(achievements.GetIcon(i),row,"images/achievements/"+QString::number(game.GetAppid())+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1),true);
                connect(image,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultImage(ImageRequest *)));
                } else {
                QPixmap pixmap;
                pixmap.load("images/achievements/"+QString::number(game.GetAppid())+"/"+AchievementIcon.mid(AchievementIcon.indexOf("/",1)+1,AchievementIcon.length()-1));
                QLabel *label = new QLabel;
                label->setPixmap(pixmap);
                ui->TableWidgetAchievements->setCellWidget(row,1,label);
                }
            ui->TableWidgetAchievements->setItem(row,2,new QTableWidgetItem(achievements.GetDisplayname(i)));
            ui->TableWidgetAchievements->setItem(row,3,new QTableWidgetItem(achievements.GetDescription(i)));
            ui->TableWidgetAchievements->setItem(row,4,new QTableWidgetItem(achievements.GetPercent(i)<10?"0"+QString::number(achievements.GetPercent(i))+"%":QString::number(achievements.GetPercent(i))+"%"));
            if(achievements.GetAchieved(i)==1){
                ui->TableWidgetAchievements->setItem(row,5,new QTableWidgetItem(Words[23]+" "+achievements.GetUnlocktime(i).toString("yyyy.MM.dd hh:mm")));
                totalr++;
                } else {
                ui->TableWidgetAchievements->setItem(row,5,new QTableWidgetItem(Words[24]));
                totalnr++;
                }
            QPushButton *button1 = new QPushButton;
            button1->setIcon(QIcon(":/"+theme+"/program/"+theme+"/favorites.png"));
            connect(button1,SIGNAL(pressed()),this,SLOT(FavoritesClicked()));
            button1->setObjectName("ButtonFavorites&"+achievements.GetApiname(i));
            ui->TableWidgetAchievements->setCellWidget(row,6,button1);
            ui->TableWidgetAchievements->item(row,2)->setTextAlignment(Qt::AlignCenter);
            ui->TableWidgetAchievements->item(row,3)->setTextAlignment(Qt::AlignCenter);
            ui->TableWidgetAchievements->item(row,4)->setTextAlignment(Qt::AlignCenter);
            ui->TableWidgetAchievements->item(row,5)->setTextAlignment(Qt::AlignCenter);
        }
    }
    ui->LabelTotalPersent->setText(QString::number(totalr)+"/"+QString::number(totalr+totalnr)+" = "+QString::number(100.0*totalr/(totalr+totalnr))+"%");
    ui->TableWidgetAchievements->setColumnHidden(0,true);
    ui->TableWidgetAchievements->setColumnWidth(1,65);
    ui->TableWidgetAchievements->setColumnWidth(2,100);
    ui->TableWidgetAchievements->setColumnWidth(3,315);
    ui->TableWidgetAchievements->resizeColumnToContents(4);
    ui->TableWidgetAchievements->setColumnWidth(5,80);
    ui->TableWidgetAchievements->setColumnWidth(6,50);
    ui->TableWidgetAchievements->resizeRowsToContents();
}

void FormAchievements::FavoritesClicked(){

}

void FormAchievements::on_LineEditNameAchievements_textChanged(const QString&){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++)
        filter[i][0]=((ui->TableWidgetAchievements->item(i,2)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1)||(ui->TableWidgetAchievements->item(i,3)->text().toLower().indexOf(ui->LineEditNameAchievements->text().toLower())>-1))?true:false;
    UpdateHiddenRows();
}
void FormAchievements::on_ButtonFindAchievement_clicked(){
    on_LineEditNameAchievements_textChanged(ui->LineEditNameAchievements->text());
}

void FormAchievements::on_RadioButtonAll_clicked(){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++){
        filter[i][1]=true;}
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonReached_clicked(){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++)
        filter[i][1]=ui->TableWidgetAchievements->item(i,5)->text().indexOf(".")>-1?true:false;
    UpdateHiddenRows();
}
void FormAchievements::on_RadioButtonNotReached_clicked(){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++)
        filter[i][1]=ui->TableWidgetAchievements->item(i,5)->text().indexOf(".")>-1?false:true;
    UpdateHiddenRows();
}

void FormAchievements::OnResultImage(ImageRequest *imgr){
    disconnect(imgr,SIGNAL(onReady(ImageRequest *)),this,SLOT(OnResultImage(ImageRequest *)));
    QPixmap pixmap;
    pixmap.loadFromData(imgr->GetAnswer());
    QLabel *label = new QLabel;
    label->setPixmap(pixmap);
    ui->TableWidgetAchievements->setCellWidget(imgr->GetRow(),1,label);
    ui->TableWidgetAchievements->resizeRowToContents(imgr->GetRow());
    imgr->deleteLater();
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
        QFormLayout *layout1 = new QFormLayout;
        QFormLayout *layout2 = new QFormLayout;
        QWidget *widget1 = new QWidget;
        QWidget *widget2 = new QWidget;
        for (int i = 0; i < list.size(); ++i){
            QFile category("Files/Categories/"+QString::number(game.GetAppid())+"/"+list.at(i).fileName());
            category.open(QFile::ReadOnly);
            QJsonDocument cat=QJsonDocument().fromJson(category.readAll());
            if(cat.object().value("values").toArray().size()==1){
                QCheckBox *chb = new QCheckBox;
                chb->setText(cat.object().value("name").toString());
                chb->setObjectName("Category"+QString::number(i));
                connect(chb,SIGNAL(stateChanged(int)),this,SLOT(on_CheckBoxCategory_Change(int)));
                layout2->addRow(chb);
            } else {
                QComboBox *cb = new QComboBox;
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
        bool **New = new bool*[ui->TableWidgetAchievements->rowCount()];
        for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
            New[i]=new bool[list.size()+3];
            for (int j=0;j<list.size()+3;j++) {
                New[i][j]=true;
                }
            }
        colfilter=list.size()+3;
        delete filter;
        filter = new bool*[ui->TableWidgetAchievements->rowCount()];
        filter = New;
}
void FormAchievements::UpdateHiddenRows(){
    for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
        bool accept=true;
        for (int j=0;j<colfilter;j++) {
            if(filter[i][j]==false){
                accept=false;
                break;
                }
            }
        ui->TableWidgetAchievements->setRowHidden(i,accept?false:true);
    }
}

void FormAchievements::on_ComboBoxCategory_Change(int index){
    QComboBox *cb = qobject_cast<QComboBox*>(sender());
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
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,0)->text()==selecteditem[j].toString()){
                        filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        break;
                        }
                    }
            } else {
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                }
            }
        category.close();
        UpdateHiddenRows();
    }
}
void FormAchievements::on_CheckBoxCategory_Change(int ind){
    QCheckBox *cb = qobject_cast<QCheckBox*>(sender());
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
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = false;
                for (int j=0;j<selecteditem.size();j++) {
                    if(ui->TableWidgetAchievements->item(i,0)->text()==selecteditem[j].toString()){
                        filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()] = true;
                        break;
                        }
                    }
            } else {
            for (int i=0;i<ui->TableWidgetAchievements->rowCount();i++) {
                filter[i][3+cb->objectName().mid(8,cb->objectName().length()).toInt()]=true;
                }
            }
        category.close();
        UpdateHiddenRows();
    }
}
void FormAchievements::on_ButtonAddCategory_clicked(){
    ui->ButtonAddCategory->setEnabled(false);
    ui->ButtonChangeCategory->setEnabled(false);
    ui->GroupBoxAddCategory->setVisible(true);
}
void FormAchievements::on_ButtonChangeCategory_clicked(){
    ui->ButtonAddCategory->setEnabled(false);
    ui->ButtonChangeCategory->setEnabled(false);
    ui->GroupBoxChangeCategory->setVisible(true);
}
void FormAchievements::on_ButtonUpdate_clicked(){
    achievements.Update();
    PullTableWidget();
    ui->LabelGameOnline->setText(Words[27]+": "+game.GetNumberPlayers(key,true));
}

void FormAchievements::on_ButtonAddValueNewCategory_clicked(){
        AddValueCategory("New",newcategoryvalueslayout);
}
void FormAchievements::on_ButtonCancelNewCategory_clicked(){
    ui->TableWidgetAchievements->setColumnCount(7);
    ui->GroupBoxAddCategory->setVisible(false);
    ui->ButtonAddCategory->setEnabled(true);
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
                QJsonArray groups;
                QJsonObject group;
                group["name"]=ui->LineEditTitleNewCategory->text();
                QJsonArray values;
                if(ui->CheckBoxNewCategoryOneValue->isChecked()){
                    if(newcategoryvalueslayout->rowCount()>0){
                        QMessageBox::StandardButton btn=QMessageBox::question(this,Words[39],Words[40].mid(0,Words[40].indexOf("\\n")-1)+"\n"+Words[40].mid(Words[40].indexOf("\\n")+2,Words[40].length()-Words[40].indexOf("\n")-2),QMessageBox::Yes|QMessageBox::No);
                        if(btn==QMessageBox::No){
                            qDebug()<<0;
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
                            qDebug()<<1<<i;
                            return;
                            }
                        for (int j=7;j<i;j++){
                            if(ui->TableWidgetAchievements->horizontalHeaderItem(i)->text()==ui->TableWidgetAchievements->horizontalHeaderItem(j)->text()){
                                Category.close();
                                Category.remove();
                                QMessageBox::warning(this,Words[28],Words[29]);
                                qDebug()<<2<<i<<j;
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
        disconnect(ui->LineEditTitleNewCategory,SIGNAL(editingFinished()),this,SLOT(on_Change_Title_NewCategory_OneValue()));
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
        connect(ui->LineEditTitleNewCategory,SIGNAL(editingFinished()),this,SLOT(on_Change_Title_NewCategory_OneValue()));
        break;
        }
    }
}
void FormAchievements::on_Change_Title_NewCategory_OneValue(){
    ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->setText(ui->LineEditTitleNewCategory->text());
}

void FormAchievements::EditLineEditNewCategoryValue(){
    QLineEdit *lied =qobject_cast<QLineEdit*>(sender());
    int i=lied->objectName().mid(20,lied->objectName().length()-20).toInt();
    ui->TableWidgetAchievements->horizontalHeaderItem(7+i)->setText(lied->text());
}
void FormAchievements::on_buttonNewCategoryUpValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(21,btn->objectName().length()-21).toInt();
    UpValueCategory("New",i);
}
void FormAchievements::on_buttonNewCategoryDownValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(23,btn->objectName().length()-23).toInt();
    UpValueCategory("New",i+1);
}
void FormAchievements::on_buttonNewCategoryDeleteValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(25,btn->objectName().length()-25).toInt();
    delete btn;
    DeleteValuesCategory("New",i,newcategoryvalueslayout);
}
void FormAchievements::on_buttonNewCategorySelectValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(25,btn->objectName().length()-25).toInt();
    SelectValueCategory(j,Qt::Checked);
}
void FormAchievements::on_buttonNewCategoryUnSelectValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(27,btn->objectName().length()-27).toInt();
    SelectValueCategory(j,Qt::Unchecked);
}

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
                QHBoxLayout *bl = new QHBoxLayout;
                QPushButton *btn = new QPushButton;
                QLineEdit *val = new QLineEdit(categor.object().value("values").toArray().at(i).toString());
                QPushButton *up = new QPushButton();
                QPushButton *down = new QPushButton();
                QPushButton *select = new QPushButton();
                QPushButton *unselect = new QPushButton();
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
                connect(btn,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryDeleteValues_clicked()));
                connect(val,SIGNAL(editingFinished()),this,SLOT(EditLineEditChangeCategoryValue()));
                connect(up,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryUpValues_clicked()));
                connect(down,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryDownValues_clicked()));
                connect(select,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategorySelectValues_clicked()));
                connect(unselect,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryUnSelectValues_clicked()));
                //changecategoryvalueslayout->addRow(categor.object().value("values").toArray().at(i).toString(),btn);
                bl->addWidget(val);
                bl->addWidget(up);
                bl->addWidget(down);
                bl->addWidget(select);
                bl->addWidget(unselect);
                bl->addWidget(btn);
                bl->setMargin(0);
                QWidget *Wbl = new QWidget;
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
        disconnect(ui->LineEditTitleCategoryChangeCategory,SIGNAL(editingFinished()),this,SLOT(on_Change_Title_ChangeCategory_OneValue()));
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
        connect(ui->LineEditTitleCategoryChangeCategory,SIGNAL(editingFinished()),this,SLOT(on_Change_Title_ChangeCategory_OneValue()));
        break;
        }
    }
}
void FormAchievements::on_Change_Title_ChangeCategory_OneValue(){
    ui->TableWidgetAchievements->horizontalHeaderItem(ui->TableWidgetAchievements->columnCount()-1)->setText(ui->LineEditTitleCategoryChangeCategory->text());
}

void FormAchievements::EditLineEditChangeCategoryValue(){
    QLineEdit *lied =qobject_cast<QLineEdit*>(sender());
    int i=lied->objectName().mid(23,lied->objectName().length()-23).toInt();
    ui->TableWidgetAchievements->horizontalHeaderItem(7+i)->setText(lied->text());
}
void FormAchievements::on_buttonChangeCategoryUpValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(24,btn->objectName().length()-24).toInt();
    UpValueCategory("Change",i);
}
void FormAchievements::on_buttonChangeCategoryDownValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(26,btn->objectName().length()-26).toInt();
    UpValueCategory("Change",i+1);
}
void FormAchievements::on_buttonChangeCategoryDeleteValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int i=btn->objectName().mid(28,btn->objectName().length()-28).toInt();
    delete btn;
    DeleteValuesCategory("Change",i,changecategoryvalueslayout);
}
void FormAchievements::on_buttonChangeCategorySelectValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(28,btn->objectName().length()-28).toInt();
    SelectValueCategory(j,Qt::Checked);
}
void FormAchievements::on_buttonChangeCategoryUnSelectValues_clicked(){
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    int j=btn->objectName().mid(30,btn->objectName().length()-30).toInt();
    SelectValueCategory(j,Qt::Unchecked);
}

void FormAchievements::on_ButtonCompare_clicked(){
    if(windowchildcount==0){
        windowchildcount++;
        compareform = new FormCompare(key,id,game,*ui->LabelGameLogo->pixmap(),achievements);
        connect(compareform,SIGNAL(return_to_achievements()),this,SLOT(returnfromcompare()));
        compareform->show();
        this->setVisible(false);
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
    QHBoxLayout *bl = new QHBoxLayout;
    QPushButton *btn = new QPushButton;
    QLineEdit *val = new QLineEdit();
    QPushButton *up = new QPushButton();
    QPushButton *down = new QPushButton();
    QPushButton *select = new QPushButton();
    QPushButton *unselect = new QPushButton();
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
        connect(btn,SIGNAL(clicked()),this,SLOT(on_buttonNewCategoryDeleteValues_clicked()));
        connect(val,SIGNAL(editingFinished()),this,SLOT(EditLineEditNewCategoryValue()));
        connect(up,SIGNAL(clicked()),this,SLOT(on_buttonNewCategoryUpValues_clicked()));
        connect(down,SIGNAL(clicked()),this,SLOT(on_buttonNewCategoryDownValues_clicked()));
        connect(select,SIGNAL(clicked()),this,SLOT(on_buttonNewCategorySelectValues_clicked()));
        connect(unselect,SIGNAL(clicked()),this,SLOT(on_buttonNewCategoryUnSelectValues_clicked()));
    } else {
        if(Type=="Change"){
            connect(btn,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryDeleteValues_clicked()));
            connect(val,SIGNAL(editingFinished()),this,SLOT(EditLineEditChangeCategoryValue()));
            connect(up,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryUpValues_clicked()));
            connect(down,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryDownValues_clicked()));
            connect(select,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategorySelectValues_clicked()));
            connect(unselect,SIGNAL(clicked()),this,SLOT(on_buttonChangeCategoryUnSelectValues_clicked()));
        }
    }
    bl->addWidget(val);
    bl->addWidget(up);
    bl->addWidget(down);
    bl->addWidget(select);
    bl->addWidget(unselect);
    bl->addWidget(btn);
    bl->setMargin(0);
    QWidget *Wbl = new QWidget;
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
        QPushButton * butn = findChild<QPushButton*>("btn"+Type+"CategoryDeleteValue"+QString::number(i));
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
    QList<QTableWidgetItem *> rows = ui->TableWidgetAchievements->selectedItems();
    qDebug()<<rows.size();
    for (int i=0;i<rows.size();i++) {
        ui->TableWidgetAchievements->item(rows.at(i)->row(),7+j)->setCheckState(CS);
    }
    ui->TableWidgetAchievements->selectColumn(0);
}
