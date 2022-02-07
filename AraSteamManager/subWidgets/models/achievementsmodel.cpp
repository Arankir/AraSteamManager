#include "achievementsmodel.h"

constexpr QColor c_achievedColor      = QColor (87, 220, 87, 255 * 1);
constexpr QColor c_notAchievedColor   = QColor (255, 48, 48, 255 * 1);
constexpr int c_reservedRows = 1;

void AchievementsModel::setAchievements(const ProfileID &aUserId, const GameID &aGameId) {
    _userId = aUserId;
    _gameId = aGameId;
    _achievementsInModel.clear();
    _profiles.clear();

    auto globals = SAchievementSchema::load(_gameId);
    auto percents = SAchievementPercentage::load(_gameId);

    auto comments = AchievementComment::load(aUserId, _gameId);

    int progress = 0;
    for (auto &global: globals) {
        for (auto &percent: percents) {
            if (percent.apiName() != global.apiName()) {
                continue;
            }
            QImage pix;
            auto achievement = AchievementInModel {QPixmap::fromImage(loadImage(pix, global.icon(), Paths::imagesAchievements(QString::number(aGameId), global.icon()), QSize(64, 64))),
                                                    QStringList(),
                                                    global,
                                                    percent,
                                                    QList<SAchievementPlayer>()};
            auto iterator = std::find_if(comments.begin(),
                                         comments.end(),
                                         [=](const AchievementComment &achievementComment) {
                                            return QString::number(achievementComment.gameId()) == percent.apiName();
                                         });
            if (iterator != comments.end()) {
                achievement.comment = (*iterator).comment();
            }
            _achievementsInModel.append(std::move(achievement));
            emit s_progress(tr("Загрузка достижений"), ++progress, globals.count());
            break;
        }
    }

    auto profile = SProfile::load(aUserId, SProfile::LoadType::id);
    addProfile(profile);
    emit s_finished();
}

int AchievementsModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return AchievementCount + _profiles.count();
}

int AchievementsModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return _achievementsInModel.count() + c_reservedRows;
}

QVariant AchievementsModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= _achievementsInModel.size() + c_reservedRows)
        return QVariant();

    if (index.row() < c_reservedRows) {
        switch (role) {
        case Qt::DecorationRole: {
            switch (index.column()) {
            case AchievementAppid:
            case AchievementIndex:
            case AchievementIcon:
            case AchievementTitle:
            case AchievementDescription:
            case AchievementComments:
            case AchievementWorld: {
                return QVariant();
            }
            default: {
                return _profiles[index.column() - AchievementCount].pixmapAvatar();
            }
            }
            break;
        }
        case Qt::ToolTipRole: {
            switch (index.column()) {
            case AchievementAppid:
            case AchievementIndex:
            case AchievementIcon:
            case AchievementTitle:
            case AchievementDescription:
            case AchievementComments:
            case AchievementWorld: {
                return QVariant();
            }
            default: {
                return textToToolTip(_profiles[index.column() - AchievementCount].personaName());
            }
            }
            break;
        }
        default: {
            return QVariant();
        }
        }
    }

    switch (role) {
    case Qt::DisplayRole: {
        switch (index.column()) {
        case AchievementAppid: {
            return _achievementsInModel[index.row() - c_reservedRows].schema.apiName();
        }
        case AchievementIndex: {
            return index.row() - c_reservedRows;
        }
        case AchievementIcon: {
            return QVariant();
        }
        case AchievementTitle: {
            return _achievementsInModel[index.row() - c_reservedRows].schema.displayName();
        }
        case AchievementDescription: {
            return _achievementsInModel[index.row() - c_reservedRows].schema.description();
        }
        case AchievementComments: {
//            if (_achievementsInModel[index.row() - c_reservedRows].comment != QStringList() &&
//                _achievementsInModel[index.row() - c_reservedRows].comment != QStringList() << "") {
//                return 1;
//            } else {
//                return 0;
//            }
            return QVariant();
        }
        case AchievementWorld: {
            return QString{"%1"}.arg(_achievementsInModel[index.row() - c_reservedRows].percent.percent(), 5, 'f', 1, '0') + "%";
        }
        default: {
            if (_achievementsInModel[index.row() - c_reservedRows].profiles.size() > (index.column() - AchievementCount)) {
                auto achievement = _achievementsInModel[index.row() - c_reservedRows].profiles[index.column() - AchievementCount];
                if (achievement.achieved() == 1) {
                    return achievement.unlockTime().toString(Settings::dateTimeFormatShort());
                } else {
                    return tr("Не получено");
                }
            } else {
                qWarning() << "no profile from achievements need"
                           << (index.column() - AchievementCount + 1)
                           << "have"
                           << _achievementsInModel[index.row() - c_reservedRows].profiles.size();
                return QVariant();
            }
        }
        }
        break;
    }
    case Qt::DecorationRole: {
        switch (index.column()) {
        case AchievementIcon: {
            return _achievementsInModel[index.row() - c_reservedRows].icon;
        }
        case AchievementComments: {
            if (_achievementsInModel[index.row() - c_reservedRows].comment != QStringList() &&
                _achievementsInModel[index.row() - c_reservedRows].comment != QStringList() << "") {
                return QPixmap(Images::isComment()).scaled(32, 32);
            } else {
                return QPixmap(Images::isNotComment()).scaled(32, 32);
            }
        }
        default: {
            return QVariant();
        }
        }
        break;
    }
    case Qt::ToolTipRole: {
        switch (index.column()) {
        case AchievementTitle: {
            return textToToolTip(_achievementsInModel[index.row() - c_reservedRows].schema.displayName());
        }
        case AchievementDescription: {
            return textToToolTip(_achievementsInModel[index.row() - c_reservedRows].schema.description());
        }
        default: {
            return QVariant();
        }
        }
        break;
    }
    case Qt::ForegroundRole: {
        switch (index.column()) {
        case AchievementAppid:
        case AchievementIndex:
        case AchievementIcon:
        case AchievementTitle:
        case AchievementDescription:
        case AchievementComments:
        case AchievementWorld: {
            return QVariant();
        }
        default: {
            if (_achievementsInModel[index.row() - c_reservedRows].profiles.size() > (index.column() - AchievementCount)) {
                if (_achievementsInModel[index.row() - c_reservedRows].profiles[index.column() - AchievementCount].achieved() == 1) {
                    return c_achievedColor;
                } else {
                    return c_notAchievedColor;
                }
            } else {
                qWarning() << "no profile from achievements need"
                           << (index.column() - AchievementCount + 1)
                           << "have"
                           << _achievementsInModel[index.row() - c_reservedRows].profiles.size();
                return QVariant();
            }
            break;
        }
        }
        break;
    }
    case Qt::TextAlignmentRole: {
        switch (index.column()) {
        case AchievementAppid:
        case AchievementIndex:
        case AchievementIcon:
        case AchievementTitle:
        case AchievementDescription:
        case AchievementComments: {
            return QVariant();
        }
        case AchievementWorld: {
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

QVariant AchievementsModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        switch (section) {
        case AchievementAppid: {
            return tr("ID");
        }
        case AchievementIndex: {
            return tr("");
        }
        case AchievementIcon: {
            return tr("");
        }
        case AchievementTitle: {
            return tr("Название");
        }
        case AchievementDescription: {
            return tr("Описание");
        }
        case AchievementComments: {
            return tr("");
        }
        case AchievementWorld: {
            return tr("По миру");
        }
        default: {
            if (section - AchievementCount >= 0 && section - AchievementCount < _profiles.count()) {
                return _profiles[section - AchievementCount].personaName();
            } else {
                return QVariant();
            }
        }
        }
    else
        return QString("%1").arg(section);
}

QString AchievementsModel::achievementId(const QModelIndex &index) const {
    return _achievementsInModel[index.row() - c_reservedRows].schema.apiName();
}

bool AchievementsModel::hasChildren(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return _achievementsInModel.count() > 0;
}

Qt::ItemFlags AchievementsModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool AchievementsModel::insertColumn(int column, int count, const QModelIndex &parent) {
    Q_UNUSED(column);
    Q_UNUSED(count);
    Q_UNUSED(parent);
    return false;
}

bool AchievementsModel::removeColumn(int column, int count, const QModelIndex &parent) {
    Q_UNUSED(column);
    Q_UNUSED(count);
    Q_UNUSED(parent);
    return false;
}

SAchievement AchievementsModel::getAchievement(const int &row) const {
    auto &schema = _achievementsInModel[row].schema;
    auto &percent = _achievementsInModel[row].percent;
    auto &player = _achievementsInModel[row].profiles[0];
    return SAchievement(schema, player, percent);
}

SAchievement AchievementsModel::getAchievement(const QModelIndex &index) const {
    auto &schema = _achievementsInModel[index.row()].schema;
    auto &percent = _achievementsInModel[index.row()].percent;
    auto &player = _achievementsInModel[index.row()].profiles[0];
    return SAchievement(schema, player, percent);
}

SAchievements AchievementsModel::getAchievements() const {
    SAchievements achievements;
    for (const auto &achievement: _achievementsInModel) {
        achievements.append(SAchievement(achievement.schema, achievement.profiles[0], achievement.percent));
    }
    return achievements;
}

int AchievementsModel::getReachedFromProfile(const int &index) {
    if (index < 0 || index > _profiles.count() || _achievementsInModel.count() == 0) {
        return -1;
    }
    int result = 0;
    if (_achievementsInModel[0].profiles[index].achieved() < 0) {
        return -1;
    }
    for (const auto &achievement: qAsConst(_achievementsInModel)) {
        result += achievement.profiles[index].achieved();
    }
    return result;
}

int AchievementsModel::getAchievementsCount() {
    return _achievementsInModel.count();
}

int AchievementsModel::addProfile(const SProfile &aProfile) {
    beginInsertColumns(QModelIndex(), columnCount(), columnCount());
    _profiles.append(aProfile);
    auto players = SAchievementPlayer::load(_gameId, aProfile.steamID());
    if (players.count() == _achievementsInModel.count()) {
        for (auto &achievement: _achievementsInModel) {
            for (auto &player: players) {
                if (player.apiName() == achievement.schema.apiName()) {
                    achievement.profiles.append(std::move(player));
                    break;
                }
            }
        }
    } else {
        for (auto &achievement: _achievementsInModel) {
            achievement.profiles.append(SAchievementPlayer());
        }
    }
    endInsertColumns();
    return _profiles.count() - 1;
}

SProfile AchievementsModel::getProfile(const int &index) {
    return _profiles[index];
}

void AchievementsModel::removeProfile(const SProfile &aProfile) {
    beginRemoveColumns(QModelIndex(), columnCount() - 1, columnCount() - 1);
    auto iterator = std::find_if(_profiles.begin(),
                                 _profiles.end(),
                                 [=](const SProfile &lProfile) {
                                    return lProfile.steamID() == aProfile.steamID();
                                });
    if (iterator == _profiles.end()) {
        return;
    }
    int i = iterator - _profiles.begin();
    for (auto &aim: _achievementsInModel) {
        aim.profiles.removeAt(i);
    }
    _profiles.removeAt(i);
    endRemoveColumns();
//    emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
}

void AchievementsModel::clearProfiles() {
    while (_profiles.count() > 1) {
        _profiles.removeAt(1);
    }
    for (auto &achievement: _achievementsInModel) {
        while (achievement.profiles.count() > 1) {
            achievement.profiles.removeAt(1);
        }
    }
}

void AchievementsModel::updateComments() {
    auto comments = AchievementComment::load(_userId, _gameId);
    int progress = 0;
    for(auto &achievement: _achievementsInModel) {
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
        emit s_progress(tr("Обновление комментариев"), ++progress, _achievementsInModel.count());
    }
}

void AchievementsModel::sort(int column, Qt::SortOrder order) {
    switch (column) {
    case AchievementAppid: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return a1.schema.apiName() < a2.schema.apiName();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return a1.schema.apiName() > a2.schema.apiName();});
            break;
        }
        }
        break;
    }
    case AchievementIndex: {
        break;
    }
    case AchievementIcon: {
        break;
    }
    case AchievementTitle: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return a1.schema.displayName() < a2.schema.displayName();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return a1.schema.displayName() > a2.schema.displayName();});
            break;
        }
        }
        break;
    }
    case AchievementDescription: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return a1.schema.description() < a2.schema.description();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return a1.schema.description() > a2.schema.description();});
            break;
        }
        }
        break;
    }
    case AchievementComments: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return (a1.comment != QStringList() &&
                                                                                                                        a1.comment != QStringList() << "" ? 1 : 0) <
                                                                                                                        (a2.comment != QStringList() &&
                                                                                                                        a2.comment != QStringList() << "" ? 1 : 0);});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return (a1.comment != QStringList() &&
                                                                                                                        a1.comment != QStringList() << "" ? 1 : 0) >
                                                                                                                        (a2.comment != QStringList() &&
                                                                                                                        a2.comment != QStringList() << "" ? 1 : 0);});
            break;
        }
        }
        break;
    }
    case AchievementWorld: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return a1.percent.percent() < a2.percent.percent();});
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort<AchievementInModel>(_achievementsInModel, [](AchievementInModel &a1, AchievementInModel &a2) {return a1.percent.percent() > a2.percent.percent();});
            break;
        }
        }
        break;
    }
    default: {
        switch(order) {
        case Qt::SortOrder::AscendingOrder: {
            mySort2<AchievementInModel>(_achievementsInModel, [&column](AchievementInModel &a1, AchievementInModel &a2) {
                return a1.profiles[column - AchievementCount].unlockTime() < a2.profiles[column - AchievementCount].unlockTime();
            });
            break;
        }
        case Qt::SortOrder::DescendingOrder: {
            mySort2<AchievementInModel>(_achievementsInModel, [&column](AchievementInModel &a1, AchievementInModel &a2) {
                return a1.profiles[column - AchievementCount].unlockTime() > a2.profiles[column - AchievementCount].unlockTime();
            });
            break;
        }
        }
        break;
    }
    }
    emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
}

ProxyModelAchievements::ProxyModelAchievements(QObject *aParent): QSortFilterProxyModel(aParent),
_name(""), _reached(0) {

}

bool ProxyModelAchievements::filterAcceptsRow(int aSource_row, const QModelIndex &aSource_parent) const {
    QModelIndex indTitle = sourceModel()->index(aSource_row, AchievementTitle, aSource_parent);
    QModelIndex indDescription = sourceModel()->index(aSource_row, AchievementDescription, aSource_parent);
    QModelIndex indReached = sourceModel()->index(aSource_row, AchievementReachedMy, aSource_parent);
    QModelIndex indId = sourceModel()->index(aSource_row, AchievementAppid, aSource_parent);

    AchievementID id = sourceModel()->data(indId, Qt::ItemDataRole::DisplayRole).toString();

    if (_name != "" &&
        sourceModel()->data(indTitle, Qt::ItemDataRole::DisplayRole).toString().toLower().indexOf(_name) == -1 &&
        sourceModel()->data(indDescription, Qt::ItemDataRole::DisplayRole).toString().toLower().indexOf(_name) == -1) {
        return false;
    }
    switch (_reached) {
    case -1: {
        if (QDateTime::fromString(sourceModel()->data(indReached, Qt::ItemDataRole::DisplayRole).toString(), Settings::dateTimeFormatShort()).isValid()) {
            return false;
        }
        break;
    }
    case 0: {
        break;
    }
    case 1: {
        if (!QDateTime::fromString(sourceModel()->data(indReached, Qt::ItemDataRole::DisplayRole).toString(), Settings::dateTimeFormatShort()).isValid()) {
            return false;
        }
        break;
    }
    default: {

    }
    }
    if (!_favorite.isEmpty() && _favorite.indexOf(id) == -1) {
        return false;
    }

    if (_categories.size() > 0) {
        return std::any_of(_preCategories.begin(),
                           _preCategories.end(),
                           [&](const QString &lAchievement) {
                                return id == lAchievement;
                           });
    } else {
        return true;
    }
}

QVariant ProxyModelAchievements::headerData(int section, Qt::Orientation orientation, int role) const {
    return sourceModel()->headerData(section, orientation, role);
}

AchievementsModel *ProxyModelAchievements::sourceModel() const {
    return static_cast<AchievementsModel*>(QSortFilterProxyModel::sourceModel());
}

void ProxyModelAchievements::setSourceModel(AchievementsModel *sourceModel) {
    QSortFilterProxyModel::setSourceModel(sourceModel);
}

void ProxyModelAchievements::setName(const QString &aNewName) {
    if(_name != aNewName)
        _name = aNewName;
    invalidateFilter();
}

void ProxyModelAchievements::setReached(int aNewReached) {
    if(_reached != aNewReached)
        _reached = aNewReached;
    invalidateFilter();
}

void ProxyModelAchievements::setCategories(const CategoriesFilter &aNewCategories) {
    _categories = aNewCategories;

    QList<QStringList> pre;
    for (const auto &oneLineCategories: _categories) {
        QStringList orList;
        for (const auto &category: oneLineCategories.second) {
            orList << category.achievementsApiName();
        }
        pre << orList;
    }

    QStringList result;
    if (pre.count() > 0) {
        result = pre.at(0);
        for (auto &resultAchievement: result) {
            for (auto &list: pre) {
                bool isExist = std::any_of(list.begin(),
                                            list.end(),
                                            [&](const QString &lAchievementID) {
                                                return lAchievementID == resultAchievement;
                                            });
                if (!isExist) {
                    result.removeOne(resultAchievement);
                    break;
                }
            }
        }
    }

    _preCategories = result;

    invalidateFilter();
}

void ProxyModelAchievements::setFavorites(const QStringList &aNewFavorites) {
    if(_favorite != aNewFavorites)
        _favorite = aNewFavorites;
    invalidateFilter();
}

void ProxyModelAchievements::clear() {
    _name.clear();
    _reached = 0;
    _categories.clear();
    _favorite.clear();
}

Filter::Filter(int aRows, int aCols):
    rows_(std::max(0, aRows)),
    cols_(std::max(0, aCols)),
    checkCols_(QList<char>((int)ceil(cols_ / 8), 0xFF)),
    filter_(rows_, QList<char>((int)ceil(cols_ / 8), 0xFF)) {

}

bool Filter::operator[](int aRow) const {
    for (int c = 0; c < cols_; ++c) {
        if ((checkCols_[c / 8] >> (c % 8)) && !(filter_[aRow][c / 8] >> (c % 8))) {
            return false;
        }
    }
    return true;
}

void Filter::setData(int aRow, int aCol, bool aData) {
    if (aData) {
        filter_[aRow][aCol / 8] |= (1 << aCol % 8);
    } else {
        filter_[aRow][aCol / 8] &= ~(1 << aCol % 8);
    }
}

void Filter::setRows(int aRows) {
    int oldRows = rows_;
    rows_ = std::max(0, aRows);
    filter_.resize(rows_);
    if (rows_ > oldRows) {
        for (int r = oldRows; r < rows_; ++r) {
            filter_[r] = QList<char>((int)ceil(cols_ / 8), 0xFF);
        }
    }
}

void Filter::setCols(int aCols) {
    int oldCols = cols_;
    cols_ = std::max(0, aCols);
    if ((int)ceil(cols_ / 8) > (int)ceil(oldCols / 8)) {
        for (int r = 0; r < rows_; ++r) {
            filter_[r].resize((int)ceil(cols_ / 8));
            for (int c = oldCols; c < cols_; ++c) {
                filter_[r][c / 8] |= (1 << c % 8);
            }
        }
    } else {
        for (int r = 0; r < rows_; ++r) {
            filter_[r].resize((int)ceil(cols_ / 8));
        }
    }
}

void Filter::insertRow(int aRow) {
    int row = std::min(rows_, aRow);
    filter_.insert(row, QList<char>((int)ceil(cols_ / 8), 0xFF));
}

void Filter::removeRow(int aRow) {
    int row = std::min(rows_, aRow);
    filter_.remove(row);
}

void Filter::insertCol(int aCol) {
    int col = std::min(cols_, aCol);
    bool isNewChar = (((cols_ + 1) / 8) == 0);
    for (int r = 0; r < rows_; ++r) {
        if (isNewChar) {
            filter_.append(QList<char>((int)ceil(cols_ / 8), 0xFF));
        }
        for (int c = cols_; c > col; --c) {
            //сместить все биты направо >>
        }
        filter_[r][col / 8] |= (1 << aCol % 8);
    }
}

void Filter::removeCol(int aCol) {
    int col = std::min(cols_, aCol);
    bool isDeleteChar = (((cols_ - 1) / 8) == 0);
    for (int r = 0; r < rows_; ++r) {
        for (int c = col; c < cols_; ++c) {
            //сместить все биты налево <<
        }
        if (isDeleteChar) {
            filter_.remove(cols_);
        }
    }
}

void Filter::disableCol(int aCol) {
    checkCols_[aCol / 8] &= ~(1 << aCol % 8);
}

void Filter::enableCol(int aCol) {
    checkCols_[aCol / 8] |= (1 << aCol % 8);
}
