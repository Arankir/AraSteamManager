#ifndef GROUPSGAMES_H
#define GROUPSGAMES_H

#include <QObject>
#include "class/steamapi/Sgames.h"
#include "class/steamapi/Sprofile.h"
#include "class/settings.h"

class GroupGames {
public:
    GroupGames(const QString &title, const QString &profileId) : _title(title), _profileId(profileId) {}
    GroupGames(const QJsonObject &object);

    GroupGames &addGame(const SGame &game);
    GroupGames &removeGame(const SGame &aGame);
    GroupGames &changeTitle(const QString &title);
    QJsonObject toJson() const;

    QString getTitle()          const {return _title;}
    QString getProfileId()      const {return _profileId;}
    QList<QString> getGames()   const {return _games;}

private:
    GroupGames &fromJson(const QJsonObject &object);

    QString _title;
    QString _profileId;
    QList<QString> _games;
};

class GroupsGames {
public:
    GroupsGames(const SProfile &profile);
    GroupGames &operator[](const int index);

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
