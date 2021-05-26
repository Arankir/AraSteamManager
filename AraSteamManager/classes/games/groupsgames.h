#ifndef GROUPSGAMES_H
#define GROUPSGAMES_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sprofile.h"

class GroupGames {
public:
    GroupGames(const QString &title, const QString &profileId): _title(title), _profileId(profileId) {}
    GroupGames(const QJsonObject &object);

    GroupGames &addGame(const SGame &game);
    GroupGames &removeGame(const SGame &aGame);
    GroupGames &changeTitle(const QString &title);
    QJsonObject toJson() const;

    QString title()          const {return _title;}
    QString profileId()      const {return _profileId;}
    QList<QString> games()   const {return _games;}

private:
    GroupGames &fromJson(const QJsonObject &object);

    QString _title;
    QString _profileId;
    QList<QString> _games;
};

class GroupsGames {
public:
    GroupsGames(const SProfile &profile = SProfile());
    GroupGames &operator[](const int &index);

    void setProfile(const SProfile &aProfile);
    GroupsGames &addGroup(const QString &title);
    QJsonObject toJson() const;
    const GroupsGames &save() const;
    void update();
    QList<GroupGames>::iterator begin() {return _groups.begin();}
    QList<GroupGames>::iterator end() {return _groups.end();}

private:
    void init();
    GroupsGames &fromJson(const QJsonObject &object);

    QList<GroupGames> _groups;
    QString _profileId;
};

#endif // GROUPSGAMES_H
