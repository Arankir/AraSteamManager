#ifndef GROUPSGAMES_H
#define GROUPSGAMES_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sprofile.h"
#include "classes/common/filesaveload.h"

class GroupGames {
public:
    GroupGames(const QString &title, const ProfileID &profileId);
    GroupGames(const QJsonObject &object);

    GroupGames &addGame(const SGame &game);
    GroupGames &removeGame(const GameID &aGame);
    GroupGames &changeTitle(const QString &title);
    QJsonObject toJson() const;

    QString title()         const;
    ProfileID profileId()   const;
    QList<GameID> games()   const;

private:
    GroupGames &fromJson(const QJsonObject &object);

    QString title_;
    ProfileID profileId_;
    QList<GameID> games_;
};

class GroupsGames: public QList<GroupGames>, public FileSaveLoad {
public:
    GroupsGames(const ProfileID &profileId = "");

    void addGroup(const QString &title);
    void removeGroup(const QString &title);
    QJsonObject toJson() const override;
    void update(const ProfileID &aId);

private:
    void init();
    void fromJson(const QJsonObject &object) override;

    ProfileID profileId_;
};

#endif // GROUPSGAMES_H
