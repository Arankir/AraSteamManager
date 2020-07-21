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
FormGames::FormGames(SProfile aProfile, SGames aGames, QWidget *aParent): QWidget(aParent), ui(new Ui::FormGames), _profile(aProfile),  _games(aGames), _favorites("games") {
    ui->setupUi(this);
    initComponents();
}

void FormGames::initComponents() {
    ui->TableWidgetGames->setMouseTracking(false);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->TableWidgetGames->setColumnCount(c_tableColumnCount);
    _games.sort();
    updateSettings();
    retranslate();
    ui->TableWidgetGames->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableWidgetGames->setAlternatingRowColors(true);

    ui->FrameGroup->stackUnder(ui->TableWidgetGames);

    _animate = new QPropertyAnimation(ui->FrameGroup, "geometry");
    _animate->setDuration(300);

    this->setMouseTracking(true);
    ui->FrameGames->setMouseTracking(true);
    ui->TableWidgetGames->viewport()->setMouseTracking(true);
    enableMouseTracking(ui->FrameGames->children());
//    enableMouseTracking(ui->TableWidgetGames->children());
//    enableMouseTracking(ui->TableWidgetGames->viewport()->children());
//    ui->FrameGames->setMouseTracking(true);
//    ui->FrameGroup->setMouseTracking(true);
//    ui->TableWidgetGames->setMouseTracking(true);
//    ui->TableWidgetGames->viewport()->setMouseTracking(true);
//    ui->TableWidgetGames->installEventFilter(this);
    //ui->TableWidgetGames->viewport()->installEventFilter(this);

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
    connect(ui->LineEditGame,       &QLineEdit::textChanged,          this, &FormGames::lineEditGame_TextChanged);
    connect(ui->ButtonFind,         &QPushButton::clicked,            this, &FormGames::buttonFind_Clicked);
    connect(ui->TableWidgetGames,   &QTableWidget::cellDoubleClicked, this, &FormGames::tableWidgetGames_CellDoubleClicked);
    connect(ui->TableWidgetGames,   &QTableWidget::cellClicked,       this, &FormGames::tableWidgetGames_CellClicked);
    connect(ui->ButtonAchievements, &QPushButton::clicked,            this, &FormGames::buttonAchievements_Clicked);
    connect(ui->ButtonFavorite,     &QPushButton::clicked,            this, &FormGames::buttonFavorite_Clicked);
    connect(ui->ButtonHide,         &QPushButton::clicked,            this, &FormGames::buttonHide_Clicked);
#define ConnectsEnd }
    createThread();
}

void FormGames::enableMouseTracking(const QObjectList &aChildren) {
    for(QObject *child: aChildren) {
        QWidget *childWidget = qobject_cast<QWidget*>(child);

        if(childWidget) {
            childWidget->setMouseTracking(true);
            enableMouseTracking(childWidget->children());
        }
    }
}

void FormGames::updateSettings() {
    _setting.syncronizeSettings();
    setIcons();
}

void FormGames::setIcons() {
    QString iconsColor = _setting.getIconsColor();
    ui->ButtonFind->setIcon(QIcon("://" + iconsColor + "/find.png"));
    ui->ButtonFavorite->setIcon(QIcon("://" + iconsColor + "/favorites.png"));
    ui->ButtonHide->setIcon(QIcon("://" + iconsColor + "/hide.png"));
    ui->ButtonCreateGroup->setIcon(QIcon(":/create.png"));
    ui->ButtonChangeGroup->setIcon(QIcon("://" + iconsColor + "/change.png"));
}

void FormGames::onFinish() {
    ui->TableWidgetGames->setColumnHidden(c_tableColumnAppid, true);
    ui->TableWidgetGames->setColumnHidden(c_tableColumnIndex, true);
    ui->TableWidgetGames->resizeColumnsToContents();
    QFile fileHide;
    fileHide.setFileName(_setting._pathHide + _profile._steamID + ".txt");
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
        SAchievementsPlayer *achievementsGame = new SAchievementsPlayer(QString::number(game._appID), _profile._steamID);
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
//    enableMouseTracking(ui->TableWidgetGames->children());
//    ui->TableWidgetGames->viewport()->setMouseTracking(true);
//    enableMouseTracking(ui->TableWidgetGames->viewport()->children());
//    ui->TableWidgetGames->installEventFilter(this);
//    ui->TableWidgetGames->viewport()->installEventFilter(this);
    ui->LineEditGame->setFocus();
}

bool FormGames::eventFilter(QObject *obj, QEvent *event) {
//       if (obj == ui->TableWidgetGames)
//       {
//           if (event->type() == QEvent::MouseButtonPress)
//               qDebug() << "table mouse press event";
//           else if (event->type() == QEvent::MouseMove)
//               qDebug() << "table mouse moveevent";
//       }
//       else if (obj == ui->TableWidgetGames->viewport())
//       {
//           if (event->type() == QEvent::MouseButtonPress)
//               qDebug() << "table->viewport mouse press event";
//           else if (event->type() == QEvent::MouseMove)
//               qDebug() << "table->viewport mouse moveevent";
//       }
//       return QObject::eventFilter(obj, event);
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
    ui->TableWidgetGames->setGeometry(c_widthVisibleGroup, 0, ui->FrameGames->width() - c_widthVisibleGroup, ui->FrameGames->height());

    QRect invisibleRect(c_invisibleGroupPos, QPoint(c_invisibleGroupPos.x() + c_widthGroup, height()));
    QRect visibleRect(c_visibleGroupPos, QPoint(c_visibleGroupPos.x() + c_widthGroup, height()));

    ui->FrameGroup->setGeometry(_isGroupShow ? visibleRect : invisibleRect);
    ui->FrameGroup->raise();
}

void FormGames::showHideSlideWidget(bool aShowing) {
    QRect invisibleRect(c_invisibleGroupPos, QPoint(c_invisibleGroupPos.x() + c_widthGroup, height()));
    QRect visibleRect(c_visibleGroupPos, QPoint(c_visibleGroupPos.x() + c_widthGroup, height()));

    if (aShowing) {
        _animate->setStartValue(invisibleRect);
        _animate->setEndValue(visibleRect);
    } else {
        _animate->setStartValue(visibleRect);
        _animate->setEndValue(invisibleRect);
    }
    _animate->start();

    _isGroupShow = aShowing;
}

void FormGames::mouseMoveEvent(QMouseEvent *aEvent) {
    qDebug()<< "pos"<< aEvent->x()<< aEvent->y();
    if (aEvent->pos().x() < c_widthVisibleGroup) {
        if (!_isGroupShow) {
            showHideSlideWidget(true);
        }
    } else {
        if ((_isGroupShow) && (aEvent->pos().x() > (c_visibleGroupPos.x() + c_widthGroup))) {
            showHideSlideWidget(false);
        }
    }
}

void FormGames::createThread() {
    Threading *loadTable = new Threading(this);
    loadTable->AddThreadGames(c_tableColumnAppid, c_tableColumnIndex, c_tableColumnName, ui->TableWidgetGames, _games);
    connect (loadTable, &Threading::s_games_progress, this, [=](int progress, int row) {
        ui->ProgressBarLoading->setValue(progress);
        emit s_achievementsLoaded(progress, row);
    });
    connect (loadTable, &Threading::s_games_finished, this, &FormGames::onFinish);
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
    QString iconsColor = _setting.getIconsColor();
    if(isFavorite) {
        ui->ButtonFavorite->setIcon(QIcon("://" + iconsColor + "/in_favorites.png"));
    } else {
        ui->ButtonFavorite->setIcon(QIcon("://" + iconsColor + "/favorites.png"));
    }
    if(ui->TableWidgetGames->item(aRow,c_tableColumnName)->foreground() == Qt::red) {
        ui->ButtonHide->setIcon(QIcon("://" + iconsColor + "/unhide.png"));
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
    newValue["idUser"] = _profile._steamID;
    ui->ButtonFavorite->setFixedSize(ui->ButtonFavorite->size());
    QString iconsColor = _setting.getIconsColor();
    if(_favorites.addValue(newValue, true)) {
        //Категория добавилась
        ui->ButtonFavorite->setIcon(QIcon("://" + iconsColor + "/in_favorites.png"));
    } else {
        //Категория уже есть (удалилась)
        ui->ButtonFavorite->setIcon(QIcon("://" + iconsColor + "/favorites.png"));
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
         savePath = _setting._pathHide + _profile._steamID + ".txt";
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
    ui->ButtonHide->setIcon(QIcon("://" + _setting.getIconsColor() + "/unhide.png"));
}
#define FunctionsEnd }
