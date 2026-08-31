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
constexpr int c_maxPixmapSize = 256;
constexpr int c_lastAchievementsCount = 50;
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

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=, this](int lCurrentTab) {
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
    if (QChart *chart = ui->ChartsViewTimes->chart()) {
        chart->setTitle(tr("Последний месяц"));
    }
    if (QChart *chart = ui->ChartsViewYears->chart()) {
        chart->setTitle(tr("Достижения по годам"));
    }
    ui->comboBoxGraph->setItemText(0, tr("Последний месяц"));
    ui->comboBoxGraph->setItemText(1, tr("По годам"));
}

void FormStatistics::resizeEvent(QResizeEvent* aEvent) {
   Form::resizeEvent(aEvent);
   movePixmapLastAchievement();
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
    qDebug() << __FUNCTION__ << " " << profile_.steamId();
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
    for (const GameWithPercentModelItem &average: aStatistic.started) {
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

int getParametersForLastAchievements(const QSize &aSize, const int aCount) {
    int l = c_minPixmapSize, r = c_maxPixmapSize;
    while (l < r) {
        int m = (l + r + 1) / 2;
        int blockSize = (m + c_pixmapSpace);
        int rows = aSize.height() / blockSize;
        int columns = aSize.width() / blockSize;
        if (rows * columns >= aCount) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

void FormStatistics::setLastAchievements(const Statistics &aStatistic) {
    scene_->clear();
    QList<CompletedAchievement> lastAchievements = aStatistic.completedAchievements.last(std::min(c_lastAchievementsCount, static_cast<int>(aStatistic.completedAchievements.size())));

    int i = 0;
    for (const CompletedAchievement &achievement: lastAchievements) {
        QList<SAchievementSchema> schema = SAchievementSchema::load(achievement.game.appId());
        auto iteratorSchema = std::find_if(schema.begin(),
                                          schema.end(),
                                          [&](const SAchievementSchema &aSchema) {
                                              return aSchema.apiName() == achievement.achievement.apiName();
                                          });
        if (iteratorSchema != schema.end()) {
            QString toolTip = textToToolTip("<b>" + achievement.game.name() + "</b><br>" +
                                            (*iteratorSchema).description() + "<br><br>" +
                                            achievement.achievement.unlockTime().toString(Settings::dateTimeFormat()), " ", "<br>");

            QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem();
            pixItem->setPixmap(SAchievementSchema::icon(achievement.game.appId(), (*iteratorSchema).icon(), QSize(c_maxPixmapSize, c_maxPixmapSize)));
            pixItem->setToolTip(toolTip);
            scene_->addItem(pixItem);
        }
        setStatus(tr("Последние достижения"), ++i, c_lastAchievementsCount);
    }
    movePixmapLastAchievement();
    clearStatus();
}

void FormStatistics::movePixmapLastAchievement() {
    int pixmapSize = getParametersForLastAchievements(ui->graphicsViewLastAchievements->size(), c_lastAchievementsCount);
    int pixmapRows = ui->graphicsViewLastAchievements->size().height() / (pixmapSize + c_pixmapSpace);
    int pixmapColumns = ui->graphicsViewLastAchievements->size().width() / (pixmapSize + c_pixmapSpace);

    QList<QGraphicsItem*> items = scene_->items();
    int col = 0;
    int row = 0;
    for (QGraphicsItem *item: items) {
        if (dynamic_cast<QGraphicsPixmapItem*>(item) != nullptr) {
            int x = col * (pixmapSize + c_pixmapSpace);
            int y = row * (pixmapSize + c_pixmapSpace);
            item->setPos(x, y);
            item->setScale(1.0 * pixmapSize / c_maxPixmapSize);
            ++col;
            if (col == pixmapColumns) {
                ++row;
                col = 0;
            }
        }
    }
    scene_->setSceneRect(0, 0, pixmapColumns * (pixmapSize + c_pixmapSpace), pixmapRows * (pixmapSize + c_pixmapSpace));
}
#define lastAchievementsBlockEnd }

#define pieBlock {
void FormStatistics::initPie() {
    AchievementCompletedPieChart *pie = new AchievementCompletedPieChart();
    connect(pie, &AchievementCompletedPieChart::s_noAchievementsClicked, this, [&]() {
        showTableGames(statistics_.noAchievements);
    });
    connect(pie, &AchievementCompletedPieChart::s_notStartedClicked, this, [&]() {
        showTableGames(statistics_.notStarted);
    });
    connect(pie, &AchievementCompletedPieChart::s_startedClicked, this, [&]() {
        showTableGames(statistics_.started);
    });
    connect(pie, &AchievementCompletedPieChart::s_completedClicked, this, [&]() {
        showTableGames(statistics_.complete);
    });
    ui->ChartViewPercentages->setChart(pie);
}

void FormStatistics::setPie(const Statistics &aStatistic) {
    AchievementCompletedPieChart *pie = dynamic_cast<AchievementCompletedPieChart*>(ui->ChartViewPercentages->chart());
    if (pie) {
        pie->setNoAchievements(aStatistic.noAchievements.count());
        pie->setNotStarted(aStatistic.notStarted.count());
        pie->setStarted(aStatistic.started.count());
        pie->setCompleted(aStatistic.complete.count());
    }
}

void FormStatistics::showTableGames(QList<GameWithPercentModelItem> aGames) {
    FormGames *formGames = new FormGames(this);
    formGames->setObjectName(QString("StatisticGames%1").arg(profile_.steamId()));

    SGames games;
    for (GameWithPercentModelItem game: aGames) {
        games << game.game;
    }

    formGames->setGames(profile_.steamId(), games);
    formGames->setAttribute( Qt::WA_DeleteOnClose );

    SubForm *form = new SubForm(formGames, this);
    form->show();

    QPushButton *buttonClose = new QPushButton(QIcon(Images::cancel()), "", form);
    buttonClose->setMinimumSize(QSize(24, 24));

    form->addWidget(buttonClose, FramelessWindow::Edge::TopRight);

    connect(buttonClose, &QPushButton::pressed,this, [formGames](){
        formGames->close();
    });
    connect(formGames, &FormGames::s_showAchievements,this, [this](const SGame &aGame){
        emit s_showAchievements(aGame);
    });
    connect(formGames, &FormGames::s_closed,          this, [this, form/*, buttonClose*/](){
        setEnable(true);
        delete form;
    });
    setEnable(false);
}

void FormStatistics::setEnable(bool isEnable) {
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
        for (QAbstractSeries *sery: aChart->series()) {
            if (QBarSeries *realSeries = dynamic_cast<QBarSeries*>(sery)) {
                for (QBarSet *bar: realSeries->barSets()) {
                    for (int i = 0; i < bar->count(); ++i) {
                        if (bar->at(i) > max) {
                            max = bar->at(i);
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
        for (QAbstractSeries *sery: aChart->series()) {
            if (QBarSeries *realSeries = dynamic_cast<QBarSeries*>(sery)) {
                for (QBarSet *bar: realSeries->barSets()) {
                    for (int i = 0; i < bar->count(); ++i) {
                        if (bar->at(i) > 0 && i < min) {
                            min = i;
                            break;
                        }
                    }
                    for (int i = bar->count() - 1; i > 0; --i) {
                        if (bar->at(i) > 0 && i > max) {
                            max = i;
                            break;
                        }
                    }
                }
            }
        }
        if (min == 4000) {
            min = 0;
        }
        for (QAbstractAxis *axis: aChart->axes(Qt::Horizontal)) {
            if (QBarCategoryAxis *categoryAxis = dynamic_cast<QBarCategoryAxis*>(axis)) {
                categoryAxis->setRange(categoryAxis->at(min), categoryAxis->at(max));
            }
        }
    } else {
        qWarning() << "error missing horizontal axis";
    }
}

void initGraph(QChartView *aChartView, const QStringList &aTitles) {
    QChart *chart = new QChart();
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

    QList<QAbstractAxis*> axess = chart->axes();
    for (QAbstractAxis *axis: axess) {
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
        QMenu *menu = createMenuChart(ui->ChartsViewTimes, item);
        menu->popup(ui->ChartsViewTimes->viewport()->mapToGlobal(pos));
    });
    connect(ui->ChartsViewYears, &QChartView::customContextMenuRequested, this, [this](const QPoint &pos) {
        QGraphicsItem *item = ui->ChartsViewYears->itemAt(pos);
        QMenu *menu = createMenuChart(ui->ChartsViewYears, item);
        menu->popup(ui->ChartsViewYears->viewport()->mapToGlobal(pos));
    });

    connect(ui->comboBoxGraph, &QComboBox::currentIndexChanged, ui->stackedWidgetGraphs, &QStackedWidget::setCurrentIndex);

    connect(ui->listViewFriendsGraph, &QListWidget::doubleClicked, this, &FormStatistics::addFriendToGraphs);

    ui->comboBoxGraph->clear();
    ui->comboBoxGraph->addItems(QStringList {tr("Последний месяц"), tr("По годам")});

    ui->graphicsViewLastAchievements->setScene(scene_);
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
        QChart *chartTimes = ui->ChartsViewTimes->chart();
        QChart *chartYears = ui->ChartsViewYears->chart();
        if (chartTimes) {
            QList<QAbstractAxis*> axess = chartTimes->axes();
            for (QAbstractAxis *axis: axess) {
                axis->setLabelsColor(Theme::getCurrentTheme().text.color);
                axis->setGridLineColor(Theme::getCurrentTheme().border.color);
            }
            chartTimes->setTitleBrush(Theme::getCurrentTheme().text.color);
            chartTimes->legend()->setLabelColor(Theme::getCurrentTheme().text.color);
        }
        if (chartYears) {
            QList<QAbstractAxis*> axess = chartYears->axes();
            for (QAbstractAxis *axis: axess) {
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
    qDebug() << __FUNCTION__ << " " << profile_.steamId();
    SFriends friends = SFriend::load(profile_.steamId());
    for(const SFriend &sFriend: qAsConst(friends)) {
        list.append(sFriend.steamId());
    }

    SProfiles friendsProfiles = SProfile::load(list);
    for(const SProfile &profileFriend: qAsConst(friendsProfiles)) {
        addFriendToList(profileFriend, FriendListItemData::ProfileType::FriendWithGame);
    }
}

void FormStatistics::addFriendToList(const SProfile &aSteamFriend, const FriendListItemData::ProfileType &aType) {
    if (aType == FriendListItemData::ProfileType::NotFriend ||
        aType == FriendListItemData::ProfileType::Unknown) {
        return;
    }
    FriendListItem *item = new FriendListItem(aSteamFriend, aType);
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->listViewFriendsGraph->model())) {
        model->appendRow(item);
        model->sort(0);
    }
}

void FormStatistics::addFriendToGraphs(const QModelIndex &index) {
    SProfile profile;
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->listViewFriendsGraph->model())) {
        if (FriendListItem *item = dynamic_cast<FriendListItem*>(model->item(index.row()))) {
            profile = item->profile();
        }
    }
    Statistics *statistic = new Statistics(profile);
    createThreadFriend(*statistic);
    if (QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->listViewFriendsGraph->model())) {
        QList<QStandardItem*> row = model->takeRow(index.row());
        for (QStandardItem *item: row) {
            delete item;
        }
    }
}

QMenu *FormStatistics::createMenuChart(QChartView *aView, QGraphicsItem *aItem) {
    Q_UNUSED(aItem);
    QChart *chart = aView->chart();
    if (chart == nullptr) {
        return nullptr;
    }
    if (chart->series().count() == 0) {
        return nullptr;
    }
    QAbstractSeries *series = chart->series().at(0);
    if (QBarSeries *barSeries = dynamic_cast<QBarSeries*>(series)) {
        QList<QBarSet*> bars = barSeries->barSets();
        QMenu *menu = new QMenu();
        for (QBarSet *bar: bars) {
            if (bar->label() == profile_.personaName()) {
                continue;
            }
            QAction *friendBar = new QAction(tr("Убрать %1 из сравнения").arg(bar->label()));

            connect(friendBar, &QAction::triggered, this, [=, this]() {
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
    QList<int> datasT(QDate::currentDate().daysInMonth());
    const int startMonthSecs = QDateTime(QDate(QDate::currentDate().year(), QDate::currentDate().month(), 1), QTime()).toSecsSinceEpoch();
    for (const CompletedAchievement &achievement: aStatistic.completedAchievements) {
        int secsFromStartMonth = achievement.achievement.unlockTime().toSecsSinceEpoch() - startMonthSecs;
        if (secsFromStartMonth > 0) {
            int index = secsFromStartMonth / c_secsInDay;
            ++(datasT[index]);
        }
    }
    QChart *chartTime = ui->ChartsViewTimes->chart();
    QBarSet *setTime = new QBarSet(aStatistic.profile.personaName());
    setTime->setObjectName(QString("BarSet_%1").arg(aStatistic.profile.steamId()));
    for (int data: datasT) {
        setTime->append(data);
    }
    if (chartTime->series().count() > 0) {
        if (QBarSeries *series = dynamic_cast<QBarSeries*>(chartTime->series().at(0))) {
            series->append(setTime);
        }
    }
    updateChartHeight(chartTime);

    QChart *chartYears = ui->ChartsViewYears->chart();
    QList<int> datasY(QDate::currentDate().year() - c_steamReleaseYear + 1);
    for (auto it = aStatistic.years.begin(); it != aStatistic.years.end(); ++it) {
        if (it.key() >= c_steamReleaseYear) {
            datasY[it.key() - c_steamReleaseYear] += it.value();
        }
    }
    QBarSet *setYear = new QBarSet(aStatistic.profile.personaName());
    setYear->setObjectName(QString("BarSet_%1").arg(aStatistic.profile.steamId()));
    for (int data: datasY) {
        setYear->append(data);
    }
    if (chartYears->series().count() > 0) {
        if (QBarSeries *series = dynamic_cast<QBarSeries*>(chartYears->series().at(0))) {
            series->append(setYear);
        }
    }

    updateChartHeight(chartYears);
    updateChartWidth(chartYears);
}

void FormStatistics::removeFriendBar(const QString &aName, const QString &aBarObjectName) {
    Q_UNUSED(aName);
    ProfileID friendId = aBarObjectName.last(aBarObjectName.length() - 7);// first 7 symvols is "BarSet_"
    QChart *chartTimes = ui->ChartsViewTimes->chart();
    QChart *chartYears = ui->ChartsViewYears->chart();
    if (chartTimes) {
        if (chartTimes->series().count() > 0) {
            if (QBarSeries *series = dynamic_cast<QBarSeries*>(chartTimes->series().at(0))) {
                QList<QBarSet*> bars = series->barSets();
                for (QBarSet *bar: bars) {
                    if (bar->objectName() == aBarObjectName) {
                        if (series->take(bar)) {
                            delete bar;
                        }
                    }
                }
            }
        }
    }
    updateChartHeight(chartTimes);
    if (chartYears) {
        if (chartYears->series().count() > 0) {
            if (QBarSeries *series = dynamic_cast<QBarSeries*>(chartYears->series().at(0))) {
                QList<QBarSet*> bars = series->barSets();
                for (QBarSet *bar: bars) {
                    if (bar->objectName() == aBarObjectName) {
                        if (series->take(bar)) {
                            delete bar;
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
