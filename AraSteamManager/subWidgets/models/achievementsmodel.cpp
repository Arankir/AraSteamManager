#include "achievementsmodel.h"

using namespace achievementsModel;

constexpr QColor c_achievedColor      = QColor (87, 220, 87, 255 * 1);
constexpr QColor c_notAchievedColor   = QColor (255, 48, 48, 255 * 1);

AchievementsModel::AchievementsModel(QObject *aParent): QAbstractTableModel(aParent) {

}

void AchievementsModel::setAchievements(const ProfileID &aProfileId, const GameID &aGameId) {
    profileId_ = aProfileId;
    gameId_ = aGameId;
    achievementsInModel_.clear();
    profiles_.clear();

    auto globals = SAchievementSchema::load(gameId_);
    auto percents = SAchievementPercentage::load(gameId_);

    auto comments = AchievementComments(aProfileId).getCommentsFromGame(aProfileId, gameId_);

    int progress = 0;
    for (auto &global: globals) {
        for (auto &percent: percents) {
            if (percent.apiName() != global.apiName()) {
                continue;
            }
            QImage pix;
            auto achievement = AchievementInModel {QPixmap::fromImage(loadImage(global.icon(), Paths::imagesAchievements(QString::number(aGameId), global.icon()), QSize(64, 64))),
                                                    QStringList(),
                                                    global,
                                                    percent,
                                                    QList<SAchievementPlayer>()};
            auto iterator = std::find_if(comments.begin(),
                                         comments.end(),
                                         [=](const AchievementComment &achievementComment) {
                                            return achievementComment.achievementId() == percent.apiName();
                                         });
            if (iterator != comments.end()) {
                achievement.comment = (*iterator).comment();
            }
            achievementsInModel_.append(std::move(achievement));
            emit s_progress(tr("Загрузка достижений"), ++progress, globals.count());
            break;
        }
    }

    auto profile = SProfile::load(aProfileId, SProfile::LoadType::id);
    addProfile(profile);
    emit s_finished();
}

int AchievementsModel::columnCount(const QModelIndex &aParent) const {
    Q_UNUSED(aParent);
    return Count + profiles_.count();
}

int AchievementsModel::rowCount(const QModelIndex &aParent) const {
    Q_UNUSED(aParent);
    return achievementsInModel_.count() + c_reservedRows;
}

QVariant AchievementsModel::data(const QModelIndex &aIndex, int aRole) const {
    if (!aIndex.isValid())
        return QVariant();

    if (aIndex.row() >= achievementsInModel_.size() + c_reservedRows)
        return QVariant();

    if (aIndex.row() < c_reservedRows) {
        switch (aIndex.row()) {
        case ReservedRows::Avatar : {
            switch (aRole) {
            case Qt::DecorationRole: {
                switch (aIndex.column()) {
                case Appid:
                case Index:
                case Icon:
                case Title:
                case Description:
                case Comments:
                case World: {
                    return QVariant();
                }
                default: {
                    return profiles_[aIndex.column() - Count].first.pixmapAvatar();
                }
                }
                break;
            }
            case Qt::ToolTipRole: {
                switch (aIndex.column()) {
                case Appid:
                case Index:
                case Icon:
                case Title:
                case Description:
                case Comments:
                case World: {
                    return QVariant();
                }
                default: {
                    return textToToolTip(profiles_[aIndex.column() - Count].first.personaName());
                }
                }
                break;
            }
            default: {
                return QVariant();
            }
            }
            break;
        }
        case ReservedRows::Percent : {
            switch (aRole) {
            case Qt::DisplayRole: {
                switch (aIndex.column()) {
                case Appid:
                case Index:
                case Icon:
                case Title:
                case Description:
                case Comments:
                case World: {
                    return QVariant();
                }
                default: {
                    return QString("%1/%2\n(%3%)").arg(QString::number(profiles_[aIndex.column() - Count].second),
                                                        QString::number(getAchievementsCount()),
                                                        QString::number(profiles_[aIndex.column() - Count].second / (1.0 * getAchievementsCount() / 100), 'f', 2));
                }
                }
                break;
            }
            default: {
                return QVariant();
            }
            }
            break;
        }
        default: {
            return QVariant();
        }
        }
    }

    switch (aRole) {
    case Qt::DisplayRole: {
        switch (aIndex.column()) {
        case Appid: {
            return achievementsInModel_[aIndex.row() - c_reservedRows].schema.apiName();
        }
        case Index: {
            return aIndex.row() - c_reservedRows;
        }
        case Icon: {
            return QVariant();
        }
        case Title: {
            return achievementsInModel_[aIndex.row() - c_reservedRows].schema.displayName();
        }
        case Description: {
            return achievementsInModel_[aIndex.row() - c_reservedRows].schema.description();
        }
        case Comments: {
            if (achievementsInModel_[aIndex.row() - c_reservedRows].comment != QStringList() &&
                achievementsInModel_[aIndex.row() - c_reservedRows].comment != QStringList() << "") {
                if (achievementsInModel_[aIndex.row() - c_reservedRows].comment.count() > 1) {
                    return achievementsInModel_[aIndex.row() - c_reservedRows].comment[0] + tr("\n...");
                } else {
                    return achievementsInModel_[aIndex.row() - c_reservedRows].comment[0];
                }
            } else {
                return tr("-");
            }
        }
        case World: {
            return QString("%1%").arg(QString::number(achievementsInModel_[aIndex.row() - c_reservedRows].percent.percent(), 'f', 2));
        }
        default: {
            if (achievementsInModel_[aIndex.row() - c_reservedRows].profiles.size() > (aIndex.column() - Count)) {
                auto achievement = achievementsInModel_[aIndex.row() - c_reservedRows].profiles[aIndex.column() - Count];
                switch(achievement.achieved()) {
                case -1: {
                    return achievement.error();
                }
                case 0: {
                    return tr("Не получено");
                }
                case 1: {
                    return achievement.unlockTime().toString(Settings::dateTimeFormatShort());
                }
                default: {
                    return tr("undefined");
                }
                }
            } else {
                qWarning() << "no profile from achievements need"
                           << (aIndex.column() - Count + 1)
                           << "have"
                           << achievementsInModel_[aIndex.row() - c_reservedRows].profiles.size();
                return QVariant();
            }
        }
        }
        break;
    }
    case Qt::DecorationRole: {
        switch (aIndex.column()) {
        case Icon: {
            return achievementsInModel_[aIndex.row() - c_reservedRows].icon;
        }
        default: {
            return QVariant();
        }
        }
        break;
    }
    case Qt::ToolTipRole: {
        switch (aIndex.column()) {
        case Title: {
            return textToToolTip(achievementsInModel_[aIndex.row() - c_reservedRows].schema.displayName());
        }
        case Description: {
            return textToToolTip(achievementsInModel_[aIndex.row() - c_reservedRows].schema.description());
        }
        default: {
            return QVariant();
        }
        }
        break;
    }
    case Qt::ForegroundRole: {
        switch (aIndex.column()) {
        case Appid:
        case Index:
        case Icon:
        case Title:
        case Description:
        case World: {
            return QVariant();
        }
        case Comments: {
            if (achievementsInModel_[aIndex.row() - c_reservedRows].comment == QStringList() ||
                achievementsInModel_[aIndex.row() - c_reservedRows].comment == QStringList() << "") {
                return QColor(55, 55, 150);
            }
            return QVariant();
        }
        default: {
            if (achievementsInModel_[aIndex.row() - c_reservedRows].profiles.size() > (aIndex.column() - Count)) {
                if (achievementsInModel_[aIndex.row() - c_reservedRows].profiles[aIndex.column() - Count].achieved() == 1) {
                    return c_achievedColor;
                } else {
                    return c_notAchievedColor;
                }
            } else {
                qWarning() << "no profile from achievements need"
                           << (aIndex.column() - Count + 1)
                           << "have"
                           << achievementsInModel_[aIndex.row() - c_reservedRows].profiles.size();
                return QVariant();
            }
            break;
        }
        }
        break;
    }
    case Qt::TextAlignmentRole: {
        switch (aIndex.column()) {
        case Appid:
        case Index:
        case Icon:
        case Title:
        case Description:
        case Comments: {
            return QVariant();
        }
        case World: {
            return QVariant(Qt::AlignVCenter | Qt::AlignHCenter);
        }
        default: {
            return QVariant();
        }
        }
    }
    default: {
        return QVariant();
    }
    }
}

QVariant AchievementsModel::headerData(int aSection, Qt::Orientation aOrientation, int aRole) const {
    if (aRole != Qt::DisplayRole)
        return QVariant();

    if (aOrientation == Qt::Horizontal)
        switch (aSection) {
        case Appid: {
            return tr("ID");
        }
        case Index: {
            return tr("");
        }
        case Icon: {
            return tr("Иконка");
        }
        case Title: {
            return tr("Название");
        }
        case Description: {
            return tr("Описание");
        }
        case Comments: {
            return tr("");
        }
        case World: {
            return tr("По миру");
        }
        default: {
            if (aSection - Count >= 0 && aSection - Count < profiles_.count()) {
                return profiles_[aSection - Count].first.personaName();
            } else {
                return QVariant();
            }
        }
        }
    else
        return QString("");//.arg(aSection);
}

AchievementID AchievementsModel::achievementId(const QModelIndex &aIndex) const {
    return achievementsInModel_[aIndex.row() - c_reservedRows].schema.apiName();
}

bool AchievementsModel::hasChildren(const QModelIndex &aParent) const {
    Q_UNUSED(aParent);
    return achievementsInModel_.count() > 0;
}

Qt::ItemFlags AchievementsModel::flags(const QModelIndex &aIndex) const {
    if (!aIndex.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(aIndex) | Qt::ItemIsEditable;
}

bool AchievementsModel::insertColumn(int aColumn, int aCount, const QModelIndex &aParent) {
    Q_UNUSED(aColumn);
    Q_UNUSED(aCount);
    Q_UNUSED(aParent);
    return false;
}

bool AchievementsModel::removeColumn(int aColumn, int aCount, const QModelIndex &aParent) {
    Q_UNUSED(aColumn);
    Q_UNUSED(aCount);
    Q_UNUSED(aParent);
    return false;
}

SAchievement AchievementsModel::getAchievement(const int &aRow) const {
    auto &schema = achievementsInModel_[aRow].schema;
    auto &percent = achievementsInModel_[aRow].percent;
    auto &player = achievementsInModel_[aRow].profiles[0];
    return SAchievement(schema, player, percent);
}

SAchievement AchievementsModel::getAchievement(const QModelIndex &aIndex) const {
    auto &schema = achievementsInModel_[aIndex.row()].schema;
    auto &percent = achievementsInModel_[aIndex.row()].percent;
    auto &player = achievementsInModel_[aIndex.row()].profiles[0];
    return SAchievement(schema, player, percent);
}

SAchievements AchievementsModel::getAchievements() const {
    SAchievements achievements;
    for (const auto &achievement: achievementsInModel_) {
        achievements.append(SAchievement(achievement.schema, achievement.profiles[0], achievement.percent));
    }
    return achievements;
}

int AchievementsModel::getReachedFromProfile(const int &aIndex) {
    if (aIndex < 0 || aIndex > profiles_.count() || achievementsInModel_.count() == 0) {
        return -1;
    }
    int result = 0;
    if (achievementsInModel_[0].profiles[aIndex].achieved() < 0) {
        return -1;
    }
    for (const auto &achievement: qAsConst(achievementsInModel_)) {
        result += achievement.profiles[aIndex].achieved();
    }
    return result;
}

int AchievementsModel::getAchievementsCount() const {
    return achievementsInModel_.count();
}

int AchievementsModel::addProfile(const SProfile &aProfile) {
    beginInsertColumns(QModelIndex(), columnCount(), columnCount());
    int countAchieved = 0;
    auto players = SAchievementsPlayer(gameId_, aProfile.steamId());
    if (players.count() == achievementsInModel_.count()) {
        for (auto &achievement: achievementsInModel_) {
            for (auto &player: players) {
                if (player.apiName() == achievement.schema.apiName()) {
                    countAchieved += player.achieved();
                    achievement.profiles.append(player);
                    break;
                }
            }
        }
    } else {
        for (auto &achievement: achievementsInModel_) {
            achievement.profiles.append(SAchievementPlayer(players.error()));
        }
    }
    profiles_.append(QPair<SProfile, int>(aProfile, countAchieved));
    endInsertColumns();
    return profiles_.count() - 1;
}

SProfile AchievementsModel::getProfile(const int &aIndex) {
    return profiles_[aIndex].first;
}

int AchievementsModel::getProfileNumber(const ProfileID &aProfileId) {
    auto iterator = std::find_if(profiles_.begin(),
                                 profiles_.end(),
                                 [=](const QPair<SProfile, double> &lProfile) {
                                    return lProfile.first.steamId() == aProfileId;
                                 });
    if (iterator != profiles_.end()) {
        return iterator - profiles_.begin();
    } else {
        return -1;
    }
}

void AchievementsModel::removeProfile(const SProfile &aProfile) {
    beginRemoveColumns(QModelIndex(), columnCount() - 1, columnCount() - 1);
    auto iterator = std::find_if(profiles_.begin(),
                                 profiles_.end(),
                                 [=](const QPair<SProfile, double> &lProfile) {
                                    return lProfile.first.steamId() == aProfile.steamId();
                                });
    if (iterator == profiles_.end()) {
        return;
    }
    int i = iterator - profiles_.begin();
    for (auto &aim: achievementsInModel_) {
        aim.profiles.removeAt(i);
    }
    profiles_.removeAt(i);
    endRemoveColumns();
//    emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
}

void AchievementsModel::clearProfiles() {
    while (profiles_.count() > 1) {
        profiles_.removeAt(1);
    }
    for (auto &achievement: achievementsInModel_) {
        while (achievement.profiles.count() > 1) {
            achievement.profiles.removeAt(1);
        }
    }
}

void AchievementsModel::updateComments() {
    auto comments = AchievementComments(profileId_).getCommentsFromGame(profileId_, gameId_);
    int progress = 0;
    for(auto &achievement: achievementsInModel_) {
        auto iterator = std::find_if(comments.begin(),
                                     comments.end(),
                                     [=](const AchievementComment &achievementComment) {
                                        return QString::number(achievementComment.gameId()) == achievement.percent.apiName();
                                     });

        if (iterator != comments.end()) {
            achievement.comment = (*iterator).comment();
        } else {
            achievement.comment = QStringList();
        }
        emit s_progress(tr("Обновление комментариев"), ++progress, achievementsInModel_.count());
    }
}

void AchievementsModel::sort(int aColumn, Qt::SortOrder aOrder) {
    switch (aColumn) {
    case Appid: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.schema.apiName() < a2.schema.apiName();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.schema.apiName() > a2.schema.apiName();
                      }
                    );
            break;
        }
        }
        break;
    }
    case Index: {
        break;
    }
    case Icon: {
        break;
    }
    case Title: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.schema.displayName() < a2.schema.displayName();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.schema.displayName() > a2.schema.displayName();
                      }
                    );
            break;
        }
        }
        break;
    }
    case Description: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.schema.description() < a2.schema.description();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.schema.description() > a2.schema.description();
                      }
                    );
            break;
        }
        }
        break;
    }
    case Comments: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return (a1.comment != QStringList() &&
                                a1.comment != QStringList() << "" ? 1 : 0) <
                                (a2.comment != QStringList() &&
                                a2.comment != QStringList() << "" ? 1 : 0);
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return (a1.comment != QStringList() &&
                                a1.comment != QStringList() << "" ? 1 : 0) >
                                (a2.comment != QStringList() &&
                                a2.comment != QStringList() << "" ? 1 : 0);
                      }
                    );
            break;
        }
        }
        break;
    }
    case World: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.percent.percent() < a2.percent.percent();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.percent.percent() > a2.percent.percent();
                      }
                    );
            break;
        }
        }
        break;
    }
    default: {
        switch(aOrder) {
        case Qt::SortOrder::AscendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [&aColumn](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.profiles[aColumn - Count].unlockTime() < a2.profiles[aColumn - Count].unlockTime();
                      }
                    );
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            std::sort(achievementsInModel_.begin(),
                      achievementsInModel_.end(),
                      [&aColumn](AchievementInModel &a1, AchievementInModel &a2) {
                        return a1.profiles[aColumn - Count].unlockTime() > a2.profiles[aColumn - Count].unlockTime();
                      }
                    );
            break;
        }
        }
        break;
    }
    }
    emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
}

CategoriesFilter::CategoriesFilter() {

}

CategoriesFilter::CategoriesFilter(QMap<QString, QList<Category *> > aCategories): categories_(aCategories) {

}

bool CategoriesFilter::addCategory(Category *aCategory) {
    if (aCategory == nullptr) {
        return false;
    }
    QStringList list = aCategory->getPathFromRoot();
    for(QString &category: list) {
        category.replace(".", "..");
    }
    list.takeFirst();
    QString parent = list.join(".");
    auto iteratorOneParent = categories_.find(parent);
    if (iteratorOneParent != categories_.end()) {
        iteratorOneParent.value().append(aCategory);
        return true;
    } else {
        categories_.insert(parent, QList<Category*>{aCategory});
        return true;
    }
    return false;
}

bool CategoriesFilter::removeCategory(Category *aCategory) {
    if (aCategory == nullptr) {
        return false;
    }
    QStringList list = aCategory->getPathFromRoot();
    for(QString &category: list) {
        category.replace(".", "..");
    }
    list.takeFirst();
    QString parent = list.join(".");
    auto iteratorOneParent = categories_.find(parent);
    if (iteratorOneParent != categories_.end()) {
        auto &listCategories = iteratorOneParent.value();
        auto iteratorCategory = std::find_if(listCategories.begin(),
                                             listCategories.end(),
                                             [&](Category *lCategory) {
                                                return lCategory == aCategory;
                                            });
        if (iteratorCategory != listCategories.end()) {
            listCategories.removeAt(iteratorCategory - listCategories.begin());
            if (listCategories.count() == 0) {
                categories_.remove(parent);
            }
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void CategoriesFilter::clear() {
    categories_.clear();
}

QMap<QString, QList<Category *> > CategoriesFilter::getCategories() const {
    return categories_;
}

QSet<AchievementID> CategoriesFilter::getAchievementIDs() {
    QList<QSet<AchievementID>> list;
    for (auto &oneParentCategories: categories_) {
        QSet<AchievementID> set;
        for (Category *category: oneParentCategories) {
            for (const AchievementID &achievement: *category) {
                set.insert(achievement);
            }
        }
        list << set;
    }

    if (list.count() == 0) {
        return QSet<AchievementID>();
    } else if (list.count() == 1) {
        return list[0];
    } else {
        QSet<AchievementID> result;
        for (const auto &achievementID: list[0]) {
            bool isAllExist = true;
            for (auto iteratorSet = std::next(list.begin()); iteratorSet != list.end(); ++iteratorSet) {
                bool isExist = std::any_of((*iteratorSet).begin(),
                                            (*iteratorSet).end(),
                                            [&](const AchievementID &lAchievementId) {
                                                return lAchievementId == achievementID;
                                            });
                isAllExist &= isExist;
            }
            if (isAllExist) {
                result << achievementID;
            }
        }
        return result;
    }
}

FilterModelAchievements::FilterModelAchievements(int aRow, QObject *aParent): FilterModel(aRow, 4, aParent) {
    columns_.insert("name", 0);
    columns_.insert("reached", 1);
    columns_.insert("categories", 2);
    columns_.insert("favorite", 3);
}

bool FilterModelAchievements::filterAcceptsRow(int aSource_row, const QModelIndex &aSource_parent) const {
    Q_UNUSED(aSource_parent);
    if (aSource_row < c_reservedRows) {
        return true;
    }
    return filter_[aSource_row];
}

const int SPECIFIC_DATA_INDEX = 0;
const QString SPECIFIC_DATA = "";

bool FilterModelAchievements::lessThan(const QModelIndex &aLeft, const QModelIndex &aRight) const {
    // Get specific data from left row
    QModelIndex leftIndex = sourceModel()->index(aLeft.row(), SPECIFIC_DATA_INDEX);
    QString leftProperty = sourceModel()->data(leftIndex).toString();
    // Get specific data from right row
    QModelIndex  rightIndex = sourceModel()->index(aRight.row(), SPECIFIC_DATA_INDEX);
    QString rightProperty = sourceModel()->data(rightIndex).toString();

    if(leftProperty.compare(SPECIFIC_DATA) == 0) {// put left on top if it has a specific property
        return sortOrder() == Qt::AscendingOrder;
    } else if(rightProperty.compare(SPECIFIC_DATA) == 0) { // put right on top if it has a specific property
        return sortOrder() != Qt::AscendingOrder;
    }

    if (aLeft.column() == aRight.column() && aLeft.column() == World) {
        QVariant leftData = sourceModel()->data(aLeft);
        QVariant rightData = sourceModel()->data(aRight);
        double iLeft = leftData.toString().left(leftData.toString().indexOf("%")).toDouble();
        double iRight = rightData.toString().left(rightData.toString().indexOf("%")).toDouble();
        return iLeft < iRight;
    }
    return QSortFilterProxyModel::lessThan(aLeft, aRight);
}

int FilterModelAchievements::addProfile(const SProfile &aProfile) {
    int number = sourceModel()->addProfile(aProfile);
    static int column = 3;
    columns_.insert(aProfile.steamId(), ++column);
    filter_.insertCol(column);
    return number;
}

SProfile FilterModelAchievements::getProfile(const int &aIndex) {
    return sourceModel()->getProfile(aIndex);
}

void FilterModelAchievements::removeProfile(const SProfile &aProfile) {
    sourceModel()->removeProfile(aProfile);
    int filterColumnReached = columns_.value(aProfile.steamId());
    filter_.disableCol(filterColumnReached);
}

void FilterModelAchievements::setSourceModel(AchievementsModel *aSourceModel) {
    connect(aSourceModel, &AchievementsModel::s_finished, this, [=, this]() {
        if (sourceModel() != nullptr) {
            filter_.setRows(sourceModel()->rowCount());
            forceInvalidate();
            emit s_modelFinished();
            emit s_rowsUpdated();
        } else {
            qWarning() << "in FilterModelAchievements missing sourceModel, but emit 'finished'";
        }
    });
    FilterModel::setSourceModel(aSourceModel);
}

QMap<ProfileID, int> FilterModelAchievements::getProfiles() {
    return profiles_;
}

AchievementsModel *FilterModelAchievements::sourceModel() const {
    return dynamic_cast<AchievementsModel*>(FilterModel::sourceModel());
}

void FilterModelAchievements::setName(const QString &aNewName) {
    if(name_ == aNewName)
        return;
    name_ = aNewName;
    int filterColumnName = columns_.value("name");
    for (int r = 0; r < sourceModel()->rowCount(); ++r) {
        QModelIndex titleIndex = sourceModel()->index(r, Title);
        QModelIndex descriptionIndex = sourceModel()->index(r, Description);
        bool isTitleInclude = sourceModel()->data(titleIndex).toString().toLower().indexOf(name_.toLower()) >= 0;
        bool isDescriptionInclude = sourceModel()->data(descriptionIndex).toString().toLower().indexOf(name_.toLower()) >= 0;
        filter_.setData(r, filterColumnName, isTitleInclude || isDescriptionInclude);
    }
    invalidateFilter();
}

void FilterModelAchievements::setReached(int aNewReached) {
    if(reached_ == aNewReached)
        return;
    reached_ = aNewReached;
    int filterColumnReached = columns_.value("reached");
    for (int r = 0; r < sourceModel()->rowCount(); ++r) {
        QModelIndex reachedIndex = sourceModel()->index(r, ReachedMy);
        bool isApply = true;
        switch (reached_) {
        case -1: {
            if (QDateTime::fromString(sourceModel()->data(reachedIndex).toString(), Settings::dateTimeFormatShort()).isValid()) {
                isApply = false;
            }
            break;
        }
        case 0: {
            break;
        }
        case 1: {
            if (!QDateTime::fromString(sourceModel()->data(reachedIndex).toString(), Settings::dateTimeFormatShort()).isValid()) {
                isApply = false;
            }
            break;
        }
        default: {

        }
        }
        filter_.setData(r, filterColumnReached, isApply);
    }
    invalidateFilter();
}

void FilterModelAchievements::setReachedFriend(int aNewReached, const ProfileID &aProfileId) {
    profiles_.insert(aProfileId, aNewReached);
    int filterColumnReached = columns_.value(aProfileId);
    int columnNumber = Count + sourceModel()->getProfileNumber(aProfileId);
    for (int r = 0; r < sourceModel()->rowCount(); ++r) {
        QModelIndex reachedIndex = sourceModel()->index(r, columnNumber);
        bool isApply = true;
        switch (aNewReached) {
        case -1: {
            if (QDateTime::fromString(sourceModel()->data(reachedIndex).toString(), Settings::dateTimeFormatShort()).isValid()) {
                isApply = false;
            }
            break;
        }
        case 0: {
            break;
        }
        case 1: {
            if (!QDateTime::fromString(sourceModel()->data(reachedIndex).toString(), Settings::dateTimeFormatShort()).isValid()) {
                isApply = false;
            }
            break;
        }
        default: {

        }
        }
        filter_.setData(r, filterColumnReached, isApply);
    }
    invalidateFilter();
}

void FilterModelAchievements::setCategories(const CategoriesFilter &aNewCategories) {
    categories_ = aNewCategories;
    updateCategoriesFilter();
}

void FilterModelAchievements::updateCategoriesFilter() {
    auto ids = categories_.getAchievementIDs();
    int filterColumnCategories = columns_.value("categories");
    if (categories_.getCategories().count() > 0) {
        for (int r = 0; r < sourceModel()->rowCount(); ++r) {
            QModelIndex appIdIndex = sourceModel()->index(r, Appid);
            bool isApply = ids.find(sourceModel()->data(appIdIndex).toString()) != ids.end();
            filter_.setData(r, filterColumnCategories, isApply);
        }
    } else {
        filter_.clearCol(filterColumnCategories);
    }
    invalidateFilter();
}

CategoriesFilter FilterModelAchievements::getCategories() const {
    return categories_;
}

void FilterModelAchievements::addCategory(Category *aCategory) {
    categories_.addCategory(aCategory);
    updateCategoriesFilter();
}

void FilterModelAchievements::removeCategory(Category *aCategory) {
    categories_.removeCategory(aCategory);
    updateCategoriesFilter();
}

void FilterModelAchievements::setFavorites(const QStringList &aNewFavorites) {
    if(favorite_ == aNewFavorites)
        return;
    favorite_ = aNewFavorites;
    int filterColumnFavorite = columns_.value("favorite");
    if (favorite_.isEmpty()) {
        filter_.clearCol(filterColumnFavorite);
    } else {
        for (int r = 0; r < sourceModel()->rowCount(); ++r) {
            QModelIndex appIdIndex = sourceModel()->index(r, Appid);
            filter_.setData(r, filterColumnFavorite, favorite_.indexOf(sourceModel()->data(appIdIndex).toString()) >= 0);
        }
    }
    invalidateFilter();
}

void FilterModelAchievements::clear() {
    name_.clear();
    reached_ = 0;
    categories_.clear();
    favorite_.clear();
    filter_.clear();
}
