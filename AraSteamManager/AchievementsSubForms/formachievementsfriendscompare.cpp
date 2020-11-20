#include "formachievementsfriendscompare.h"
#include "ui_formachievementsfriendscompare.h"

FormAchievementsFriendsCompare::FormAchievementsFriendsCompare(QWidget *parent): QWidget(parent),
                                                               ui(new Ui::FormAchievementsFriendsCompare) {
    ui->setupUi(this);
//    setIcons();
//    #define Connects {
//    connect(ui->CheckBoxCompareIcon,                &QCheckBox::stateChanged,                 ui->TableViewCompare,  [=](int arg1) {
//        ui->TableViewCompare->setColumnHidden(c_tableAchievementColumnIcon, arg1 == 0);
//    });
//    connect(ui->CheckBoxCompareTitle,               &QCheckBox::stateChanged,                 ui->TableViewCompare,  [=](int arg1) {
//        ui->TableViewCompare->setColumnHidden(c_tableAchievementColumnTitle, arg1 == 0);
//    });
//    connect(ui->CheckBoxCompareDescription,         &QCheckBox::stateChanged,                 ui->TableViewCompare,  [=](int arg1) {
//        ui->TableViewCompare->setColumnHidden(c_tableAchievementColumnDescription, arg1 == 0);
//    });
//    connect(ui->CheckBoxCompareTotalPercent,        &QCheckBox::stateChanged,                 ui->TableViewCompare,  [=](int arg1) {
//        ui->TableViewCompare->setColumnHidden(c_tableAchievementColumnWorld, arg1 == 0);
//    });
//    #define ConnectsEnd }
}

FormAchievementsFriendsCompare::~FormAchievementsFriendsCompare() {
    delete ui;
}

//void FormAchievementsFriendsCompare::setIcons() {
//    QWidget *wFriendsFilter = dynamic_cast<QWidget*>(ui->TableWidgetFriends->cellWidget(c_tableFriendsRowFilters, 1));
//    if (wFriendsFilter) {
//        QButtonWithData *bFriendsAll = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(0)->widget());
//        if (bFriendsAll) {
//            bFriendsAll->setIcon(QIcon(Images::allAchievements()));
//        } else {
//            qWarning() << "not init bFriendsAll";
//        }
//        QButtonWithData *bFriendsReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(1)->widget());
//        if (bFriendsReached) {
//            bFriendsReached->setIcon(QIcon(Images::reached()));
//        } else {
//            qWarning() << "not init bFriendsReached";
//        }
//        QButtonWithData *bFriendsNotReached = dynamic_cast<QButtonWithData*>(wFriendsFilter->layout()->itemAt(2)->widget());
//        if (bFriendsNotReached) {
//            bFriendsNotReached->setIcon(QIcon(Images::notReached()));
//        } else {
//            qWarning() << "not init bFriendsNotReached";
//        }
//    } else {
//        qWarning() << "not init wFriendsFilter";
//    }
//}

//void FormAchievementsFriendsCompare::initTableCompare() {
//    ui->TableViewCompare->setVerticalScrollMode  (QAbstractItemView::ScrollMode::ScrollPerPixel);
//    ui->TableViewCompare->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

//    ui->TableViewCompare->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->TableViewCompare->setShowGrid(false);
//    ui->TableViewCompare->setSortingEnabled(true);
//    ui->TableViewCompare->horizontalHeader()->setStretchLastSection(true);
//    ui->TableViewCompare->verticalHeader()->setVisible(false);
//    ui->TableViewCompare->setContextMenuPolicy(Qt::CustomContextMenu);
//    ui->TableViewCompare->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    connect(ui->TableViewCompare, &QTableView::customContextMenuRequested, this, [=](QPoint pos) {
//        updateCurrentAchievement();
//        if (_currentAchievement != nullptr) {
//            QMenu *menu = createMenuCompare(*_currentAchievement);
//            menu->popup(ui->TableViewCompare->viewport()->mapToGlobal(pos));
//        }
//    });

//    connect(ui->TableViewCompare, &QTableView::doubleClicked, this, [=](QModelIndex aIndex) {
//        updateCurrentAchievement();
//        if (aIndex.column() == c_tableAchievementColumnComment) {
//            buttonComment_Clicked();
//        } else {
////            buttonAchievements_Clicked();
//        }
//    });
//}
