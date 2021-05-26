#include "achievementsmodel.h"

constexpr QColor c_achievedColor      = QColor (87, 220, 87, 255 * 1);
constexpr QColor c_notAchievedColor   = QColor (255, 48, 48, 255 * 1);
constexpr int c_reservedRows = 1;

void AchievementsModel::setAchievements(const QString &aUserId, const QString &aGameId) {
    _userId = aUserId;
    _gameId = aGameId;
    _achievementsInModel.clear();

    auto globals = SAchievementSchema::load(_gameId);
    auto percents = SAchievementPercentage::load(_gameId);

    auto comments = AchievementComment::load(aUserId, _gameId);

    int progress = 0;
    for (auto &global: globals) {
        for (auto &percent: percents) {
            if (percent.apiName() != global.apiName()) {
                continue;
            }
            auto iterator = std::find_if(comments.begin(),
                                         comments.end(),
                                         [=](const AchievementComment &achievementComment) {
                                            return achievementComment.gameId() == percent.apiName();
                                         });
            auto achievement = AchievementInModel{cLoadPixmap(global.icon(), Paths::imagesAchievements(aGameId, global.icon()), QSize(64, 64)),
                                                    QStringList(),
                                                    global,
                                                    percent,
                                                    QList<SAchievementPlayer>()};
            if (iterator != comments.end()) {
                achievement.comment = (*iterator).comment();
            }
            _achievementsInModel.append(std::move(achievement));
            emit s_progress(1, ++progress);
            break;
        }
    }

    auto profile = SProfile::load(aUserId, SProfileRequestType::id);
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
                return _profiles[index.column() - AchievementCount].first;
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
                return textToToolTip(_profiles[index.column() - AchievementCount].second.personaName());
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
            auto achievement = _achievementsInModel[index.row() - c_reservedRows].profiles[index.column() - AchievementCount];
            if (achievement.achieved() == 1) {
                return achievement.unlockTime().toString(Settings::dateTimeFormatShort());
            } else {
                return tr("Не получено");
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
            if (_achievementsInModel[index.row() - c_reservedRows].profiles[index.column() - AchievementCount].achieved() == 1) {
                return c_achievedColor;
            } else {
                return c_notAchievedColor;
            }
            break;
        }
        }
        break;
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
                return _profiles[section - AchievementCount].second.personaName();
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

}

bool AchievementsModel::removeColumn(int column, int count, const QModelIndex &parent) {

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

int AchievementsModel::getReachedFromProfile(const int &index) {
    if (index < 0 || index > _profiles.count()) {
        return -1;
    }
    int result = 0;
    if (_achievementsInModel[0].profiles[index].achieved() < 0) {
        return -1;
    }
    for (const auto &achievement: _achievementsInModel) {
        result += achievement.profiles[index].achieved();
    }
    return result;
}

int AchievementsModel::getAchievementsCount() {
    return _achievementsInModel.count();
}

int AchievementsModel::addProfile(const SProfile &aProfile) {
    beginInsertColumns(QModelIndex(), columnCount(), columnCount());
    _profiles.append(std::move(QPair<QPixmap, SProfile>(aProfile.pixmapAvatar(), aProfile)));
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
            achievement.profiles.append(std::move(SAchievementPlayer()));
        }
    }
    endInsertColumns();
    return _profiles.count() - 1;
}

SProfile AchievementsModel::getProfile(const int &index) {
    return _profiles[index].second;
}

void AchievementsModel::removeProfile(const SProfile &aProfile) {
    beginRemoveColumns(QModelIndex(), columnCount() - 1, columnCount() - 1);
    auto iterator = std::find_if(_profiles.begin(),
                                 _profiles.end(),
                                 [=](const QPair<QPixmap, SProfile> &lProfile) {
                                    return lProfile.second.steamID() == aProfile.steamID();
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
                                        return achievementComment.gameId() == achievement.percent.apiName();
                                     });

        if (iterator != comments.end()) {
            achievement.comment = (*iterator).comment();
        } else {
            achievement.comment = QStringList();
        }
        emit s_progress(1, ++progress);
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
