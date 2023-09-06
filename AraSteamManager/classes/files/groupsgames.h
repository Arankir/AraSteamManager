#ifndef GROUPSGAMES_H
#define GROUPSGAMES_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/common/filesaveload.h"

class GroupGames: public QSet<GameID> {
public:
    GroupGames(const QString &title = "", const ProfileID &profileId = "");
    GroupGames(const QJsonObject &object);

    GroupGames &addGame(const SGame &game);
    GroupGames &removeGame(const GameID &gameId);
    GroupGames &changeTitle(const QString &title);
    QJsonObject toJson() const;
    GroupGames &fromJson(const QJsonObject &object);

    QString title()         const;
    ProfileID profileId()   const;

private:
    QString title_;
    ProfileID profileId_;
};

class GroupsGames: public QMap<QString, GroupGames>, public FileSaveLoad {
public:
    GroupsGames(const ProfileID &profileId = "");

    void addGroup(const QString &title);
    void addGroup(const GroupGames &group);
    void removeGroup(const QString &title);
    QJsonObject toJson() const override;
    void update(const ProfileID &profileId);

private:
    void init();
    void fromJson(const QJsonObject &object) override;

    ProfileID profileId_;
};

#endif // GROUPSGAMES_H
