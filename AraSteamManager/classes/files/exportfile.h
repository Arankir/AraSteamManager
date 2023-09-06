#ifndef EXPORTFILE_H
#define EXPORTFILE_H

#include <QObject>

#include "classes/common/filesaveload.h"
#include "classes/files/category.h"
#include "classes/files/favorites.h"
#include "classes/files/comments.h"
#include "classes/files/groupsgames.h"
#include "classes/common/settings.h"

//enum class ExportType {
//    unknown,
//    categories,
//    favorites,
//    comments,
//    groups,
//    settings,
//    multiple
//};

//QString exportTypeToString(ExportType type);
//ExportType stringToExportType(QString type);

//class ExportFileData: public FileSaveLoad {
//public:
//    ExportFileData(ExportType = ExportType::unknown, double version = 1.0, QDateTime date = QDateTime::currentDateTime());
//    void setPath(const QString &);
//    void fromJson(const QJsonObject &object) override;
//    QJsonObject toJson() const override;
//    friend QDebug operator<<(QDebug dbg, const ExportFileData &efd) {
//        dbg.nospace() << "(" << efd.toJson() << ")\n";
//        return dbg.space();
//    }

//    QJsonValue data;
//    ExportType type;
//    double version;
//    QDateTime date;
//};

enum class IEDataType {
    imported,
    exported,
    unknown
};

class ImportExportType {
public:
    enum Type {
    unknown,
    category,
    favorite_game,
    favorite_profile,
    favorite_achievement,
    comment_game,
    comment_achievement,
    group,
    settings
    };
    ImportExportType(Type aType): type(aType) {};
    QString toString() const {
        switch (type) {
        case category:              return "category";
        case favorite_game:         return "favorite_game";
        case favorite_profile:      return "favorite_profile";
        case favorite_achievement:  return "favorite_achievement";
        case comment_game:          return "comment_game";
        case comment_achievement:   return "comment_achievement";
        case group:                 return "group";
        case settings:              return "settings";
        case unknown:               return "unknown";
        }
        return "error convert to String";
    }
    static ImportExportType fromString(const QString &aStr) {
        if (aStr == "category")             return ImportExportType(category);
        if (aStr == "favorite_game")        return ImportExportType(favorite_game);
        if (aStr == "favorite_profile")     return ImportExportType(favorite_profile);
        if (aStr == "favorite_achievement") return ImportExportType(favorite_achievement);
        if (aStr == "comment_game")         return ImportExportType(comment_game);
        if (aStr == "comment_achievement")  return ImportExportType(comment_achievement);
        if (aStr == "group")                return ImportExportType(group);
        if (aStr == "settings")             return ImportExportType(settings);
        return ImportExportType(unknown);
    }
    friend QDebug operator<<(QDebug dbg, const ImportExportType &efd) {
        dbg.nospace() << efd.toString();
        return dbg.space();
    }
    bool operator!=(const Type &aType) {
        return type != aType;
    }
    bool operator==(const Type &aType) {
        return type == aType;
    }
    Type type = Type::unknown;
};

class ImportExportData {
public:
    ImportExportData(ImportExportType = ImportExportType::unknown, double version = 1.0);
    virtual void fromJson(const QJsonObject &object);
    virtual QJsonObject toJson() const;
    friend QDebug operator<<(QDebug dbg, const ImportExportData &ied) {
        dbg.nospace() << "(" << ied.toJson() << ")\n";
        return dbg.space();
    };
    virtual bool isExist() const = 0;
    virtual QString existError() const = 0;
    virtual bool import() const = 0;

    ImportExportType type = ImportExportType::unknown;
    IEDataType ieType = IEDataType::unknown;
    double version;
};

class ImportExportFile: public FileSaveLoad {
public:
    ImportExportFile(const QString &path);

    void fromJson(const QJsonObject &object) override;
    QJsonObject toJson() const override;

    QList<ImportExportData*> datas;
private:
    QDateTime date = QDateTime::currentDateTime();

};

class IECategory: public ImportExportData {
public:
    IECategory();
    IECategory(GameID gameId, const QString &gameIcon, const QString &gameName, const Category &category);
    IECategory(const QJsonObject &object);
    ~IECategory();

    GameID gameId;
    QString gameIcon;
    QString gameName;
    Category category;

    void fromJson(const QJsonObject &object) override;
    QJsonObject toJson() const override;
    bool isExist() const override;
    QString existError() const override;
    bool import() const override;
};

class IEFavoriteGame: public ImportExportData {
public:
    IEFavoriteGame();
    IEFavoriteGame(FavoriteGame favorite);
    IEFavoriteGame(const QJsonObject &object);
    ~IEFavoriteGame();

    FavoriteGame favorite;

    void fromJson(const QJsonObject &object) override;
    QJsonObject toJson() const override;
    bool isExist() const override;
    QString existError() const override;
    bool import() const override;
};

class IEFavoriteProfile: public ImportExportData {
public:
    IEFavoriteProfile();
    IEFavoriteProfile(FavoriteProfile favorite);
    IEFavoriteProfile(const QJsonObject &object);
    ~IEFavoriteProfile();

    FavoriteProfile favorite;

    void fromJson(const QJsonObject &object) override;
    QJsonObject toJson() const override;
    bool isExist() const override;
    QString existError() const override;
    bool import() const override;
};

class IEFavoriteAchievement: public ImportExportData {
public:
    IEFavoriteAchievement();
    IEFavoriteAchievement(FavoriteAchievement favorite);
    IEFavoriteAchievement(const QJsonObject &object);
    ~IEFavoriteAchievement();

    FavoriteAchievement favorite;
    ProfileID profileId;

    void fromJson(const QJsonObject &object) override;
    QJsonObject toJson() const override;
    bool isExist() const override;
    QString existError() const override;
    bool import() const override;
};

class IECommentGame: public ImportExportData {
public:
    IECommentGame();
    IECommentGame(GameComment comment);
    IECommentGame(const QJsonObject &object);
    ~IECommentGame();

    GameComment comment;
    ProfileID profile;

    void fromJson(const QJsonObject &object) override;
    QJsonObject toJson() const override;
    bool isExist() const override;
    QString existError() const override;
    bool import() const override;
};

class IECommentAchievement: public ImportExportData {
public:
    IECommentAchievement();
    IECommentAchievement(AchievementComment comment);
    IECommentAchievement(const QJsonObject &object);
    ~IECommentAchievement();

    AchievementComment comment;
    ProfileID profile;

    void fromJson(const QJsonObject &object) override;
    QJsonObject toJson() const override;
    bool isExist() const override;
    QString existError() const override;
    bool import() const override;
};

class IEGroup: public ImportExportData {
public:
    IEGroup();
    IEGroup(GroupGames group);
    IEGroup(const QJsonObject &object);
    ~IEGroup();

    GroupGames group;

    void fromJson(const QJsonObject &object) override;
    QJsonObject toJson() const override;
    bool isExist() const override;
    QString existError() const override;
    bool import() const override;
};

class IESettings: public ImportExportData {
public:
    struct Setting {
        Setting();
        Setting(const QString &name);
        Setting(const QString &name, const QString &valueType, const QVariant &value);

        bool operator==(const Setting &s) const;

        QString name;
        QString valueType;
        QVariant value;

        QJsonObject toJson() const;
        void fromJson(const QJsonObject &object);
    };

    IESettings();
    IESettings(const QString &name, const QString &valueType, const QVariant &value);
    IESettings(const Setting &setting);
    IESettings(const QList<Setting> &settings);
    IESettings(const QJsonObject &object);
    ~IESettings();

    void addSetting(const Setting &setting);
    void removeSetting(const Setting &setting);

    QList<Setting> settings;

    void fromJson(const QJsonObject &object) override;
    QJsonObject toJson() const override;
    bool isExist() const override;
    QString existError() const override;
    bool import() const override;
};

//class ExportFile: public FileSaveLoad {
//public:
//    ExportFile();
//    ExportFile(const QJsonObject &object);
//    ExportFile(const QString &filePath);

//    void fromJson(const QJsonObject &object) override;
//    QJsonObject toJson() const override;

//protected:
//    QString type_;
//};

//class ExportCategory: public ExportFileData {
//public:
//    ExportCategory();
//    ExportCategory(GameID gameId, const QString &gameIcon, const QString &gameName, const Category &category);
//    ExportCategory(const QJsonObject &object);
//    ExportCategory(const QString &pathFile);

//    GameID gameId;
//    QString gameIcon;
//    QString gameName;
//    Category category;

//    void fromJson(const QJsonObject &object) override;
//    QJsonObject toJson() const override;
//};

//class ExportFavorites: public ExportFileData {
//public:
//    ExportFavorites();
//    ExportFavorites(Favorite *favorite);
//    ExportFavorites(const QJsonObject &object);
//    ExportFavorites(const QString &pathFile);

//    Favorite *favorite;

//    void fromJson(const QJsonObject &object) override;
//    QJsonObject toJson() const override;
//};

//class ExportComments: public ExportFileData {
//public:
//    ExportComments();
//    ExportComments(Comment *comment);
//    ExportComments(const QJsonObject &object);
//    ExportComments(const QString &pathFile);

//    Comment *comment;

//    void fromJson(const QJsonObject &object) override;
//    QJsonObject toJson() const override;
//};

//class ExportGroup: public ExportFileData {
//public:
//    ExportGroup();
//    ExportGroup(GroupGames group);
//    ExportGroup(const QJsonObject &object);
//    ExportGroup(const QString &pathFile);

//    GroupGames group;

//    void fromJson(const QJsonObject &object) override;
//    QJsonObject toJson() const override;
//};

//class ExportSettings: public ExportFileData {
//public:
//    ExportSettings();
//    ExportSettings(const QString &name, const QString &valueType, const QVariant &value);
//    ExportSettings(const QJsonObject &object);
//    ExportSettings(const QString &pathFile);

//    QString name;
//    QString valueType;
//    QVariant value;

//    void fromJson(const QJsonObject &object) override;
//    QJsonObject toJson() const override;
//};

#endif // EXPORTFILE_H
