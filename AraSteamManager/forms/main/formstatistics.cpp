#include "formstatistics.h"
#include "ui_formstatistics.h"
#include "classes/common/theme.h"
#include "forms/widgets/formfrienditemgraph.h"
#include "forms/main/formgames.h"
#include "subWidgets/charts/achievementcountchart.h"
#include "subWidgets/charts/achievementcompletedpiechart.h"
#include "classes/common/generalfunctions.h"
#include "classes/common/images.h"

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QPushButton>
#include <math.h>
#include <QGraphicsPixmapItem>
#include <QSpacerItem>
#include <QMenu>
#include <QToolTip>

constexpr int c_steamReleaseYear = 2002;
constexpr int c_secsInDay = 60 * 60 * 24;

constexpr int c_minPixmapSize = 32;
constexpr int c_maxPixmapSize = 128;
constexpr int c_pixmapSpace = 2;

FormStatistics::FormStatistics(QWidget *aParent): Form(aParent), ui(new Ui::FormStatistics), scene_(new QGraphicsScene()) {
    ui->setupUi(this);
    init();
}

FormStatistics::~FormStatistics() {
    delete ui;
}

void FormStatistics::init() {
    qApp->installEventFilter(this);

    ui->splitterGraph->setStretchFactor(0, 10);
    ui->splitterGraph->setStretchFactor(1, 1);

    initLastAchievements();
    initPie();
    initGraphs();

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=](int lCurrentTab) {
        if (lCurrentTab == 1) {//если это Последние достижения
            movePixmapLastAchievement();
        }
    });

    retranslate();

    ui->tabWidget->setCurrentIndex(0);
}

bool FormStatistics::isInit() {
    return (profile_.steamId() != "");
}

void FormStatistics::updateIcons() {

}

void FormStatistics::retranslate() {
    ui->retranslateUi(this);
    if (auto chart = ui->ChartsViewTimes->chart()) {
        chart->setTitle(tr("Последний месяц"));
    }
    if (auto chart = ui->ChartsViewYears->chart()) {
        chart->setTitle(tr("Достижения по годам"));
    }
    ui->comboBoxGraph->setItemText(0, tr("Последний месяц"));
    ui->comboBoxGraph->setItemText(1, tr("По годам"));
}

void FormStatistics::resizeEvent(QResizeEvent* aEvent) {
   Form::resizeEvent(aEvent);
   isUserResizing_ = true;
}

bool FormStatistics::eventFilter(QObject *pObj, QEvent *pEvent) {
    if ((pEvent->type() == QEvent::MouseButtonRelease) || (pEvent->type() == QEvent::NonClientAreaMouseButtonRelease)) {
        QMouseEvent* pMouseEvent = dynamic_cast<QMouseEvent*>(pEvent);
        if ((pMouseEvent->button() == Qt::MouseButton::LeftButton) && isUserResizing_) {
            isUserResizing_ = false;
            movePixmapLastAchievement();
        }
    }
    return QObject::eventFilter(pObj, pEvent);
}

#define setProfileBlock {
void FormStatistics::clear() {
    profile_ = SProfile();
}

void FormStatistics::setProfile(const SProfile &aProfile) {
    profile_ = aProfile;
    statistics_ = Statistics(profile_);

    createThread();
    loadFriends();
}

void FormStatistics::createThread() {
    ThreadStatistics *statistics = new ThreadStatistics(statistics_);
    connect(statistics, &ThreadStatistics::s_progress, this, &Form::setStatus);
    connect(statistics, &ThreadStatistics::s_finish, this, &FormStatistics::onFinish);
    statistics->start();
}

void FormStatistics::onFinish(Statistics &aStatistic) {
    aStatistic.summAverages = 100.0 * aStatistic.complete.count();
    for (const auto &average: qAsConst(aStatistic.started)) {
        aStatistic.summAverages += average.percent;
    }
    aStatistic.sortAllLists();

    setInfo(aStatistic);
    setPie(aStatistic);
    setGraphs(aStatistic);
    clearStatus();
    emit s_finish(ui->graphicsViewLastAchievements->sizeHint().width());
}
#define setProfileBlockEnd }

#define infoBlock {
void FormStatistics::setInfo(const Statistics &aStatistic) {
    ui->labelAverageAllGamesValue->setText(QString::number(aStatistic.summAverages / (aStatistic.complete.count() + aStatistic.started.count() + aStatistic.notStarted.count())) + "%");
    ui->labelAverageStartedGamesValue->setText(QString::number(aStatistic.summAverages / (aStatistic.complete.count() + aStatistic.started.count())) + "%");
    ui->labelSumAchievementsValue->setText(QString::number(aStatistic.achievementCount));
    ui->labelCompletedGamesValue->setText(QString::number(aStatistic.complete.count()));
    ui->labelStartedGamesValue->setText(QString::number(aStatistic.started.count()));
    ui->labelNotStartedGamesValue->setText(QString::number(aStatistic.notStarted.count()));
    ui->labelNoAchievementsGamesValue->setText(QString::number(aStatistic.noAchievements.count()));

    setLastAchievements(aStatistic);
}
#define infoBlockEnd }

#define lastAchievementsBlock {
void FormStatistics::initLastAchievements() {
    ui->graphicsViewLastAchievements->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->graphicsViewLastAchievements->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
}

void FormStatistics::setLastAchievements(const Statistics &aStatistic) {
    int pixmapSize, pixmapRows, pixmapColumns, pixmapCount;
    getParametersForLastAchievements(pixmapSize, pixmapRows, pixmapColumns, pixmapCount);
    scene_->clear();

    auto tempLast50 = aStatistic.completedAchievements.last(std::min(pixmapCount, static_cast<int>(aStatistic.completedAchievements.size())));
    QList<CompletedAchievement> last50(reverseList<CompletedAchievement>(tempLast50));
    QMap<GameID, QList<SAchievementSchema>> mapGames;

    int i = 0;
    for (const auto &achievements: last50) {
        auto iteratorGames = mapGames.find(achievements.game.appId());
        if (iteratorGames == mapGames.end()) {
            iteratorGames = mapGames.insert(achievements.game.appId(), SAchievementSchema::load(achievements.game.appId()));
        }
        auto schema = (*iteratorGames);
        auto iteratorSchema = std::find_if(schema.begin(),
                                          schema.end(),
                                          [&](const SAchievementSchema &aSchema) {
                                              return aSchema.apiName() == achievements.achievement.apiName();
                                          });
        if (iteratorSchema != schema.end()) {
            QImage pix = loadImage((*iteratorSchema).icon(), Paths::imagesAchievements(QString::number(iteratorGames.key()), (*iteratorSchema).icon()), QSize(c_maxPixmapSize, c_maxPixmapSize));
            QString toolTip = textToToolTip("<b>" + achievements.game.name() + "</b>\n" +
                                            (*iteratorSchema).description() + "\n\n" +
                                            achievements.achievement.unlockTime().toString(Settings::dateTimeFormat()))
                                .replace("\n", "<br>");

            QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap::fromImage(pix));
            pixmapsLastAchievements_.insert(pixItem, QPixmap::fromImage(pix).scaled(pixmapSize, pixmapSize));
            int x = (i % pixmapColumns) * (pixmapSize + c_pixmapSpace) + (c_pixmapSpace / 2);
            int y = (i / pixmapColumns) * (pixmapSize + c_pixmapSpace) + (c_pixmapSpace / 2);
            pixItem->setPos(x, y);
            pixItem->setToolTip(toolTip);
            scene_->addItem(pixItem);
        }
        setStatus(tr("Последние достижения"), ++i, pixmapCount);
    }
    clearStatus();
}

void FormStatistics::getParametersForLastAchievements(int &aSize, int &aRows, int &aColumns, int &aCount) {
    aSize = c_minPixmapSize;
    aRows = 0;
    aColumns = 0;
    aCount = 50;
    QSize viewSize = ui->graphicsViewLastAchievements->size();
    if ((c_maxPixmapSize + c_pixmapSpace) * (c_maxPixmapSize + c_pixmapSpace) * aCount < viewSize.width() * viewSize.height()) {
        aRows = viewSize.height() / (c_maxPixmapSize + c_pixmapSpace);
        aColumns = viewSize.width() / (c_maxPixmapSize + c_pixmapSpace);
        aSize = c_maxPixmapSize;
        return;
    }
    QList<int> variants;
    for (int i = c_minPixmapSize; i <= c_maxPixmapSize; ++i) {
        variants << i;
    }
    auto result = std::lower_bound(variants.begin(),
                                   variants.end(),
                                   viewSize.width() * viewSize.height(),
                                   [=](const int &lVariant, double value) {
        return  (lVariant + c_pixmapSpace) * (lVariant + c_pixmapSpace) * aCount < value;
    });
    if (result != variants.end()) {
        for (aSize = *result; aRows * aColumns < aCount && aSize > c_minPixmapSize; --aSize) {
            aRows = viewSize.height() / (aSize + c_pixmapSpace);
            aColumns = viewSize.width() / (aSize + c_pixmapSpace);
        }
    } else {
        aRows = 10;
        aColumns = 5;
        aCount = 50;
    }
}

void FormStatistics::movePixmapLastAchievement() {
    int pixmapSize, pixmapRows, pixmapColumns, pixmapCount;
    getParametersForLastAchievements(pixmapSize, pixmapRows, pixmapColumns, pixmapCount);

    auto items = scene_->items(Qt::AscendingOrder);
    int i = 0;
    for (const auto &item: items) {
        int x = (i % pixmapColumns) * (pixmapSize + c_pixmapSpace) + (c_pixmapSpace / 2);
        int y = (i / pixmapColumns) * (pixmapSize + c_pixmapSpace) + (c_pixmapSpace / 2);
        item->setPos(x, y);
        if (auto pItem = dynamic_cast<QGraphicsPixmapItem*>(item)) {
            auto pixmap = pixmapsLastAchievements_.find(pItem);
            if (pixmap != pixmapsLastAchievements_.end()) {
                pItem->setPixmap((*pixmap).scaled(pixmapSize, pixmapSize));
            }
        }
        ++i;
    }
    scene_->setSceneRect(0, 0, pixmapColumns * (pixmapSize + c_pixmapSpace), pixmapRows * (pixmapSize + c_pixmapSpace));
}
#define lastAchievementsBlockEnd }

#define pieBlock {
void FormStatistics::initPie() {
    auto pie = new AchievementCompletedPieChart();
    connect(pie, &AchievementCompletedPieChart::s_noAchievementsClicked, this, [&]() {
//        _currentGamesType = GamesType::noAchievements;
        showTableGames(statistics_.noAchievements);
    });
    connect(pie, &AchievementCompletedPieChart::s_notStartedClicked, this, [&]() {
//        _currentGamesType = GamesType::notStarted;
        showTableGames(statistics_.notStarted);
    });
    connect(pie, &AchievementCompletedPieChart::s_startedClicked, this, [&]() {
//        _currentGamesType = GamesType::started;
        showTableGames(statistics_.started);
    });
    connect(pie, &AchievementCompletedPieChart::s_completedClicked, this, [&]() {
//        _currentGamesType = GamesType::complete;
        showTableGames(statistics_.complete);
    });
    ui->ChartViewPercentages->setChart(pie);

//    ui->horizontalLayoutPie->setStretch(0, 1);
//    ui->horizontalLayoutPie->setStretch(1, 2);

//    initingTable(ui->TableViewGames)->verticalHeader()->setVisible(true);
//    connect(ui->TableViewGames, &QTableView::customContextMenuRequested, this, [&](QPoint pos) {
//        SGame *game = currentGame();
//        if (game != nullptr) {
//            createMenu(*game)->popup(ui->TableViewGames->viewport()->mapToGlobal(pos));
//        }
//    });

//    connect(ui->TableViewGames, &QTableView::doubleClicked, this, [&](QModelIndex aIndex) {
//        Q_UNUSED(aIndex);
//        SGame *game = currentGame();
//        if (game != nullptr) {
//            emit s_showAchievements(*game);
//        }
//    });

//    GamesWithPercentModel *model2 = new GamesWithPercentModel();
//    ui->TableViewGames->setModel(model2);
//    ui->TableViewGames->setSortingEnabled(true);
//    ui->TableViewGames->setColumnHidden(gamesWithPercentModel::Appid, true);
//    ui->TableViewGames->setColumnHidden(gamesWithPercentModel::Index, true);
}

void FormStatistics::setPie(const Statistics &aStatistic) {
    auto pie = dynamic_cast<AchievementCompletedPieChart*>(ui->ChartViewPercentages->chart());
    if (pie) {
        pie->setNoAchievements(aStatistic.noAchievements.count());
        pie->setNotStarted(aStatistic.notStarted.count());
        pie->setStarted(aStatistic.started.count());
        pie->setCompleted(aStatistic.complete.count());
    }
//    if (_gamePercent->series().size() > 0) {
//        if (auto series = dynamic_cast<QPieSeries*>(_gamePercent->series().at(0))) {
//            auto slices = series->slices();
//            switch (series->count()) {
//            default:
//            case 4: {
//                slices[3]->setLabel(QString("%1%").arg(100.0 * aStatistic.noAchievements.count() / aStatistic.games.count(), 0, 'f', 2));
//                slices[3]->setValue(aStatistic.noAchievements.count());
//                [[fallthrough]];
//            }
//            case 3: {
//                slices[2]->setLabel(QString("%1%").arg(100.0 * aStatistic.notStarted.count() / aStatistic.games.count(), 0, 'f', 2));
//                slices[2]->setValue(aStatistic.notStarted.count());
//                [[fallthrough]];
//            }
//            case 2: {
//                slices[1]->setLabel(QString("%1%").arg(100.0 * aStatistic.started.count() / aStatistic.games.count(), 0, 'f', 2));
//                slices[1]->setValue(aStatistic.started.count());
//                [[fallthrough]];
//            }
//            case 1: {
//                slices[0]->setLabel(QString("%1%").arg(100.0 * aStatistic.complete.count() / aStatistic.games.count(), 0, 'f', 2));
//                slices[0]->setValue(aStatistic.complete.count());
//                break;
//            }
//            case 0: {
//                qWarning() << "on set data to pie slices.count = 0";
//            }
//            }
//        }
//    }
}

void FormStatistics::showTableGames(QList<GameWithPercentModelItem> aGames) {
    FormGames *formGames = new FormGames(this);
    formGames->setObjectName(QString("StatisticGames%1").arg(profile_.steamId()));

    SGames games;
    for (auto game: aGames) {
        games << game.game;
    }

    formGames->setGames(profile_.steamId(), games);
    formGames->setAttribute( Qt::WA_DeleteOnClose );
    QFrame *frame = createSubForm<FormGames>(formGames, this);
    QWidget *closeWidget = new QWidget();
    QPushButton *buttonClose = new QPushButton(QIcon(Images::cancel()), "");
    buttonClose->setMinimumSize(QSize(24, 24));
    QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Maximum);
    QHBoxLayout *hLayout = new QHBoxLayout(closeWidget);
    hLayout->addSpacerItem(spacer);
    hLayout->addWidget(buttonClose);
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    frame->layout()->replaceWidget(formGames, closeWidget);
    frame->layout()->addWidget(formGames);
    int x = this->width() / 8;
    int y = this->height() / 8;
    int w = this->width() / 4 * 3;
    int h = this->height() / 4 * 3;
    frame->setGeometry(QRect(x, y, w, h));

    connect(buttonClose, &QPushButton::pressed,this, [formGames](){
        formGames->close();
    });
    connect(formGames, &FormGames::s_showAchievements,this, [this](const SGame &aGame){
        emit s_showAchievements(aGame);
    });
    connect(formGames, &FormGames::s_closed,          this, [this, frame, buttonClose](){
        setEnable(true);
        delete buttonClose;
        delete frame->layout();
        delete frame;
    });
    setEnable(false);
}

void FormStatistics::setEnable(const bool &isEnable) {
    ui->tabWidget->setEnabled(isEnable);
}
#define pieBlockEnd }

#define graphsBlock {
QStringList getDaysMonthTitles(const QDate &aDate) {
    QDate date(aDate.year(), aDate.month(), 1);
    QStringList monthsTitles;
    while (date.month() == aDate.month()) {
        monthsTitles << date.toString("dd");
        date = date.addDays(1);
    }
    return monthsTitles;
}

QStringList getYearsTitles() {
    QStringList list;
    QDate date(c_steamReleaseYear,1,1);
    while (date < QDate::currentDate()) {
        list << date.toString("yyyy");
        date = date.addYears(1);
    }
    return list;
}

int roundToDesimal(int aData) {
    const double delta = 0.1;
    static const QVector<double> logs {0, log10(1), log10(2), log10(3), log10(4), log10(5), log10(6), log10(7), log10(8), log10(9), 1};
    int newData = aData;
    double dDecimal = log10(aData);
    int iDecimal = dDecimal;
    dDecimal -= iDecimal;
    for (int i = 1; i < 11; ++i) {
        if (dDecimal < logs[i]) {
            newData = pow(10, logs[i - 1] + iDecimal);
            break;
        }
    }
    if (newData % 10 == 9) {
        ++newData;
    }
    for (int i = 0; i < 20; ++i) {
        if (abs((1.0 * aData/newData) - 0.8) < delta) {
            break;
        }
        newData += pow(10, iDecimal - 1);
    }
    return newData;
}

void updateChartHeight(QChart *aChart) {
    if (aChart->axes(Qt::Vertical).count() > 0) {
        int max = 9;
        for (auto sery: aChart->series()) {
            if (auto realSeries = dynamic_cast<QBarSeries*>(sery)) {
                for (auto bar: realSeries->barSets()) {
                    if (auto realSery = dynamic_cast<QBarSet*>(bar)) {
                        for (int i = 0; i < realSery->count(); ++i) {
                            if (realSery->at(i) > max) {
                                max = realSery->at(i);
                            }
                        }
                    }
                }
            }
        }
        aChart->axes(Qt::Vertical).at(0)->setRange(0, roundToDesimal(max));
    } else {
        qWarning() << "error missing vertical axis";
    }
}

void updateChartWidth(QChart *aChart) {
    if (aChart->axes(Qt::Horizontal).count() > 0) {
        int min = 4000;
        int max = 0;
        for (auto sery: aChart->series()) {
            if (auto realSeries = dynamic_cast<QBarSeries*>(sery)) {
                for (auto bar: realSeries->barSets()) {
                    if (auto realSery = dynamic_cast<QBarSet*>(bar)) {
                        for (int i = 0; i < realSery->count(); ++i) {
                            if (realSery->at(i) > 0 && i < min) {
                                min = i;
                                break;
                            }
                        }
                        for (int i = realSery->count() - 1; i > 0; --i) {
                            if (realSery->at(i) > 0 && i > max) {
                                max = i;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (min == 4000) {
            min = 0;
        }
        for (auto axis: aChart->axes(Qt::Horizontal)) {
            if (auto categoryAxis = dynamic_cast<QBarCategoryAxis*>(axis)) {
                categoryAxis->setRange(categoryAxis->at(min), categoryAxis->at(max));
            }
        }
    } else {
        qWarning() << "error missing horizontal axis";
    }
}

void initGraph(QChartView *aChartView, const QStringList &aTitles) {
    auto chart = new QChart();
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::NoAnimation);
    chart->setBackgroundVisible(false);

    aChartView->setChart(chart);
    aChartView->setRenderHint(QPainter::Antialiasing);
//    ui->ChartsViewYears->setMinimumSize(480, 480);
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(aTitles);
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis();
//    axisY->setLabelFormat("%i");
    chart->addAxis(axisY, Qt::AlignLeft);

    QBarSeries *series = new QBarSeries();
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    auto axess = chart->axes();
    for (auto axis: axess) {
        axis->setLabelsColor(Theme::getCurrentTheme().text.color);
        axis->setGridLineColor(Theme::getCurrentTheme().border.color);
    }
    chart->setTitleBrush(Theme::getCurrentTheme().text.color);
    chart->legend()->setLabelColor(Theme::getCurrentTheme().text.color);

    aChartView->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(series, &QBarSeries::hovered, [=](bool lStatus, int lIndex, QBarSet *lBarset) {
        if (lStatus) {
            QToolTip::showText(QCursor::pos(QApplication::screens().at(0)),
                               QObject::tr("%1\n%2").arg(lBarset->label(), QString::number(lBarset->at(lIndex), 'f', 0)),
                               aChartView);
        } else {
            QToolTip::hideText();
        }
    });
}

void FormStatistics::initGraphs() {
    ui->stackedWidgetGraphs->setCurrentIndex(0);
    ui->listViewFriendsGraph->setModel(new QStandardItemModel());
    initGraph(ui->ChartsViewTimes, getDaysMonthTitles(QDate::currentDate()));
    initGraph(ui->ChartsViewYears, getYearsTitles());
    connect(ui->ChartsViewTimes, &QChartView::customContextMenuRequested, this, [this](const QPoint &pos) {
        QGraphicsItem *item = ui->ChartsViewTimes->itemAt(pos);
        QMenu *menu = createMenuChartTimes(item);
        menu->popup(ui->ChartsViewTimes->viewport()->mapToGlobal(pos));
    });
    connect(ui->ChartsViewYears, &QChartView::customContextMenuRequested, this, [this](const QPoint &pos) {
        QGraphicsItem *item = ui->ChartsViewYears->itemAt(pos);
        QMenu *menu = createMenuChartYears(item);
        menu->popup(ui->ChartsViewYears->viewport()->mapToGlobal(pos));
    });

    connect(ui->comboBoxGraph, &QComboBox::currentIndexChanged, ui->stackedWidgetGraphs, &QStackedWidget::setCurrentIndex);

    connect(ui->listViewFriendsGraph, &QListWidget::doubleClicked, this, &FormStatistics::addFriendToGraphs);

    ui->comboBoxGraph->clear();
    ui->comboBoxGraph->addItems(QStringList {tr("Последний месяц"), tr("По годам")});

    ui->graphicsViewLastAchievements->setScene(scene_);
    loadFriends();
}

void FormStatistics::createThreadFriend(Statistics &aStatistics) {
    ThreadStatistics *statistics = new ThreadStatistics(aStatistics);
    connect(statistics, &ThreadStatistics::s_progress,  this, &Form::setStatus);
    connect(statistics, &ThreadStatistics::s_finish,  this, &Form::clearStatus);
    connect(statistics, &ThreadStatistics::s_finish,  this, &FormStatistics::addFriendBar);
    statistics->start();
}

void FormStatistics::updateSettings(QFlags<changedSettings> aSettings) {
    if (aSettings.testFlag(changedSettings::theme)) {
        auto chartTimes = ui->ChartsViewTimes->chart();
        auto chartYears = ui->ChartsViewYears->chart();
        if (chartTimes) {
            auto axess = chartTimes->axes();
            for (auto axis: axess) {
                axis->setLabelsColor(Theme::getCurrentTheme().text.color);
                axis->setGridLineColor(Theme::getCurrentTheme().border.color);
            }
            chartTimes->setTitleBrush(Theme::getCurrentTheme().text.color);
            chartTimes->legend()->setLabelColor(Theme::getCurrentTheme().text.color);
        }
        if (chartYears) {
            auto axess = chartYears->axes();
            for (auto axis: axess) {
                axis->setLabelsColor(Theme::getCurrentTheme().text.color);
                axis->setGridLineColor(Theme::getCurrentTheme().border.color);
            }
            chartYears->setTitleBrush(Theme::getCurrentTheme().text.color);
            chartYears->legend()->setLabelColor(Theme::getCurrentTheme().text.color);
        }
    }
    Form::updateSettings(aSettings);
}

void FormStatistics::loadFriends() {
    QStringList list;
    SFriends friends = SFriend::load(profile_.steamId());
    for(const SFriend &sFriend: qAsConst(friends)) {
        list.append(sFriend.steamId());
    }

    auto friendsProfiles = SProfile::load(list);
    for(const auto &profileFriend: qAsConst(friendsProfiles)) {
        addFriendToList(profileFriend, FriendListItemData::ProfileType::FriendWithGame);
    }
}

void FormStatistics::addFriendToList(const SProfile &aSteamFriend, const FriendListItemData::ProfileType &aType) {
    if (aType == FriendListItemData::ProfileType::NotFriend ||
        aType == FriendListItemData::ProfileType::Unknown) {
        return;
    }
    FriendListItem *item = new FriendListItem(aSteamFriend, aType);
    if (auto model = dynamic_cast<QStandardItemModel*>(ui->listViewFriendsGraph->model())) {
        model->appendRow(item);
        model->sort(0);
    }
}

void FormStatistics::addFriendToGraphs(const QModelIndex &index) {
    SProfile profile;
    if (auto model = dynamic_cast<QStandardItemModel*>(ui->listViewFriendsGraph->model())) {
        if (auto item = dynamic_cast<FriendListItem*>(model->item(index.row()))) {
            profile = item->profile();
        }
    }
    Statistics *statistic = new Statistics(profile);
    createThreadFriend(*statistic);
    if (auto model = dynamic_cast<QStandardItemModel*>(ui->listViewFriendsGraph->model())) {
        auto row = model->takeRow(index.row());
        for (auto item: row) {
            delete item;
        }
    }
}

QMenu *FormStatistics::createMenuChartTimes(QGraphicsItem *aItem) {
    Q_UNUSED(aItem);
    QChart *chart = ui->ChartsViewTimes->chart();
    if (chart == nullptr) {
        return nullptr;
    }
    if (chart->series().count() == 0) {
        return nullptr;
    }
    auto series = chart->series().at(0);
    if (auto barSeries = dynamic_cast<QBarSeries*>(series)) {
        auto bars = barSeries->barSets();
        QMenu *menu = new QMenu();
        for (auto bar: bars) {
            if (bar->label() == profile_.personaName()) {
                continue;
            }
            QAction *friendBar = new QAction(tr("Убрать %1 из сравнения").arg(bar->label()));

            connect(friendBar, &QAction::triggered, this, [=]() {
                removeFriendBar(bar->label(), bar->objectName());
            });

            menu->addAction(friendBar);
        }
        return menu;
    }
    return nullptr;
}

QMenu *FormStatistics::createMenuChartYears(QGraphicsItem *aItem) {
    Q_UNUSED(aItem);
    QChart *chart = ui->ChartsViewYears->chart();
    if (chart == nullptr) {
        return nullptr;
    }
    if (chart->series().count() == 0) {
        return nullptr;
    }
    auto series = chart->series().at(0);
    if (auto barSeries = dynamic_cast<QBarSeries*>(series)) {
        auto bars = barSeries->barSets();
        QMenu *menu = new QMenu();
        for (auto bar: bars) {
            if (bar->label() == profile_.personaName()) {
                continue;
            }
            QAction *friendBar = new QAction(tr("Убрать %1 из сравнения").arg(bar->label()));

            connect(friendBar, &QAction::triggered, this, [=]() {
                removeFriendBar(bar->label(), bar->objectName());
            });

            menu->addAction(friendBar);
        }
        return menu;
    }
    return nullptr;
}

void FormStatistics::setGraphs(const Statistics &aStatistic) {
    addFriendBar(aStatistic);
}

void FormStatistics::addFriendBar(const Statistics &aStatistic) {
    QList<int> datasT(daysInMonth(QDate::currentDate()));
    const int startMonthSecs = QDateTime(QDate(QDate::currentDate().year(), QDate::currentDate().month(), 1), QTime()).toSecsSinceEpoch();
    for (const auto &achievement: aStatistic.completedAchievements) {
        int secsFromStartMonth = achievement.achievement.unlockTime().toSecsSinceEpoch() - startMonthSecs;
        if (secsFromStartMonth > 0) {
            int index = secsFromStartMonth / c_secsInDay;
            ++(datasT[index]);
        }
    }
    auto chartTime = ui->ChartsViewTimes->chart();
    QBarSet *setTime = new QBarSet(aStatistic.profile.personaName());
    setTime->setObjectName(QString("BarSet_%1").arg(aStatistic.profile.steamId()));
    for (const auto &data: datasT) {
        setTime->append(data);
    }
    if (chartTime->series().count() > 0) {
        if (auto series = dynamic_cast<QBarSeries*>(chartTime->series().at(0))) {
            series->append(setTime);
        }
    }
    updateChartHeight(chartTime);

    auto chartYears = ui->ChartsViewYears->chart();
    QList<int> datasY(QDate::currentDate().year() - c_steamReleaseYear + 1);
    for (const auto &data: aStatistic.years) {
        datasY[data.year.toInt() - c_steamReleaseYear] += data.count;
    }
    QBarSet *setYear = new QBarSet(aStatistic.profile.personaName());
    setYear->setObjectName(QString("BarSet_%1").arg(aStatistic.profile.steamId()));
    for (const auto &data: datasY) {
        setYear->append(data);
    }
    if (chartYears->series().count() > 0) {
        if (auto series = dynamic_cast<QBarSeries*>(chartYears->series().at(0))) {
            series->append(setYear);
        }
    }

    updateChartHeight(chartYears);
    updateChartWidth(chartYears);
}

void FormStatistics::removeFriendBar(const QString &aName, const QString &aBarObjectName) {
    Q_UNUSED(aName);
    ProfileID friendId = aBarObjectName.last(aBarObjectName.length() - 7);// first 7 symvols is "BarSet_"
    auto chartTimes = ui->ChartsViewTimes->chart();
    auto chartYears = ui->ChartsViewYears->chart();
    if (chartTimes) {
        if (chartTimes->series().count() > 0) {
            if (auto series = dynamic_cast<QBarSeries*>(chartTimes->series().at(0))) {
                if (auto barSeries = dynamic_cast<QBarSeries*>(series)) {
                    auto bars = barSeries->barSets();
                    for (auto bar: bars) {
                        if (bar->objectName() == aBarObjectName) {
                            if (barSeries->take(bar)) {
                                delete bar;
                            }
                        }
                    }
                }
            }
        }
    }
    updateChartHeight(chartTimes);
    if (chartYears) {
        if (chartYears->series().count() > 0) {
            if (auto series = dynamic_cast<QBarSeries*>(chartYears->series().at(0))) {
                if (auto barSeries = dynamic_cast<QBarSeries*>(series)) {
                    auto bars = barSeries->barSets();
                    for (auto bar: bars) {
                        if (bar->objectName() == aBarObjectName) {
                            if (barSeries->take(bar)) {
                                delete bar;
                            }
                        }
                    }
                }
            }
        }
    }
    updateChartHeight(chartYears);
    updateChartWidth(chartYears);
    addFriendToList(SProfile::load(friendId), FriendListItemData::ProfileType::FriendWithGame);
}
#define graphsBlockEnd }
