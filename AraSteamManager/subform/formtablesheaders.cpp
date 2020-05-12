#include "formtablesheaders.h"
#include "ui_formtablesheaders.h"

#define Constants {
constexpr int c_filterName=0;
constexpr int c_filterReached=1;
constexpr int c_filterFavorite=2;
constexpr int c_filterUniqueValue=3;
constexpr int c_filterColumnCount=4;
constexpr int c_filterEndConstValues=4;

constexpr int c_tableAchievementColumnAppid=0;
constexpr int c_tableAchievementColumnIcon=1;
constexpr int c_tableAchievementColumnTitle=2;
constexpr int c_tableAchievementColumnDescription=3;
constexpr int c_tableAchievementColumnWorld=4;
constexpr int c_tableAchievementColumnReachedMy=5;
constexpr int c_tableAchievementColumnCount=6;
#define ConstantsEnd }

//Добавить Retranslate()
FormTablesHeaders::FormTablesHeaders(int a_rowHeaders, int a_rowContent, SGame a_game, QString a_id, SAchievements a_achievements, TableType a_type, QWidget *parent): QWidget(parent),
                    ui(new Ui::FormTablesHeaders),_game(a_game),_noValueColumn(-1),_id(a_id){
    ui->setupUi(this);
#define ConnectSlots {
    connect(ui->TableWidgetContent->horizontalScrollBar(),&QScrollBar::sliderMoved,ui->TableWidgetHorizontalHeader->horizontalScrollBar(),&QScrollBar::setValue);
    connect(ui->TableWidgetContent->horizontalScrollBar(),&QScrollBar::valueChanged,ui->TableWidgetHorizontalHeader->horizontalScrollBar(),&QScrollBar::setValue);

    connect(ui->TableWidgetHorizontalHeader->horizontalHeader(),&QHeaderView::sectionClicked,ui->TableWidgetContent,[=](int logicalIndex)
            {ui->TableWidgetContent->sortByColumn(logicalIndex,ui->TableWidgetHorizontalHeader->horizontalHeader()->sortIndicatorOrder());});
    connect(ui->TableWidgetHorizontalHeader->horizontalHeader(),&QHeaderView::sectionResized,ui->TableWidgetContent,[=](int logicalIndex, int, int newSize)
            {ui->TableWidgetContent->setColumnWidth(logicalIndex,newSize);});

    connect(ui->TableWidgetHorizontalHeader->verticalHeader(),&QHeaderView::sectionResized,ui->TableWidgetContent,[=](int /*logicalIndex*/, int oldSize, int newSize){
        _horizontalHeaderHeight+=(newSize-oldSize);
        connect(ui->TableWidgetContent,&QTableWidget::cellClicked,this,[=](int a_row, int a_col){emit s_contentCellClicked(a_row,a_col);});
        Resize();
        });
#define ConnectSlotsEnd }
    ui->TableWidgetHorizontalHeader->setRowCount(a_rowHeaders);
    ui->TableWidgetContent->setRowCount(a_rowContent);
    SetColumnCount(0);
    SetColumnCount(c_tableAchievementColumnCount);
    SetType(a_type);

    _achievements=a_achievements;
    _achievements._appid=QString::number(_game._appID);
    _achievements._id=_id;
    _achievements.Set(SAchievementsPercentage(QString::number(_game._appID),false,this));
    _achievements.Update();

    ui->TableWidgetContent->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetHorizontalHeader->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->TableWidgetContent->setSelectionMode(QAbstractItemView::NoSelection);

    _horizontalHeaderHeight=2;
    for (int i=0;i<ui->TableWidgetHorizontalHeader->rowCount();i++)
        _horizontalHeaderHeight+=ui->TableWidgetHorizontalHeader->rowHeight(i);

    SProfile profileData(_id,false,QueryType::url);
//    QLabel *profileAvatarCompare = new QLabel;
//    profileAvatarCompare->setAlignment(Qt::AlignCenter);
//    new RequestImage(profileAvatarCompare,profileData.GetAvatar(),"",false,this);
//    SetWidgetContent(0,c_tableAchievementColumnReachedMy,profileAvatarCompare);
    SetRowHeightHeaders(0,33);
    SetVerticalHeaderTitle(0,new  QTableWidgetItem(""));
    SetVerticalHeaderTitle(1,new  QTableWidgetItem("%"));
    ChangeHorizontalTitle(c_tableAchievementColumnIcon,"");
    ChangeHorizontalTitle(c_tableAchievementColumnTitle,tr("Название"));
    ChangeHorizontalTitle(c_tableAchievementColumnDescription,tr("Описание"));
    ChangeHorizontalTitle(c_tableAchievementColumnWorld,tr("По миру"));
    ChangeHorizontalTitle(c_tableAchievementColumnReachedMy,profileData.GetPersonaname());
    SetVisibleColumn(c_tableAchievementColumnAppid,false);
    SetColumnWidth(c_tableAchievementColumnIcon,65);
    SetColumnWidth(c_tableAchievementColumnTitle,100);
    SetColumnWidth(c_tableAchievementColumnDescription,315);
    SetColumnWidth(c_tableAchievementColumnWorld,65);
    SetColumnWidth(c_tableAchievementColumnReachedMy,80);
}
FormTablesHeaders::~FormTablesHeaders(){
    delete ui;
}

void FormTablesHeaders::resizeEvent(QResizeEvent*){
    Resize();
}
void FormTablesHeaders::Resize(){
    int height= _visibleHorizontal?_horizontalHeaderHeight+ui->TableWidgetHorizontalHeader->horizontalHeader()->height():0;
    ui->TableWidgetHorizontalHeader->setGeometry(0,0,this->width(),height);
    ui->TableWidgetContent->setGeometry(0,height,this->width(),this->height()-height);
}

#define Gets {
int FormTablesHeaders::GetColumnCount(){
    return ui->TableWidgetHorizontalHeader->columnCount();
}
int FormTablesHeaders::GetRowCount(){
    return ui->TableWidgetContent->rowCount();
}
int FormTablesHeaders::GetRowCountHeaders(){
    return ui->TableWidgetHorizontalHeader->rowCount();
}
int FormTablesHeaders::GetRowHeightHeaders(int a_row){
    return ui->TableWidgetHorizontalHeader->rowHeight(a_row);
}
int FormTablesHeaders::GetColumnWidth(int a_column){
    return ui->TableWidgetContent->columnWidth(a_column);
}
int FormTablesHeaders::GetRowHeight(int a_row){
    return ui->TableWidgetContent->rowHeight(a_row);
}

QTableWidgetItem* FormTablesHeaders::ItemContent(int a_row, int a_column){
    return ui->TableWidgetContent->item(a_row, a_column);
}
QTableWidgetItem* FormTablesHeaders::ItemHorizontalHeader(int a_row, int a_column){
    return ui->TableWidgetHorizontalHeader->item(a_row, a_column);
}

QTableWidget *FormTablesHeaders::GetTableHH(){
    return ui->TableWidgetHorizontalHeader;
}
QTableWidget *FormTablesHeaders::GetTableContent(){
    return ui->TableWidgetContent;
}
#define GetsEnd }

void FormTablesHeaders::SetColumnCount(int a_col){
    int columnNow=ui->TableWidgetContent->columnCount();
    ui->TableWidgetContent->setColumnCount(a_col);
    ui->TableWidgetHorizontalHeader->setColumnCount(a_col);
    while(columnNow<ui->TableWidgetContent->columnCount()){
        SetHorizontalTitle(columnNow, "");
        columnNow++;
    }
}
void FormTablesHeaders::SetColumnWidth(int a_column, int a_width){
    ui->TableWidgetHorizontalHeader->setColumnWidth(a_column,a_width);
    ui->TableWidgetContent->setColumnWidth(a_column,a_width);
}
void FormTablesHeaders::SetRowCount(int a_row){
    ui->TableWidgetContent->setRowCount(a_row);
    _fAchievements.SetRow(a_row);
    _fCompare.SetRow(a_row);
}
void FormTablesHeaders::SetRowHeight(int a_row, int a_height){
    ui->TableWidgetContent->setRowHeight(a_row,a_height);
}
void FormTablesHeaders::SetRowCountHeaders(int a_row){
    ui->TableWidgetHorizontalHeader->setRowCount(a_row);
    _horizontalHeaderHeight=1;
    for (int i=0;i<ui->TableWidgetHorizontalHeader->rowCount();i++) {
        _horizontalHeaderHeight+=ui->TableWidgetHorizontalHeader->rowHeight(i);
    }
}
void FormTablesHeaders::SetRowHeightHeaders(int a_row, int a_height){
    ui->TableWidgetHorizontalHeader->setRowHeight(a_row,a_height);
}
void FormTablesHeaders::SetWidgetContent(int a_row, int a_column, QWidget *a_widget){
    ui->TableWidgetContent->setCellWidget(a_row, a_column, a_widget);
}
void FormTablesHeaders::SetWidgetHorizontalHeader(int a_row, int a_column, QWidget *a_widget){
    ui->TableWidgetHorizontalHeader->setCellWidget(a_row, a_column, a_widget);
}
void FormTablesHeaders::SetItemContent(int a_row, int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetContent->setItem(a_row, a_column, a_item);
}
void FormTablesHeaders::SetItemHorizontalHeader(int a_row, int a_column, QTableWidgetItem *a_item){
    ui->TableWidgetHorizontalHeader->setItem(a_row, a_column, a_item);
}

void FormTablesHeaders::SetVisibleColumn(int a_column, bool a_visible){
    ui->TableWidgetHorizontalHeader->setColumnHidden(a_column, !a_visible);
    ui->TableWidgetContent->setColumnHidden(a_column, !a_visible);
}
void FormTablesHeaders::SetVisibleRowContent(int a_row, bool a_visible){
    ui->TableWidgetContent->setRowHidden(a_row, !a_visible);
}
void FormTablesHeaders::SetVisibleRowHeaders(int a_row, bool a_visible){
    ui->TableWidgetHorizontalHeader->setRowHidden(a_row, !a_visible);
}

void FormTablesHeaders::SetHorizontalTitle(int a_column, QString a_text){
    ui->TableWidgetHorizontalHeader->setHorizontalHeaderItem(a_column, new QTableWidgetItem(a_text));
    ui->TableWidgetContent->setHorizontalHeaderItem(a_column, new QTableWidgetItem(a_text));
}
void FormTablesHeaders::ChangeHorizontalTitle(int a_column, QString a_text){
    ui->TableWidgetHorizontalHeader->horizontalHeaderItem(a_column)->setText(a_text);
    ui->TableWidgetContent->horizontalHeaderItem(a_column)->setText(a_text);
}
void FormTablesHeaders::SetVerticalTitle(int a_row, QTableWidgetItem *a_item){
    ui->TableWidgetContent->setVerticalHeaderItem(a_row, a_item);
}
void FormTablesHeaders::SetVerticalHeaderTitle(int a_row, QTableWidgetItem *a_item){
    ui->TableWidgetHorizontalHeader->setVerticalHeaderItem(a_row, a_item);
}
void FormTablesHeaders::ResizeRowsToContentsContents(){
    ui->TableWidgetContent->resizeRowsToContents();
}
//void FormTablesHeaders::ResizeColumnsToContents(){

//}
void FormTablesHeaders::ResizeRowsToContentsHeaders(){
    ui->TableWidgetHorizontalHeader->resizeRowsToContents();
}
void FormTablesHeaders::ResizeRowToContentsContents(int a_row){
    ui->TableWidgetContent->resizeRowToContents(a_row);
}
//void FormTablesHeaders::ResizeColumnToContents(int a_column){

//}
void FormTablesHeaders::ResizeRowToContentsHeaders(int a_row){
    ui->TableWidgetHorizontalHeader->resizeRowToContents(a_row);
}
void FormTablesHeaders::ResizeRowContent(int a_row, int a_height){
    ui->TableWidgetContent->setRowHeight(a_row, a_height);
}
void FormTablesHeaders::ResizeColumn(int a_column, int a_width){
    ui->TableWidgetHorizontalHeader->setColumnWidth(a_column, a_width);
}
void FormTablesHeaders::ResizeRowHeaders(int a_row, int a_height){
    ui->TableWidgetHorizontalHeader->setRowHeight(a_row, a_height);
}

void FormTablesHeaders::SetType(TableType a_newType){
    switch (a_newType) {
    case TableType::compare:{
        _visibleHorizontal=true;
        ui->TableWidgetHorizontalHeader->setVisible(true);
        ui->TableWidgetContent->horizontalHeader()->setVisible(false);
        while(_categoriesColumns.size()>0){
            RemoveCategoryColumn(0);
        }
        if(_noValueColumn>-1)
            RemoveColumn(_noValueColumn);
        _noValueColumn=-1;
        Resize();
        break;
    }
    case TableType::standart:{
        _visibleHorizontal=false;
        ui->TableWidgetHorizontalHeader->setVisible(false);
        ui->TableWidgetContent->horizontalHeader()->setVisible(true);
        while(_friendsColumns.size()>0){
            RemoveFriendColumn(0);
        }
        Resize();
        break;
    }
    }
    _currentType=a_newType;
    //!!!!!!!!!!!!!
}

bool FormTablesHeaders::AddFriendColumn(SProfile a_friendProfile){
    int column=ui->TableWidgetContent->columnCount();
    InsertColumn(column);
    ChangeHorizontalTitle(column,a_friendProfile.GetPersonaname());
    QLabel *avatarFriend = new QLabel;
    avatarFriend->setPixmap(RequestData(a_friendProfile.GetAvatar(),false).GetPixmap());
    avatarFriend->setToolTip(a_friendProfile.GetPersonaname());
    avatarFriend->setAlignment(Qt::AlignCenter);
    ui->TableWidgetHorizontalHeader->setCellWidget(0,column,avatarFriend);
    SAchievements achievementsFriends=_achievements;
    achievementsFriends.Set(SAchievementsPlayer(QString::number(_game._appID),a_friendProfile.GetSteamid(),false,this));
//    Threading LoadFriendTable(this);
//    LoadFriendTable.AddThreadFriendAchievements(ui->TableWidgetAchievements,ach,col,c_tableCompareColumnAppid);
    _fCompare.SetCol(_fCompare.GetCol()+1);
    SetColumnWidth(column,80);

    _friendsColumns.push_back(column);
    int totalReach=0;
    int totalNotReach=0;
    for(int i=0;i<ui->TableWidgetContent->rowCount();i++){
        int j=0;
        bool isAchievementExist=false;
        for(;j<achievementsFriends.GetCount();j++){
            if(achievementsFriends[j]._apiName==ui->TableWidgetContent->item(i,c_tableAchievementColumnAppid)->text()){
                isAchievementExist=true;
                break;
                }
        }
        if(isAchievementExist){
            QTableWidgetItem *itemReached;
            if(achievementsFriends[j]._achieved==1){
                itemReached = new QTableWidgetItem(tr("Получено %1").arg(achievementsFriends[j]._unlockTime.toString("yyyy.MM.dd hh:mm")));
                itemReached->setToolTip(achievementsFriends[j]._unlockTime.toString("yyyy.MM.dd hh:mm"));
                totalReach++;
                } else {
                itemReached = new QTableWidgetItem(tr("Не получено"));
                totalNotReach++;
                }
            itemReached->setTextAlignment(Qt::AlignCenter);
            ui->TableWidgetContent->setItem(i,column,itemReached);
        }
        }
    if((totalReach==0)&&(totalNotReach==0)){
        ui->TableWidgetHorizontalHeader->setItem(1,column, new QTableWidgetItem(QString("%1\n%2").arg(tr("Профиль не"),tr("публичный"))));
        return false;
    } else {
        ui->TableWidgetHorizontalHeader->setItem(1,column, new QTableWidgetItem(QString("%1/%2\n%3%").arg(QString::number(totalReach),QString::number(totalReach+totalNotReach),
                                                                                                          QString::number(100.0*totalReach/(totalReach+totalNotReach)))));
        return true;
    }
}
void FormTablesHeaders::AddNoValueColumn(){
    InsertColumn(ui->TableWidgetContent->columnCount());
    for(int i=0;i<ui->TableWidgetContent->rowCount();i++){
        QTableWidgetItem *itemCheck(new QTableWidgetItem(tr("Add")));
        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
        itemCheck->setCheckState(Qt::Unchecked);
        ui->TableWidgetContent->setItem(i,ui->TableWidgetContent->columnCount()-1, itemCheck);
        }
    _noValueColumn=ui->TableWidgetContent->columnCount()-1;
}
void FormTablesHeaders::AddCategoryColumn(){
    InsertColumn(ui->TableWidgetContent->columnCount());
    for(int i=0;i<ui->TableWidgetContent->rowCount();i++){
        QTableWidgetItem *itemCheck(new QTableWidgetItem(tr("Add")));
        itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
        itemCheck->setCheckState(Qt::Unchecked);
        ui->TableWidgetContent->setItem(i,ui->TableWidgetContent->columnCount()-1, itemCheck);
        }
    _categoriesColumns.push_back(ui->TableWidgetContent->columnCount()-1);
}
void FormTablesHeaders::RemoveFriendColumn(int a_column){
    int column=_friendsColumns.takeAt(a_column);
    RemoveColumn(column);
    for (int i=0;i<_friendsColumns.size();i++) {
        if(_friendsColumns[i]>column)
            _friendsColumns[i]--;
    }
}
void FormTablesHeaders::RemoveCategoryColumn(int a_column){
    int column=_categoriesColumns.takeAt(a_column);
    RemoveColumn(column);
    for (int i=0;i<_categoriesColumns.size();i++) {
        if(_categoriesColumns[i]>column)
            _categoriesColumns[i]--;
    }
}

void FormTablesHeaders::InsertColumn(int a_columns){
    ui->TableWidgetHorizontalHeader->insertColumn(a_columns);
    ui->TableWidgetContent->insertColumn(a_columns);
    SetHorizontalTitle(a_columns,"");
}
void FormTablesHeaders::RemoveColumn(int a_columns){
    ui->TableWidgetContent->removeColumn(a_columns);
    ui->TableWidgetHorizontalHeader->removeColumn(a_columns);
}
void FormTablesHeaders::InsertRow(int a_row){
    ui->TableWidgetContent->insertRow(a_row);
}
void FormTablesHeaders::RemoveRow(int a_row){
    ui->TableWidgetContent->removeRow(a_row);
}
