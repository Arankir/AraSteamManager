#include "formtablesheaders.h"
#include "ui_formtablesheaders.h"

#define Constants {
constexpr int c_filterName = 0;
constexpr int c_filterReached = 1;
constexpr int c_filterFavorite = 2;
constexpr int c_filterUniqueValue = 3;
constexpr int c_filterColumnCount = 4;
constexpr int c_filterEndConstValues = 4;

constexpr int c_tableAchievementColumnAppid = 0;
constexpr int c_tableAchievementColumnIcon = 1;
constexpr int c_tableAchievementColumnTitle = 2;
constexpr int c_tableAchievementColumnDescription = 3;
constexpr int c_tableAchievementColumnWorld = 4;
constexpr int c_tableAchievementColumnReachedMy = 5;
constexpr int c_tableAchievementColumnCount = 6;
#define ConstantsEnd }

FormTablesHeaders::FormTablesHeaders(SGame aGame, QString aId, SAchievementsPlayer aPlayer, QWidget *aParent): QWidget(aParent),
ui(new Ui::FormTablesHeaders), _game(aGame), _noValueColumn(-1), _isUnique(false), _id(aId), _achievements(aPlayer) {
    ui->setupUi(this);
    ui->TableWidgetContent->setRowCount(0);
    setColumnCount(0);
    setColumnCount(c_tableAchievementColumnCount);

    setType(TableType::standart);
    ui->TableWidgetContent         ->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetHorizontalHeader->setEditTriggers(QAbstractItemView::NoEditTriggers);

#define InitHeaderTable {
    ui->TableWidgetHorizontalHeader->setRowCount(2);
    setRowHeightHeaders(0, 33 + 18);
    setRowHeightHeaders(1, 33 + 18);
    _horizontalHeaderHeight = 2;
    for (int i = 0; i < ui->TableWidgetHorizontalHeader->rowCount(); i++) {
        _horizontalHeaderHeight += ui->TableWidgetHorizontalHeader->rowHeight(i);
    }
    setVerticalHeaderTitle(0, new  QTableWidgetItem(""));
    setVerticalHeaderTitle(1, new  QTableWidgetItem("%"));
#define InitHeaderTableEnd }

    SProfiles profileData(_id, false, ProfileUrlType::id);

    changeHorizontalTitle(c_tableAchievementColumnIcon,         "");
    changeHorizontalTitle(c_tableAchievementColumnTitle,        tr("Название"));
    changeHorizontalTitle(c_tableAchievementColumnDescription,  tr("Описание"));
    changeHorizontalTitle(c_tableAchievementColumnWorld,        tr("По миру"));
    changeHorizontalTitle(c_tableAchievementColumnReachedMy,    profileData.getPersonaname());
    setColumnWidth(       c_tableAchievementColumnIcon,         65 + 8);
    setColumnWidth(       c_tableAchievementColumnTitle,        100);
    setColumnWidth(       c_tableAchievementColumnDescription,  315);
    setColumnWidth(       c_tableAchievementColumnWorld,        65);
    setColumnWidth(       c_tableAchievementColumnReachedMy,    80);

    setVisibleColumn(     c_tableAchievementColumnAppid,        false);

    _achievements._appid = QString::number(_game._appID);
    _achievements._id = _id;
    _achievements.update();

#define ConnectSlots {
    connect(&_achievements,                                      SIGNAL(s_finished()),         this,                                                   SLOT(pullTable()));
    connect(ui->TableWidgetContent->horizontalScrollBar(),       &QScrollBar::sliderMoved,     ui->TableWidgetHorizontalHeader->horizontalScrollBar(), &QScrollBar::setValue);
    connect(ui->TableWidgetContent->horizontalScrollBar(),       &QScrollBar::valueChanged,    ui->TableWidgetHorizontalHeader->horizontalScrollBar(), &QScrollBar::setValue);

    connect(ui->TableWidgetHorizontalHeader->horizontalHeader(), &QHeaderView::sectionClicked, ui->TableWidgetContent,                                 [=](int logicalIndex) {
        ui->TableWidgetContent->sortByColumn(logicalIndex, ui->TableWidgetHorizontalHeader->horizontalHeader()->sortIndicatorOrder());
    });
    connect(ui->TableWidgetHorizontalHeader->horizontalHeader(), &QHeaderView::sectionResized, ui->TableWidgetContent,                                 [=](int logicalIndex, int, int newSize) {
        ui->TableWidgetContent->setColumnWidth(logicalIndex, newSize);
    });

    connect(ui->TableWidgetHorizontalHeader->verticalHeader(),   &QHeaderView::sectionResized, ui->TableWidgetContent,                                 [=](int /*logicalIndex*/, int oldSize, int newSize) {
        _horizontalHeaderHeight += (newSize - oldSize);
        resize();
    });

    connect(ui->TableWidgetContent,                              &QTableWidget::cellClicked,   this,                                                   [=](int aRow, int aCol) {
        emit s_contentCellClicked(aRow, aCol);
    });
#define ConnectSlotsEnd }
}

FormTablesHeaders::~FormTablesHeaders() {
    delete ui;
}

#define Events {
void FormTablesHeaders::resizeEvent(QResizeEvent*) {
    resize();
}

void FormTablesHeaders::changeEvent(QEvent *event) {
    if (event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}
#define EventsEnd }

void FormTablesHeaders::resize() {
    int height = _visibleHorizontal ? _horizontalHeaderHeight + ui->TableWidgetHorizontalHeader->horizontalHeader()->height() : 0;
    ui->TableWidgetHorizontalHeader->setGeometry(0, 0, this->width(), height);
    ui->TableWidgetContent->setGeometry(0, height, this->width(), this->height() - height);
}

void FormTablesHeaders::retranslate() {
    ui->retranslateUi(this);
    changeHorizontalTitle(c_tableAchievementColumnIcon, "");
    changeHorizontalTitle(c_tableAchievementColumnTitle, tr("Название"));
    changeHorizontalTitle(c_tableAchievementColumnDescription, tr("Описание"));
    changeHorizontalTitle(c_tableAchievementColumnWorld, tr("По миру"));
    //_tableAchievements->ChangeHorizontalTitle(c_tableAchievementColumnReachedMy, tr("Получено"));
    //_achievements.set(SAchievementsGlobal(QString::number(_game._appID), false));
    pullTable();
}

void FormTablesHeaders::updateHiddenRows() {
    switch (_currentType) {
    case TableType::standart: {
        if (_isUnique) {
            for (int i = 0; i < getRowCount(); i++) {
                if (_fAchievements.getData(i)) {
                    bool isExist = false;
                    if (_isNoValue) {
                        if (itemContent(i, _noValueColumn)->checkState() == Qt::Checked) {
                            isExist = true;
                        }
                    } else {
                        for (int j = 0; j < _categoriesColumns.size(); j++) {
                            if (itemContent(i, _categoriesColumns[j])->checkState() == Qt::Checked) {
                                isExist = true;
                                break;
                            }
                        }
                    }
                    setVisibleRowContent(i, !isExist);
                } else {
                    setVisibleRowContent(i, false);
                }
            }
        } else {
            for (int i = 0; i < getRowCount(); i++) {
                setVisibleRowContent(i, _fAchievements.getData(i));
            }
        }
        break;
    }
    case TableType::compare: {
        for (int i = 0; i < getRowCount(); i++) {
            setVisibleRowContent(i, _fCompare.getData(i));
        }
        break;
    }
    }
}

void FormTablesHeaders::update() {
    _achievements.update();
//TODO Подождать пока ачивки обновятся
//    pullTable();
}

#define StandartFunctions {
#define Gets {
int FormTablesHeaders::getColumnCount() {
    return ui->TableWidgetHorizontalHeader->columnCount();
}

int FormTablesHeaders::getRowCount() {
    return ui->TableWidgetContent->rowCount();
}

int FormTablesHeaders::getRowCountHeaders() {
    return ui->TableWidgetHorizontalHeader->rowCount();
}

int FormTablesHeaders::getRowHeightHeaders(int aRow) {
    return ui->TableWidgetHorizontalHeader->rowHeight(aRow);
}

int FormTablesHeaders::getColumnWidth(int aColumn) {
    return ui->TableWidgetContent->columnWidth(aColumn);
}

int FormTablesHeaders::getRowHeight(int aRow) {
    return ui->TableWidgetContent->rowHeight(aRow);
}

QTableWidgetItem* FormTablesHeaders::itemContent(int aRow, int aColumn) {
    return ui->TableWidgetContent->item(aRow, aColumn);
}

QTableWidgetItem* FormTablesHeaders::itemHorizontalHeader(int aRow, int aColumn) {
    return ui->TableWidgetHorizontalHeader->item(aRow, aColumn);
}

SAchievement FormTablesHeaders::getAchievement(int aIndex) {
    return _achievements[aIndex];
}

QTableWidget *FormTablesHeaders::getTableHH() {
    return ui->TableWidgetHorizontalHeader;
}

QTableWidget *FormTablesHeaders::getTableContent() {
    return ui->TableWidgetContent;
}

QVector<int> FormTablesHeaders::getFriendsColumns() {
    return _friendsColumns;
}

int FormTablesHeaders::getNoValueColumn() {
    return _noValueColumn;
}

QVector<int> FormTablesHeaders::getCategoryColumns() {
    return _categoriesColumns;
}

QString FormTablesHeaders::getHeaderText(int aIndex) {
    return ui->TableWidgetHorizontalHeader->horizontalHeaderItem(aIndex)->text();
}
#define GetsEnd }

#define Sets {
void FormTablesHeaders::setColumnCount(int aCol) {
    int columnNow = ui->TableWidgetContent->columnCount();
    ui->TableWidgetContent->setColumnCount(aCol);
    ui->TableWidgetHorizontalHeader->setColumnCount(aCol);
    while (columnNow < ui->TableWidgetContent->columnCount()) {
        setHorizontalTitle(columnNow, "");
        columnNow++;
    }
    updateHiddenRows();
}

void FormTablesHeaders::setColumnWidth(int aColumn, int aWidth) {
    ui->TableWidgetHorizontalHeader->setColumnWidth(aColumn, aWidth);
    ui->TableWidgetContent->setColumnWidth(aColumn, aWidth);
}

void FormTablesHeaders::setRowCount(int aRow) {
    ui->TableWidgetContent->setRowCount(aRow);
    _fAchievements.setRow(aRow);
    _fCompare.setRow(aRow);
}

void FormTablesHeaders::setRowHeight(int aRow, int aHeight){
    ui->TableWidgetContent->setRowHeight(aRow, aHeight);
}

void FormTablesHeaders::setRowCountHeaders(int aRow) {
    ui->TableWidgetHorizontalHeader->setRowCount(aRow);
    _horizontalHeaderHeight = 1;
    for (int i = 0; i < ui->TableWidgetHorizontalHeader->rowCount(); i++) {
        _horizontalHeaderHeight += ui->TableWidgetHorizontalHeader->rowHeight(i);
    }
}

void FormTablesHeaders::setRowHeightHeaders(int aRow, int aHeight) {
    ui->TableWidgetHorizontalHeader->setRowHeight(aRow, aHeight);
}

void FormTablesHeaders::setWidgetContent(int aRow, int aColumn, QWidget *aWidget) {
    ui->TableWidgetContent->setCellWidget(aRow, aColumn, aWidget);
}

void FormTablesHeaders::setWidgetHorizontalHeader(int a_row, int a_column, QWidget *a_widget){
    ui->TableWidgetHorizontalHeader->setCellWidget(a_row, a_column, a_widget);
}

void FormTablesHeaders::setItemContent(int aRow, int aColumn, QTableWidgetItem *aItem) {
    ui->TableWidgetContent->setItem(aRow, aColumn, aItem);
}

void FormTablesHeaders::setItemHorizontalHeader(int aRow, int aColumn, QTableWidgetItem *aItem) {
    ui->TableWidgetHorizontalHeader->setItem(aRow, aColumn, aItem);
}

void FormTablesHeaders::setVisibleColumn(int aColumn, bool aVisible) {
    ui->TableWidgetHorizontalHeader->setColumnHidden(aColumn, !aVisible);
    ui->TableWidgetContent->setColumnHidden(aColumn, !aVisible);
}

void FormTablesHeaders::setVisibleRowContent(int aRow, bool aVisible) {
    ui->TableWidgetContent->setRowHidden(aRow, !aVisible);
}

void FormTablesHeaders::setVisibleRowHeaders(int aRow, bool aVisible) {
    ui->TableWidgetHorizontalHeader->setRowHidden(aRow, !aVisible);
}

void FormTablesHeaders::setHorizontalTitle(int aColumn, QString aText) {
    ui->TableWidgetHorizontalHeader->setHorizontalHeaderItem(aColumn, new QTableWidgetItem(aText));
    ui->TableWidgetContent->setHorizontalHeaderItem(aColumn, new QTableWidgetItem(aText));
}

void FormTablesHeaders::changeHorizontalTitle(int aColumn, QString aText) {
    ui->TableWidgetHorizontalHeader->horizontalHeaderItem(aColumn)->setText(aText);
    ui->TableWidgetContent->horizontalHeaderItem(aColumn)->setText(aText);
}

void FormTablesHeaders::setVerticalTitle(int aRow, QTableWidgetItem *aItem) {
    ui->TableWidgetContent->setVerticalHeaderItem(aRow, aItem);
}

void FormTablesHeaders::setVerticalHeaderTitle(int aRow, QTableWidgetItem *aItem) {
    ui->TableWidgetHorizontalHeader->setVerticalHeaderItem(aRow, aItem);
}
#define SetsEnd }

#define Resizes {
void FormTablesHeaders::resizeRowsToContentsContents() {
    ui->TableWidgetContent->resizeRowsToContents();
}
//void FormTablesHeaders::ResizeColumnsToContents(){

//}
void FormTablesHeaders::resizeRowsToContentsHeaders() {
    ui->TableWidgetHorizontalHeader->resizeRowsToContents();
}

void FormTablesHeaders::resizeRowToContentsContents(int aRow) {
    ui->TableWidgetContent->resizeRowToContents(aRow);
}
//void FormTablesHeaders::ResizeColumnToContents(int a_column){

//}
void FormTablesHeaders::resizeRowToContentsHeaders(int aRow) {
    ui->TableWidgetHorizontalHeader->resizeRowToContents(aRow);
}

void FormTablesHeaders::resizeRowContent(int aRow, int aHeight) {
    ui->TableWidgetContent->setRowHeight(aRow, aHeight);
}

void FormTablesHeaders::resizeColumn(int aColumn, int aWidth) {
    ui->TableWidgetHorizontalHeader->setColumnWidth(aColumn, aWidth);
}

void FormTablesHeaders::resizeRowHeaders(int aRow, int aHeight) {
    ui->TableWidgetHorizontalHeader->setRowHeight(aRow, aHeight);
}
#define ResizesEnd }

void FormTablesHeaders::insertColumn(int aColumns) {
    ui->TableWidgetHorizontalHeader->insertColumn(aColumns);
    ui->TableWidgetContent->insertColumn(aColumns);
    setHorizontalTitle(aColumns, "");
}

void FormTablesHeaders::removeColumn(int aColumns) {
    ui->TableWidgetContent->removeColumn(aColumns);
    ui->TableWidgetHorizontalHeader->removeColumn(aColumns);
}

void FormTablesHeaders::insertRow(int aRow) {
    ui->TableWidgetContent->insertRow(aRow);
}

void FormTablesHeaders::removeRow(int aRow) {
    ui->TableWidgetContent->removeRow(aRow);
}
#define StandartFunctionsEnd }

#define Category {
void FormTablesHeaders::addCategoryColumn() {
    _categoriesColumns.push_back(insertCheckableColumn());
}

void FormTablesHeaders::addNoValueColumn() {
    _noValueColumn = insertCheckableColumn();
}

int FormTablesHeaders::insertCheckableColumn() {
    insertColumn(ui->TableWidgetContent->columnCount());
    setColumnWidth(ui->TableWidgetContent->columnCount() -1, 48);
    for(int i = 0; i < ui->TableWidgetContent->rowCount(); i++) {
        ui->TableWidgetContent->setItem(i, ui->TableWidgetContent->columnCount() - 1, createFlag(false));
    }
    return ui->TableWidgetContent->columnCount() - 1;
}

QTableWidgetItem *FormTablesHeaders::createFlag(bool flagState) {
    QTableWidgetItem *itemCheck(new QTableWidgetItem(tr("")));
    itemCheck->setFlags(itemCheck->flags() | Qt::ItemIsUserCheckable);
    itemCheck->setCheckState(flagState ? Qt::Checked : Qt::Unchecked);
    return itemCheck;
}

void FormTablesHeaders::reverseCategoryColumn(int index) {
    for (int i = 0; i < getRowCount(); i++) {
        QTableWidgetItem *item = itemContent(i, _categoriesColumns[index]);
        item->setCheckState(item->checkState() == Qt::Checked ? Qt::Unchecked : Qt::Checked);
    }
}

void FormTablesHeaders::removeCategoryColumn(int aColumn) {
    int column = _categoriesColumns.takeAt(aColumn);
    removeColumn(column);
    for(auto &cColumn: _categoriesColumns) {
        if(cColumn > column) {
            cColumn--;
        }
    }
}

void FormTablesHeaders::setValuesMode(bool value) {
    if (_currentType == TableType::standart) {
        _isNoValue = !value;
        if (value) {
            for (auto column: _categoriesColumns) {
                setVisibleColumn(column, true);
            }
            setVisibleColumn(_noValueColumn, false);
        } else {
            for (auto column: _categoriesColumns) {
                setVisibleColumn(column, false);
            }
            setVisibleColumn(_noValueColumn, true);
        }
    }
}

void FormTablesHeaders::setUniqueMode(bool aUnique) {
    if (aUnique) {
        connect(ui->TableWidgetContent, &QTableWidget::itemClicked, this, &FormTablesHeaders::hideCheckedAchievement);
        _isUnique = true;
        if (_isNoValue) {
            for (int i = 0; i < getRowCount(); i++) {
                if (itemContent(i, _noValueColumn)->checkState() == Qt::Checked) {
                    _fAchievements.setData(i, c_filterUniqueValue, false);
                }
            }
        } else {
            for (int i = 0; i < getRowCount(); i++) {
                for (auto &column: _categoriesColumns) {
                    if (itemContent(i, column)->checkState() == Qt::Checked) {
                        _fAchievements.setData(i, c_filterUniqueValue, false);
                    }
                }
            }
        }
    } else {
        disconnect(ui->TableWidgetContent, &QTableWidget::itemClicked, this, &FormTablesHeaders::hideCheckedAchievement);
        _isUnique = false;
        for (int i = 0; i < getRowCount(); i++) {
            _fAchievements.setData(i, c_filterUniqueValue, true);
        }
    }
    updateHiddenRows();
}

void FormTablesHeaders::hideCheckedAchievement(QTableWidgetItem *aItem) {
    if (aItem->column() > c_tableAchievementColumnCount) {
        if (aItem->checkState() == Qt::Checked) {
            _fAchievements.setData(aItem->row(), c_filterUniqueValue, false);
        }
    }
    updateHiddenRows();
}

void FormTablesHeaders::setVisibleContentSelect(int aPos, bool aSelect) {
    if (aPos < ui->TableWidgetContent->columnCount()) {
        if (_isUnique) {
            for (int i = 0; i < getRowCount(); i++) {
                if (!ui->TableWidgetContent->isRowHidden(i)) {
                    itemContent(i, (_noValueColumn + 1) + aPos)->setCheckState(aSelect ? Qt::Checked : Qt::Unchecked);
                    _fAchievements.setData(i, c_filterUniqueValue, !aSelect);
                }
            }
        } else {
            for (int i = 0; i < getRowCount(); i++) {
                if (!ui->TableWidgetContent->isRowHidden(i)) {
                    itemContent(i, (_noValueColumn + 1) + aPos)->setCheckState(aSelect ? Qt::Checked : Qt::Unchecked);
                }
            }
        }
    }
    updateHiddenRows();
}

void FormTablesHeaders::categoryToTable(QString aTitle, QList<QString> aNoValues, QJsonArray aValues, bool aIsNoValue) {
    if (_currentType == TableType::standart) {
        setColumnCount(c_tableAchievementColumnCount);
        _categoriesColumns.clear();
        addNoValueColumn();
        changeHorizontalTitle(_noValueColumn, aTitle);
        for (int j = 0; j < getRowCount(); j++) {
            bool isAchievementCheck = true;
            for(int k = 0; k < aNoValues.size(); k++) {
                if(itemContent(j, c_tableAchievementColumnAppid)->text() == aNoValues[k]) {
                    isAchievementCheck = false;
                    break;
                }
            }
            setItemContent(j, _noValueColumn, createFlag(isAchievementCheck));
        }
        for(auto title: aValues) {
            addCategoryColumn();
            changeHorizontalTitle(getColumnCount() - 1, title.toObject().value("Title").toString());
            for (int j = 0; j < getRowCount(); j++) {
                bool isAchievementCheck = false;
                for (auto appid: title.toObject().value("Achievements").toArray()) {
                    if (itemContent(j, c_tableAchievementColumnAppid)->text() == appid.toString()) {
                        isAchievementCheck = true;
                        break;
                    }
                }
                setItemContent(j, getColumnCount() - 1, createFlag(isAchievementCheck));
            }
        }
        setValuesMode(!aIsNoValue);
    }
}

bool FormTablesHeaders::swapCategoryColumns(int aPosOld, int aPosNew) {
    if((_noValueColumn == -1) ||
        (aPosNew < 0) ||
        (aPosNew > getColumnCount() - (_noValueColumn + 1)) ||
        (aPosOld < 0) ||
        (aPosOld > getColumnCount() - (_noValueColumn + 1))) {
        return false;
    } else {
        for (int j = 0; j < getRowCount(); j++) {
            Qt::CheckState tempCheckState = itemContent(j, (_noValueColumn + 1) + aPosOld)->checkState();
            itemContent(j, (_noValueColumn + 1) + aPosOld)->setCheckState(itemContent(j, (_noValueColumn + 1) + aPosNew)->checkState());
            itemContent(j, (_noValueColumn + 1) + aPosNew)->setCheckState(tempCheckState);
        }
        QString tempHorisontalHeader = getTableContent()->horizontalHeaderItem((_noValueColumn + 1) + aPosOld)->text();
        getTableContent()->horizontalHeaderItem((_noValueColumn + 1) + aPosOld)->setText(getTableContent()->horizontalHeaderItem((_noValueColumn + 1) + aPosNew)->text());
        getTableContent()->horizontalHeaderItem((_noValueColumn + 1) + aPosNew)->setText(tempHorisontalHeader);
        return true;
    }
}

void FormTablesHeaders::cancelCategory() {
    while (_categoriesColumns.size() > 0) {
        for (auto friendColumn: _friendsColumns) {
            if (friendColumn > _categoriesColumns.last()) {
                friendColumn--;
            }
        }
        removeColumn(_categoriesColumns.last());
        _categoriesColumns.removeLast();
    }
    if (_noValueColumn > -1) {
        for (auto friendColumn: _friendsColumns) {
            if (friendColumn > _noValueColumn) {
                friendColumn--;
            }
        }
        removeColumn(_noValueColumn);
        _isNoValue = -1;
    }
    _isUnique = false;
}
#define CategoryEnd }

#define Friends {
bool FormTablesHeaders::addFriendColumn(SProfile aFriendProfile) {
    int column=ui->TableWidgetContent->columnCount();
    insertColumn(column);
    changeHorizontalTitle(column, aFriendProfile._personaName);
    QLabel *avatarFriend = new QLabel;
    avatarFriend->setPixmap(aFriendProfile.getPixmapAvatar());
    avatarFriend->setToolTip(aFriendProfile._personaName);
    avatarFriend->setAlignment(Qt::AlignCenter);
    ui->TableWidgetHorizontalHeader->setCellWidget(0, column, avatarFriend);
    SAchievements achievementsFriends = _achievements;
    achievementsFriends.set(new SAchievementsPlayer (QString::number(_game._appID), aFriendProfile._steamID, false, this));
//    Threading LoadFriendTable(this);
//    LoadFriendTable.AddThreadFriendAchievements(ui->TableWidgetAchievements,ach,col,c_tableCompareColumnAppid);
    _fCompare.setCol(_fCompare.getCol() + 1);
    setColumnWidth(column, 80);

    _friendsColumns.push_back(column);
    int totalReach = 0;
    int totalNotReach = 0;
    for(int i = 0; i < ui->TableWidgetContent->rowCount(); i++) {
        for(auto &achievement: achievementsFriends) {
            if(achievement._apiName == ui->TableWidgetContent->item(i, c_tableAchievementColumnAppid)->text()) {
                QTableWidgetItem *itemReached;
                if(achievement._achieved == 1) {
                    itemReached = new QTableWidgetItem(tr("Получено %1").arg(achievement._unlockTime.toString("yyyy.MM.dd hh:mm")));
                    itemReached->setToolTip(achievement._unlockTime.toString("yyyy.MM.dd hh:mm"));
                    totalReach++;
                } else {
                    itemReached = new QTableWidgetItem(tr("Не получено"));
                    totalNotReach++;
                }
                itemReached->setTextAlignment(Qt::AlignCenter);
                ui->TableWidgetContent->setItem(i, column, itemReached);
                break;
            }
        }
    }
    if((totalReach == 0) && (totalNotReach == 0)) {
        ui->TableWidgetHorizontalHeader->setItem(1, column, new QTableWidgetItem(QString("%1\n%2").arg(tr("Профиль не"), tr("публичный"))));
        return false;
    } else {
        ui->TableWidgetHorizontalHeader->setItem(1, column, new QTableWidgetItem(QString("%1/%2\n%3%").arg(QString::number(totalReach),
                                                                                                           QString::number(totalReach + totalNotReach),
                                                                                                           QString::number(100.0 * totalReach / (totalReach + totalNotReach)))));
        return true;
    }
}

void FormTablesHeaders::removeFriendColumn(QString aFriendName) {
    int columnFriend = 0;
    int indexFriend = 0;
    for (auto &column: _friendsColumns) {
        if (ui->TableWidgetHorizontalHeader->horizontalHeaderItem(column)->text() == aFriendName) {
            columnFriend = column;
            removeFriendColumn(indexFriend);
            break;
        }
        indexFriend++;
    }
    if(_fCompare.getCol() >= columnFriend) {
        _fCompare.removeCol(_fCompare.getCol() - (getColumnCount() - columnFriend + 1));
    }
    updateHiddenRows();
}

void FormTablesHeaders::removeFriendColumn(int aColumn) {
    int column = _friendsColumns.takeAt(aColumn);
    removeColumn(column);
    for(auto &fColumn: _friendsColumns) {
        if(fColumn > column) {
            fColumn--;
        }
    }
}

void FormTablesHeaders::updateFilterWithFriend(QString aFriendName, ReachedType aType) {
    int columnFriend = 0;
    for (auto &column: _friendsColumns) {
        if (ui->TableWidgetHorizontalHeader->horizontalHeaderItem(column)->text() == aFriendName){
            columnFriend = column;
            break;
        }
    }
    int filterColumn = _fCompare.getCol() - (getColumnCount() - columnFriend);
    switch (aType) {
    case ReachedType::all: {
        for (int i = 0; i < getRowCount(); i++) {
            _fCompare.setData(i, filterColumn, true);
        }
        break;
    }
    case ReachedType::reached: {
        for (int i = 0; i < getRowCount(); i++) {
            _fCompare.setData(i, filterColumn, itemContent(i, columnFriend)->text().indexOf(".") > -1);
        }
        break;
    }
    case ReachedType::notReached: {
        for (int i = 0; i < getRowCount(); i++) {
            _fCompare.setData(i, filterColumn, itemContent(i, columnFriend)->text().indexOf(".") == -1);
        }
        break;
    }
    default: {
        break;
    }
    }
    updateHiddenRows();
}
#define FriendsEnd }

void FormTablesHeaders::setType(TableType aNewType) {
    switch (aNewType) {
    case TableType::compare: {
        _visibleHorizontal = true;
        ui->TableWidgetHorizontalHeader->setVisible(true);
        ui->TableWidgetContent->horizontalHeader()->setVisible(false);
        for (const int &index: _categoriesColumns) {
            setVisibleColumn(index, false);
        }
        if (_noValueColumn > -1) {
            setVisibleColumn(_noValueColumn, false);
        }
        for (const int &index: _friendsColumns) {
            setVisibleColumn(index, true);
        }
        resize();
        break;
    }
    case TableType::standart: {
        _visibleHorizontal = false;
        ui->TableWidgetHorizontalHeader->setVisible(false);
        ui->TableWidgetContent->horizontalHeader()->setVisible(true);
        for (const int &index: _categoriesColumns) {
            setVisibleColumn(index, true);
        }
        if (_noValueColumn > -1) {
            setVisibleColumn(_noValueColumn, true);
        }
        for (const int &index: _friendsColumns) {
            setVisibleColumn(index, false);
        }
        resize();
        break;
    }
    }
    _currentType = aNewType;
    updateHiddenRows();
    //!!!!!!!!!!!!!
}

TableType FormTablesHeaders::getType() {
    return _currentType;
}

bool FormTablesHeaders::pullTable() {
    if (_achievements.getStatus() == StatusValue::success) {
        setRowCount(_achievements.getCount());
        for (int i = 0; i < _achievements.getCount(); i++) {
            setRowHeight(i, 66 + 18);
        }
        _fAchievements.setRow(getRowCount());
        _fCompare.setRow(getRowCount());
        createThread();
        return true;
    } else {
        setRowCount(1);
        setItemHorizontalHeader(c_tableAchievementColumnAppid, 1, new QTableWidgetItem(tr("Ошибка")));
        setVisibleColumn(c_tableAchievementColumnTitle, false);
        setVisibleColumn(c_tableAchievementColumnDescription, false);
        setVisibleColumn(c_tableAchievementColumnWorld, false);
        setVisibleColumn(c_tableAchievementColumnReachedMy, false);
        return false;
    }
}

void FormTablesHeaders::createThread() {
    Threading *loadTable = new Threading(this);
    loadTable->AddThreadAchievements(c_tableAchievementColumnAppid,  c_tableAchievementColumnTitle,  c_tableAchievementColumnDescription, c_tableAchievementColumnWorld,
                                     c_tableAchievementColumnReachedMy, &_achievements, ui->TableWidgetContent);
    connect (loadTable, &Threading::s_achievements_progress, this, [=](int progress, int row) {
        emit s_achievementsLoaded(progress, row);
    });
    connect (loadTable, &Threading::s_achievements_finished, this, &FormTablesHeaders::onTablePulled);
}

void FormTablesHeaders::onTablePulled(int reached, int notReached) {
    QLabel *labelCompareSummary = new QLabel(this);
    setWidgetHorizontalHeader(1, c_tableAchievementColumnReachedMy, labelCompareSummary);
    labelCompareSummary->setText(QString("%1/%2\n%3%").arg(
                                     QString::number(reached),
                                     QString::number(reached + notReached),
                                     QString::number(100.0 * reached / (reached + notReached))));
    ui->TableWidgetContent->resizeRowsToContents();
    int row = 0;
    for (auto &achievement: _achievements) {
        //создание картинок
        QLabel *iconGame = new QLabel(this);
        getTableContent()->setCellWidget(row, c_tableAchievementColumnIcon, iconGame);
        if (achievement._displayName != "") {
            iconGame->setPixmap(achievement.getIcon(_game._appID));

            ui->TableWidgetContent->resizeRowToContents(row);
            if(ui->TableWidgetContent->rowHeight(row) < (64 + 18)) {
                ui->TableWidgetContent->setRowHeight(row, 64 + 18);
            }
            row++;
        } else {
            setRowCount(getRowCount() - 1);
        }
    }
    emit s_tablePulled(reached, notReached);
}

#define Filter {
void FormTablesHeaders::updateFilterWithMyProfile(ReachedType aType, bool aSolo, bool aCompare) {
    switch (aType) {
    case ReachedType::all: {
        if (aSolo) {
            if (aCompare) {
                for (int i = 0; i < getRowCount(); i++) {
                    _fAchievements.setData(i, c_filterReached, true);
                    _fCompare.setData(i, c_filterReached, true);
                }
            } else {
                for (int i = 0; i < getRowCount(); i++) {
                    _fAchievements.setData(i, c_filterReached, true);
                }
            }
        } else {
            if (aCompare) {
                for (int i = 0; i < getRowCount(); i++) {
                    _fCompare.setData(i, c_filterReached, true);
                }
            }
        }
        break;
    }
    case ReachedType::reached: {
        if (aSolo) {
            if (aCompare) {
                for (int i = 0; i < getRowCount(); i++) {
                    _fAchievements.setData(i, c_filterReached, itemContent(i, c_tableAchievementColumnReachedMy)->text().indexOf(".") > -1);
                    _fCompare.setData(i, c_filterReached, itemContent(i, c_tableAchievementColumnReachedMy)->text().indexOf(".") > -1);
                }
            } else {
                for (int i = 0; i < getRowCount(); i++) {
                    _fAchievements.setData(i, c_filterReached, itemContent(i, c_tableAchievementColumnReachedMy)->text().indexOf(".") > -1);
                }
            }
        } else {
            if (aCompare) {
                for (int i = 0; i < getRowCount(); i++) {
                    _fCompare.setData(i, c_filterReached, itemContent(i, c_tableAchievementColumnReachedMy)->text().indexOf(".") > -1);
                }
            }
        }
        break;
    }
    case ReachedType::notReached: {
        if (aSolo) {
            if (aCompare) {
                for (int i = 0; i < getRowCount(); i++) {
                    _fAchievements.setData(i, c_filterReached, itemContent(i, c_tableAchievementColumnReachedMy)->text().indexOf(".") == -1);
                    _fCompare.setData(i, c_filterReached, itemContent(i, c_tableAchievementColumnReachedMy)->text().indexOf(".") == -1);
                }
            } else {
                for (int i = 0; i < getRowCount(); i++) {
                    _fAchievements.setData(i, c_filterReached, itemContent(i, c_tableAchievementColumnReachedMy)->text().indexOf(".") == -1);
                }
            }
        } else {
            if (aCompare) {
                for (int i = 0; i < getRowCount(); i++) {
                    _fCompare.setData(i, c_filterReached, itemContent(i, c_tableAchievementColumnReachedMy)->text().indexOf(".") == -1);
                }
            }
        }
        break;
    }
    default: {
        break;
    }
    }
    updateHiddenRows();
}

void FormTablesHeaders::updateFilterCategoriesColumns(int aCategories) {
    _fAchievements.setCol(aCategories + c_filterColumnCount);
    _fCompare.setCol(aCategories + c_filterColumnCount + getColumnCount() - c_tableAchievementColumnCount);
    updateHiddenRows();
}

void FormTablesHeaders::updateFilterFavorite(QJsonArray aFavoritesAchievement) {
    if (aFavoritesAchievement == QJsonArray()) {
        for (int i = 0; i < getRowCount(); i++) {
            _fAchievements.setData(i, c_filterFavorite, true);
            _fCompare.setData(i, c_filterFavorite, true);
        }
    } else {
        for (int i = 0; i < getRowCount(); i++) {
            bool accept = false;
            for (auto value: aFavoritesAchievement) {
                if (value.toObject().value("id").toString() == _achievements[i]._apiName) {
                    accept = true;
                    break;
                }
            }
            _fAchievements.setData(i, c_filterFavorite, accept);
            _fCompare.setData(i, c_filterFavorite, accept);
        }
    }
    updateHiddenRows();
}

void FormTablesHeaders::updateFilterTextAchievement(QString aNewText, bool aSolo, bool aCompare) {
    if (aSolo) {
        if (aCompare) {
            for (int i = 0; i < getRowCount(); i++) {
                _fAchievements.setData(i, c_filterName, ((itemContent(i, c_filterName + 2)->text().toLower().indexOf(aNewText.toLower()) > -1)
                                                       ||(itemContent(i, c_tableAchievementColumnDescription)->text().toLower().indexOf(aNewText.toLower()) > -1)));
                _fCompare.setData(i, c_filterName, ((itemContent(i, c_filterName + 2)->text().toLower().indexOf(aNewText.toLower()) > -1)
                                                    ||(itemContent(i, c_tableAchievementColumnDescription)->text().toLower().indexOf(aNewText.toLower()) > -1)));
            }
        } else {
            for (int i = 0; i < getRowCount(); i++) {
                _fAchievements.setData(i, c_filterName, ((itemContent(i, c_filterName + 2)->text().toLower().indexOf(aNewText.toLower()) > -1)
                                                       ||(itemContent(i, c_tableAchievementColumnDescription)->text().toLower().indexOf(aNewText.toLower()) > -1)));
            }
        }
    } else {
        if (aCompare) {
            for (int i = 0; i < getRowCount(); i++) {
                _fCompare.setData(i, c_filterName, ((itemContent(i, c_filterName + 2)->text().toLower().indexOf(aNewText.toLower()) > -1)
                                                    ||(itemContent(i, c_tableAchievementColumnDescription)->text().toLower().indexOf(aNewText.toLower()) > -1)));
            }
        }
    }
    updateHiddenRows();
}

void FormTablesHeaders::updateFilterCategory(int aCategoryIndex, bool aClear, QList<QString> aAchievementNames) {
    if (aClear) {
        for (int i = 0; i < getRowCount(); i++) {
            _fAchievements.setData(i, c_filterEndConstValues + aCategoryIndex, true);
            _fCompare.setData(i, c_filterEndConstValues + aCategoryIndex, true);
        }
    } else {
        for (int i = 0; i < getRowCount(); i++) {
            _fAchievements.setData(i, c_filterEndConstValues + aCategoryIndex, false);
            _fCompare.setData(i, c_filterEndConstValues + aCategoryIndex, false);
            for (auto &achievementName: aAchievementNames) {
                if (itemContent(i, c_tableAchievementColumnAppid)->text() == achievementName) {
                    _fAchievements.setData(i, c_filterEndConstValues + aCategoryIndex, true);
                    _fCompare.setData(i, c_filterEndConstValues + aCategoryIndex, true);
                    break;
                }
            }
        }
    }
    updateHiddenRows();
}
#define FilterEnd }
