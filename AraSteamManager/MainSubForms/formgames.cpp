#include "formgames.h"
#include "ui_formgames.h"

#define Constants {
constexpr int c_tableColumnAppid = 0;
constexpr int c_tableColumnIndex = 1;
constexpr int c_tableColumnIcon = 2;
constexpr int c_tableColumnName = 3;
constexpr int c_tableColumnProgress = 4;
constexpr int c_tableColumnCount = 5;
#define ConstantsEnd }

#define Init {
FormGames::FormGames(QString aId, SGames aGames, QWidget *aParent): QWidget(aParent), ui(new Ui::FormGames), _id(aId),  _games(aGames), _favorites("games") {
    ui->setupUi(this);
    initComponents();
}

void FormGames::initComponents() {
    ui->TableWidgetGames->setMouseTracking(false);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->TableWidgetGames->setColumnCount(c_tableColumnCount);
    _games.sort();
    updateTheme();
    retranslate();
    ui->TableWidgetGames->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetGames->setAlternatingRowColors(true);

    ui->FrameGroup->stackUnder(ui->TableWidgetGames);
    _geometryGroup = QRect(0, 0, 0, ui->FrameGames->height());
    //ui->TableWidgetGames->installEventFilter(this);
    this->setMouseTracking(true);
    ui->FrameGames->setMouseTracking(true);
    ui->TableWidgetGames->setMouseTracking(true);
    ui->TableWidgetGames->viewport()->setMouseTracking(true);
    ui->FrameGroup->setVisible(false);

    ui->TableWidgetGames->setSortingEnabled(true);
    ui->ProgressBarLoading->setVisible(false);
    ui->TableWidgetGames->setRowCount(_games.getCount());
    for (int i = 0; i < _games.getCount(); i++) {
        ui->TableWidgetGames->setRowHeight(i, 33);
        ui->TableWidgetGames->setCellWidget(i, c_tableColumnProgress, new QProgressBar);
    }
    //загрузить группы
    ui->TableWidgetGames->setColumnWidth(c_tableColumnIcon, 33);
    ui->TableWidgetGames->setColumnWidth(c_tableColumnName, 300);
#define Connects {
    connect(ui->LineEditGame, &QLineEdit::textChanged, this, &FormGames::lineEditGame_TextChanged);
    connect(ui->ButtonFind, &QPushButton::clicked, this, &FormGames::buttonFind_Clicked);
    connect(ui->TableWidgetGames, &QTableWidget::cellDoubleClicked, this, &FormGames::tableWidgetGames_CellDoubleClicked);
    connect(ui->TableWidgetGames, &QTableWidget::cellClicked, this, &FormGames::tableWidgetGames_CellClicked);
    connect(ui->ButtonAchievements, &QPushButton::clicked, this, &FormGames::buttonAchievements_Clicked);
    connect(ui->ButtonFavorite, &QPushButton::clicked, this, &FormGames::buttonFavorite_Clicked);
    connect(ui->ButtonHide, &QPushButton::clicked, this, &FormGames::buttonHide_Clicked);
#define ConnectsEnd }
    Threading loadTable(this);
    loadTable.AddThreadGames(c_tableColumnAppid, c_tableColumnIndex, c_tableColumnName, ui->TableWidgetGames, _games);
}

void FormGames::updateTheme() {
    switch(_setting.getTheme()) {
        case 1:
            _theme = "white";
            break;
        case 2:
            _theme = "black";
            break;
    }
    setIcons();
}

void FormGames::setIcons() {
    ui->ButtonFind->setIcon(QIcon("://" + _theme + "/find.png"));
    ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/favorites.png"));
    ui->ButtonHide->setIcon(QIcon("://" + _theme + "/hide.png"));
    ui->ButtonCreateGroup->setIcon(QIcon(":/create.png"));
    ui->ButtonChangeGroup->setIcon(QIcon("://" + _theme + "/change.png"));
}

void FormGames::progressLoading(int aProgress, int aRow){
    ui->ProgressBarLoading->setValue(aProgress);
    //if(ui->ProgressBarLoading->value()==ui->ProgressBarLoading->maximum()-1){
        //ui->ProgressBarLoading->setVisible(false);
    //}
}

void FormGames::onFinish() {
    ui->TableWidgetGames->setColumnHidden(c_tableColumnAppid, true);
    ui->TableWidgetGames->setColumnHidden(c_tableColumnIndex, true);
    ui->TableWidgetGames->resizeColumnsToContents();
    QFile fileHide;
    fileHide.setFileName(_setting._pathHide + _id + ".txt");
    if(fileHide.open(QIODevice::ReadOnly)) {
        while(!fileHide.atEnd()) {
            _hide << QString::fromLocal8Bit(fileHide.readLine()).remove("\r\n").remove("\n");
        }
        fileHide.close();
    }
    fileHide.setFileName(_setting._pathHide + "All.txt");
    if(fileHide.open(QIODevice::ReadOnly)) {
        while(!fileHide.atEnd()) {
            _hide << QString::fromLocal8Bit(fileHide.readLine()).remove("\r\n").remove("\n").split("%%").at(0);
        }
        fileHide.close();
    }
    QStringList hideList = _hide;
    _achievements = new SAchievementsPlayer[_games.getCount()];
    int row = 0;
    for(auto &game: _games) {
        QString path = _setting._pathImagesIconGames + game._img_icon_url + ".jpg";
        QLabel *iconGame = new QLabel;
        ui->TableWidgetGames->setCellWidget(row, c_tableColumnIcon, iconGame);
        if(!QFile::exists(path)) {
            iconGame->setBaseSize(QSize(32, 32));
            new RequestImage(iconGame, "http://media.steampowered.com/steamcommunity/public/images/apps/" +
                         QString::number(game._appID) + "/" + game._img_icon_url + ".jpg", path, true, this);
        } else {
            iconGame->setPixmap(QPixmap(path));
        }
        SAchievementsPlayer *achievementsGame = new SAchievementsPlayer(QString::number(game._appID), _id);
        achievementsGame->_index = row;
        connect(achievementsGame, SIGNAL(s_finished(SAchievementsPlayer)), this, SLOT(onResultAchievements(SAchievementsPlayer)));
        for (int j = 0; j < hideList.size(); j++) {
            if(hideList[j].toInt() == game._appID) {
                ui->TableWidgetGames->setRowHidden(row, true);
                ui->TableWidgetGames->item(row, c_tableColumnName)->setToolTip("StandartColor");
                ui->TableWidgetGames->item(row, c_tableColumnName)->setForeground(Qt::red);
                //static_cast<QPushButton*>(ui->TableWidgetGames->cellWidget(i,c_tableColumnHide))->setEnabled(false);
                hideList.removeAt(j);
                break;
            }
        }
        row++;
    }
    ui->LineEditGame->setFocus();
}

void FormGames::onResultAchievements(SAchievementsPlayer aAchievements) {
    disconnect(&aAchievements, SIGNAL(s_finished(SAchievementsPlayer)), this, SLOT(onResultAchievements(SAchievementsPlayer)));
    QProgressBar *progressBarAchievements = dynamic_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(aAchievements._index, c_tableColumnProgress));
    if (progressBarAchievements) {
        progressBarAchievements->setMaximum(aAchievements.getCount());
        progressBarAchievements->setMinimumSize(QSize(25, 25));
        if(aAchievements.getCount() > 0) {
            int val = 0;
            for (int i = 0; i < aAchievements.getCount(); i++) {
                if(aAchievements[i]._achieved == 1) {
                    val++;
                }
            }
            progressBarAchievements->setValue(val);
        } else {
            progressBarAchievements->setValue(0);
            //static_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(a_achievements.GetIndex(),c_tableColumnProgress))->setEnabled(false);
        }
        ui->TableWidgetGames->setItem(aAchievements._index, c_tableColumnProgress, new QTableWidgetItem(progressBarAchievements->text().rightJustified(4, '0')));
        ui->TableWidgetGames->item(aAchievements._index, c_tableColumnProgress)->setTextAlignment(Qt::AlignRight);
        _achievements[aAchievements._index] = aAchievements;
        emit s_achievementsLoaded(_load++, 0);
        if(_load == _games.getCount()) {
            tableWidgetGames_CellClicked(0, 1);
            int width = 22;
            for(int i = 0; i < ui->TableWidgetGames->columnCount(); i++) {
                width += ui->TableWidgetGames->columnWidth(i);
            }
            emit s_finish(width);
        }
        //ach->deleteLater();
    }
}
#define InitEnd }

#define System {
FormGames::~FormGames() {
    qDebug()<<_numRequests<<"запросов на картинки";
    delete [] _achievements;
    delete ui;
}

void FormGames::changeEvent(QEvent *event) {
    if(event->type() == QEvent::LanguageChange) {
        retranslate();
    }
}

void FormGames::retranslate() {
    ui->retranslateUi(this);
    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnIcon, new QTableWidgetItem(""));
    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnName, new QTableWidgetItem(tr("Название игры")));
    ui->TableWidgetGames->setHorizontalHeaderItem(c_tableColumnProgress, new QTableWidgetItem(tr("Прогресс")));
    ui->ButtonAchievements->setText(tr("Достижения"));
    ui->ButtonFavorite->setText("");
    ui->ButtonHide->setText("");
}

void FormGames::closeEvent(QCloseEvent*) {
    emit s_return_to_profile(this);
    //delete this;
}

void FormGames::resizeEvent(QResizeEvent*) {
    ui->TableWidgetGames->setGeometry(0, 0, ui->FrameGames->width(), ui->FrameGames->height());
    ui->FrameGroup->setGeometry(0, 0, ui->FrameGroup->width(), ui->FrameGames->height());
    ui->FrameGroup->raise();
}

void FormGames::showHideSlideWidget(bool aFlag){
//    qDebug()<<4<<aFlag;
//    if (aFlag)
//        ui->FrameGroup->setGeometry(_geometryGroup);
//    _animate = new QPropertyAnimation(ui->FrameGroup, "geometry");
//    _animate->setDuration(300);

//    QRect startRect(0, 0, 0, height());
//    QRect endRect(0, 0, 300, height());

//    if (aFlag)
//    {
//        _animate->setStartValue(startRect);
//        _animate->setEndValue(endRect);
//        _geometryGroup=endRect;
//    }
//    else
//    {
//        _animate->setStartValue(endRect);
//        _animate->setEndValue(startRect);
//        _geometryGroup=startRect;
//    }
//    _animate->start();
    //connect(_animate, QPropertyAnimations::, ui->FrameGroup->setVisible(!aFlag));
}

void FormGames::mouseMoveEvent(QMouseEvent *aEvent) {
    if (aEvent->pos().x() < 50) {
        qDebug()<<1<<aEvent->pos();
        if (!ui->FrameGroup->isVisible()){
            ui->FrameGroup->show();
            showHideSlideWidget(true);
        }
    } else {
        qDebug()<<2<<aEvent->pos();
        if (ui->FrameGroup->isVisible()) {
            showHideSlideWidget(false);
        }
    }
}

void FormGames::slotShowHideSlide() {
//    if (ui->FrameGroup->isHidden())
//        ui->FrameGroup->show();

//    qDebug()<<3<<ui->FrameGroup->isVisible();
//    showHideSlideWidget(!ui->FrameGroup->isVisible());
}
#define SystemEnd }

#define Filter {
void FormGames::lineEditGame_TextChanged(const QString arg) {
    if(_setting.getVisibleHiddenGames() == 1 && arg != "") {
        for (int i = 0; i < ui->TableWidgetGames->rowCount(); i++) {
            ui->TableWidgetGames->setRowHidden(i, ui->TableWidgetGames->item(i, c_tableColumnName)->text().toLower().indexOf(arg.toLower(), 0) == -1);
        }
    } else {
        for (int i = 0; i < ui->TableWidgetGames->rowCount(); i++) {
            ui->TableWidgetGames->setRowHidden(i, ui->TableWidgetGames->item(i, c_tableColumnName)->text().toLower().indexOf(arg.toLower(), 0) == -1);
            QStringList hideList = _hide;
            for (int j = 0; j < hideList.size(); j++) {
                if(hideList[j] == ui->TableWidgetGames->item(i, c_tableColumnAppid)->text()) {
                    ui->TableWidgetGames->setRowHidden(i, true);
                    hideList.removeAt(j);
                    break;
                }
            }
        }
    }
}

void FormGames::buttonFind_Clicked() {
    lineEditGame_TextChanged(ui->LineEditGame->text());
}
#define FilterEnd }

#define Functions {
void FormGames::tableWidgetGames_CellDoubleClicked(int aRow, int) {
    buttonAchievements_Clicked();
    //this->findChild<QButtonWithData*>("ButtonAchievements"+ui->TableWidgetGames->item(row,0)->text())->click();
}

void FormGames::tableWidgetGames_CellClicked(int aRow, int) {
    _selectedGame = ui->TableWidgetGames->item(aRow, c_tableColumnAppid)->text();
    _selectedIndex = ui->TableWidgetGames->item(aRow, c_tableColumnIndex)->text();
    QLabel *lGameIcon = dynamic_cast<QLabel*>(ui->TableWidgetGames->cellWidget(aRow, c_tableColumnIcon));
    if(lGameIcon) {
        ui->LabelIconGame->setPixmap(*lGameIcon->pixmap());
    } else {
        ui->LabelIconGame->setPixmap(QPixmap());
    }
    ui->LabelTitleGame->setText(ui->TableWidgetGames->item(aRow, c_tableColumnName)->text());
    QProgressBar *progressBarSelectedGame = dynamic_cast<QProgressBar*>(ui->TableWidgetGames->cellWidget(aRow, c_tableColumnProgress));
    if (progressBarSelectedGame) {
        ui->ProgressBarSelectedGame->setMaximum(progressBarSelectedGame->maximum());
        ui->ProgressBarSelectedGame->setValue(progressBarSelectedGame->value());
    }
    QJsonArray favorites = _favorites.getValues();
    bool isFavorite = false;
    for(auto favorite: favorites) {
        if(favorite.toObject().value("id").toString() == _selectedGame) {
            isFavorite = true;
            break;
        }
    }
    if(isFavorite) {
        ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/in_favorites.png"));
    } else {
        ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/favorites.png"));
    }
    if(ui->TableWidgetGames->item(aRow,c_tableColumnName)->foreground() == Qt::red) {
        ui->ButtonHide->setIcon(QIcon("://" + _theme + "/unhide.png"));
    }
    ui->FrameGame->setVisible(true);
}

void FormGames::buttonAchievements_Clicked() {
    SAchievementsPercentage Percentage(_selectedGame, false);
    if (Percentage.getCount() == 0) {
        QMessageBox::warning(this, tr("Ошибка"), tr("В этой игре нет достижений"));
    } else {
        //ui->TableWidgetGames->setEnabled(false);
        ui->ProgressBarLoading->setMaximum(ui->ProgressBarSelectedGame->maximum());
        //ui->ProgressBarLoading->setVisible(true);
        emit s_showAchievements(_achievements[_selectedIndex.toInt()], _games[_selectedIndex.toInt()]);
    }
}

void FormGames::buttonFavorite_Clicked() {
    QJsonObject newValue;
    newValue["id"] = QString::number(_games[_selectedIndex.toInt()]._appID);
    newValue["name"] = _games[_selectedIndex.toInt()]._name;
    newValue["icon"] = _games[_selectedIndex.toInt()]._img_icon_url;
    newValue["idUser"] = _id;
    ui->ButtonFavorite->setFixedSize(ui->ButtonFavorite->size());
    if(_favorites.addValue(newValue, true)) {
        //Категория добавилась
        ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/in_favorites.png"));
    } else {
        //Категория уже есть (удалилась)
        ui->ButtonFavorite->setIcon(QIcon("://" + _theme + "/favorites.png"));
    }
}

void FormGames::buttonHide_Clicked() {
    QString savePath = "";
    QMessageBox question(QMessageBox::Question,
                           tr("Внимание!"),
                           tr("Вы уверены, что хотите скрыть эту игру?"));
    QAbstractButton *btnProfile = question.addButton(tr("Да, но только для этого аккаунта"), QMessageBox::YesRole);
    QAbstractButton *btnAll = question.addButton(tr("Да, для всех аккаунтов"), QMessageBox::YesRole);
    question.addButton(tr("Отмена"), QMessageBox::NoRole);
    question.exec();
    if(question.clickedButton() == btnProfile) {
         savePath = _setting._pathHide + _id + ".txt";
    } else if(question.clickedButton() == btnAll) {
         savePath = _setting._pathHide + "All.txt";
    } else {
        return;
    }

    Settings::createDir(savePath);
    QFile fileHide(savePath);
    fileHide.open(QIODevice::Append | QIODevice::Text);
    QTextStream writeStream(&fileHide);
    writeStream <<_games[_selectedIndex.toInt()]._appID <<(savePath == _setting._pathHide + "All.txt" ? "%%"
                                                             + _games[_selectedIndex.toInt()]._img_icon_url + "%%"
                                                             + _games[_selectedIndex.toInt()]._name : "") <<"\n";
    fileHide.close();
    for (int i = 0; i < _games.getCount(); i++) {
        if(_games[_selectedIndex.toInt()]._name == ui->TableWidgetGames->item(i, c_tableColumnName)->text()) {
            ui->TableWidgetGames->item(i, c_tableColumnName)->setForeground(Qt::red);
            ui->TableWidgetGames->setRowHidden(i, true);
            break;
        }
    }
    ui->ButtonHide->setFixedSize(ui->ButtonHide->size());
    ui->ButtonHide->setIcon(QIcon("://" + _theme + "/unhide.png"));
}
#define FunctionsEnd }
