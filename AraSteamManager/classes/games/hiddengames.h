#ifndef HIDDENGAMES_H
#define HIDDENGAMES_H

#include "classes/steamApi/structures/sgames.h"
#include "classes/steamApi/structures/sprofile.h"

class HiddenGame {
public:
    HiddenGame(const SGame &game);
    HiddenGame(const QJsonObject &game);
    HiddenGame &fromJson(const QJsonObject &object);
    QJsonObject toJson() const;

    QString id() const {return _id;}
    QString name() const {return _name;}
    QString iconUrl() const {return _iconUrl;}

private:
    QString _id;
    QString _name;
    QString _iconUrl;
};

class HiddenGames {
public:
    HiddenGames(SProfile profile = SProfile());

    HiddenGames &addGame(const SGame &game, const bool &removeIfExist = false);
    HiddenGames &removeGame(const SGame &game, const bool &addIfExist = false);
    HiddenGames &save();

    QList<HiddenGame> games() const {return _games;}

private:
    void load();
    QJsonObject toJson();

    QList<HiddenGame> _games;
    QString _profile;
};

#endif // HIDDENGAMES_H
