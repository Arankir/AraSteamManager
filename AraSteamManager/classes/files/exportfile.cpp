#include "exportfile.h"

//void ExportFileData::fromJson(QJsonObject aObject) {
//    ExportFileData efd;
//    efd.data = aObject["data"];
//    efd.type = stringToExportType(aObject["type"].toString());
//    efd.version = aObject["version"].toString().toDouble();
//    efd.date = QDateTime::fromString(aObject["date"].toString(), Settings::dateTimeFormat());
//    return efd;
//}

//ExportFileData::ExportFileData(ExportType aType, double aVersion, QDateTime aDate): FileSaveLoad(""), type(aType), version(aVersion), date(aDate) {

//}

//void ExportFileData::setPath(const QString &aPath) {
//    filePath_ = aPath;
//}

//void ExportFileData::fromJson(const QJsonObject &aObject) {
//    data = aObject["data"];
//    type = stringToExportType(aObject["type"].toString());
//    version = aObject["version"].toString().toDouble();
//    date = QDateTime::fromString(aObject["date"].toString(), Settings::dateTimeFormat());
//}

//QJsonObject ExportFileData::toJson() const {
//    QJsonObject jObject;
//    jObject["data"] = data;
//    jObject["type"] = exportTypeToString(type);
//    jObject["version"] = QString::number(version);
//    jObject["date"] = date.toString(Settings::dateTimeFormat());
//    return jObject;
//}

//QString exportTypeToString(ExportType aType) {
//    switch (aType) {
//    case ExportType::unknown: {
//        return "unknown";
//    }
//    case ExportType::categories: {
//        return "categories";
//    }
//    case ExportType::favorites: {
//        return "favorites";
//    }
//    case ExportType::comments: {
//        return "comments";
//    }
//    case ExportType::groups: {
//        return "groups";
//    }
//    case ExportType::settings: {
//        return "settings";
//    }
//    case ExportType::multiple: {
//        return "multiple";
//    }
//    }
//    return "";
//}

//ExportType stringToExportType(QString aType) {
//    if (aType == "categories") {
//        return ExportType::categories;
//    } else if (aType == "favorites") {
//        return ExportType::favorites;
//    } else if (aType == "comments") {
//        return ExportType::comments;
//    } else if (aType == "groups") {
//        return ExportType::groups;
//    } else if (aType == "settings") {
//        return ExportType::settings;
//    } else if (aType == "multiple") {
//        return ExportType::multiple;
//    } else {
//        return ExportType::unknown;
//    }
//}

//ExportFile::ExportFile(): FileSaveLoad("") {

//}

//ExportFile::ExportFile(const QJsonObject &aObject): FileSaveLoad("") {
//    fromJson(aObject);
//}

//ExportFile::ExportFile(const QString &aFilePath): FileSaveLoad(aFilePath) {
//    load(filePath_);
//}

//void ExportFile::fromJson(const QJsonObject &object) {

//}

//QJsonObject ExportFile::toJson() const {

//}

//ExportCategory::ExportCategory(): ExportFileData(ExportType::categories, 1.0) {

//}

//ExportCategory::ExportCategory(GameID aGameId, const QString &aGameIcon, const QString &aGameName, const Category &aCategory):
//ExportFileData(ExportType::categories, 1.0), gameId(aGameId), gameIcon(aGameIcon), gameName(aGameName), category(aCategory) {

//}

//ExportCategory::ExportCategory(const QJsonObject &aObject): ExportCategory() {
//    fromJson(aObject);
//}

//ExportCategory::ExportCategory(const QString &aFilePath): ExportCategory() {
//    filePath_ = aFilePath;
//    load(filePath_);
//}

//void ExportCategory::fromJson(const QJsonObject &aObject) {
//    gameId = aObject["gameId"].toInt();
//    gameName = aObject["gameName"].toString();
//    gameIcon = aObject["gameIcon"].toString();
//    category = Category(aObject["category"].toObject());
//    ExportFileData::fromJson(aObject);
//}

//QJsonObject ExportCategory::toJson() const {
//    QJsonObject jObj = ExportFileData::toJson();
//    jObj["category"] = category.toJson();
//    jObj["gameName"] = gameName;
//    jObj["gameIcon"] = gameIcon;
//    jObj["gameId"] = gameId;
//    return jObj;
//}

//ExportFavorites::ExportFavorites(): ExportFileData(ExportType::favorites, 1.0) {

//}

//ExportFavorites::ExportFavorites(Favorite *aFavorite): ExportFavorites() {
//    favorite = aFavorite;
//}

//ExportFavorites::ExportFavorites(const QJsonObject &aObject): ExportFavorites() {
//    fromJson(aObject);
//}

//ExportFavorites::ExportFavorites(const QString &aFilePath): ExportFavorites() {
//    filePath_ = aFilePath;
//    load(filePath_);
//}

//void ExportFavorites::fromJson(const QJsonObject &aObject) {
//    switch (aObject.value("type").toInt()) {
//    case Favorite::FavoriteType::game: {
//        favorite = new FavoriteGame(aObject);
//        break;
//    }
//    case Favorite::FavoriteType::achievement: {
//        favorite = new FavoriteAchievement(aObject);
//        break;
//    }
//    case Favorite::FavoriteType::profile: {
//        favorite = new FavoriteProfile(aObject);
//        break;
//    }
//    default: {
//        favorite = new Favorite(Favorite::FavoriteType::unknown);
//    }
//    }
//    ExportFileData::fromJson(aObject);
//}

//QJsonObject ExportFavorites::toJson() const {
//    QJsonObject jObj = ExportFileData::toJson();
//    jObj["favorite"] = favorite->toJson();
//    return jObj;
//}

//ExportComments::ExportComments(): ExportFileData(ExportType::comments, 1.0) {

//}

//ExportComments::ExportComments(Comment *aComment): ExportComments() {
//    comment = aComment;
//}

//ExportComments::ExportComments(const QJsonObject &aObject): ExportComments() {
//    fromJson(aObject);
//}

//ExportComments::ExportComments(const QString &aFilePath): ExportComments() {
//    filePath_ = aFilePath;
//    load(filePath_);
//}

//void ExportComments::fromJson(const QJsonObject &aObject) {
//    if (aObject.value("type").toString() == "AchievementComment") {
//        comment = new AchievementComment(aObject);
//    } else if (aObject.value("type").toString() == "GameComment") {
//        comment = new GameComment(aObject);
//    } else {
//        comment = new GameComment(aObject);
//    }
//    ExportFileData::fromJson(aObject);
//}

//QJsonObject ExportComments::toJson() const {
//    QJsonObject jObj = ExportFileData::toJson();
//    jObj["comment"] = comment->toJson();
//    return jObj;
//}

//ExportGroup::ExportGroup(): ExportFileData(ExportType::groups, 1.0) {

//}

//ExportGroup::ExportGroup(GroupGames aGroup): ExportFileData(ExportType::groups, 1.0), group(aGroup) {

//}

//ExportGroup::ExportGroup(const QJsonObject &aObject): ExportGroup() {
//    fromJson(aObject);
//}

//ExportGroup::ExportGroup(const QString &aFilePath): ExportGroup() {
//    filePath_ = aFilePath;
//    load(filePath_);
//}

//void ExportGroup::fromJson(const QJsonObject &aObject) {
//    group = GroupGames(aObject.value("group").toObject());
//    ExportFileData::fromJson(aObject);
//}

//QJsonObject ExportGroup::toJson() const {
//    QJsonObject jObj = ExportFileData::toJson();
//    jObj["group"] = group.toJson();
//    return jObj;
//}

//ExportSettings::ExportSettings(): ExportFileData(ExportType::settings, 1.0) {

//}

//ExportSettings::ExportSettings(const QString &aName, const QString &aValueType, const QVariant &aValue)
//: ExportFileData(ExportType::settings, 1.0), name(aName), valueType(aValueType), value(aValue) {

//}

//ExportSettings::ExportSettings(const QJsonObject &aObject): ExportSettings() {
//    fromJson(aObject);
//}

//ExportSettings::ExportSettings(const QString &aFilePath): ExportSettings() {
//    filePath_ = aFilePath;
//    load(filePath_);
//}

//void ExportSettings::fromJson(const QJsonObject &aObject) {
//    name = aObject.value("name").toString();
//    valueType = aObject.value("valueType").toString();
//    value = QVariant(aObject.value("value").toString());
//    ExportFileData::fromJson(aObject);
//}

//QJsonObject ExportSettings::toJson() const {
//    QJsonObject jObj = ExportFileData::toJson();
//    jObj["name"] = name;
//    jObj["valueType"] = valueType;
//    jObj["value"] = value.toString();
//    return jObj;
//}

ImportExportData::ImportExportData(ImportExportType aType, double aVersion):
type{aType}, version{aVersion} {

}

void ImportExportData::fromJson(const QJsonObject &aObject) {
    type = ImportExportType::fromString(aObject["type"].toString());
    version = aObject["version"].toString().toDouble();
}

QJsonObject ImportExportData::toJson() const {
    QJsonObject jObject;
    jObject["type"] = type.toString();
    jObject["version"] = QString::number(version);
    return jObject;
}

IECategory::IECategory() {
    type = ImportExportType::category;
}

IECategory::IECategory(GameID aGameId, const QString &aGameIcon, const QString &aGameName, const Category &aCategory):
gameId{aGameId}, gameIcon{aGameIcon}, gameName{aGameName}, category{aCategory} {
    type = ImportExportType::category;
    ieType = IEDataType::exported;
}

IECategory::IECategory(const QJsonObject &aObject): IECategory() {
    fromJson(aObject);
}

IECategory::~IECategory() {
    if (ieType == IEDataType::imported) {
        category.deleteAllCategories();
    }
}

void IECategory::fromJson(const QJsonObject &aObject) {
    gameId = aObject["gameId"].toInt();
    gameName = aObject["gameName"].toString();
    gameIcon = aObject["gameIcon"].toString();
    category = Category(aObject["category"].toObject());
    ImportExportData::fromJson(aObject);
    ieType = IEDataType::imported;
}

QJsonObject IECategory::toJson() const {
    QJsonObject jObj = ImportExportData::toJson();
    jObj["category"] = category.toJson();
    jObj["gameName"] = gameName;
    jObj["gameIcon"] = gameIcon;
    jObj["gameId"] = gameId;
    return jObj;
}

bool IECategory::isExist() const {
    Category newCategory(category.gameID(), category.gameName(), category.gameIcon());
    auto categories = newCategory.categories();
    auto it = std::find_if(categories.begin(),
                            categories.end(),
                            [this](Category *lCategory) {
                                return lCategory->title() == category.title();
                            });
    return (it != categories.end());
}

QString IECategory::existError() const {
    return QObject::tr("В игре %1 уже существует категория %2\n"
                       "Вы уверены, что хотите её заменить?").arg(category.gameName(), category.title());
}

bool IECategory::import() const {
    Category newCategory(category.gameID(), category.gameName(), category.gameIcon());
    if (isExist()) {
        if (!newCategory.removeCategory(category.title())) {
            return false;
        }
    }
    if (!newCategory.addCategory(new Category(category))) {
         return false;
     }
    return newCategory.save();
}

IEFavoriteGame::IEFavoriteGame() {
    type = ImportExportType::favorite_game;
}

IEFavoriteGame::IEFavoriteGame(FavoriteGame aFavorite): favorite{aFavorite} {
    type = ImportExportType::favorite_game;
    ieType = IEDataType::exported;
}

IEFavoriteGame::IEFavoriteGame(const QJsonObject &aObject): IEFavoriteGame() {
    fromJson(aObject);
}

IEFavoriteGame::~IEFavoriteGame() {

}

void IEFavoriteGame::fromJson(const QJsonObject &aObject) {
    favorite.fromJson(aObject.value("favorite").toObject());
    ImportExportData::fromJson(aObject);
    ieType = IEDataType::imported;
}

QJsonObject IEFavoriteGame::toJson() const {
    QJsonObject jObj = ImportExportData::toJson();
    jObj["favorite"] = favorite.toJson();
    return jObj;
}

bool IEFavoriteGame::isExist() const {
    FavoriteGames games;
    auto it = std::find_if(games.begin(),
                           games.end(),
                           [&](const FavoriteGame &lGame) {
                                return lGame.appId() == favorite.appId() &&
                                       lGame.steamId() == favorite.steamId();
                            });
    return (it != games.end());
}

QString IEFavoriteGame::existError() const {
    return QObject::tr("Игра %1 уже добавлена в избранное\n"
                       "Вы уверены, что хотите её заменить?").arg(favorite.name());
}

bool IEFavoriteGame::import() const {
    FavoriteGames games;
    if (isExist()) {
        games.remove(favorite.steamId(), favorite.appId());
    }
    games.append(favorite);
    return games.save();
}

IEFavoriteProfile::IEFavoriteProfile() {
    type = ImportExportType::favorite_profile;
}

IEFavoriteProfile::IEFavoriteProfile(FavoriteProfile aFavorite): favorite{aFavorite} {
    type = ImportExportType::favorite_profile;
    ieType = IEDataType::exported;
}

IEFavoriteProfile::IEFavoriteProfile(const QJsonObject &aObject): IEFavoriteProfile() {
    fromJson(aObject);
}

IEFavoriteProfile::~IEFavoriteProfile() {

}

void IEFavoriteProfile::fromJson(const QJsonObject &aObject) {
    favorite.fromJson(aObject.value("favorite").toObject());
    ImportExportData::fromJson(aObject);
    ieType = IEDataType::imported;
}

QJsonObject IEFavoriteProfile::toJson() const {
    QJsonObject jObj = ImportExportData::toJson();
    jObj["favorite"] = favorite.toJson();
    return jObj;
}

bool IEFavoriteProfile::isExist() const {
    FavoriteProfiles profile;
    auto it = std::find_if(profile.begin(),
                           profile.end(),
                           [&](const FavoriteProfile &lProfile) {
                                return lProfile.profileId() == favorite.profileId();
                            });
    return (it != profile.end());
}

QString IEFavoriteProfile::existError() const {
    return QObject::tr("Профиль %1 уже добавлен в избранное\n"
                       "Вы уверены, что хотите его заменить?").arg(SProfile::load(favorite.profileId()).personaName());
}

bool IEFavoriteProfile::import() const {
    FavoriteProfiles profile;
    if (isExist()) {
        profile.remove(favorite.profileId());
    }
    profile.append(favorite);
    return profile.save();
}

IEFavoriteAchievement::IEFavoriteAchievement() {
    type = ImportExportType::favorite_achievement;
}

IEFavoriteAchievement::IEFavoriteAchievement(FavoriteAchievement aFavorite): favorite{aFavorite} {
    type = ImportExportType::favorite_achievement;
    ieType = IEDataType::exported;
}

IEFavoriteAchievement::IEFavoriteAchievement(const QJsonObject &aObject): IEFavoriteAchievement() {
    fromJson(aObject);
}

IEFavoriteAchievement::~IEFavoriteAchievement() {

}

void IEFavoriteAchievement::fromJson(const QJsonObject &aObject) {
    favorite.fromJson(aObject.value("favorite").toObject());
    ImportExportData::fromJson(aObject);
    ieType = IEDataType::imported;
}

QJsonObject IEFavoriteAchievement::toJson() const {
    QJsonObject jObj = ImportExportData::toJson();
    jObj["favorite"] = favorite.toJson();
    return jObj;
}

bool IEFavoriteAchievement::isExist() const {
    FavoriteAchievements achievement;
    return achievement.isInFavorite(favorite.game().appId, profileId, favorite.apiName());
}

QString IEFavoriteAchievement::existError() const {
    return QObject::tr("Достижение %1 из игры %2 уже добавлено в избранное\n"
                       "Вы уверены, что хотите его заменить?").arg(favorite.title(), favorite.game().name);
}

bool IEFavoriteAchievement::import() const {
    FavoriteAchievements achievement;
    if (isExist()) {
        achievement.remove(profileId, favorite.game().appId, favorite.apiName());
    }
    achievement.append(favorite, profileId);
    return achievement.save();
}

IECommentGame::IECommentGame() {
    type = ImportExportType::comment_game;
}

IECommentGame::IECommentGame(GameComment aComment): comment{aComment} {
    type = ImportExportType::comment_game;
    ieType = IEDataType::exported;
}

IECommentGame::IECommentGame(const QJsonObject &aObject): IECommentGame() {
    fromJson(aObject);

}

IECommentGame::~IECommentGame() {

}

void IECommentGame::fromJson(const QJsonObject &aObject) {
    comment.fromJson(aObject.value("comment").toObject());
    ImportExportData::fromJson(aObject);
    ieType = IEDataType::imported;
}

QJsonObject IECommentGame::toJson() const {
    QJsonObject jObj = ImportExportData::toJson();
    jObj["comment"] = comment.toJson();
    return jObj;
}

bool IECommentGame::isExist() const {
    GameID gameId = comment.gameId();
    GameComments comments(comment.profileId());
    return std::any_of(comments.begin(),
                       comments.end(),
                        [=](const GameComment &lComment) {
                            return lComment.gameId() == gameId;
                        });
}

QString IECommentGame::existError() const {
    return QObject::tr("В игре %1 уже существует комментарий\n"
                       "Вы уверены, что хотите его заменить?").arg(comment.gameName());
}

bool IECommentGame::import() const {
    QString gameName = comment.gameName();
    GameComments comments(comment.profileId());
    if (isExist()) {
        comments.remove(profile, comment.gameId());
    }
    comments.append(comment);
    return comments.save();
}

IECommentAchievement::IECommentAchievement() {
    type = ImportExportType::comment_achievement;
}

IECommentAchievement::IECommentAchievement(AchievementComment aComment): comment{aComment} {
    type = ImportExportType::comment_achievement;
    ieType = IEDataType::exported;
}

IECommentAchievement::IECommentAchievement(const QJsonObject &aObject): IECommentAchievement() {
    fromJson(aObject);
}

IECommentAchievement::~IECommentAchievement() {

}

void IECommentAchievement::fromJson(const QJsonObject &aObject) {
    comment.fromJson(aObject.value("comment").toObject());
    ImportExportData::fromJson(aObject);
    ieType = IEDataType::imported;
}

QJsonObject IECommentAchievement::toJson() const {
    QJsonObject jObj = ImportExportData::toJson();
    jObj["comment"] = comment.toJson();
    return jObj;
}

bool IECommentAchievement::isExist() const {
    GameID gameId = comment.gameId();
    QString achievementId = comment.achievementId();
    AchievementComments comments(comment.profileId());
    return std::any_of(comments.begin(),
                       comments.end(),
                        [=](const AchievementComment &lComment) {
                            return lComment.gameId() == gameId && lComment.achievementId() == achievementId;
                        });
}

QString IECommentAchievement::existError() const {
    return QObject::tr("В игре %1, у достижения %2 уже существует комментарий\n"
                       "Вы уверены, что хотите его заменить?").arg(comment.gameName(), comment.title());
}

bool IECommentAchievement::import() const {
    AchievementComments comments(comment.profileId());
    if (isExist()) {
        comments.remove(profile, comment.gameId(), comment.achievementId());
    }
    comments.append(comment);
    return comments.save();
}

IEGroup::IEGroup() {
    type = ImportExportType::group;
}

IEGroup::IEGroup(GroupGames aGroup): group{aGroup} {
    type = ImportExportType::group;
    ieType = IEDataType::exported;
}

IEGroup::IEGroup(const QJsonObject &aObject): IEGroup() {
    fromJson(aObject);
}

IEGroup::~IEGroup() {

}

void IEGroup::fromJson(const QJsonObject &aObject) {
    group.fromJson(aObject.value("group").toObject());
    ImportExportData::fromJson(aObject);
    ieType = IEDataType::imported;
}

QJsonObject IEGroup::toJson() const {
    QJsonObject jObj = ImportExportData::toJson();
    jObj["group"] = group.toJson();
    return jObj;
}

bool IEGroup::isExist() const {
    QString importedTitle = group.title();
    GroupsGames groups(group.profileId());
    return std::any_of(groups.begin(),
                       groups.end(),
                        [=](const GroupGames &lGroup) {
                            return lGroup.title() == importedTitle;
                        });
}

QString IEGroup::existError() const {
    return QObject::tr("В аккаунте %1 уже существует группа %2\n"
                       "Вы уверены, что хотите её заменить?").arg(SProfile::load(group.profileId()).personaName(), group.title());
}

bool IEGroup::import() const {
    GroupsGames groups(group.profileId());
    if (isExist()) {
        groups.removeGroup(group.title());
    }
    groups.addGroup(group);
    return groups.save();
}

IESettings::IESettings() {
    type = ImportExportType::settings;
}

IESettings::IESettings(const QString &aName, const QString &aValueType, const QVariant &aValue): IESettings{Setting{aName, aValueType, aValue}} {

}

IESettings::IESettings(const Setting &aSetting): IESettings{QList<Setting>{aSetting}} {

}

IESettings::IESettings(const QList<Setting> &aSettings): settings{aSettings} {
    type = ImportExportType::settings;
    ieType = IEDataType::exported;

}

IESettings::IESettings(const QJsonObject &aObject): IESettings() {
    fromJson(aObject);
}

IESettings::~IESettings() {

}

void IESettings::addSetting(const Setting &aSetting) {
    settings.append(aSetting);
}

void IESettings::removeSetting(const Setting &aSetting) {
    settings.removeOne(aSetting);
}

void IESettings::fromJson(const QJsonObject &aObject) {
    for (const auto &jSetting: aObject.value("settings").toArray()) {
        Setting setting;
        setting.fromJson(jSetting.toObject());
        settings.append(setting);
    }
    ImportExportData::fromJson(aObject);
    ieType = IEDataType::imported;
}

QJsonObject IESettings::toJson() const {
    QJsonArray sett;
    for (const Setting &setting: settings) {
        sett.append(setting.toJson());
    }
    QJsonObject jObj = ImportExportData::toJson();
    jObj["settings"] = sett;
    return jObj;
}

bool IESettings::isExist() const {
    return false;
}

QString IESettings::existError() const {
    return QObject::tr("");
}

bool IESettings::import() const {
    for (auto setting: settings) {
        if (setting.name == "myProfile") {
            Settings::setMyProfile(setting.value.toString());
        } else if (setting.name == "language") {
            Settings::setLanguage(setting.value.toInt());
        }  else if (setting.name == "theme") {
            Settings::setTheme(setting.value.toInt());
        }  else if (setting.name == "profileInfoSize") {
            Settings::setVisibleProfileInfo(setting.value.toInt());
        }  else if (setting.name == "timeFormat") {
            Settings::setTimeFormat(setting.value.toString());
        }  else if (setting.name == "dateFormat") {
            Settings::setDateFormat(setting.value.toString());
        }  else if (setting.name == "timeShortFormat") {
            Settings::setTimeShortFormat(setting.value.toString());
        } else {
            return false;
        }
    }
    return true;
}

IESettings::Setting::Setting(): Setting{"", "", QVariant()} {

}

IESettings::Setting::Setting(const QString &aName): Setting{aName, Settings().property(aName.toStdString().c_str()).typeName() , Settings().property(aName.toStdString().c_str())} {

}

IESettings::Setting::Setting(const QString &aName, const QString &aValueType, const QVariant &aValue):
name{aName}, valueType{aValueType}, value{aValue} {

}

bool IESettings::Setting::operator==(const Setting &aS) const {
    return name == aS.name && valueType == aS.valueType && value == aS.value;
}

QJsonObject IESettings::Setting::toJson() const {
    QJsonObject jObj;
    jObj["name"] = name;
    jObj["valueType"] = valueType;
    jObj["value"] = value.toString();
    return jObj;
}

void IESettings::Setting::fromJson(const QJsonObject &aObject) {
    name = aObject.value("name").toString();
    valueType = aObject.value("valueType").toString();
    value = aObject.value("value").toVariant();
}

ImportExportFile::ImportExportFile(const QString &aPath): FileSaveLoad{aPath} {
    load(filePath_);
}

void ImportExportFile::fromJson(const QJsonObject &aObject) {
    date = QDateTime::fromString(aObject["date"].toString(), Settings::dateTimeFormat());
    datas.clear();
    for (auto jData: aObject.value("datas").toArray()) {
        switch (ImportExportType::fromString(jData.toObject().value("type").toString()).type) {
        case ImportExportType::category: {
            datas << (new IECategory(jData.toObject()));
            break;
        }
        case ImportExportType::favorite_game: {
            datas << (new IEFavoriteGame(jData.toObject()));
            break;
        }
        case ImportExportType::favorite_profile: {
            datas << (new IEFavoriteProfile(jData.toObject()));
            break;
        }
        case ImportExportType::favorite_achievement: {
            datas << (new IEFavoriteAchievement(jData.toObject()));
            break;
        }
        case ImportExportType::comment_game: {
            datas << (new IECommentGame(jData.toObject()));
            break;
        }
        case ImportExportType::comment_achievement: {
            datas << (new IECommentAchievement(jData.toObject()));
            break;
        }
        case ImportExportType::group: {
            datas << (new IEGroup(jData.toObject()));
            break;
        }
        case ImportExportType::settings: {
            datas << (new IESettings(jData.toObject()));
            break;
        }
        case ImportExportType::unknown: {
            break;
        }
        }
    }
}

QJsonObject ImportExportFile::toJson() const {
    QJsonObject jObj;
    jObj["date"] = date.toString(Settings::dateTimeFormat());
    QJsonArray jDatas;
    for (auto data: datas) {
        jDatas.append(data->toJson());
    }
    jObj["datas"] = jDatas;
    return jObj;
}
